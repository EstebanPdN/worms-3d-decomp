// GWMP8P rev0 0x80281ff0. Front-end game mode setup, selected by name:
// MultiPlayer, SinglePlayer, Network, QuickStart (twice, the second
// unreachable), AttractGame, QuickDebug, TeamAdjust, Wormpot and Locks.
// Fills the GM.GameInitData and GM.SchemeData records, sets front-end
// properties and posts front-end messages, and calls itself with Wormpot.
// The Message id, Cache and String views are partial; field roles are
// inferred. Generated from build/d32f/gen1ff0.py.

struct Obj { void **table; };
inline void retain(Obj *p) { if (p) ((void (*)(Obj *))p->table[3])(p); }
inline void release(Obj *p) { if (p) ((void (*)(Obj *))p->table[4])(p); }
extern "C" void w3d_string_base_init(void *), w3d_string_base_finish(void *), w3d_string_release(void *), w3d_string_release_header(void *);
extern "C" unsigned short *w3d_string_header(void *);
struct String_803426b8 {
    char *text;
    String_803426b8();
    String_803426b8(const char *);
    String_803426b8(const String_803426b8 &);
    ~String_803426b8() { w3d_string_base_finish(this); w3d_string_release(this); }
    String_803426b8 &operator=(const String_803426b8 &other) {
        ++*(unsigned short *)(other.text - 6);
        char *old = text;
        unsigned short *header = (unsigned short *)(old - 6);
        unsigned short references = --*header;
        if (!references)
            w3d_string_release_header(header);
        text = other.text;
        return *this;
    }
};
typedef String_803426b8 String;
inline void Put(String &field, const char *text) { field = String(text); }
struct Handle {
    Obj *p;
    Handle() : p(0) {}
    Handle(Obj *x) : p(x) { retain(p); }
    Handle(const Handle &o);
    ~Handle() { release(p); }
    Handle &operator=(const Handle &o) { Obj *next = o.p; if (next) { retain(next); release(p); p = next; } return *this; }
};
struct Descriptor_80178474 { int zero; unsigned type; Descriptor_80178474() : zero(0), type(58280) {} ~Descriptor_80178474(); };
struct Base_8015f558 { int prefix[2]; ~Base_8015f558(); };
struct Cache_8015f704;
extern "C" unsigned w3d_cached_message_id(Cache_8015f704 *, int);
struct Cache_8015f704 : Base_8015f558 { String name; Cache_8015f704(const char *); unsigned Id() { return w3d_cached_message_id(this, 1); } };
typedef Cache_8015f704 Cache;
struct Key { const char *text; Key(const char *t) : text(t) {} };
struct Message;
extern void *lbl_804b1754;
extern "C" Message *tsonnet_b33_arena_801613f0(void *, int);
extern "C" Message *w3d_message_string_init(Message *, unsigned short, const char *);
extern "C" Message *w3d_message_int_init_800a82f0(Message *, unsigned short, int);
extern "C" int w3d_message_post_current(Message *);
extern "C" int w3d_constructor_lookup_name(const Key &, Handle &);
extern "C" int s8_property_write_800fc43c(const Key &, unsigned);
extern "C" int s8_property_read_800fc550(const Key &, const char *);
extern "C" int w3d_auto_800fc2b0(const Key &, const char **);
extern "C" Obj *w3d_empty_80341584(Obj *);
extern "C" Obj *w3d_empty_803426b4(Obj *);
extern "C" Obj *w3d_auto_80179598(Obj *, Descriptor_80178474 *);
extern "C" void *w3d_auto_801797b4(Obj *);
extern "C" int fn_80178c54(Obj *, const int &);
extern "C" int w3d_d24z_strcasecmp_802ef074(const char *, const char *);
extern "C" int strcmp(const char *, const char *);
extern "C" void w3d_string_format(String *, const char *, ...);
extern "C" String *w3d_string_assign(String *, const char *);
extern "C" void fn_802847cc(void *), fn_80280370(void *);
extern "C" unsigned fn_80162c20(), fn_80162ba8(), fn_801fe45c();
extern "C" unsigned w3d_r25b_category_count_8027be7c(void *, unsigned);
extern "C" String sol35e2_choose_string_8027befc(void *, unsigned, unsigned);
extern void *lbl_804abbac;
extern unsigned lbl_804abbb0;
extern char lbl_803cf0b0[], lbl_803cea68[], lbl_803cf0bc[], lbl_803cf0cc[], lbl_803ceac8[], lbl_803cf0d8[], lbl_803cf0e8[], lbl_803cf0fc[], lbl_803cf110[], lbl_803cf11c[], lbl_803cf124[], lbl_803cf134[], lbl_803cf13c[], lbl_803cf148[], lbl_803cf15c[], lbl_803cf16c[], lbl_803cf180[], lbl_803cf190[], lbl_803cf198[], lbl_803cf1a8[], lbl_803cf1b8[], lbl_803cf1c8[], lbl_803cf1d0[], lbl_803cf1d4[], lbl_803cf1d8[], lbl_803cf1dc[], lbl_803cf1e8[], lbl_803cf1f8[], lbl_803cec64[], lbl_803cf204[], lbl_803cf218[], lbl_803cf21c[], lbl_803cf224[], lbl_803cf22c[], lbl_803cf238[], lbl_803cf240[], lbl_803cf248[], lbl_803cf250[], lbl_803cf260[], lbl_803cf270[], lbl_803cf280[], lbl_803ce9dc[], lbl_803ce9f0[], lbl_803cea04[], lbl_803ce988[], lbl_803cf28c[], lbl_803cf29c[], lbl_803cf2a0[], lbl_803cf2b0[];
struct Init : Obj { char u4[20]; int f24; int f28; char u32[8]; String f40; String f44; String f48; char u52[4]; int f56; char u60[4]; String f64; int f68; int f72; int f76; int f80; int f84; String f88; int f92; String f96; char u100[4]; int f104; int f108; char u112[8]; String f120; char u124[4]; String f128; String f132; int f136; char u140[4]; String f144; int f148; int f152; String f156; String f160; String f164; char u168[28]; int f196; char u200[8]; int f208; char u212[4]; String f216; int f220; int f224; int f228; int f232; int f236; char u240[24]; String f264; char u268[16]; int f284; String f288; String f292; int f296; int f300; char u304[8]; int f312; };
struct Scheme : Obj { char u4[252]; int f256; char u260[56]; int f316; int f320; int f324; };
struct Land : Obj { char u4[16]; float f20; float f24; char u28[20]; String f48; String f52; String f56; String f60; String f64; };

