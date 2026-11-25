#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_ee_801ddf5c.c"
// desc: Appears to append an interface object to a growable array: it reserves one more slot, retains the new object, releases whatever the slot held, stores it, bumps the count and returns one.
struct S21Ref;
struct S21RefMethods { Ptr32<void (void)> reserved[3]; Ptr32<void (Ptr32<struct S21Ref>)> retain; Ptr32<void (Ptr32<struct S21Ref>)> release; };
struct S21Ref { Ptr32<struct S21RefMethods> methods; };
struct S21Array { unsigned count; int reserved; Ptr32<Ptr32<struct S21Ref>> items; };
struct S21Object { char pad[20]; struct S21Array array; };
extern void fn_80210d54(Ptr32<struct S21Array>, unsigned);
int w3d_s21_append_ref_801ddf5c(Ptr32<struct S21Object> self, Ptr32<struct S21Ref> ref)
{
    Ptr32<struct S21Array> array = &self->array;
    unsigned offset;
    Ptr32<Ptr32<struct S21Ref>> items;
    fn_80210d54(array, array->count + 1);
    offset = self->array.count << 2;
    items = array->items;
    if (ref)
        ref->methods->retain(ref);
    if (*(Ptr32<Ptr32<struct S21Ref>>)w3d::G((offset + (unsigned)w3d::H(items))))
        (*(Ptr32<Ptr32<struct S21Ref>>)w3d::G((offset + (unsigned)w3d::H(items))))->methods->release(*(Ptr32<Ptr32<struct S21Ref>>)w3d::G((offset + (unsigned)w3d::H(items))));
    *(Ptr32<Ptr32<struct S21Ref>>)w3d::G((offset + (unsigned)w3d::H(items))) = ref;
    self->array.count++;
    return 1;
}

}
