#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_msg_a.c"
/* Message posting helpers. */
typedef struct S20Msg { short id; short pad; Ptr32<void> table; } S20Msg;
extern Ptr32<S20Msg> fn_801613f0(Ptr32<void>, int);
extern short fn_8015f5a0(Ptr32<void>, int);
extern unsigned int fn_8015fc58(Ptr32<char>, Ptr32<S20Msg>);
extern void fn_8015884c(Ptr32<char>);
extern Ptr32<void> lbl_804b1754;
extern char lbl_804afe70;
extern char lbl_8040db38[];

void w3d_s20_reset_with_message_80156190(Ptr32<char> self) {
    Ptr32<S20Msg> message = fn_801613f0(lbl_804b1754, 8);
    Ptr32<int> slot;
    int zero;
    int i;
    {
        short id = fn_8015f5a0(&lbl_804afe70, 1);
        message->id = id;
        message->table = lbl_8040db38;
    }
    fn_8015fc58(self, message);
    fn_8015884c(self);
    zero = 0;
    slot = (Ptr32<int>)(self + 312);
    for (i = 16; i != zero; i--) {
        *slot = -1;
        slot++;
    }
}

}
