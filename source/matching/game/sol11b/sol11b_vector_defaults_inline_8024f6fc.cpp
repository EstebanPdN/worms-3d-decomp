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
extern const unsigned char descriptor_803c5650[];
extern const unsigned char descriptor_803c567c[];
extern const unsigned char descriptor_803c56a0[];
extern const unsigned char descriptor_803c5628[];
extern const float default_803c56c4[];
}
inline void setDefault(Sol11bVectorBinding *binding, float zero) { Sol11bVector value(zero); binding->value=value; }
extern "C" int sol11b_vector_defaults_inline_8024f6fc(void *object)
{
    fn_801ebf38(object, descriptor_803c5628);
    Sol11bVectorBinding *binding0 = fn_801f0210(object, descriptor_803c5650);
    float zero = default_803c56c4[0];
    setDefault(binding0, zero);
    Sol11bVectorBinding *binding1 = fn_801f0210(object, descriptor_803c567c);
    setDefault(binding1, zero);
    Sol11bVectorBinding *binding2 = fn_801f0210(object, descriptor_803c56a0);
    setDefault(binding2, zero);
    fn_801e8d9c(object);
    return 0;
}
