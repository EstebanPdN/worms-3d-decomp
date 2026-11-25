// d27c: 0x800ed9c8. Plays a named effect on a payload: reads the Payload.Mesh setting, posts a message, then either attaches the effect to the mesh node or spawns it at the predicted position, or the node's position when it resolves. Names are inferred.
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3 &operator+=(const Vec3 &o) { x += o.x; y += o.y; z += o.z; return *this; }
};
struct Pos { float x, y, z; Pos(); };
struct Xform { float axis[9]; Pos position; const Pos &P() const { return position; } };
struct W { int a, b, c; };
struct String {
    char *text;
    String(const String &o);
    ~String();
    unsigned short length() const { return ((unsigned short *)text)[-2]; }
};
extern "C" void string_init_8020c5c0(String *);
extern "C" unsigned short *string_header_80341884(String *);
extern "C" void string_finish_8020c5c4(String *);
extern "C" void string_release_80341588(String *);
inline String::String(const String &o) {
    string_init_8020c5c0(this);
    text = o.text;
    ++*string_header_80341884(this);
}
inline String::~String() {
    string_finish_8020c5c4(this);
    string_release_80341588(this);
}
struct Desc { char u0[436]; String mesh; };
struct Message { unsigned short id; void **vtable; };
struct Actor {
    struct V { void *u[11]; void (*position)(Actor *, int, Vec3 *); void *u48[3]; void (*velocity)(Actor *, int, Vec3 *); } *vtable;
    char u4[16];
    int id;
    char u24[168];
    void *h192;
    char u196[76];
    int effect;
};
struct Context { char u0[52]; int now; };
extern char key_8038b620[];
extern void *heap_804b1754;
extern int msgid_804aef38;
extern void *vt_8040db38[];
extern "C" void *empty_80341584(void *);
extern "C" Desc *desc_801797b4(void *);
extern "C" int write_800fc43c(const char **, int);
extern "C" Message *alloc_801613f0(void *, int);
extern "C" short msg_id_8015f5a0(void *, int);
extern "C" int post_8015fc58(Actor *, Message *);
extern "C" int read_800fc230(const char **, void **);
extern "C" void base_800edbbc(Actor *);
extern "C" int spawn_800e5cf0(void *, char *, char *, int, int);
extern "C" Context *ctx_80165254(void);
extern "C" int xform_80181e3c(void *, char *, Xform *);
extern "C" int effect_800e5ca4(const Vec3 *, const char *, int, float);
extern "C" void d27c_payload_play_effect_800ed9c8(Actor *self, int attached, const String &name) {
    if (name.length()) {
        String mesh(desc_801797b4(empty_80341584(self->h192))->mesh);
        const char *k1 = key_8038b620;
        write_800fc43c(&k1, 0);
        Message *m = alloc_801613f0(heap_804b1754, 8);
        m->id = msg_id_8015f5a0(&msgid_804aef38, 1);
        m->vtable = vt_8040db38;
        post_8015fc58(self, m);
        const char *k2 = key_8038b620;
        void *res;
        read_800fc230(&k2, &res);
        void *r = res;
        if (attached) {
            base_800edbbc(self);
            self->effect = spawn_800e5cf0(r, mesh.text, name.text, self->id, 0);
        } else {
            int now = ctx_80165254()->now;
            Vec3 p, v;
            self->vtable->position(self, now, &p);
            self->vtable->velocity(self, now, &v);
            p += v;
            if (r) {
                Xform t;
                if (xform_80181e3c(r, mesh.text, &t) >= 0) *(W *)&p = *(const W *)&t.P();
            }
            effect_800e5ca4(&p, name.text, 0, 0.0f);
        }
    }
}
