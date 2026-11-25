// desc: Appears to call virtual slot 7 of the object with its four arguments and a trailing one.
struct S21Object;
struct S21Methods { void (*reserved[7])(void); int (*convert)(struct S21Object *, int, int, int, int, int); };
struct S21Object { struct S21Methods *methods; };
int w3d_s21_forward_flagged_8020e1f0(struct S21Object *self, int a, int b, int c, int d)
{
    return self->methods->convert(self, a, b, c, d, 1);
}
