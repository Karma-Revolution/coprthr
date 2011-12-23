
#ifndef _UTIL
#define _UTIL

#ifdef _WIN64
#include "fix_windows.h"
#else
#include <sys/types.h>
#include <unistd.h>
#endif

#include <stdio.h>

#ifdef _WIN64
#define ERROR CLERROR
#endif

#ifdef _WIN64
#define ERROR CLERROR
#endif


#ifdef CLLD_DEBUG

#define DEBUG(f,l,msg,...)  do { \
	fprintf(stderr,"[%d]clld: debug: %s(%d): " msg "\n", \
		getpid(),f,l,##__VA_ARGS__); \
	fflush(stderr); \
	} while(0)

#define DEBUG2(msg,...)  do { \
	fprintf(stderr, "[%d]clld: debug: %s(%d): " msg "\n", \
		getpid(),__FILE__,__LINE__,##__VA_ARGS__); \
	fflush(stderr); \
	} while(0)

#else 

#define DEBUG(f,l,msg,...)  do {} while(0)

#define DEBUG2(msg,...)  do {} while(0)

#endif


#if defined(CLLD_WARN) || defined(CLLD_DEBUG)

//#define WARN(f,l,msg)  \
//	fprintf(stderr,"clld: warning: %s(%d): " msg "\n",f,l); 
#define WARN(f,l,msg,...)  do { \
	fprintf(stderr,"[%d]clld: warning: %s(%d): " msg "\n", \
		getpid(),f,l,##__VA_ARGS__); \
	fflush(stderr); \
	} while (0)

#define WARN2(msg,...)  do { \
	fprintf(stderr,"[%d]clld: warning: %s(%d): " msg "\n", \
		getpid(),__FILE__,__LINE__,##__VA_ARGS__); \
	fflush(stderr); \
	} while (0)

#else

#define WARN(f,l,msg) do {} while(0)

#define WARN2(msg,...)  do {} while(0)

#endif


//#define ERROR(f,l,msg) \
//	fprintf(stderr,"clld: error: %s(%d): " msg "\n",f,l); 
#define ERROR(f,l,msg,...)  do { \
	fprintf(stderr,"[%d]clld: warning: %s(%d): " msg "\n", \
		getpid(),f,l,##__VA_ARGS__); \
	fflush(stderr); \
	} while(0)

#define ERROR2(msg,...)  do { \
	fprintf(stderr,"[%d]clld: warning: %s(%d): " msg "\n", \
		getpid(),__FILE__,__LINE__,##__VA_ARGS__); \
	fflush(stderr); \
	} while(0)


#endif
