#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "genfastc_802c1124.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Quantized-conversion templates built with -mfast-cast (eighth batch). */
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef struct W3dColor { unsigned char r, g, b, a; } __attribute__((aligned(4))) W3dColor;
extern const float lbl_803d84c8[];
extern const float lbl_803d84cc[];
extern const float lbl_803d84d0[];
int fn_80173df0(Ptr32<void>, Ptr32<W3dColor>);
void fn_8015fd1c(Ptr32<void>);

int w3d_update_overlay_fade_802c1124(Ptr32<void> self)
{
    if (FIELD(self, void *, 36)) {
        unsigned char alpha;
        W3dColor color;
        if (FIELD(self, int, 76) == 0)
            alpha = 170 - (unsigned char)(FIELD(self, float, 40) * lbl_803d84c8[0]);
        else
            alpha = (unsigned char)(-FIELD(self, float, 40) * lbl_803d84c8[0]) + 5;
        color.r = 0;
        color.g = 0;
        color.b = 0;
        color.a = alpha;
        fn_80173df0(FIELD(self, void *, 36), &color);
    }
    if (FIELD(self, int, 28) && FIELD(self, float, 40) != lbl_803d84cc[0]) {
        if (FIELD(self, int, 76) == 0)
            FIELD(self, float, 40) = FIELD(self, float, 40) - lbl_803d84d0[0];
        else
            FIELD(self, float, 40) = FIELD(self, float, 40) + lbl_803d84d0[0];
        if (FIELD(self, float, 40) == lbl_803d84cc[0] && FIELD(self, int, 76) == 1)
            fn_8015fd1c(self);
    }
    return 0;
}

}
