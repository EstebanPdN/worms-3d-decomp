#ifndef W3D_STDIO_H
#define W3D_STDIO_H
#include "w3d_libc_decl.h"
#include <stddef.h>
#include <stdarg.h>
#define EOF (-1)
#define BUFSIZ 1024
#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2
#define L_tmpnam 32
struct __w3d_FILE;
typedef struct __w3d_FILE FILE;
extern "C" {
extern Ptr32<FILE> __w3d_stdin __asm__(W3D_SYM("w3d_stdin_"));
extern Ptr32<FILE> __w3d_stdout __asm__(W3D_SYM("w3d_stdout_"));
extern Ptr32<FILE> __w3d_stderr __asm__(W3D_SYM("w3d_stderr_"));
int printf(Ptr32<const char>, ...) W3D_LIBC(printf);
int puts(Ptr32<const char>) W3D_LIBC(puts);
int fprintf(Ptr32<FILE>, Ptr32<const char>, ...) W3D_LIBC(fprintf);
int sprintf(Ptr32<char>, Ptr32<const char>, ...) W3D_LIBC(sprintf);
int vsprintf(Ptr32<char>, Ptr32<const char>, va_list) W3D_LIBC(vsprintf);
int snprintf(Ptr32<char>, size_t, Ptr32<const char>, ...) W3D_LIBC(snprintf);
int sscanf(Ptr32<const char>, Ptr32<const char>, ...) W3D_LIBC(sscanf);
Ptr32<FILE> fopen(Ptr32<const char>, Ptr32<const char>) W3D_LIBC(fopen);
Ptr32<FILE> freopen(Ptr32<const char>, Ptr32<const char>, Ptr32<FILE>) W3D_LIBC(freopen);
int fclose(Ptr32<FILE>) W3D_LIBC(fclose);
size_t fread(Ptr32<void>, size_t, size_t, Ptr32<FILE>) W3D_LIBC(fread);
size_t fwrite(Ptr32<const void>, size_t, size_t, Ptr32<FILE>) W3D_LIBC(fwrite);
int fseek(Ptr32<FILE>, int, int) W3D_LIBC(fseek);
int ftell(Ptr32<FILE>) W3D_LIBC(ftell);
int feof(Ptr32<FILE>) W3D_LIBC(feof);
int ferror(Ptr32<FILE>) W3D_LIBC(ferror);
int fflush(Ptr32<FILE>) W3D_LIBC(fflush);
int getc(Ptr32<FILE>) W3D_LIBC(getc);
int ungetc(int, Ptr32<FILE>) W3D_LIBC(ungetc);
Ptr32<char> fgets(Ptr32<char>, int, Ptr32<FILE>) W3D_LIBC(fgets);
int fputs(Ptr32<const char>, Ptr32<FILE>) W3D_LIBC(fputs);
}
#define stdin __w3d_stdin
#define stdout __w3d_stdout
#define stderr __w3d_stderr
#endif
