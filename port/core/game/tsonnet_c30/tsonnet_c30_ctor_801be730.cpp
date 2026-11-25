#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "tsonnet_c30_ctor_801be730.c"
/* Reference-only: constructor of a held-base object. The two 64-byte members
   are copies of the same external 64-byte record and the count field is zero;
   layout and meaning are inferred from offsets. */
typedef struct { int w[16]; } Block64;
extern Ptr32<void> fn_801b4e94(Ptr32<void> self, Ptr32<void>);
extern char lbl_80415050[];
extern Block64 lbl_8045e708[];
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))

Ptr32<void> tsonnet_c30_ctor_801be730(Ptr32<void> self, Ptr32<void> arg_r4) {
    fn_801b4e94(self, arg_r4);
    FIELD(self, void *, 0) = lbl_80415050;
    FIELD(self, Block64, 48) = lbl_8045e708[0];
    FIELD(self, Block64, 112) = lbl_8045e708[0];
    FIELD(self, int, 176) = 0;
    return self;
}

}
