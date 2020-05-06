#pragma once


#ifdef NDEBUG
#define presume(expression) ((void)0)
#undef NDEBUG
#include <assert.h>
#define NDEBUG
#else
#define presume(expression) assert(expression)
#include <assert.h>
#endif