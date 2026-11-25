#include "w3d_ptr.h"
#line 1 "genparamc_800202d8.cpp"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Static initializer template (later batch): derived pointers, type object
 * constructed in place and two cached message names (see families_e.cpp). */
inline void *operator new(__SIZE_TYPE__, void *place) { return place; }
typedef struct W3dSmallObject { int word0; int word1; } W3dSmallObject;
struct W3dType_801629f8 { W3dType_801629f8(Ptr32<void>, Ptr32<void>, Ptr32<void>, int, int); int words[4]; };
extern "C" Ptr32<char> lbl_804aa784;
extern "C" Ptr32<char> lbl_804ac918;
extern "C" Ptr32<char> lbl_804ac91c;
extern "C" Ptr32<char> lbl_804ac920;
extern "C" Ptr32<char> lbl_804ac924;
extern "C" Ptr32<char> lbl_804ac928;
extern "C" Ptr32<char> lbl_804ac92c;
extern "C" Ptr32<char> lbl_804ac930;
extern "C" Ptr32<char> lbl_804ac934;
extern "C" Ptr32<char> lbl_804ac938;
extern W3dType_801629f8 lbl_8035fa60;
extern "C" char lbl_803e76c0[];
extern "C" char lbl_803618f0[];
extern "C" Ptr32<void> fn_8001c770(void);
extern "C" Ptr32<void> fn_8015f518(Ptr32<void>, Ptr32<const char>);
extern "C" W3dSmallObject lbl_804ac93c;
extern "C" W3dSmallObject lbl_804ac944;
extern "C" char lbl_8036ba6c[];
extern "C" char lbl_8036ba80[];
struct W3dType_8016115c { W3dType_8016115c(Ptr32<void>, Ptr32<void>, Ptr32<void>, int, int); int words[4]; };
extern "C" Ptr32<char> lbl_804aa944;
extern "C" Ptr32<char> lbl_804ad188;
extern "C" Ptr32<char> lbl_804ad18c;
extern "C" Ptr32<char> lbl_804ad190;
extern "C" Ptr32<char> lbl_804ad194;
extern "C" Ptr32<char> lbl_804ad198;
extern "C" Ptr32<char> lbl_804ad19c;
extern "C" Ptr32<char> lbl_804ad1a0;
extern "C" Ptr32<char> lbl_804ad1a4;
extern "C" Ptr32<char> lbl_804ad1a8;
extern W3dType_8016115c lbl_80360000;
extern "C" char lbl_803e7a08[];
extern "C" char lbl_80361860[];
extern "C" Ptr32<void> fn_8003dd0c(void);
extern "C" W3dSmallObject lbl_804ad1ac;
extern "C" W3dSmallObject lbl_804ad1b4;
extern "C" char lbl_8037469c[];
extern "C" char lbl_803746ac[];

extern "C" void w3d_sinit_derived_messages_800202d8(int initialize, int priority)
{
    if (priority == 0xffff && initialize) {
        lbl_804ac918 = lbl_804aa784 + 16384;
        lbl_804ac91c = lbl_804aa784;
        lbl_804ac920 = lbl_804aa784 + 736;
        lbl_804ac924 = lbl_804aa784 + 12400;
        lbl_804ac928 = lbl_804aa784;
        lbl_804ac92c = lbl_804aa784 + 16368;
        lbl_804ac930 = lbl_804aa784 + 16304;
        lbl_804ac934 = lbl_804aa784 + 16176;
        lbl_804ac938 = lbl_804aa784;
        new (&lbl_8035fa60) W3dType_801629f8(lbl_803e76c0, lbl_803618f0, (Ptr32<void>)fn_8001c770, 10, 0);
        fn_8015f518(&lbl_804ac93c, lbl_8036ba6c);
        fn_8015f518(&lbl_804ac944, lbl_8036ba80);
    }
}

extern "C" void w3d_sinit_derived_messages_8003f028(int initialize, int priority)
{
    if (priority == 0xffff && initialize) {
        lbl_804ad188 = lbl_804aa944 + 16384;
        lbl_804ad18c = lbl_804aa944;
        lbl_804ad190 = lbl_804aa944 + 736;
        lbl_804ad194 = lbl_804aa944 + 12400;
        lbl_804ad198 = lbl_804aa944;
        lbl_804ad19c = lbl_804aa944 + 16368;
        lbl_804ad1a0 = lbl_804aa944 + 16304;
        lbl_804ad1a4 = lbl_804aa944 + 16176;
        lbl_804ad1a8 = lbl_804aa944;
        new (&lbl_80360000) W3dType_8016115c(lbl_803e7a08, lbl_80361860, (Ptr32<void>)fn_8003dd0c, 11, 0);
        fn_8015f518(&lbl_804ad1ac, lbl_8037469c);
        fn_8015f518(&lbl_804ad1b4, lbl_803746ac);
    }
}


