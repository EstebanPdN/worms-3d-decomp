#include "w3d_ptr.h"
#line 1 "s8hand_800eba70.cpp"
struct s8_Message { short id; short pad2; Ptr32<void> vtable; };
struct s8_Cache { int word0,word1; };
struct s8_ResetContext { char pad0[88]; int state; };
extern Ptr32<void> lbl_804b1754;
extern s8_Cache lbl_804aef08;
extern char lbl_8040db38[];
extern "C" Ptr32<s8_Message> fn_801613f0(Ptr32<void>,int);
extern "C" short fn_8015f5a0(Ptr32<s8_Cache>,int);
extern "C" int fn_8015fc58(Ptr32<s8_ResetContext>,Ptr32<s8_Message>);
extern "C" void s8_reset_typed_800eba70(Ptr32<s8_ResetContext> self) {
    self->state=0;
    Ptr32<s8_Message> message=fn_801613f0(lbl_804b1754,8);
    message->id=fn_8015f5a0(&lbl_804aef08,1);
    message->vtable=lbl_8040db38;
    fn_8015fc58(self,message);
}


