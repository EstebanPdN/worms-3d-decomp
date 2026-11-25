#include "w3d_ptr.h"
#line 1 "d32f_start_game_mode_80281ff0.cpp"
// GWMP8P rev0 0x80281ff0. Front-end game mode setup, selected by name:
// MultiPlayer, SinglePlayer, Network, QuickStart (twice, the second
// unreachable), AttractGame, QuickDebug, TeamAdjust, Wormpot and Locks.
// Fills the GM.GameInitData and GM.SchemeData records, sets front-end
// properties and posts front-end messages, and calls itself with Wormpot.
// The Message id, Cache and String views are partial; field roles are
// inferred. Generated from build/d32f/gen1ff0.py.

struct Obj { Ptr32<Ptr32<void>> table; };
inline void retain(Ptr32<Obj> p) { if (p) ((Ptr32<void (Ptr32<Obj>)>)p->table[3])(p); }
inline void release(Ptr32<Obj> p) { if (p) ((Ptr32<void (Ptr32<Obj>)>)p->table[4])(p); }
extern "C" void w3d_string_base_init(Ptr32<void>), w3d_string_base_finish(Ptr32<void>), w3d_string_release(Ptr32<void>), w3d_string_release_header(Ptr32<void>);
extern "C" Ptr32<unsigned short> w3d_string_header(Ptr32<void>);
struct String_803426b8 {
    Ptr32<char> text;
    String_803426b8();
    template <class W3dU> String_803426b8(Ptr32<W3dU> w3d_p) : String_803426b8((const char *)w3d_p.get()) {}
 String_803426b8(const char *);
    String_803426b8(const String_803426b8 &);
    ~String_803426b8() { w3d_string_base_finish(this); w3d_string_release(this); }
    String_803426b8 &operator=(const String_803426b8 &other) {
        ++*(Ptr32<unsigned short>)(other.text - 6);
        Ptr32<char> old = text;
        Ptr32<unsigned short> header = (Ptr32<unsigned short>)(old - 6);
        unsigned short references = --*header;
        if (!references)
            w3d_string_release_header(header);
        text = other.text;
        return *this;
    }
};
typedef String_803426b8 String;
inline void Put(String &field, Ptr32<const char> text) { field = String(text); }
struct Handle {
    Ptr32<Obj> p;
    Handle() : p(0) {}
    template <class W3dU> Handle(Ptr32<W3dU> w3d_p) : Handle((Obj *)w3d_p.get()) {}
 Handle(Obj *x) : p(x) { retain(p); }
    Handle(const Handle &o);
    ~Handle() { release(p); }
    Handle &operator=(const Handle &o) { Ptr32<Obj> next = o.p; if (next) { retain(next); release(p); p = next; } return *this; }
};
struct Descriptor_80178474 { int zero; unsigned type; Descriptor_80178474() : zero(0), type(58280) {} ~Descriptor_80178474(); };
struct Base_8015f558 { int prefix[2]; ~Base_8015f558(); };
struct Cache_8015f704;
extern "C" unsigned w3d_cached_message_id(Ptr32<Cache_8015f704>, int);
struct Cache_8015f704 : Base_8015f558 { String name __attribute__((aligned(__alignof__(Base_8015f558)))); template <class W3dU> Cache_8015f704(Ptr32<W3dU> w3d_p) : Cache_8015f704((const char *)w3d_p.get()) {}
 Cache_8015f704(const char *); unsigned Id() { return w3d_cached_message_id(this, 1); } };
typedef Cache_8015f704 Cache;
struct Key { Ptr32<const char> text; template <class W3dU> Key(Ptr32<W3dU> w3d_p) : Key((const char *)w3d_p.get()) {}
 Key(const char *t) : text(t) {} };
