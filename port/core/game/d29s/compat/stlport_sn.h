/* Build configuration for unmodified STLport under the ProDG 3.7 cc1plus route.
 * The reference preprocessor does not predefine __GNUC__. The malloc allocator
 * is the stock STLport option witnessed by the original: allocation calls
 * 0x80212fd4 with the fallback 0x803413d8, which is __malloc_alloc::allocate. */
#ifndef D29S_STLPORT_SN_H
#define D29S_STLPORT_SN_H
#define __GNUC__ 2
#define __GNUC_MINOR__ 95
#define _STLP_NO_IOSTREAMS 1
#define _STLP_NO_NEW_IOSTREAMS 1
#define _NOTHREADS 1
#define _STLP_NO_THREADS 1
#define _STLP_USE_MALLOC 1
#endif
