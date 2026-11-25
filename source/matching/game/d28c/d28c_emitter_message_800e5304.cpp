// d28c: 0x800e5304. Message handler: start, trigger, resource loads, and on one id spawns a named group at the position of the worm with a named id. Names are inferred; classes are partial views.
struct String;
extern "C" String *string_default_803426b8(String *);
extern "C" void string_finish_8020c5c4(String *);
extern "C" void string_release_80341588(String *);
extern "C" void string_release_header_8020bb2c(void *);
extern "C" void string_assign_8020bd38(String *, const char *);
extern "C" int strcmp_802ef234(const char *, const char *);
struct String {
    const char *text;
    String();
    String(const String &);
    ~String() { string_finish_8020c5c4(this); string_release_80341588(this); }
    unsigned short *header() const { return (unsigned short *)(text - 6); }
    static void release(unsigned short *h) { if (--*h == 0) string_release_header_8020bb2c(h); }
    String &operator=(const String &x) { ++*x.header(); release(header()); text = x.text; return *this; }
};
struct Vec3 { float x, y, z; Vec3() {} Vec3(const Vec3 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; } };
struct Words { int a, b, c; };
template<class T> struct List { T *begin, *end, *capacity; unsigned size() const { return end - begin; } T &operator[](unsigned i) { return begin[i]; } };
struct Worm { char u0[4]; Vec3 pos; char u16[44]; const char *name; };
struct Team { char u0[20]; List<Worm *> worms; };
struct Msg { unsigned short id; };
struct Self { char u0[56]; void *h56; void *h60; void *h64; };
extern List<Team *> teams_8043bb64;
extern int id_804aedc4, id_804aedbc, id_804aedb4, id_804aeddc, id_804aede4;
extern "C" int base_8016293c(Self *, Msg *);
extern "C" void start_800e6390(Self *);
extern "C" int same_8015f65c(unsigned short, int *);
extern "C" void trigger_800e64e8();
extern "C" const char *text_8010a8fc(Msg *);
extern "C" int load_800fd504(const char *, int, unsigned);
extern "C" void *alloc_80212fd4(unsigned);
extern "C" void free_802134fc(void *);
extern "C" void *memcpy(void *, const void *, unsigned);
extern "C" void *empty_80343744(void *);
extern "C" String *name_80179170(void *);
extern "C" int spawn_800e5da0(Self *, const Words *, const char *, unsigned, float);
extern "C" void assign_800609ec(Worm *, int);
extern "C" void *cast_80342a78(void *);
extern "C" int update_80178d28(void *, int *);
extern "C" void fn_800e5698(Self *);
extern "C" int d28c_emitter_message_800e5304(Self *self, Msg *m) {
    unsigned short id = m->id;
    if (id == 64) {
        if (base_8016293c(self, m) >= 0) {
            start_800e6390(self);
            return 0;
        }
        return 0x80004005;
    }
    if (same_8015f65c(id, &id_804aedc4)) {
        trigger_800e64e8();
    } else if (same_8015f65c(id, &id_804aedbc)) {
        if (load_800fd504(text_8010a8fc(m), 6, 2) < 0) load_800fd504(text_8010a8fc(m), 6, 1);
    } else if (same_8015f65c(id, &id_804aedb4)) {
        List<Team *> teams;
        {
            unsigned n = (char *)teams_8043bb64.end - (char *)teams_8043bb64.begin;
            Team **p = (Team **)alloc_80212fd4(n);
            Team **e = (Team **)((char *)p + n);
            teams.begin = p;
            teams.end = e;
            teams.capacity = e;
            memcpy(p, teams_8043bb64.begin, n);
        }
        {
        Words at;
        String name, want, group;
        want = *name_80179170(empty_80343744(self->h60));
        group = *name_80179170(empty_80343744(self->h64));
        for (unsigned i = 0; i < teams.size(); i++) {
            List<Worm *> &worms = teams[i]->worms;
            for (unsigned j = 0; j < worms.size(); j++) {
                string_assign_8020bd38(&name, worms[j]->name);
                if (strcmp_802ef234(name.text, want.text) == 0) {
                    Vec3 v(worms[j]->pos);
                    at = *(Words *)&v;
                    int h = spawn_800e5da0(self, &at, group.text, 0, 0.0f);
                    assign_800609ec(worms[j], h);
                    update_80178d28(cast_80342a78(self->h56), &h);
                    i = teams.size();
                    break;
                }
            }
        }
        }
        if (teams.begin) free_802134fc(teams.begin);
    } else if (same_8015f65c(id, &id_804aeddc) || same_8015f65c(id, &id_804aede4)) {
        fn_800e5698(self);
    }
    return base_8016293c(self, m);
}
