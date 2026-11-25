/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Quantized-conversion templates built with -mfast-cast (fifth batch). */
#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef float (*W3dGetScale)(void *, void *);
typedef struct W3dColor { unsigned char r, g, b, a; } __attribute__((aligned(4))) W3dColor;
extern const float lbl_803a5058[];
extern const float lbl_803b0800[];
extern void *lbl_804ab80c;
extern void *lbl_804ab85c;
void *fn_801e25d4(void *);
void *fn_801e41d0(void *, void *, void *, unsigned char);
int fn_801e4120(void *, void *, unsigned char, int);
void fn_802b16c4(void *, int);
void fn_802b1258(void *);
W3dColor *fn_80178f54(void *);
void fn_8026b2c4(void *);

int w3d_set_color_from_message_801697b4(void *iface, void *message)
{
    char *self = iface ? (char *)iface - 4 : 0;
    float *rgba = (float *)((char *)message + 20);
    float scale = lbl_803a5058[0];
    self[208] = (unsigned char)(rgba[0] * scale);
    self[209] = (unsigned char)(rgba[1] * scale);
    self[210] = (unsigned char)(rgba[2] * scale);
    self[211] = (unsigned char)(rgba[3] * scale);
    FIELD(self, int, 288) |= 64;
    FIELD(self, int, 284) += 1;
    return 0;
}

void w3d_open_stream_801e6b1c(void *self)
{
    if (FIELD(self, void *, 44)) {
        void *manager = lbl_804ab80c;
        float volume = (*(W3dGetScale *)(*(char **)manager + 132))(manager, fn_801e25d4(FIELD(self, void *, 44)));
        void *streams = lbl_804ab85c;
        unsigned char level = (unsigned char)(volume * lbl_803b0800[0]);
        if (FIELD(self, unsigned int, 16) > 1)
            FIELD(self, void *, 56) = fn_801e41d0(streams, (char *)self + 68, (char *)self + 116, level);
        else
            FIELD(self, void *, 56) = fn_801e4120(streams, (char *)self + 68, level, 64);
    }
}

void w3d_set_render_mode_8026b334(void *self, int mode)
{
    if (mode != FIELD(self, int, 188)) {
        fn_802b16c4((char *)self + 28, mode);
        if (FIELD(self, int, 188) == 1) {
            char *node = FIELD(self, char *, 40);
            char *text = FIELD(node, char *, 148);
            if (FIELD(text, unsigned short, -4) != 0 && ((FIELD(node, unsigned char, 11) ^ 4) & 4)
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
