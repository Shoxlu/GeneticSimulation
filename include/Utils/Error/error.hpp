#pragma once
#include <stdio.h>
#include <stdarg.h>

void stub_print(const char* a, ...);

#ifndef DISPLAY_ERROR_NOPRINT
#define log_printf printf
#else
#define log_printf stub_print
#endif
