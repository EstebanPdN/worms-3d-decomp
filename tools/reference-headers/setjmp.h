#ifndef W3D_REFERENCE_SETJMP_H
#define W3D_REFERENCE_SETJMP_H
/* Reference ABI surface, not a portable setjmp implementation.
 * Original luaD_throw (802cfc7c) uses buffer offset 8 and status 108.
 * luaD_rawrunprotected (802cfcc0) independently confirms this layout.
 * Native setjmp/longjmp at 802efe74/802eff30 save GPR and FPR state.
 * A 0x100-byte, double-aligned buffer reproduces the observed container.
 * This representation does not claim the original header's type spelling.
 */
typedef double jmp_buf[32];
int setjmp(jmp_buf);
void longjmp(jmp_buf, int) __attribute__((noreturn));
#endif
