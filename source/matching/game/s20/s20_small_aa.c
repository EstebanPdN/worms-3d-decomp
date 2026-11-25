/* Guarded global forwards, float forwarding and a virtual toggle. */
extern int fn_800fdcf4(void *, int, int, int, int, int, int);
extern void *lbl_804aaf64;

int w3d_s20_forward_global6_800fdc80(int a, int b, int c, int d, int e, int f) {
    if (lbl_804aaf64 == 0)
        return 0x80004005;
    return fn_800fdcf4(lbl_804aaf64, a, b, c, d, e, f);
}