#define D(h, T) ((T *)(h).p)
extern "C" void d32f_start_game_mode_80281ff0(void *self, const char *mode) {
Handle h, h2;
Descriptor_80178474 d1, d2, d3;
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
const char *user;
w3d_auto_800fc2b0(lbl_803cf180, &user);
String worm(user);
{ Init *o = D(data, Init); o->f64 = String(lbl_803cf190); }
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
{ Init *o = D(data, Init); o->f160 = String(lbl_803cf1c8); }
{ Init *o = D(data, Init); o->f96 = String(lbl_803cf1d0); }
w3d_message_post_current(w3d_message_int_init_800a82f0(tsonnet_b33_arena_801613f0(lbl_804b1754, 12), names.Id(), 1));
w3d_message_post_current(w3d_message_int_init_800a82f0(tsonnet_b33_arena_801613f0(lbl_804b1754, 12), names.Id(), 2));
w3d_message_post_current(w3d_message_int_init_800a82f0(tsonnet_b33_arena_801613f0(lbl_804b1754, 12), names.Id(), 3));
w3d_message_post_current(w3d_message_int_init_800a82f0(tsonnet_b33_arena_801613f0(lbl_804b1754, 12), names.Id(), 4));
{ Init *o = D(data, Init); o->f144 = String(lbl_803cf1d4); }
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
{ Init *o = D(data, Init); o->f88 = String(lbl_803cf1d8); }
D(data, Init)->f104 = 1;
D(data, Init)->f224 = 1;
D(data, Init)->f312 = 1;
{ Init *o = D(data, Init); o->f156 = String(lbl_803cf1dc); }
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
String level;
level = sol35e2_choose_string_8027befc(lbl_804abbac, 5, r);
Cache set(lbl_803cec64);
w3d_message_post_current(w3d_message_string_init(tsonnet_b33_arena_801613f0(lbl_804b1754, 12), set.Id(), level.text));
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
Land *from = (Land *)w3d_auto_801797b4(w3d_empty_80341584(src.p));
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
case 0: { Land *o = D(to, Land); o->f52 = String(lbl_803cf218); } break;
case 1: { Land *o = D(to, Land); o->f52 = String(lbl_803cf21c); } break;
case 2: { Land *o = D(to, Land); o->f52 = String(lbl_803cf224); } break;
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
{ Init *o = D(data, Init); o->f64 = String(lbl_803cf190); }
D(data, Init)->f56 = 1;
{ Init *o = D(data, Init); o->f264 = String(lbl_803cf238); }
D(data, Init)->f28 = 0;
{ Init *o = D(data, Init); o->f144 = String(lbl_803cf240); }
D(data, Init)->f136 = 1;
{ Init *o = D(data, Init); o->f132 = String(lbl_803cf248); }
D(data, Init)->f108 = 0;
w3d_constructor_lookup_name(lbl_803cf250, h);
Handle *q = &h;
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
const char *user;
w3d_auto_800fc2b0(lbl_803cf180, &user);
String worm(user);
{ Init *o = D(data, Init); o->f64 = String(lbl_803cf190); }
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
{ Init *o = D(data, Init); o->f160 = String(lbl_803cf1c8); }
{ Init *o = D(data, Init); o->f96 = String(lbl_803cf1d0); }
w3d_message_post_current(w3d_message_int_init_800a82f0(tsonnet_b33_arena_801613f0(lbl_804b1754, 12), names.Id(), 1));
w3d_message_post_current(w3d_message_int_init_800a82f0(tsonnet_b33_arena_801613f0(lbl_804b1754, 12), names.Id(), 2));
w3d_message_post_current(w3d_message_int_init_800a82f0(tsonnet_b33_arena_801613f0(lbl_804b1754, 12), names.Id(), 3));
w3d_message_post_current(w3d_message_int_init_800a82f0(tsonnet_b33_arena_801613f0(lbl_804b1754, 12), names.Id(), 4));
{ Init *o = D(data, Init); o->f144 = String(lbl_803cf1d4); }
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
{ Init *o = D(data, Init); o->f88 = String(lbl_803cf1d8); }
D(data, Init)->f104 = 1;
D(data, Init)->f224 = 1;
D(data, Init)->f312 = 1;
{ Init *o = D(data, Init); o->f156 = String(lbl_803cf1dc); }
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
Init *init = (Init *)w3d_auto_801797b4(w3d_empty_80341584(h.p));
const char *team;
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
