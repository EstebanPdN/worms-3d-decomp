#include "w3d_ptr.h"
#line 1 "d43l_keyboard_layout_build_802c2dc4.cpp"
// GWMP8P rev0 0x802c2dc4. Creates the on-screen keyboard's panels, arrow and
// action buttons and thirty keys in rows of ten, with space and backspace,
// each only when it does not yet exist.
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct Obj;
struct ObjVt { char u[12]; Ptr32<void (Ptr32<Obj>)> acquire; Ptr32<void (Ptr32<Obj>)> destroy; };
struct Obj { Ptr32<ObjVt> vt; };
struct Ref {
    Ptr32<Obj> r;
    Ref(const Ref &o) { r = o.r; if (r) r->vt->acquire(r); }
    // Port: suelta la referencia, como todos los Ref del juego (destroy, +16). Solo declarado, el enlace lo buscaba en otra
    // unidad, y en 3DS no lo encontraba: el teclado del juego (equipo nuevo, código del paisaje) caía al crearse.
    ~Ref() { if (r) r->vt->destroy(r); }
};
struct Held {
    Ptr32<Obj> r;
    Held(const Held &);
    ~Held() { if (r) r->vt->destroy(r); }
    Held &operator=(const Held &o) {
        if (o.r) o.r->vt->acquire(o.r);
        if (r) r->vt->destroy(r);
        r = o.r;
        return *this;
    }
};
struct Str { Ptr32<char> p; template <class W3dU> Str(Ptr32<W3dU> w3d_p) : Str((const char *)w3d_p.get()) {}
 Str(const char *); Str(const Str &); };
struct Keyboard {
    char u0[20];
    int w20;
    char u24[8];
    Ref font;
    Held w36;
    Held w40;
    char u44[40];
    Ptr32<void> w84; Ptr32<void> w88;
    Ptr32<void> keys[30];
    Ptr32<void> w212; Ptr32<void> w216; Ptr32<void> w220; Ptr32<void> w224; Ptr32<void> w228; Ptr32<void> w232;
    char u236[100];
    Ptr32<void> res;
};
extern unsigned char type_8041c660[], type_8041c910[], type_8041c950[];
extern Ptr32<void> scene_804b178c;
extern "C" {
Ptr32<void> fn_8020b680(Ptr32<void>);
int fn_80164514(Ptr32<void>, Ptr32<void>, int);
float fn_80178df0(Ptr32<void>);
void fn_802b310c(Ptr32<void>, float);
void fn_802b30c0(Ptr32<void>, float, float);
void fn_802b3020(Ptr32<void>, Vec);
void fn_802b3d04(Ptr32<void>, int, int);
Held fn_802b3c5c(Ptr32<void>, Ref);
void fn_802c629c(Ptr32<void>, float, float);
void fn_802c61fc(Ptr32<void>, Vec);
void fn_802c6924(Ptr32<void>, int);
Held fn_802c6384(Ptr32<void>, Ref);
void fn_802c7278(Ptr32<void>, float, float);
void fn_802c71d8(Ptr32<void>, Vec);
void fn_802c813c(Ptr32<void>, int);
void fn_802c7cec(Ptr32<void>, float, float, int);
Held fn_802c72e4(Ptr32<void>, Ref);
void fn_802c7a0c(Ptr32<void>, Str, int);
void fn_802c38cc(Ptr32<Keyboard>, int);
void fn_802c37e0(Ptr32<Keyboard>);
}

