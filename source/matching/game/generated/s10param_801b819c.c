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
extern S10PropertyInfo lbl_8045cfe4;
extern int lbl_804b0398;
extern char lbl_803ab330[];
extern char lbl_8045ed34[];
void *memset();
int fn_801efd98(void *, S10PropertyInfo *);
int fn_801e8d9c(void *);
extern S10PropertyInfo lbl_8045cff8;
extern int lbl_804b039c;
extern S10PropertyInfo lbl_8045d00c;
extern int lbl_804b03a0;
extern char lbl_803ab360[];
extern S10PropertyInfo lbl_8045d160;
extern int lbl_804b03e4;
extern char lbl_803ab6bc[];
extern char lbl_8045ed1c[];
int fn_801efd34(void *, S10PropertyInfo *);
extern S10PropertyInfo lbl_8045d174;
extern int lbl_804b03e8;
extern char lbl_803ab708[];
extern S10PropertyInfo lbl_8045d188;
extern int lbl_804b03ec;
extern S10PropertyInfo lbl_80464a7c;
extern int lbl_804b07e4;
extern char lbl_803b66c0[];
extern char lbl_8045e23c[];
int fn_801f2100(void *, S10PropertyInfo *);
extern S10PropertyInfo lbl_80464a90;
extern int lbl_804b07e8;
extern S10PropertyInfo lbl_80464c84;
extern int lbl_804b0848;
extern char lbl_803bb23c[];
extern char lbl_8045ed94[];
int fn_801efff0(void *, S10PropertyInfo *);
extern S10PropertyInfo lbl_80464c98;
extern int lbl_804b084c;
extern char lbl_803bbe08[];
extern char lbl_8045ed58[];
int fn_801efe60(void *, S10PropertyInfo *);
extern S10PropertyInfo lbl_80464cd4;
extern int lbl_804b0858;
extern char lbl_8045ed7c[];
int fn_801efec4(void *, S10PropertyInfo *);

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

int w3d_s10_register_array_801b83ec(void *self)
{
 if (!lbl_804b039c) {
 S10PropertyInfo *target = &lbl_8045cff8;
 S10PropertyInfo info;
 memset(&info, 0, sizeof info);
 info.name = lbl_803ab330;
 info.size = 96;
 info.elementType = 10;
 info.type = 9;
 info.descriptor = lbl_8045ed34;
 *target = info;
 lbl_804b039c = 1;
 }
 fn_801efd98(self, &lbl_8045cff8);
 fn_801e8d9c(self);
 return 0;
}

int w3d_s10_register_array_801b863c(void *self)
{
 if (!lbl_804b03a0) {
 S10PropertyInfo *target = &lbl_8045d00c;
 S10PropertyInfo info;
 memset(&info, 0, sizeof info);
 info.name = lbl_803ab360;
 info.size = 96;
 info.elementType = 10;
 info.type = 9;
 info.descriptor = lbl_8045ed34;
 *target = info;
 lbl_804b03a0 = 1;
 }
 fn_801efd98(self, &lbl_8045d00c);
 fn_801e8d9c(self);
 return 0;
}

int w3d_s10_register_array_801bb9a8(void *self)
{
 if (!lbl_804b03e4) {
 S10PropertyInfo *target = &lbl_8045d160;
 S10PropertyInfo info;
 memset(&info, 0, sizeof info);
 info.name = lbl_803ab6bc;
 info.size = 28;
 info.elementType = 2;
 info.type = 9;
 info.descriptor = lbl_8045ed1c;
 *target = info;
 lbl_804b03e4 = 1;
 }
 fn_801efd34(self, &lbl_8045d160);
 fn_801e8d9c(self);
 return 0;
}

int w3d_s10_register_array_801bbd84(void *self)
{
 if (!lbl_804b03e8) {
 S10PropertyInfo *target = &lbl_8045d174;
 S10PropertyInfo info;
 memset(&info, 0, sizeof info);
 info.name = lbl_803ab708;
 info.size = 24;
 info.elementType = 1;
 info.type = 9;
 info.descriptor = lbl_8045ed34;
 *target = info;
 lbl_804b03e8 = 1;
 }
 fn_801efd98(self, &lbl_8045d174);
 fn_801e8d9c(self);
 return 0;
}

int w3d_s10_register_array_801bbfd4(void *self)
{
 if (!lbl_804b03ec) {
 S10PropertyInfo *target = &lbl_8045d188;
 S10PropertyInfo info;
 memset(&info, 0, sizeof info);
 info.name = lbl_803ab708;
 info.size = 24;
 info.elementType = 1;
 info.type = 9;
 info.descriptor = lbl_8045ed1c;
 *target = info;
 lbl_804b03ec = 1;
 }
 fn_801efd34(self, &lbl_8045d188);
 fn_801e8d9c(self);
 return 0;
}

int w3d_s10_register_array_802268e4(void *self)
{
 if (!lbl_804b07e4) {
 S10PropertyInfo *target = &lbl_80464a7c;
 S10PropertyInfo info;
 memset(&info, 0, sizeof info);
 info.name = lbl_803b66c0;
 info.size = 48;
 info.elementType = 7;
 info.type = 9;
 info.descriptor = lbl_8045e23c;
 *target = info;
 lbl_804b07e4 = 1;
 }
 fn_801f2100(self, &lbl_80464a7c);
 fn_801e8d9c(self);
 return 0;
}

int w3d_s10_register_array_80226b34(void *self)
{
 if (!lbl_804b07e8) {
 S10PropertyInfo *target = &lbl_80464a90;
 S10PropertyInfo info;
 memset(&info, 0, sizeof info);
 info.name = lbl_803b66c0;
 info.size = 48;
 info.elementType = 7;
 info.type = 9;
 info.descriptor = lbl_8045e23c;
 *target = info;
 lbl_804b07e8 = 1;
 }
 fn_801f2100(self, &lbl_80464a90);
 fn_801e8d9c(self);
 return 0;
}

int w3d_s10_register_array_8023bb28(void *self)
{
 if (!lbl_804b0848) {
 S10PropertyInfo *target = &lbl_80464c84;
 S10PropertyInfo info;
 memset(&info, 0, sizeof info);
 info.name = lbl_803bb23c;
 info.size = 36;
 info.elementType = 4;
 info.type = 9;
 info.descriptor = lbl_8045ed94;
 *target = info;
 lbl_804b0848 = 1;
 }
 fn_801efff0(self, &lbl_80464c84);
 fn_801e8d9c(self);
 return 0;
}

int w3d_s10_register_array_8023bd78(void *self)
{
 if (!lbl_804b084c) {
 S10PropertyInfo *target = &lbl_80464c98;
 S10PropertyInfo info;
 memset(&info, 0, sizeof info);
 info.name = lbl_803bbe08;
 info.size = 36;
 info.elementType = 4;
 info.type = 9;
 info.descriptor = lbl_8045ed58;
 *target = info;
 lbl_804b084c = 1;
 }
 fn_801efe60(self, &lbl_80464c98);
 fn_801e8d9c(self);
 return 0;
}

int w3d_s10_register_array_8023c2ec(void *self)
{
 if (!lbl_804b0858) {
 S10PropertyInfo *target = &lbl_80464cd4;
 S10PropertyInfo info;
 memset(&info, 0, sizeof info);
 info.name = lbl_803bbe08;
 info.size = 36;
 info.elementType = 4;
 info.type = 9;
 info.descriptor = lbl_8045ed7c;
 *target = info;
 lbl_804b0858 = 1;
 }
 fn_801efec4(self, &lbl_80464cd4);
 fn_801e8d9c(self);
 return 0;
}
