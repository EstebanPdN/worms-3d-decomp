// desc: Appears to be a static initialization entry that clears five global tables of sixteen entries and a counter when called with the final priority.
struct S21Record { int a; int b; int c; int d; };
extern int lbl_804b10b0;
extern int lbl_80473724[];
extern int lbl_80473764[];
extern struct S21Record lbl_804737a4[];
extern int lbl_804738a4[];
extern int lbl_804738e4[];
void w3d_s21_static_clear_tables_802cd308(int initialize, int priority)
{
    int i;
    if (priority == 0xffff && initialize) {
        lbl_804b10b0 = 0;
        for (i = 0; i < 16; i++)
            lbl_80473724[i] = 0;
        for (i = 0; i < 16; i++)
            lbl_80473764[i] = 0;
        for (i = 0; i < 16; i++) {
            lbl_804737a4[i].a = 0;
            lbl_804737a4[i].b = 0;
            lbl_804737a4[i].d = 0;
        }
        for (i = 0; i < 16; i++)
            lbl_804738a4[i] = 0;
        for (i = 0; i < 16; i++)
            lbl_804738e4[i] = 0;
    }
}
