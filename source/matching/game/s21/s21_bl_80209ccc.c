// desc: Appears to construct an object holding a global handle value, then notify a helper with it and return the object.
struct S21Object { int handle; int second; };
extern int lbl_804ab9ec;
extern void fn_80209e08(struct S21Object *, int);
struct S21Object *w3d_s21_construct_80209ccc(struct S21Object *self)
{
    int handle = lbl_804ab9ec;
    self->second = 0;
    self->handle = handle;
    fn_80209e08(self, handle);
    return self;
}
