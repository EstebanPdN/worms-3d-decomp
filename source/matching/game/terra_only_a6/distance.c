typedef struct { float x, y, z; } Vec3;
typedef struct { float v[16]; } Matrix;
typedef struct Camera Camera;
typedef struct { void *slots[6]; const float *(*matrix)(Camera *); } CameraVtable;
struct Camera { CameraVtable *vtable; };
typedef struct { char pad[48]; Camera *camera; } Context;
typedef struct { char pad[40]; void *handle; } Owner;
typedef struct { char pad[80]; Vec3 position; } Item;
extern Context *context_804b1788;
extern int invert_801f6c2c(float *, const float *);
extern int handle_80178c48(void *);
extern Item *item_800fc6dc(int);
extern float threshold_8038092c[];
static inline void copy_point(Vec3 *out, const float *v) { out->x = v[12]; out->y = v[13]; out->z = v[14]; }
static inline float distance_squared(const Vec3 *a, const Vec3 *b) {
    float y = a->y - b->y; float x = a->x - b->x; float z = a->z - b->z;
    return z*z + (x*x + y*y);
}
int terra_only_a6_distance_800a1534(Owner *owner) {
    Vec3 point;
    Matrix matrix;
    int index;
    invert_801f6c2c(matrix.v, context_804b1788->camera->vtable->matrix(context_804b1788->camera));
    copy_point(&point, matrix.v);
    index = handle_80178c48(owner->handle);
    if (index != -1) {
        Item *item = item_800fc6dc(index);
        return distance_squared(&item->position, &point) < threshold_8038092c[0];
    }
    return 1;
}
