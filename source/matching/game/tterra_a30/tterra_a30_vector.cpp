struct Vec3 {
    float x, y, z;
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    void add(const Vec3 &v) { x += v.x; y += v.y; z += v.z; }
};
struct Vec4 { float x, y, z, w; };
struct Object { char pad[20]; Vec4 v; };
struct Owner { char pad[4]; Object *object; };
struct Global { char pad[104]; Vec3 delta; };
extern Global *lbl_804b17e0 __attribute__((section(".sdata")));
extern "C" void tterra_a30_vector_800b3d78(Owner *owner)
{
    Object *object = owner->object;
    Vec3 v(object->v.x, object->v.y, object->v.z);
    v.add(lbl_804b17e0->delta);
    Vec4 result = {v.x, v.y, v.z, object->v.w};
    object->v = result;
}
