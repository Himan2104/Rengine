#pragma once

#define REN_VERSION_MAJOR 0
#define REN_VERSION_MINOR 1
#define REN_VERSION_PATCH 4
#define REN_VERSION_INTERNAL 9

#define REN_EXPORTS

#ifdef REN_EXPORTS
#define REN_API __declspec(dllexport)
#else
#define REN_API __declspec(dllimport)
#endif

#ifndef REN_DEBUG
#define REN_RELEASE
#endif