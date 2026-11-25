/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Quantized-conversion templates built with -mfast-cast (fourth batch):
 * graphics state helpers. */
#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef struct W3dColor { unsigned char r, g, b, a; } __attribute__((aligned(4))) W3dColor;
extern int lbl_803a552c[];
void fn_8030b3dc(int, unsigned char, int, int, unsigned char);
void fn_8030ba98(int);
void fn_802b16c4(void *, int);
W3dColor *fn_80178f54(void *);
void fn_802a0d44(void *);

int w3d_apply_alpha_test_8016a3ac(void *self, void *state)
{
    if (FIELD(state, int, 32) == 0) {
        fn_8030b3dc(7, 0, 0, 7, 0);
        fn_8030ba98(1);
    } else {
        unsigned char reference = (unsigned char)FIELD(state, float, 24);
        int compare = lbl_803a552c[FIELD(state, int, 28)];
        fn_8030b3dc(compare, reference, 0, compare, reference);
        fn_8030ba98(0);
    }
    return 0;
}

void w3d_set_blend_mode_802a0cc0(void *self, int mode)
{
    if (mode != FIELD(self, int, 188)) {
        fn_802b16c4((char *)self + 28, mode);
        if (FIELD(self, int, 188) != 1) {
            W3dColor color = *fn_80178f54(FIELD(self, void *, 332));
            FIELD(self, float, 280) = (float)color.a;
            if (FIELD(self, int, 272) == 0)
                FIELD(self, float, 284) = FIELD(self, float, 280);
        }
        if (FIELD(self, int, 272) == 1)
            fn_802a0d44(self);
    }
}
