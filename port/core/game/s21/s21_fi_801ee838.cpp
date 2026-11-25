#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_fi_801ee838.c"
// desc: Appears to be a destructor body that releases every interface of the counted array at offset 32, installs the base vtable and destroys the embedded node.
struct S21Ref;
struct S21RefMethods { Ptr32<void (void)> reserved[4]; Ptr32<void (Ptr32<struct S21Ref>)> release; };
struct S21Ref { Ptr32<struct S21RefMethods> methods; };
struct S21Object { Ptr32<void> vtable; char node[20]; int count; char pad[4]; Ptr32<struct S21Ref> items[1]; };
extern char lbl_804176a0[];
extern char lbl_80411ac0[];
extern void fn_80210990(Ptr32<void>, int);
void w3d_s21_destroy_refs_b_801ee838(Ptr32<struct S21Object> self)
{
    int count = self->count;
    Ptr32<Ptr32<struct S21Ref>> strings = self->items;
    Ptr32<Ptr32<struct S21Ref>> item;
    int remaining;
    self->vtable = lbl_804176a0;
    if (count > 0) {
        item = strings;
        remaining = count;
        do {
            Ptr32<struct S21Ref> ref = *item;
            item++;
            if (ref)
                ref->methods->release(ref);
        } while (--remaining);
    }
    self->vtable = lbl_80411ac0;
    fn_80210990(self->node, 0);
}

}
