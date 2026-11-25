#include "w3d_ptr.h"
#line 1 "d25i_wind_gauge_load_80130638.cpp"
// d25i: 0x80130638. Load the wind gauge: resolve the HUD.WindPointer,
// HUD.WindBacking and HUD.TimerFont resources, give the font mesh 16/2
// elements and both colours from HUD.Wind.ColourText, resolve nine retained
// HUD.Wind settings, copy the off-screen position, read the four Wind
// settings, subscribe two messages, start the Wind animation and update the
// ratio. The handle has one word and a user copy constructor (d24r), which
// makes it block mode with an 8-aligned slot.
struct String {
    Ptr32<char> text;
    template <class W3dU> String(Ptr32<W3dU> w3d_p) : String((const char *)w3d_p.get()) {}
 String(const char *);
    String(const String &);
    ~String();
};
extern "C" void string_finish_8020c5c4(Ptr32<String>);
extern "C" void string_release_80341588(Ptr32<String>);
inline String::~String() {
    string_finish_8020c5c4(this);
    string_release_80341588(this);
}
struct Object;
struct ObjectVtable {
    Ptr32<void> unknown00[3];
    Ptr32<void (Ptr32<Object>)> retain;       // +12
    Ptr32<void (Ptr32<Object>)> release;      // +16
};
struct Object { Ptr32<ObjectVtable> vtable; };
struct Key { Ptr32<const char> name; };
struct Ref {
    Ptr32<Object> value;
    Ref() { value = 0; }
    Ref(const Ref &);
    ~Ref() { if (value) value->vtable->release(value); }
};
struct Vec3 { int x, y, z; };
struct MessageId { unsigned short value; };
struct Anim;
struct AnimVtable {
    Ptr32<void> unknown00[5];
    Ptr32<void (Ptr32<Anim>)> start;                  // +20
    Ptr32<void> unknown18[7];
    Ptr32<void (Ptr32<Anim>, int, float)> set_time;  // +52
    Ptr32<void> unknown38;
    Ptr32<void (Ptr32<Anim>, int, Ptr32<void>)> get_attr;   // +60
};
struct Anim { Ptr32<AnimVtable> vtable; };
struct AnimManager;
struct AnimManagerVtable {
    Ptr32<void> unknown00[23];
    Ptr32<void (Ptr32<AnimManager>, Ptr32<const char>, Ptr32<Ptr32<Anim>>)> load; // +92
};
struct AnimManager { Ptr32<AnimManagerVtable> vtable; };
struct Services { unsigned char unknown00[108]; Ptr32<AnimManager> anims; };
struct Wind {
    unsigned char unknown00[28];
    Ptr32<void> pointer;       // +28
    unsigned char unknown20[4];
    Ptr32<void> backing;       // +36
    Ptr32<void> font;          // +40
    int direction;       // +44
    int speed;           // +48
    int max_speed;       // +52
    int anim_scaler;     // +56
    Vec3 pos;            // +60
    int on_a;            // +72
    int on_b;            // +76
    unsigned char unknown50[24];
    Ptr32<Anim> anim;          // +104
    float anim_time;     // +108
    int anim_attr;       // +112
    unsigned char unknown74[4];
    Ptr32<Object> back_scale;  // +120
    Ptr32<Object> scale;       // +124
    Ptr32<Object> text_spacing;// +128
    Ptr32<Object> scroll;      // +132
    Ptr32<Object> back_offset; // +136
    Ptr32<Object> off_pos;     // +140
    Ptr32<Object> on_pos;      // +144
    Ptr32<Object> text_offset; // +148
    Ptr32<Object> text_scale;  // +152
};
extern "C" int load_8015adf4(Ptr32<const String>, Ptr32<void>, unsigned char);
extern "C" Ptr32<void> as_mesh_8034380c(Ptr32<void>);
extern "C" int mesh_lock_80189450(Ptr32<void>, int);
extern "C" int mesh_alloc_8018920c(Ptr32<void>, int);
extern "C" Ptr32<int> mesh_colours_80189760(Ptr32<void>);
extern "C" int read_colour_800fc370(Ptr32<Key>, Ptr32<int>);
extern "C" int read_setting_800fc1b0(Ptr32<Key>, Ptr32<void>);
extern "C" Ptr32<Object> as_float_80342a74(Ptr32<Object>);
extern "C" Ptr32<Object> as_vector_80342fa4(Ptr32<Object>);
extern "C" Ptr32<Vec3> value_of_80178ec4(Ptr32<Object>);
extern "C" void set_scale_80130fb8(Ptr32<Wind>, float);
extern "C" unsigned short cached_id_8015f5a0(Ptr32<void>, int);
extern "C" int subscribe_80162024(Ptr32<Wind>, Ptr32<MessageId>, Ptr32<void>);
extern "C" void digits_80130e24(Ptr32<Wind>);
extern "C" void ratio_80130d1c(Ptr32<Wind>, int);
extern Ptr32<Services> services_804b1788;
extern char cache_804af730, cache_804af738;
extern const char n_8039e010[], n_8039e020[], n_8039e030[], n_8039e040[], n_8039e054[], n_8039e068[], n_8039e078[], n_8039e090[], n_8039e0a4[], n_8039e0bc[], n_8039e0d0[], n_8039e0e8[], n_8039e100[], n_8039e114[], n_8039e120[], n_8039e130[], n_8039e140[], n_8039e150[];

