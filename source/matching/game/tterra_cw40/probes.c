/* Reference-only matching scaffolding: wrapper arguments and return types are
   unverified; the unused volatile stack reservation reproduces the PPC frame.
   Do not treat these provisional C signatures as portable interfaces. */
typedef unsigned int u32;
extern void fn_803345bc(int, void *); extern void fn_803345f0(int, void *); extern void fn_80334840(void);
extern void fn_8033dcf0(int, int, void *); extern void fn_8033de40(int); extern int fn_80335440(void *); extern void fn_80335580(void *); extern void fn_80334f84(void); extern void fn_80334c80(void);
extern int fn_802fdb6c(void); extern int fn_802fdb80(void);
void tterra_cw40_wrap_80322ce0(void * arg_r3, void * arg_r4){volatile char pad[8]; fn_803345bc(arg_r3, arg_r4);}
void tterra_cw40_wrap_80322d00(void * arg_r3, void * arg_r4){volatile char pad[8]; fn_803345f0(arg_r3, arg_r4);}
void tterra_cw40_wrap_80328694(void){volatile char pad[8]; fn_80334840();}
void tterra_cw40_wrap_8033457c(void * arg_r3, void * arg_r4, void * arg_r5){volatile char pad[8]; fn_8033dcf0(arg_r3, arg_r4, arg_r5);}
void tterra_cw40_wrap_8033459c(void * arg_r3){volatile char pad[8]; fn_8033de40(arg_r3);}
void tterra_cw40_wrap_80334758(void * arg_r3){volatile char pad[8]; fn_80335440(arg_r3);}
void tterra_cw40_wrap_80334778(void * arg_r3){volatile char pad[8]; fn_80335580(arg_r3);}
void tterra_cw40_wrap_80334840(void){volatile char pad[8]; fn_80334f84();}
void tterra_cw40_wrap_80334978(void){volatile char pad[8]; fn_80334c80();}
void tterra_cw40_wrap_80335b30(void){volatile char pad[8]; fn_802fdb6c();}
void tterra_cw40_wrap_80335b50(void){volatile char pad[8]; fn_802fdb80();}
extern u32 lbl_804b1690,lbl_804b1680;
void tterra_cw40_flags_80335720(void){lbl_804b1680=1;lbl_804b1690=1;}
