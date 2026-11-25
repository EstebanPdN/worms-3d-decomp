#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_adjust_calls.c"
/* Methods that run on the secondary base subobject of an object (this - 4, null-checked). */
extern int fn_801a572c(Ptr32<void>, Ptr32<void>);
extern int fn_801a46bc(Ptr32<void>, Ptr32<void>, Ptr32<void>);
extern int fn_801ad790(Ptr32<void>, Ptr32<char>, Ptr32<char>);
extern int fn_801a59c0(Ptr32<void>, Ptr32<char>);
extern void fn_802cd99c(Ptr32<void>, int);
extern void fn_802ce148(Ptr32<void>, Ptr32<void>, int);
extern void fn_802cdfd4(Ptr32<void>, Ptr32<char>);
extern void fn_802cd8e0(Ptr32<void>, int);
extern void fn_802ce4d8(Ptr32<void>, int);

void w3d_s20_forward_base_field_801a59c0(Ptr32<char> self) {
    Ptr32<char> base = self ? w3d::R(self - 4) : 0;
    fn_801a572c(self, w3d::G(*(Ptr32<int>)(base + 0x18)));
}

void w3d_s20_forward_base_field_801aac8c(Ptr32<char> self, int arg) {
    Ptr32<char> base = self ? w3d::R(self - 4) : 0;
    fn_801a46bc(self, w3d::G(arg), w3d::G(*(Ptr32<int>)(base + 0x38)));
}

void w3d_s20_forward_base_range_801ad8fc(Ptr32<char> self, Ptr32<char> item) {
    Ptr32<char> base = self ? w3d::R(self - 4) : 0;
    fn_801ad790(base, item, item + 20);
}

typedef Ptr32<int (Ptr32<void>)> S20GetSlot;
typedef Ptr32<void (Ptr32<void>, int, Ptr32<char>)> S20PutSlot;

int w3d_s20_apply_base_item_801a59f4(Ptr32<char> self, Ptr32<char> item) {
    Ptr32<char> base = self ? w3d::R(self - 4) : 0;
    int result = fn_801a59c0(self, item);
    if (result >= 0) {
        Ptr32<char> vtable = *(Ptr32<Ptr32<char>>)base;
        ((S20PutSlot)*(Ptr32<Ptr32<void>>)(vtable + 0x50))(base, ((S20GetSlot)*(Ptr32<Ptr32<void>>)(vtable + 0x40))(base), item + 20);
        result = 0;
    }
    return result;
}

void w3d_s20_lua_set_closure_field_801a0384(Ptr32<void> L, Ptr32<char> name, Ptr32<void> function, int index) {
    fn_802cd99c(L, index);
    fn_802ce148(L, function, 1);
    fn_802cdfd4(L, name);
    fn_802cd8e0(L, -2);
    fn_802ce4d8(L, -3);
}

}
