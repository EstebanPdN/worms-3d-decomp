#include "w3d_ptr.h"
#line 1 "d29f_border_view_setup_8028a784.cpp"
// GWMP8P rev0 0x8028a784. Builds a node's border view on first use: ensures
// the scene exists, creates the view object, registers it with the node's
// owner, reads FE.BorderThickness, sets its size from the node's width and
// height, rebuilds its layout and attaches it to the scene. Field names are
// inferred; the unit owns no data.
struct Obj { Ptr32<Ptr32<void>> table; };
inline void retain(Ptr32<Obj> p) { if (p) ((Ptr32<void (Ptr32<Obj>)>)p->table[3])(p); }
inline void release(Ptr32<Obj> p) { if (p) ((Ptr32<void (Ptr32<Obj>)>)p->table[4])(p); }
struct Handle {
    Ptr32<Obj> p;
    Handle() : p(0) {}
    Handle(const Handle &o) : p(o.p) { retain(p); }
    ~Handle() { release(p); }
};
struct Key { Ptr32<const char> text; template <class W3dU> Key(Ptr32<W3dU> w3d_p) : Key((const char *)w3d_p.get()) {}
 Key(const char *p) : text(p) {} };
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(const Vec3 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct Node {
    char pad0[20];
    Ptr32<void> owner;
    char pad1[704 - 24];
    int state;
    char pad2[988 - 708];
    Handle scene;
    Ptr32<void> view;
    float width, height;
};
extern char lbl_8041c660[], lbl_803cfb54[];
extern float lbl_803cfb68[];
extern int lbl_804abb60;
struct Svc { Ptr32<void> p; };
extern Svc lbl_804b178c;
extern "C" void d25f_node_scene_setup_8028a900(Ptr32<Node>);
extern "C" Ptr32<void> w3d_s10_service_forward_8020b680(Ptr32<void>);
extern "C" int fn_80164514(Ptr32<void>, Ptr32<void>, Ptr32<void>);
extern "C" int w3d_constructor_lookup_name(const Key &, Handle &);
extern "C" Ptr32<void> w3d_empty_80342a74(Ptr32<Obj>);
extern "C" float w3d_auto_80178df0(Ptr32<void>);
extern "C" void w3d_auto_802b310c(Ptr32<void>, float);
extern "C" void w3d_set_triple_802b3020(Ptr32<void>, const Vec3 &);
extern "C" void w3d_auto_802b30c0(Ptr32<void>, float, float);
extern "C" void d10b_rebuild_layout_802b3d04(Ptr32<void>, int, int);
extern "C" Handle w3d_cx12b_child_view_initialize_802b3c5c(Ptr32<void>, Handle);
extern "C" void d29f_border_view_setup_8028a784(Ptr32<Node> self) {
    if (self->scene.p == 0)
        d25f_node_scene_setup_8028a900(self);
    if (self->view == 0) {
        lbl_804abb60 += 10;
        Vec3 v;
        Ptr32<void> view = w3d_s10_service_forward_8020b680(lbl_8041c660);
        self->view = view;
        fn_80164514(lbl_804b178c.p, view, self->owner);
        Handle border;
        w3d_constructor_lookup_name(lbl_803cfb54, border);
        w3d_auto_802b310c(self->view, w3d_auto_80178df0(w3d_empty_80342a74(border.p)));
        float one = lbl_803cfb68[0];
        Ptr32<Vec3> p = &v;
        v.x = self->width;
        p->y = self->height;
        p->z = one;
        w3d_set_triple_802b3020(self->view, Vec3(*p));
        w3d_auto_802b30c0(self->view, one, one);
        d10b_rebuild_layout_802b3d04(self->view, 1, 0);
        retain(self->scene.p);  // La función llamada libera su argumento por valor (GCC 2.95) y clang libera además la copia aquí.
        w3d_cx12b_child_view_initialize_802b3c5c(self->view, self->scene);
        self->state = 2;
    }
}


