/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Pair templates (later batch): binding with a 64-byte default and reference
 * array copy construction. */
#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef void (*W3dMethod)(void *);
#define VCALL(p, o) ((*(W3dMethod *)(*(char **)(p) + (o)))(p))
typedef struct W3dBlock64 { int words[64 / 4]; } W3dBlock64;
extern char lbl_803abc34[];
extern W3dBlock64 lbl_8045e708;
void *fn_801f0d2c(void *, const char *);
void fn_801e8d9c(void *);
void fn_801f282c(void *, unsigned int);
extern char lbl_803aecb0[];
void fn_80210b90(void *, unsigned int);

int w3d_register_block_binding_801bde7c(void *self)
{
    void *binding = fn_801f0d2c(self, lbl_803abc34);
    FIELD(binding, W3dBlock64, 8) = lbl_8045e708;
    fn_801e8d9c(self);
    return 0;
}

int w3d_register_block_binding_801ce4f0(void *self)
{
    void *binding = fn_801f0d2c(self, lbl_803aecb0);
    FIELD(binding, W3dBlock64, 8) = lbl_8045e708;
    fn_801e8d9c(self);
    return 0;
}

void *w3d_copy_refs_801f2698(void *self, void *other)
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
        void **source = FIELD(other, void **, 8);
        void **target = FIELD(self, void **, 8);
        if (source[i])
            VCALL(source[i], 12);
        if (target[i])
            VCALL(target[i], 16);
        target[i] = source[i];
    }
    return self;
}

void *w3d_copy_refs_802109fc(void *self, void *other)
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
        void **source = FIELD(other, void **, 8);
        void **target = FIELD(self, void **, 8);
        if (source[i])
            VCALL(source[i], 12);
        if (target[i])
            VCALL(target[i], 16);
        target[i] = source[i];
    }
    return self;
}
