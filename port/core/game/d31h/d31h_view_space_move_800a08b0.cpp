#include "w3d_ptr.h"
#line 1 "d31h_view_space_move_800a08b0.cpp"
// GWMP8P rev0 0x800a08b0. Moves an object between view spaces. Names are
// inferred. Copies the two 4x4 matrices from virtual slots 24 and 32 of the
// two view objects at +48 and +132 of the screen service, converts them to
// transforms, inverts those of the second view, passes the point through the
// first view's transforms, adjusts it with 0x800a0fbc, brings it back
// through the inverted transforms and hands the result to virtual slot 76 of
// the object at +28. Class layouts are partial views.
struct Pos { float x, y, z; Pos(); };
struct Axis { float x, y, z; };
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct Mat44 { float m[16]; };
struct Transform {
    Axis axis[3]; Pos position;
    const Axis &R(int i) const { return axis[i]; }
    const Pos &P() const { return position; }
    void apply(Vec &o, const Vec &v) const {
        o.x = v.x * R(0).x + v.y * R(1).x + v.z * R(2).x + P().x;
        o.y = v.x * R(0).y + v.y * R(1).y + v.z * R(2).y + P().y;
        o.z = v.x * R(0).z + v.y * R(1).z + v.z * R(2).z + P().z;
    }
};
extern "C" void from44_801f74d0(Ptr32<Transform>, Ptr32<const Mat44>);
extern "C" int invert_801f76e0(Ptr32<Transform>, Ptr32<const Transform>);
struct View {
    Ptr32<Ptr32<void>> vt;
    Ptr32<const Mat44> Get(int off) { return ((Ptr32<Ptr32<const Mat44> (Ptr32<View>)>)*(Ptr32<Ptr32<void>>)((Ptr32<char>)vt + off))(this); }
};
struct Screen { char unknown0[48]; Ptr32<View> a; char unknown52[80]; Ptr32<View> b; };
extern Ptr32<Screen> lbl_804b1788;
struct Sink { Ptr32<Ptr32<void>> vt; int Move(Ptr32<const Vec> v, int n) { return ((Ptr32<int (Ptr32<Sink>, Ptr32<const Vec>, int)>)*(Ptr32<Ptr32<void>>)((Ptr32<char>)vt + 76))(this, v, n); } };
struct Self { char unknown0[28]; Ptr32<Sink> sink; };
extern "C" Vec solve_800a0fbc(Ptr32<Self>, Vec);
extern "C" void d31h_view_space_move_800a08b0(Ptr32<Self> self, Ptr32<const Vec> p) {
    Mat44 m0 = *lbl_804b1788->a->Get(24);
    Mat44 m1 = *lbl_804b1788->a->Get(32);
    Mat44 m2 = *lbl_804b1788->b->Get(24);
    Mat44 m3 = *lbl_804b1788->b->Get(32);
    Transform a, b, c, d, e, f;
    from44_801f74d0(&a, &m0);
    from44_801f74d0(&b, &m1);
    from44_801f74d0(&c, &m2);
    from44_801f74d0(&d, &m3);
    invert_801f76e0(&e, &c);
    invert_801f76e0(&f, &d);
    Vec w, x, y;
    a.apply(w, *p);
    b.apply(x, w);
    x = solve_800a0fbc(self, x);
    f.apply(w, x);
    e.apply(y, w);
    Ptr32<Vec> out = &y;
    self->sink->Move(out, 0);
}


