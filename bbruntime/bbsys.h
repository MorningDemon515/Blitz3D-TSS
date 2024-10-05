#ifndef BBSYS_H
#define BBSYS_H

#include "basic.h"

extern bool debug;
extern const char* errorfunc;
extern const char* errorlog;

/*
struct bbEx {
	const char* err;
	//bbEx(const char* e) : err(e)
	//{
		//return ;
	//}
};
*/

#define RTEX( _X_ ) throw bbEx( _X_ );

#endif