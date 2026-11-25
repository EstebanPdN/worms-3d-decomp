// desc: Appears to install a vtable pointer, clear a global singleton pointer and forward to the base destructor helper.
struct S21Object { void *vtable; };
extern char lbl_804197d8[];
extern int lbl_804abaa4;
extern int fn_8021837c(struct S21Object *, void *);
int w3d_s21_destroy_802182cc(struct S21Object *self, void * arg_r4)
{
    self->vtable = lbl_804197d8;
    lbl_804abaa4 = 0;
    return fn_8021837c(self, arg_r4);
}
