extern char *lbl_8045ce40[];
int w3d_s20_clear_flag_for_kind_801a2324(char *self, char *item) {
    unsigned int word = *(unsigned int *)(item + 32);
    if (((word >> 16) & 15) == 3)
        ((char *)lbl_8045ce40[0])[word >> 22] = 0;
    return 0;
}