struct Message;
extern Ptr32<void> lbl_804b1754;
extern "C" Ptr32<Message> tsonnet_b33_arena_801613f0(Ptr32<void>, int);
extern "C" Ptr32<Message> w3d_message_string_init(Ptr32<Message>, unsigned short, Ptr32<const char>);
extern "C" Ptr32<Message> w3d_message_int_init_800a82f0(Ptr32<Message>, unsigned short, int);
extern "C" int w3d_message_post_current(Ptr32<Message>);
extern "C" int w3d_constructor_lookup_name(const Key &, Handle &);
extern "C" int s8_property_write_800fc43c(const Key &, unsigned);
extern "C" int s8_property_read_800fc550(const Key &, Ptr32<const char>);
extern "C" int w3d_auto_800fc2b0(const Key &, Ptr32<Ptr32<const char>>);
extern "C" Ptr32<Obj> w3d_empty_80341584(Ptr32<Obj>);
extern "C" Ptr32<Obj> w3d_empty_803426b4(Ptr32<Obj>);
extern "C" Ptr32<Obj> w3d_auto_80179598(Ptr32<Obj>, Ptr32<Descriptor_80178474>);
extern "C" Ptr32<void> w3d_auto_801797b4(Ptr32<Obj>);
extern "C" int fn_80178c54(Ptr32<Obj>, const int &);
extern "C" int w3d_d24z_strcasecmp_802ef074(Ptr32<const char>, Ptr32<const char>);
extern "C" int strcmp(Ptr32<const char>, Ptr32<const char>);
extern "C" void w3d_string_format(Ptr32<String>, Ptr32<const char>, ...);
extern "C" Ptr32<String> w3d_string_assign(Ptr32<String>, Ptr32<const char>);
extern "C" void fn_802847cc(Ptr32<void>), fn_80280370(Ptr32<void>);
extern "C" unsigned fn_80162c20(), fn_80162ba8(), fn_801fe45c();
extern "C" int w3d_env_int(const char *, int *);
extern "C" void w3d_mapa_um_modo(void);
extern "C" const char *w3d_mapa_um_partida_rapida(const char *);
extern "C" unsigned w3d_r25b_category_count_8027be7c(Ptr32<void>, unsigned);
extern "C" String sol35e2_choose_string_8027befc(Ptr32<void>, unsigned, unsigned);
extern Ptr32<void> lbl_804abbac;
extern unsigned lbl_804abbb0;
extern char lbl_803cf0b0[], lbl_803cea68[], lbl_803cf0bc[], lbl_803cf0cc[], lbl_803ceac8[], lbl_803cf0d8[], lbl_803cf0e8[], lbl_803cf0fc[], lbl_803cf110[], lbl_803cf11c[], lbl_803cf124[], lbl_803cf134[], lbl_803cf13c[], lbl_803cf148[], lbl_803cf15c[], lbl_803cf16c[], lbl_803cf180[], lbl_803cf190[], lbl_803cf198[], lbl_803cf1a8[], lbl_803cf1b8[], lbl_803cf1c8[], lbl_803cf1d0[], lbl_803cf1d4[], lbl_803cf1d8[], lbl_803cf1dc[], lbl_803cf1e8[], lbl_803cf1f8[], lbl_803cec64[], lbl_803cf204[], lbl_803cf218[], lbl_803cf21c[], lbl_803cf224[], lbl_803cf22c[], lbl_803cf238[], lbl_803cf240[], lbl_803cf248[], lbl_803cf250[], lbl_803cf260[], lbl_803cf270[], lbl_803cf280[], lbl_803ce9dc[], lbl_803ce9f0[], lbl_803cea04[], lbl_803ce988[], lbl_803cf28c[], lbl_803cf29c[], lbl_803cf2a0[], lbl_803cf2b0[];
struct Init : Obj { char u4[20] __attribute__((aligned(__alignof__(Obj)))); int f24; int f28; char u32[8]; String f40; String f44; String f48; char u52[4]; int f56; char u60[4]; String f64; int f68; int f72; int f76; int f80; int f84; String f88; int f92; String f96; char u100[4]; int f104; int f108; char u112[8]; String f120; char u124[4]; String f128; String f132; int f136; char u140[4]; String f144; int f148; int f152; String f156; String f160; String f164; char u168[28]; int f196; char u200[8]; int f208; char u212[4]; String f216; int f220; int f224; int f228; int f232; int f236; char u240[24]; String f264; char u268[16]; int f284; String f288; String f292; int f296; int f300; char u304[8]; int f312; };
struct Scheme : Obj { char u4[252] __attribute__((aligned(__alignof__(Obj)))); int f256; char u260[56]; int f316; int f320; int f324; };
struct Land : Obj { char u4[16] __attribute__((aligned(__alignof__(Obj)))); float f20; float f24; char u28[20]; String f48; String f52; String f56; String f60; String f64; };

