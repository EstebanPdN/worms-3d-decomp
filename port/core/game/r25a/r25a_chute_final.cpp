#include "w3d_ptr.h"
#line 1 "r25a_chute_final.cpp"
// GWMP8P rev0. Names inferred from instructions and original Worm.Chute string.
// Allocation, cached message identifiers, string lifetime and dispatch remain external.
// Observed stack string is one PPC32 word; ownership services remain external.
struct SharedString_8020bb54 {
    Ptr32<void> value;
    template <class W3dU> SharedString_8020bb54(Ptr32<W3dU> w3d_p) : SharedString_8020bb54((const char *)w3d_p.get()) {}
 SharedString_8020bb54(const char *);
    inline ~SharedString_8020bb54();
};
typedef SharedString_8020bb54 SharedString;
struct ChuteObject { unsigned char unknown[20]; int target; unsigned char gap[8]; int handle; };
struct Message;
extern "C" {
void fn_8020c5c4(Ptr32<SharedString>);
void fn_80341588(Ptr32<SharedString>);
Ptr32<void> fn_8015adf4(Ptr32<SharedString>, Ptr32<int>, int);
int fn_8015f5a0(Ptr32<void>, int);
Ptr32<Message> fn_801613f0(Ptr32<void>, unsigned int);
Ptr32<Message> fn_801190b4(Ptr32<Message>, unsigned short, int);
int fn_8016239c(Ptr32<Message>);
extern char lbl_8038975c[];
extern unsigned int lbl_804aeb8c;
extern Ptr32<void> lbl_804b1754;
}
inline SharedString_8020bb54::~SharedString_8020bb54() {
    fn_8020c5c4(this);
    fn_80341588(this);
}
// Field +32 receives the Worm.Chute handle; target +20 is sent in a 12-byte message.
extern "C" void w3d_r25a_initialize_chute_message_800da3fc(Ptr32<ChuteObject> self) {
    {
        SharedString text(lbl_8038975c);
        fn_8015adf4(&text, &self->handle, 255);
    }
    Ptr32<Message> message = fn_801613f0(lbl_804b1754, 12);
    fn_8016239c(fn_801190b4(message,
        (unsigned short)fn_8015f5a0(&lbl_804aeb8c, 1), self->target));
}


