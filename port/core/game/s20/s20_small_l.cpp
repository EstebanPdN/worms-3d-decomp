#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_small_l.c"
/* Table store with owner dispatch and a global forwarder. */
typedef Ptr32<int (Ptr32<char>, Ptr32<char>)> S20DispatchL;

int w3d_s20_store_and_dispatch_801a3190(Ptr32<char> self, int index, Ptr32<char> object) {
    Ptr32<char> owner;
    Ptr32<char> table = *(Ptr32<Ptr32<char>>)(self + 72);
    int offset = index * 4;
    Ptr32<char> sub;
    *(Ptr32<Ptr32<char>>)(table + offset) = object;
    owner = *(Ptr32<Ptr32<char>>)(self + 20);
    sub = owner ? w3d::R(owner + 4) : 0;
    return ((S20DispatchL)(*(Ptr32<Ptr32<Ptr32<void>>>)(sub + 24))[*(Ptr32<unsigned short>)(object + 6)])(sub, object);
}

extern int fn_800e5f98(Ptr32<void>, int, int, int, int, int);
extern Ptr32<void> lbl_804aaecc;

int w3d_s20_forward_global5_800e5cf0(int a, int b, int c, int d, int e) {
    if (lbl_804aaecc == 0)
        return 0;
    return fn_800e5f98(lbl_804aaecc, a, b, c, d, e);
}

}
