#include "w3d_ptr.h"
#line 1 "k10b_dispatch_message_80161ce8.cpp"
// Partial view of a message handler. A message starts with a 16-bit id; bit 15
// marks ids that are looked up in four parallel 12-byte-stride tables (bases
// held in small-data pointers) before the owner is notified.
struct K10bMessage_80161ce8;

struct K10bMessageVtable_80161ce8 {
    Ptr32<void> slot0;
    Ptr32<void> slot1;
    Ptr32<int (Ptr32<K10bMessage_80161ce8>)> check;
};

struct K10bMessage_80161ce8 {
    unsigned short id;
    unsigned short padding;
    Ptr32<K10bMessageVtable_80161ce8> vtable;
};

extern "C" {
int fn_8016293c(Ptr32<void> owner, Ptr32<K10bMessage_80161ce8> message);
void fn_80161dd0(Ptr32<void> owner);
void fn_801623dc(Ptr32<void> entry, Ptr32<K10bMessage_80161ce8> message);
void fn_80162480(Ptr32<void> owner);
extern Ptr32<char> lbl_804ab4ac;
extern Ptr32<char> lbl_804ab4b4;
extern Ptr32<char> lbl_804ab4b0;
extern Ptr32<char> lbl_804ab4b8;

int w3d_k10b_dispatch_message_80161ce8(Ptr32<void> owner, Ptr32<K10bMessage_80161ce8> message) {
    unsigned int id = message->id;
    if (id == 64) {
        if (fn_8016293c(owner, message) >= 0) {
            fn_80161dd0(owner);
            return 0;
        }
        return 0x80004005;
    }
    if (id & 0x8000) {
        if (message->vtable->check(message) == 0) {
            unsigned int index = id & ~0x8000;
            index *= 12;
            fn_801623dc(lbl_804ab4ac + index, message);
            fn_801623dc(lbl_804ab4b4 + index, message);
            fn_801623dc(lbl_804ab4b0 + index, message);
            fn_801623dc(lbl_804ab4b8 + index, message);
        }
        fn_80162480(owner);
    }
    return fn_8016293c(owner, message);
}
}


