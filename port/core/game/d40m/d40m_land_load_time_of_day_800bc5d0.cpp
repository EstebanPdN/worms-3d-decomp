#include "w3d_ptr.h"
#line 1 "d40m_land_load_time_of_day_800bc5d0.cpp"
// GWMP8P rev0 0x800bc5d0. Loader around 0x800bc7c4: runs the land file; on
// failure the by-value name is copied into a dead scoped String (witnessed
// by its copy and destructor calls) and E_FAIL is returned. Otherwise the
// path is the name without its 4-letter extension, plus the Land.TimeOfDay
// setting and .csh; the stream and string constructors are out of line so
// their addresses stay in registers. Stream, Extent, Key and Holder are
// partial views.
struct Obj;
struct ObjVt { Ptr32<void> u[4]; Ptr32<void (Ptr32<Obj>)> release; };
struct Obj { Ptr32<ObjVt> vt; };
struct Holder {
    Ptr32<Obj> p;
    Holder() { p = 0; }
    ~Holder() { if (p) p->vt->release(p); }
};
struct Header { unsigned short refs; };
struct String_803426b8;
extern "C" void fn_8020c5c0(Ptr32<String_803426b8>);
extern "C" Ptr32<Header> fn_80341884(Ptr32<String_803426b8>);
extern "C" void fn_8020c5c4(Ptr32<String_803426b8>);
extern "C" void fn_80341588(Ptr32<String_803426b8>);
extern "C" Ptr32<String_803426b8> fn_8020c048(Ptr32<String_803426b8>, Ptr32<String_803426b8>, unsigned);
extern "C" Ptr32<void> fn_8020bf2c(Ptr32<String_803426b8>, Ptr32<const char>);
struct String_803426b8 {
    Ptr32<char> text;
    String_803426b8();
    String_803426b8(const String_803426b8 &o) { fn_8020c5c0(this); text = o.text; fn_80341884(this)->refs++; }
    ~String_803426b8() { fn_8020c5c4(this); fn_80341588(this); }
    unsigned Length() const { return ((Ptr32<unsigned short>)text)[-2]; }
};
struct Stream_80207fec { unsigned words[6]; Stream_80207fec(); };
struct Extent { unsigned value, opaque[3]; };
extern "C" int fn_802080a0(Ptr32<Stream_80207fec>, Ptr32<const char>, int);
extern "C" void fn_802081c8(Ptr32<Stream_80207fec>, Ptr32<Extent>);
extern "C" int fn_8020810c(Ptr32<Stream_80207fec>);
extern "C" void fn_8020803c(Ptr32<Stream_80207fec>, int);
extern "C" int fn_80208298(Ptr32<Stream_80207fec>, Ptr32<void>, unsigned, int);
extern "C" Ptr32<void> fn_801fe0b8(unsigned);
extern "C" void fn_801fe160(Ptr32<void>);
extern "C" int fn_8020b6e8(Ptr32<const char>, Ptr32<Holder>);
extern "C" int fn_800bc7c4(Ptr32<void>, Ptr32<Obj>, int, Ptr32<void>, unsigned);
struct Key { Ptr32<const char> name; template <class W3dU> Key(Ptr32<W3dU> w3d_p) : Key((const char *)w3d_p.get()) {}
 Key(const char *n) { name = n; } };
extern "C" int fn_800fc2b0(Ptr32<Key>, Ptr32<Ptr32<const char>>);
extern const char lbl_80382c24[];   // "Land.TimeOfDay"
extern const char lbl_80382c34[];   // ".csh"
extern "C" int d40m_land_load_time_of_day_800bc5d0(Ptr32<void> self, String_803426b8 name) {
    Holder holder;
    if (fn_8020b6e8(name.text, &holder) < 0) {
        String_803426b8 copy(name);
        return 0x80004005;
    }
    String_803426b8 path;
    fn_8020c048(&path, &name, name.Length() - 4);
    Ptr32<const char> tod;
    Key key(lbl_80382c24);
    fn_800fc2b0(&key, &tod);
    fn_8020bf2c(&path, tod);
    fn_8020bf2c(&path, lbl_80382c34);
    Stream_80207fec s;
    int result;
    if (fn_802080a0(&s, path.text, 1) >= 0) {
        Extent e;
        fn_802081c8(&s, &e);
        Ptr32<void> data = fn_801fe0b8(e.value);
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


