#include "w3d_ptr.h"
#line 1 "d25h_screen_show_800c7cd0.cpp"
// Loading screen visibility (Worms 3D GameCube PAL, 0x800c7cd0, 788 bytes).
//
// Names are inferred. The null image pointer read at the start doubles as the
// zero for the handle and the time reset, as the original's single register shows.

struct Flags { unsigned int rest:27; unsigned int e:1; unsigned int d:1; unsigned int c:1; unsigned int b:1; unsigned int a:1; };
struct Vec3 {
    float x, y, z;
    Vec3(float a, float b, float c) { x = a; y = b; z = c; }
};
struct Color {
    unsigned char r, g, b, a;
    void Set(unsigned char x, unsigned char y, unsigned char z, unsigned char w) { r = x; g = y; b = z; a = w; }
    Color(unsigned char x, unsigned char y, unsigned char z, unsigned char w) { r = x; g = y; b = z; a = w; }
};
struct Obj;
struct ObjVt { Ptr32<void> u[3]; Ptr32<void (Ptr32<Obj>)> addref; Ptr32<void (Ptr32<Obj>)> release; Ptr32<void> u20[14]; Ptr32<void (Ptr32<Obj>, Ptr32<const Vec3>, int)> colour; };
struct Obj { Ptr32<ObjVt> vt; };
struct Ref {
    Ptr32<Obj> p;
    void Clear() { if (p) p->vt->release(p); p = 0; }
};
struct ResRef {
    Ptr32<Obj> p;
    template <class W3dU> ResRef(Ptr32<W3dU> w3d_p) : ResRef((Obj *)w3d_p.get()) {}
 ResRef(Obj *o) { p = o; }
    ResRef(const ResRef &);
    ~ResRef() { if (p) p->vt->release(p); }
};
struct String;
extern "C" void w3d_string_finish_8020c5c4(Ptr32<String>);
extern "C" void w3d_string_release_80341588(Ptr32<String>);
struct String {
    Ptr32<void> p;
    template <class W3dU> String(Ptr32<W3dU> w3d_p) : String((const char *)w3d_p.get()) {}
 String(const char *);
    String(const String &);
    ~String() { w3d_string_finish_8020c5c4(this); w3d_string_release_80341588(this); }
};
extern "C" int w3d_handle_load_8015adf4(Ptr32<const String>, Ptr32<void>, unsigned char);
extern "C" Ptr32<Obj> fn_8034357c(Ptr32<Obj>);
extern "C" int fn_80173df0(Ptr32<Obj>, Ptr32<Color>);
extern "C" Ptr32<void> fn_80343994();
extern "C" void fn_801fdfb8(Ptr32<void>, int);
extern "C" int fn_801fe45c();
extern const char lbl_80387a7c[], lbl_80387a8c[];
struct Bank;
struct BankVt { Ptr32<void> u[40]; Ptr32<void (Ptr32<Bank>, int, int)> range; };
struct Bank { Ptr32<BankVt> vt; };
struct Sound { unsigned char u[116]; Ptr32<Bank> bank; };
extern Ptr32<Sound> lbl_804b17ec;
struct Services;
struct ServicesVt { Ptr32<void> u[16]; Ptr32<void (Ptr32<Services>, int)> wait; };
struct Services { Ptr32<ServicesVt> vt; unsigned char u4[72]; Flags flags; };
extern Ptr32<Services> lbl_804b1788;
struct Screen {
    unsigned char u0[228];
    int start;   // +228
    int time;    // +232
    Ref image;   // +236
    Ref frame;   // +240
    unsigned char u244[4];
    Flags flags; // +248
};
extern "C" void w3d_d25h_screen_show_800c7cd0(Ptr32<Screen> self, int on) {
    self->flags.a = on;
    fn_801fdfb8(fn_80343994(), on);
    if (self->flags.e && on) {
        Ref &image = self->image;
        Ptr32<Obj> none = image.p;
        Ptr32<Services> s = lbl_804b1788;
        if (none == 0) {
            Vec3 tint(-32.0f, 0.0f, 0.0f);
            Vec3 edge(64.0f, 0.0f, 0.0f);
            {
                String name(lbl_80387a7c);
                w3d_handle_load_8015adf4(&name, &image, 255);
            }
            {
                String name(lbl_80387a8c);
                ResRef res(none);
                w3d_handle_load_8015adf4(&name, &res, 255);
                Ptr32<Obj> o = fn_8034357c(res.p);
                if (o) o->vt->addref(o);
                if (self->frame.p) self->frame.p->vt->release(self->frame.p);
                self->frame.p = o;
            }
            self->image.p->vt->colour(self->image.p, &tint, 0);
            self->frame.p->vt->colour(self->frame.p, &edge, 0);
            self->start = fn_801fe45c();
            self->time = (int)w3d::H(none);
        }
        lbl_804b17ec->bank->vt->range(lbl_804b17ec->bank, 59, 61);
        Color colour(0, 0, 0, 255);
        self->flags.c = 1;
        s->flags.d = 0;
        float level = 0.0f;
        for (unsigned i = 0; i < 30; i++) {
            level += 8.5f;
            int v = (unsigned char)level;
            colour.Set(v, v, v, 255);
            fn_80173df0(fn_8034357c(self->image.p), &colour);
            fn_80173df0(fn_8034357c(self->frame.p), &colour);
            s->vt->wait(s, 0);
        }
        s->flags.d = 1;
        self->flags.c = 0;
    } else {
        Ptr32<Obj> zero = 0;
        lbl_804b17ec->bank->vt->range(lbl_804b17ec->bank, 0, 58);
        if (self->image.p) self->image.p->vt->release(self->image.p);
        self->image.p = zero;
        if (self->frame.p) self->frame.p->vt->release(self->frame.p);
        self->frame.p = zero;
    }
}


