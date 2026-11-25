/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Family templates, 2026-10-22 (third session). Hand-matched against the
 * original; tools/gen_param_units.py instantiates every member. */
#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))

typedef struct W3dSmallObject { int word0; int word1; } W3dSmallObject;
typedef struct W3dBlock48 { int words[48 / 4]; } W3dBlock48;
extern char lbl_803621a8[];
extern char lbl_803e8cbc[];
extern char lbl_8036573c[];
extern char lbl_803fe96c[];
extern void *lbl_804b0310;
void fn_8019c1dc(void);
void fn_801e74d0(void);
void fn_801e7174(void *, void *, void *, void *, int, void *);
void fn_801fc86c(void *);
extern char lbl_8035fb50[];
extern char lbl_803e774c[];
extern char lbl_80361860[];
void fn_80024c34(void);
void fn_8016115c(void *, void *, void *, void *, int, int);
void fn_8015f518(void *, const char *);
extern W3dSmallObject lbl_804aca8c;
extern W3dSmallObject lbl_804aca94;
extern char lbl_8036c7f8[];
extern char lbl_8036c80c[];
extern char lbl_80411fc0[];
extern char lbl_80411f90[];
extern char lbl_804552b0[];
extern char lbl_803e8904[];
extern char lbl_80419598[];
extern char lbl_80411ad8[];
void fn_801655fc(void);
void * fn_8020fbd0(void *, void *, void *, void *, int, int);
extern char lbl_8045ce60[];
extern char lbl_803e8eec[];
void fn_801b2ab8(void);
extern char lbl_8045e7b8[];
extern char lbl_803ea0f8[];
void fn_801f7b58(void);
extern char lbl_8045edf4[];
extern char lbl_803ea1d8[];
void fn_802058ac(void);

void w3d_sinit_registry_80166470(int initialize, int priority)
{
    if (priority == 0xffff && initialize) {
        char *registry = lbl_804552b0;
        fn_8020fbd0(registry, lbl_803e8904, registry, (void *)fn_801655fc, 7, 0);
        FIELD(registry, void *, 12) = lbl_80419598;
        FIELD(lbl_804552b0, void *, 0) = lbl_80411ad8;
    }
}

void w3d_sinit_registry_801b41e8(int initialize, int priority)
{
    if (priority == 0xffff && initialize) {
        char *registry = lbl_8045ce60;
        fn_8020fbd0(registry, lbl_803e8eec, registry, (void *)fn_801b2ab8, 7, 0);
        FIELD(registry, void *, 12) = lbl_80419598;
        FIELD(lbl_8045ce60, void *, 0) = lbl_80411ad8;
    }
}

void w3d_copy_block_801c8424(void *object, const void *source)
{
    FIELD(object, W3dBlock48, 20) = *(const W3dBlock48 *)source;
}

unsigned short w3d_next_serial_801dfaac(void *object)
{
    return FIELD(object, unsigned short, 40)++;
}

void w3d_sinit_registry_801f80b4(int initialize, int priority)
{
    if (priority == 0xffff && initialize) {
        char *registry = lbl_8045e7b8;
        fn_8020fbd0(registry, lbl_803ea0f8, registry, (void *)fn_801f7b58, 7, 0);
        FIELD(registry, void *, 12) = lbl_80419598;
        FIELD(lbl_8045e7b8, void *, 0) = lbl_80411ad8;
    }
}

unsigned short w3d_next_serial_801f98b0(void *object)
{
    return FIELD(object, unsigned short, 12)++;
}

unsigned short w3d_next_serial_801f9978(void *object)
{
    return FIELD(object, unsigned short, 8)++;
}

unsigned short w3d_next_serial_801fc208(void *object)
{
    return FIELD(object, unsigned short, 12)++;
}

unsigned short w3d_next_serial_801fc2d0(void *object)
{
    return FIELD(object, unsigned short, 8)++;
}

void w3d_sinit_registry_80206850(int initialize, int priority)
{
    if (priority == 0xffff && initialize) {
        char *registry = lbl_8045edf4;
        fn_8020fbd0(registry, lbl_803ea1d8, registry, (void *)fn_802058ac, 7, 0);
        FIELD(registry, void *, 12) = lbl_80419598;
        FIELD(lbl_8045edf4, void *, 0) = lbl_80411ad8;
    }
}

unsigned short w3d_next_serial_80219b08(void *object)
{
    return FIELD(object, unsigned short, 20)++;
}

unsigned short w3d_next_serial_80219bc4(void *object)
{
    return FIELD(object, unsigned short, 20)++;
}

unsigned short w3d_next_serial_80219c80(void *object)
{
    return FIELD(object, unsigned short, 20)++;
}

unsigned short w3d_next_serial_80219d3c(void *object)
{
    return FIELD(object, unsigned short, 20)++;
}

unsigned short w3d_next_serial_80219df8(void *object)
{
    return FIELD(object, unsigned short, 20)++;
}

void w3d_copy_block_80250d60(void *object, const void *source)
{
    FIELD(object, W3dBlock48, 240) = *(const W3dBlock48 *)source;
}

void w3d_copy_block_80250db4(void *object, const void *source)
{
    FIELD(object, W3dBlock48, 192) = *(const W3dBlock48 *)source;
}

void w3d_copy_block_80250e58(void *object, const void *source)
{
    FIELD(object, W3dBlock48, 144) = *(const W3dBlock48 *)source;
}

void w3d_copy_block_80250eac(void *object, const void *source)
{
    FIELD(object, W3dBlock48, 96) = *(const W3dBlock48 *)source;
}

void w3d_copy_block_80250f00(void *object, const void *source)
{
    FIELD(object, W3dBlock48, 48) = *(const W3dBlock48 *)source;
}
