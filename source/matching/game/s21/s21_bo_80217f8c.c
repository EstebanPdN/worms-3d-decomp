// desc: Appears to install a new global handler pointer, fill three callback slots in a hook table and return the previous handler.
extern void *lbl_804aba90;
extern int lbl_80400768[];
extern int fn_80217c6c(void *, void *, int);
extern int fn_80217cd4(int, void *);
extern void fn_80217dac(void *, void *, void *, void *);
void *w3d_s21_install_hooks_80217f8c(void *handler)
{
    void *previous = lbl_804aba90;
    lbl_804aba90 = handler;
    lbl_80400768[3] = (int)fn_80217c6c;
    lbl_80400768[4] = (int)fn_80217cd4;
    lbl_80400768[5] = (int)fn_80217dac;
    return previous;
}
