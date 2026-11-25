// d26c: 0x800d8300. ParabolicPayloadLogicEntity (file name from its report call): when at rest, test the rest message and
// leave rest, reporting if the payload type is one of two kinds; when moving, refresh position and velocity. Names are
// inferred. The checks use the same type chain test as other units.
struct Type { unsigned char unknown00[20]; const Type *parent; };
struct Vec3 {
    float x, y, z;
    float lenSq() const { return x * x + y * y + z * z; }
};
struct Message { unsigned short id; };
struct Actor {
    struct V { void *u[5]; const Type *(*type)(Actor *); void *u24[5]; void (*position)(Actor *, int, Vec3 *); void (*velocity)(Actor *, int, Vec3 *); } *vtable;
    char u4[32];
    Vec3 pos;
    Vec3 vel;
    Vec3 force;
    char u72[28];
    char name[92];
    void *h192;
    char u196[172];
    int when;
};
struct Context { char u0[52]; int now; };
extern "C" Context *ctx_80165254(void);
extern "C" int id_equals_8015f65c(unsigned, int *);
extern int rest_id_804aeaf8;
extern "C" int may_rest_800d8f8c(Actor *);
extern "C" void leave_800eb6e4(Actor *);
extern "C" void land_800d8b4c(Actor *);
extern "C" void *empty_80341584(void *);
extern "C" void *desc_801797b4(void *);
extern "C" int report_80022e20(const char *, const char *, int, void *);
extern char rest_text_8038923c[], file_80389260[];
extern const Type type_80361860[], type_803618f0[];
inline bool is_a(const Type *t, const Type *target) {
    while (t != target) {
        if (t == t->parent) return false;
        t = t->parent;
    }
    return true;
}
extern "C" void d26c_payload_rest_check_800d8300(Actor *self, Message *m) {
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
