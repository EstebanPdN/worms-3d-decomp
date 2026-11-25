/* Registration with a descriptor block and a struct default copied from a global. */
typedef struct S20PropertyInfo {
    const char *name;
    unsigned short size;
    unsigned char elementType;
    unsigned char type;
    void *descriptor;
    void *extra;
    int reserved16;
} S20PropertyInfo;
void *memset();

extern int lbl_804b0414;
extern S20PropertyInfo lbl_8045d250;
extern char lbl_803ac3a8[];
extern char lbl_8045e004[];
extern char lbl_803fe588[];
void * fn_801eff8c(void *, S20PropertyInfo *);
extern char lbl_803ac3bc[];
char *fn_801f0d2c(void *, char *);
typedef struct S20Block64 { int words[16]; } S20Block64;
extern S20Block64 lbl_8045e708;
void fn_801e8d9c(void *);
int w3d_s20_register_properties_801c04f8(void *object)
{
    S20PropertyInfo info;
    if (!lbl_804b0414) {
        S20PropertyInfo *target = &lbl_8045d250;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ac3a8;
        info.size = 84;
        info.type = 9;
        info.descriptor = lbl_8045e004;
        info.extra = lbl_803fe588;
        *target = info;
        lbl_804b0414 = 1;
    }
    fn_801eff8c(object, &lbl_8045d250);
    {
        char *property = fn_801f0d2c(object, lbl_803ac3bc);
        *(S20Block64 *)(property + 8) = lbl_8045e708;
    }
    fn_801e8d9c(object);
    return 0;
}
