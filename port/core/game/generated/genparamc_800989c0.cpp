#include "w3d_ptr.h"
#line 1 "genparamc_800989c0.cpp"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Pair template (later batch): derived-pointer static initializer (layout
 * as families_e.cpp). */
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
inline void *operator new(__SIZE_TYPE__, void *place) { return place; }
struct W3dType_8016115c { W3dType_8016115c(Ptr32<void>, Ptr32<void>, Ptr32<void>, int, int); int words[4]; };
extern "C" Ptr32<char> lbl_804aabbc;
extern "C" Ptr32<char> lbl_804adf98;
extern "C" Ptr32<char> lbl_804adf9c;
extern "C" Ptr32<char> lbl_804adfa0;
extern "C" Ptr32<char> lbl_804adfa4;
extern "C" Ptr32<char> lbl_804adfa8;
extern "C" Ptr32<char> lbl_804adfac;
extern "C" Ptr32<char> lbl_804adfb0;
extern "C" Ptr32<char> lbl_804adfb4;
extern "C" Ptr32<char> lbl_804adfb8;
extern W3dType_8016115c lbl_803605d0;
extern "C" char lbl_803e7d6c[];
extern "C" char lbl_80360000[];
extern "C" Ptr32<void> fn_80097fd8(void);
struct W3dType_80160038 { W3dType_80160038(Ptr32<void>, Ptr32<void>, Ptr32<void>, int, int); int words[4]; };
extern "C" Ptr32<char> lbl_804aaf20;
extern "C" Ptr32<char> lbl_804af0a0;
extern "C" Ptr32<char> lbl_804af0a4;
extern "C" Ptr32<char> lbl_804af0a8;
extern "C" Ptr32<char> lbl_804af0ac;
extern "C" Ptr32<char> lbl_804af0b0;
extern "C" Ptr32<char> lbl_804af0b4;
extern "C" Ptr32<char> lbl_804af0b8;
extern "C" Ptr32<char> lbl_804af0bc;
extern "C" Ptr32<char> lbl_804af0c0;
extern W3dType_80160038 lbl_80360f30;
extern "C" char lbl_803e82e4[];
extern "C" char lbl_803617d0[];
extern "C" Ptr32<void> fn_800f1d58(void);

extern "C" void w3d_sinit_derived_only_800989c0(int initialize, int priority)
{
    if (priority == 0xffff && initialize) {
        lbl_804adf98 = lbl_804aabbc + 16384;
        lbl_804adf9c = lbl_804aabbc;
        lbl_804adfa0 = lbl_804aabbc + 736;
        lbl_804adfa4 = lbl_804aabbc + 12400;
        lbl_804adfa8 = lbl_804aabbc;
        lbl_804adfac = lbl_804aabbc + 16368;
        lbl_804adfb0 = lbl_804aabbc + 16304;
        lbl_804adfb4 = lbl_804aabbc + 16176;
        lbl_804adfb8 = lbl_804aabbc;
        new (&lbl_803605d0) W3dType_8016115c(lbl_803e7d6c, lbl_80360000, (Ptr32<void>)fn_80097fd8, 11, 0);
    }
}

extern "C" void w3d_sinit_derived_only_800f28d8(int initialize, int priority)
{
    if (priority == 0xffff && initialize) {
        lbl_804af0a0 = lbl_804aaf20 + 16384;
        lbl_804af0a4 = lbl_804aaf20;
        lbl_804af0a8 = lbl_804aaf20 + 736;
        lbl_804af0ac = lbl_804aaf20 + 12400;
        lbl_804af0b0 = lbl_804aaf20;
        lbl_804af0b4 = lbl_804aaf20 + 16368;
        lbl_804af0b8 = lbl_804aaf20 + 16304;
        lbl_804af0bc = lbl_804aaf20 + 16176;
        lbl_804af0c0 = lbl_804aaf20;
        new (&lbl_80360f30) W3dType_80160038(lbl_803e82e4, lbl_803617d0, (Ptr32<void>)fn_800f1d58, 9, 0);
    }
}


