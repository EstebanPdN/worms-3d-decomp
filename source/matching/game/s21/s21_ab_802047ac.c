// desc: Appears to forward its two arguments to a virtual slot of the inner stream object with a trailing zero.
struct S21Inner;
struct S21InnerMethods { void (*reserved[6])(void); int (*write)(struct S21Inner *, int, int, int); };
struct S21Inner { struct S21InnerMethods *methods; };
struct S21Wrapper { char pad[20]; struct S21Inner *inner; };
int w3d_s21_forward_write_802047ac(struct S21Wrapper *self, int a, int b)
{
    return self->inner->methods->write(self->inner, a, b, 0);
}
