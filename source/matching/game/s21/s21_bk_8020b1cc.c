// desc: Appears to be a static destruction entry that installs a vtable pointer in a global object and destroys its embedded node.
struct S21Global { void *vtable; char node[4]; };
extern struct S21Global lbl_804632e8[];
extern char lbl_804181c0[];
extern void fn_80210990(void *, int);
void w3d_s21_destroy_global_8020b1cc(void)
{
    lbl_804632e8[0].vtable = lbl_804181c0;
    fn_80210990(lbl_804632e8[0].node, 0);
}
