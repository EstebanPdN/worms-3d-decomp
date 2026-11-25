#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_df_801eb9f8.c"
// desc: Appears to create a 28-byte typed entry like its sibling with another vtable, copying two callback pairs and a flag byte and appending it to the container.
struct S21Pair { int a; int b; };
struct S21Entry { char pad[4]; Ptr32<void> vtable; unsigned char flag; char pad1[3]; struct S21Pair first; struct S21Pair second; };
struct S21Source { char pad[20]; struct S21Pair first; struct S21Pair second; unsigned char flag; };
extern Ptr32<void> fn_801fe1d8(int);
extern void fn_801eb058(Ptr32<void>);
extern void fn_801eb0a8(Ptr32<struct S21Entry>, Ptr32<struct S21Source>);
extern int fn_801e8bc4(Ptr32<void>, Ptr32<struct S21Entry>);
extern char lbl_80417570[];
Ptr32<struct S21Entry> w3d_s21_create_typed_801eb9f8(Ptr32<void> container, Ptr32<struct S21Source> source)
{
    Ptr32<struct S21Entry> entry = fn_801fe1d8(28);
    unsigned char flag;
    struct S21Pair first, second;
    fn_801eb058(entry);
    entry->vtable = lbl_80417570;
    fn_801eb0a8(entry, source);
    first = source->first;
    second = source->second;
    flag = source->flag;
    entry->first = first;
    entry->second = second;
    entry->flag = flag;
    fn_801e8bc4(container, entry);
    return entry;
}

}
