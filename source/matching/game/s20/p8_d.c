extern void fn_802DCF90(int, int, int);
extern void fn_802CE3D4(int, int);
extern int fn_802CDBD0(int, int, int);
extern void fn_802DCD3C(int, int, void *);
extern void fn_802CD808(int, int);
extern void fn_802CDE08(int, int);
extern char lbl_803A9980[];
void w3d_s20_p_8019e68c(int L, int idx) {
    fn_802DCF90(L, idx, 7);
    fn_802CE3D4(L, idx);
    if (!fn_802CDBD0(L, -0x2712, -1))
        fn_802DCD3C(L, idx, lbl_803A9980);
    fn_802CD808(L, -2);
    fn_802CDE08(L, idx);
}
