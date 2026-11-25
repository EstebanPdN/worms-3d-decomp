// Disc text layout (Worms 3D GameCube PAL, 0x800c7944, 764 bytes).
//
// Line records are 20 bytes at +32, with the count at +224 (add-entry
// 0x800c7c40). Names are inferred. The word loop tests for zero twice, as the
// original's retained condition register shows.

struct Vec3 {
    float x, y, z;
    Vec3(float a, float b, float c) { x = a; y = b; z = c; }
};
struct Font;
struct FontVt { void *u[3]; void (*addref)(Font *); void (*release)(Font *); void *u20[16]; void (*colour)(Font *, const Vec3 *, int); };
struct Font { FontVt *vt; };
struct FontRef {
    Font *p;
    FontRef() { p = 0; }
    ~FontRef() { if (p) p->vt->release(p); p = 0; }
};
struct String;
extern "C" void w3d_string_finish_8020c5c4(String *);
extern "C" void w3d_string_release_80341588(String *);
struct String {
    void *p;
    String(const char *);
    String(const String &);
    ~String() { w3d_string_finish_8020c5c4(this); w3d_string_release_80341588(this); }
};
struct Res;
struct ResVt { void *u[4]; void (*release)(Res *); };
struct Res { ResVt *vt; };
struct ResRef {
    Res *p;
    ResRef() { p = 0; }
    ~ResRef() { if (p) p->vt->release(p); }
};
extern "C" int w3d_handle_load_8015adf4(const String *, ResRef *, unsigned char);
extern "C" Font *fn_80343580(Res *);
extern "C" int fn_8018c5b0(Font *, const char *);
extern "C" float fn_8018c938(Font *, int, int);
extern const char lbl_803879f8[];
struct Line { float x, y, width; int count; const signed char *text; };
struct Disc;
extern "C" Line *fn_800c7c40(Disc *);
struct Disc { unsigned char u0[32]; Line lines[8]; void *slots[8]; unsigned count; };
extern "C" void w3d_d25h_disc_text_800c7944(Disc *self, const signed char *text, int font_id) {
    Vec3 colour(30.0f, 30.0f, 0.0f);
    FontRef font;
    {
        String name(lbl_803879f8);
        ResRef res;
        w3d_handle_load_8015adf4(&name, &res, font_id + 1);
        Font *o = fn_80343580(res.p);
        if (o) o->vt->addref(o);
        if (font.p) font.p->vt->release(font.p);
        font.p = o;
    }
    font.p->vt->colour(font.p, &colour, 0);
    fn_8018c5b0(font.p, (const char *)text);
    int i = 0;
    Line *line = fn_800c7c40(self);
    const signed char *p = text;
    line->text = p;
    while (*p) {
        signed char c = *p;
        if (c == 10) {
            line = fn_800c7c40(self);
            line->text = p + 1;
            line->y += 34.0f;
        } else {
            int fit = 1;
            if (c == 32) {
                float word = 0.0f;
                const signed char *q = p + 1;
                signed char d = *q;
                while (d != 32 && d != 0 && d != 10 && d != 0) {
                    word += fn_8018c938(font.p, i, 1);
                    d = *++q;
                }
                if (line->width + word > 400.0f) {
                    fit = 0;
                    line = fn_800c7c40(self);
                    line->text = p + 1;
                    line->y += 34.0f;
                }
            }
            if (fit) {
                float w = fn_8018c938(font.p, i, 1);
                line->count++;
                line->width += w;
            }
        }
        p++;
        i++;
    }
    float y = (float)self->count * 0.5f * 34.0f;
    for (unsigned j = 0; j < self->count; j++) {
        self->lines[j].y = y;
        y -= 34.0f;
    }
}
