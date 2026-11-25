extern int lbl_804abce4;
extern int lbl_80403f94[];
extern int fn_802ccb00(unsigned);
int w3d_s21_consume_flag_802ccb40(unsigned index){if (!(lbl_804abce4 && index <= 15 && fn_802ccb00(index) && lbl_80403f94[index])) return 0; lbl_80403f94[index]=0; return 1; }