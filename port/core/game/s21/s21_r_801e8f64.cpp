#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_r_801e8f64.c"
// desc: Appears to scan a global list of registered objects for one whose 16-byte identifier equals the given one and return its packed field.
struct S21Item { char pad[32]; unsigned packed; };
struct S21ItemList { Ptr32<Ptr32<struct S21Item>> begin; Ptr32<Ptr32<struct S21Item>> end; };
extern struct S21ItemList lbl_8045e080[];
extern Ptr32<const void> fn_801fff3c(Ptr32<struct S21Item>);
extern int fn_802eedc0(Ptr32<const void>, Ptr32<const void>, int);
int w3d_s21_find_item_class_801e8f64(Ptr32<const void> id, Ptr32<unsigned int> out)
{
    Ptr32<Ptr32<struct S21Item>> item = lbl_8045e080[0].begin;
    Ptr32<Ptr32<struct S21Item>> end = lbl_8045e080[0].end;
    for (; item != end; item++) {
        if (*item && fn_802eedc0(fn_801fff3c(*item), id, 16) == 0) {
            *out = (*item)->packed >> 22;
            return 0;
        }
    }
    return 0x80004005;
}

}
