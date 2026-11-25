#include "w3d_ptr.h"
#line 1 "d25i_camera_construct_8011f900.cpp"
// d25i: 0x8011f900. Camera constructor: base 0x8015a6b8, posts eight string
// messages (worm aiming, roping, girder, flying, fire, moving and camera
// select), copies the eye, target and up vectors from the arguments, resolves
// Camera.Data and the two task ids, reads the definition category, checks the
// entity task's type against 0x80360e10 and calls the camera update.
struct Vec3 { int x, y, z; };
struct Key { Ptr32<const char> name; };
struct Type { unsigned char unknown00[20]; Ptr32<const Type> parent; };
struct Task;
struct TaskVtable {
    Ptr32<void> unknown00[5];
    Ptr32<Ptr32<const Type> (Ptr32<Task>)> type;     // +20
};
struct Task { Ptr32<TaskVtable> vtable; };
struct Message;
struct Definition { unsigned char unknown00[24]; int category; };
struct CameraArgs {
    unsigned char unknown00[4];
    Vec3 eye;                        // +4
    Vec3 target;                     // +16
    Vec3 up;                         // +28
};
struct Camera {
    unsigned char unknown00[4];
    Vec3 eye;                        // +4
    Vec3 target;                     // +16
    Vec3 up;                         // +28
    unsigned char unknown28[36];
    int entity_task;                 // +76
    int graphic_task;                // +80
    int category;                    // +84
    Ptr32<void> data;                      // +88
    int state;                       // +92
    Vec3 a;                          // +96
    Vec3 b;                          // +108
    Vec3 c;                          // +120
    Vec3 d;                          // +132
    unsigned char unknown90[24];
    int value168;                    // +168
    int outside;                     // +172
    int value176;                    // +176
};
extern "C" void base_8015a6b8(Ptr32<Camera>, Ptr32<CameraArgs>);
extern "C" Ptr32<Message> arena_alloc_801613f0(Ptr32<void>, int);
extern "C" int cached_id_8015f5a0(Ptr32<void>, int);
extern "C" Ptr32<Message> message_init_8010a8e0(Ptr32<Message>, unsigned short, Ptr32<const char>);
extern "C" int message_post_8016239c(Ptr32<Message>);
extern "C" int read_key_800fc2b0(Ptr32<Key>, Ptr32<Key>);
extern "C" int read_setting_800fc1b0(Ptr32<Key>, Ptr32<void>);
extern "C" int read_task_800fc230(Ptr32<Key>, Ptr32<int>);
extern "C" Ptr32<void> as_definition_80341584(Ptr32<void>);
extern "C" Ptr32<Definition> definition_801797b4(Ptr32<void>);
extern "C" Ptr32<Task> find_task_80164fc8(int);
extern "C" void camera_update_80120648(Ptr32<Camera>, Ptr32<Vec3>, Ptr32<Vec3>, Ptr32<Vec3>, Ptr32<Vec3>);
extern Ptr32<void> arena_804b1754;
extern char cache_804af4b4, cache_804af4bc;
extern const Type type_80360e10[];
extern const char n_8039b5f0[], n_8039b608[], n_8039b614[], n_8039b620[], n_8039b630[], n_8039b638[], n_8039b640[], n_8039b64c[], n_8039b65c[], n_8039b668[], n_8039b680[];

inline bool is_a(Ptr32<const Type> t, Ptr32<const Type> target) {
    while (t != target) {
        if (t == t->parent) return false;
        t = t->parent;
    }
    return true;
}
extern "C" void d25i_camera_construct_8011f900(Ptr32<Camera> self, Ptr32<CameraArgs> args) {
    base_8015a6b8(self, args);
    {
        Ptr32<Message> m = arena_alloc_801613f0(arena_804b1754, 12);
        message_post_8016239c(message_init_8010a8e0(m, cached_id_8015f5a0(&cache_804af4b4, 1), n_8039b5f0));
    }
    {
        Ptr32<Message> m = arena_alloc_801613f0(arena_804b1754, 12);
        message_post_8016239c(message_init_8010a8e0(m, cached_id_8015f5a0(&cache_804af4b4, 1), n_8039b608));
    }
    {
        Ptr32<Message> m = arena_alloc_801613f0(arena_804b1754, 12);
        message_post_8016239c(message_init_8010a8e0(m, cached_id_8015f5a0(&cache_804af4b4, 1), n_8039b614));
    }
    {
        Ptr32<Message> m = arena_alloc_801613f0(arena_804b1754, 12);
        message_post_8016239c(message_init_8010a8e0(m, cached_id_8015f5a0(&cache_804af4b4, 1), n_8039b620));
    }
    {
        Ptr32<Message> m = arena_alloc_801613f0(arena_804b1754, 12);
        message_post_8016239c(message_init_8010a8e0(m, cached_id_8015f5a0(&cache_804af4b4, 1), n_8039b630));
    }
    {
        Ptr32<Message> m = arena_alloc_801613f0(arena_804b1754, 12);
        message_post_8016239c(message_init_8010a8e0(m, cached_id_8015f5a0(&cache_804af4bc, 1), n_8039b638));
    }
    {
        Ptr32<Message> m = arena_alloc_801613f0(arena_804b1754, 12);
        message_post_8016239c(message_init_8010a8e0(m, cached_id_8015f5a0(&cache_804af4bc, 1), n_8039b640));
    }
    {
        Ptr32<Message> m = arena_alloc_801613f0(arena_804b1754, 12);
        message_post_8016239c(message_init_8010a8e0(m, cached_id_8015f5a0(&cache_804af4bc, 1), n_8039b64c));
    }
    self->eye = args->eye;
    self->target = args->target;
    self->up = args->up;
    Key data_name;
    Key name;
    name.name = n_8039b65c;
    read_key_800fc2b0(&name, &data_name);
    read_setting_800fc1b0(&data_name, &self->data);
    Key entity;
    entity.name = n_8039b668;
    read_task_800fc230(&entity, &self->entity_task);
    Key graphic;
    graphic.name = n_8039b680;
    read_task_800fc230(&graphic, &self->graphic_task);
    self->category = definition_801797b4(as_definition_80341584(self->data))->category;
    self->state = -1;
    self->value176 = 0;
    self->value168 = 0;
    Ptr32<Task> task = find_task_80164fc8(self->entity_task);
    if (task && is_a(task->vtable->type(task), type_80360e10))
        self->outside = 0;
    else
        self->outside = 1;
    camera_update_80120648(self, &self->a, &self->c, &self->b, &self->d);
}


