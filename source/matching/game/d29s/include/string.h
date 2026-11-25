#ifndef D28_STRING
#define D28_STRING
#include <../include/stddef.h>
extern "C" { void *memchr(const void*,int,size_t); int memcmp(const void*,const void*,size_t); void *memcpy(void*,const void*,size_t); void *memmove(void*,const void*,size_t); void *memset(void*,int,size_t); char *strchr(const char*,int); char *strrchr(const char*,int); char *strcat(char*,const char*); int strcmp(const char*,const char*); int strcoll(const char*,const char*); char *strcpy(char*,const char*); size_t strlen(const char*); char *strerror(int); char *strncat(char*,const char*,size_t); int strncmp(const char*,const char*,size_t); char *strncpy(char*,const char*,size_t); char *strtok(char*,const char*); size_t strxfrm(char*,const char*,size_t); char *strstr(const char*,const char*); char *strpbrk(const char*,const char*); size_t strspn(const char*,const char*); size_t strcspn(const char*,const char*); }
#endif
