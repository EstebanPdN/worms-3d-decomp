typedef struct S10PropertyInfo {
 const char *name;
 unsigned short size;
 unsigned char elementType;
 unsigned char type;
 void *descriptor;
 void *extra;
 int unknown16;
} S10PropertyInfo;
extern S10PropertyInfo lbl_8045cecc;
extern int lbl_804b0360;
extern char lbl_803aace8[];
extern char lbl_8045e004[];
extern char lbl_803fe4c4[];
void *memset();
int fn_801eff8c(void *, S10PropertyInfo *);
int fn_801e8d9c(void *);

int w3d_s10_register_array_801b4f60(void *self)
{
 if (!lbl_804b0360) {
 S10PropertyInfo *target = &lbl_8045cecc;
 S10PropertyInfo info;
 memset(&info, 0, sizeof info);
 info.name = lbl_803aace8;
 info.size = 44;
 info.elementType = 3;
 info.type = 9;
 info.descriptor = lbl_8045e004;
 info.extra = lbl_803fe4c4;
 *target = info;
 lbl_804b0360 = 1;
 }
 fn_801eff8c(self, &lbl_8045cecc);
 fn_801e8d9c(self);
 return 0;
}
