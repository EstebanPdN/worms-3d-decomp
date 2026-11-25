// Landscape settings save (Worms 3D GameCube PAL, 0x8026bdf0).
// 
// Writes the seven FE.Land integer settings, formats and stores the seed in FE.Land.Seed and stores
// the theme's lump name in FE.Land.Theme, with the busy flag at +496 set during the writes.

struct String_803426b8;
extern "C" void assign_8020bd38(String_803426b8 *, const char *);
extern "C" void string_finish_8020c5c4(String_803426b8 *);
extern "C" void string_release_80341588(String_803426b8 *);
struct String_803426b8 {
    char *text;
    String_803426b8();
    const char *c_str() const { return text; }
    String_803426b8 &operator=(const char *t) { assign_8020bd38(this, t); return *this; }
    String_803426b8(const String_803426b8 &);
    ~String_803426b8() {
        string_finish_8020c5c4(this);
        string_release_80341588(this);
    }
};
struct Key { const char *name; };
struct Land { int w0; int theme; int w8; int bridges; int sobjects; int lobjects; int amount; int space; int size; int height; };
struct Menu { char pad0[312]; Land land; char pad1[496 - 352]; int busy; };
extern "C" void format_8020c510(String_803426b8 *, const char *, ...);
extern "C" void assign_8020bd38(String_803426b8 *, const char *);
extern "C" int write_800fc43c(Key *, int);
extern "C" int read_800fc550(Key *, char *);
extern "C" int seed_8026ce4c(Land *);
extern const char text_803cb8f8[], text_803cb908[], text_803cb918[], text_803cb92c[], text_803cb940[], text_803cb960[], text_803cb970[], text_803cb8d0[], text_803cb950[], text_803cb990[];
extern const char text_803cb9a0[], text_803cb9b0[], text_803cb80c[], text_803cb9bc[], text_803cb9cc[], text_803cb9dc[];
#define PUT(t, v) { Key k; k.name = t; write_800fc43c(&k, v); }
extern "C" void w3d_d27k_land_settings_save_8026bdf0(Menu *self) {
    self->busy = 1;
    String_803426b8 text;
    String_803426b8 unused;
    Land *land = &self->land;
    PUT(text_803cb8f8, land->amount)
    PUT(text_803cb908, land->bridges)
    PUT(text_803cb918, land->lobjects)
    PUT(text_803cb92c, land->sobjects)
    PUT(text_803cb940, land->size)
    PUT(text_803cb960, land->space)
    PUT(text_803cb970, land->height)
    format_8020c510(&text, text_803cb8d0, seed_8026ce4c(land));
    { Key k; k.name = text_803cb950; read_800fc550(&k, const_cast<char *>(text.c_str())); }
    switch (land->theme) {
    case 0: text = text_803cb9a0; break;
    case 1: text = text_803cb9b0; break;
    case 2: text = text_803cb80c; break;
    case 3: text = text_803cb9bc; break;
    case 4: text = text_803cb9cc; break;
    case 5: text = text_803cb9dc; break;
    }
    { Key k; k.name = text_803cb990; read_800fc550(&k, const_cast<char *>(text.c_str())); }
    self->busy = 0;
}
