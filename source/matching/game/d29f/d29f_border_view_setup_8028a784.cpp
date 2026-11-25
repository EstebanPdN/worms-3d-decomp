// GWMP8P rev0 0x8028a784. Builds a node's border view on first use: ensures
// the scene exists, creates the view object, registers it with the node's
// owner, reads FE.BorderThickness, sets its size from the node's width and
// height, rebuilds its layout and attaches it to the scene. Field names are
// inferred; the unit owns no data.
struct Obj { void **table; };
inline void retain(Obj *p) { if (p) ((void (*)(Obj *))p->table[3])(p); }
inline void release(Obj *p) { if (p) ((void (*)(Obj *))p->table[4])(p); }
struct Handle {
    Obj *p;
    Handle() : p(0) {}
    Handle(const Handle &o) : p(o.p) { retain(p); }
    ~Handle() { release(p); }
};
struct Key { const char *text; Key(const char *p) : text(p) {} };
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(const Vec3 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct Node {
    char pad0[20];
    void *owner;
    char pad1[704 - 24];
    int state;
    char pad2[988 - 708];
    Handle scene;
    void *view;
    float width, height;
};
extern char lbl_8041c660[], lbl_803cfb54[];
extern float lbl_803cfb68[];
extern int lbl_804abb60;
struct Svc { void *p; };
extern Svc lbl_804b178c;
extern "C" void d25f_node_scene_setup_8028a900(Node *);
extern "C" void *w3d_s10_service_forward_8020b680(void *);
extern "C" int fn_80164514(void *, void *, void *);
extern "C" int w3d_constructor_lookup_name(const Key &, Handle &);
extern "C" void *w3d_empty_80342a74(Obj *);
extern "C" float w3d_auto_80178df0(void *);
extern "C" void w3d_auto_802b310c(void *, float);
extern "C" void w3d_set_triple_802b3020(void *, const Vec3 &);
extern "C" void w3d_auto_802b30c0(void *, float, float);
extern "C" void d10b_rebuild_layout_802b3d04(void *, int, int);
extern "C" Handle w3d_cx12b_child_view_initialize_802b3c5c(void *, Handle);
extern "C" void d29f_border_view_setup_8028a784(Node *self) {
    if (self->scene.p == 0)
        d25f_node_scene_setup_8028a900(self);
    if (self->view == 0) {
        lbl_804abb60 += 10;
        Vec3 v;
        void *view = w3d_s10_service_forward_8020b680(lbl_8041c660);
        self->view = view;
        fn_80164514(lbl_804b178c.p, view, self->owner);
        Handle border;
        w3d_constructor_lookup_name(lbl_803cfb54, border);
        w3d_auto_802b310c(self->view, w3d_auto_80178df0(w3d_empty_80342a74(border.p)));
        float one = lbl_803cfb68[0];
        Vec3 *p = &v;
        v.x = self->width;
        p->y = self->height;
        p->z = one;
        w3d_set_triple_802b3020(self->view, Vec3(*p));
        w3d_auto_802b30c0(self->view, one, one);
        d10b_rebuild_layout_802b3d04(self->view, 1, 0);
        w3d_cx12b_child_view_initialize_802b3c5c(self->view, self->scene);
        self->state = 2;
    }
}
