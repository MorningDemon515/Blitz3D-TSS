#ifndef BBAUDIO_H
#define BBAUDIO_H

#include "bbsys.h"

int          bbLoadSound(BBStr* file);
void		 bbFreeSound(int sound);
int          bbPlaySound(int sound);
void		 bbLoopSound(int sound);
void		 bbSoundPitch(int sound, int pitch);
void		 bbSoundVolume(int sound, float volume);
void		 bbSoundPan(int sound, float pan);
int          bbPlayMusic(BBStr* s, int mode);
int          bbPlayCDTrack(int track, int mode);
void		 bbStopChannel(int channel);
void		 bbPauseChannel(int channel);
void		 bbResumeChannel(int channel);
void		 bbChannelPitch(int channel, int pitch);
void		 bbChannelVolume(int channel, float volume);
void		 bbChannelPan(int channel, float pan);
int			 bbChannelPlaying(int channel);

#endif
