/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Static initializer template: file-scope pointers derived from a shared
 * base pointer, then a type object constructed in place (see families_b.cpp). */
inline void *operator new(unsigned int, void *place) { return place; }
typedef struct W3dSmallObject { int word0; int word1; } W3dSmallObject;
struct W3dType_8016115c { W3dType_8016115c(void *, void *, void *, int, int); int words[4]; };
extern "C" char *lbl_804aa91c;
extern "C" char *lbl_804ad108;
extern "C" char *lbl_804ad10c;
extern "C" char *lbl_804ad110;
extern "C" char *lbl_804ad114;
extern "C" char *lbl_804ad118;
extern "C" char *lbl_804ad11c;
extern "C" char *lbl_804ad120;
extern "C" char *lbl_804ad124;
extern "C" char *lbl_804ad128;
extern W3dType_8016115c lbl_8035ff70;
extern "C" char lbl_803e79b4[];
extern "C" char lbl_80361860[];
extern "C" void * fn_8003a850(void);
extern "C" void * fn_8015f518(void *, const char *);
extern "C" W3dSmallObject lbl_804ad12c;
extern "C" char lbl_8037432c[];
extern "C" char *lbl_804aaa78;
extern "C" char *lbl_804ad5b0;
extern "C" char *lbl_804ad5b4;
extern "C" char *lbl_804ad5b8;
extern "C" char *lbl_804ad5bc;
extern "C" char *lbl_804ad5c0;
extern "C" char *lbl_804ad5c4;
extern "C" char *lbl_804ad5c8;
extern "C" char *lbl_804ad5cc;
extern "C" char *lbl_804ad5d0;
extern W3dType_8016115c lbl_80360390;
extern "C" char lbl_803e7c1c[];
extern "C" void * fn_80066dfc(void);
extern "C" W3dSmallObject lbl_804ad5d4;
extern "C" char lbl_8037a0f4[];
struct W3dType_80160038 { W3dType_80160038(void *, void *, void *, int, int); int words[4]; };
extern "C" char *lbl_804aad9c;
extern "C" char *lbl_804ae5e8;
extern "C" char *lbl_804ae5ec;
extern "C" char *lbl_804ae5f0;
extern "C" char *lbl_804ae5f4;
extern "C" char *lbl_804ae5f8;
extern "C" char *lbl_804ae5fc;
extern "C" char *lbl_804ae600;
extern "C" char *lbl_804ae604;
extern "C" char *lbl_804ae608;
extern W3dType_80160038 lbl_80360930;
extern "C" char lbl_803e7f64[];
extern "C" char lbl_803617d0[];
extern "C" void * fn_800bed88(void);
extern "C" W3dSmallObject lbl_804ae60c;
extern "C" char lbl_80382e70[];
extern "C" char *lbl_804aade4;
extern "C" char *lbl_804ae768;
extern "C" char *lbl_804ae76c;
extern "C" char *lbl_804ae770;
extern "C" char *lbl_804ae774;
extern "C" char *lbl_804ae778;
extern "C" char *lbl_804ae77c;
extern "C" char *lbl_804ae780;
extern "C" char *lbl_804ae784;
extern "C" char *lbl_804ae788;
extern W3dType_80160038 lbl_80360a50;
extern "C" char lbl_803e800c[];
extern "C" void * fn_800c3fa4(void);
extern "C" W3dSmallObject lbl_804ae78c;
extern "C" char lbl_80383570[];

extern "C" void w3d_sinit_derived_pointers_8003b7f8(int initialize, int priority)
{
    if (priority == 0xffff && initialize) {
        lbl_804ad108 = lbl_804aa91c + 16384;
        lbl_804ad10c = lbl_804aa91c;
        lbl_804ad110 = lbl_804aa91c + 736;
        lbl_804ad114 = lbl_804aa91c + 12400;
        lbl_804ad118 = lbl_804aa91c;
        lbl_804ad11c = lbl_804aa91c + 16368;
        lbl_804ad120 = lbl_804aa91c + 16304;
        lbl_804ad124 = lbl_804aa91c + 16176;
        lbl_804ad128 = lbl_804aa91c;
        new (&lbl_8035ff70) W3dType_8016115c(lbl_803e79b4, lbl_80361860, (void *)fn_8003a850, 11, 0);
        fn_8015f518(&lbl_804ad12c, lbl_8037432c);
    }
}

extern "C" void w3d_sinit_derived_pointers_80067894(int initialize, int priority)
{
    if (priority == 0xffff && initialize) {
        lbl_804ad5b0 = lbl_804aaa78 + 16384;
        lbl_804ad5b4 = lbl_804aaa78;
        lbl_804ad5b8 = lbl_804aaa78 + 736;
        lbl_804ad5bc = lbl_804aaa78 + 12400;
        lbl_804ad5c0 = lbl_804aaa78;
        lbl_804ad5c4 = lbl_804aaa78 + 16368;
        lbl_804ad5c8 = lbl_804aaa78 + 16304;
        lbl_804ad5cc = lbl_804aaa78 + 16176;
        lbl_804ad5d0 = lbl_804aaa78;
        new (&lbl_80360390) W3dType_8016115c(lbl_803e7c1c, lbl_80361860, (void *)fn_80066dfc, 11, 0);
        fn_8015f518(&lbl_804ad5d4, lbl_8037a0f4);
    }
}

extern "C" void w3d_sinit_derived_pointers_800bfdac(int initialize, int priority)
{
    if (priority == 0xffff && initialize) {
        lbl_804ae5e8 = lbl_804aad9c + 16384;
        lbl_804ae5ec = lbl_804aad9c;
        lbl_804ae5f0 = lbl_804aad9c + 736;
        lbl_804ae5f4 = lbl_804aad9c + 12400;
        lbl_804ae5f8 = lbl_804aad9c;
        lbl_804ae5fc = lbl_804aad9c + 16368;
        lbl_804ae600 = lbl_804aad9c + 16304;
        lbl_804ae604 = lbl_804aad9c + 16176;
        lbl_804ae608 = lbl_804aad9c;
        new (&lbl_80360930) W3dType_80160038(lbl_803e7f64, lbl_803617d0, (void *)fn_800bed88, 9, 0);
        fn_8015f518(&lbl_804ae60c, lbl_80382e70);
    }
}

extern "C" void w3d_sinit_derived_pointers_800c44b4(int initialize, int priority)
{
    if (priority == 0xffff && initialize) {
        lbl_804ae768 = lbl_804aade4 + 16384;
        lbl_804ae76c = lbl_804aade4;
        lbl_804ae770 = lbl_804aade4 + 736;
        lbl_804ae774 = lbl_804aade4 + 12400;
        lbl_804ae778 = lbl_804aade4;
        lbl_804ae77c = lbl_804aade4 + 16368;
        lbl_804ae780 = lbl_804aade4 + 16304;
        lbl_804ae784 = lbl_804aade4 + 16176;
        lbl_804ae788 = lbl_804aade4;
        new (&lbl_80360a50) W3dType_80160038(lbl_803e800c, lbl_803617d0, (void *)fn_800c3fa4, 9, 0);
        fn_8015f518(&lbl_804ae78c, lbl_80383570);
    }
}
