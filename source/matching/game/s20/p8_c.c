extern int fn_802DCF90(void *, int, int);
extern void fn_802CE3D4(void *, int);
extern int fn_802CDBD0(void *, int, int);
extern void fn_802DCD3C(void *, int, void *);
extern void fn_802CD808(void *, int);
extern void fn_802CDE08(void *, int);
extern char lbl_803A9980[];
void w3d_s20_p_8019e68c(void *L, int idx) {
    fn_802DCF90(L, idx, 7);
    fn_802CE3D4(L, idx);
    if (!fn_802CDBD0(L, -0x2712, -1))
        fn_802DCD3C(L, idx, lbl_803A9980);
    fn_802CD808(L, -2);
    fn_802CDE08(L, idx);
}
