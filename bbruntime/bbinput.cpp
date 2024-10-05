#include "std.h"
#include "bbsys.h"
#include "bbutf8.h"

static int mouse_x, mouse_y, mouse_z;
static const float JLT = -1.0f / 3.0f;
static const float JHT = 1.0f / 3.0f;

static std::vector<int> chars;

std::vector<int> bbgetchars()
{
	std::vector<int> chrs = chars;
	chars.clear();
	return chrs;
}

BBStr* bbTextInput(BBStr* s) {
	BBStr t = *s;
	char tBuf[9];
	std::vector<int> chars = bbgetchars();
	for (int i = 0; i < chars.size(); i++) {
		if (chars[i] == 8) { //backspace
			if (t.size() > 0) UTF8::popBack(t);
		}
		else if (chars[i] == 127) {
			t.clear();
		}
		else if (chars[i] >= 32) {
			int codepointLen = UTF8::encodeCharacter(chars[i], tBuf);
			tBuf[codepointLen] = '\0';
			t += tBuf;
		}
	}
	*s = t;
	return s;
}


int bbKeyDown(int n) {
	return 0;
}

int bbKeyHit(int n) {
	return 0;
}

int bbGetKey() {
	return 0;
}

int bbWaitKey() {
	return 0;
}

void bbFlushKeys() {
	
}

int bbMouseDown(int n) {
	return 0;
}

int bbMouseHit(int n) {
	return 0;
}

int bbGetMouse() {
	return 0;
}

int bbWaitMouse() {
	return 0;
}

int bbMouseWait() {
	return 0;
}

int bbMouseX() {
	return 0;
}

int bbMouseY() {
	return 0;
}

int bbMouseZ() {
	return 0;
}

int bbMouseXSpeed() {
	int dx = bbMouseX() - mouse_x;
	mouse_x += dx;
	return dx;
}

int bbMouseYSpeed() {
	int dy = bbMouseY() - mouse_y;
	mouse_y += dy;
	return dy;
}

int bbMouseZSpeed() {
	int dz = bbMouseZ() - mouse_z;
	mouse_z += dz;
	return dz;
}

void bbFlushMouse() {
	
}

void bbMoveMouse(int x, int y) {
	
}

int bbJoyType(int port) {
	return 0;
}

int bbJoyDown(int n, int port) {
	return 0;
}

int bbJoyHit(int n, int port) {
	return 0;
}

int bbGetJoy(int port) {
	return 0;
}

int bbWaitJoy(int port) {
	return 0;
}

float bbJoyX(int port) {
	return 0;
}

float bbJoyY(int port) {
	return 0;
}

float bbJoyZ(int port) {
	return 0;
}

float bbJoyU(int port) {
	return 0;
}

float bbJoyV(int port) {
	return 0;
}

float bbJoyPitch(int port) {
	return 0;
}

float bbJoyYaw(int port) {
	return 0;
}

float bbJoyRoll(int port) {
	return 0;
}

int  bbJoyHat(int port) {
	return 0;
}

int	bbJoyXDir(int port) {
	return 0;
}

int bbJoyYDir(int port) {
	return 0;
}

int	bbJoyZDir(int port) {
	return 0;
}

int	bbJoyUDir(int port) {
	return 0;
}

int	bbJoyVDir(int port) {
	return 0;
}

void bbFlushJoy() {
	
}

void  bbEnableDirectInput(int enable) {
	
}

int  bbDirectInputEnabled() {
	return 0;
}

bool input_create()
{
	return true;
}

bool input_destroy()
{
	return true;
}

void input_link(void (*rtSym)(const char* sym, void* pc)) {
	rtSym("%KeyDown%key", bbKeyDown);
	rtSym("%KeyHit%key", bbKeyHit);
	rtSym("%GetKey", bbGetKey);
	rtSym("%WaitKey", bbWaitKey);
	rtSym("$TextInput$txt", bbTextInput);
	rtSym("FlushKeys", bbFlushKeys);

	rtSym("%MouseDown%button", bbMouseDown);
	rtSym("%MouseHit%button", bbMouseHit);
	rtSym("%GetMouse", bbGetMouse);
	rtSym("%WaitMouse", bbWaitMouse);
	rtSym("%MouseWait", bbWaitMouse);
	rtSym("%MouseX", bbMouseX);
	rtSym("%MouseY", bbMouseY);
	rtSym("%MouseZ", bbMouseZ);
	rtSym("%MouseXSpeed", bbMouseXSpeed);
	rtSym("%MouseYSpeed", bbMouseYSpeed);
	rtSym("%MouseZSpeed", bbMouseZSpeed);
	rtSym("FlushMouse", bbFlushMouse);
	rtSym("MoveMouse%x%y", bbMoveMouse);

	rtSym("%JoyType%port=0", bbJoyType);
	rtSym("%JoyDown%button%port=0", bbJoyDown);
	rtSym("%JoyHit%button%port=0", bbJoyHit);
	rtSym("%GetJoy%port=0", bbGetJoy);
	rtSym("%WaitJoy%port=0", bbWaitJoy);
	rtSym("%JoyWait%port=0", bbWaitJoy);
	rtSym("#JoyX%port=0", bbJoyX);
	rtSym("#JoyY%port=0", bbJoyY);
	rtSym("#JoyZ%port=0", bbJoyZ);
	rtSym("#JoyU%port=0", bbJoyU);
	rtSym("#JoyV%port=0", bbJoyV);
	rtSym("#JoyPitch%port=0", bbJoyPitch);
	rtSym("#JoyYaw%port=0", bbJoyYaw);
	rtSym("#JoyRoll%port=0", bbJoyRoll);
	rtSym("%JoyHat%port=0", bbJoyHat);
	rtSym("%JoyXDir%port=0", bbJoyXDir);
	rtSym("%JoyYDir%port=0", bbJoyYDir);
	rtSym("%JoyZDir%port=0", bbJoyZDir);
	rtSym("%JoyUDir%port=0", bbJoyUDir);
	rtSym("%JoyVDir%port=0", bbJoyVDir);
	rtSym("FlushJoy", bbFlushJoy);

	rtSym("EnableDirectInput%enable", bbEnableDirectInput);
	rtSym("%DirectInputEnabled", bbDirectInputEnabled);
}