#ifndef W3D_STRING_H
#define W3D_STRING_H
#include "w3d_libc_decl.h"
#include <stddef.h>
extern "C" {
Ptr32<void> memcpy(Ptr32<void>, Ptr32<const void>, size_t) W3D_LIBC(memcpy);
Ptr32<void> memmove(Ptr32<void>, Ptr32<const void>, size_t) W3D_LIBC(memmove);
Ptr32<void> memset(Ptr32<void>, int, size_t) W3D_LIBC(memset);
int memcmp(Ptr32<const void>, Ptr32<const void>, size_t) W3D_LIBC(memcmp);
Ptr32<void> memchr(Ptr32<const void>, int, size_t) W3D_LIBC(memchr);
size_t strlen(Ptr32<const char>) W3D_LIBC(strlen);
int strcmp(Ptr32<const char>, Ptr32<const char>) W3D_LIBC(strcmp);
int strncmp(Ptr32<const char>, Ptr32<const char>, size_t) W3D_LIBC(strncmp);
int strcoll(Ptr32<const char>, Ptr32<const char>) W3D_LIBC(strcoll);
Ptr32<char> strcpy(Ptr32<char>, Ptr32<const char>) W3D_LIBC(strcpy);
Ptr32<char> strncpy(Ptr32<char>, Ptr32<const char>, size_t) W3D_LIBC(strncpy);
Ptr32<char> strcat(Ptr32<char>, Ptr32<const char>) W3D_LIBC(strcat);
Ptr32<char> strncat(Ptr32<char>, Ptr32<const char>, size_t) W3D_LIBC(strncat);
Ptr32<char> strchr(Ptr32<const char>, int) W3D_LIBC(strchr);
Ptr32<char> strrchr(Ptr32<const char>, int) W3D_LIBC(strrchr);
Ptr32<char> strstr(Ptr32<const char>, Ptr32<const char>) W3D_LIBC(strstr);
Ptr32<char> strpbrk(Ptr32<const char>, Ptr32<const char>) W3D_LIBC(strpbrk);
size_t strspn(Ptr32<const char>, Ptr32<const char>) W3D_LIBC(strspn);
size_t strcspn(Ptr32<const char>, Ptr32<const char>) W3D_LIBC(strcspn);
Ptr32<char> strerror(int) W3D_LIBC(strerror);
}
#endif
