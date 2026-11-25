#include "w3d_ptr.h"
#line 1 "d24g_efmv_borders_update_80062ea0.cpp"
/* Worms 3D GameCube PAL 0x80062ea0. EFMV border bars update: computes the remaining fraction of the on-time; when closing, either finishes (releases the mesh and ends) or places the two sprites at the fraction of the height; when opening, places them at one minus the fraction and, once past the end time, posts one finished message. Field and type names are inferred from the original instructions; strings and globals are external views of original data. */
struct Object;
struct ObjectVtable { Ptr32<void> u[4]; Ptr32<void (Ptr32<Object>)> release; };
struct Object { Ptr32<ObjectVtable> vtable; };
struct Vec2 { float x, y; Vec2() {} };
struct MessageCache { unsigned short id; unsigned char unknown[6]; };
struct Message { unsigned short id; Ptr32<const void> vtable; };
struct Borders {
    char u0[32];
    int closing;
    int done;
    Ptr32<Object> mesh;
    Ptr32<Object> height;
    char u48[8];
    unsigned endTime;
    int duration;
    float x;
    float u68;
    float base;
};
extern "C" float value_80178df0(Ptr32<Object>);
extern "C" Ptr32<Vec2> mesh_a_8018963c(Ptr32<Object>);
extern "C" void end_8015fd1c(Ptr32<Borders>);
extern "C" int message_id_8015f5a0(Ptr32<MessageCache>, int);
extern "C" Ptr32<void> arena_alloc_801613f0(Ptr32<void>, int);
extern "C" int message_post_8016239c(Ptr32<void>);
extern Ptr32<void> arena_804b1754;
extern char vt_8040db38[];
extern MessageCache c_804ad530;
extern float zero_80379b14[];
extern "C" int w3d_d24g_efmv_borders_update_80062ea0(Ptr32<Borders> self, unsigned time)
{
    float t = zero_80379b14[0];
    if (time < self->endTime)
        t = (float)(self->endTime - time) / (float)self->duration;
    if (self->closing) {
        if (time >= self->endTime) {
            if (self->mesh) self->mesh->vtable->release(self->mesh);
            self->mesh = 0;
            end_8015fd1c(self);
        } else {
            Vec2 p;
            float h = value_80178df0(self->height);
            p.x = self->x;
            p.y = h * t + self->base;
            Ptr32<Vec2> a = mesh_a_8018963c(self->mesh);
            a[0] = p;
            a[1] = p;
        }
    } else {
        Vec2 p;
        float h = value_80178df0(self->height);
        p.x = self->x;
        p.y = h * (1.0f - t) + self->base;
        Ptr32<Vec2> a = mesh_a_8018963c(self->mesh);
        a[0] = p;
        a[1] = p;
        if (!self->done && time > self->endTime) {
            self->done = 1;
            Ptr32<Message> m = (Ptr32<Message>)arena_alloc_801613f0(arena_804b1754, 8);
            m->id = message_id_8015f5a0(&c_804ad530, 1);
            m->vtable = vt_8040db38;
            message_post_8016239c(m);
        }
    }
    return 0;
}


