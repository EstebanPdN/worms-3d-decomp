struct S10Vector3 {
    float x, y, z;
    S10Vector3(float a, float b, float c) : x(a), y(b), z(c) {}
};
struct S10VectorBinding { char reserved[8]; S10Vector3 value; };
extern "C" S10VectorBinding *fn_801f0504(void *, const char *);
extern "C" void fn_801e8d9c(void *);
extern char lbl_803ab9f8[], lbl_803aba28[];
extern const float lbl_803aba4c[];
extern "C" int w3d_s10_reset_vector_properties_801bce74(void *object)
{
    S10VectorBinding *first = fn_801f0504(object, lbl_803ab9f8);
    float value = lbl_803aba4c[0];
    S10Vector3 a(value, value, value);
    first->value = a;
    S10VectorBinding *second = fn_801f0504(object, lbl_803aba28);
    S10Vector3 b(value, value, value);
    second->value = b;
    fn_801e8d9c(object);
    return 0;
}
