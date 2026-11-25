// desc: Appears to compute a clamped ratio from three float fields of a projection-like object, capping the result at a global limit.
struct S21Object { char pad[36]; float a; char pad1[20]; float b; float c; };
extern float lbl_803d8414[];
float w3d_s21_clamped_ratio_802bfa40(struct S21Object *self)
{
    float ratio = (self->c + self->b) / (self->a + self->a);
    if (ratio > lbl_803d8414[0])
        ratio = lbl_803d8414[0];
    return ratio;
}
