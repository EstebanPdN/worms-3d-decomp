typedef struct S10PropertyInfo {
 const char *name;
 unsigned short size;
 unsigned char elementType;
 unsigned char type;
 void *descriptor;
 int unknown12;
 int unknown16;
} S10PropertyInfo;
extern S10PropertyInfo lbl_8045d69c, lbl_8045d6b0;
extern int lbl_804b04f0, lbl_804b04f4;
extern char lbl_803adc88[], lbl_803adc94[];
extern char lbl_8045e29c[], lbl_8045e47c[];
void *memset();
int fn_801f2420(void *, S10PropertyInfo *);
int fn_801f25b0(void *, S10PropertyInfo *);
int fn_801e8d9c(void *);
int w3d_s10_register_two_arrays_801ca35c(void *self)
{
    S10PropertyInfo info;
    if (!lbl_804b04f0) {
        S10PropertyInfo *target = &lbl_8045d69c;
        memset(&info, 0, sizeof info);
        info.name = lbl_803adc88;
        info.size = 40;
        info.elementType = 4;
        info.type = 9;
        info.descriptor = lbl_8045e29c;
        *target = info;
        lbl_804b04f0 = 1;
    }
    fn_801f2420(self, &lbl_8045d69c);
    if (!lbl_804b04f4) {
        S10PropertyInfo *target = &lbl_8045d6b0;
        memset(&info, 0, sizeof info);
        info.name = lbl_803adc94;
        info.size = 36;
        info.elementType = 5;
        info.type = 9;
        info.descriptor = lbl_8045e47c;
        *target = info;
        lbl_804b04f4 = 1;
    }
    fn_801f25b0(self, &lbl_8045d6b0);
    fn_801e8d9c(self);
    return 0;
}