static inline void assign(Ptr32<Object> &slot, Ptr32<Object> value) {
    if (value) value->vtable->retain(value);
    if (slot) slot->vtable->release(slot);
    slot = value;
}
static inline void load_float(Ptr32<Object> &slot, Ptr32<const char> name) {
    Key key;
    key.name = name;
    Ref found;
    read_setting_800fc1b0(&key, &found);
    assign(slot, as_float_80342a74(found.value));
}
static inline void load_vector(Ptr32<Object> &slot, Ptr32<const char> name) {
    Key key;
    key.name = name;
    Ref found;
    read_setting_800fc1b0(&key, &found);
    assign(slot, as_vector_80342fa4(found.value));
}
static inline void read(Ptr32<void> out, Ptr32<const char> name) {
    Key key;
    key.name = name;
    read_setting_800fc1b0(&key, out);
}
extern "C" void d25i_wind_gauge_load_80130638(Ptr32<Wind> self) {
    {
        String name(n_8039e010);
        load_8015adf4(&name, &self->pointer, 255);
    }
    {
        String name(n_8039e020);
        load_8015adf4(&name, &self->backing, 255);
    }
    {
        String name(n_8039e030);
        load_8015adf4(&name, &self->font, 255);
    }
    Ptr32<void> mesh = as_mesh_8034380c(self->font);
    mesh_lock_80189450(mesh, 16);
    mesh_alloc_8018920c(mesh, 2);
    int colour;
    Key ckey;
    ckey.name = n_8039e040;
    read_colour_800fc370(&ckey, &colour);
    mesh_colours_80189760(mesh)[0] = colour;
    mesh_colours_80189760(mesh)[1] = colour;
    load_float(self->back_scale, n_8039e054);
    load_float(self->scale, n_8039e068);
    load_float(self->text_spacing, n_8039e078);
    load_vector(self->text_scale, n_8039e090);
    load_float(self->scroll, n_8039e0a4);
    load_vector(self->back_offset, n_8039e0bc);
    load_vector(self->off_pos, n_8039e0d0);
    load_vector(self->on_pos, n_8039e0e8);
    load_vector(self->text_offset, n_8039e100);
    self->pos = *value_of_80178ec4(self->off_pos);
    set_scale_80130fb8(self, 1.0f);
    read(&self->speed, n_8039e114);
    read(&self->direction, n_8039e120);
    read(&self->anim_scaler, n_8039e130);
    read(&self->max_speed, n_8039e140);
    MessageId a;
    a.value = cached_id_8015f5a0(&cache_804af730, 1);
    subscribe_80162024(self, &a, &self->on_a);
    MessageId b;
    b.value = cached_id_8015f5a0(&cache_804af738, 1);
    subscribe_80162024(self, &b, &self->on_b);
    digits_80130e24(self);
    services_804b1788->anims->vtable->load(services_804b1788->anims, n_8039e150, &self->anim);
    self->anim->vtable->get_attr(self->anim, 12, &self->anim_attr);
    self->anim->vtable->set_time(self->anim, 1, self->anim_time);
    self->anim->vtable->start(self->anim);
    ratio_80130d1c(self, 1);
}


