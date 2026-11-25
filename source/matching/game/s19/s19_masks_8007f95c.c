extern unsigned lbl_804addec;
extern unsigned lbl_804addf0;
extern unsigned lbl_804addf4;
extern unsigned lbl_804addfc;
extern unsigned lbl_804adb20;
extern unsigned lbl_804adb24;

void s19_build_masks_8007f95c(void)
{
    unsigned a = lbl_804addec;
    lbl_804adb20 = 0;
    lbl_804adb24 = 0;
    if (!(a & 1))
        lbl_804adb20 = 325;
    if (!(a & 64))
        lbl_804adb24 = 2565;
    if (!(lbl_804addf4 & 16)) {
        lbl_804adb24 |= 0x8140;
        lbl_804adb24 |= 0x20000;
    }
    if (!(a & 32))
        lbl_804adb24 |= 0x8241;
    if (!(lbl_804addf0 & 16)) {
        lbl_804adb24 |= 0x904;
        lbl_804adb24 |= 0x20000;
    }
    if (!(lbl_804addfc & 16)) {
        lbl_804adb20 |= 0x8a00;
        lbl_804adb20 |= 0x20000;
    }
    lbl_804adb20 |= lbl_804adb24;
}
