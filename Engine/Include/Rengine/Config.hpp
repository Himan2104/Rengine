#pragma once

#define REN_VERSION_MAJOR 0
#define REN_VERSION_MINOR 1
#define REN_VERSION_PATCH 4

#if defined(_WIN32)
    #define REN_PLATFORM_WINDOWS
#elif defined(__unix__)
    #if defined(__linux__)
        #define REN_PLATFORM_LINUX
    #else
        #error "Unsupported OS"
    #endif
#endif

#if defined(REN_PLATFORM_WINDOWS)
    #define REN_EXPORT __declspec(dllexport)
    #define REN_IMPORT __declspec(dllimport)
#elif defined(REN_PLATFORM_LINUX)
    #if __GNUC__ >= 4
        #define REN_EXPORT __attribute__ ((__visibility__ ("default")))
        #define REN_IMPORT __attribute__ ((__visibility__ ("default")))
    #else
        #define REN_EXPORT
        #define REN_IMPORT
    #endif
#endif

#ifdef REN_DEBUG
    #define LOG_EXPORT_STACK_TRACE
#endif

#define REN_API REN_IMPORT