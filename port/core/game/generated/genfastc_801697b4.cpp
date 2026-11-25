#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "genfastc_801697b4.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Quantized-conversion templates built with -mfast-cast (fifth batch). */
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef Ptr32<float (Ptr32<void>, Ptr32<void>)> W3dGetScale;
typedef struct W3dColor { unsigned char r, g, b, a; } __attribute__((aligned(4))) W3dColor;
extern const float lbl_803a5058[];
extern const float lbl_803b0800[];
extern Ptr32<void> lbl_804ab80c;
extern Ptr32<void> lbl_804ab85c;
Ptr32<void> fn_801e25d4(Ptr32<void>);
Ptr32<void> fn_801e41d0(Ptr32<void>, Ptr32<void>, Ptr32<void>, unsigned char);
int fn_801e4120(Ptr32<void>, Ptr32<void>, unsigned char, int);
void fn_802b16c4(Ptr32<void>, int);
void fn_802b1258(Ptr32<void>);
Ptr32<W3dColor> fn_80178f54(Ptr32<void>);
void fn_8026b2c4(Ptr32<void>);

int w3d_set_color_from_message_801697b4(Ptr32<void> iface, Ptr32<void> message)
{
    Ptr32<char> self = iface ? w3d::R((Ptr32<char>)iface - 4) : 0;
    Ptr32<float> rgba = (Ptr32<float>)((Ptr32<char>)message + 20);
    float scale = lbl_803a5058[0];
    self[208] = (unsigned char)(rgba[0] * scale);
    self[209] = (unsigned char)(rgba[1] * scale);
    self[210] = (unsigned char)(rgba[2] * scale);
    self[211] = (unsigned char)(rgba[3] * scale);
    FIELD(self, int, 288) |= 64;
    FIELD(self, int, 284) += 1;
    return 0;
}

void w3d_open_stream_801e6b1c(Ptr32<void> self)
{
    if (FIELD(self, void *, 44)) {
        Ptr32<void> manager = lbl_804ab80c;
        float volume = (*(Ptr32<W3dGetScale>)(*(Ptr32<Ptr32<char>>)manager + 132))(manager, fn_801e25d4(FIELD(self, void *, 44)));
        Ptr32<void> streams = lbl_804ab85c;
        unsigned char level = (unsigned char)(volume * lbl_803b0800[0]);
        if (FIELD(self, unsigned int, 16) > 1)
            FIELD(self, void *, 56) = fn_801e41d0(streams, (Ptr32<char>)self + 68, (Ptr32<char>)self + 116, level);
        else
            FIELD(self, void *, 56) = w3d::G(fn_801e4120(streams, (Ptr32<char>)self + 68, level, 64));
    }
}

void w3d_set_render_mode_8026b334(Ptr32<void> self, int mode)
{
    if (mode != FIELD(self, int, 188)) {
        fn_802b16c4((Ptr32<char>)self + 28, mode);
        if (FIELD(self, int, 188) == 1) {
            Ptr32<char> node = FIELD(self, char *, 40);
            Ptr32<char> text = FIELD(node, char *, 148);
            if (FIELD(text, unsigned short, -4) != 0 && ((FIELD(node, unsigned char, 8) ^ 4) & 4)
                && FIELD(self, int, 140) != 0)
                fn_802b1258(text);
        } else {
            W3dColor color = *fn_80178f54(FIELD(self, void *, 300));
            FIELD(self, float, 304) = (float)color.a;
            if (FIELD(self, int, 448) == 0)
                FIELD(self, float, 308) = FIELD(self, float, 304);
        }
        if (FIELD(self, int, 448) == 1)
            fn_8026b2c4(self);
    }
}

}
