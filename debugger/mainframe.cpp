#include "stdafx.h"
#include "mainframe.h"
#include "resource.h"
#include "debuggerapp.h"
#include "prefs.h"
#include "../MultiLang/MultiLang.h"

#include <sstream>
#include <format>

#define WM_IDLEUPDATECMDUI  0x0363

enum {
	WM_STOP = WM_APP + 1, WM_RUN, WM_END
};

enum {
	STARTING, RUNNING, STOPPED, ENDING
};

IMPLEMENT_DYNAMIC(MainFrame, CFrameWnd)
BEGIN_MESSAGE_MAP(MainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_CLOSE()
	ON_WM_WINDOWPOSCHANGING()

	ON_COMMAND(ID_STOP, cmdStop)
	ON_COMMAND(ID_RUN, cmdRun)
	ON_COMMAND(ID_STEPOVER, cmdStepOver)
	ON_COMMAND(ID_STEPINTO, cmdStepInto)
	ON_COMMAND(ID_STEPOUT, cmdStepOut)
	ON_COMMAND(ID_END, cmdEnd)

	ON_UPDATE_COMMAND_UI(ID_STOP, updateCmdUI)
	ON_UPDATE_COMMAND_UI(ID_RUN, updateCmdUI)
	ON_UPDATE_COMMAND_UI(ID_STEPOVER, updateCmdUI)
	ON_UPDATE_COMMAND_UI(ID_STEPINTO, updateCmdUI)
	ON_UPDATE_COMMAND_UI(ID_STEPOUT, updateCmdUI)
	ON_UPDATE_COMMAND_UI(ID_END, updateCmdUI)

END_MESSAGE_MAP()

MainFrame::MainFrame() :state(STARTING), step_level(-1), cur_pos(0), cur_file(0) {
}

MainFrame::~MainFrame() {
	std::map<const char*, SourceFile*>::iterator it;
	for(it = files.begin(); it != files.end(); ++it) delete it->second;
}

int MainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct) {
	CFrameWnd::OnCreate(lpCreateStruct);

	HICON hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON1));
	SetIcon(hIcon, FALSE);

	prefs.open();

	std::string tb = prefs.homeDir + "/cfg/dbg_toolbar.bmp";

	//Toolbar
	HBITMAP toolbmp = (HBITMAP)LoadImage(
		0, tb.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADMAP3DCOLORS);

	BITMAP bm;
	GetObject(toolbmp, sizeof(bm), &bm);

	int n = 0;
	UINT toolbuts[] = { ID_STOP,ID_RUN,ID_STEPOVER,ID_STEPINTO,ID_STEPOUT,ID_END };
	int toolcnt = sizeof(toolbuts) / sizeof(UINT);
	for(int k = 0; k < toolcnt; ++k) if(toolbuts[k] != ID_SEPARATOR) ++n;

	SIZE imgsz, butsz;
	imgsz.cx = bm.bmWidth / n; imgsz.cy = bm.bmHeight;
	butsz.cx = imgsz.cx + 7; butsz.cy = imgsz.cy + 6;

	toolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_TOOLTIPS);
	toolBar.SetBitmap(toolbmp);
	toolBar.SetSizes(butsz, imgsz);
	toolBar.SetButtons(toolbuts, toolcnt);

	//Tabber
	tabber.Create(
		WS_VISIBLE | WS_CHILD |
		TCS_HOTTRACK,
		CRect(0, 0, 0, 0), this, 1);
	tabber.SetFont(&prefs.tabsFont);

	//Second tabber
	tabber2.Create(
		WS_VISIBLE | WS_CHILD |
		TCS_HOTTRACK,
		CRect(0, 0, 0, 0), this, 2);
	tabber2.SetFont(&prefs.tabsFont);

	//Debug Log
	debug_log.Create(
		WS_CHILD | WS_HSCROLL | WS_VSCROLL |
		ES_NOHIDESEL | ES_MULTILINE | ES_AUTOHSCROLL | ES_AUTOVSCROLL,
		CRect(0, 0, 0, 0), &tabber, 1);
	tabber.insert(0, &debug_log, "Debug log");

	//Debug trees
	locals_tree.Create(
		WS_VISIBLE | WS_CHILD |
		TVS_HASLINES | TVS_LINESATROOT | TVS_HASBUTTONS,
		CRect(0, 0, 0, 0), &tabber2, 3);

	globals_tree.Create(
		WS_VISIBLE | WS_CHILD |
		TVS_HASLINES | TVS_LINESATROOT | TVS_HASBUTTONS,
		CRect(0, 0, 0, 0), &tabber2, 3);

	consts_tree.Create(
		WS_VISIBLE | WS_CHILD |
		TVS_HASLINES | TVS_LINESATROOT | TVS_HASBUTTONS,
		CRect(0, 0, 0, 0), &tabber2, 3);

	tabber2.insert(0, &locals_tree, MultiLang::debugger_locals);
	tabber2.insert(1, &globals_tree, MultiLang::debugger_globals);
	tabber2.insert(2, &consts_tree, MultiLang::debugger_consts);
	tabber2.setCurrent(0);

	setState(STARTING);

	return 0;
}

