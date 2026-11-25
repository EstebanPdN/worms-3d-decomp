/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Family templates, 2026-10-22 (third session), eighth batch. */
#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef struct W3dBlock12 { int words[12 / 4]; } W3dBlock12;
int fn_8020db88(void *, int, int);
extern char lbl_804131d8[];
extern char *lbl_804b06a0[];
void * fn_801ea0ec(void *, int);
void fn_8020c5c0(void *);
unsigned short *fn_80341884(void *);
extern char lbl_803aad38[];
extern char lbl_803aad68[];
extern char lbl_803aad98[];
extern char lbl_803aadc4[];
void * fn_801ebf38(void *, const char *);
void * fn_801ecc6c(void *, const char *);
void fn_801e8d9c(void *);
extern char lbl_803ab73c[];
extern char lbl_803ab770[];
extern char lbl_803ab7a4[];
extern char lbl_803ab7d8[];

void w3d_get_block12_8009f4bc(void *self, void *unused, void *out)
{
    *(W3dBlock12 *)out = FIELD(self, W3dBlock12, 320);
}

void w3d_get_block12_800ed34c(void *self, void *unused, void *out)
{
    *(W3dBlock12 *)out = FIELD(self, W3dBlock12, 36);
}

void w3d_get_block12_800ed36c(void *self, void *unused, void *out)
{
    *(W3dBlock12 *)out = FIELD(self, W3dBlock12, 48);
}

int w3d_get_indexed_80186864(void *self, int index)
{
    int *table = FIELD(self, int *, 104);
    return *(int *)((char *)table + (index << 2));
}

void *w3d_construct_named_8018e26c(void *self, void * arg_r4)
{
    char *name = (char *)self + 24;
    char **empty = lbl_804b06a0;
    fn_801ea0ec(self, arg_r4);
    FIELD(self, int, 20) = 0;
    FIELD(self, void *, 0) = lbl_804131d8;
    fn_8020c5c0(name);
    FIELD(self, char *, 24) = *empty;
    ++*fn_80341884(name);
    return self;
}

int w3d_set_block12_801a0974(void *self, const void *source)
{
    FIELD(self, W3dBlock12, 176) = *(const W3dBlock12 *)source;
    FIELD(self, int, 212) = 1;
    return 0;
}

int w3d_set_block12_801a09a4(void *self, const void *source)
{
    FIELD(self, W3dBlock12, 188) = *(const W3dBlock12 *)source;
    FIELD(self, int, 212) = 1;
    return 0;
}

int w3d_set_block12_801a09d4(void *self, const void *source)
{
    FIELD(self, W3dBlock12, 200) = *(const W3dBlock12 *)source;
    FIELD(self, int, 212) = 1;
    return 0;
}

int w3d_set_slot_801ab5f0(void *self, int index, int value)
{
    struct W3dSlots { char pad[124]; int slots[1]; };
    ((struct W3dSlots *)self)->slots[index] = value;
    return 0;
}

int w3d_get_slot_801ab604(void *self, int index)
{
    struct W3dSlots { char pad[124]; int slots[1]; };
    return ((struct W3dSlots *)self)->slots[index];
}

int w3d_set_slot_801ab740(void *self, int index, int value)
{
    struct W3dSlots { char pad[228]; int slots[1]; };
    ((struct W3dSlots *)self)->slots[index] = value;
    return 0;
}

int w3d_get_slot_801ab754(void *self, int index)
{
    struct W3dSlots { char pad[228]; int slots[1]; };
    return ((struct W3dSlots *)self)->slots[index];
}

int w3d_set_slot_801ab8b4(void *self, int index, int value)
{
    struct W3dSlots { char pad[248]; int slots[1]; };
    ((struct W3dSlots *)self)->slots[index] = value;
    return 0;
}

int w3d_get_slot_801ab8c8(void *self, int index)
{
    struct W3dSlots { char pad[248]; int slots[1]; };
    return ((struct W3dSlots *)self)->slots[index];
}

int w3d_set_slot_801ab8d8(void *self, int index, int value)
{
    struct W3dSlots { char pad[264]; int slots[1]; };
    ((struct W3dSlots *)self)->slots[index] = value;
    return 0;
}

int w3d_get_slot_801ab8ec(void *self, int index)
{
    struct W3dSlots { char pad[264]; int slots[1]; };
    return ((struct W3dSlots *)self)->slots[index];
}

int w3d_set_slot_801ab8fc(void *self, int index, int value)
{
    struct W3dSlots { char pad[280]; int slots[1]; };
    ((struct W3dSlots *)self)->slots[index] = value;
    return 0;
}

int w3d_get_slot_801ab910(void *self, int index)
{
    struct W3dSlots { char pad[280]; int slots[1]; };
    return ((struct W3dSlots *)self)->slots[index];
}

int w3d_register_bindings_801b54e0(void *self)
{
    fn_801ebf38(self, lbl_803aad38);
    fn_801ecc6c(self, lbl_803aad68);
    fn_801ecc6c(self, lbl_803aad98);
    fn_801ebf38(self, lbl_803aadc4);
    fn_801e8d9c(self);
    return 0;
}

int w3d_register_bindings_801bc26c(void *self)
{
    fn_801ecc6c(self, lbl_803ab73c);
    fn_801ecc6c(self, lbl_803ab770);
    fn_801ecc6c(self, lbl_803ab7a4);
    fn_801ecc6c(self, lbl_803ab7d8);
    fn_801e8d9c(self);
    return 0;
}
