// GWMP8P rev0 0x80295268. Sets up a frontend box border: creates the named
// border node at unit scale, attaches it to the model, reads the border
// thickness and stores the derived width and height fields. Field names are
// inferred; the unit owns no data.
// Observed handle, string and view object slices; roles inferred.
struct Vec3 { float x, y, z; Vec3() {} };
struct Obj { void **vtable; };
inline void retain(Obj *p) { ((void (*)(Obj *))p->vtable[3])(p); }
inline void release(Obj *p) { ((void (*)(Obj *))p->vtable[4])(p); }
struct Handle {
    Obj *p;
    Handle() : p(0) {}
    Handle(const Handle &);
    ~Handle() { if (p) release(p); }
};
extern "C" void w3d_string_base_finish(void *), w3d_string_release(void *);
struct String {
    char *text;
    String(const char *);
    String(const String &);
    ~String() { w3d_string_base_finish(this); w3d_string_release(this); }
};
struct Key { const char *text; Key(const char *p) : text(p) {} };
struct Self {
    char pad[32]; char transform[24]; int active; char pad60[60]; Obj *model; Obj *node; char pad128[28]; Obj *border; float f160, f164, f168;
};
extern char lbl_803d0798[], lbl_803d07a0[];
extern float lbl_803d07b4[], lbl_803d07b8[], lbl_803d07bc[];
extern "C" int w3d_handle_set_name(String *, Obj **, int);
extern "C" int w3d_constructor_lookup_name(const Key &, Handle *);
extern "C" Obj *w3d_empty_80342a74(Obj *);
extern "C" float w3d_auto_80178df0(Obj *);
extern "C" void fn_80295cec(Self *);
inline void Scale(Obj *f, const Vec3 &v) { ((int (*)(Obj *, const Vec3 *, int))f->vtable[21])(f, &v, 0); }
extern "C" void d29f_border_setup_80295268(Self *self, Handle h) {
    self->active = 1;
    {
        String name(lbl_803d0798);
        w3d_handle_set_name(&name, &self->node, 255);
    }
    Vec3 v;
    Vec3 *p = &v;
    float s = lbl_803d07b4[0];
    v.x = s;
    p->y = s;
    p->z = s;
    Scale(self->node, *p);
    ((void (*)(Obj *, void *, int))self->node->vtable[19])(self->node, self->transform, 0);
    if (h.p) retain(h.p);
    if (self->model) release(self->model);
    self->model = h.p;
    ((void (*)(Obj *, Obj *, int))self->model->vtable[23])(self->model, self->node, 0);
    Handle tmp;
    w3d_constructor_lookup_name(lbl_803d07a0, &tmp);
    Obj *border = w3d_empty_80342a74(tmp.p);
    if (border) retain(border);
    if (self->border) release(self->border);
    self->border = border;
    float width = w3d_auto_80178df0(border);
    float scale = lbl_803d07b8[0];
    self->f168 = width * scale;
    width = w3d_auto_80178df0(self->border);
    self->f160 = self->f168 * lbl_803d07bc[0];
    self->f164 = width * scale;
    fn_80295cec(self);
}
