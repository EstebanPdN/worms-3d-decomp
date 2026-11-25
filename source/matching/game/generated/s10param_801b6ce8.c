/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

typedef struct S10PropertyInfo {
 const char *name;
 unsigned short size;
 unsigned char elementType;
 unsigned char type;
 void *descriptor;
 int unknown12;
 int unknown16;
} S10PropertyInfo;
extern S10PropertyInfo lbl_8045cf94;
extern int lbl_804b0388;
extern char lbl_803ab2e8[];
extern char lbl_8045ed7c[];
void *memset();
int fn_801efec4(void *, S10PropertyInfo *);
int fn_801e8d9c(void *);
extern S10PropertyInfo lbl_8045cfa8;
extern int lbl_804b038c;
extern char lbl_803ab330[];
extern char lbl_8045ed34[];
int fn_801efd98(void *, S10PropertyInfo *);
extern S10PropertyInfo lbl_8045cfbc;
extern int lbl_804b0390;
extern S10PropertyInfo lbl_8045cfd0;
extern int lbl_804b0394;
extern char lbl_803ab360[];

int w3d_s10_register_array_801b6ce8(void *self)
{
 if (!lbl_804b0388) {
 S10PropertyInfo *target = &lbl_8045cf94;
 S10PropertyInfo info;
 memset(&info, 0, sizeof info);
 info.name = lbl_803ab2e8;
 info.size = 92;
 info.elementType = 9;
 info.type = 9;
 info.descriptor = lbl_8045ed7c;
 *target = info;
 lbl_804b0388 = 1;
 }
 fn_801efec4(self, &lbl_8045cf94);
 fn_801e8d9c(self);
 return 0;
}

int w3d_s10_register_array_801b736c(void *self)
{
 if (!lbl_804b038c) {
 S10PropertyInfo *target = &lbl_8045cfa8;
 S10PropertyInfo info;
 memset(&info, 0, sizeof info);
 info.name = lbl_803ab330;
 info.size = 92;
 info.elementType = 9;
 info.type = 9;
 info.descriptor = lbl_8045ed34;
 *target = info;
 lbl_804b038c = 1;
 }
 fn_801efd98(self, &lbl_8045cfa8);
 fn_801e8d9c(self);
 return 0;
}

int w3d_s10_register_array_801b75b8(void *self)
{
 if (!lbl_804b0390) {
 S10PropertyInfo *target = &lbl_8045cfbc;
 S10PropertyInfo info;
 memset(&info, 0, sizeof info);
 info.name = lbl_803ab330;
 info.size = 92;
 info.elementType = 9;
 info.type = 9;
 info.descriptor = lbl_8045ed34;
 *target = info;
 lbl_804b0390 = 1;
 }
 fn_801efd98(self, &lbl_8045cfbc);
 fn_801e8d9c(self);
 return 0;
}

int w3d_s10_register_array_801b7804(void *self)
{
 if (!lbl_804b0394) {
 S10PropertyInfo *target = &lbl_8045cfd0;
 S10PropertyInfo info;
 memset(&info, 0, sizeof info);
 info.name = lbl_803ab360;
 info.size = 92;
 info.elementType = 9;
 info.type = 9;
 info.descriptor = lbl_8045ed34;
 *target = info;
 lbl_804b0394 = 1;
 }
 fn_801efd98(self, &lbl_8045cfd0);
 fn_801e8d9c(self);
 return 0;
}
