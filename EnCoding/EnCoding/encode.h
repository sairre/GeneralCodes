#ifndef ENCODE_H
#define ENCODE_H
#include <stdio.h>
#include <windows.h>
#include <locale.h>
wchar_t * ANSIToUnicode(const char* str);
char * UnicodeToANSI(const wchar_t* str);
wchar_t * UTF8ToUnicode(const char* str);
char * UnicodeToUTF8(const wchar_t* str);
char* w2m(const wchar_t* wcs);
wchar_t* m2w(const char* mbs);
char* ANSIToUTF8(const char* str);
char* UTF8ToANSI(const char* str);
#endif