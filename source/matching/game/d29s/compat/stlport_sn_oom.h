/* The original's out-of-memory loop at 0x803413d8 calls the handler with no null
 * check and carries no message text, so STLport's throw macro was empty in that build.
 * That function exists once in the program, so other units only declare it. */
#ifndef D29S_STLPORT_SN_OOM_H
#define D29S_STLPORT_SN_OOM_H
#include "stlport_sn.h"
#define __THROW_BAD_ALLOC
#include <stl/_alloc.h>
template <> void *_STL::__malloc_alloc<0>::_S_oom_malloc(size_t);
#endif
