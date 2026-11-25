/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Static initializers that construct a file-scope type object in place.
 * The original passes the object as `this` of a C++ constructor, so its
 * address is loaded after the other arguments; placement new on the object
 * (referenced by address until its unit owns the data) reproduces that. */

inline void *operator new(unsigned int, void *place) { return place; }
typedef struct W3dSmallObject { int word0; int word1; } W3dSmallObject;
struct W3dType_801e7174 { W3dType_801e7174(void *, void *, void *, int, void *); int words[4]; };
struct W3dType_8016115c { W3dType_8016115c(void *, void *, void *, int, int); int words[4]; };
extern W3dType_801e7174 lbl_803621a8;
extern "C" char lbl_803e8cbc[];
extern "C" char lbl_8036573c[];
extern "C" char lbl_803fe96c[];
extern "C" void *lbl_804b0310;
extern "C" void * fn_8019c1dc(void);
extern "C" int fn_801e74d0(void *);
extern "C" void fn_801fc86c(void *);
extern W3dType_8016115c lbl_8035fb50;
extern "C" char lbl_803e774c[];
extern "C" char lbl_80361860[];
extern "C" void * fn_80024c34(void);
extern "C" void * fn_8015f518(void *, const char *);
extern "C" W3dSmallObject lbl_804aca8c;
extern "C" W3dSmallObject lbl_804aca94;
extern "C" char lbl_8036c7f8[];
extern "C" char lbl_8036c80c[];
extern W3dType_8016115c lbl_8035fbb0;
extern "C" char lbl_803e7784[];
extern "C" void * fn_8002575c(void);
extern "C" W3dSmallObject lbl_804acad4;
extern "C" W3dSmallObject lbl_804acadc;
extern "C" char lbl_8036c924[];
extern "C" char lbl_8036c938[];
struct W3dType_80160038 { W3dType_80160038(void *, void *, void *, int, int); int words[4]; };
extern W3dType_80160038 lbl_8035fee0;
extern "C" char lbl_803e7960[];
extern "C" char lbl_803617d0[];
extern "C" void * fn_800378b4(void);
extern "C" W3dSmallObject lbl_804ad050;
extern "C" W3dSmallObject lbl_804ad058;
extern "C" char lbl_80373fbc[];
extern "C" char lbl_80373fd0[];
struct W3dType_801629f8 { W3dType_801629f8(void *, void *, void *, int, int); int words[4]; };
extern W3dType_801629f8 lbl_803601e0;
extern "C" char lbl_803e7b20[];
extern "C" char lbl_803618f0[];
extern "C" void * fn_80051bc8(void);
extern "C" W3dSmallObject lbl_804ad478;
extern "C" W3dSmallObject lbl_804ad480;
extern "C" char lbl_80378220[];
extern "C" char lbl_80378230[];
extern W3dType_80160038 lbl_80361560;
extern "C" char lbl_803e8680[];
extern "C" void * fn_8012ff20(void);
extern "C" W3dSmallObject lbl_804af730;
extern "C" W3dSmallObject lbl_804af738;
extern "C" char lbl_8039e1f4[];
extern "C" char lbl_8039e204[];
extern W3dType_801e7174 lbl_803621f4;
extern "C" char lbl_803e8cd8[];
extern "C" char lbl_803fe98c[];
extern "C" void *lbl_804b0314;
extern "C" void * fn_8019ca74(void);
extern W3dType_801e7174 lbl_803623f8;
extern "C" char lbl_803e8dd4[];
extern "C" char lbl_803fea0c[];
extern "C" void *lbl_804b0334;
extern "C" void * fn_801a70ec(void);
extern W3dType_801e7174 lbl_80362528;
extern "C" char lbl_803e8e44[];
extern "C" char lbl_803fea8c[];
extern "C" void *lbl_804b0348;
extern "C" void * fn_801ac614(void);
extern W3dType_801e7174 lbl_80362574;
extern "C" char lbl_803e8e60[];
extern "C" char lbl_803feaac[];
extern "C" void *lbl_804b034c;
extern "C" void * fn_801ae250(void);
extern W3dType_801e7174 lbl_803625f0;
extern "C" char lbl_803e8e98[];
extern "C" char lbl_803feacc[];
extern "C" void *lbl_804b0350;
extern "C" void * fn_801b0bb0(void);
extern W3dType_801e7174 lbl_8036263c;
extern "C" char lbl_803e8eb4[];
extern "C" char lbl_803feaec[];
extern "C" void *lbl_804b0354;
extern "C" void * fn_801b1634(void);
extern W3dType_801e7174 lbl_80362688;
extern "C" char lbl_803e8ed0[];
extern "C" char lbl_803feb0c[];
extern "C" void *lbl_804b0358;
extern "C" void * fn_801b2114(void);
extern W3dType_801e7174 lbl_803653e0;
extern "C" char lbl_803e9ee4[];
extern "C" char lbl_803ff154[];
extern "C" void *lbl_804b0540;
extern "C" void * fn_801d40c4(void);
extern W3dType_801e7174 lbl_8036545c;
extern "C" char lbl_803e9f1c[];
extern "C" char lbl_803ff174[];
extern "C" void *lbl_804b0544;
extern "C" void * fn_801d4ed0(void);
extern W3dType_80160038 lbl_80368668;
extern "C" char lbl_803eb278[];
extern "C" void * fn_80268734(void);
extern "C" W3dSmallObject lbl_804b0ac4;
extern "C" W3dSmallObject lbl_804b0acc;
extern "C" char lbl_803cbb40[];
extern "C" char lbl_803cbb54[];

