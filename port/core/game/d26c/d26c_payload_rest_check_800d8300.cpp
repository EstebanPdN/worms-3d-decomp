#include "w3d_ptr.h"
#line 1 "d26c_payload_rest_check_800d8300.cpp"
// d26c: 0x800d8300. ParabolicPayloadLogicEntity (file name from its report call): when at rest, test the rest message and
// leave rest, reporting if the payload type is one of two kinds; when moving, refresh position and velocity. Names are
// inferred. The checks use the same type chain test as other units.
struct Type { unsigned char unknown00[20]; Ptr32<const Type> parent; };
struct Vec3 {
    float x, y, z;
    float lenSq() const { return x * x + y * y + z * z; }
};
struct Message { unsigned short id; };
struct Actor {
    struct V { Ptr32<void> u[5]; Ptr32<Ptr32<const Type> (Ptr32<Actor>)> type; Ptr32<void> u24[5]; Ptr32<void (Ptr32<Actor>, int, Ptr32<Vec3>)> position; Ptr32<void (Ptr32<Actor>, int, Ptr32<Vec3>)> velocity; }; Ptr32<struct V> vtable;
    char u4[32];
    Vec3 pos;
    Vec3 vel;
    Vec3 force;
    char u72[28];
    char name[92];
    Ptr32<void> h192;
    char u196[172];
    int when;
};
struct Context { char u0[52]; int now; };
extern "C" Ptr32<Context> ctx_80165254(void);
extern "C" int id_equals_8015f65c(unsigned, Ptr32<int>);
extern int rest_id_804aeaf8;
extern "C" int may_rest_800d8f8c(Ptr32<Actor>);
extern "C" void leave_800eb6e4(Ptr32<Actor>);
extern "C" void land_800d8b4c(Ptr32<Actor>);
extern "C" Ptr32<void> empty_80341584(Ptr32<void>);
extern "C" Ptr32<void> desc_801797b4(Ptr32<void>);
extern "C" int report_80022e20(Ptr32<const char>, Ptr32<const char>, int, Ptr32<void>);
extern char rest_text_8038923c[], file_80389260[];
extern const Type type_80361860[], type_803618f0[];
inline bool is_a(Ptr32<const Type> t, Ptr32<const Type> target) {
    while (t != target) {
        if (t == t->parent) return false;
        t = t->parent;
    }
    return true;
}
extern "C" void d26c_payload_rest_check_800d8300(Ptr32<Actor> self, Ptr32<Message> m) {
    unsigned short id = m->id;
    int now = ctx_80165254()->now;
    if (self->vel.lenSq() == 0.0f && self->force.lenSq() == 0.0f) {
        if (id_equals_8015f65c(id, &rest_id_804aeaf8) && may_rest_800d8f8c(self)) {
            leave_800eb6e4(self);
            if (is_a(self->vtable->type(self), type_80361860) || is_a(self->vtable->type(self), type_803618f0)) {
                report_80022e20(rest_text_8038923c, file_80389260, 272, self->name);
            }
            self->when = now;
            land_800d8b4c(self);
            desc_801797b4(empty_80341584(self->h192));
        }
    } else {
        self->vtable->position(self, now, &self->pos);
        self->vtable->velocity(self, now, &self->vel);
        self->when = now;
        land_800d8b4c(self);
    }
}


