#include "w3d_ptr.h"
#line 1 "d27d_worm_message_bounce_801535cc.cpp"
// GWMP8P rev0 0x801535cc. Handle a contact message: when the sender is a
// listed entity, probe around the raised position and find the object owned
// by the sender. If it lies below, push the worm away from it, add the
// scaled push to the velocity, set falling state 7 and log the bounce for
// logic entity types. If none is found set state 7 and log the fall. Always
// post a target message. Names are inferred; virtual slots are reference-ABI
// observations.
extern "C" float sqrt_802e82c0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
    void unit() { float f = 1.0f / sqrt_802e82c0(lenSq()); x *= f; y *= f; z *= f; }
    Vec &operator+=(const Vec &o) { x += o.x; y += o.y; z += o.z; return *this; }
};
inline Vec operator+(const Vec &a, const Vec &b) { Vec r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }
inline Vec operator-(const Vec &a, const Vec &b) { Vec r; r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; return r; }
inline Vec operator*(const Vec &a, float k) { Vec r; r.x = a.x * k; r.y = a.y * k; r.z = a.z * k; return r; }
struct TypeDesc {
    char pad[20];
    Ptr32<TypeDesc> parent;
    bool is_a(Ptr32<TypeDesc> target) {
        Ptr32<TypeDesc> t = this;
        while (t != target) {
            if (t == t->parent) return false;
            t = t->parent;
        }
        return true;
    }
};
extern TypeDesc type_80361860[];
extern TypeDesc type_803618f0[];
struct Handle { int h; };
struct Object {
    int w3d_r_query_interface() __asm__(W3D_SYM("_ZN6Object15query_interfaceEv"));
    void w3d_r_retain() __asm__(W3D_SYM("_ZN6Object6retainEv"));
    void w3d_r_release() __asm__(W3D_SYM("_ZN6Object7releaseEv"));
    Ptr32<TypeDesc> w3d_r_type() __asm__(W3D_SYM("_ZN6Object4typeEv"));
 __attribute__((always_inline)) inline int query_interface() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Object, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void retain() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Object, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Object, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<TypeDesc> type() { return ((Ptr32<TypeDesc> (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Object, 5))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Object; };
struct Worm : Object {
    char u4[16] __attribute__((aligned(__alignof__(Object)))); int id; char u18[536]; Vec pos; char u23c[104]; Vec vel; char u2b0[28]; int moving; char u2d0[40]; int state; char u2fc[40]; int slot; char u328[336]; Handle handle;
};
struct Message;
struct Target { char u0[24]; int owner; };
extern unsigned short kind_804aa95e;
extern "C" Ptr32<const Target> lookup_8003f240(int);
inline Vec lookupVec() { return *(Ptr32<const Vec>)lookup_8003f240(kind_804aa95e); }
extern "C" int sender_801190d0(Ptr32<Message>);
extern "C" int hasEntity_80153a1c(Ptr32<Worm>, int);
extern "C" void position_801262c0(Ptr32<Handle>, const Vec &);
extern "C" void run_80126334(Ptr32<Handle>);
extern "C" int clock_801264fc(Ptr32<Handle>);
extern "C" void finish_80126524(Ptr32<Handle>);
extern "C" void apply_80153f80(Ptr32<Worm>, const Vec &, const Vec &);
extern "C" int log_80022e20(Ptr32<const char>, Ptr32<const char>, int, Ptr32<int>);
extern const char logic_entity_803a0e2c[];
extern "C" Ptr32<void> alloc_801613f0(Ptr32<void>, int);
extern "C" short msg_id_8015f5a0(Ptr32<void>, int);
extern "C" Ptr32<void> target_message_801190b4(Ptr32<Message>, unsigned short, int);
extern "C" int post_8016239c(Ptr32<void>);
extern Ptr32<void> heap_804b1754;
extern int cache_804afd40;
extern "C" void d27d_worm_message_bounce_801535cc(Ptr32<Worm> self, Ptr32<Message> m) {
    if (!hasEntity_80153a1c(self, sender_801190d0(m))) return;
    Vec p = self->pos;
    p.y += 10.0f;
    position_801262c0(&self->handle, p);
    run_80126334(&self->handle);
    int id = clock_801264fc(&self->handle);
    if (id != 0xffff) do {
        int owner = lookup_8003f240(kind_804aa95e)->owner;
        if (owner == sender_801190d0(m)) {
            Vec t = lookupVec();
            bool below = t.y < p.y;
            if (!below) break;
            Vec d = p - lookupVec();
            d.unit();
            apply_80153f80(self, self->pos, self->pos + d);
            self->vel += d * 0.02f;
            self->state = 7;
            self->moving = 0;
            if (self->type()->is_a(type_80361860) || self->type()->is_a(type_803618f0))
                log_80022e20("Worm Bounce Off Moving Object", logic_entity_803a0e2c, 7012, &self->slot);
            break;
        }
        id = clock_801264fc(&self->handle);
    } while (id != 0xffff);
    finish_80126524(&self->handle);
    if (id == 0xffff) {
        self->state = 7;
        self->moving = 0;
        if (self->type()->is_a(type_80361860) || self->type()->is_a(type_803618f0))
            log_80022e20("Worm Fall Of Object", logic_entity_803a0e2c, 7025, &self->slot);
    }
    Ptr32<void> n = alloc_801613f0(heap_804b1754, 12);
    post_8016239c(target_message_801190b4((Ptr32<Message>)n, msg_id_8015f5a0(&cache_804afd40, 1), self->id));
}