extern "C" void w3d_sinit_messages_80024f94(int initialize, int priority)
{
    if (priority == 0xffff && initialize) {
        new (&lbl_8035fb50) W3dType_8016115c(lbl_803e774c, lbl_80361860, (void *)fn_80024c34, 11, 0);
        fn_8015f518(&lbl_804aca8c, lbl_8036c7f8);
        fn_8015f518(&lbl_804aca94, lbl_8036c80c);
    }
}

extern "C" void w3d_sinit_messages_80025b38(int initialize, int priority)
{
    if (priority == 0xffff && initialize) {
        new (&lbl_8035fbb0) W3dType_8016115c(lbl_803e7784, lbl_80361860, (void *)fn_8002575c, 11, 0);
        fn_8015f518(&lbl_804acad4, lbl_8036c924);
        fn_8015f518(&lbl_804acadc, lbl_8036c938);
    }
}

extern "C" void w3d_sinit_messages_800386bc(int initialize, int priority)
{
    if (priority == 0xffff && initialize) {
        new (&lbl_8035fee0) W3dType_80160038(lbl_803e7960, lbl_803617d0, (void *)fn_800378b4, 9, 0);
        fn_8015f518(&lbl_804ad050, lbl_80373fbc);
        fn_8015f518(&lbl_804ad058, lbl_80373fd0);
    }
}

extern "C" void w3d_sinit_messages_80052048(int initialize, int priority)
{
    if (priority == 0xffff && initialize) {
        new (&lbl_803601e0) W3dType_801629f8(lbl_803e7b20, lbl_803618f0, (void *)fn_80051bc8, 10, 0);
        fn_8015f518(&lbl_804ad478, lbl_80378220);
        fn_8015f518(&lbl_804ad480, lbl_80378230);
    }
}

extern "C" void w3d_sinit_messages_80131818(int initialize, int priority)
{
    if (priority == 0xffff && initialize) {
        new (&lbl_80361560) W3dType_80160038(lbl_803e8680, lbl_803617d0, (void *)fn_8012ff20, 9, 0);
        fn_8015f518(&lbl_804af730, lbl_8039e1f4);
        fn_8015f518(&lbl_804af738, lbl_8039e204);
    }
}

extern "C" void w3d_sinit_type_cache_8019c980(int initialize, int priority)
{
    if (priority == 0xffff && initialize) {
        new (&lbl_803621a8) W3dType_801e7174(lbl_803e8cbc, lbl_8036573c, (void *)fn_8019c1dc, 1, (void *)fn_801e74d0);
        lbl_804b0310 = lbl_803fe96c;
        fn_801fc86c(lbl_803fe96c);
    }
}

