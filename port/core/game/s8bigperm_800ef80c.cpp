#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s8bigperm_800ef80c.c"

typedef signed char s8;
typedef short s16;
typedef int s32;
typedef long long s64;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
typedef s64 M2C_UNK64;
Ptr32<void> fn_80341584(Ptr32<void>);
Ptr32<void> fn_80343584(Ptr32<void>);
Ptr32<void> fn_803426B4(Ptr32<void>);
Ptr32<void> fn_80343744(Ptr32<void>);
Ptr32<void> fn_80179598(Ptr32<void>, int);
Ptr32<void> fn_801797B4(Ptr32<void>);
int fn_80178C48(Ptr32<void>);
Ptr32<void> fn_801613F0(Ptr32<void>, int);
int fn_8016239C(Ptr32<void>);
int fn_8015FC58(Ptr32<void>, Ptr32<void>);
Ptr32<void> fn_800C1620(Ptr32<void>, Ptr32<int>);
Ptr32<void> fn_80125FDC(Ptr32<void>, unsigned, int);
unsigned fn_8015F5A0(Ptr32<void>, int);
int fn_80162024(Ptr32<void>, Ptr32<unsigned short>, Ptr32<void>);
int fn_8016115C(Ptr32<void>, Ptr32<void>, Ptr32<void>, Ptr32<void (void)>, int, int);
int fn_801629F8(Ptr32<void>, Ptr32<void>, Ptr32<void>, Ptr32<void (void)>, int, int);
int fn_8015F518(Ptr32<void>, Ptr32<const char>);
int fn_802EEE50(Ptr32<void>, Ptr32<const void>, unsigned, ...);
int fn_802EF234(Ptr32<const char>, Ptr32<const char>);
Ptr32<void> fn_8020BB54(Ptr32<void>, Ptr32<const char>);
int fn_8020C5C4(Ptr32<void>);
int fn_80341588(Ptr32<void>);
Ptr32<void> fn_80212FD4(unsigned);
void fn_802134FC(Ptr32<void>);
Ptr32<void> fn_80164FC8(Ptr32<void>);
int fn_80181640(Ptr32<void>, int, Ptr32<void>, int, float, float, float);
int fn_80181CCC(Ptr32<void>, int);
int fn_801817E0(Ptr32<void>, int);
extern Ptr32<void> lbl_804B1754;
extern Ptr32<void> lbl_804B1788;
extern char lbl_8040DB38[];
Ptr32<void> fn_800EE1A0();
extern M2C_UNK lbl_80360E40[];
extern M2C_UNK lbl_80361860[];
extern s8 lbl_8038BEBC[];
extern s8 lbl_8038BECC[];
extern s8 lbl_8038BEE4[];
extern s8 lbl_8038BEF8[];
extern s8 lbl_8038BF0C[];
extern s8 lbl_8038BF20[];
extern s8 lbl_8038BF38[];
extern s8 lbl_8038BF54[];
extern s8 lbl_8038BF70[];
extern s8 lbl_8038BF8C[];
extern s8 lbl_8038BFAC[];
extern s8 lbl_8038BFCC[];
extern s8 lbl_8038BFE8[];
extern s8 lbl_8038C000[];
extern s8 lbl_8038C014[];
extern s8 lbl_8038C034[];
extern s8 lbl_8038C04C[];
extern s8 lbl_8038C060[];
extern s8 lbl_8038C070[];
extern s8 lbl_8038C088[];
extern s8 lbl_8038C0A0[];
extern s8 lbl_8038C0B4[];
extern s8 lbl_8038C0C8[];
extern s8 lbl_8038C0DC[];
extern s8 lbl_8038C0F0[];
extern f32 lbl_8038C104[];
extern f32 lbl_8038C108[];
extern M2C_UNK lbl_803E8258[];
extern M2C_UNK lbl_804494B0[];
extern M2C_UNK lbl_804AEF5C;
extern M2C_UNK lbl_804AEF64;
extern M2C_UNK lbl_804AEF6C;
extern M2C_UNK lbl_804AEF74;
extern M2C_UNK lbl_804AEF7C;
extern M2C_UNK lbl_804AEF84;
extern M2C_UNK lbl_804AEF8C;
extern M2C_UNK lbl_804AEF94;
extern M2C_UNK lbl_804AEF9C;
extern M2C_UNK lbl_804AEFA4;
extern M2C_UNK lbl_804AEFAC;
extern M2C_UNK lbl_804AEFB4;
extern M2C_UNK lbl_804AEFBC;
extern M2C_UNK lbl_804AEFC4;
extern M2C_UNK lbl_804AEFCC;
extern M2C_UNK lbl_804AEFD4;
extern M2C_UNK lbl_804AEFDC;
extern M2C_UNK lbl_804AEFE4;
extern M2C_UNK lbl_804AEFEC;
extern M2C_UNK lbl_804AEFF4;
extern M2C_UNK lbl_804AEFFC;
extern M2C_UNK lbl_804AF004;
extern M2C_UNK lbl_804AF00C;
extern M2C_UNK lbl_804AF014;
extern M2C_UNK lbl_804AF01C;
void s8_permuted_800ef80c(s32 arg0, s32 arg1)
{
  if ((arg1 == 0xFFFF) && (arg0 != 0))
  {
    *((Ptr32<f32>) (((Ptr32<s8>) (&(*lbl_804494B0))) + 0)) = (f32) (*lbl_8038C104);
    *((Ptr32<f32>) (((Ptr32<s8>) (&(*lbl_804494B0))) + 4)) = (f32) (*lbl_8038C104);
    *((Ptr32<f32>) (((Ptr32<s8>) (&(*lbl_804494B0))) + 8)) = (f32) (*lbl_8038C108);
    fn_8016115C(&(*lbl_80360E40), &(*lbl_803E8258), &(*lbl_80361860), fn_800EE1A0, 0xB, 0);
    fn_8015F518(&lbl_804AEF5C, &(*lbl_8038BEBC));
    fn_8015F518(&lbl_804AEF64, &(*lbl_8038BECC));
    if (1)
    {
      fn_8015F518(&lbl_804AEF6C, &(*lbl_8038BEE4));
      fn_8015F518(&lbl_804AEF74, &(*lbl_8038BEF8));
      fn_8015F518(&lbl_804AEF7C, &(*lbl_8038BF0C));
      fn_8015F518(&lbl_804AEF84, &(*lbl_8038BF20));
    }
    fn_8015F518(&lbl_804AEF8C, &(*lbl_8038BF38));
    fn_8015F518(&lbl_804AEF94, &(*lbl_8038BF54));
    fn_8015F518(&lbl_804AEF9C, &(*lbl_8038BF70));
    fn_8015F518(&lbl_804AEFA4, &(*lbl_8038BF8C));
    fn_8015F518(&lbl_804AEFAC, &(*lbl_8038BFAC));
    fn_8015F518(&lbl_804AEFB4, &(*lbl_8038BFCC));
    fn_8015F518(&lbl_804AEFBC, &(*lbl_8038BFE8));
    fn_8015F518(&lbl_804AEFC4, &(*lbl_8038C000));
    fn_8015F518(&lbl_804AEFCC, &(*lbl_8038C014));
    fn_8015F518(&lbl_804AEFD4, &(*lbl_8038C034));
    fn_8015F518(&lbl_804AEFDC, &(*lbl_8038C04C));
    fn_8015F518(&lbl_804AEFE4, &(*lbl_8038C060));
    fn_8015F518(&lbl_804AEFEC, &(*lbl_8038C070));
    fn_8015F518(&lbl_804AEFF4, &(*lbl_8038C088));
    fn_8015F518(&lbl_804AEFFC, &(*lbl_8038C0A0));
    fn_8015F518(&lbl_804AF004, &(*lbl_8038C0B4));
    fn_8015F518(&lbl_804AF00C, &(*lbl_8038C0C8));
    fn_8015F518(&lbl_804AF014, &(*lbl_8038C0DC));
    fn_8015F518(&lbl_804AF01C, &(*lbl_8038C0F0));
  }
}

}
