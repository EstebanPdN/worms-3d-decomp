#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "genfastc_800fddd8.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Quantized-conversion templates built with -mfast-cast (second batch). */
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef struct W3dColor { unsigned char r, g, b, a; } __attribute__((aligned(4))) W3dColor;
extern const float lbl_803b074c[];
extern const float lbl_803b0734[];
extern const float lbl_803b0738[];
extern const float lbl_803b073c[];
Ptr32<void> fn_80322898(Ptr32<void>, int, unsigned short);
int fn_80322838(Ptr32<void>, int, unsigned char);
Ptr32<W3dColor> fn_80178f54(Ptr32<void>);
int fn_80173df0(Ptr32<void>, Ptr32<W3dColor>);
extern const float lbl_803b0740[];
extern const float lbl_803b0744[];
extern const float lbl_803b0748[];

int w3d_init_fade_800fddd8(Ptr32<void> self, unsigned char from, unsigned char to, int unused, int duration)
{
    Ptr32<char> fade = (Ptr32<char>)self + 68;
    FIELD(self, int, 68) = 0;
    FIELD(fade, int, 4) = -1;
    FIELD(self, int, 92) |= 0x40000000;
    FIELD(fade, float, 16) = (float)from;
    FIELD(fade, float, 20) = (float)to;
    FIELD(fade, int, 12) = -1;
    FIELD(fade, int, 8) = 0;
    if (duration > 0)
        FIELD(fade, int, 8) = duration;
    return 0;
}

void w3d_set_voice_pan_801e58b0(Ptr32<void> self, float value)
{
    fn_80322838(FIELD(self, void *, 16), 10,
                (unsigned char)((value + lbl_803b0734[0]) * lbl_803b0738[0] * lbl_803b073c[0]));
}

void w3d_set_voice_pan_801e5908(Ptr32<void> self, float value)
{
    fn_80322838(FIELD(self, void *, 16), 131,
                (unsigned char)((value + lbl_803b0740[0]) * lbl_803b0744[0] * lbl_803b0748[0]));
}

void w3d_set_voice_pitch_801e5960(Ptr32<void> self, float value)
{
    fn_80322898(FIELD(self, void *, 16), 132, (unsigned short)((short)(value * lbl_803b074c[0]) + 8192));
}

void w3d_update_tint_8026b2c4(Ptr32<void> self)
{
    if (FIELD(self, int, 448) && FIELD(self, void *, 284)) {
        W3dColor color = *fn_80178f54(FIELD(self, void *, 300));
        color.a = (unsigned char)FIELD(self, float, 308);
        fn_80173df0(FIELD(self, void *, 284), &color);
    }
}

void w3d_update_tint_802a0d44(Ptr32<void> self)
{
    if (FIELD(self, int, 272) && FIELD(self, void *, 220)) {
        W3dColor color = *fn_80178f54(FIELD(self, void *, 332));
        color.a = (unsigned char)FIELD(self, float, 284);
        fn_80173df0(FIELD(self, void *, 220), &color);
    }
}

}
