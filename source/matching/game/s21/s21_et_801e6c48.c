// desc: Appears to report whether a stream handle is already playing: it logs and returns one when more than five streams are active, else returns one when the handle is in the global table, otherwise zero.
extern unsigned lbl_804ab874;
extern int lbl_803ffe34[];
extern const char lbl_803b0804[];
extern int fn_802fb7ac(const char *, ...);
int w3d_s21_is_playing_801e6c48(int unused, int handle)
{
    if (lbl_804ab874 > 5) {
        fn_802fb7ac(lbl_803b0804, lbl_804ab874);
        return 1;
    }
    if (handle != -1) {
        unsigned i = 0;
        int *entry;
        if (i < lbl_804ab874) {
            entry = lbl_803ffe34;
            do {
                if (*entry++ == handle)
                    return 1;
                i++;
            } while (i < lbl_804ab874);
        }
    }
    return 0;
}
