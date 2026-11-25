struct S21Inner { char pad[24]; int value; };
struct S21Outer { char pad[36]; struct S21Inner *inner; };
extern void fn_8021bffc(void *, void *);
void w3d_s21_forward_inner_8021bf14(struct S21Outer *self)
{
    fn_8021bffc(self, self->inner->value);
}