#define D(h, T) ((w3d::slot_t<T> *)(h).p)
extern "C" void d32f_start_game_mode_80281ff0(Ptr32<void> self, Ptr32<const char> mode) {
Handle h, h2;
Descriptor_80178474 d1, d2, d3;
w3d_mapa_um_modo();   // Port (v26): cualquier modo borra la marca del mapa de UM (core/native/mapa_um.cpp).
if (!w3d_d24z_strcasecmp_802ef074(mode, lbl_803cf0b0)) {
if (w3d_constructor_lookup_name(lbl_803cea68, h) < 0) return;
Handle data;
data = Handle(w3d_auto_80179598(w3d_empty_80341584(h.p), &d1));
D(data, Init)->f92 = 0;
D(data, Init)->f80 = -1;
D(data, Init)->f76 = -1;
D(data, Init)->f72 = -1;
D(data, Init)->f68 = -1;
D(data, Init)->f84 = -1;
D(data, Init)->f148 = -1;
D(data, Init)->f220 = -1;
D(data, Init)->f296 = -1;
D(data, Init)->f232 = -1;
fn_802847cc(self);
s8_property_write_800fc43c(lbl_803cf0bc, 1);
s8_property_write_800fc43c(lbl_803cf0cc, 0);
Cache table(lbl_803ceac8);
s8_property_read_800fc550(lbl_803cf0d8, lbl_803cf0e8);
w3d_message_post_current(w3d_message_string_init(tsonnet_b33_arena_801613f0(lbl_804b1754, 12), table.Id(), lbl_803cf0fc));
w3d_message_post_current(w3d_message_string_init(tsonnet_b33_arena_801613f0(lbl_804b1754, 12), table.Id(), lbl_803cf110));
d32f_start_game_mode_80281ff0(self, lbl_803cf11c);
} else if (!w3d_d24z_strcasecmp_802ef074(mode, lbl_803cf124)) {
if (w3d_constructor_lookup_name(lbl_803cea68, h) < 0) return;
Handle data;
data = Handle(w3d_auto_80179598(w3d_empty_80341584(h.p), &d1));
if (D(data, Init)->f92 == 0) return;
D(data, Init)->f92 = 1;
D(data, Init)->f80 = -1;
D(data, Init)->f76 = -1;
D(data, Init)->f72 = -1;
D(data, Init)->f68 = -1;
D(data, Init)->f84 = -1;
D(data, Init)->f148 = -1;
D(data, Init)->f220 = -1;
D(data, Init)->f296 = -1;
D(data, Init)->f232 = -1;
s8_property_write_800fc43c(lbl_803cf0bc, 1);
s8_property_write_800fc43c(lbl_803cf0cc, 0);
d32f_start_game_mode_80281ff0(self, lbl_803cf11c);
} else if (!w3d_d24z_strcasecmp_802ef074(mode, lbl_803cf134)) {
fn_802847cc(self);
s8_property_write_800fc43c(lbl_803cf0bc, 1);
s8_property_write_800fc43c(lbl_803cf0cc, 0);
Cache table(lbl_803ceac8);
s8_property_read_800fc550(lbl_803cf0d8, lbl_803cf0e8);
w3d_message_post_current(w3d_message_string_init(tsonnet_b33_arena_801613f0(lbl_804b1754, 12), table.Id(), lbl_803cf0fc));
w3d_message_post_current(w3d_message_string_init(tsonnet_b33_arena_801613f0(lbl_804b1754, 12), table.Id(), lbl_803cf110));
d32f_start_game_mode_80281ff0(self, lbl_803cf11c);
} else if (!w3d_d24z_strcasecmp_802ef074(mode, lbl_803cf13c)) {
Cache names(lbl_803cf148);
w3d_message_post_current(w3d_message_int_init_800a82f0(tsonnet_b33_arena_801613f0(lbl_804b1754, 12), names.Id(), 1));
w3d_message_post_current(w3d_message_int_init_800a82f0(tsonnet_b33_arena_801613f0(lbl_804b1754, 12), names.Id(), 2));
w3d_message_post_current(w3d_message_int_init_800a82f0(tsonnet_b33_arena_801613f0(lbl_804b1754, 12), names.Id(), 3));
w3d_message_post_current(w3d_message_int_init_800a82f0(tsonnet_b33_arena_801613f0(lbl_804b1754, 12), names.Id(), 4));
Cache scheme(lbl_803cf15c);
w3d_message_post_current(w3d_message_string_init(tsonnet_b33_arena_801613f0(lbl_804b1754, 12), scheme.Id(), lbl_803cf16c));
s8_property_write_800fc43c(lbl_803cf0bc, 1);
s8_property_write_800fc43c(lbl_803cf0cc, 0);
if (w3d_constructor_lookup_name(lbl_803cea68, h) < 0) return;
Handle data;
data = Handle(w3d_auto_80179598(w3d_empty_80341584(h.p), &d1));
D(data, Init)->f92 = 2;
Ptr32<const char> user;
w3d_auto_800fc2b0(lbl_803cf180, &user);
String worm(user);
{ Ptr32<Init> o = D(data, Init); o->f64 = String(lbl_803cf190); }
D(data, Init)->f56 = 4;
D(data, Init)->f264 = worm;
w3d_auto_800fc2b0(lbl_803cf198, &user);
w3d_string_assign(&worm, user);
D(data, Init)->f48 = worm;
w3d_auto_800fc2b0(lbl_803cf1a8, &user);
w3d_string_assign(&worm, user);
D(data, Init)->f44 = worm;
w3d_auto_800fc2b0(lbl_803cf1b8, &user);
w3d_string_assign(&worm, user);
D(data, Init)->f40 = worm;
D(data, Init)->f28 = 0;
D(data, Init)->f152 = 0;
D(data, Init)->f24 = 0;
D(data, Init)->f300 = 1;
{ Ptr32<Init> o = D(data, Init); o->f160 = String(lbl_803cf1c8); }
{ Ptr32<Init> o = D(data, Init); o->f96 = String(lbl_803cf1d0); }
w3d_message_post_current(w3d_message_int_init_800a82f0(tsonnet_b33_arena_801613f0(lbl_804b1754, 12), names.Id(), 1));
w3d_message_post_current(w3d_message_int_init_800a82f0(tsonnet_b33_arena_801613f0(lbl_804b1754, 12), names.Id(), 2));
w3d_message_post_current(w3d_message_int_init_800a82f0(tsonnet_b33_arena_801613f0(lbl_804b1754, 12), names.Id(), 3));
w3d_message_post_current(w3d_message_int_init_800a82f0(tsonnet_b33_arena_801613f0(lbl_804b1754, 12), names.Id(), 4));
{ Ptr32<Init> o = D(data, Init); o->f144 = String(lbl_803cf1d4); }
D(data, Init)->f136 = 4;
w3d_auto_800fc2b0(lbl_803cf180, &user);
w3d_string_assign(&worm, user);
D(data, Init)->f132 = worm;
w3d_auto_800fc2b0(lbl_803cf198, &user);
w3d_string_assign(&worm, user);
D(data, Init)->f128 = worm;
w3d_auto_800fc2b0(lbl_803cf1a8, &user);
w3d_string_assign(&worm, user);
D(data, Init)->f164 = worm;
w3d_auto_800fc2b0(lbl_803cf1b8, &user);
w3d_string_assign(&worm, user);
D(data, Init)->f120 = worm;
D(data, Init)->f108 = 2;
{ Ptr32<Init> o = D(data, Init); o->f88 = String(lbl_803cf1d8); }
D(data, Init)->f104 = 1;
D(data, Init)->f224 = 1;
D(data, Init)->f312 = 1;
{ Ptr32<Init> o = D(data, Init); o->f156 = String(lbl_803cf1dc); }
if (w3d_constructor_lookup_name(lbl_803cf1e8, h2) < 0) return;
Handle sch;
sch = Handle(w3d_auto_80179598(w3d_empty_80341584(h2.p), &d2));
D(sch, Scheme)->f316 = 45000;
D(sch, Scheme)->f320 = 1200000;
D(sch, Scheme)->f256 = 1;
D(sch, Scheme)->f324 = 100;
d32f_start_game_mode_80281ff0(self, lbl_803cf11c);
unsigned r = fn_80162c20();
r %= w3d_r25b_category_count_8027be7c(lbl_804abbac, 5);
w3d_env_int("W3D_LEVEL_DRAW", (int *)&r);
String level;
level = sol35e2_choose_string_8027befc(lbl_804abbac, 5, r);
Cache set(lbl_803cec64);
// Port (v26): con el mapa de UM elegido en la pantalla de abajo, la partida rápida va a su nivel anfitrión.
Ptr32<const char> elegido = level.text;
if (const char *um = w3d_mapa_um_partida_rapida(level.text.get())) elegido = um;
w3d_message_post_current(w3d_message_string_init(tsonnet_b33_arena_801613f0(lbl_804b1754, 12), set.Id(), elegido));
} else if (!w3d_d24z_strcasecmp_802ef074(mode, lbl_803cf1f8)) {
s8_property_write_800fc43c(lbl_803cf0bc, 1);
s8_property_write_800fc43c(lbl_803cf0cc, 0);
fn_80162ba8();
unsigned v = lbl_804abbb0 == 99999 ? fn_801fe45c() : lbl_804abbb0 + 1;
lbl_804abbb0 = v;
v %= w3d_r25b_category_count_8027be7c(lbl_804abbac, 6);
String level;
level = sol35e2_choose_string_8027befc(lbl_804abbac, 6, v);
Handle src, dst;
w3d_constructor_lookup_name(level.text, src);
w3d_constructor_lookup_name(lbl_803cf204, dst);
Ptr32<Land> from = (Ptr32<Land>)w3d_auto_801797b4(w3d_empty_80341584(src.p));
Handle to;
to = Handle(w3d_auto_80179598(w3d_empty_80341584(dst.p), &d3));
String unused;
D(to, Land)->f20 = from->f20;
D(to, Land)->f24 = from->f24;
D(to, Land)->f60 = from->f60;
D(to, Land)->f56 = from->f56;
D(to, Land)->f48 = from->f48;
D(to, Land)->f64 = from->f64;
unsigned w = fn_80162ba8();
switch (w % 3) {
case 0: { Ptr32<Land> o = D(to, Land); o->f52 = String(lbl_803cf218); } break;
case 1: { Ptr32<Land> o = D(to, Land); o->f52 = String(lbl_803cf21c); } break;
case 2: { Ptr32<Land> o = D(to, Land); o->f52 = String(lbl_803cf224); } break;
}
d32f_start_game_mode_80281ff0(self, lbl_803cf11c);
Cache set(lbl_803cec64);
w3d_message_post_current(w3d_message_string_init(tsonnet_b33_arena_801613f0(lbl_804b1754, 12), set.Id(), lbl_803cf204));
} else if (!w3d_d24z_strcasecmp_802ef074(mode, lbl_803cf22c)) {
if (w3d_constructor_lookup_name(lbl_803cea68, h) < 0) return;
s8_property_write_800fc43c(lbl_803cf0bc, 1);
s8_property_write_800fc43c(lbl_803cf0cc, 0);
Handle data;
data = Handle(w3d_auto_80179598(w3d_empty_80341584(h.p), &d1));
D(data, Init)->f92 = 2;
{ Ptr32<Init> o = D(data, Init); o->f64 = String(lbl_803cf190); }
D(data, Init)->f56 = 1;
{ Ptr32<Init> o = D(data, Init); o->f264 = String(lbl_803cf238); }
D(data, Init)->f28 = 0;
{ Ptr32<Init> o = D(data, Init); o->f144 = String(lbl_803cf240); }
D(data, Init)->f136 = 1;
{ Ptr32<Init> o = D(data, Init); o->f132 = String(lbl_803cf248); }
D(data, Init)->f108 = 0;
w3d_constructor_lookup_name(lbl_803cf250, h);
Ptr32<Handle> q = &h;
fn_80178c54(w3d_empty_803426b4(h.p), 45000);
w3d_constructor_lookup_name(lbl_803cf260, *q);
fn_80178c54(w3d_empty_803426b4(h.p), 1200000);
w3d_constructor_lookup_name(lbl_803cf270, *q);
} else if (!w3d_d24z_strcasecmp_802ef074(mode, lbl_803cf13c)) {
Cache names(lbl_803cf148);
w3d_message_post_current(w3d_message_int_init_800a82f0(tsonnet_b33_arena_801613f0(lbl_804b1754, 12), names.Id(), 1));
w3d_message_post_current(w3d_message_int_init_800a82f0(tsonnet_b33_arena_801613f0(lbl_804b1754, 12), names.Id(), 2));
w3d_message_post_current(w3d_message_int_init_800a82f0(tsonnet_b33_arena_801613f0(lbl_804b1754, 12), names.Id(), 3));
w3d_message_post_current(w3d_message_int_init_800a82f0(tsonnet_b33_arena_801613f0(lbl_804b1754, 12), names.Id(), 4));
Cache scheme(lbl_803cf15c);
w3d_message_post_current(w3d_message_string_init(tsonnet_b33_arena_801613f0(lbl_804b1754, 12), scheme.Id(), lbl_803cf16c));
s8_property_write_800fc43c(lbl_803cf0bc, 1);
s8_property_write_800fc43c(lbl_803cf0cc, 0);
if (w3d_constructor_lookup_name(lbl_803cea68, h) < 0) return;
Handle data;
data = Handle(w3d_auto_80179598(w3d_empty_80341584(h.p), &d1));
D(data, Init)->f92 = 2;
Ptr32<const char> user;
w3d_auto_800fc2b0(lbl_803cf180, &user);
String worm(user);
{ Ptr32<Init> o = D(data, Init); o->f64 = String(lbl_803cf190); }
D(data, Init)->f56 = 4;
D(data, Init)->f264 = worm;
w3d_auto_800fc2b0(lbl_803cf198, &user);
w3d_string_assign(&worm, user);
D(data, Init)->f48 = worm;
w3d_auto_800fc2b0(lbl_803cf1a8, &user);
w3d_string_assign(&worm, user);
D(data, Init)->f44 = worm;
w3d_auto_800fc2b0(lbl_803cf1b8, &user);
w3d_string_assign(&worm, user);
D(data, Init)->f40 = worm;
D(data, Init)->f28 = 0;
D(data, Init)->f152 = 0;
D(data, Init)->f24 = 0;
D(data, Init)->f300 = 1;
{ Ptr32<Init> o = D(data, Init); o->f160 = String(lbl_803cf1c8); }
{ Ptr32<Init> o = D(data, Init); o->f96 = String(lbl_803cf1d0); }
w3d_message_post_current(w3d_message_int_init_800a82f0(tsonnet_b33_arena_801613f0(lbl_804b1754, 12), names.Id(), 1));
w3d_message_post_current(w3d_message_int_init_800a82f0(tsonnet_b33_arena_801613f0(lbl_804b1754, 12), names.Id(), 2));
w3d_message_post_current(w3d_message_int_init_800a82f0(tsonnet_b33_arena_801613f0(lbl_804b1754, 12), names.Id(), 3));
w3d_message_post_current(w3d_message_int_init_800a82f0(tsonnet_b33_arena_801613f0(lbl_804b1754, 12), names.Id(), 4));
{ Ptr32<Init> o = D(data, Init); o->f144 = String(lbl_803cf1d4); }
D(data, Init)->f136 = 4;
w3d_auto_800fc2b0(lbl_803cf180, &user);
w3d_string_assign(&worm, user);
D(data, Init)->f132 = worm;
w3d_auto_800fc2b0(lbl_803cf198, &user);
w3d_string_assign(&worm, user);
D(data, Init)->f128 = worm;
w3d_auto_800fc2b0(lbl_803cf1a8, &user);
w3d_string_assign(&worm, user);
D(data, Init)->f164 = worm;
w3d_auto_800fc2b0(lbl_803cf1b8, &user);
w3d_string_assign(&worm, user);
D(data, Init)->f120 = worm;
D(data, Init)->f108 = 2;
{ Ptr32<Init> o = D(data, Init); o->f88 = String(lbl_803cf1d8); }
D(data, Init)->f104 = 1;
D(data, Init)->f224 = 1;
D(data, Init)->f312 = 1;
{ Ptr32<Init> o = D(data, Init); o->f156 = String(lbl_803cf1dc); }
if (w3d_constructor_lookup_name(lbl_803cf1e8, h2) < 0) return;
Handle sch;
sch = Handle(w3d_auto_80179598(w3d_empty_80341584(h2.p), &d2));
D(sch, Scheme)->f316 = 45000;
D(sch, Scheme)->f320 = 1200000;
D(sch, Scheme)->f256 = 1;
D(sch, Scheme)->f324 = 100;
d32f_start_game_mode_80281ff0(self, lbl_803cf11c);
unsigned r = fn_80162ba8();
r %= w3d_r25b_category_count_8027be7c(lbl_804abbac, 5);
w3d_env_int("W3D_LEVEL_DRAW", (int *)&r);
String level;
level = sol35e2_choose_string_8027befc(lbl_804abbac, 5, r);
Cache set(lbl_803cec64);
w3d_message_post_current(w3d_message_string_init(tsonnet_b33_arena_801613f0(lbl_804b1754, 12), set.Id(), level.text));
fn_80178c54(w3d_empty_803426b4(h.p), 100);
} else if (!w3d_d24z_strcasecmp_802ef074(mode, lbl_803cf280)) {
if (w3d_constructor_lookup_name(lbl_803cea68, h) < 0) return;
int allied, worms;
worms = 1;
allied = 0;
Ptr32<Init> init = (Ptr32<Init>)w3d_auto_801797b4(w3d_empty_80341584(h.p));
Ptr32<const char> team;
w3d_auto_800fc2b0(lbl_803cf28c, &team);
switch ((unsigned)init->f92) {
case 4:
if (!strcmp(init->f292.text, team)) { worms = init->f284; allied = init->f236; }
case 3:
if (!strcmp(init->f216.text, team)) { worms = init->f208; allied = init->f228; }
case 2:
if (!strcmp(init->f144.text, team)) { worms = init->f136; allied = init->f224; }
}
if (!strcmp(init->f64.text, team)) { worms = init->f56; allied = init->f152; }
String a, b;
w3d_string_format(&a, lbl_803cf29c, worms);
w3d_string_format(&b, lbl_803cf29c, allied);
s8_property_read_800fc550(lbl_803cf2a0, a.text);
s8_property_read_800fc550(lbl_803cf2b0, b.text);
} else if (!w3d_d24z_strcasecmp_802ef074(mode, lbl_803cf11c)) {
s8_property_write_800fc43c(lbl_803ce9dc, 17);
s8_property_write_800fc43c(lbl_803ce9f0, 17);
s8_property_write_800fc43c(lbl_803cea04, 17);
} else if (!w3d_d24z_strcasecmp_802ef074(mode, lbl_803ce988)) {
fn_80280370(self);
}
}


