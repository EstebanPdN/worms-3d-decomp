#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "tsonnet_c26_blob_801bc7ec.c"
struct Blob { int w[12]; };
struct Rec { int head[2]; struct Blob blob; };
extern char lbl_803ab88c[];
extern char lbl_803ab8b0[];
extern struct Blob lbl_8045e748;
extern Ptr32<struct Rec> fn_801f0e4c(Ptr32<void>, Ptr32<char>);
extern Ptr32<void> fn_801ebf38(Ptr32<void>, Ptr32<char>);
extern void fn_801e8d9c(Ptr32<void>);
int tsonnet_c26_register_blob_801bc7ec(Ptr32<void> self) {
 Ptr32<struct Rec> r = fn_801f0e4c(self, lbl_803ab88c);
 r->blob = lbl_8045e748;
 fn_801ebf38(self, lbl_803ab8b0);
 fn_801e8d9c(self);
 return 0;
}

}
