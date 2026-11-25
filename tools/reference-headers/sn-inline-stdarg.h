/* Observed SN v1.46 System V va_start profile. The compiler creates a
 * __va_list_tag save descriptor; typed assignment reproduces the native
 * inlined12-byte copy rather than an out-of-line builtin memcpy call.
 * This reference-only profile is selected per unit, not imposed on Lua.
 */
#ifndef W3D_SN_INLINE_STDARG_H
#define W3D_SN_INLINE_STDARG_H
#include <stdarg.h>
#undef va_start
#define va_start(AP,LAST) \
    (__builtin_next_arg(LAST), *(AP) = *(struct __va_list_tag *)__builtin_saveregs())
#endif