void MainFrame::setState(int n) {
	state = n;
	SendMessageToDescendants(WM_IDLEUPDATECMDUI, (WPARAM)TRUE, 0, TRUE, TRUE);
	if(shouldRun()) {
		if(HWND app = ::FindWindow("Blitz Runtime Class", 0)) {
			::SetActiveWindow(app);
		}
	}
	else {
		SetActiveWindow();
	}
}

void MainFrame::OnClose() {
	cmdEnd();
}

void MainFrame::OnSize(UINT type, int sw, int sh) {
	CFrameWnd::OnSize(type, sw, sh);

	CRect r, t; GetClientRect(&r);
	int x = r.left, y = r.top, w = r.Width(), h = r.Height();

	toolBar.GetWindowRect(&t); y += t.Height(); h -= t.Height();

	tabber.MoveWindow(x, y, w - 360, h);

	tabber2.MoveWindow(x + w - 360, y, 360, h);
}

void MainFrame::setRuntime(void* mod, void* env) {
	consts_tree.reset((Environ*)env);
	globals_tree.reset((Module*)mod, (Environ*)env);
	locals_tree.reset((Environ*)env);
}

void MainFrame::showCurStmt() {
	if(!cur_file) return;

	SourceFile* t = sourceFile(cur_file);

	int row = (cur_pos >> 16) & 0xffff, col = cur_pos & 0xffff;
	t->highLight(row, col);

	globals_tree.refresh();
	locals_tree.refresh();
}

void MainFrame::debugRun() {
	setState(RUNNING);
}

void MainFrame::debugStop() {
	step_level = locals_tree.size();
	setState(STOPPED);
	showCurStmt();
}

void MainFrame::debugStmt(int pos, const char* file) {
	cur_pos = pos;
	cur_file = file;

	if(shouldRun()) return;

	::PostMessage(0, WM_STOP, 0, 0);
}

void MainFrame::debugEnter(void* frame, void* env, const char* func) {
	locals_tree.pushFrame(frame, env, func);

	if(locals_tree.size() > 1) return;

	globals_tree.refresh();
	locals_tree.refresh();

	setState(RUNNING);
}

void MainFrame::debugLeave() {
	locals_tree.popFrame();
}

