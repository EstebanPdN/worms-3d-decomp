#include "w3d_ptr.h"
#line 1 "d28k_land_menu_start_802691fc.cpp"
// Landscape menu start (Worms 3D GameCube PAL, 0x802691fc).
// Connects the panel, reads the game data named at settings +156 with a watcher or an error
// text, reads Land.Finished and FE.TextBoxBackground, loads the Back overlay, and the Changing
// overlay when scaled, reads FE.Land.RealSeed or generates a seed, applies and saves the
// settings, builds the menu and subscribes to two messages. Names are inferred from the strings.

struct String_803426b8;
extern "C" void string_finish_8020c5c4(Ptr32<String_803426b8>);
extern "C" void string_release_80341588(Ptr32<String_803426b8>);
extern "C" void string_init_8020c5c0(Ptr32<String_803426b8>);
extern "C" Ptr32<unsigned short> string_header_80341884(Ptr32<String_803426b8>);
struct String_803426b8 {
    Ptr32<char> text;
    String_803426b8();
    template <class W3dU> String_803426b8(Ptr32<W3dU> w3d_p) : String_803426b8((const char *)w3d_p.get()) {}
 String_803426b8(const char *);
    String_803426b8(const String_803426b8 &o) {
        string_init_8020c5c0(this);
        text = o.text;
        ++*string_header_80341884(this);
    }
    ~String_803426b8() {
        string_finish_8020c5c4(this);
        string_release_80341588(this);
    }
};
struct Object;
struct ObjectTable { Ptr32<void> pad[3]; Ptr32<void (Ptr32<Object>)> addRef; Ptr32<void (Ptr32<Object>)> release; Ptr32<void> p5[14]; Ptr32<void (Ptr32<Object>, Ptr32<const void>, int)> colour; Ptr32<void> p20; Ptr32<void (Ptr32<Object>, Ptr32<const void>, int)> size; Ptr32<void (Ptr32<Object>, int)> mode; Ptr32<void (Ptr32<Object>, Ptr32<Object>, int)> add; };
struct Object { Ptr32<ObjectTable> table; };
struct Holder {
    Ptr32<Object> p;
    Holder() : p(0) {}
    Holder(const Holder &);
    ~Holder() { if (p) p->table->release(p); }
};
struct Key { Ptr32<const char> name; template <class W3dU> Key(Ptr32<W3dU> w3d_p) : Key((const char *)w3d_p.get()) {}
 Key(const char *n) : name(n) {} };
