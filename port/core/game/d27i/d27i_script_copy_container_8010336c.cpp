#include "w3d_ptr.h"
#line 1 "d27i_script_copy_container_8010336c.cpp"
// GWMP8P rev0 0x8010336c. Script binding CopyContainer(source, target):
// looks up two data entries by name, checks both are containers of the same
// type and copies one into the other.
struct lua_State;
extern "C" int lua_gettop(Ptr32<lua_State>);
extern "C" void lua_settop(Ptr32<lua_State>, int);
extern "C" int lua_isstring(Ptr32<lua_State>, int);
extern "C" Ptr32<const char> lua_tostring(Ptr32<lua_State>, int);
extern "C" void str_finish_8020c5c4(Ptr32<void>);
extern "C" void str_release_80341588(Ptr32<void>);
struct String_8020bb54 {
    Ptr32<char> text;
    template <class W3dU> String_8020bb54(Ptr32<W3dU> w3d_p) : String_8020bb54((const char *)w3d_p.get()) {}
 String_8020bb54(const char *);
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
    ~Descriptor_80178474();
};
struct Key; extern "C" int lookup_800fc1b0(Ptr32<Key>, Ptr32<Ref>);
struct Key { Ptr32<const char> text; Key() {} Key(const String &o) { text = o.text; } };
inline int find(const String &o, Ref &r) { Key k; k.text = o.text; return lookup_800fc1b0(&k, &r); }
inline int find2(const String &o, Ref &r) { Key k(o); return lookup_800fc1b0(&k, &r); }
struct Script { char u0[68]; Ptr32<lua_State> L; };

extern char s_80399288[], s_803992c4[], s_803992f4[], s_80399324[], s_80399358[];
extern "C" {
void error_801022ec(Ptr32<Script>, Ptr32<const char>);
int lookup_800fc1b0(Ptr32<Key>, Ptr32<Ref>);
Ptr32<void> ref_80341584(Ptr32<void>);
Ptr32<Object> cfg_801797b4(Ptr32<void>);
Ptr32<Object> as_80179598(Ptr32<void>, Ptr32<Descriptor_80178474>);
void copy_801ea4c8(Ptr32<Object>, Ptr32<Object>);
}
extern "C" int d27i_script_copy_container_8010336c(Ptr32<Script> self) {
    int n = lua_gettop(self->L);
    if (n != 2) {
        error_801022ec(self, s_80399288);
        lua_settop(self->L, -n - 1);
        return 0;
    }
    if (!lua_isstring(self->L, -2) || !lua_isstring(self->L, -1)) {
        error_801022ec(self, s_803992c4);
        lua_settop(self->L, -3);
        return 0;
    }
    Ref a;
    Ref b;
    String n1(lua_tostring(self->L, -2));
    Key k1;
    k1.text = n1.text;
    int r1 = lookup_800fc1b0(&k1, &a);
    String n2(lua_tostring(self->L, -1));
    Key k2;
    k2.text = n2.text;
    int r2 = lookup_800fc1b0(&k2, &b);
    if (r1 < 0 || r2 < 0) {
        error_801022ec(self, s_803992f4);
        lua_settop(self->L, -3);
        return 0;
    }
    if (a.p->vt->kind(a.p) != 5 || b.p->vt->kind(b.p) != 5) {
        error_801022ec(self, s_80399324);
        lua_settop(self->L, -3);
        return 0;
    }
    Ptr32<Object> src = cfg_801797b4(ref_80341584(a.p));
    Descriptor_80178474 desc;
    Ref d;
    {
        Ref tmp(as_80179598(ref_80341584(b.p), &desc));
        Ptr32<Object> q = tmp.p;
        if (q) d = q;
    }
    if (src->vt->type(src) != d.p->vt->type(d.p)) {
        error_801022ec(self, s_80399358);
        lua_settop(self->L, -3);
    } else {
        lua_settop(self->L, -3);
        copy_801ea4c8(d.p, src);
    }
    return 0;
}


