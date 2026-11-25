// GWMP8P rev0 0x8028ba38. Frontend panel setup: loads the label, normal,
// grey and colour images, the text part and on first use the border pieces.
struct Obj { void **vtable; };
inline void retain(Obj *p) { ((void (*)(Obj *))p->vtable[3])(p); }
inline void release(Obj *p) { ((void (*)(Obj *))p->vtable[4])(p); }
extern "C" void w3d_string_base_finish(void *), w3d_string_release(void *);
struct String {
    char *text;
    String();
    String(const char *);
    String(const String &);
    ~String() { w3d_string_base_finish(this); w3d_string_release(this); }
    unsigned short length() const { return *(unsigned short *)(text - 4); }
};
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(const Vec3 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct Handle {
    Obj *p;
    Handle() : p(0) {}
    Handle(const Handle &);
    ~Handle() { if (p) release(p); }
};
struct Ref {
    Obj *p;
    Ref &operator=(Obj *q) {
        if (q) retain(q);
        if (p) release(p);
        p = q;
        return *this;
    }
};
struct Colour { unsigned char r, g, b, a; };
struct Named;
struct Data { char pad[20]; Vec3 transform; char pad32[28]; String extra; char pad64[56]; int colour; String file; char pad128[8]; String first; char pad140[12]; float thickness; String name; };
struct Self { char pad[28]; char owner[7]; unsigned char level; char pad36[4]; Data *data; char pad44[64]; String error; Obj *list; char pad116[96]; Named *named[3]; Ref back; Obj *tint; Ref image, high, grey, label, part; char pad252[64]; Vec3 offset; };
typedef const char *Text;
extern char lbl_803cfcfc[], lbl_803cfd20[], lbl_803cfd2c[], lbl_803cfd38[], lbl_803cfd40[], lbl_803cfd48[], lbl_803cfd50[], lbl_803cfd58[], lbl_803cfd5c[], lbl_803cfd8c[], lbl_803cfd9c[], lbl_803cfdb0[], lbl_803cfdc0[];

extern Vec3 lbl_8045e788;
extern "C" int w3d_named_suffix_802b1510(char *, const char *, Ref *, unsigned char);
extern "C" int w3d_handle_set_name(String *, void *, unsigned char);
extern "C" Obj *w3d_empty_8034357c(Obj *), *w3d_empty_80343580(Obj *);
extern "C" void w3d_string_format(String *, const char *, ...);
extern "C" String *w3d_string_assign(void *, const char *);
extern "C" float tsonnet_c31_text_size_802b1880(char *);
extern "C" int s9_permute_8018d324(Obj *, int);
extern "C" float d20d_text_width_8018c8bc(Obj *), w3d_getf_8018ca14(Obj *);
extern "C" Colour *w3d_auto_80178f54(Obj *);
extern "C" int d26j_set_colour_80173df0(Obj *, Colour);
extern "C" void *w3d_heap_allocate_entry_a(unsigned);
extern "C" const char *w3d_auto_80263c24(int);
extern "C" Named *s11_named_handle_8025dffc(void *, const char *, unsigned char);
extern "C" int w3d_auto_800fc270(const Text &, float *);
extern "C" void fn_8025e128(Named *, float, float, float);
extern "C" void w3d_forward_to_held_8025ee60(Named *, const Vec3 *);
extern "C" void w3d_call_with_owner_8025ee94(Named *, Obj *);
extern "C" void d25f_panel_visibility_8028c160(Self *);
inline void Add(Self *self, Obj *o) { ((int (*)(Obj *, Obj *, int))self->list->vtable[23])(self->list, o, 0); }
inline void Place(Self *self, Obj *o) { ((int (*)(Obj *, Vec3 *, int))o->vtable[21])(o, &self->data->transform, 0); }
inline void Scale(Obj *o, const Vec3 *v) { ((int (*)(Obj *, const Vec3 *, int))o->vtable[21])(o, v, 0); }
inline void Move(Obj *o, const Vec3 *v) { ((int (*)(Obj *, const Vec3 *, int))o->vtable[19])(o, v, 0); }
inline void Fmt(String &s, Data *data, const char *x) { w3d_string_format(&s, data->file.text, x); }
inline void Into(Ref &dst, const String &name, int id) {
    Handle h;
    w3d_handle_set_name((String *)&name, &h, id);
    dst = w3d_empty_8034357c(h.p);
}
extern "C" void w3d_d40f_panel_build_8028ba38(Self *self) {
    Data *data = self->data;
    if (data->first.length() != 0) {
        Ref *slot = &self->label;
        if (w3d_named_suffix_802b1510(self->owner, data->first.text, slot, self->level + 30) < 0) {
            w3d_string_format(&self->error, lbl_803cfcfc, data->first.text);
            String name(lbl_803cfd20);
            w3d_handle_set_name(&name, slot, self->level + 30);
        }
        if (self->label.p) {
            Add(self, self->label.p);
            Place(self, self->label.p);
        }
    }
    char *owner = self->owner;
    String text;
    if (data->file.length() != 0) {
        w3d_string_format(&text, data->file.text, lbl_803cfd2c);
        if (w3d_named_suffix_802b1510(owner, text.text, &self->high, self->level + 29) < 0)
            w3d_string_format(&self->error, lbl_803cfcfc, text.text);
        else {
            Add(self, self->high.p);
            Place(self, self->high.p);
        }
        w3d_string_format(&text, data->file.text, lbl_803cfd38);
        if (w3d_named_suffix_802b1510(owner, text.text, &self->grey, self->level + 29) >= 0) {
            Add(self, self->grey.p);
            Place(self, self->grey.p);
        }
        if (data->colour != 0) {
            switch (data->colour) {
            case 1: Fmt(text, data, lbl_803cfd40); break;
            case 2: Fmt(text, data, lbl_803cfd48); break;
            case 3: Fmt(text, data, lbl_803cfd40); break;
            case 4: Fmt(text, data, lbl_803cfd50); break;
            case 5: Fmt(text, data, lbl_803cfd58); break;
            default: w3d_string_assign(&text, lbl_803cfd5c); break;
            }
            if (w3d_named_suffix_802b1510(owner, text.text, &self->image, self->level + 29) < 0)
                w3d_string_format(&self->error, lbl_803cfcfc, text.text);
            else {
                Add(self, self->image.p);
                Place(self, self->image.p);
            }
        }
    }
    Vec3 scale;
    Vec3 place;
    Vec3 *pp = &place;
    const Vec3 &pos = data->transform;
    w3d_handle_set_name(&data->name, &self->part, self->level + 32);
    Add(self, self->part.p);
    Obj *label = w3d_empty_80343580(self->part.p);
    float size = tsonnet_c31_text_size_802b1880(owner);
    Vec3 *sp = &scale;
    scale.x = size;
    scale.y = size;
    sp->z = 1.0f;
    Scale(label, sp);
    s9_permute_8018d324(label, 0);
    float width = d20d_text_width_8018c8bc(label);
    float height = w3d_getf_8018ca14(label);
    float zero = 0.0f;
    float y = zero - pos.y;
    float half = 0.5f;
    float centre = height * half;
    place.x = zero;
    place.y = y + centre;
    pp->z = zero;
    Move(label, pp);
    if (self->named[0] == 0) {
        do { { String name(lbl_803cfd8c); Into(self->back, name, self->level + 31); } Add(self, self->back.p); } while (0);
        d26j_set_colour_80173df0(self->back.p, *w3d_auto_80178f54(self->tint));
        void *memory = w3d_heap_allocate_entry_a(4);
        self->named[0] = s11_named_handle_8025dffc(memory, w3d_auto_80263c24(data->colour), self->level + 32);
        self->named[1] = s11_named_handle_8025dffc(w3d_heap_allocate_entry_a(4), lbl_803cfd9c, self->level + 32);
        if (data->extra.length() != 0)
            self->named[2] = s11_named_handle_8025dffc(w3d_heap_allocate_entry_a(4), lbl_803cfdb0, self->level + 32);
        Vec3 box = lbl_8045e788;
        Vec3 *bp = &box;
        float border;
        w3d_auto_800fc270(lbl_803cfdc0, &border);
        if (data->thickness != zero)
            border = data->thickness;
        place.y += size * 0.0625f;
        float inset = border * half;
        float top = centre + inset;
        float right = width * half + inset;
        self->offset = place;
        for (unsigned i = 0; i <= 2; i++) {
            if (self->named[i]) {
                fn_8025e128(self->named[i], border, right, top);
                w3d_forward_to_held_8025ee60(self->named[i], &place);
                w3d_call_with_owner_8025ee94(self->named[i], self->list);
            }
        }
        float back = border * 0.5f;
        bp->z = 1.0f;
        box.x = right - back;
        box.y = top - back;
        Scale(self->back.p, bp);
        { Vec3 *q = &place; Move(self->back.p, q); }
    }
    d25f_panel_visibility_8028c160(self);
}
