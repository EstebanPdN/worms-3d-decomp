/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Family templates, 2026-10-22 (third session), eighth batch. */
#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef struct W3dBlock12 { int words[12 / 4]; } W3dBlock12;
int fn_8020db88(void *, int, int);
extern char lbl_80414d58[];
extern char *lbl_804b06a0[];
void * fn_801ea0ec(void *, int);
void fn_8020c5c0(void *);
unsigned short *fn_80341884(void *);
extern char lbl_803aad38[];
extern char lbl_803aad68[];
extern char lbl_803aad98[];
extern char lbl_803aadc4[];
void fn_801ebf38(void *, const char *);
void fn_801ecc6c(void *, const char *);
void fn_801e8d9c(void *);
extern char lbl_804131d8[];
extern char lbl_803b9544[];
extern char lbl_803b9574[];
extern char lbl_803b95a4[];
extern char lbl_803b95d4[];
void * fn_801ec0f8(void *, const char *);
void * fn_801ec0f8(void *, const char *);

void *w3d_construct_named_801c2168(void *self, void * arg_r4)
{
    char *name = (char *)self + 24;
    char **empty = lbl_804b06a0;
    fn_801ea0ec(self, arg_r4);
    FIELD(self, int, 20) = 0;
    FIELD(self, void *, 0) = lbl_80414d58;
    fn_8020c5c0(name);
    FIELD(self, char *, 24) = *empty;
    ++*fn_80341884(name);
    return self;
}

int w3d_get_indexed_801fbe9c(void *self, int index)
{
    int *table = FIELD(self, int *, 52);
    return *(int *)((char *)table + (index << 2));
}

int w3d_get_indexed_8020a7f8(void *self, int index)
{
    int *table = FIELD(self, int *, 20);
    return *(int *)((char *)table + (index << 2));
}

int w3d_register_bindings_8022a058(void *self)
{
    fn_801ec0f8(self, lbl_803b9544);
    fn_801ec0f8(self, lbl_803b9574);
    fn_801ec0f8(self, lbl_803b95a4);
    fn_801ec0f8(self, lbl_803b95d4);
    fn_801e8d9c(self);
    return 0;
}
