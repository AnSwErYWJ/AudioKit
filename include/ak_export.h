/*************************************************************************
	> File Name: ak_export.h
	> Author: weijie.yuan
	> Mail: yuanweijie1993@gmail.com
	> Created Time: Thu 29 Nov 2018 11:47:31 AM CST
 ************************************************************************/

#ifndef __AK_EXPORT__H
#define __AK_EXPORT__H

#ifdef __cplusplus
extern "C" {
#endif

#if (!(defined AK_CALL) || !(defined AK_IMPORT_OR_EXPORT))
	#if defined _WIN32 || defined _WIN64 || defined WIN32 
		#define AK_CALL __stdcall

		#ifdef AK_IMPLEMENTION
			#define AK_IMPORT_OR_EXPORT __declspec(dllexport)
		#else
			#define AK_IMPORT_OR_EXPORT __declspec(dllimport)
		#endif
	#elif defined __ANDROID__
		#define AK_CALL
		#define AK_IMPORT_OR_EXPORT
		#undef  JNIEXPORT
		#define JNIEXPORT __attribute ((visibility("default")))
	#elif defined __APPLE__
		#define AK_CALL
		#define AK_IMPORT_OR_EXPORT
	#elif defined __unix__
		#define AK_CALL
		#define AK_IMPORT_OR_EXPORT __attribute ((visibility("default")))
	#else
		#define AK_CALL
		#define AK_IMPORT_OR_EXPORT
	#endif
#endif

#ifdef __cplusplus
}
#endif

#endif
