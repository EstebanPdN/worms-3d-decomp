#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_cx_801ed24c.c"
// desc: Appears to create a 28-byte entry, initialize it from a source descriptor, copy two eight-byte callback pairs into it and append it to the container, returning the entry.
struct S21Pair { int a; int b; };
struct S21Entry { char pad[12]; struct S21Pair first; struct S21Pair second; };
struct S21Source { char pad[20]; struct S21Pair first; struct S21Pair second; };
extern Ptr32<void> fn_801fe1d8(int);
extern Ptr32<struct S21Entry> fn_801ed16c(Ptr32<void>);
extern void fn_801eb0a8(Ptr32<struct S21Entry>, Ptr32<struct S21Source>);
extern int fn_801e8bc4(Ptr32<void>, Ptr32<struct S21Entry>);
Ptr32<struct S21Entry> w3d_s21_create_entry_801ed24c(Ptr32<void> container, Ptr32<struct S21Source> source)
{
    Ptr32<struct S21Entry> entry = fn_801ed16c(fn_801fe1d8(28));
    fn_801eb0a8(entry, source);
    entry->first = source->first;
    entry->second = source->second;
    fn_801e8bc4(container, entry);
    return entry;
}

}
