#include "w3d_ptr.h"
#line 1 "d29c_script_open_container_80102dfc.cpp"
// d29c: 0x80102dfc. Script binding: takes a data entry name, checks it names a container, makes a heap descriptor bound to it, pushes the descriptor as light user data and registers the container. Names are inferred; classes are partial views.
struct lua_State;
extern "C" int lua_gettop(Ptr32<lua_State>);
extern "C" void lua_settop(Ptr32<lua_State>, int);
extern "C" int lua_isstring(Ptr32<lua_State>, int);
extern "C" Ptr32<const char> lua_tostring(Ptr32<lua_State>, int);
extern "C" void lua_pushlightuserdata(Ptr32<lua_State>, Ptr32<void>);
extern "C" void str_finish_8020c5c4(Ptr32<void>);
extern "C" void str_release_80341588(Ptr32<void>);
struct String_8020bb54 {
    Ptr32<char> text;
    template <class W3dU> String_8020bb54(Ptr32<W3dU> w3d_p) : String_8020bb54((const char *)w3d_p.get()) {}
 String_8020bb54(const char *);
    Ptr32<const char> c_str() const { return text; }
    String_8020bb54(const String_8020bb54 &);
    ~String_8020bb54() { str_finish_8020c5c4(this); str_release_80341588(this); }
};
typedef String_8020bb54 String;
struct Object;
struct ObjectVt { char u0[12]; Ptr32<void (Ptr32<Object>)> add; Ptr32<void (Ptr32<Object>)> release; Ptr32<int (Ptr32<Object>)> type; Ptr32<int (Ptr32<Object>)> kind; };
struct Object { Ptr32<ObjectVt> vt; };
struct Ref {
    Ptr32<Object> p;
    Ref() { p = 0; }
    template <class W3dU> Ref(Ptr32<W3dU> w3d_p) : Ref((Object *)w3d_p.get()) {}
 Ref(Object *q) { p = q; if (p) p->vt->add(p); }
    Ref(const Ref &);
    ~Ref() { if (p) p->vt->release(p); }
    template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((Object *)w3d_p.get()); }
 Ref &operator=(Object *q) { if (q) q->vt->add(q); if (p) p->vt->release(p); p = q; return *this; }
};
struct Descriptor_80178474 {
    Ptr32<void> value;
    unsigned tag;
    Descriptor_80178474() : value(0), tag(58280) {}
};
struct Key { Ptr32<const char> text; };
struct Script;
struct Registry { struct V { char u0[28]; Ptr32<void (Ptr32<Registry>, Ptr32<Object>)> add; }; Ptr32<struct V> vt; };
struct Script { char u0[64]; Ptr32<Registry> registry; Ptr32<lua_State> L; char u72[284]; int containers; };
extern char s1_8039904c[], s2_80399088[], s3_803990b8[], s4_803990e8[];
extern "C" {
void error_801022ec(Ptr32<Script>, Ptr32<const char>);
int lookup_800fc1b0(Ptr32<Key>, Ptr32<Ref>);
Ptr32<void> ref_80341584(Ptr32<void>);
Ptr32<Object> as_80179598(Ptr32<void>, Ptr32<Descriptor_80178474>);
}
extern "C" int d29c_script_open_container_80102dfc(Ptr32<Script> self) {
    if (lua_gettop(self->L) != 1) {
        error_801022ec(self, s1_8039904c);
        lua_settop(self->L, -2);
        return 0;
    }
    if (!lua_isstring(self->L, -1)) {
        error_801022ec(self, s2_80399088);
        lua_settop(self->L, -2);
        return 0;
    }
    String name(lua_tostring(self->L, -1));
    Ref r;
    Key k;
    k.text = name.c_str();
    if (lookup_800fc1b0(&k, &r) < 0) {
        error_801022ec(self, s3_803990b8);
        lua_settop(self->L, -2);
        return 0;
    }
    if (r.p->vt->kind(r.p) != 5) {
        error_801022ec(self, s4_803990e8);
        lua_settop(self->L, -2);
        return 0;
    }
    Ptr32<Descriptor_80178474> d = new Descriptor_80178474;
    Ref held;
    {
        Ref tmp(as_80179598(ref_80341584(r.p), d));
        Ptr32<Object> q = tmp.p;
        if (q) held = q;
    }
    lua_settop(self->L, -2);
    lua_pushlightuserdata(self->L, d);
    self->registry->vt->add(self->registry, held.p);
    self->containers++;
    return 2;
}


