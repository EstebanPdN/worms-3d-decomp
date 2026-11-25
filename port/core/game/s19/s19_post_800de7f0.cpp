#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_post_800de7f0.c"
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
extern Ptr32<void> FUN_801613f0(Ptr32<void>, int);
extern Ptr32<void> w3d_auto_8003a264(Ptr32<void>, int, int);
extern int w3d_message_post_current(Ptr32<void>);
extern Ptr32<void> lbl_804b1754;
extern int lbl_804b17a0;

void s19_post_selected_800de7f0(Ptr32<void> self)
{
    int flag;
    if (FIELD(self, int, 176) != -1) {
        w3d_message_post_current(w3d_auto_8003a264(FUN_801613f0(lbl_804b1754, 12), FIELD(self, int, 176), FIELD(self, int, 180)));
        flag = lbl_804b17a0;
        if (flag == 0)
            FIELD(self, char, 104) = flag;
    }
}

}
