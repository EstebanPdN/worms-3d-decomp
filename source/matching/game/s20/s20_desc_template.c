typedef struct S20PropertyInfo {
    const char *name;
    unsigned short size;
    unsigned char elementType;
    unsigned char type;
    void *descriptor;
    void *extra;
    int unknown;
} S20PropertyInfo;
extern S20PropertyInfo lbl_8045d3cc;
extern int lbl_804b0460;
extern char lbl_803ac6a8[];
extern char lbl_803ac6d0[];
extern char lbl_8045e004[];
extern char lbl_803fe464[];
void *memset();
void fn_801ebf38(void *, char *);
int fn_801eff8c(void *, S20PropertyInfo *);
int fn_801e8d9c(void *);

int w3d_s20desc_801c1fcc(void *self)
{
    fn_801ebf38(self, lbl_803ac6a8);
    if (!lbl_804b0460) {
        S20PropertyInfo *target = &lbl_8045d3cc;
        S20PropertyInfo info;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ac6d0;
        info.size = 20;
        info.elementType = 1;
        info.type = 9;
        info.descriptor = lbl_8045e004;
        info.extra = lbl_803fe464;
        *target = info;
        lbl_804b0460 = 1;
    }
    fn_801eff8c(self, &lbl_8045d3cc);
    fn_801e8d9c(self);
    return 0;
}
