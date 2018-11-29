/*************************************************************************
	> File Name: ak_import_version.h
	> Author: weijie.yuan
	> Mail: yuanweijie1993@gmail.com
	> Created Time: Thu 29 Nov 2018 11:08:05 AM CST
 ************************************************************************/

#ifndef __AK_IMPORT_VERSION__H
#define __AK_IMPORT_VERSION__H

#ifdef __cplusplus
extern "C" {
#endif

#define AK_MAJOR  	   (0)
#define AK_MINOR       (0)
#define AK_REVISION    (1)

#define STRINGIFY(x) (#x)
#define TOSTRING(x) STRINGIFY(x)

#define AK_VERSION_NUM  (((AK_MAJOR)%100)*10000 + ((AK_MINOR)%100)*100 + ((AK_REVISION)%100))

#define AK_VERSION_STRING TOSTRING(AK_MAJOR) "." TOSTRING(AK_MINOR) "." TOSTRING(AK_REVISION)

#define AK_VERSION_TEXT "AudioKits V" AK_VERSION_STRING " " __DATE__ " " __TIME__

#ifdef __cplusplus
}
#endif

#endif
