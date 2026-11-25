typedef struct S10PropertyInfo {
 const char *name;
 unsigned short size;
 unsigned char elementType;
 unsigned char type;
 void *descriptor;
 int unknown12;
 int unknown16;
} S10PropertyInfo;
extern S10PropertyInfo lbl_8045cfe4;
extern int lbl_804b0398;
extern char lbl_803ab330[];
extern char lbl_8045ed34[];
void *memset();
int fn_801efd98(void *, S10PropertyInfo *);
int fn_801e8d9c(void *);

int w3d_s10_register_array_801b819c(void *self)
{
 if (!lbl_804b0398) {
 S10PropertyInfo *target = &lbl_8045cfe4;
 S10PropertyInfo info;
 memset(&info, 0, sizeof info);
 info.name = lbl_803ab330;
 info.size = 96;
 info.elementType = 10;
 info.type = 9;
 info.descriptor = lbl_8045ed34;
 *target = info;
 lbl_804b0398 = 1;
 }
 fn_801efd98(self, &lbl_8045cfe4);
 fn_801e8d9c(self);
 return 0;
}
