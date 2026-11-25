#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_small_r.c"
/* Slot flags, owner forwards, indexed float lookup and a Lua check. */
extern void fn_80307e24(int, int, int, int, int, int);

void w3d_s20_enable_slot_flag_8016c014(Ptr32<char> self, int index) {
    int offset = index * 4;
    Ptr32<char> table = self + 328;
    if (*(Ptr32<int>)(table + offset) != 1) {
        *(Ptr32<int>)(self + 304) = 0;
        fn_80307e24(index, 1, 4, 60, 0, 125);
        *(Ptr32<int>)(table + offset) = 1;
    }
}

extern void fn_801ef380(Ptr32<char>, int, int, int, int);
extern void fn_801ef174(Ptr32<char>, int, int, Ptr32<char>);

int w3d_s20_forward_owner_801750f4(Ptr32<char> self, Ptr32<char> item) {
    Ptr32<char> owner = *(Ptr32<Ptr32<char>>)(self + 120);
    int value = *(Ptr32<int>)(*(Ptr32<Ptr32<char>>)(owner + 44) + 24);
    if (value != 0)
        fn_801ef380(owner, 44, 3, 0, value);
    fn_801ef174(*(Ptr32<Ptr32<char>>)(self + 120), 44, 3, item);
    return 0;
}

extern int fn_80177eb0(Ptr32<char>, Ptr32<void>, Ptr32<unsigned short>);
extern int fn_80342a74(int);
extern float fn_80178df0(Ptr32<void>);

int w3d_s20_get_float_80176a44(Ptr32<char> self, int key, Ptr32<float> out) {
    unsigned short index;
    if (fn_80177eb0(self, w3d::G(key), &index) < 0)
        return 0x80004005;
    *out = fn_80178df0(w3d::G(fn_80342a74(*(Ptr32<int>)(*(Ptr32<Ptr32<char>>)(self + 24) + index * 4))));
    return 0;
}

extern void fn_802cd99c(Ptr32<void>, int);
extern void fn_802ce264(Ptr32<void>, int);
extern int fn_802cda44(Ptr32<void>, int);
extern int fn_8019eed4(Ptr32<void>, Ptr32<char>, int);
extern char lbl_803a99f8[];

int w3d_s20_check_lua_function_8019f838(Ptr32<void> L) {
    fn_802cd99c(L, 2);
    fn_802ce264(L, -10002);
    if (fn_802cda44(L, -1) != 0)
        return 1;
    return fn_8019eed4(L, lbl_803a99f8, 0);
}

}
