// desc: Appears to register a stream handle: it appends a valid handle to the global table unless more than five streams are active, in which case it logs the count.
extern unsigned lbl_804ab874;
extern int lbl_803ffe34[];
extern const char lbl_803b0824[];
extern int fn_802fb7ac(const char *, ...);
void w3d_s21_register_stream_801e6cd0(int unused, int handle)
{
    if (handle != -1) {
        unsigned count = lbl_804ab874;
        if (count > 5) {
            fn_802fb7ac(lbl_803b0824, count);
            return;
        }
        lbl_803ffe34[count] = handle;
        lbl_804ab874 = count + 1;
    }
}
