extern void fn_8030ba64(int, int, int);
extern volatile unsigned char lbl_804ab520;
extern int lbl_804ab51c;
int w3d_s20_store_flag_and_notify_8016a4f4(char *self, char *item) {
    int flag = *(int *)(item + 24);
    if (flag != 0)
        flag = 1;
    lbl_804ab520 = flag;
    fn_8030ba64(1, lbl_804ab51c, (unsigned char)lbl_804ab520);
    return 0;
}

