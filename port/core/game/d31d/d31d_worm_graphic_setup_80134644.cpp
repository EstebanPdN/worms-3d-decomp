#include "w3d_ptr.h"
#line 1 "d31d_worm_graphic_setup_80134644.cpp"
// GWMP8P rev0 0x80134644. Worm graphic entity setup: subscribes to its messages,
// binds properties, creates the three worm parts, plays the first clip, finds
// the aim and locator clips and creates the name pot. Names are read from the
// strings in the original; others are inferred from use. Virtual slots are
// reference-ABI observations.
struct Vec { float x, y, z; void init(float a, float b, float c) { x = a; y = b; z = c; } };
struct Rgba { float r, g, b, a; Rgba(float v, float w) { r = v; g = v; b = v; a = w; } };
struct Obj;
struct ObjVt { char u0[12]; Ptr32<void (Ptr32<Obj>)> retain; Ptr32<void (Ptr32<Obj>)> release; };
struct Obj { Ptr32<ObjVt> vt; };
struct Ref {
    Ptr32<Obj> p;
    Ref() { p = 0; }
    Ref(const Ref &);
    ~Ref() { if (p) p->vt->release(p); }
    template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((Obj *)w3d_p.get()); }
 void operator=(Obj *q) {
        if (q) q->vt->retain(q);
        if (p) p->vt->release(p);
        p = q;
    }
};
extern "C" {
struct String;
void string_finish_8020c5c4(Ptr32<String>);
void string_release_80341588(Ptr32<String>);
}
struct String {
    Ptr32<void> rep;
    template <class W3dU> String(Ptr32<W3dU> w3d_p) : String((const char *)w3d_p.get()) {}
 String(const char *);
    String(const String &);
    ~String() { string_finish_8020c5c4(this); string_release_80341588(this); }
};
struct Event { unsigned short id; };
struct Mesh;
struct MeshVt { char u0[76]; Ptr32<void (Ptr32<Mesh>, Ptr32<void>, int)> scale; char u50[4]; Ptr32<void (Ptr32<Mesh>, Ptr32<void>, int)> vec; char u58[4]; Ptr32<void (Ptr32<Mesh>, Ptr32<Obj>, Ptr32<const char>)> locate; };
struct Mesh { Ptr32<MeshVt> vt; };
struct Info { char u0[68]; Vec v68; char u50[60]; int f140; char u90[26]; unsigned short hp; char uac[12]; int f184; char uc0[25]; unsigned char team; char ud6[46]; int f260; };
struct Tag { char u[4]; unsigned char bits; char w3d_tag_rest[3]; void set2() { bits |= 2; } };
struct Clip { char u0[4]; Tag tag; char u0c[96]; int f108; };
struct Worm {
    Ptr32<void> vt;
     char u4[16]; int f20; char u24[4]; Ref f28; int f32; int f36; int f40[3]; Vec f52; Vec f64; char u76[8]; int f84; char u88[4]; int f92; int f96; int f100; int f104; Ref f108; int f112; char u116[8]; Vec f124; int f136; char u140[28]; Ref f168; int f172; float f176; float f180; int f184; int f188; int f192; int f196; int f200; int f204; int f208; int f212; int f216; int f220; int f224; int f228; int f232; int f236; int f240; int f244; int f248; int f252; int f256; int f260; int f264; int f268; int f272; int f276; int f280; int f284; char u288[4]; int f292; int f296; int f300; int f304; int f308; int f312; int f316; int f320; int f324; int f328; int f332; int f336; int f340; int f344; int f348; int f352; int f356; char u360[4]; int f364; int f368; int f372; int f376; int f380; int f384; int f388; int f392; int f396; int f400; int f404; int f408; int f412; int f416; int f420; int f424; int f428; int f432; int f436; int f440; int f444; int f448; int f452; int f456; int f460; int f464; int f468; char u472[20]; int f492; int f496; char u500[12]; Vec f512; char u524[36]; int f560; int f564; int f568; char u572[28]; int f600; char u604[32]; int f636; int f640; int f644; char u648[52]; Ref f700; Ref f704; Ref f708; Ref f712; Ref f716; int f720; char u724[8]; int f732; int f736;
};
extern "C" {
int bind_800fc1b0(Ptr32<Ptr32<const char>>, Ptr32<void>);
int bind_float_800fc270(Ptr32<Ptr32<const char>>, Ptr32<float>);
int bind_vec_800fc2f0(Ptr32<Ptr32<const char>>, Ptr32<Vec>);
unsigned short message_id_8015f5a0(Ptr32<int>, int);
int subscribe_80162024(Ptr32<void>, Ptr32<unsigned short>, Ptr32<void>);
Ptr32<Obj> cast_80342a74(Ptr32<Obj>);
Ptr32<Obj> cast_80342a78(Ptr32<Obj>);
Ptr32<Obj> cast_80343584(Ptr32<Obj>);
int set_name_8015adf4(String &, Ptr32<void>, int);
int set_tint_80182178(Ptr32<void>, Ptr32<Rgba>);
int play_clip_80181640(Ptr32<Mesh>, Ptr32<const char>, Ptr32<void>, float, float, float, int);
Ptr32<Clip> unbind_80181e18(Ptr32<Mesh>);
int find_clip_80181598(Ptr32<Mesh>, Ptr32<const char>, Ptr32<void>);
Ptr32<Info> query_800fc6dc(int);
Ptr32<void> create_8020b680(Ptr32<void>);
int send_80164514(Ptr32<void>, Ptr32<void>, int);
Ptr32<void> lookup_80164fc8(int);
void pot_apply_80140dc4(Ptr32<void>, int);
void pot_text_80140d80(Ptr32<void>, int);
void pot_set_80140d78(Ptr32<void>, int);
void pot_pair_80140f70(Ptr32<void>, int, int);
int value_80178d1c(Ptr32<Obj>);
void lights_80139a04(Ptr32<Worm>);
int set_resource_80182410(Ptr32<Obj>, int);
void update_8013c890(Ptr32<Worm>, int);
void slot_801262e4(Ptr32<void>, int);
void word_8012632c(Ptr32<void>, int);
void query_8012629c(Ptr32<void>, float);
void query_80126308(Ptr32<void>, int);
void query_801262c0(Ptr32<void>, Ptr32<void>);
void activate_80126548(Ptr32<void>);
}
extern Ptr32<void> service_804b178c;
extern char desc_80410eb0[];
extern Ptr32<const char> anim_804ab100; extern Ptr32<const char> anim_804ab314; extern Ptr32<const char> anim_804ab318; extern Ptr32<const char> anim_804ab1c8; extern Ptr32<const char> anim_804ab1cc; extern Ptr32<const char> anim_804ab374;
extern int clip_804ab3b8, clip_804ab3b4;
extern const char str_8039f240[];
extern const char str_8039f250[];
extern const char str_8039f268[];
extern const char str_8039f284[];
extern const char str_8039f294[];
extern const char str_8039f2a4[];
extern const char str_8039f2b0[];
extern const char str_8039f2c4[];
extern const char str_8039f2d0[];
extern const char str_8039f2dc[];
extern const char str_8039f2e8[];
extern const char str_8039f2f0[];
extern const char str_8039f2fc[];
extern const char str_8039f31c[];
extern const char str_8039f33c[];
extern const char str_8039f354[];
extern const char str_8039f370[];
extern const char str_8039f37c[];
extern const char str_8039f38c[];
extern int cache_804af8b0;
extern int cache_804af8a8;
extern int cache_804af7f8;
extern int cache_804af818;
extern int cache_804af820;
extern int cache_804af960;
extern int cache_804af968;
extern int cache_804af970;
extern int cache_804af978;
extern int cache_804af980;
extern int cache_804af988;
extern int cache_804af828;
extern int cache_804af800;
extern int cache_804af808;
extern int cache_804af848;
extern int cache_804af850;
extern int cache_804af858;
extern int cache_804af898;
extern int cache_804af8a0;
extern int cache_804af810;
extern int cache_804af870;
extern int cache_804af878;
extern int cache_804af880;
extern int cache_804af860;
extern int cache_804af868;
extern int cache_804af888;
extern int cache_804af890;
extern int cache_804af8b8;
extern int cache_804af8c0;
extern int cache_804af8c8;
extern int cache_804af8d0;
extern int cache_804af8d8;
extern int cache_804af8e0;
extern int cache_804af8e8;
extern int cache_804af8f0;
extern int cache_804af8f8;
extern int cache_804af900;
extern int cache_804af908;
extern int cache_804af910;
extern int cache_804af918;
extern int cache_804af920;
extern int cache_804af928;
extern int cache_804af930;
extern int cache_804af938;
extern int cache_804af940;
extern int cache_804af948;
extern int cache_804af950;
extern int cache_804af958;
extern int cache_804af990;
extern int cache_804af998;
extern int cache_804af9a0;
extern int cache_804af9a8;
extern int cache_804af9b0;
extern int cache_804af9c0;
extern int cache_804af9c8;
extern int cache_804af9d0;
extern int cache_804af9d8;
extern int cache_804af9e0;
extern int cache_804af9e8;
extern int cache_804af9f0;
extern int cache_804af9f8;
extern int cache_804afa00;
extern int cache_804afa08;
extern int cache_804afa10;
extern int cache_804afa18;
extern int cache_804afa20;
extern int cache_804afa28;
extern int cache_804afa30;
extern int cache_804afa38;
extern int cache_804afa40;
extern "C" void w3d_d31d_worm_graphic_setup_80134644(Ptr32<Worm> self) {
    int zero = 0;
    Event e0; e0.id = message_id_8015f5a0(&cache_804af8b0, 1); subscribe_80162024(self, &e0.id, &self->f192);
    Event e1; e1.id = message_id_8015f5a0(&cache_804af8a8, 1); subscribe_80162024(self, &e1.id, &self->f196);
    Event e2; e2.id = message_id_8015f5a0(&cache_804af7f8, 1); subscribe_80162024(self, &e2.id, &self->f200);
    Event e3; e3.id = message_id_8015f5a0(&cache_804af818, 1); subscribe_80162024(self, &e3.id, &self->f204);
    Event e4; e4.id = message_id_8015f5a0(&cache_804af820, 1); subscribe_80162024(self, &e4.id, &self->f212);
    Event e5; e5.id = message_id_8015f5a0(&cache_804af960, 1); subscribe_80162024(self, &e5.id, &self->f216);
    Event e6; e6.id = message_id_8015f5a0(&cache_804af968, 1); subscribe_80162024(self, &e6.id, &self->f224);
    Event e7; e7.id = message_id_8015f5a0(&cache_804af970, 1); subscribe_80162024(self, &e7.id, &self->f220);
    Event e8; e8.id = message_id_8015f5a0(&cache_804af978, 1); subscribe_80162024(self, &e8.id, &self->f228);
    Event e9; e9.id = message_id_8015f5a0(&cache_804af980, 1); subscribe_80162024(self, &e9.id, &self->f232);
    Event e10; e10.id = message_id_8015f5a0(&cache_804af988, 1); subscribe_80162024(self, &e10.id, &self->f236);
    Event e11; e11.id = message_id_8015f5a0(&cache_804af828, 1); subscribe_80162024(self, &e11.id, &self->f240);
    Event e12; e12.id = message_id_8015f5a0(&cache_804af800, 1); subscribe_80162024(self, &e12.id, &self->f188);
    Event e13; e13.id = message_id_8015f5a0(&cache_804af808, 1); subscribe_80162024(self, &e13.id, &self->f184);
    Event e14; e14.id = message_id_8015f5a0(&cache_804af848, 1); subscribe_80162024(self, &e14.id, &self->f244);
    Event e15; e15.id = message_id_8015f5a0(&cache_804af850, 1); subscribe_80162024(self, &e15.id, &self->f248);
    Event e16; e16.id = message_id_8015f5a0(&cache_804af858, 1); subscribe_80162024(self, &e16.id, &self->f252);
    Event e17; e17.id = message_id_8015f5a0(&cache_804af898, 1); subscribe_80162024(self, &e17.id, &self->f280);
    Event e18; e18.id = message_id_8015f5a0(&cache_804af8a0, 1); subscribe_80162024(self, &e18.id, &self->f284);
    Event e19; e19.id = message_id_8015f5a0(&cache_804af810, 1); subscribe_80162024(self, &e19.id, &self->f208);
    Event e20; e20.id = message_id_8015f5a0(&cache_804af870, 1); subscribe_80162024(self, &e20.id, &self->f264);
    Event e21; e21.id = message_id_8015f5a0(&cache_804af878, 1); subscribe_80162024(self, &e21.id, &self->f268);
    Event e22; e22.id = message_id_8015f5a0(&cache_804af880, 1); subscribe_80162024(self, &e22.id, &self->f272);
    Event e23; e23.id = message_id_8015f5a0(&cache_804af860, 1); subscribe_80162024(self, &e23.id, &self->f256);
    Event e24; e24.id = message_id_8015f5a0(&cache_804af868, 1); subscribe_80162024(self, &e24.id, &self->f260);
    Event e25; e25.id = message_id_8015f5a0(&cache_804af888, 1); subscribe_80162024(self, &e25.id, &self->f276);
    Event e26; e26.id = message_id_8015f5a0(&cache_804af890, 1); subscribe_80162024(self, &e26.id, &self->f464);
    Event e27; e27.id = message_id_8015f5a0(&cache_804af8b8, 1); subscribe_80162024(self, &e27.id, &self->f296);
    Event e28; e28.id = message_id_8015f5a0(&cache_804af8c0, 1); subscribe_80162024(self, &e28.id, &self->f292);
    Event e29; e29.id = message_id_8015f5a0(&cache_804af8c8, 1); subscribe_80162024(self, &e29.id, &self->f300);
    Event e30; e30.id = message_id_8015f5a0(&cache_804af8d0, 1); subscribe_80162024(self, &e30.id, &self->f304);
    Event e31; e31.id = message_id_8015f5a0(&cache_804af8d8, 1); subscribe_80162024(self, &e31.id, &self->f308);
    Event e32; e32.id = message_id_8015f5a0(&cache_804af8e0, 1); subscribe_80162024(self, &e32.id, &self->f312);
    Event e33; e33.id = message_id_8015f5a0(&cache_804af8e8, 1); subscribe_80162024(self, &e33.id, &self->f316);
    Event e34; e34.id = message_id_8015f5a0(&cache_804af8f0, 1); subscribe_80162024(self, &e34.id, &self->f320);
    Event e35; e35.id = message_id_8015f5a0(&cache_804af8f8, 1); subscribe_80162024(self, &e35.id, &self->f324);
    Event e36; e36.id = message_id_8015f5a0(&cache_804af900, 1); subscribe_80162024(self, &e36.id, &self->f328);
    Event e37; e37.id = message_id_8015f5a0(&cache_804af908, 1); subscribe_80162024(self, &e37.id, &self->f332);
    Event e38; e38.id = message_id_8015f5a0(&cache_804af910, 1); subscribe_80162024(self, &e38.id, &self->f336);
    Event e39; e39.id = message_id_8015f5a0(&cache_804af918, 1); subscribe_80162024(self, &e39.id, &self->f340);
    Event e40; e40.id = message_id_8015f5a0(&cache_804af920, 1); subscribe_80162024(self, &e40.id, &self->f344);
    Event e41; e41.id = message_id_8015f5a0(&cache_804af928, 1); subscribe_80162024(self, &e41.id, &self->f348);
    Event e42; e42.id = message_id_8015f5a0(&cache_804af930, 1); subscribe_80162024(self, &e42.id, &self->f352);
    Event e43; e43.id = message_id_8015f5a0(&cache_804af938, 1); subscribe_80162024(self, &e43.id, &self->f356);
    Event e44; e44.id = message_id_8015f5a0(&cache_804af940, 1); subscribe_80162024(self, &e44.id, &self->f364);
    Event e45; e45.id = message_id_8015f5a0(&cache_804af948, 1); subscribe_80162024(self, &e45.id, &self->f372);
    Event e46; e46.id = message_id_8015f5a0(&cache_804af950, 1); subscribe_80162024(self, &e46.id, &self->f368);
    Event e47; e47.id = message_id_8015f5a0(&cache_804af958, 1); subscribe_80162024(self, &e47.id, &self->f376);
    Event e48; e48.id = message_id_8015f5a0(&cache_804af990, 1); subscribe_80162024(self, &e48.id, &self->f380);
    Event e49; e49.id = message_id_8015f5a0(&cache_804af998, 1); subscribe_80162024(self, &e49.id, &self->f384);
    Event e50; e50.id = message_id_8015f5a0(&cache_804af9a0, 1); subscribe_80162024(self, &e50.id, &self->f388);
    Event e51; e51.id = message_id_8015f5a0(&cache_804af9a8, 1); subscribe_80162024(self, &e51.id, &self->f392);
    Event e52; e52.id = message_id_8015f5a0(&cache_804af9b0, 1); subscribe_80162024(self, &e52.id, &self->f396);
    Event e53; e53.id = message_id_8015f5a0(&cache_804af9c0, 1); subscribe_80162024(self, &e53.id, &self->f400);
    Event e54; e54.id = message_id_8015f5a0(&cache_804af9c8, 1); subscribe_80162024(self, &e54.id, &self->f416);
    Event e55; e55.id = message_id_8015f5a0(&cache_804af9d0, 1); subscribe_80162024(self, &e55.id, &self->f404);
    Event e56; e56.id = message_id_8015f5a0(&cache_804af9d8, 1); subscribe_80162024(self, &e56.id, &self->f408);
    Event e57; e57.id = message_id_8015f5a0(&cache_804af9e0, 1); subscribe_80162024(self, &e57.id, &self->f412);
    Event e58; e58.id = message_id_8015f5a0(&cache_804af9e8, 1); subscribe_80162024(self, &e58.id, &self->f420);
    Event e59; e59.id = message_id_8015f5a0(&cache_804af9f0, 1); subscribe_80162024(self, &e59.id, &self->f424);
    Event e60; e60.id = message_id_8015f5a0(&cache_804af9f8, 1); subscribe_80162024(self, &e60.id, &self->f428);
    Event e61; e61.id = message_id_8015f5a0(&cache_804afa00, 1); subscribe_80162024(self, &e61.id, &self->f432);
    Event e62; e62.id = message_id_8015f5a0(&cache_804afa08, 1); subscribe_80162024(self, &e62.id, &self->f436);
    Event e63; e63.id = message_id_8015f5a0(&cache_804afa10, 1); subscribe_80162024(self, &e63.id, &self->f440);
    Event e64; e64.id = message_id_8015f5a0(&cache_804afa18, 1); subscribe_80162024(self, &e64.id, &self->f444);
    Event e65; e65.id = message_id_8015f5a0(&cache_804afa20, 1); subscribe_80162024(self, &e65.id, &self->f448);
    Event e66; e66.id = message_id_8015f5a0(&cache_804afa28, 1); subscribe_80162024(self, &e66.id, &self->f452);
    Event e67; e67.id = message_id_8015f5a0(&cache_804afa30, 1); subscribe_80162024(self, &e67.id, &self->f456);
    Event e68; e68.id = message_id_8015f5a0(&cache_804afa38, 1); subscribe_80162024(self, &e68.id, &self->f460);
    Event e69; e69.id = message_id_8015f5a0(&cache_804afa40, 1); subscribe_80162024(self, &e69.id, &self->f468);
    self->f736 = 1;
    self->f560 = zero;
    self->f564 = zero;
    self->f568 = zero;
    Ptr32<const char> n0 = str_8039f240; bind_800fc1b0(&n0, &self->f84);
    Ptr32<const char> r0 = str_8039f250; { Ref t; bind_800fc1b0(&r0, &t); self->f700 = cast_80342a74(t.p); }
    Ptr32<const char> r1 = str_8039f268; { Ref t; bind_800fc1b0(&r1, &t); self->f704 = cast_80342a74(t.p); }
    Ptr32<const char> r2 = str_8039f284; { Ref t; bind_800fc1b0(&r2, &t); self->f708 = cast_80342a78(t.p); }
    Ptr32<const char> r3 = str_8039f294; { Ref t; bind_800fc1b0(&r3, &t); self->f712 = cast_80342a78(t.p); }
    Ptr32<const char> r4 = str_8039f2a4; { Ref t; bind_800fc1b0(&r4, &t); self->f716 = cast_80342a78(t.p); }
    Ptr32<const char> r5 = str_8039f2b0; { Ref t; bind_800fc1b0(&r5, &t); self->f108 = cast_80342a78(t.p); }
    Rgba tint(0.0f, 0.2f);
    for (unsigned i = 0; i < 3; i++) {
        Ptr32<int> part;
 do { part = &self->f40[i]; } while (0);
 {String name(str_8039f2c4);
            set_name_8015adf4(name, part, 255);} set_tint_80182178((Ptr32<void>)w3d::G((*part)), &tint);
    }
    {
        String name(str_8039f2d0);
        Ptr32<String> n = &name;
        Ref t;
        set_name_8015adf4(*n, &t, 255);
        self->f28 = cast_80343584(t.p);
    }
    Ptr32<Mesh> mesh;
    play_clip_80181640((Ptr32<Mesh>)self->f28.p, anim_804ab100, &self->f492, 1.0f, 0.0f, 0.0f, 0);
    Ptr32<Clip> c = unbind_80181e18((Ptr32<Mesh>)self->f28.p);
    c->f108 = 3;
    c->tag.set2();
    find_clip_80181598((Ptr32<Mesh>)self->f28.p, anim_804ab314, &self->f636);
    find_clip_80181598((Ptr32<Mesh>)self->f28.p, anim_804ab318, &self->f640);
    find_clip_80181598((Ptr32<Mesh>)self->f28.p, str_8039f2dc, &self->f644);
    find_clip_80181598((Ptr32<Mesh>)self->f28.p, anim_804ab1c8, &clip_804ab3b8);
    find_clip_80181598((Ptr32<Mesh>)self->f28.p, anim_804ab1cc, &clip_804ab3b4);
    {
        String none(str_8039f2e8);
        set_name_8015adf4(none, &self->f172, 255);
    }
    ((Ptr32<Mesh>)self->f28.p)->vt->locate((Ptr32<Mesh>)self->f28.p, (Ptr32<Obj>)w3d::G(self->f172), str_8039f2f0);
    Ptr32<Info> record = query_800fc6dc(self->f112);
    Ptr32<const char> w0 = str_8039f2fc; bind_800fc1b0(&w0, &self->f92);
    Ptr32<const char> w1 = str_8039f31c; bind_800fc1b0(&w1, &self->f96);
    Ptr32<const char> w2 = str_8039f33c; bind_800fc1b0(&w2, &self->f100);
    Ptr32<const char> w3 = str_8039f354; bind_800fc1b0(&w3, &self->f104);
    self->f52.init(0.0f, 0.0f, 0.0f);
    Ptr32<const char> w4 = str_8039f370;
    float scale;
    bind_float_800fc270(&w4, &scale);
    Vec v;
    v.x = scale; v.y = scale; v.z = scale;
    mesh = (Ptr32<Mesh>)self->f28.p;
    mesh->vt->vec(mesh, &v, 0);
    ((Ptr32<Mesh>)self->f28.p)->vt->scale((Ptr32<Mesh>)self->f28.p, &self->f52, 0);
    self->f124 = self->f52;
    Ptr32<void> entry = create_8020b680(desc_80410eb0);
    self->f136 = send_80164514(service_804b178c, entry, self->f20);
    Ptr32<void> pot = lookup_80164fc8(self->f136);
    Ptr32<Info> info = query_800fc6dc(self->f112);
    pot_apply_80140dc4(pot, info->team);
    pot_text_80140d80(pot, info->f140);
    pot_set_80140d78(pot, info->hp);
    int health = value_80178d1c(self->f712.p) != 0;
    int shown = value_80178d1c(self->f708.p) != 0;
    pot_pair_80140f70(pot, health, shown);
    Ptr32<const char> sun = str_8039f37c; bind_vec_800fc2f0(&sun, &self->f512);
    lights_80139a04(self);
    if (record->f184) {
        {
            String hat(anim_804ab374);
            Ref t;
            set_name_8015adf4(hat, &t, 255);
            self->f168 = cast_80343584(t.p);
        }
        ((Ptr32<Mesh>)self->f28.p)->vt->locate((Ptr32<Mesh>)self->f28.p, self->f168.p, str_8039f38c);
        set_resource_80182410(self->f168.p, self->f600);
    } else if (record->f260) {
        self->f732 = 1;
        self->f496 = 37;
        update_8013c890(self, 1);
    }
    self->f64 = info->v68;
    slot_801262e4(&self->f720, 0);
    word_8012632c(&self->f720, 8);
    query_8012629c(&self->f720, 170.0f);
    query_80126308(&self->f720, self->f20);
    query_801262c0(&self->f720, &self->f52);
    activate_80126548(&self->f720);
    {
        String none(str_8039f2e8);
        set_name_8015adf4(none, &self->f32, 255);
    }
    {
        String none(str_8039f2e8);
        set_name_8015adf4(none, &self->f36, 255);
    }
    self->f176 = 0.0f;
    self->f180 = 0.0f;
}


