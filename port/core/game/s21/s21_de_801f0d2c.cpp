#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_de_801f0d2c.c"
// desc: Appears to create an 88-byte typed entry, construct and initialize it from a source descriptor, copy two callback pairs into it and append it to the container.
struct S21Pair { int a; int b; };
struct S21Entry { char pad[4]; Ptr32<void> vtable; char pad1[64]; struct S21Pair first; struct S21Pair second; };
struct S21Source { char pad[20]; struct S21Pair first; struct S21Pair second; };
extern Ptr32<void> fn_801fe1d8(int);
extern void fn_801eb058(Ptr32<void>);
extern void fn_801eb0a8(Ptr32<struct S21Entry>, Ptr32<struct S21Source>);
extern int fn_801e8bc4(Ptr32<void>, Ptr32<struct S21Entry>);
extern char lbl_804178e0[];
Ptr32<struct S21Entry> w3d_s21_create_typed_801f0d2c(Ptr32<void> container, Ptr32<struct S21Source> source)
{
    Ptr32<struct S21Entry> entry = fn_801fe1d8(88);
    struct S21Pair first, second;
    fn_801eb058(entry);
    entry->vtable = lbl_804178e0;
    fn_801eb0a8(entry, source);
    first = source->first;
    second = source->second;
    entry->second = second;
    entry->first = first;
    fn_801e8bc4(container, entry);
    return entry;
}

}