void MainFrame::debugMsg(const char* msg, bool serious) {
	if(serious) {
		::MessageBoxW(0, UTF8::convertToUtf16(msg).c_str(), MultiLang::runtime_error, MB_OK | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
	}
	else {
		::MessageBoxW(0, UTF8::convertToUtf16(msg).c_str(), MultiLang::runtime_message, MB_OK | MB_ICONINFORMATION | MB_TOPMOST | MB_SETFOREGROUND);
	}
}

void MainFrame::debugLog(const char* msg) {
	debug_log.ReplaceSel(msg);
	debug_log.ReplaceSel("\n");
	tabber.setCurrent(0);
	setState(state);
}

void MainFrame::debugSys(void* m) {
}

void MainFrame::cmdStop() {
	::PostMessage(0, WM_STOP, 0, 0);
}

void MainFrame::cmdRun() {
	step_level = -1;
	::PostMessage(0, WM_RUN, 0, 0);
}

void MainFrame::cmdEnd() {
	::PostMessage(0, WM_END, 0, 0);
	setState(ENDING);
}

void MainFrame::cmdStepOver() {
	::PostMessage(0, WM_RUN, 0, 0);
}

void MainFrame::cmdStepInto() {
	step_level = locals_tree.size() + 1;
	::PostMessage(0, WM_RUN, 0, 0);
}

void MainFrame::cmdStepOut() {
	step_level = locals_tree.size() - 1;
	::PostMessage(0, WM_RUN, 0, 0);
}

SourceFile* MainFrame::sourceFile(const char* file) {
	if(!file) file = MultiLang::debugger_unknown;

	std::map<const char*, SourceFile*>::const_iterator it = files.find(file);

	if(it != files.end()) {
		tabber.setCurrent(file_tabs[file]);
		return it->second;
	}

	//crete new source file
	SourceFile* t = new SourceFile();

	it = files.insert(std::make_pair(file, t)).first;

	int tab = files.size();

	t->Create(
		WS_CHILD | WS_HSCROLL | WS_VSCROLL |
		ES_NOHIDESEL | ES_MULTILINE | ES_AUTOHSCROLL | ES_AUTOVSCROLL,
		CRect(0, 0, 0, 0), &tabber, 1);

	if(FILE* f = fopen(file, "rb")) {
		fseek(f, 0, SEEK_END);
		int sz = ftell(f);
		fseek(f, 0, SEEK_SET);
		char* buf = new char[sz + 1];
		fread(buf, sz, 1, f);
		buf[sz] = 0;
		t->ReplaceSel(buf);
		delete[] buf;
		fclose(f);
	}

	file_tabs.insert(std::make_pair(file, tab));

	if(const char* p = strrchr(file, '/')) file = p + 1;
	if(const char* p = strrchr(file, '\\')) file = p + 1;
	tabber.insert(tab, t, file);

	tabber.setCurrent(tab);

	return t;
}

void MainFrame::updateCmdUI(CCmdUI* ui) {
	if(state != RUNNING && state != STOPPED) {
		ui->Enable(false);
		return;
	}
	switch(ui->m_nID) {
		case ID_STOP:
			ui->Enable(shouldRun());
			break;
		case ID_RUN:
		case ID_STEPOVER:
		case ID_STEPINTO:
		case ID_STEPOUT:
			ui->Enable(!shouldRun());
			break;
		case ID_END:
			ui->Enable(true);
			break;
	}
}

void MainFrame::OnWindowPosChanging(WINDOWPOS* pos) {
	RECT rect;
	SystemParametersInfo(SPI_GETWORKAREA, 0, &rect, 0);

	pos->x = rect.left;
	pos->cx = rect.right - pos->x;
	pos->cy = rect.bottom - pos->y;
}

int UTF8::measureCodepoint(char chr) {
	if ((chr & 0x80) == 0x00) {
		//first bit is 0: treat as ASCII
		return 1;
	}

	//first bit is 1, number of consecutive 1 bits at the start is length of codepoint
	int len = 0;
	while (((chr >> (7 - len)) & 0x01) == 0x01) {
		len++;
	}
	return len;
}

int UTF8::decodeCharacter(const char* buf, int index) {
	int codepointLen = measureCodepoint(buf[index]);

	if (codepointLen == 1) {
		return buf[index];
	}
	else {
		//decode first byte by skipping all bits that indicate the length of the codepoint
		int newChar = buf[index] & (0x7f >> codepointLen);
		for (int j = 1; j < codepointLen; j++) {
			//decode all of the following bytes, fixed 6 bits per byte
			newChar = (newChar << 6) | (buf[index + j] & 0x3f);
		}
		return newChar;
	}
}

int UTF8::encodeCharacter(int chr, char* result) {
	//fits in standard ASCII, just return the char as-is
	if ((chr & 0x7f) == chr) {
		if (result != nullptr) { result[0] = chr; }
		return 1;
	}

	int len = 1;

	//determine most of the bytes after the first one
	while ((chr & (~0x3f)) != 0x00) {
		if (result != nullptr) { result[len - 1] = 0x80 | (chr & 0x3f); }
		chr >>= 6;
		len++;
	}

	//determine the remaining byte(s): if the number of free bits in
	//the first byte isn't enough to fit the remaining bits,
	//add another byte
	char firstByte = 0x00;
	for (int i = 0; i < len; i++) {
		firstByte |= (0x1 << (7 - i));
	}

	if (((firstByte | (0x1 << (7 - len))) & chr) == 0x00) {
		//it fits!
		firstByte = firstByte | chr;
		if (result != nullptr) { result[len - 1] = firstByte; }
	}
	else {
		//it doesn't fit: add another byte
		if (result != nullptr) { result[len - 1] = 0x80 | (chr & 0x3f); }
		chr >>= 6;
		firstByte = (firstByte | (0x1 << (7 - len))) | chr;
		len++;
		if (result != nullptr) { result[len - 1] = firstByte; }
	}

	if (result != nullptr) {
		//flip the result
		for (int i = 0; i < len / 2; i++) {
			char b = result[i];
			result[i] = result[len - 1 - i];
			result[len - 1 - i] = b;
		}
	}

	return len;
}

std::string UTF8::convertToUtf8(const std::string& str) {
	UINT nLen = MultiByteToWideChar(GetACP(), NULL, str.c_str(), -1, NULL, NULL);
	WCHAR* wszBuffer = new WCHAR[nLen + 1];
	nLen = MultiByteToWideChar(GetACP(), NULL, str.c_str(), -1, wszBuffer, nLen);
	wszBuffer[nLen] = 0;

	nLen = WideCharToMultiByte(CP_UTF8, NULL, wszBuffer, -1, NULL, NULL, NULL, NULL);
	CHAR* szBuffer = new CHAR[nLen + 1];
	nLen = WideCharToMultiByte(CP_UTF8, NULL, wszBuffer, -1, szBuffer, nLen, NULL, NULL);
	szBuffer[nLen] = 0;

	std::string converted = szBuffer;
	delete[] wszBuffer;
	delete[] szBuffer;
	return converted;
}

std::string UTF8::convertToAnsi(const std::string& str) {
	UINT nLen = MultiByteToWideChar(CP_UTF8, NULL, str.c_str(), -1, NULL, NULL);
	WCHAR* wszBuffer = new WCHAR[nLen + 1];
	nLen = MultiByteToWideChar(CP_UTF8, NULL, str.c_str(), -1, wszBuffer, nLen);
	wszBuffer[nLen] = 0;

	nLen = WideCharToMultiByte(GetACP(), NULL, wszBuffer, -1, NULL, NULL, NULL, NULL);
	CHAR* szBuffer = new CHAR[nLen + 1];
	nLen = WideCharToMultiByte(GetACP(), NULL, wszBuffer, -1, szBuffer, nLen, NULL, NULL);
	szBuffer[nLen] = 0;

	std::string converted = szBuffer;
	delete[] szBuffer;
	delete[] wszBuffer;
	return converted;
}

int UTF8::length(const std::string& str) {
	int utf8Len = 0;
	for (int i = 0; i < str.size();) {
		utf8Len++;
		i += measureCodepoint(str[i]);
	}
	return utf8Len;
}

int UTF8::find(const std::string& str, const std::string& sstr, int from) {
	int utf8Index = 0;
	int bytesFrom = -1;
	for (int i = 0; i < str.size();) {
		if (from == utf8Index) {
			bytesFrom = i;
			break;
		}
		utf8Index++;
		i += measureCodepoint(str[i]);
	}
	if (bytesFrom < 0) { return -1; }
	int bytesResult = str.find(sstr, bytesFrom);
	int result = -1;
	for (int i = bytesFrom; i < str.size();) {
		if (bytesResult == i) {
			result = utf8Index;
			break;
		}
		utf8Index++;
		i += measureCodepoint(str[i]);
	}
	return result;
}

void UTF8::popBack(std::string& str) {
	for (int i = str.size() - 1; i >= 0; i--) {
		char chr = str[i];
		str.pop_back();
		if (((chr & 0x80) == 0) || ((chr & 0xc0) == 0xc0)) {
			break;
		}
	}
}

std::string UTF8::substr(const std::string& str, int start, int length) {
	int utf8Index = 0;
	int bytesStart = str.size();
	int bytesLength = str.size();
	for (int i = 0; i < str.size();) {
		if (start == utf8Index) {
			bytesStart = i;
		}
		if ((start + length) == utf8Index) {
			bytesLength = i - bytesStart;
			break;
		}
		utf8Index++;
		i += measureCodepoint(str[i]);
	}
	return str.substr(bytesStart, bytesLength);
}

std::wstring UTF8::convertToUtf16(const std::string& str) {
	std::wstring result = L"";

	for (int i = 0; i < str.size();) {
		result.push_back(decodeCharacter(str.c_str(), i));
		i += measureCodepoint(str[i]);
	}

	return result;
}

std::string UTF8::replaceAll(const std::string_view& str, const std::string_view& pattern, const std::string_view& newpat) {
	std::string result;
	result.reserve(str.size());

	size_t pos = 0;
	size_t prev_pos = 0;

	while ((pos = str.find(pattern, pos)) != std::string::npos) {
		result.append(str.substr(prev_pos, pos - prev_pos));
		result.append(newpat);
		pos += pattern.size();
		prev_pos = pos;
	}

	result.append(str.substr(prev_pos));
	return result;
}

std::string UTF8::getSystemFontFile(const std::string& faceName) {
	static LPCWSTR fontRegistryPath = L"Software\\Microsoft\\Windows NT\\CurrentVersion\\Fonts";
	HKEY hKey;
	LONG result;
	std::wstring wsFaceName(faceName.begin(), faceName.end());

	// Open Windows font registry key
	result = RegOpenKeyExW(HKEY_LOCAL_MACHINE, fontRegistryPath, 0, KEY_READ, &hKey);
	if (result != ERROR_SUCCESS) {
		return "";
	}

	DWORD maxValueNameSize, maxValueDataSize;
	result = RegQueryInfoKeyW(hKey, 0, 0, 0, 0, 0, 0, 0, &maxValueNameSize, &maxValueDataSize, 0, 0);
	if (result != ERROR_SUCCESS) {
		return "";
	}

	DWORD valueIndex = 0;
	LPWSTR valueName = new WCHAR[maxValueNameSize];
	LPBYTE valueData = new BYTE[maxValueDataSize];
	DWORD valueNameSize, valueDataSize, valueType;
	std::wstring wsFontFile;

	// Look for a matching font name
	do {

		wsFontFile.clear();
		valueDataSize = maxValueDataSize;
		valueNameSize = maxValueNameSize;

		result = RegEnumValueW(hKey, valueIndex, valueName, &valueNameSize, 0, &valueType, valueData, &valueDataSize);

		valueIndex++;

		if (result != ERROR_SUCCESS || valueType != REG_SZ) {
			continue;
		}

		std::wstring wsValueName(valueName, valueNameSize);

		// Found a match
		if (_wcsnicmp(wsFaceName.c_str(), wsValueName.c_str(), wsFaceName.length()) == 0) {

			wsFontFile.assign((LPWSTR)valueData, valueDataSize);
			break;
		}
	} while (result != ERROR_NO_MORE_ITEMS);

	delete[] valueName;
	delete[] valueData;

	RegCloseKey(hKey);

	if (wsFontFile.empty()) {
		return "";
	}

	// Build full font file path
	WCHAR winDir[MAX_PATH];
	GetWindowsDirectoryW(winDir, MAX_PATH);

	std::wstringstream ss;
	ss << winDir << "\\Fonts\\" << wsFontFile;
	wsFontFile = ss.str();

	return std::string(wsFontFile.begin(), wsFontFile.end());
}