struct Settings { char pad0[116]; float scale[3]; float colour[2]; char pad1[156 - 136]; Ptr32<char> name; };
struct Context { char pad[52]; int service; };
struct Land { char pad0[28]; char panel[4]; unsigned char index; char w3d_tag_rest[3]; char pad1[4]; Ptr32<Settings> settings; char pad2[108 - 44]; String_803426b8 error; Ptr32<Object> scene; char pad3[212 - 116]; char info[72]; Ptr32<Object> back; char pad4[296 - 288]; Ptr32<Object> changing; Ptr32<Object> box; float a, b; char land[496 - 312 - 0]; int busy; };
extern "C" Ptr32<Context> engine_80165254();
extern "C" void panel_802b0b84(Ptr32<void>, Ptr32<Land>, int);
extern "C" int lookup_800fc1b0(const Key &, Ptr32<void>);
extern "C" void format_8020c510(Ptr32<String_803426b8>, Ptr32<const char>, ...);
extern "C" void watch_800fd62c(Ptr32<Ptr32<char>>, Ptr32<void>, Ptr32<Land>, Ptr32<void>);
extern "C" int land_callback_80269994(Ptr32<void>, Ptr32<void>);
extern "C" Ptr32<Object> cast_80343df4(Ptr32<Object>);
extern "C" Ptr32<Object> cast_8034357c(Ptr32<Object>);
extern "C" Ptr32<int> value_80178f54(Ptr32<Object>);
extern "C" int load_8015adf4(Ptr32<String_803426b8>, Ptr32<Holder>, unsigned char);
extern "C" int store_80173f88(Ptr32<Object>, const unsigned char &);
extern "C" int read_800fc230(const Key &, Ptr32<int>);
extern "C" int write_800fc43c(const Key &, int);
extern "C" int random_8026cd1c(Ptr32<void>, Ptr32<String_803426b8>);
extern "C" Ptr32<void> apply_8026c8a8(Ptr32<void>, Ptr32<char>);
extern "C" void save_8026bdf0(Ptr32<Land>);
extern "C" void build_8026a16c(Ptr32<Land>);
struct Cache;
extern "C" unsigned short cached_8015f5a0(Ptr32<Cache>, int);
extern "C" int acquire_80162024(Ptr32<Land>, const unsigned short &, Ptr32<void>);
extern const char text_803cb850[], text_803cb874[], text_803cb884[], text_803cb89c[], text_803cb8ac[], text_803cb8bc[], text_803cb8d0[];
extern float zero_803cb8f4[];
struct Cache { int a, b; };
extern Cache cache_804b0ac4, cache_804b0acc;
inline void sink(String_803426b8) {}
template <class T> inline void set(Ptr32<T> &slot, Ptr32<Object> o) {
 if (o) o->table->addRef(o);
 if (slot) slot->table->release(slot);
 slot = o;
}
inline void fresh(Ptr32<Land> self, Ptr32<char> land, Ptr32<String_803426b8> t, Ptr32<const char> key, int &seed, int on) {
 seed = random_8026cd1c(land, t);
 self->busy = on;
 write_800fc43c(Key(key), seed);
 self->busy = on;
}
extern "C" void w3d_d28k_land_menu_start_802691fc(Ptr32<Land> self) {
 panel_802b0b84(self->panel, self, engine_80165254()->service);
 Ptr32<Settings> s = self->settings;
 Holder bg;
 Ptr32<Ptr32<char>> name = &s->name;
 if (*(Ptr32<unsigned short>)(s->name - 4)) {
  if (lookup_800fc1b0(Key(s->name), &bg) < 0) {
   sink(*(Ptr32<String_803426b8>)&s->name);
   format_8020c510(&self->error, text_803cb850, w3d::VA(s->name));
  } else watch_800fd62c(name, (Ptr32<void>)land_callback_80269994, self, self->info);
 }
 lookup_800fc1b0(Key(text_803cb874), (Ptr32<char>)self + 408);
 lookup_800fc1b0(Key(text_803cb884), &bg);
 {
  Ptr32<Object> o = cast_80343df4(bg.p);
  set(self->box, o);
  { int v = *value_80178f54(o); self->b = self->a = (float)(unsigned char)v; }
 }
 Ptr32<float> sc;
 {
  String_803426b8 t(text_803cb89c);
  {
   Holder h;
   load_8015adf4(&t, &h, self->index + 29);
   Ptr32<Object> o = cast_8034357c(h.p);
   set(self->back, o);
  }
  sc = s->scale;
 }
 self->scene->table->add(self->scene, self->back, 0);
 self->back->table->mode(self->back, 0);
 if (s->scale[0] != zero_803cb8f4[0]) {
  {
   String_803426b8 t(text_803cb8ac);
   Holder h;
   load_8015adf4(&t, &h, self->index + 32);
   Ptr32<Object> o = cast_8034357c(h.p);
   set(self->changing, o);
  }
  self->scene->table->add(self->scene, self->changing, 0);
  self->changing->table->mode(self->changing, 0);
  store_80173f88(self->changing, 0);
  self->changing->table->colour(self->changing, s->colour, 0);
  self->changing->table->size(self->changing, sc, 0);
 }
 int seed;
 Ptr32<const char> key = text_803cb8bc;
 read_800fc230(Key(key), &seed);
 String_803426b8 text;
 Ptr32<char> l;
 if (!seed) {
  Ptr32<char> land = self->land;
  fresh(self, land, &text, key, seed, 1);
  l = land;
 } else {
  format_8020c510(&text, text_803cb8d0, seed);
  l = self->land;
 }
 apply_8026c8a8(l, text.text);
 save_8026bdf0(self);
 build_8026a16c(self);
 *(Ptr32<int>)((Ptr32<char>)self + 440) = 1;
 *(Ptr32<int>)((Ptr32<char>)self + 448) = 1;
 acquire_80162024(self, cached_8015f5a0(&cache_804b0ac4, 1), (Ptr32<char>)self + 504);
 acquire_80162024(self, cached_8015f5a0(&cache_804b0acc, 1), (Ptr32<char>)self + 508);
 *(Ptr32<int>)((Ptr32<char>)self + 420) = engine_80165254()->service;
}


