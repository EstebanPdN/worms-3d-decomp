// desc: Appears to finish an object: it runs a cleanup helper and, when a check succeeds, closes its stream handle through the global stream and returns one, else zero.
struct S21Object { char pad[56]; int stream; };
extern int fn_801e5fd4(struct S21Object *);
extern void fn_801e6bbc(struct S21Object *);
extern void fn_801e45f0(int, int);
extern int lbl_804ab85c;
int w3d_s21_finish_801e65a0(struct S21Object *self)
{
    int result;
    if (fn_801e5fd4(self)) {
        fn_801e6bbc(self);
        fn_801e45f0(lbl_804ab85c, self->stream);
        result = 1;
    } else {
        fn_801e6bbc(self);
        result = 0;
    }
    return result;
}
