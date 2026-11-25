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
struct ObjVt { char u[12]; void (*acquire)(Obj *); void (*destroy)(Obj *); };
struct Obj { ObjVt *vt; };
struct Ref {
    Obj *r;
    Ref(const Ref &o) { r = o.r; if (r) r->vt->acquire(r); }
    ~Ref();
};
struct Held {
    Obj *r;
    Held(const Held &);
    ~Held() { if (r) r->vt->destroy(r); }
    Held &operator=(const Held &o) {
        if (o.r) o.r->vt->acquire(o.r);
        if (r) r->vt->destroy(r);
        r = o.r;
        return *this;
    }
};
struct Str { char *p; Str(const char *); Str(const Str &); };
struct Keyboard {
    char u0[20];
    int w20;
    char u24[8];
    Ref font;
    Held w36;
    Held w40;
    char u44[40];
    void *w84, *w88;
    void *keys[30];
    void *w212, *w216, *w220, *w224, *w228, *w232;
    char u236[100];
    void *res;
};
extern unsigned char type_8041c660[], type_8041c910[], type_8041c950[];
extern void *scene_804b178c;
extern "C" {
void *fn_8020b680(void *);
int fn_80164514(void *, void *, int);
float fn_80178df0(void *);
void fn_802b310c(void *, float);
void fn_802b30c0(void *, float, float);
void fn_802b3020(void *, Vec);
void fn_802b3d04(void *, int, int);
Held fn_802b3c5c(void *, Ref);
void fn_802c629c(void *, float, float);
void fn_802c61fc(void *, Vec);
void fn_802c6924(void *, int);
Held fn_802c6384(void *, Ref);
void fn_802c7278(void *, float, float);
void fn_802c71d8(void *, Vec);
void fn_802c813c(void *, int);
void fn_802c7cec(void *, float, float, int);
Held fn_802c72e4(void *, Ref);
void fn_802c7a0c(void *, Str, int);
void fn_802c38cc(Keyboard *, int);
void fn_802c37e0(Keyboard *);
}

inline Ref Font(Keyboard *self) { return self->font; }
inline Held mk(Keyboard *self) { return fn_802b3c5c(self->w84, Font(self)); }
extern "C" void d43l_keyboard_layout_build_802c2dc4(Keyboard *self) {
    float h = 250.0f;

    if (!self->w84) {
        void *b = fn_8020b680(type_8041c660);
        void *&slot = self->w84;
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
        void *b = fn_8020b680(type_8041c660);
        void *&slot = self->w88;
        slot = b;
        fn_80164514(scene_804b178c, b, self->w20);

        fn_802b310c(self->w88, fn_80178df0(self->res));
        fn_802b30c0(self->w88, 428.0f, h);
        Vec v(0.0f, -20.0f, 0.0f);
        fn_802b3020(self->w88, v);
        fn_802b3d04(self->w88, 1, 1);
        self->w40 = fn_802b3c5c(self->w88, self->font);
    }

    if (!self->w224) {
        void *b = fn_8020b680(type_8041c910);
        void *&slot = self->w224;
        slot = b;
        fn_80164514(scene_804b178c, b, self->w20);

        fn_802c629c(self->w224, 80.0f, 80.0f);
        float t = fn_80178df0(self->res);
        Vec v(140.0f, -h * 0.5f + t * 0.5f + 32.0f, 0.0f);
        fn_802c61fc(self->w224, v);
        fn_802c6924(self->w224, 6);
        fn_802c6384(self->w224, (const Ref &)self->w40);
    }

    if (!self->w220) {
        void *b = fn_8020b680(type_8041c910);
        void *&slot = self->w220;
        slot = b;
        fn_80164514(scene_804b178c, b, self->w20);

        fn_802c629c(self->w220, 80.0f, 80.0f);
        float t = fn_80178df0(self->res);
        Vec v(-140.0f, -h * 0.5f + t * 0.5f + 32.0f, 0.0f);
        fn_802c61fc(self->w220, v);
        fn_802c6924(self->w220, 0);
        fn_802c6384(self->w220, (const Ref &)self->w40);
    }

    if (!self->w228) {
        void *b = fn_8020b680(type_8041c950);
        void *&slot = self->w228;
        slot = b;
        fn_80164514(scene_804b178c, b, self->w20);

        fn_802c7278(self->w228, 40.0f, 40.0f);
        float t = fn_80178df0(self->res);
        Vec v(30.0f, -h * 0.5f + t * 0.5f + 32.0f, 0.0f);
        fn_802c71d8(self->w228, v);
        fn_802c813c(self->w228, 1);
        fn_802c7cec(self->w228, 0.0f, 0.0f, 0);
        fn_802c72e4(self->w228, (const Ref &)self->w40);
    }

    if (!self->w232) {
        void *b = fn_8020b680(type_8041c950);
        void *&slot = self->w232;
        slot = b;
        fn_80164514(scene_804b178c, b, self->w20);

        fn_802c7278(self->w232, 40.0f, 40.0f);
        float t = fn_80178df0(self->res);
        Vec v(-30.0f, -h * 0.5f + t * 0.5f + 32.0f, 0.0f);
        fn_802c71d8(self->w232, v);
        fn_802c813c(self->w232, 1);
        fn_802c7cec(self->w232, 0.0f, 0.0f, 1);
        fn_802c72e4(self->w232, (const Ref &)self->w40);
    }

    float x0 = -180.0f;
    if (!self->keys[0]) {
        void **keys = self->keys;
        float t = fn_80178df0(self->res);
        float x = x0;
        float z = 0.0f;
        float y = h * 0.5f - t * 0.5f - 26.0f;
        unsigned col = 0;
        float s;
        for (unsigned i = 0; i <= 29; i++) {
            void *k = fn_8020b680(type_8041c950);
            fn_80164514(scene_804b178c, k, self->w20);
            self->keys[i] = k;
            fn_802c7278(k, 40.0f, 40.0f);
            Vec v(x, y, z);
            fn_802c71d8(self->keys[i], v);
            fn_802c72e4(keys[i], (const Ref &)self->w40);
            s = 40.0f;
            x += s;
            if (col++ == 9) {
                x = x0;
                col = 0;
                y -= s;
            }
        }
        unsigned char *type = type_8041c950;
        { float k = 400.0f; x = x0 - 20.0f; x0 = k; }
        void *b = fn_8020b680(type);
        void *&slot = self->w212;
        slot = b;
        fn_80164514(scene_804b178c, b, self->w20);
        float sp = x0 * 0.8f;
        fn_802c7278(self->w212, sp, s);
        float zz = 0.0f;
        {
        Vec v(sp * 0.5f + x, y, zz);
        fn_802c71d8(self->w212, v);
        fn_802c7a0c(self->w212, Str("FE.Font"), 32);
        fn_802c72e4(self->w212, (const Ref &)self->w40);
        }
        x0 -= sp;
        x += sp + 1.0f;
        void *c = fn_8020b680(type);
        void *&slot2 = self->w216;
        slot2 = c;
        fn_80164514(scene_804b178c, c, self->w20);
        fn_802c7278(self->w216, x0, s);
        fn_802c7cec(self->w216, -20.0f, 5.0f, 1);
        {
        Vec v(x + s, y, zz);
        fn_802c71d8(self->w216, v);
        fn_802c72e4(self->w216, (const Ref &)self->w40);
        }
    }
    fn_802c38cc(self, 1);
    fn_802c37e0(self);
}
