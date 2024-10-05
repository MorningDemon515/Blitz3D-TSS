#ifndef MAINFRAME_H
#define MAINFRAME_H

#include "tabber.h"
#include "debugger.h"
#include "sourcefile.h"
#include "debugtree.h"

#include <string>
#include <atlstr.h>

class UTF8 {
private:
	UTF8() {}
	UTF8(const UTF8& o) {}
public:
	static int measureCodepoint(char chr);
	static int decodeCharacter(const char* buf, int index);
	static int encodeCharacter(int chr, char* result);
	static std::string convertToUtf8(const std::string& str);
	static std::string convertToAnsi(const std::string& str);
	static int length(const std::string& str);
	static int find(const std::string& str, const std::string& sstr, int from);
	static void popBack(std::string& str);
	static std::string substr(const std::string& str, int start, int length);
	static std::wstring convertToUtf16(const std::string& str);
	static std::string replaceAll(const std::string_view& string, const std::string_view& pattern, const std::string_view& newpat);
	static std::string getSystemFontFile(const std::string& faceName);
};

class MainFrame : public CFrameWnd, public Debugger {

	Tabber tabber;
	Tabber tabber2;
	CToolBar toolBar;
	SourceFile debug_log;
	ConstsTree consts_tree;
	GlobalsTree globals_tree;
	LocalsTree locals_tree;
	std::map<const char*, int> file_tabs;
	std::map<const char*, SourceFile*> files;

	int state, step_level, cur_pos;
	const char* cur_file;

	bool shouldRun()const { return step_level < locals_tree.size(); }

public:
	MainFrame();
	~MainFrame();

	void debugRun();
	void debugStop();
	void debugStmt(int srcpos, const char* file);
	void debugEnter(void* frame, void* env, const char* func);
	void debugLeave();
	void debugLog(const char* msg);
	void debugMsg(const char* msg, bool serious);
	void debugSys(void* msg);

	void showCurStmt();
	void setState(int n);
	void setRuntime(void* mod, void* env);
	SourceFile* sourceFile(const char* file);

	DECLARE_DYNAMIC(MainFrame)
	DECLARE_MESSAGE_MAP()

	afx_msg int  OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT type, int w, int h);
	afx_msg void OnClose();

	afx_msg void cmdStop();
	afx_msg void cmdRun();
	afx_msg void cmdStepOver();
	afx_msg void cmdStepInto();
	afx_msg void cmdStepOut();
	afx_msg void cmdEnd();

	afx_msg void updateCmdUI(CCmdUI* ui);

	afx_msg void OnWindowPosChanging(WINDOWPOS* pos);
};

#endif