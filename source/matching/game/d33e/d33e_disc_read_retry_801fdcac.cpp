// (Worms 3D GameCube PAL, 0x801fdcac).
//
// Starts an async disc read with priority 2 and polls until the completion
// callback sets the shared result. Cancels and restarts the read when the
// hold check reports a timeout; returns 0 on success, or E_FAIL after
// logging a read error.

extern int lbl_804ab93c;
extern char lbl_803b1dd8[];
extern char lbl_803b1dfc[];
extern "C" void fn_801fdb98(int, void *);
extern "C" int fn_802f5568(int, void *, unsigned, unsigned, void (*)(int, void *), int);
extern "C" void fn_802fb7ac(const char *, ...);
extern "C" int fn_802f7a68(int);
struct Disc;
extern "C" void tsonnet_c33_poll_dispatch_801fdbec(Disc *, int);
extern "C" int w3d_k10b_hold_timeout_801fddac(Disc *, int);
extern "C" int w3d_d33e_disc_read_retry_801fdcac(Disc *self, int file, void *buf, unsigned size, unsigned off)
{
    lbl_804ab93c = 0;
    fn_802f5568(file, buf, size, off, fn_801fdb98, 2);
    for (;;) {
        tsonnet_c33_poll_dispatch_801fdbec(self, 1);
        int r = w3d_k10b_hold_timeout_801fddac(self, file);
        if (r == 0) {
            fn_802fb7ac(lbl_803b1dd8);
            fn_802f7a68(file);
            lbl_804ab93c = r;
            fn_802f5568(file, buf, size, off, fn_801fdb98, 2);
        }
        switch (lbl_804ab93c) {
        case 0: break;
        case 1: return 0;
        case -1:
            fn_802fb7ac(lbl_803b1dfc);
            return 0x80004005;
        }
    }
}
