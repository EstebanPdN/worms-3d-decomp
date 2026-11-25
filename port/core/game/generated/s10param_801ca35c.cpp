#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s10param_801ca35c.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

typedef struct S10PropertyInfo {
 Ptr32<const char> name;
 unsigned short size;
 unsigned char elementType;
 unsigned char type;
 Ptr32<void> descriptor;
 int unknown12;
 int unknown16;
} S10PropertyInfo;
extern S10PropertyInfo lbl_8045d69c, lbl_8045d6b0;
extern int lbl_804b04f0, lbl_804b04f4;
extern char lbl_803adc88[], lbl_803adc94[];
extern char lbl_8045e29c[], lbl_8045e47c[];
Ptr32<void> memset(Ptr32<void>, int, unsigned int);
int fn_801f2420(Ptr32<void>, Ptr32<S10PropertyInfo>);
int fn_801f25b0(Ptr32<void>, Ptr32<S10PropertyInfo>);
int fn_801e8d9c(Ptr32<void>);
extern S10PropertyInfo lbl_80464c5c, lbl_80464c70;
extern int lbl_804b0840, lbl_804b0844;
extern char lbl_803bb27c[], lbl_803bbdc8[];
extern char lbl_8045ed4c[], lbl_8045ed4c[];
int fn_801efdfc(Ptr32<void>, Ptr32<S10PropertyInfo>);
int fn_801efdfc(Ptr32<void>, Ptr32<S10PropertyInfo>);
extern S10PropertyInfo lbl_80464cac, lbl_80464cc0;
extern int lbl_804b0850, lbl_804b0854;
extern char lbl_803bbe08[], lbl_803bbe2c[];
extern char lbl_8045ed58[], lbl_8045ed58[];
int fn_801efe60(Ptr32<void>, Ptr32<S10PropertyInfo>);
int fn_801efe60(Ptr32<void>, Ptr32<S10PropertyInfo>);
extern S10PropertyInfo lbl_80464ce8, lbl_80464cfc;
extern int lbl_804b085c, lbl_804b0860;
extern char lbl_8045ed7c[], lbl_8045ed7c[];
int fn_801efec4(Ptr32<void>, Ptr32<S10PropertyInfo>);
int fn_801efec4(Ptr32<void>, Ptr32<S10PropertyInfo>);

int w3d_s10_register_two_arrays_801ca35c(Ptr32<void> self)
{
    S10PropertyInfo info;
    if (!lbl_804b04f0) {
        Ptr32<S10PropertyInfo> target = &lbl_8045d69c;
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
        Ptr32<S10PropertyInfo> target = &lbl_8045d6b0;
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

int w3d_s10_register_two_arrays_8023b840(Ptr32<void> self)
{
    S10PropertyInfo info;
    if (!lbl_804b0840) {
        Ptr32<S10PropertyInfo> target = &lbl_80464c5c;
        memset(&info, 0, sizeof info);
        info.name = lbl_803bb27c;
        info.size = 32;
        info.elementType = 2;
        info.type = 9;
        info.descriptor = lbl_8045ed4c;
        *target = info;
        lbl_804b0840 = 1;
    }
    fn_801efdfc(self, &lbl_80464c5c);
    if (!lbl_804b0844) {
        Ptr32<S10PropertyInfo> target = &lbl_80464c70;
        memset(&info, 0, sizeof info);
        info.name = lbl_803bbdc8;
        info.size = 28;
        info.elementType = 3;
        info.type = 9;
        info.descriptor = lbl_8045ed4c;
        *target = info;
        lbl_804b0844 = 1;
    }
    fn_801efdfc(self, &lbl_80464c70);
    fn_801e8d9c(self);
    return 0;
}

int w3d_s10_register_two_arrays_8023c004(Ptr32<void> self)
{
    S10PropertyInfo info;
    if (!lbl_804b0850) {
        Ptr32<S10PropertyInfo> target = &lbl_80464cac;
        memset(&info, 0, sizeof info);
        info.name = lbl_803bbe08;
        info.size = 40;
        info.elementType = 4;
        info.type = 9;
        info.descriptor = lbl_8045ed58;
        *target = info;
        lbl_804b0850 = 1;
    }
    fn_801efe60(self, &lbl_80464cac);
    if (!lbl_804b0854) {
        Ptr32<S10PropertyInfo> target = &lbl_80464cc0;
        memset(&info, 0, sizeof info);
        info.name = lbl_803bbe2c;
        info.size = 36;
        info.elementType = 5;
        info.type = 9;
        info.descriptor = lbl_8045ed58;
        *target = info;
        lbl_804b0854 = 1;
    }
    fn_801efe60(self, &lbl_80464cc0);
    fn_801e8d9c(self);
    return 0;
}

int w3d_s10_register_two_arrays_8023c578(Ptr32<void> self)
{
    S10PropertyInfo info;
    if (!lbl_804b085c) {
        Ptr32<S10PropertyInfo> target = &lbl_80464ce8;
        memset(&info, 0, sizeof info);
        info.name = lbl_803bbe08;
        info.size = 40;
        info.elementType = 4;
        info.type = 9;
        info.descriptor = lbl_8045ed7c;
        *target = info;
        lbl_804b085c = 1;
    }
    fn_801efec4(self, &lbl_80464ce8);
    if (!lbl_804b0860) {
        Ptr32<S10PropertyInfo> target = &lbl_80464cfc;
        memset(&info, 0, sizeof info);
        info.name = lbl_803bbe2c;
        info.size = 36;
        info.elementType = 5;
        info.type = 9;
        info.descriptor = lbl_8045ed7c;
        *target = info;
        lbl_804b0860 = 1;
    }
    fn_801efec4(self, &lbl_80464cfc);
    fn_801e8d9c(self);
    return 0;
}

}
