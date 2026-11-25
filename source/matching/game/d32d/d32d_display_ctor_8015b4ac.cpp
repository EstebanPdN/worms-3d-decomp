// GWMP8P rev0 0x8015b4ac. Display setup constructor: 800x600, 24 bit colour, 32 bit depth, 60 Hz.
// Takes a reference on the service entry, creates the global mode record and
// sets its defaults. Field names are inferred; virtual slots are table views.
#pragma interface
struct Item { virtual void s2(); virtual void retain(); virtual void release(); };
struct Root { virtual void a0(); };
struct Base_8015be3c : Root { char u4[24]; Base_8015be3c(); };
struct Ref { Item *p; void set(Item *e) { if (e) e->retain(); if (p) p->release(); p = e; } };
struct Mode;
extern Mode *mode_804b1880;
struct Mode {
    Item *r;
    unsigned kind : 7;
    unsigned b7 : 1;
    unsigned char c5;
    unsigned d : 5;
    Mode(Item *i) : r(i) {
        if (r) r->retain();
        kind = 10;
        b7 = 0;
        c5 = 0;
        d = 6;
        mode_804b1880 = this;
    }
};
extern "C" Item *forward_8020b680(void *);
extern unsigned char desc_80419460[];
struct Display_804110e8 : Base_8015be3c {
    void a0();
    int f28;
    int width;
    int height;
    unsigned b0 : 1;
    unsigned b1 : 1;
    unsigned b2 : 1;
    unsigned char colour;
    unsigned char depth;
    unsigned char r43;
    unsigned char r44;
    int f48;
    int f52;
    int f56;
    int u60;
    float f64;
    int f68;
    Ref ref;
    unsigned g0 : 1;
    unsigned g1 : 1;
    unsigned g2 : 1;
    unsigned g3 : 1;
    unsigned g4 : 1;
    unsigned g5 : 2;
    unsigned g7 : 1;
    unsigned g8 : 1;
    int f80;
    int f84;
    Display_804110e8();
};
Display_804110e8::Display_804110e8() : f48(0), f68(0) {
    b0 = 0;
    b2 = 0;
    ref.p = 0;
    f28 = 2;
    width = 800;
    height = 600;
    colour = 24;
    depth = 32;
    r43 = 60;
    r44 = 60;
    ref.set(forward_8020b680(desc_80419460));
    new Mode(ref.p);
    g1 = 0;
    g2 = 0;
    g3 = 1;
    g8 = 1;
    g4 = 0;
    g0 = 1;
    g7 = 0;
    b1 = 0;
    f56 = 1;
    f64 = 1.0f;
    g5 = 3;
    f80 = 20;
    f52 = 0;
    f84 = 0;
}
