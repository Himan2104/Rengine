#pragma once

#define REN_VERSION_MAJOR 0
#define REN_VERSION_MINOR 1
#define REN_VERSION_PATCH 4
#define REN_VERSION_INTERNAL 9

#ifdef REN_EXPORTS
#define REN_API __declspec(dllexport)
#else
#define REN_API __declspec(dllimport)
#endif