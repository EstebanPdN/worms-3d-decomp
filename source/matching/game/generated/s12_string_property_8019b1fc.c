/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

typedef struct S12PropertyInfo {
    const char *name;
    unsigned short size;
    unsigned char elementType;
    unsigned char type;
    void *descriptor;
    void *extra;
    int reserved16;
} S12PropertyInfo;
typedef struct S12StringBinding { char reserved[8]; char *value; } S12StringBinding;
extern S12StringBinding *fn_801ed24c(void *, const char *);
extern void * fn_801ec52c(void *, const char *);
extern void fn_8020c5c0(void *);
extern unsigned short *fn_80341884(void *);
extern void fn_8020bb2c(void *);
extern void fn_8020c5c4(void *);
extern void fn_80341588(void *);
extern char *lbl_804b06a0[];
extern char lbl_803a9500[], lbl_803a9530[], lbl_803a9558[], lbl_803fe938[], lbl_8045e004[];
extern S12PropertyInfo lbl_8045cd0c;
extern int lbl_804b02f8;
extern void * fn_801eff8c(void *, S12PropertyInfo *);
extern void fn_801e8d9c(void *);
void *memset();

int w3d_s12_init_string_property_8019b1fc(void *object)
{
    S12StringBinding *binding = fn_801ed24c(object, lbl_803a9500);
    typedef struct S12String { char *data; } S12String;
    /* Observed local layout: string at sp+8, descriptor at sp+16. */
    struct { S12String string; int reserved; S12PropertyInfo property; } frame;
    S12String *temporary = (S12String *)&frame.string;
    char **empty = lbl_804b06a0;
    unsigned short remaining;
    unsigned short *oldHeader;
    fn_8020c5c0(temporary);
    temporary->data = *empty;
    ++*fn_80341884(temporary);
    ++*(unsigned short *)(temporary->data - 6);
    oldHeader = (unsigned short *)(binding->value - 6);
    remaining = --*oldHeader;
    if (remaining == 0)
        fn_8020bb2c(oldHeader);
    binding->value = temporary->data;
    fn_8020c5c4(temporary);
    fn_80341588(temporary);
    fn_801ec52c(object, lbl_803a9530);
    if (!lbl_804b02f8) {
        S12PropertyInfo *target = &lbl_8045cd0c;
        memset(&frame.property, 0, sizeof frame.property);
        frame.property.name = lbl_803a9558;
        frame.property.size = 20;
        frame.property.elementType = 2;
        frame.property.type = 9;
        frame.property.descriptor = lbl_8045e004;
        frame.property.extra = lbl_803fe938;
        *target = frame.property;
        lbl_804b02f8 = 1;
    }
    fn_801eff8c(object, &lbl_8045cd0c);
    fn_801e8d9c(object);
    return 0;
}
