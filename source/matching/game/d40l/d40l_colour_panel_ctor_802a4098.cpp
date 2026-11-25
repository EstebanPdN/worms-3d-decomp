// GWMP8P rev0 0x802a4098. Constructor of a menu panel with bases at +0
// (0x8015fef0) and +28 (0x802afb20), written as a plain function over a
// partial view: member word arrays, a colour table, and four string arrays.
// Field names are inferred.
inline void *operator new(unsigned, void *p) { return p; }
inline void *operator new[](unsigned, void *p) { return p; }
extern "C" void * fn_803426b8(void *);
struct Str { char *p; Str() { fn_803426b8(this); } };
struct Word { int v; Word() { v = 0; } };
struct Colour {
    unsigned char r, g, b, a;
    Colour() {}
    void set(unsigned char x, unsigned char y, unsigned char z, unsigned char w) { r = x; g = y; b = z; a = w; }
};
struct Pair { Word w[2]; };
struct Item {
    void **vt;
    char u4[24];
    char base[180];
    void **vt208;
    Word w212[3];
    Word w224, w228, w232, w236;
    int w240;
    Word w244[2], w252[2], w260[2], w268[2];
    Word w276[8];
    Colour col[9];
    float f344, f348, f352, f356, f360, f364, f368;
    int w372;
    int w376, w380, w384, w388, w392, w396, w400;
    float f404, f408, f412, f416;
    Str s420[10], s460[10], s500[10], s540[10];
    int w580, w584, w588, w592, w596, w600, w604, w608, w612, w616, w620;
};
extern void *vt_8041c470[], *vt_8041c4c0[];
extern "C" Item *fn_8015fef0(Item *);
extern "C" void * fn_802afb20(void *);
inline void two(Word *p) { int i = 1; do { new (p) Word; ++p; } while (i-- != 0); }
extern "C" Item *d40l_colour_panel_ctor_802a4098(Item *s) {
    fn_8015fef0(s);
    fn_802afb20(s->base);
    s->vt208 = vt_8041c470;
    s->vt = vt_8041c4c0;
    new (s->w212) Word[3];
    new (&s->w224) Word;
    new (&s->w228) Word;
    new (&s->w232) Word;
    new (&s->w236) Word;
    two(s->w244);
    two(s->w252);
    two(s->w260);
    two(s->w268);
    new (s->w276) Word[8];
    new (s->col) Colour[9];
    s->w376 = 0; s->w380 = 0; s->w384 = 0; s->w388 = 0; s->w392 = 0; s->w396 = 0; s->w400 = 0;
    new (s->s420) Str[10];
    new (s->s460) Str[10];
    new (s->s500) Str[10];
    new (s->s540) Str[10];
    s->w620 = 4;
    float one = 0.0f;
    s->f344 = one; s->f348 = one; s->f352 = one; s->f356 = one; s->f360 = one; s->f364 = one; s->f368 = one;
    s->w600 = 0; s->w612 = 0; s->w604 = 0; s->w608 = 0; s->w592 = 0; s->w240 = 0; s->w580 = 0; s->w584 = 0; s->w588 = 0; s->w596 = 0; s->w616 = 0;
    s->col[0].set(0, 160, 105, 255);
    s->col[1].set(91, 197, 53, 255);
    s->col[2].set(182, 234, 0, 255);
    s->col[3].set(218, 217, 0, 255);
    s->col[4].set(255, 200, 0, 255);
    s->col[5].set(249, 131, 0, 255);
    s->col[6].set(243, 62, 0, 255);
    s->col[7].set(255, 0, 0, 255);
    s->col[8].set(50, 50, 50, 200);
    s->w372 = 0;
    float f = 1.0f;
    s->f404 = f; s->f408 = f; s->f412 = f; s->f416 = f;
    return s;
}
