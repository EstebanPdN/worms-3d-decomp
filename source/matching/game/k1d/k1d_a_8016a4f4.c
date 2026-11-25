struct K1dEvent { char pad[24]; int flag; };
extern volatile unsigned char lbl_804ab520;
extern int lbl_804ab51c;
extern void fn_8030ba64(int, int, int);
int w3d_k1d_forward_flag_8016a4f4(void *self, struct K1dEvent *ev)
{
    int v;
    if (ev->flag)
    {
        v = 1;
        lbl_804ab520 = v;
    }
    {
        int h = lbl_804ab51c;
        fn_8030ba64(1, h, lbl_804ab520);
    }
    return 0;
}
// k1d: w3d_k1d_forward_flag_8016a4f4|0x8016a4f4|Appears to store whether an event flag is set into a global byte and forward it with a global handle to a callee, returning zero.
