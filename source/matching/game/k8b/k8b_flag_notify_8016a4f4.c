extern int fn_8030ba64(int, int, int);
extern volatile unsigned char lbl_804ab520;
extern int lbl_804ab51c;

int w3d_k8b_flag_notify_8016a4f4(char *self, char *item)
{
    int flag = *(int *)(item + 24);
    int handle;
    int mode;
    if (flag != 0)
        flag = 1;
    lbl_804ab520 = flag;
    handle = lbl_804ab51c;
    mode = 1;
    fn_8030ba64(mode, handle, (unsigned char)lbl_804ab520);
    return 0;
}
