// GWMP8P rev0 0x8028c8e4. Lays out a frontend spinner box: clears its texts,
// creates the FE.Textbox.Back box once with its colour, builds the
// highlight, FE.NewBox.Highlight and optional FE.NewBox.Grey parts at depth
// + 32, sizes and places each part, then positions the box. Field names are
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
struct Ref {
    Obj *p;
    Ref &operator=(Obj *q) { retain(q); release(p); p = q; return *this; }
};
extern "C" void w3d_string_base_finish(void *), w3d_string_release(void *);
struct String {
    char *text;
    String(const char *);
    String(const String &);
    unsigned Length() const { return ((unsigned short *)text)[-2]; }
    ~String() { w3d_string_base_finish(this); w3d_string_release(this); }
};
struct Vec3 {
    float x, y, z;
    Vec3(const Vec3 &o) { Vec3 *p = this; float a = o.x, b = o.y, c = o.z; x = a; p->y = b; p->z = c; }
    Vec3(float a, float b, float c) { Vec3 *p = this; x = a; p->y = b; p->z = c; }
};
struct Colour { int value; };
struct Owner { char pad[60]; String label; char pad2[120 - 64]; void *f120; };
struct Control {
    char pad0[28];
    char sized[7];
    unsigned char depth;
    char pad1[4];
    Owner *owner;
    char pad2[112 - 44];
    Obj *parent;
    char pad3[212 - 116];
    void *highlights[3];
    Ref box;
    void *colour;
    char pad4[316 - 232];
    Vec3 position;
};
extern char lbl_803cfd8c[], lbl_803cfd9c[], lbl_803cfdb0[];
extern float lbl_803cfe14[], lbl_803cfe18[];
extern Vec3 lbl_8045e788[];
extern "C" void w3d_s4_spinner_clear_texts(Control *);
extern "C" int w3d_handle_set_name(String *, Handle *, unsigned char);
extern "C" Obj *w3d_empty_8034357c(Obj *);
extern "C" int *w3d_auto_80178f54(void *);
extern "C" int d26j_set_colour_80173df0(Obj *, Colour *);
extern "C" void *w3d_heap_allocate_entry_a(unsigned);
extern "C" const char *w3d_auto_80263c24(int);
extern "C" void *s11_named_handle_8025dffc(void *, const char *, unsigned char);
extern "C" float tsonnet_c31_text_size_802b1880(void *);
extern "C" void fn_8025e128(void *, float, float, float);
extern "C" void w3d_forward_to_held_8025ee60(void *, Vec3 *);
extern "C" void w3d_call_with_owner_8025ee94(void *, Obj *);
extern "C" void d25f_panel_visibility_8028c160(Control *);
inline void SetBox(Control *self, const String &name) {
    Handle h;
    w3d_handle_set_name((String *)&name, &h, self->depth + 31);
    self->box = w3d_empty_8034357c(h.p);
}
inline void Place(Obj *box, const Vec3 &v) { ((void (*)(Obj *, const Vec3 *, int))box->table[21])(box, &v, 0); }
inline void Reset(void *sized, Vec3 v) { tsonnet_c31_text_size_802b1880(sized); }
extern "C" void d29f_spinner_box_layout_8028c8e4(Control *self, float scale, float x, float y) {
    Owner *owner = self->owner;
    w3d_s4_spinner_clear_texts(self);
    if (self->box.p == 0) {
        SetBox(self, String(lbl_803cfd8c));
        ((void (*)(Obj *, Obj *, int))self->parent->table[23])(self->parent, self->box.p, 0);
        Colour c;
        c.value = *w3d_auto_80178f54(self->colour);
        d26j_set_colour_80173df0(self->box.p, &c);
    }
    self->highlights[0] = s11_named_handle_8025dffc(w3d_heap_allocate_entry_a(4), w3d_auto_80263c24((int)owner->f120), self->depth + 32);
    self->highlights[1] = s11_named_handle_8025dffc(w3d_heap_allocate_entry_a(4), lbl_803cfd9c, self->depth + 32);
    if (owner->label.Length() != 0)
        self->highlights[2] = s11_named_handle_8025dffc(w3d_heap_allocate_entry_a(4), lbl_803cfdb0, self->depth + 32);
    Reset(self->sized, lbl_8045e788[0]);
    for (unsigned i = 0; i <= 2; i++) {
        if (self->highlights[i]) {
            fn_8025e128(self->highlights[i], scale, x, y);
            w3d_forward_to_held_8025ee60(self->highlights[i], &self->position);
            w3d_call_with_owner_8025ee94(self->highlights[i], self->parent);
        }
    }
    float half = scale * lbl_803cfe14[0];
    Place(self->box.p, Vec3(x - half, y - half, lbl_803cfe18[0]));
    ((void (*)(Obj *, Vec3 *, int))self->box.p->table[19])(self->box.p, &self->position, 0);
    d25f_panel_visibility_8028c160(self);
}
