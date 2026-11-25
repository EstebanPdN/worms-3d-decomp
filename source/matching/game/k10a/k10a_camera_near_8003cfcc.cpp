// Appears to test whether the camera is within 50 units (squared distance
// below 2500) of the worm record referenced by an object; true when no record.
struct K10aVec3
{
    float x, y, z;
    K10aVec3() {}
    void set(const float *p) { x = p[0]; y = p[1]; z = p[2]; }
};

struct K10aMatrix4
{
    float m[16];
};

struct K10aCamera;
struct K10aCameraTable
{
    void (*unused[6])();
    void *(*transform)(K10aCamera *camera);   // +24
};
struct K10aCamera
{
    K10aCameraTable *vtable;
};

struct K10aEnvironment
{
    char pad0[48];
    K10aCamera *camera;       // +48
};

struct K10aRecord
{
    char pad0[80];
    K10aVec3 position;        // +80
};

struct K10aObject
{
    char pad0[40];
    void *handle;             // +40
};

extern K10aEnvironment *w3d_environment_804b1788;
extern "C" int w3d_fn_801f6c2c(void *out, void *source);
extern "C" int w3d_auto_80178c48(void *handle);
extern "C" K10aRecord *s8_index_query_800fc6dc(int index);

static inline float k10a_distance_squared(const K10aVec3 *a, const K10aVec3 *b)
{
    float dx = a->x - b->x;
    float dy = a->y - b->y;
    float dz = a->z - b->z;
    return dx * dx + dy * dy + dz * dz;
}

extern "C" int w3d_k10a_camera_near_8003cfcc(K10aObject *self)
{
    K10aVec3 camera;
    K10aMatrix4 transform;
    K10aCamera *c = w3d_environment_804b1788->camera;
    w3d_fn_801f6c2c(&transform, c->vtable->transform(c));
    camera.set(&transform.m[12]);
    int index = w3d_auto_80178c48(self->handle);
    if (index == -1)
        return 1;
    K10aRecord *record = s8_index_query_800fc6dc(index);
    return k10a_distance_squared(&record->position, &camera) < 2500.0f;
}
