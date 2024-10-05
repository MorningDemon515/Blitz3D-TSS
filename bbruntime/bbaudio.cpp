#include "std.h"
#include "bbaudio.h"
#include "../MultiLang/MultiLang.h"

int bbVerifySound(int sound) {
	return 0;
}

int bbLoadSound(BBStr* f) {
	return 0;
}

void bbFreeSound(int sound) {
	
}

void bbLoopSound(int sound) {
	
}

void bbSoundPitch(int sound, int pitch) {
	
}

void bbSoundVolume(int sound, float volume) {
	
}

void bbSoundPan(int sound, float pan) {
	
}

int bbPlaySound(int sound) {

	return 0;
}

int bbPlayMusic(BBStr* f, int mode) {
	return 0;
}

int bbPlayCDTrack(int track, int mode) {
	return 0;
}

void bbStopChannel(int channel) {
	
}

void bbPauseChannel(int channel) {
	
}

void bbResumeChannel(int channel) {
	
}

void bbChannelPitch(int channel, int pitch) {
	
}

void bbChannelVolume(int channel, float volume) {
	
}

void bbChannelPan(int channel, float pan) {
	
}

int bbChannelPlaying(int channel) {
	return 0;
}

int bbLoad3DSound(BBStr* f) {
	return 0;
}
bool audio_create() {

	return true;
}

bool audio_destroy() {
	
	return true;
}



void audio_link(void(*rtSym)(const char*, void*)) {
	rtSym("%VerifySound%sound", bbVerifySound);
	rtSym("%LoadSound$filename", bbLoadSound);
	rtSym("FreeSound%sound", bbFreeSound);
	rtSym("LoopSound%sound", bbLoopSound);
	rtSym("SoundPitch%sound%pitch", bbSoundPitch);
	rtSym("SoundVolume%sound#volume", bbSoundVolume);
	rtSym("SoundPan%sound#pan", bbSoundPan);
	rtSym("%PlaySound%sound", bbPlaySound);
	rtSym("%PlayMusic$midifile%mode=0", bbPlayMusic);
	rtSym("%PlayCDTrack%track%mode=1", bbPlayCDTrack);
	rtSym("StopChannel%channel", bbStopChannel);
	rtSym("PauseChannel%channel", bbPauseChannel);
	rtSym("ResumeChannel%channel", bbResumeChannel);
	rtSym("ChannelPitch%channel%pitch", bbChannelPitch);
	rtSym("ChannelVolume%channel#volume", bbChannelVolume);
	rtSym("ChannelPan%channel#pan", bbChannelPan);
	rtSym("%ChannelPlaying%channel", bbChannelPlaying);
	rtSym("%Load3DSound$filename", bbLoad3DSound);
}