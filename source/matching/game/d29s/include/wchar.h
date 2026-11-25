/* Only the types <cwchar> names; no wide character function is used by the game code. */
#ifndef D29S_WCHAR_H
#define D29S_WCHAR_H
#include <../include/stddef.h>
typedef struct { int __count; int __value; } mbstate_t;
extern "C" { size_t wcslen(const wchar_t *); int wcscmp(const wchar_t *, const wchar_t *); int wcsncmp(const wchar_t *, const wchar_t *, size_t); wchar_t *wmemcpy(wchar_t *, const wchar_t *, size_t); wchar_t *wmemmove(wchar_t *, const wchar_t *, size_t); wchar_t *wmemset(wchar_t *, wchar_t, size_t); int wmemcmp(const wchar_t *, const wchar_t *, size_t); const wchar_t *wmemchr(const wchar_t *, wchar_t, size_t); }
#endif
