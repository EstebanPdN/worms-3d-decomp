struct S21Inner { char pad[24]; int value; };
struct S21Outer { char pad[36]; struct S21Inner *inner; };
extern int fn_8021e930(void *, int);
void w3d_s21_forward_inner_8021bfd4(struct S21Outer *self, int arg)
{
    fn_8021e930(self->inner->value, arg);
}
