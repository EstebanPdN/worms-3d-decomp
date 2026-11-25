/* Selects one of three fields of a resolved object by flags and forwards. */
extern int fn_80341584(int);
extern char *fn_801797b4(int);
extern void fn_800ec6a8(char *, char *, int, int);

void w3d_s20_forward_selected_800ed938(char *self, int unused, int a, unsigned int flags, int b, int c, int d) {
    char *resolved = fn_801797b4(fn_80341584(*(int *)(self + 192)));
    int selected;
    unsigned int low_bit;
    unsigned int top_bit;
    low_bit = flags & 1;
    if (low_bit != 0)
        selected = *(int *)(resolved + 468);
    else if ((top_bit = flags & 0x40000000, 0 | top_bit) != 0)
        selected = *(int *)(resolved + 472);
    else
        selected = *(int *)(resolved + 448);
    if (selected != 0)
        fn_800ec6a8(self, self + 36, c, d);
}
