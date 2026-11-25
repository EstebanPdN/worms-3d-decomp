// desc: Appears to report whether a flag in a sixteen-entry table is set when the subsystem is enabled.
extern int lbl_804abce4;
extern int lbl_80473724[];
int w3d_s21_flag_is_set_802ccb00(unsigned index)
{
    if (!lbl_804abce4 || index > 15)
        return 0;
    return *(int *)((index << 2) + (char *)lbl_80473724) != 0;
}
