#include "w3d_ptr.h"
#line 1 "d40c_payload_setup_800eb064.cpp"
// d40c: 0x800eb064. Payload object setup: subscribes two messages, reads
// settings, loads effects, builds the motion handle and collects its clock
// ids into an int list. The list element is passed as a converted temporary
// from an int local, which gives the slot at sp+16 and its scalar store.
// Payload start-up.
struct Object;
struct ObjectVtable { Ptr32<void> unknown00[3]; Ptr32<void (Ptr32<Object>)> retain; Ptr32<void (Ptr32<Object>)> release; };
struct Object { Ptr32<ObjectVtable> vtable; };
struct Key { Ptr32<const char> name; };
struct Ref {
    Ptr32<Object> value;
    Ref() { value = 0; }
    Ref(const Ref &);
    ~Ref() { if (value) value->vtable->release(value); }
};
extern "C" int read_setting_800fc1b0(Ptr32<Key>, Ptr32<void>);
extern "C" Ptr32<Object> cast_80342a74(Ptr32<Object>);
static inline void assign(Ptr32<Object> &slot, Ptr32<Object> value) {
    if (value) value->vtable->retain(value);
    if (slot) slot->vtable->release(slot);
    slot = value;
}
static inline void load(Ptr32<Object> &slot, Ptr32<const char> name) {
    Key key;
    key.name = name;
    Ref found;
    read_setting_800fc1b0(&key, &found);
    assign(slot, cast_80342a74(found.value));
}
static inline void setting(Ptr32<const char> name, Ptr32<void> to) {
    Key key;
    key.name = name;
    read_setting_800fc1b0(&key, to);
}
extern "C" Ptr32<void> malloc(unsigned);
extern "C" void release_802134fc(Ptr32<void>);
extern "C" Ptr32<void> copy_802eee50(...);
template <class T> inline const T &maximum(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline const T &minimum(const T &a, const T &b) { return b < a ? b : a; }
typedef unsigned Item;
struct IntList {
    Ptr32<Item> begin; Ptr32<Item> end; Ptr32<Item> capacity;
    void push(const Item &value) {
        if (end == capacity) {
            unsigned old = (Ptr32<char>)end - (Ptr32<char>)begin;
            int one = old + 1, grow = old + (old >> 1);
            unsigned bytes = maximum(one, grow) << 2;
            Ptr32<char> p = (Ptr32<char>)malloc(bytes);
            if (begin) {
                copy_802eee50(w3d::VA(p), w3d::VA(begin), minimum(bytes, old));
                release_802134fc(begin);
            }
            begin = (Ptr32<Item>)p;
            end = (Ptr32<Item>)(p + old);
            capacity = (Ptr32<Item>)(p + bytes);
        }
        *end = value;
        end++;
    }
};
struct Vec3 { float x, y, z; };
struct Handle;
extern "C" Ptr32<void> heap_allocate_802098d8(Ptr32<void>, int);
extern char heap_804af5bc;
inline void *operator new(__SIZE_TYPE__ size) { return heap_allocate_802098d8(&heap_804af5bc, size); }
extern "C" Ptr32<Handle> handle_construct_801261bc(Ptr32<void>, Ptr32<Vec3>, int, int, float);
extern "C" void handle_owner_80126308(Ptr32<Handle>, int);
extern "C" void handle_start_80126384(Ptr32<Handle>, Ptr32<Vec3>, int);
extern "C" int handle_clock_801264fc(Ptr32<Handle>);
extern "C" void handle_finish_80126524(Ptr32<Handle>);
struct Info { char u0[24]; int value; };
extern "C" Ptr32<Info> lookup_8003f240(int);
extern unsigned short kind_804aa95e;
struct Class { char pad[20]; Ptr32<Class> base; };
inline int is_kind(Ptr32<const Class> c, Ptr32<const Class> t) {
    for (; c != t; c = c->base) if (c == c->base) return 0;
    return 1;
}
extern Class class_a_80361860[], class_c_803618f0[];
struct Type { char u0[176]; float f176, f180; char u184[36]; float f220; char u224[12]; int u236; char u240[148]; float f388; char u392[124]; int u516; char u520[4]; int u524; };
struct Message;
struct Self;
struct SelfVt { Ptr32<void> u[5]; Ptr32<Ptr32<Class> (Ptr32<Self>)> cls; };
struct Self {
    Ptr32<SelfVt> vt; char u4[16]; int u20; char u24[4]; int u28; char u32[4];
    Vec3 v36, v48; char u60[24]; int u84, u88; char u92[8]; int u100; char u104[4]; float f108; char u112[48];
    int u160, u164, u168; Ptr32<Object> o172; Ptr32<Object> o176; int u180; char u184[4]; int u188; Ptr32<void> owner; int u196, u200, u204; int s208, s212;
    char u216[36]; Ptr32<Handle> h252; Ptr32<Handle> h256; IntList list;
};
struct MessageId { unsigned short value; };
extern "C" short cached_id_8015f5a0(Ptr32<void>, int);
extern "C" int subscribe_80162024(Ptr32<Self>, Ptr32<MessageId>, Ptr32<void>);
extern "C" Ptr32<void> empty_80341584(Ptr32<void>);
extern "C" Ptr32<Type> cast_801797b4(Ptr32<void>);
extern "C" void move_800eac84(Ptr32<Self>, Ptr32<Vec3>);
extern "C" float random_801610a0(Ptr32<Self>);
extern "C" void forces_800eb6e4(Ptr32<Self>);
extern "C" void speed_800ecf54(Ptr32<Self>, Ptr32<Vec3>);
struct Context { char u0[52]; int u52; };
extern "C" Ptr32<Context> context_80165254();
extern "C" void pick_800edd90(Ptr32<Self>);
extern "C" void arm_800eb910(Ptr32<Self>, int);
extern "C" Ptr32<Message> arena_801613f0(Ptr32<void>, int);
extern "C" Ptr32<Message> target_801190b4(Ptr32<Message>, unsigned short, int);
extern "C" int post_8016239c(Ptr32<Message>);
extern "C" int log_80022e20(Ptr32<const char>, Ptr32<const char>, int, Ptr32<int>);
extern Ptr32<void> arena_804b1754;
extern char c_804aef20, c_804aef50, c_804aef40;
extern const char s_wd_8038b404[], s_ws_8038b414[], s_wm_8038b420[], s_wl_8038b42c[], s_rn_8038b438[], s_aw_8038b44c[], s_ed_8038b45c[], s_bm_8038b470[], s_gs_8038b480[], s_g_8038b490[], s_lg_8038b498[], s_pl_8038b4b0[], s_pf_8038b4c4[];
extern float zero_8038b4dc[];
extern "C" void d40c_payload_setup_800eb064(Ptr32<Self> self) {
    Ptr32<Type> t = cast_801797b4(empty_80341584(self->owner));
    { MessageId id; id.value = cached_id_8015f5a0(&c_804aef20, 1); subscribe_80162024(self, &id, &self->s208); }
    { MessageId id; id.value = cached_id_8015f5a0(&c_804aef50, 1); subscribe_80162024(self, &id, &self->s212); }
    setting(s_wd_8038b404, &self->u164);
    setting(s_ws_8038b414, &self->u160);
    setting(s_wm_8038b420, &self->u168);
    setting(s_wl_8038b42c, &self->u180);
    setting(s_rn_8038b438, &self->u196);
    setting(s_aw_8038b44c, &self->u204);
    setting(s_ed_8038b45c, &self->u188);
    setting(s_bm_8038b470, &self->u200);
    if (t->u516) load(self->o172, s_gs_8038b480);
    else load(self->o172, s_g_8038b490);
    load(self->o176, s_lg_8038b498);
    Ptr32<Handle> h = handle_construct_801261bc(operator new(8), &self->v36, t->u236 | 8, 1079, t->f220);
    self->h252 = h;
    handle_owner_80126308(h, self->u20);
    move_800eac84(self, &self->v36);
    handle_start_80126384(self->h252, &self->v48, 20);
    for (int i = handle_clock_801264fc(self->h252); i != 0xffff; i = handle_clock_801264fc(self->h252)) {
        int v = lookup_8003f240(kind_804aa95e)->value; self->list.push(v);
    }
    handle_finish_80126524(self->h252);
    if (t->f388 > zero_8038b4dc[0]) {
        h = handle_construct_801261bc(operator new(8), &self->v36, 0, 1, t->f388);
        self->h256 = h;
        handle_owner_80126308(h, self->u20);
    }
    float lo = t->f180, hi = t->f176;
    self->f108 = (hi - lo) * random_801610a0(self) + lo;
    forces_800eb6e4(self);
    speed_800ecf54(self, &self->v48);
    self->u28 = context_80165254()->u52;
    pick_800edd90(self);
    if (t->u524) arm_800eb910(self, self->u28);
    else { self->u88 = t->u524; self->u84 = -1; }
    Ptr32<Message> m = arena_801613f0(arena_804b1754, 12);
    post_8016239c(target_801190b4(m, cached_id_8015f5a0(&c_804aef40, 1), self->u20));
    if (is_kind(self->vt->cls(self), class_a_80361860) || is_kind(self->vt->cls(self), class_c_803618f0))
        log_80022e20(s_pl_8038b4b0, s_pf_8038b4c4, 421, &self->u100);
}


