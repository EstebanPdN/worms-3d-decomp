extern "C" void *fn_801e8a88(void *, void *, void *, void *, int, void *);
extern "C" char lbl_80365788[], lbl_80362704[], lbl_80362754[], lbl_803627a4[], lbl_803627f4[], lbl_80362844[];
extern "C" char lbl_803e8f24[], lbl_803e8f40[], lbl_803e8f5c[], lbl_803e8f78[], lbl_803e8f94[];
extern "C" void * fn_801b5044(void);
extern "C" int fn_801b4f60(void *);
extern "C" void * fn_801b4de8(void);
extern "C" int fn_801b4cd4(void *);
extern "C" void * fn_801b4b20(void);
extern "C" int fn_801b54e0(void *);
extern "C" void * fn_801b5358(void);
extern "C" int fn_801b5328(void *);
extern "C" void * fn_801b51f0(void);
extern "C" int fn_801b51a4(void *);
extern "C" void w3d_cc17c_sinit_801b5550(int init, int priority)
{
    if (priority == 0xffff && init) {
        fn_801e8a88(lbl_80362704, lbl_803e8f24, lbl_80365788, (void *)fn_801b4b20, 2, (void *)fn_801b4cd4);
        fn_801e8a88(lbl_80362754, lbl_803e8f40, lbl_80362704, (void *)fn_801b4de8, 2, (void *)fn_801b4f60);
        fn_801e8a88(lbl_803627a4, lbl_803e8f5c, lbl_80362754, (void *)fn_801b5044, 2, (void *)fn_801b51a4);
        fn_801e8a88(lbl_803627f4, lbl_803e8f78, lbl_80365788, (void *)fn_801b51f0, 2, (void *)fn_801b5328);
        fn_801e8a88(lbl_80362844, lbl_803e8f94, lbl_80362704, (void *)fn_801b5358, 2, (void *)fn_801b54e0);
    }
}
