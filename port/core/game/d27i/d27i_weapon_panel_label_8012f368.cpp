#include "w3d_ptr.h"
#line 1 "d27i_weapon_panel_label_8012f368.cpp"
// GWMP8P rev0 0x8012f368. Weapon panel event: reads the Weapon.PanelChanged
// index from the sender's name and writes the ammo or delay label for that
// weapon.
extern "C" void str_init_8020c5c0(Ptr32<void>);
extern "C" Ptr32<unsigned short> str_refs_80341884(Ptr32<void>);
extern "C" void str_finish_8020c5c4(Ptr32<void>);
extern "C" void str_release_80341588(Ptr32<void>);
struct String_803426b8 {
    Ptr32<char> text;
    String_803426b8();
    String_803426b8(const String_803426b8 &o) { str_init_8020c5c0(this); text = o.text; (*str_refs_80341884(this))++; }
    ~String_803426b8() { str_finish_8020c5c4(this); str_release_80341588(this); }
    int length() const { return ((Ptr32<unsigned short>)text)[-2]; }
};
typedef String_803426b8 String;
struct TypeInfo { char u0[20]; Ptr32<TypeInfo> base; };
struct Object;
struct ObjectVt { char u0[12]; Ptr32<void (Ptr32<Object>)> add; Ptr32<void (Ptr32<Object>)> release; Ptr32<Ptr32<TypeInfo> (Ptr32<Object>)> type; };
struct Object { Ptr32<ObjectVt> vt; };
struct Ref {
    Ptr32<Object> p;
    template <class W3dU> Ref(Ptr32<W3dU> w3d_p) : Ref((Object *)w3d_p.get()) {}
 Ref(Object *q) { p = q; if (p) p->vt->add(p); }
    Ref(const Ref &);
    ~Ref() { if (p) p->vt->release(p); }
    void e(Ptr32<void> x);
    void h(Ptr32<void> x);
    int i(int n);
};
template <TypeInfo *TYPE> inline bool isKind(Ptr32<Object> o) {
    Ptr32<TypeInfo> c = o->vt->type(o);
    Ptr32<TypeInfo> t = TYPE;
    while (c != t) {
        Ptr32<TypeInfo> n = c->base;
        if (c == n) return false;
        c = n;
    }
    return true;
}
struct Info { char u0[213]; unsigned char index; };
struct Team { char u0[60]; unsigned char id; };
inline int indexOf(Ptr32<Info> i) { return i->index; }
inline int teamOf(Ptr32<Team> t) { return t->id; }
struct Named { char u0[40]; Ptr32<Object> child; char u44[84]; String name; };
struct Value { int v; };
struct Ctx { char u0[28]; Ptr32<void> p28; char u32[4]; Ptr32<void> p36; Ptr32<void> p40; Ptr32<void> text44; Ptr32<void> p48; Ptr32<void> p52; Ptr32<void> p56; };
extern TypeInfo type_803685d8, type_80365b28;
extern char s_8039d9b0[], s_8039dcec[], s_8039dd04[], s_8039dd0c[];
extern char svc_8041b958[];
extern "C" {
Ptr32<Value> get_80178f54(Ptr32<void>);
int set_80178f60(Ptr32<void>, Ptr32<Value>);
Ptr32<void> key_80178d1c(Ptr32<void>);
Ptr32<Object> look_80164fc8(Ptr32<void>);
int rename_801790bc(Ptr32<void>, Ptr32<const char>);
unsigned strlen_802ef9c0(Ptr32<const char>);
int strcmp_802ef234(Ptr32<const char>, Ptr32<const char>);
Ptr32<void> left_8020c048(Ptr32<String>, Ptr32<const String>, unsigned);
int atol_802ed8c4(Ptr32<const char>);
Ptr32<void> ref_80341584(Ptr32<void>);
Ptr32<void> cfg_801797b4(Ptr32<void>);
int slot_8025c3a8(Ptr32<void>, int);
Ptr32<Object> svc_8020b680(Ptr32<void>);
Ptr32<void> a_80178c48(Ptr32<void>);
Ptr32<struct Info> b_800fc6dc(int);
Ptr32<struct Team> c_800fc7f8(int);
Ptr32<void> d_800fca30(int);
void e_801ea4c8(Ptr32<Object>, Ptr32<void>);
Ptr32<void> f_800fcc68(int);
Ptr32<void> g_800fcd84(int);
void h_8025cb4c(Ptr32<Object>, Ptr32<void>);
int i_8025cbe0(Ptr32<Object>, int);
void fmt_8020c510(Ptr32<String>, Ptr32<const char>, ...);
}
inline void Ref::e(Ptr32<void> x) { e_801ea4c8(p, x); }
inline void Ref::h(Ptr32<void> x) { h_8025cb4c(p, x); }
inline int Ref::i(int n) { return i_8025cbe0(p, n); }
extern "C" int d27i_weapon_panel_label_8012f368(Ptr32<void> self, Ptr32<Ctx> ctx) {
    Value v = *get_80178f54(ctx->p52);
    set_80178f60(ctx->p48, &v);
    Ptr32<void> out = ctx->text44;
    Ptr32<Object> o = look_80164fc8(key_80178d1c(ctx->p40));
    if (!o) {
        rename_801790bc(out, s_8039d9b0);
        return 0;
    }
    if (!isKind<&type_803685d8>(o)) {
        rename_801790bc(out, s_8039d9b0);
        return 0;
    }
    Ptr32<Named> obj = (Ptr32<Named>)((Ptr32<Named>)o)->child;
    if (!isKind<&type_80365b28>((Ptr32<Object>)obj)) {
        rename_801790bc(out, s_8039d9b0);
        return 0;
    }
    String a(obj->name);
    String b;
    Ptr32<const char> pre = s_8039dcec;
    left_8020c048(&b, &a, strlen_802ef9c0(pre));
    if (strcmp_802ef234(b.text, pre) == 0) {
    unsigned idx = atol_802ed8c4(a.text + b.length());
    Ptr32<void> cfg = cfg_801797b4(ref_80341584(ctx->p36));
    if (idx > 58) {
        rename_801790bc(out, s_8039d9b0);
        return 0;
    }
    if (slot_8025c3a8(cfg, idx) == 0) {
        Ref s(svc_8020b680(svc_8041b958));
        Ptr32<Info> info = b_800fc6dc((int)w3d::H((a_80178c48(ctx->p28))));
        int team = teamOf(c_800fc7f8(indexOf(info)));
        int k = indexOf(info);
        s.e(d_800fca30((int)w3d::H((a_80178c48(ctx->p28)))));
        if (k >= 0) s.h(f_800fcc68(k));
        if (team >= 0) s.h(g_800fcd84(team));
        if (s.i(idx) == -1) {
            rename_801790bc(out, s_8039d9b0);
            return 0;
        }
        String t;
        fmt_8020c510(&t, s_8039dd04, s.i(idx));
        rename_801790bc(out, t.text);
    } else {
        String t;
        fmt_8020c510(&t, s_8039dd0c, slot_8025c3a8(cfg, idx));
        Value w = *get_80178f54(ctx->p56);
        set_80178f60(ctx->p48, &w);
        rename_801790bc(out, t.text);
    }
    } else {
        rename_801790bc(out, s_8039d9b0);
        return 0;
    }
    return 0;
}


