#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_small_c.c"
/* Small forwarding wrappers. */
extern Ptr32<char> fn_8019a2a8(Ptr32<char>, int);
extern void fn_800fde98(Ptr32<void>, int);
extern void fn_800fdf58(Ptr32<void>, int);
extern Ptr32<void> lbl_804aaf64;
extern void fn_8016f650(int);
extern int lbl_803a54e4[];
extern int fn_801720fc(Ptr32<char>, int);

int w3d_s20_has_record_80199f38(Ptr32<char> self, int key) {
    if (fn_8019a2a8(self, key) != 0)
        return 1;
    return 0;
}

void w3d_s20_notify_global_800fde64(int value) {
    if (lbl_804aaf64 != 0)
        fn_800fde98(lbl_804aaf64, value);
}

void w3d_s20_notify_global_800fdf24(int value) {
    if (lbl_804aaf64 != 0)
        fn_800fdf58(lbl_804aaf64, value);
}

int w3d_s20_forward_table_entry_8016a538(Ptr32<char> self, Ptr32<char> item) {
    fn_8016f650(lbl_803a54e4[*(Ptr32<int>)(item + 24)]);
    return 0;
}

int w3d_s20_get_selected_80172050(Ptr32<char> self, Ptr32<void> arg_r4) {
    int index = fn_801720fc(self, w3d::H(arg_r4));
    return *(Ptr32<int>)(*(Ptr32<Ptr32<char>>)(self + 60) + index * 4);
}

}
