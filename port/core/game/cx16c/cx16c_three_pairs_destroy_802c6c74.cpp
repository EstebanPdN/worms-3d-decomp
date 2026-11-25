#include "w3d_ptr.h"
#line 1 "cx16c_three_pairs_destroy_802c6c74.cpp"

// Observed held interfaces release through slot +16; semantic class names are inferred.
#define CX16C_FIELD(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char*)w3d::AG(p)+(o)))
struct Cx16cHeld { Ptr32<void> held; ~Cx16cHeld() { if(held) ((Ptr32<void (Ptr32<void>)>)(*(Ptr32<Ptr32<void>>)(*(Ptr32<Ptr32<char>>)held+16)))(held); } };
extern "C" void cx16c_context_destroy_802afc40(Ptr32<void>,int);
extern "C" void cx16c_base_destroy_8015ff2c(Ptr32<void>,int);

extern Ptr32<const void> cx16c_table_8041c960[];
extern "C" void cx16c_text_finish_8020c5c4(Ptr32<void>);
extern "C" void cx16c_text_release_80341588(Ptr32<void>);
struct Cx16cText { Ptr32<const char> data; ~Cx16cText() { cx16c_text_finish_8020c5c4(this);cx16c_text_release_80341588(this); } };
struct Cx16cThreePairs {
 Ptr32<const void> table;char reserved[24];Cx16cHeld field28;char gap32[8];
 Cx16cHeld first[2],second[2],third[2],field64;char gap68[24];
 Cx16cHeld field92;char gap96[4];Cx16cText text;
 ~Cx16cThreePairs() {}
};
extern "C" void w3d_cx16c_three_pairs_destroy_802c6c74(Ptr32<void> self,int flags) {
 Ptr32<Cx16cThreePairs> owner=(Ptr32<Cx16cThreePairs>)self;
 owner->table=cx16c_table_8041c960;
 owner->~Cx16cThreePairs();
 cx16c_base_destroy_8015ff2c(self,flags);
}


