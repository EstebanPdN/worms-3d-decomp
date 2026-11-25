/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

typedef struct S10PropertyInfo {
    const char *name;
    unsigned short size;
    unsigned char elementType;
    unsigned char type;
    void *descriptor;
    void *extra;
    int reserved16;
} S10PropertyInfo;
typedef struct S10StringBinding { char reserved[8]; char *value; } S10StringBinding;
extern S10StringBinding *fn_801ed24c(void *, const char *);
extern void fn_801ecc6c(void *, const char *);
extern void fn_8020c5c0(void *);
extern unsigned short *fn_80341884(void *);
extern void fn_8020bb2c(void *);
extern void fn_8020c5c4(void *);
extern void fn_80341588(void *);
extern char *lbl_804b06a0[];
extern char lbl_803b7d00[], lbl_803a94cc[], lbl_803a94f0[], lbl_803fe92c[], lbl_8045e004[];
extern S10PropertyInfo lbl_8045ccf8;
extern int lbl_804b02f4;
extern void fn_801eff8c(void *, S10PropertyInfo *);
extern void fn_801e8d9c(void *);
void *memset();

int w3d_s10_init_string_property_8022572c(void *object)
{
    S10StringBinding *binding = fn_801ed24c(object, lbl_803b7d00);
    struct { char *data; } temporary;
    char **empty = lbl_804b06a0;
    unsigned short remaining;
    unsigned short *oldHeader;
    fn_8020c5c0(&temporary);
    temporary.data = *empty;
    ++*fn_80341884(&temporary);
    ++*(unsigned short *)(temporary.data - 6);
    oldHeader = (unsigned short *)(binding->value - 6);
    remaining = --*oldHeader;
    if (remaining == 0)
        fn_8020bb2c(oldHeader);
    binding->value = temporary.data;
    fn_8020c5c4(&temporary);
    fn_80341588(&temporary);
    fn_801e8d9c(object);
    return 0;
}