inline Ref Font(Ptr32<Keyboard> self) { return self->font; }
// La función llamada libera su argumento por valor (GCC 2.95) y clang libera además la copia en quien llama.
inline Held view_init(Ptr32<void> view, const Ref &font) { if (font.r) font.r->vt->acquire(font.r); return fn_802b3c5c(view, font); }
inline void grid_init(Ptr32<void> grid, const Ref &parent) { if (parent.r) parent.r->vt->acquire(parent.r); fn_802c6384(grid, parent); }
inline void key_init(Ptr32<void> key, const Ref &parent) { if (parent.r) parent.r->vt->acquire(parent.r); fn_802c72e4(key, parent); }
inline Held mk(Ptr32<Keyboard> self) { return view_init(self->w84, Font(self)); }
extern "C" void d43l_keyboard_layout_build_802c2dc4(Ptr32<Keyboard> self) {
    float h = 250.0f;

    if (!self->w84) {
        Ptr32<void> b = fn_8020b680(type_8041c660);
        Ptr32<void> &slot = self->w84;
        slot = b;
        fn_80164514(scene_804b178c, b, self->w20);

        fn_802b310c(self->w84, fn_80178df0(self->res));
        fn_802b30c0(self->w84, 380.0f, 60.0f);
        Vec v(0.0f, 150.0f, 0.0f);
        fn_802b3020(self->w84, v);
        fn_802b3d04(self->w84, 1, 0);
        self->w36 = mk(self);
    }

    if (!self->w88) {
        Ptr32<void> b = fn_8020b680(type_8041c660);
        Ptr32<void> &slot = self->w88;
        slot = b;
        fn_80164514(scene_804b178c, b, self->w20);

        fn_802b310c(self->w88, fn_80178df0(self->res));
        fn_802b30c0(self->w88, 428.0f, h);
        Vec v(0.0f, -20.0f, 0.0f);
        fn_802b3020(self->w88, v);
        fn_802b3d04(self->w88, 1, 1);
        self->w40 = view_init(self->w88, self->font);
    }

    if (!self->w224) {
        Ptr32<void> b = fn_8020b680(type_8041c910);
        Ptr32<void> &slot = self->w224;
        slot = b;
        fn_80164514(scene_804b178c, b, self->w20);

        fn_802c629c(self->w224, 80.0f, 80.0f);
        float t = fn_80178df0(self->res);
        Vec v(140.0f, -h * 0.5f + t * 0.5f + 32.0f, 0.0f);
        fn_802c61fc(self->w224, v);
        fn_802c6924(self->w224, 6);
        grid_init(self->w224, (const Ref &)self->w40);
    }

    if (!self->w220) {
        Ptr32<void> b = fn_8020b680(type_8041c910);
        Ptr32<void> &slot = self->w220;
        slot = b;
        fn_80164514(scene_804b178c, b, self->w20);

        fn_802c629c(self->w220, 80.0f, 80.0f);
        float t = fn_80178df0(self->res);
        Vec v(-140.0f, -h * 0.5f + t * 0.5f + 32.0f, 0.0f);
        fn_802c61fc(self->w220, v);
        fn_802c6924(self->w220, 0);
        grid_init(self->w220, (const Ref &)self->w40);
    }

    if (!self->w228) {
        Ptr32<void> b = fn_8020b680(type_8041c950);
        Ptr32<void> &slot = self->w228;
        slot = b;
        fn_80164514(scene_804b178c, b, self->w20);

        fn_802c7278(self->w228, 40.0f, 40.0f);
        float t = fn_80178df0(self->res);
        Vec v(30.0f, -h * 0.5f + t * 0.5f + 32.0f, 0.0f);
        fn_802c71d8(self->w228, v);
        fn_802c813c(self->w228, 1);
        fn_802c7cec(self->w228, 0.0f, 0.0f, 0);
        key_init(self->w228, (const Ref &)self->w40);
    }

    if (!self->w232) {
        Ptr32<void> b = fn_8020b680(type_8041c950);
        Ptr32<void> &slot = self->w232;
        slot = b;
        fn_80164514(scene_804b178c, b, self->w20);

        fn_802c7278(self->w232, 40.0f, 40.0f);
        float t = fn_80178df0(self->res);
        Vec v(-30.0f, -h * 0.5f + t * 0.5f + 32.0f, 0.0f);
        fn_802c71d8(self->w232, v);
        fn_802c813c(self->w232, 1);
        fn_802c7cec(self->w232, 0.0f, 0.0f, 1);
        key_init(self->w232, (const Ref &)self->w40);
    }

    float x0 = -180.0f;
    if (!self->keys[0]) {
        Ptr32<Ptr32<void>> keys = self->keys;
        float t = fn_80178df0(self->res);
        float x = x0;
        float z = 0.0f;
        float y = h * 0.5f - t * 0.5f - 26.0f;
        unsigned col = 0;
        float s;
        for (unsigned i = 0; i <= 29; i++) {
            Ptr32<void> k = fn_8020b680(type_8041c950);
            fn_80164514(scene_804b178c, k, self->w20);
            self->keys[i] = k;
            fn_802c7278(k, 40.0f, 40.0f);
            Vec v(x, y, z);
            fn_802c71d8(self->keys[i], v);
            key_init(keys[i], (const Ref &)self->w40);
            s = 40.0f;
            x += s;
            if (col++ == 9) {
                x = x0;
                col = 0;
                y -= s;
            }
        }
        Ptr32<unsigned char> type = type_8041c950;
        { float k = 400.0f; x = x0 - 20.0f; x0 = k; }
        Ptr32<void> b = fn_8020b680(type);
        Ptr32<void> &slot = self->w212;
        slot = b;
        fn_80164514(scene_804b178c, b, self->w20);
        float sp = x0 * 0.8f;
        fn_802c7278(self->w212, sp, s);
        float zz = 0.0f;
        {
        Vec v(sp * 0.5f + x, y, zz);
        fn_802c71d8(self->w212, v);
        fn_802c7a0c(self->w212, Str("FE.Font"), 32);
        key_init(self->w212, (const Ref &)self->w40);
        }
        x0 -= sp;
        x += sp + 1.0f;
        Ptr32<void> c = fn_8020b680(type);
        Ptr32<void> &slot2 = self->w216;
        slot2 = c;
        fn_80164514(scene_804b178c, c, self->w20);
        fn_802c7278(self->w216, x0, s);
        fn_802c7cec(self->w216, -20.0f, 5.0f, 1);
        {
        Vec v(x + s, y, zz);
        fn_802c71d8(self->w216, v);
        key_init(self->w216, (const Ref &)self->w40);
        }
    }
    fn_802c38cc(self, 1);
    fn_802c37e0(self);
}


