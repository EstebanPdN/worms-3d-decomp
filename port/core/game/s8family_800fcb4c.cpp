#include "w3d_ptr.h"
#line 1 "s8family_800fcb4c.cpp"
extern Ptr32<void> lbl_8044a5e4[];
extern "C" Ptr32<void> fn_80341584(Ptr32<void>);
extern "C" int fn_801797b4(Ptr32<void>);
extern "C" int s8_index_query_800fcb4c(int index) {
    return fn_801797b4(fn_80341584(*(Ptr32<Ptr32<void>>)w3d::G(((index * 4) + (unsigned)w3d::H(lbl_8044a5e4)))));
}


