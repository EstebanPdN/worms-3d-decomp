#ifndef W3D_REFERENCE_LIBRARY_STRING_H
#define W3D_REFERENCE_LIBRARY_STRING_H
#include_next <string.h>
void *memchr(const void *, int, size_t);
char *strncpy(char *, const char *, size_t);
char *strcat(char *, const char *);
char *strncat(char *, const char *, size_t);
char *strerror(int);
int strcoll(const char *, const char *);
#endif
