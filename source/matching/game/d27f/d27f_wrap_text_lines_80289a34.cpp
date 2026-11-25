// GWMP8P rev0 0x80289a34. Wraps a text into line records on a memory card or
// text panel: loads FE.Font, walks the characters, starts a new record at
// each newline or when the next word would pass 430 units, tracks each
// line's width and count, then lays the lines out vertically with a 23 unit
// step. Same code shape as 0x800c7944 with different constants and offsets.
// Built with -mps-float. The leading 21.0 of the literal pool stays external
// because the pool starts 4 bytes past an 8-byte boundary. Names are
// inferred.
// TextBox text layout (Worms 3D GameCube PAL, 0x800c7944, 764 bytes).
//
// Line records are 20 bytes at +32, with the count at +224 (add-entry
// 0x800c7c40). Names are inferred. The word loop tests for zero twice, as the
// original's retained condition register shows.

extern float lbl_803cfa24[];
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
extern "C" int w3d_handle_load_8015adf4(const String *, ResRef *, int);
extern "C" Font *fn_80343580(Res *);
extern "C" int fn_8018c5b0(Font *, const char *);
extern "C" float fn_8018c938(Font *, int, int);
extern const char lbl_803cf9f4[];
struct Line { float x, y, width; int count; const signed char *text; };
struct TextBox;
extern "C" Line *w3d_s4_card_add_record_80289d2c(TextBox *);
struct TextBox { unsigned char u0[712]; Line lines[12]; void *slot; unsigned count; };
extern "C" void d27f_wrap_text_lines_80289a34(TextBox *self, const signed char *text, int font_id) {
    Vec3 colour(lbl_803cfa24[0], lbl_803cfa24[0], 0.0f);
    FontRef font;
    {
        String name(lbl_803cf9f4);
        ResRef res;
        w3d_handle_load_8015adf4(&name, &res, font_id);
        Font *o = fn_80343580(res.p);
        if (o) o->vt->addref(o);
        if (font.p) font.p->vt->release(font.p);
        font.p = o;
    }
    font.p->vt->colour(font.p, &colour, 0);
    fn_8018c5b0(font.p, (const char *)text);
    int i = 0;
    Line *line = w3d_s4_card_add_record_80289d2c(self);
    const signed char *p = text;
    line->text = p;
    while (*p) {
        signed char c = *p;
        if (c == 10) {
            line = w3d_s4_card_add_record_80289d2c(self);
            line->text = p + 1;
            line->y += 23.0f;
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
                if (line->width + word > 430.0f) {
                    fit = 0;
                    line = w3d_s4_card_add_record_80289d2c(self);
                    line->text = p + 1;
                    line->y += 23.0f;
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
    float y = (float)self->count * 0.5f * 23.0f;
    for (unsigned j = 0; j < self->count; j++) {
        self->lines[j].y = y;
        y -= 23.0f;
    }
}
