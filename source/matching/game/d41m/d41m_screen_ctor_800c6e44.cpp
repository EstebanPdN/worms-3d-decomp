// GWMP8P rev0 0x800c6e44. Text screen constructor: runs the base
// constructor, installs the table, clears the eight font handles, the box
// and counters, then resets the screen. Same class as 0x800c71f8. Names are
// inferred.
#pragma interface
struct Font;
struct FontVt { void *u[3]; void (*addref)(Font *); void (*release)(Font *); };
struct Font { FontVt *vt; };
struct FontRef {
    Font *p;
    FontRef() { p = 0; }
    FontRef(const FontRef &);
    ~FontRef() { if (p) p->vt->release(p); }
    void operator=(Font *f) { if (f) f->vt->addref(f); if (p) p->vt->release(p); p = f; }
};
struct Line { float x, y, width; int count; const unsigned char *text; };
struct Bits { unsigned b0 : 1; unsigned b1 : 1; unsigned b2 : 1; unsigned b3 : 1; unsigned b4 : 1; unsigned rest : 27; };
struct Root { virtual void a0(); };
struct Base_801628b0 : Root { char u4[24]; Base_801628b0(); };
struct Screen_8040faa8 : Base_801628b0 {
    int f28; char u32[160]; FontRef fonts[8]; unsigned count; int f228; int u232; int f236; FontRef x; Font *box; Bits bits;
    Screen_8040faa8();
    void Reset(Font *const &z);
};
inline void Screen_8040faa8::Reset(Font *const &z) {
    x = z;
    f228 = 0;
    for (int i = 0; i < 8; i++) fonts[i] = 0;
    count = 0;
    bits.b0 = 0; bits.b1 = 0; bits.b2 = 0; bits.b4 = 0;
}
Screen_8040faa8::Screen_8040faa8() {
    f28 = 0;
    box = 0;
    f236 = 0;
    Reset(0);
}
