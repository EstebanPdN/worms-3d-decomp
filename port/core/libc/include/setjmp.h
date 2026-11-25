#ifndef W3D_SETJMP_H
#define W3D_SETJMP_H
// Buffer anfitrión: nunca forma parte de una estructura guardada ni cruza plataformas.
typedef int jmp_buf[64];
extern "C" {
int setjmp(int *) __asm__(W3D_SYM("setjmp")) __attribute__((returns_twice));
void longjmp(int *, int) __asm__(W3D_SYM("longjmp")) __attribute__((noreturn));
}
#endif
