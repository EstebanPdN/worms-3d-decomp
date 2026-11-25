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
extern void * fn_801ecc6c(void *, const char *);
extern void fn_8020c5c0(void *);
extern unsigned short *fn_80341884(void *);
extern void fn_8020bb2c(void *);
extern void fn_8020c5c4(void *);
extern void fn_80341588(void *);
extern char *lbl_804b06a0[];
extern char lbl_803a9498[], lbl_803a94cc[], lbl_803a94f0[], lbl_803fe92c[], lbl_8045e004[];
extern S12PropertyInfo lbl_8045ccf8;
extern int lbl_804b02f4;
extern void * fn_801eff8c(void *, S12PropertyInfo *);
extern void fn_801e8d9c(void *);
void *memset();
int w3d_s12_init_string_property_8019aeb8(void *object)
{
    S12StringBinding *binding = fn_801ed24c(object, lbl_803a9498);
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
    fn_801ecc6c(object, lbl_803a94cc);
    if (!lbl_804b02f4) {
        S12PropertyInfo *target = &lbl_8045ccf8;
        memset(&frame.property, 0, sizeof frame.property);
        frame.property.name = lbl_803a94f0;
        frame.property.size = 20;
        frame.property.elementType = 2;
        frame.property.type = 9;
        frame.property.descriptor = lbl_8045e004;
        frame.property.extra = lbl_803fe92c;
        *target = frame.property;
        lbl_804b02f4 = 1;
    }
    fn_801eff8c(object, &lbl_8045ccf8);
    fn_801e8d9c(object);
    return 0;
}
