#pragma once


#ifdef REN_EXPORTS
#define REN_API __declspec(dllexport)
#else
#define REN_API __declspec(dllimport)
#endif