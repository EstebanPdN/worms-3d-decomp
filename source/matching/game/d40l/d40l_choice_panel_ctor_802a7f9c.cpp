// GWMP8P rev0 0x802a7f9c. Constructor of the choice panel with bases at +0
// (0x8015fef0) and +28 (0x802afb20), written as a plain function over a
// partial view: handles, a slot array, a cell table and a clearing pass.
// Field names are inferred.
extern "C" void *memset(void *, int, unsigned);
extern "C" void * fn_803426b8(void *);
struct Str { char *p; Str() { fn_803426b8(this); } };
struct Res;
struct ResVt { char u0[16]; void (*destroy)(Res *); };
struct Res { ResVt *vt; };
struct Handle {
    Res *r;
    Handle() { r = 0; }
    void clear() { if (r) r->vt->destroy(r); r = 0; }
    void clear(Res *z) { if (r) r->vt->destroy(r); r = z; }
};
inline void *operator new(unsigned, void *p) { return p; }
inline void *operator new[](unsigned, void *p) { return p; }
struct Slot {
    int u0[15];
    Str a;
    int u64;
    Str b;
};
struct Cell {
    int u0;
    Handle h;
    int u8;
    Handle g;
};
struct Row {
    Cell c[5];
    Row() {}
};
struct Item {
    void **vt;
    char u4[24];
    char base[180];
    void **vt208;
    Handle w212, w216, w220;
    int w224;
    char u228[12];
    int w240;
    Handle w244;
    Handle w248[3];
    int u260[2];
    Slot slots[11];
    int w1060[3];
    int current;
    Row cells[3];
    char u1316x[0];
    int w1316[3];
    int u1328[3];
    int flags;
    int u1344[3];
    Handle w1356, w1360;
    Handle w1364[3];
    int w1376, w1380;
};
extern void *vt_8041c550[], *vt_8041c500[];
extern "C" Item *fn_8015fef0(Item *);
extern "C" void * fn_802afb20(void *);
extern "C" Item *d40l_choice_panel_ctor_802a7f9c(Item *s) {
    fn_8015fef0(s);
    fn_802afb20(s->base);
    s->vt208 = vt_8041c500;
    s->vt = vt_8041c550;
    new (&s->w212) Handle;
    new (&s->w216) Handle;
    new (&s->w220) Handle;
    new (&s->w244) Handle;
    new (s->w248) Handle[3];
    new (s->slots) Slot[11];
    new (s->cells) Row[3];
    new (&s->w1356) Handle;
    new (&s->w1360) Handle;
    new (s->w1364) Handle[3];
    s->w224 = 0;
    s->w240 = 0;
    s->current = 0;
    s->flags = 1;
    memset(s->w1316, 0, 12);
    Res *z;
    for (unsigned i = 0; i <= 2; i++) {
        for (unsigned j = 0; j <= 4; j++) {
            s->cells[i].c[j].h.clear();
        }
        z = 0;
        s->w1364[i].clear(z);
    }
    s->w1356.clear();
    { Res *q = 0; s->w1360.clear(q); }
    s->w1376 = 0;
    s->w1380 = 0;
    return s;
}
