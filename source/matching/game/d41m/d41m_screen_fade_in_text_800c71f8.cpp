// GWMP8P rev0 0x800c71f8. Text screen fade-in. Marks the screen busy, loads
// the FE.Textbox.Back box if missing, places it, builds the text lines
// (dollar signs become spaces) with an FE.Font box per line, fades all
// colours in over 30 frames, then presents the screen. Built with -mfast-
// cast and -mps-float. Names are inferred.
struct Vec3 { float x, y, z; void Set(float a, float b, float c) { Vec3 *p = this; x = a; p->y = b; p->z = c; } };
struct Colour { signed char r, g, b; unsigned char a; void Set(int x, int y, int z, int w) { Colour *p = this; r = x; p->g = y; p->b = z; p->a = w; } };
struct Font;
struct FontVt { void *u[3]; void (*addref)(Font *); void (*release)(Font *); void *u20[14]; void (*offset)(Font *, const Vec3 *, int); void *u80; void (*place)(Font *, const Vec3 *, int); };
struct Font { FontVt *vt; };
struct FontRef {
    Font *p;
    FontRef() { p = 0; }
    FontRef(const FontRef &);
    ~FontRef() { if (p) p->vt->release(p); }
    operator Font *() const { return p; }
    Font *operator->() const { return p; }
    void operator=(Font *f) { if (f) f->vt->addref(f); if (p) p->vt->release(p); p = f; }
};
struct String;
extern "C" void w3d_string_finish_8020c5c4(String *);
extern "C" void w3d_string_release_80341588(String *);
struct String {
    void *p;
    String() {}
    String(const String &);
    ~String() { w3d_string_finish_8020c5c4(this); w3d_string_release_80341588(this); }
};
struct Line { float x, y, width; int count; const unsigned char *text; };
struct Bits { unsigned b0 : 1; unsigned b1 : 1; unsigned b2 : 1; unsigned b3 : 1; unsigned rest : 28; };
struct Screen { char u0[32]; Line lines[8]; FontRef fonts[8]; unsigned count; char u228[16]; FontRef box; Bits bits; };
struct Scene;
struct View;
struct ViewVt { void *u[11]; void (*show)(View *); };
struct View { ViewVt *vt; };
struct SceneVt { void *u[16]; void (*flip)(Scene *, int); };
struct Scene { SceneVt *vt; char u4[72]; Bits bits; char u80[28]; View *view; };
extern Scene *scene_804b1788;
extern "C" int w3d_handle_load_8015adf4(const String *, FontRef *, unsigned char);
extern "C" Font *fn_8034357c(Font *);
extern "C" Font *fn_80343580(Font *);
extern "C" void fn_800fde38();
extern "C" int fn_80173df0(Font *, const Colour *);
extern "C" void fn_800c7944(Screen *, void *, int);
extern "C" int fn_8018c5b0(Font *, const char *);
extern "C" int fn_8018d35c(Font *, const Colour *);
extern "C" int fn_8018d434(Font *, const Colour *);
extern "C" String *string_ctor_8020bb54(String *, const char *);
extern "C" void fn_800c7c84(Screen *);
inline void IntoBox(FontRef &dst, int id) { String name; String *pn = &name; string_ctor_8020bb54(pn, "FE.Textbox.Back"); FontRef found; w3d_handle_load_8015adf4(pn, &found, id); dst = fn_8034357c(found.p); }
inline void IntoFont(FontRef &dst, int id) { String name; String *pn = &name; string_ctor_8020bb54(pn, "FE.Font"); FontRef found; w3d_handle_load_8015adf4(pn, &found, id); dst = fn_80343580(found.p); }
extern "C" void d41m_screen_fade_in_text_800c71f8(Screen *self, void *text) {
    int flags = 55;
    self->bits.b2 = 1;
    Vec3 at;
    Vec3 *pa = &at;
    pa->x = 30.0f; pa->y = 30.0f; pa->z = 0.0f;
    fn_800fde38();
    scene_804b1788->view->vt->show(scene_804b1788->view);
    self->bits.b3 = 1;
    Scene *sc = scene_804b1788;
    if (self->bits.b1) sc->bits.b2 = 1;
    sc->bits.b2 = self->bits.b0;
    sc->bits.b3 = 0;
    sc->bits.b1 = 0;
    { bool on = sc->bits.b2; if (on) flags = 60; }
    if (!self->box) IntoBox(self->box, flags);
    Vec3 size;
    size.Set(640.0f, 480.0f, 0.0f);
    self->box->vt->place(self->box, &size, 0);
    Colour back;
    back.Set(0, 0, 0, 0);
    fn_80173df0(self->box, &back);
    fn_800c7944(self, text, flags);
    Vec3 pos;
    pos.Set(0.0f, 0.0f, 0.0f);
    Colour fg;
    fg.Set(-1, -1, -1, 0);
    Colour shade;
    shade.Set(0, 0, 0, 0);
    char buffer[128];
    buffer[0] = 0;
    for (unsigned i = 0; i < self->count; i++) {
        if (!self->fonts[i]) IntoFont(self->fonts[i], flags + 1);
        Line *l = &self->lines[i];
        int k;
        for (k = 0; k < l->count; k++) {
            unsigned char c = l->text[k];
            if (c == '$') buffer[k] = ' ';
            else buffer[k] = c;
        }
        buffer[k] = 0;
        pos.y = l->y;
        { Font *b = self->fonts[i]; b->vt->place(b, &at, 0); }
        fn_8018c5b0(self->fonts[i], buffer);
        { Font *b = self->fonts[i]; b->vt->offset(b, &pos, 0); }
        fn_8018d35c(self->fonts[i], &fg);
    }
    unsigned k;
    float level = 0.0f;
    int n = 0;
    for (;;) {
        level += 8.5f;
        back.a = (unsigned char)(level / 255.0f * 180.0f);
        shade.a = fg.a = (unsigned char)level;
        fn_80173df0(self->box, &back);
        for (k = 0; k < self->count; k++) {
            fn_8018d35c(self->fonts[k], &fg);
            fn_8018d434(self->fonts[k], &shade);
        }
        sc->vt->flip(sc, 0);
        n++;
        if (n >= 30) break;
    }
    back.a = 180;
    fn_80173df0(self->box, &back);
    fg.a = 255;
    for (k = 0; k < self->count; k++) fn_8018d35c(self->fonts[k], &fg);
    fn_800c7c84(self);
    self->bits.b2 = 0;
}