extern "C" void w3d_sinit_type_cache_8019d494(int initialize, int priority)
{
    if (priority == 0xffff && initialize) {
        new (&lbl_803621f4) W3dType_801e7174(lbl_803e8cd8, lbl_8036573c, (void *)fn_8019ca74, 1, (void *)fn_801e74d0);
        lbl_804b0314 = lbl_803fe98c;
        fn_801fc86c(lbl_803fe98c);
    }
}

extern "C" void w3d_sinit_type_cache_801a7e34(int initialize, int priority)
{
    if (priority == 0xffff && initialize) {
        new (&lbl_803623f8) W3dType_801e7174(lbl_803e8dd4, lbl_8036573c, (void *)fn_801a70ec, 1, (void *)fn_801e74d0);
        lbl_804b0334 = lbl_803fea0c;
        fn_801fc86c(lbl_803fea0c);
    }
}

extern "C" void w3d_sinit_type_cache_801ae15c(int initialize, int priority)
{
    if (priority == 0xffff && initialize) {
        new (&lbl_80362528) W3dType_801e7174(lbl_803e8e44, lbl_8036573c, (void *)fn_801ac614, 1, (void *)fn_801e74d0);
        lbl_804b0348 = lbl_803fea8c;
        fn_801fc86c(lbl_803fea8c);
    }
}

extern "C" void w3d_sinit_type_cache_801ae8a4(int initialize, int priority)
{
    if (priority == 0xffff && initialize) {
        new (&lbl_80362574) W3dType_801e7174(lbl_803e8e60, lbl_8036573c, (void *)fn_801ae250, 1, (void *)fn_801e74d0);
        lbl_804b034c = lbl_803feaac;
        fn_801fc86c(lbl_803feaac);
    }
}

extern "C" void w3d_sinit_type_cache_801b1444(int initialize, int priority)
{
    if (priority == 0xffff && initialize) {
        new (&lbl_803625f0) W3dType_801e7174(lbl_803e8e98, lbl_8036573c, (void *)fn_801b0bb0, 1, (void *)fn_801e74d0);
        lbl_804b0350 = lbl_803feacc;
        fn_801fc86c(lbl_803feacc);
    }
}

extern "C" void w3d_sinit_type_cache_801b2020(int initialize, int priority)
{
    if (priority == 0xffff && initialize) {
        new (&lbl_8036263c) W3dType_801e7174(lbl_803e8eb4, lbl_8036573c, (void *)fn_801b1634, 1, (void *)fn_801e74d0);
        lbl_804b0354 = lbl_803feaec;
        fn_801fc86c(lbl_803feaec);
    }
}

extern "C" void w3d_sinit_type_cache_801b29bc(int initialize, int priority)
{
    if (priority == 0xffff && initialize) {
        new (&lbl_80362688) W3dType_801e7174(lbl_803e8ed0, lbl_8036573c, (void *)fn_801b2114, 1, (void *)fn_801e74d0);
        lbl_804b0358 = lbl_803feb0c;
        fn_801fc86c(lbl_803feb0c);
    }
}

extern "C" void w3d_sinit_type_cache_801d449c(int initialize, int priority)
{
    if (priority == 0xffff && initialize) {
        new (&lbl_803653e0) W3dType_801e7174(lbl_803e9ee4, lbl_8036573c, (void *)fn_801d40c4, 1, (void *)fn_801e74d0);
        lbl_804b0540 = lbl_803ff154;
        fn_801fc86c(lbl_803ff154);
    }
}

extern "C" void w3d_sinit_type_cache_801d51d0(int initialize, int priority)
{
    if (priority == 0xffff && initialize) {
        new (&lbl_8036545c) W3dType_801e7174(lbl_803e9f1c, lbl_8036573c, (void *)fn_801d4ed0, 1, (void *)fn_801e74d0);
        lbl_804b0544 = lbl_803ff174;
        fn_801fc86c(lbl_803ff174);
    }
}

extern "C" void w3d_sinit_messages_8026c660(int initialize, int priority)
{
    if (priority == 0xffff && initialize) {
        new (&lbl_80368668) W3dType_80160038(lbl_803eb278, lbl_803617d0, (void *)fn_80268734, 9, 0);
        fn_8015f518(&lbl_804b0ac4, lbl_803cbb40);
        fn_8015f518(&lbl_804b0acc, lbl_803cbb54);
    }
}
