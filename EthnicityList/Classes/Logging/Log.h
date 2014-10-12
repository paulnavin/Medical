#ifndef __LOGGING_LOG_H__
#define __LOGGING_LOG_H__

#include <cocos2d.h>

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
  #define  LOG_TAG    "apollo-reignited"
  #define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
  #define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
  #include <stdio.h>
  #include <Windows.h>
  #define  LOGD(...) {char output[102]; int length = snprintf(output, 100, __VA_ARGS__); output[length] = '\n'; output[length + 1] = '\0'; OutputDebugStringA(output); }
  #define  LOGE(...) printf(__VA_ARGS__); \
           fflush(stdout)
#endif
//
//class Log
//{
//  public:
//    static void LogDebug(const char* format, ...);
//    static void LogError(const char* format, ...);
//};

#endif // __LOGGING_LOG_H__
