#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_dtor_a.c"
/* Deleting destructors of classes with a header sub-object at offset 4. */
typedef struct S20Object { Ptr32<Ptr32<void>> vtable; } S20Object;
extern void fn_80210990(Ptr32<char>, int);
extern void fn_801fe1f8(Ptr32<char>);
extern void fn_802134fc(Ptr32<void>);
extern Ptr32<char> lbl_804b1884;
extern char lbl_80411c10[];
extern char lbl_80411c88[];

void w3d_s20_destroy_registered_80166f5c(Ptr32<char> self, int flags) {
    Ptr32<char> registered = lbl_804b1884;
    *(Ptr32<Ptr32<char>>)self = lbl_80411c10;
    if (registered == self)
        lbl_804b1884 = 0;
    *(Ptr32<Ptr32<char>>)self = lbl_80411c88;
    fn_80210990(self + 4, 0);
    if (flags & 1)
        fn_801fe1f8(self);
}

extern char lbl_80413830[];
extern char lbl_80413858[];
extern void fn_802dd884(Ptr32<void>, int, int);

void w3d_s20_destroy_lua_ref_8019e600(Ptr32<char> self, int flags) {
    int reference = *(Ptr32<int>)(self + 24);
    *(Ptr32<Ptr32<char>>)self = lbl_80413830;
    if (reference != 0) {
        Ptr32<S20Object> owner = *(Ptr32<Ptr32<S20Object>>)(self + 20);
        Ptr32<void> state = ((Ptr32<Ptr32<void> (Ptr32<S20Object>)>)owner->vtable[9])(owner);
        fn_802dd884(state, -10000, *(Ptr32<int>)(self + 24));
    }
    *(Ptr32<Ptr32<char>>)self = lbl_80413858;
    fn_80210990(self + 4, 0);
    if (flags & 1)
        fn_801fe1f8(self);
}

extern char lbl_80411a30[];
extern char lbl_80411a88[];
extern void fn_8034ba74(Ptr32<char>);

void w3d_s20_destroy_list_owner_80165af0(Ptr32<char> self, int flags) {
    Ptr32<char> list = self + 24;
    Ptr32<S20Object> held;
    *(Ptr32<Ptr32<char>>)self = lbl_80411a30;
    fn_8034ba74(list);
    if (*(Ptr32<Ptr32<void>>)(list + 4) != 0)
        fn_802134fc(*(Ptr32<Ptr32<void>>)(list + 4));
    held = *(Ptr32<Ptr32<S20Object>>)(self + 20);
    if (held != 0)
        ((Ptr32<void (Ptr32<S20Object>)>)held->vtable[4])(held);
    *(Ptr32<Ptr32<char>>)self = lbl_80411a88;
    fn_80210990(self + 4, 0);
    if (flags & 1)
        fn_801fe1f8(self);
}

extern char lbl_804139c0[];
extern char lbl_804139e0[];
extern int fn_801a18f8(Ptr32<char>);
extern void fn_80210120(Ptr32<char>);
extern int lbl_804ab74c;

void w3d_s20_destroy_service_801a1cf0(Ptr32<char> self, int flags) {
    Ptr32<S20Object> held;
    *(Ptr32<Ptr32<char>>)self = lbl_804139c0;
    fn_801a18f8(self);
    fn_80210120(self);
    held = *(Ptr32<Ptr32<S20Object>>)(self + 32);
    lbl_804ab74c = 0;
    if (held != 0)
        ((Ptr32<void (Ptr32<S20Object>)>)held->vtable[4])(held);
    if (*(Ptr32<Ptr32<void>>)(self + 20) != 0)
        fn_802134fc(*(Ptr32<Ptr32<void>>)(self + 20));
    *(Ptr32<Ptr32<char>>)self = lbl_804139e0;
    fn_80210990(self + 4, 0);
    if (flags & 1)
        fn_801fe1f8(self);
}

}
