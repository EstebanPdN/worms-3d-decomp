// Observed startup type-descriptor constructor chain.
// Names remain address based; constructor arguments are original witnesses.
extern "C" void *fn_801e8a88(void *, void *, void *, void *, int, void *);
extern "C" char lbl_80365788[], lbl_803682d8[], lbl_80368328[], lbl_80368378[], lbl_803683c8[], lbl_80368418[];
extern "C" char lbl_80368468[], lbl_803684b8[], lbl_80368508[], lbl_80368558[], lbl_803eb10c[], lbl_803eb128[];
extern "C" char lbl_803eb144[], lbl_803eb160[], lbl_803eb17c[], lbl_803eb198[], lbl_803eb1b4[], lbl_803eb1d0[];
extern "C" char lbl_803eb1ec[];
extern "C" int fn_802551dc(void *);
extern "C" void * fn_80255074(void);
extern "C" int fn_80253c80(void *);
extern "C" void * fn_80253284(void);
extern "C" int fn_802525c4(void *);
extern "C" void * fn_80251e94(void);
extern "C" int fn_80256158(void *);
extern "C" void * fn_80255d30(void);
extern "C" int fn_80255850(void *);
extern "C" void * fn_80255504(void);
extern "C" int fn_80255418(void *);
extern "C" void * fn_802552a8(void);
extern "C" int fn_8025768c(void *);
extern "C" void * fn_8025747c(void);
extern "C" int fn_80257110(void *);
extern "C" void * fn_80256f00(void);
extern "C" int fn_80256b3c(void *);
extern "C" void * fn_80256890(void);
//===
extern "C" void w3d_cc18b_type_chain_802579ec(int init, int priority)
{
    if (priority == 0xffff && init) {
        fn_801e8a88(lbl_803682d8, lbl_803eb10c, lbl_80365788, (void *)fn_80251e94, 2, (void *)fn_802525c4);
        fn_801e8a88(lbl_80368328, lbl_803eb128, lbl_803682d8, (void *)fn_80253284, 2, (void *)fn_80253c80);
        fn_801e8a88(lbl_80368378, lbl_803eb144, lbl_80368328, (void *)fn_80255074, 2, (void *)fn_802551dc);
        fn_801e8a88(lbl_803683c8, lbl_803eb160, lbl_80368328, (void *)fn_802552a8, 2, (void *)fn_80255418);
        fn_801e8a88(lbl_80368418, lbl_803eb17c, lbl_80368378, (void *)fn_80255504, 2, (void *)fn_80255850);
        fn_801e8a88(lbl_80368468, lbl_803eb198, lbl_803682d8, (void *)fn_80255d30, 2, (void *)fn_80256158);
        fn_801e8a88(lbl_803684b8, lbl_803eb1b4, lbl_803682d8, (void *)fn_80256890, 2, (void *)fn_80256b3c);
        fn_801e8a88(lbl_80368508, lbl_803eb1d0, lbl_80365788, (void *)fn_80256f00, 2, (void *)fn_80257110);
        fn_801e8a88(lbl_80368558, lbl_803eb1ec, lbl_80365788, (void *)fn_8025747c, 2, (void *)fn_8025768c);
    }
}

