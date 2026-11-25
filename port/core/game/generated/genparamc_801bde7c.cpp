#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "genparamc_801bde7c.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Pair templates (later batch): binding with a 64-byte default and reference
 * array copy construction. */
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef Ptr32<void (Ptr32<void>)> W3dMethod;
#define VCALL(p, o) ((*(W3dMethod *)w3d::AG(*(Ptr32<char> *)w3d::AG(p) + (o)))(p))
typedef struct W3dBlock64 { int words[64 / 4]; } W3dBlock64;
extern char lbl_803abc34[];
extern W3dBlock64 lbl_8045e708;
Ptr32<void> fn_801f0d2c(Ptr32<void>, Ptr32<const char>);
void fn_801e8d9c(Ptr32<void>);
void fn_801f282c(Ptr32<void>, unsigned int);
extern char lbl_803aecb0[];
void fn_80210b90(Ptr32<void>, unsigned int);

int w3d_register_block_binding_801bde7c(Ptr32<void> self)
{
    Ptr32<void> binding = fn_801f0d2c(self, lbl_803abc34);
    FIELD(binding, W3dBlock64, 8) = lbl_8045e708;
    fn_801e8d9c(self);
    return 0;
}

int w3d_register_block_binding_801ce4f0(Ptr32<void> self)
{
    Ptr32<void> binding = fn_801f0d2c(self, lbl_803aecb0);
    FIELD(binding, W3dBlock64, 8) = lbl_8045e708;
    fn_801e8d9c(self);
    return 0;
}

Ptr32<void> w3d_copy_refs_801f2698(Ptr32<void> self, Ptr32<void> other)
{
    unsigned int i;
    {
        int zero = 0;
        FIELD(self, int, 8) = zero;
        FIELD(self, unsigned int, 0) = zero;
        FIELD(self, unsigned short, 4) = zero;
        FIELD(self, unsigned short, 6) = 4;
    }
    fn_801f282c(self, FIELD(other, unsigned int, 0));
    for (i = 0; i < FIELD(other, unsigned int, 0); i++) {
        Ptr32<Ptr32<void>> source = FIELD(other, void **, 8);
        Ptr32<Ptr32<void>> target = FIELD(self, void **, 8);
        if (source[i])
            VCALL(source[i], 12);
        if (target[i])
            VCALL(target[i], 16);
        target[i] = source[i];
    }
    return self;
}

Ptr32<void> w3d_copy_refs_802109fc(Ptr32<void> self, Ptr32<void> other)
{
    unsigned int i;
    {
        int zero = 0;
        FIELD(self, int, 8) = zero;
        FIELD(self, unsigned int, 0) = zero;
        FIELD(self, unsigned short, 4) = zero;
        FIELD(self, unsigned short, 6) = 4;
    }
    fn_80210b90(self, FIELD(other, unsigned int, 0));
    for (i = 0; i < FIELD(other, unsigned int, 0); i++) {
        Ptr32<Ptr32<void>> source = FIELD(other, void **, 8);
        Ptr32<Ptr32<void>> target = FIELD(self, void **, 8);
        if (source[i])
            VCALL(source[i], 12);
        if (target[i])
            VCALL(target[i], 16);
        target[i] = source[i];
    }
    return self;
}

}
