#include "w3d_ptr.h"
#line 1 "d40i_emitter_activate_801074f0.cpp"
// d40i: 0x801074f0. Particle emitter start: posts the start message, loads
// the mesh, places itself at the camera or at the origin, takes its
// orientation from the camera matrix, expands its bounds and starts every
// particle with a colour from its style. The expand call takes its matrix
// and direction by value, and the loop vector is a function-level local,
// which together give the frame.
struct String {
    Ptr32<char> text;
    String();
    String(const String &);
    ~String();
};
extern "C" void string_finish_8020c5c4(Ptr32<String>);
extern "C" void string_release_80341588(Ptr32<String>);
inline String::~String() {
    string_finish_8020c5c4(this);
    string_release_80341588(this);
}
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(const Vec3 &o) { x = o.x; y = o.y; z = o.z; }
    void set(float a, float b, float c) { x = a; y = b; z = c; }
};
inline Vec3 operator-(const Vec3 &a, const Vec3 &b) { Vec3 r; r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; return r; }
struct Row { float x, y, z, w; };
struct Matrix { Row r[4]; };
struct Mat33 {
    float m[9];
    Mat33() {}
    void From(const Matrix &o) {
        m[0] = o.r[0].x; m[1] = o.r[0].y; m[2] = o.r[0].z;
        m[3] = o.r[1].x; m[4] = o.r[1].y; m[5] = o.r[1].z;
        m[6] = o.r[2].x; m[7] = o.r[2].y; m[8] = o.r[2].z;
    }
};
struct Object;
struct ObjectVtable { Ptr32<void> unknown00[3]; Ptr32<void (Ptr32<Object>)> retain; Ptr32<void (Ptr32<Object>)> release; };
struct Object { Ptr32<ObjectVtable> vtable; };
struct Handle {
    Ptr32<Object> value;
    Handle() : value(0) {}
    ~Handle() { if (value) value->vtable->release(value); }
};
struct Ref {
    Ptr32<Object> value;
    template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((Object *)w3d_p.get()); }
 void operator=(Object *next) {
        if (next) next->vtable->retain(next);
        if (value) value->vtable->release(value);
        value = next;
    }
};
struct Camera;
struct CameraVt { unsigned char unknown00[24]; Ptr32<Ptr32<const Matrix> (Ptr32<Camera>)> matrix; unsigned char unknown1c[28]; Ptr32<Ptr32<const Vec3> (Ptr32<Camera>)> position; Ptr32<Ptr32<const Vec3> (Ptr32<Camera>)> target; };
struct Camera { Ptr32<CameraVt> vt; };
struct Service { unsigned char unknown00[48]; Ptr32<Camera> camera; };
struct Colour { float r, g, b; };
struct Style { unsigned char unknown00[32]; Colour colour; };
struct Inner { unsigned char unknown00[140]; Ptr32<Style> style; unsigned char unknown90[160]; int mode; unsigned char unknown134[28]; int names; };
struct Particle;
struct ParticleLink { unsigned char unknown00[20]; Ptr32<void (Ptr32<Particle>, Ptr32<Vec3>)> moved; };
struct Particle { Vec3 pos; unsigned char unknown0c[100]; Ptr32<ParticleLink> link; };
struct List;
struct ListVt { unsigned char unknown00[20]; Ptr32<Ptr32<Particle> (Ptr32<List>, unsigned int)> at; };
struct List { Ptr32<ListVt> vt; };
struct Spawner { unsigned char unknown00[8]; Ptr32<void (Ptr32<void>, Ptr32<Particle>, int, int)> bind; };
struct Message { unsigned short id; };
struct Posted { unsigned short id; Ptr32<void> vt; };
struct Emitter {
    unsigned char unknown00[20];
    int owner;           // +20
    unsigned char unknown18[4];
    unsigned char sub[4];  // +28
    Ptr32<List> list;          // +32
    unsigned char unknown24[60];
    Vec3 origin;         // +96
    unsigned char unknown6c[32];
    unsigned count;      // +140
    unsigned char unknown90[12];
    Ptr32<Object> table;       // +156
    unsigned char unknowna0[20];
    unsigned flags;      // +180
    unsigned char unknownb8[72];
    Ptr32<Spawner> spawner;    // +256
    Ref mesh;            // +260
    unsigned char unknown108[68];
    Vec3 centre;         // +332
    unsigned char unknown158;
    unsigned char alpha; // +345
    unsigned char unknown15a[14];
    int spawned;         // +360
    int message;         // +364
    int t368, t372, t376;
    float f380;
};
extern Ptr32<Service> service_804b1788;
extern Ptr32<void> arena_804b1754; extern Ptr32<void> spawn_804b178c; extern Ptr32<void> pot_804aaecc;
extern Ptr32<void> vt_8040db38[];
extern int id_804af230, id_804af220;
extern const char class_80410398[];
extern "C" void pot_800e58fc(Ptr32<void>, int);
extern "C" int message_id_8015f5a0(Ptr32<void>, int);
extern "C" int acquire_80162024(Ptr32<Emitter>, Ptr32<Message>, Ptr32<int>);
extern "C" Ptr32<void> as_table_80341584(Ptr32<Object>);
extern "C" Ptr32<Inner> inner_801797b4(Ptr32<void>);
extern "C" int set_name_8015adf4(Ptr32<int>, Ptr32<Handle>, int);
extern "C" Ptr32<Object> cast_8034380c(Ptr32<Object>);
extern "C" Ptr32<Object> create_8020b680(Ptr32<const void>);
extern "C" int spawn_80164514(Ptr32<void>, Ptr32<Object>, int);
extern "C" Ptr32<void> arena_801613f0(Ptr32<void>, int);
extern "C" int post_8016239c(Ptr32<void>);
extern "C" int normalize_801f6c2c(Ptr32<Matrix>, Ptr32<const Matrix>);
extern "C" void expand_80107ccc(Ptr32<Emitter>, Mat33, Vec3);
extern "C" int resize_8018920c(Ptr32<Object>, unsigned);
extern "C" Ptr32<unsigned char> colours_80189760(Ptr32<Object>);
extern "C" Ptr32<unsigned char> flags_80189704(Ptr32<Object>);
extern "C" Ptr32<float> uvs_8018963c(Ptr32<Object>);
struct Context { unsigned char unknown00[52]; int time; };
extern "C" Ptr32<Context> context_80165254();
extern "C" int wrap_80107ab8(Ptr32<Emitter>, Ptr32<Vec3>);
extern "C" void activate_800dca14(Ptr32<Particle>, int);
extern "C" void start_800ddcbc(Ptr32<Particle>, int, Ptr32<float>, Ptr32<Inner>, int, int);
extern "C" void d40i_emitter_activate_801074f0(Ptr32<Emitter> self) {
    Ptr32<unsigned char> flags = 0;
    String name;
    Ptr32<const Vec3> pos = service_804b1788->camera->vt->position(service_804b1788->camera);
    Ptr32<const Vec3> at = service_804b1788->camera->vt->target(service_804b1788->camera);
    Vec3 dir = *at - *pos;
    Vec3 w;
    Ptr32<const Matrix> cam = service_804b1788->camera->vt->matrix(service_804b1788->camera);
    Mat33 current;
    Matrix unit;
    Mat33 rotation;
    pot_800e58fc(pot_804aaecc, 1);
    Message msg;
    msg.id = message_id_8015f5a0(&id_804af230, 1);
    acquire_80162024(self, &msg, &self->message);
    Ptr32<Inner> in = inner_801797b4(as_table_80341584(self->table));
    if (self->flags & 256) {
        {
            Handle h;
            h.value = (Ptr32<Object>)flags;
            set_name_8015adf4(&in->names, &h, 255);
            self->mesh = cast_8034380c(h.value);
        }
        self->centre.set(0.0f, 0.0f, 0.0f);
        self->t368 = 600;
        self->t372 = 600;
        self->t376 = 20;
        self->f380 = 800.0f;
    } else {
        if (in->mode == 2) {
            Ptr32<Object> made = create_8020b680(class_80410398);
            self->spawned = spawn_80164514(spawn_804b178c, made, self->owner);
            Ptr32<Posted> p = (Ptr32<Posted>)arena_801613f0(arena_804b1754, 8);
            p->id = message_id_8015f5a0(&id_804af220, 1);
            p->vt = vt_8040db38;
            post_8016239c(p);
        }
        {
            Handle h;
            h.value = (Ptr32<Object>)flags;
            set_name_8015adf4(&in->names, &h, 255);
            self->mesh = cast_8034380c(h.value);
        }
        self->centre = *pos;
    }
    if (in->mode == 2) self->alpha = 128;
    else self->alpha = 255;
    normalize_801f6c2c(&unit, cam);
    rotation.From(unit);
    current.From(*cam);
    expand_80107ccc(self, current, dir);
    self->origin = self->centre;
    Ptr32<Object> mesh = cast_8034380c(self->mesh.value);
    resize_8018920c(self->mesh.value, self->count);
    Ptr32<unsigned char> colours = colours_80189760(mesh);
    flags = flags_80189704(mesh);
    Ptr32<float> uvs = uvs_8018963c(mesh);
    int time = context_80165254()->time;
    for (unsigned i = 0; i < self->count; i++) {
        Ptr32<Particle> p = self->list->vt->at(self->list, i);
        self->spawner->bind(self->sub, p, time, 1);
        w = p->pos;
        wrap_80107ab8(self, &w);
        p->link->moved(p, &w);
        activate_800dca14(p, 1);
        start_800ddcbc(p, time, &uvs[i * 2], in, 0, 0);
        Ptr32<Colour> c = &in->style->colour;
        colours[0] = (unsigned char)(c->r * 255.0f);
        colours[1] = (unsigned char)(c->g * 255.0f);
        colours[2] = (unsigned char)(c->b * 255.0f);
        colours[3] = self->alpha;
        flags[i] = 1;
        colours += 4;
    }
}


