#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_df_801f0e4c.c"
// desc: Appears to create a 72-byte typed entry with an embedded member, copying two callback pairs and appending it to the container.
struct S21Pair { int a; int b; };
struct S21Entry { char pad[4]; Ptr32<void> vtable; char pad2[4]; char pad1[44]; struct S21Pair first; struct S21Pair second; };
struct S21Source { char pad[20]; struct S21Pair first; struct S21Pair second; float flag; };
extern Ptr32<void> fn_801fe1d8(int);
extern void fn_801eb058(Ptr32<void>);
extern void fn_801eb0a8(Ptr32<struct S21Entry>, Ptr32<struct S21Source>);
extern int fn_801e8bc4(Ptr32<void>, Ptr32<struct S21Entry>);
extern void fn_80343740(Ptr32<void>);
extern char lbl_804178b0[];
Ptr32<struct S21Entry> w3d_s21_create_typed_801f0e4c(Ptr32<void> container, Ptr32<struct S21Source> source)
{
    Ptr32<struct S21Entry> entry = fn_801fe1d8(72);
    struct S21Pair first, second;
    
    fn_801eb058(entry);
    entry->vtable = lbl_804178b0;
    fn_80343740((Ptr32<char>)entry + 44);
    fn_801eb0a8(entry, source);
    first = source->first;
    second = source->second;
    entry->first = first;
    entry->second = second;
    fn_801e8bc4(container, entry);
    return entry;
}

}
