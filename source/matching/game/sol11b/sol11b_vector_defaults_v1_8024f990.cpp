// External property binding view: two header words followed by a three-float value.
// The complete binding owner and descriptor types remain external GC ABI objects.
struct Sol11bVector {
    float x, y, z;
    Sol11bVector(float value) { x=value; y=value; z=value; }
};
struct Sol11bVectorBinding { unsigned header[2]; Sol11bVector value; };
extern "C" {
Sol11bVectorBinding *fn_801f0210(void *, const void *);
void fn_801e8d9c(void *);
void *fn_801ebf38(void *, const void *);
void *fn_801eb834(void *, const void *);
extern const unsigned char descriptor_803c56cc[];
extern const unsigned char descriptor_803c56f0[];
extern const unsigned char descriptor_803c5714[];
extern const unsigned char descriptor_803c5740[];
extern const float default_803c5768[];
}
extern "C" int sol11b_vector_defaults_v1_8024f990(void *object)
{
    Sol11bVectorBinding *binding0 = fn_801f0210(object, descriptor_803c56cc);
    float zero = default_803c5768[0];
    Sol11bVector value0(zero);
    binding0->value = value0;
    Sol11bVectorBinding *binding1 = fn_801f0210(object, descriptor_803c56f0);
    Sol11bVector value1(zero);
    binding1->value = value1;
    Sol11bVectorBinding *binding2 = fn_801f0210(object, descriptor_803c5714);
    Sol11bVector value2(zero);
    binding2->value = value2;
    fn_801eb834(object, descriptor_803c5740);
    fn_801e8d9c(object);
    return 0;
}
