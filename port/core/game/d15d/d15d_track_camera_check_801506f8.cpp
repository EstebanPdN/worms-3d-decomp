#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "d15d_track_camera_check_801506f8.c"
/* Track-camera range check recovered from 0x801506f8 (SN ProDG GCC 2.95). Layouts are partial observed views. */
typedef struct S3Vec { float x, y, z; } S3Vec;
typedef struct S3VecLocal { S3Vec value; int unused; } S3VecLocal;
typedef struct S3Interface S3Interface;
typedef struct S3Vtable {
    Ptr32<void (void)> unused0; Ptr32<void (void)> unused1; Ptr32<void (void)> unused2;
    Ptr32<void (Ptr32<S3Interface>)> retain;
    Ptr32<void (Ptr32<S3Interface>)> release;
} S3Vtable;
struct S3Interface { Ptr32<S3Vtable> vtable; };
typedef struct S3Actor S3Actor;
typedef struct S3View { int unused; S3Vec position; } S3View;
typedef struct S3Scene { unsigned char pad00[312]; unsigned int view_index; Ptr32<Ptr32<S3View>> views; } S3Scene;
typedef struct S3Camera { unsigned char pad00[48]; float range; } S3Camera;
extern Ptr32<S3Scene> w3d_scene_804aa8c8;
extern const char w3d_str_803a1800[];
extern void w3d_actor_camera_target_position(Ptr32<S3Actor>, Ptr32<S3Vec>);
extern Ptr32<void> w3d_constructor_lookup_name(Ptr32<Ptr32<const char>>, Ptr32<Ptr32<S3Interface>>);
extern Ptr32<S3Camera> w3d_auto_801797b4(Ptr32<S3Interface>);
extern Ptr32<S3Interface> w3d_empty_80341584(Ptr32<S3Interface>);
extern int w3d_fn_80035b50(Ptr32<S3Scene>, Ptr32<S3Vec>), w3d_fn_80121330(Ptr32<S3Vec>);
extern float w3d_fn_802e82c0(float);
extern void w3d_fn_80150828(Ptr32<S3Actor>);

static __inline__ float s3_vec_distance_squared(Ptr32<const S3Vec> a, Ptr32<const S3Vec> b)
{
    float x = a->x-b->x, y = a->y-b->y, z = a->z-b->z;
    return x*x + y*y + z*z;
}

void d15d_actor_check_track_camera_801506f8(Ptr32<S3Actor> self)
{
    Ptr32<S3Scene> scene = w3d_scene_804aa8c8;
    if (scene) {
        S3VecLocal position;
        struct { Ptr32<S3Interface> object; int unused; Ptr32<const char> key; } local;
        Ptr32<S3Camera> camera;
        int first, second, outside, change;
        float length;
        w3d_actor_camera_target_position(self, &position.value);
        local.object = 0;
        local.key = w3d_str_803a1800;
        w3d_constructor_lookup_name(&local.key, &local.object);
        camera = w3d_auto_801797b4(w3d_empty_80341584(local.object));
        first = w3d_fn_80035b50(scene, &position.value);
        second = w3d_fn_80121330(&position.value);
        { Ptr32<S3View> view = *(Ptr32<Ptr32<S3View>>)((Ptr32<char>)scene->views + (scene->view_index << 2));
          length = w3d_fn_802e82c0(s3_vec_distance_squared(&position.value, &view->position)); }
        outside = length > camera->range;
        change = 0;
        if (!first || !second || outside) change = 1;
        if (change) w3d_fn_80150828(self);
        if (local.object) local.object->vtable->release(local.object);
    }
}

}
