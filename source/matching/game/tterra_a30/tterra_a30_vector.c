typedef struct { float x, y, z; } Vec3;
typedef struct { float x, y, z, w; } Vec4;
typedef struct { char pad[20]; Vec4 v; } Object;
typedef struct { char pad[4]; Object *object; } Owner;
typedef struct { char pad[104]; Vec3 delta; } Global;
extern Global *lbl_804b17e0 __attribute__((section(".sdata")));

void tterra_a30_vector_800b3d78(Owner *owner)
{
    Object *object = owner->object;
    Vec3 v;
    Vec3 *delta = &lbl_804b17e0->delta;
    Vec4 result;
    v.x = object->v.x;
    v.y = object->v.y;
    v.z = object->v.z;
    v.x += delta->x;
    v.y += delta->y;
    v.z += delta->z;
    result.x = v.x;
    result.y = v.y;
    result.z = v.z;
    result.w = object->v.w;
    object->v = result;
}
