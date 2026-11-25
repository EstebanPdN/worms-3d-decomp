#include "w3d_ptr.h"
#line 1 "d40g_weapon_view_start_80068a14.cpp"
// GWMP8P rev0 0x80068a14. First person weapon view start. Field names are
// inferred from the original instructions; strings and globals are external
// views of original data. String is one word.
struct Object;
struct ObjectVtable { Ptr32<void> u[3]; Ptr32<void (Ptr32<Object>)> retain; Ptr32<void (Ptr32<Object>)> release; };
struct Object { Ptr32<ObjectVtable> vtable; };
struct String;
extern "C" void string_finish_8020c5c4(Ptr32<String>);
extern "C" void string_release_80341588(Ptr32<String>);
extern "C" void string_init_8020c5c0(Ptr32<String>);
extern "C" Ptr32<unsigned short> string_header_80341884(Ptr32<String>);
extern "C" int set_name_8015adf4(Ptr32<String>, Ptr32<void>, int);
extern "C" void string_assign_8020bd38(Ptr32<void>, Ptr32<const char>);
extern "C" void string_release_header_8020bb2c(Ptr32<void>);
struct String {
    Ptr32<char> text;
    template <class W3dU> String(Ptr32<W3dU> w3d_p) : String((const char *)w3d_p.get()) {}
 String(const char *);
    String(Ptr32<const char> t, int);
    String(const String &o) {
        string_init_8020c5c0(this);
        text = o.text;
        ++*string_header_80341884(this);
    }
    ~String() { string_finish_8020c5c4(this); string_release_80341588(this); }
};
struct Vec {
    float x, y, z;
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct Ref {
    Ptr32<Object> value;
    Ref() {}
    Ref(const Ref &);
    ~Ref() { if (value) value->vtable->release(value); }
};
struct Key { Ptr32<const char> text; };
struct MessageCache { unsigned short id; unsigned char unknown[6]; };
struct WormView { char u0[132]; int index; };
struct Prop { char u0[20]; Vec hand; Vec eye; char u44[4]; Ptr32<char> weapon; char u52[20]; String model; };
struct Self {
    char u0[20]; int id; char u24[8]; Ptr32<Object> worm; char u36[24]; Vec eye; Vec hand; char u84[12]; Ptr32<Object> model; Ptr32<Object> hands; char u104[8]; int active; int team; char u120[240];
    int payload; Ptr32<char> weapon; char spawn[4]; char subs[24]; int firstPerson;
    void setEye(Vec v) { eye = v; }
    void setHand(Vec v) { hand = v; }
    void setActive(const int &v) { active = v; }
};
extern MessageCache msg_804ad650, msg_804ad630, msg_804ad628, msg_804ad638, msg_804ad658, msg_804ad660, msg_804ad668;
extern Ptr32<void> arena_804b1754;
extern Key keys_803eb63c[];
extern const char s_8037a884[], s_8037a894[], s_8037a898[], s_8037a8a8[], s_8037a858[];
extern "C" int message_id_8015f5a0(Ptr32<MessageCache>, int);
extern "C" int acquire_80162024(Ptr32<Self>, const unsigned short &, Ptr32<void>);
extern "C" int lookup_800fc1b0(Ptr32<Key>, Ptr32<void>);
extern "C" Ptr32<Object> cast_803426b4(Ptr32<Object>);
extern "C" int index_80178c48(Ptr32<Object>);
extern "C" Ptr32<WormView> worm_800fc6dc(int);
extern "C" int read_prop_800fc330(Ptr32<Key>, Ptr32<Ptr32<Prop>>);
extern "C" int strcmp(Ptr32<const char>, Ptr32<const char>);
extern "C" void deactivate_8015fd1c(Ptr32<Self>);
extern "C" void load_80068eac(Ptr32<Self>, Ptr32<Prop>);
extern "C" Ptr32<Object> model_cast_80343584(Ptr32<Object>);
extern "C" void hands_800697ac(Ptr32<Self>);
extern "C" int read_int_800fc230(Ptr32<Key>, Ptr32<int>);
extern "C" void camera_8006947c(Ptr32<Self>);
extern "C" Ptr32<void> arena_alloc_801613f0(Ptr32<void>, int);
extern "C" Ptr32<void> target_message_801190b4(Ptr32<void>, int, int);
extern "C" int message_post_8016239c(Ptr32<void>);
inline bool differs(Ptr32<const char> a, Ptr32<const char> b) { return strcmp(a, b) != 0; }
inline int differi(Ptr32<const char> a, Ptr32<const char> b) { int r = 1; if (strcmp(a, b) == 0) r = 0; return r; }
extern "C" void d40g_weapon_view_start_80068a14(Ptr32<Self> self)
{
    acquire_80162024(self, message_id_8015f5a0(&msg_804ad650, 1), (Ptr32<char>)self + 372);
    acquire_80162024(self, message_id_8015f5a0(&msg_804ad630, 1), (Ptr32<char>)self + 376);
    acquire_80162024(self, message_id_8015f5a0(&msg_804ad628, 1), (Ptr32<char>)self + 380);
    acquire_80162024(self, message_id_8015f5a0(&msg_804ad638, 1), (Ptr32<char>)self + 384);
    acquire_80162024(self, message_id_8015f5a0(&msg_804ad658, 1), (Ptr32<char>)self + 388);
    acquire_80162024(self, message_id_8015f5a0(&msg_804ad660, 1), (Ptr32<char>)self + 392);
    { Key k; k.text = s_8037a884; lookup_800fc1b0(&k, &self->worm); }
    self->setActive(0);
    Ptr32<WormView> view = worm_800fc6dc(index_80178c48(cast_803426b4(self->worm)));
    Ptr32<Prop> read;
    read_prop_800fc330(&keys_803eb63c[view->index], &read);
    Ptr32<Prop> prop = read;
    Ref model;
    model.value = 0;
    Ptr32<Ref> mp = &model;
    String name(prop->model);
    int valid = differi(name.text, s_8037a894);
    while (valid == 0) {
        deactivate_8015fd1c(self);
        self->active = valid;
        return;
    }
    Ptr32<Object> none = 0;
    set_name_8015adf4(&name, mp, 25);
    self->team = view->index;
    load_80068eac(self, prop);
    self->setEye(prop->eye);
    self->setHand(prop->hand);
    if (self->model) self->model->vtable->release(self->model);
    self->model = none;
    Ptr32<Object> o = model_cast_80343584(model.value);
    if (o) o->vtable->retain(o);
    if (self->model) self->model->vtable->release(self->model);
    self->model = o;
    Ref hands;
    hands.value = none;
    Ptr32<Ref> hp = &hands;
    if (self->hands) self->hands->vtable->release(self->hands);
    self->hands = 0;
    { String h(s_8037a898); set_name_8015adf4(&h, hp, 25); }
    Ptr32<Object> q = model_cast_80343584(hands.value);
    if (q) q->vtable->retain(q);
    if (self->hands) self->hands->vtable->release(self->hands);
    self->hands = q;
    {
        ((Ptr32<unsigned short>)prop->weapon)[-3]++;
        Ptr32<char> old = self->weapon;
        Ptr32<void> header = old - 6;
        if (--((Ptr32<unsigned short>)old)[-3] == 0)
            string_release_header_8020bb2c(header);
        self->weapon = prop->weapon;
    }
    { int d = differs(self->weapon, s_8037a894); self->payload = d ? 1 : d; }
    string_assign_8020bd38(self->spawn, s_8037a8a8);
    hands_800697ac(self);
    int mode;
    { Key k; k.text = s_8037a858; read_int_800fc230(&k, &mode); }
    self->firstPerson = mode == 1;
    camera_8006947c(self);
    Ptr32<void> m = arena_alloc_801613f0(arena_804b1754, 12);
    message_post_8016239c(target_message_801190b4(m, (unsigned short)message_id_8015f5a0(&msg_804ad668, 1), self->id));
}


