// GWMP8P rev0 0x800bc5d0. Loader around 0x800bc7c4: runs the land file; on
// failure the by-value name is copied into a dead scoped String (witnessed
// by its copy and destructor calls) and E_FAIL is returned. Otherwise the
// path is the name without its 4-letter extension, plus the Land.TimeOfDay
// setting and .csh; the stream and string constructors are out of line so
// their addresses stay in registers. Stream, Extent, Key and Holder are
// partial views.
struct Obj;
struct ObjVt { void *u[4]; void (*release)(Obj *); };
struct Obj { ObjVt *vt; };
struct Holder {
    Obj *p;
    Holder() { p = 0; }
    ~Holder() { if (p) p->vt->release(p); }
};
struct Header { unsigned short refs; };
struct String_803426b8;
extern "C" void fn_8020c5c0(String_803426b8 *);
extern "C" Header *fn_80341884(String_803426b8 *);
extern "C" void fn_8020c5c4(String_803426b8 *);
extern "C" void fn_80341588(String_803426b8 *);
extern "C" String_803426b8 *fn_8020c048(String_803426b8 *, String_803426b8 *, unsigned);
extern "C" void * fn_8020bf2c(String_803426b8 *, const char *);
struct String_803426b8 {
    char *text;
    String_803426b8();
    String_803426b8(const String_803426b8 &o) { fn_8020c5c0(this); text = o.text; fn_80341884(this)->refs++; }
    ~String_803426b8() { fn_8020c5c4(this); fn_80341588(this); }
    unsigned Length() const { return ((unsigned short *)text)[-2]; }
};
struct Stream_80207fec { unsigned words[6]; Stream_80207fec(); };
struct Extent { unsigned value, opaque[3]; };
extern "C" int fn_802080a0(Stream_80207fec *, const char *, int);
extern "C" void fn_802081c8(Stream_80207fec *, Extent *);
extern "C" int fn_8020810c(Stream_80207fec *);
extern "C" void fn_8020803c(Stream_80207fec *, int);
extern "C" int fn_80208298(Stream_80207fec *, void *, unsigned, int);
extern "C" void *fn_801fe0b8(unsigned);
extern "C" void fn_801fe160(void *);
extern "C" int fn_8020b6e8(const char *, Holder *);
extern "C" int fn_800bc7c4(void *, Obj *, int, void *, unsigned);
struct Key { const char *name; Key(const char *n) { name = n; } };
extern "C" int fn_800fc2b0(Key *, const char **);
extern const char lbl_80382c24[];   // "Land.TimeOfDay"
extern const char lbl_80382c34[];   // ".csh"
extern "C" int d40m_land_load_time_of_day_800bc5d0(void *self, String_803426b8 name) {
    Holder holder;
    if (fn_8020b6e8(name.text, &holder) < 0) {
        String_803426b8 copy(name);
        return 0x80004005;
    }
    String_803426b8 path;
    fn_8020c048(&path, &name, name.Length() - 4);
    const char *tod;
    Key key(lbl_80382c24);
    fn_800fc2b0(&key, &tod);
    fn_8020bf2c(&path, tod);
    fn_8020bf2c(&path, lbl_80382c34);
    Stream_80207fec s;
    int result;
    if (fn_802080a0(&s, path.text, 1) >= 0) {
        Extent e;
        fn_802081c8(&s, &e);
        void *data = fn_801fe0b8(e.value);
        fn_80208298(&s, data, e.value, 0);
        fn_8020810c(&s);
        result = fn_800bc7c4(self, holder.p, 0, data, e.value >> 2);
        fn_801fe160(data);
    } else {
        result = fn_800bc7c4(self, holder.p, 1, 0, 0);
    }
    fn_8020803c(&s, 2);
    return result;
}
