#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "probes.c"
/* Reference-only matching scaffolding: wrapper arguments and return types are
   unverified; the unused volatile stack reservation reproduces the PPC frame.
   Do not treat these provisional C signatures as portable interfaces. */
typedef unsigned int u32;
extern void fn_803345bc(int, Ptr32<void>); extern void fn_803345f0(int, Ptr32<void>); extern void fn_80334840(void);
extern void fn_8033dcf0(int, int, Ptr32<void>); extern void fn_8033de40(int); extern int fn_80335440(Ptr32<void>); extern void fn_80335580(Ptr32<void>); extern void fn_80334f84(void); extern void fn_80334c80(void);
extern int fn_802fdb6c(void); extern int fn_802fdb80(void);
void tterra_cw40_wrap_80322ce0(Ptr32<void> arg_r3, Ptr32<void> arg_r4){volatile char pad[8]; fn_803345bc(w3d::H(arg_r3), arg_r4);}
void tterra_cw40_wrap_80322d00(Ptr32<void> arg_r3, Ptr32<void> arg_r4){volatile char pad[8]; fn_803345f0(w3d::H(arg_r3), arg_r4);}
void tterra_cw40_wrap_80328694(void){volatile char pad[8]; fn_80334840();}
void tterra_cw40_wrap_8033457c(Ptr32<void> arg_r3, Ptr32<void> arg_r4, Ptr32<void> arg_r5){volatile char pad[8]; fn_8033dcf0(w3d::H(arg_r3), w3d::H(arg_r4), arg_r5);}
void tterra_cw40_wrap_8033459c(Ptr32<void> arg_r3){volatile char pad[8]; fn_8033de40(w3d::H(arg_r3));}
void tterra_cw40_wrap_80334758(Ptr32<void> arg_r3){volatile char pad[8]; fn_80335440(arg_r3);}
void tterra_cw40_wrap_80334778(Ptr32<void> arg_r3){volatile char pad[8]; fn_80335580(arg_r3);}
void tterra_cw40_wrap_80334840(void){volatile char pad[8]; fn_80334f84();}
void tterra_cw40_wrap_80334978(void){volatile char pad[8]; fn_80334c80();}
void tterra_cw40_wrap_80335b30(void){volatile char pad[8]; fn_802fdb6c();}
void tterra_cw40_wrap_80335b50(void){volatile char pad[8]; fn_802fdb80();}
extern u32 lbl_804b1690,lbl_804b1680;
void tterra_cw40_flags_80335720(void){lbl_804b1680=1;lbl_804b1690=1;}

}
