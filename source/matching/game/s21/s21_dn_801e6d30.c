// desc: Appears to remove a handle from a global table by swapping the last entry into its slot, shrinking the count and marking the freed slot with minus one.
extern unsigned lbl_804ab874;
extern int lbl_803ffe34[];
void w3d_s21_remove_handle_801e6d30(int unused, int handle)
{
    unsigned i;
    int index;
    unsigned last;
    if (handle == -1)
        return;
    index = -1;
    for (i = 0; i < lbl_804ab874; i++) {
        if (lbl_803ffe34[i] == handle) {
            index = i;
            break;
        }
    }
    if (index <= -1)
        return;
    last = lbl_804ab874 - 1;
    lbl_804ab874 = last;
    lbl_803ffe34[index] = lbl_803ffe34[last];
    lbl_803ffe34[last] = -1;
}
