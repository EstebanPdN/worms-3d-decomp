// GWMP8P rev0 0x80068a14. First person weapon view start. Field names are
// inferred from the original instructions; strings and globals are external
// views of original data. String is one word.
struct Object;
struct ObjectVtable { void *u[3]; void (*retain)(Object *); void (*release)(Object *); };
struct Object { ObjectVtable *vtable; };
struct String;
extern "C" void string_finish_8020c5c4(String *);
extern "C" void string_release_80341588(String *);
extern "C" void string_init_8020c5c0(String *);
extern "C" unsigned short *string_header_80341884(String *);
extern "C" int set_name_8015adf4(String *, void *, int);
extern "C" void string_assign_8020bd38(void *, const char *);
extern "C" void string_release_header_8020bb2c(void *);
struct String {
    char *text;
    String(const char *);
    String(const char *t, int);
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
    Object *value;
    Ref() {}
    Ref(const Ref &);
    ~Ref() { if (value) value->vtable->release(value); }
};
struct Key { const char *text; };
struct MessageCache { unsigned short id; unsigned char unknown[6]; };
struct WormView { char u0[132]; int index; };
struct Prop { char u0[20]; Vec hand; Vec eye; char u44[4]; char *weapon; char u52[20]; String model; };
struct Self {
    char u0[20]; int id; char u24[8]; Object *worm; char u36[24]; Vec eye; Vec hand; char u84[12]; Object *model; Object *hands; char u104[8]; int active; int team; char u120[240];
    int payload; char *weapon; char spawn[4]; char subs[24]; int firstPerson;
    void setEye(Vec v) { eye = v; }
    void setHand(Vec v) { hand = v; }
    void setActive(const int &v) { active = v; }
};
extern MessageCache msg_804ad650, msg_804ad630, msg_804ad628, msg_804ad638, msg_804ad658, msg_804ad660, msg_804ad668;
extern void *arena_804b1754;
extern Key keys_803eb63c[];
extern const char s_8037a884[], s_8037a894[], s_8037a898[], s_8037a8a8[], s_8037a858[];
extern "C" int message_id_8015f5a0(MessageCache *, int);
extern "C" int acquire_80162024(Self *, const unsigned short &, void *);
extern "C" int lookup_800fc1b0(Key *, void *);
extern "C" Object *cast_803426b4(Object *);
extern "C" int index_80178c48(Object *);
extern "C" WormView *worm_800fc6dc(int);
extern "C" int read_prop_800fc330(Key *, Prop **);
extern "C" int strcmp(const char *, const char *);
extern "C" void deactivate_8015fd1c(Self *);
extern "C" void load_80068eac(Self *, Prop *);
extern "C" Object *model_cast_80343584(Object *);
extern "C" void hands_800697ac(Self *);
extern "C" int read_int_800fc230(Key *, int *);
extern "C" void camera_8006947c(Self *);
extern "C" void *arena_alloc_801613f0(void *, int);
extern "C" void *target_message_801190b4(void *, int, int);
extern "C" int message_post_8016239c(void *);
inline bool differs(const char *a, const char *b) { return strcmp(a, b) != 0; }
inline int differi(const char *a, const char *b) { int r = 1; if (strcmp(a, b) == 0) r = 0; return r; }
extern "C" void d40g_weapon_view_start_80068a14(Self *self)
{
    acquire_80162024(self, message_id_8015f5a0(&msg_804ad650, 1), (char *)self + 372);
    acquire_80162024(self, message_id_8015f5a0(&msg_804ad630, 1), (char *)self + 376);
    acquire_80162024(self, message_id_8015f5a0(&msg_804ad628, 1), (char *)self + 380);
    acquire_80162024(self, message_id_8015f5a0(&msg_804ad638, 1), (char *)self + 384);
    acquire_80162024(self, message_id_8015f5a0(&msg_804ad658, 1), (char *)self + 388);
    acquire_80162024(self, message_id_8015f5a0(&msg_804ad660, 1), (char *)self + 392);
    { Key k; k.text = s_8037a884; lookup_800fc1b0(&k, &self->worm); }
    self->setActive(0);
    WormView *view = worm_800fc6dc(index_80178c48(cast_803426b4(self->worm)));
    Prop *read;
    read_prop_800fc330(&keys_803eb63c[view->index], &read);
    Prop *prop = read;
    Ref model;
    model.value = 0;
    Ref *mp = &model;
    String name(prop->model);
    int valid = differi(name.text, s_8037a894);
    while (valid == 0) {
        deactivate_8015fd1c(self);
        self->active = valid;
        return;
    }
    Object *none = 0;
    set_name_8015adf4(&name, mp, 25);
    self->team = view->index;
    load_80068eac(self, prop);
    self->setEye(prop->eye);
    self->setHand(prop->hand);
    if (self->model) self->model->vtable->release(self->model);
    self->model = none;
    Object *o = model_cast_80343584(model.value);
    if (o) o->vtable->retain(o);
    if (self->model) self->model->vtable->release(self->model);
    self->model = o;
    Ref hands;
    hands.value = none;
    Ref *hp = &hands;
    if (self->hands) self->hands->vtable->release(self->hands);
    self->hands = 0;
    { String h(s_8037a898); set_name_8015adf4(&h, hp, 25); }
    Object *q = model_cast_80343584(hands.value);
    if (q) q->vtable->retain(q);
    if (self->hands) self->hands->vtable->release(self->hands);
    self->hands = q;
    {
        ((unsigned short *)prop->weapon)[-3]++;
        char *old = self->weapon;
        void *header = old - 6;
        if (--((unsigned short *)old)[-3] == 0)
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
    void *m = arena_alloc_801613f0(arena_804b1754, 12);
    message_post_8016239c(target_message_801190b4(m, (unsigned short)message_id_8015f5a0(&msg_804ad668, 1), self->id));
}
