#include "w3d_ptr.h"
#line 1 "d40f_panel_build_8028ba38.cpp"
// GWMP8P rev0 0x8028ba38. Frontend panel setup: loads the label, normal,
// grey and colour images, the text part and on first use the border pieces.
struct Obj { Ptr32<Ptr32<void>> vtable; };
inline void retain(Ptr32<Obj> p) { ((Ptr32<void (Ptr32<Obj>)>)p->vtable[3])(p); }
inline void release(Ptr32<Obj> p) { ((Ptr32<void (Ptr32<Obj>)>)p->vtable[4])(p); }
extern "C" void w3d_string_base_finish(Ptr32<void>), w3d_string_release(Ptr32<void>);
struct String {
    Ptr32<char> text;
    String();
    template <class W3dU> String(Ptr32<W3dU> w3d_p) : String((const char *)w3d_p.get()) {}
 String(const char *);
    String(const String &);
    ~String() { w3d_string_base_finish(this); w3d_string_release(this); }
    unsigned short length() const { return *(Ptr32<unsigned short>)(text - 4); }
};
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(const Vec3 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct Handle {
    Ptr32<Obj> p;
    Handle() : p(0) {}
    Handle(const Handle &);
    ~Handle() { if (p) release(p); }
};
struct Ref {
    Ptr32<Obj> p;
    template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((Obj *)w3d_p.get()); }
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
struct Self { char pad[28]; char owner[4]; unsigned char level; char w3d_tag_rest[3]; char pad36[4]; Ptr32<Data> data; char pad44[64]; String error; Ptr32<Obj> list; char pad116[96]; Ptr32<Named> named[3]; Ref back; Ptr32<Obj> tint; Ref image, high, grey, label, part; char pad252[64]; Vec3 offset; };
typedef Ptr32<const char> Text;
extern char lbl_803cfcfc[], lbl_803cfd20[], lbl_803cfd2c[], lbl_803cfd38[], lbl_803cfd40[], lbl_803cfd48[], lbl_803cfd50[], lbl_803cfd58[], lbl_803cfd5c[], lbl_803cfd8c[], lbl_803cfd9c[], lbl_803cfdb0[], lbl_803cfdc0[];

extern Vec3 lbl_8045e788;
extern "C" int w3d_named_suffix_802b1510(Ptr32<char>, Ptr32<const char>, Ptr32<Ref>, unsigned char);
extern "C" int w3d_handle_set_name(Ptr32<String>, Ptr32<void>, unsigned char);
extern "C" Ptr32<Obj> w3d_empty_8034357c(Ptr32<Obj>); Ptr32<Obj> w3d_empty_80343580(Ptr32<Obj>);
extern "C" void w3d_string_format(Ptr32<String>, Ptr32<const char>, ...);
extern "C" Ptr32<String> w3d_string_assign(Ptr32<void>, Ptr32<const char>);
extern "C" float tsonnet_c31_text_size_802b1880(Ptr32<char>);
extern "C" int s9_permute_8018d324(Ptr32<Obj>, int);
extern "C" float d20d_text_width_8018c8bc(Ptr32<Obj>), w3d_getf_8018ca14(Ptr32<Obj>);
extern "C" Ptr32<Colour> w3d_auto_80178f54(Ptr32<Obj>);
// Recibe un puntero al color: en el ABI de PowerPC una estructura por valor viaja como puntero a una copia. Con
// `Colour` por valor, en ARM los cuatro bytes del color iban en r1 y 80173df0 los leía como dirección: data abort con
// far=b3563c05 (color 02 3c 56 b3) al abrir "Landscape Selection" en multijugador (v13 y v21, se reiniciaba la consola).
extern "C" int d26j_set_colour_80173df0(Ptr32<Obj>, Ptr32<const Colour>);
extern "C" Ptr32<void> w3d_heap_allocate_entry_a(unsigned);
extern "C" Ptr32<const char> w3d_auto_80263c24(int);
extern "C" Ptr32<Named> s11_named_handle_8025dffc(Ptr32<void>, Ptr32<const char>, unsigned char);
extern "C" int w3d_auto_800fc270(const Text &, Ptr32<float>);
extern "C" void fn_8025e128(Ptr32<Named>, float, float, float);
extern "C" void w3d_forward_to_held_8025ee60(Ptr32<Named>, Ptr32<const Vec3>);
extern "C" void w3d_call_with_owner_8025ee94(Ptr32<Named>, Ptr32<Obj>);
extern "C" void d25f_panel_visibility_8028c160(Ptr32<Self>);
inline void Add(Ptr32<Self> self, Ptr32<Obj> o) { ((Ptr32<int (Ptr32<Obj>, Ptr32<Obj>, int)>)self->list->vtable[23])(self->list, o, 0); }
inline void Place(Ptr32<Self> self, Ptr32<Obj> o) { ((Ptr32<int (Ptr32<Obj>, Ptr32<Vec3>, int)>)o->vtable[21])(o, &self->data->transform, 0); }
inline void Scale(Ptr32<Obj> o, Ptr32<const Vec3> v) { ((Ptr32<int (Ptr32<Obj>, Ptr32<const Vec3>, int)>)o->vtable[21])(o, v, 0); }
inline void Move(Ptr32<Obj> o, Ptr32<const Vec3> v) { ((Ptr32<int (Ptr32<Obj>, Ptr32<const Vec3>, int)>)o->vtable[19])(o, v, 0); }
inline void Fmt(String &s, Ptr32<Data> data, Ptr32<const char> x) { w3d_string_format(&s, data->file.text, w3d::VA(x)); }
inline void Into(Ref &dst, const String &name, int id) {
    Handle h;
    w3d_handle_set_name((Ptr32<String>)&name, &h, id);
    dst = w3d_empty_8034357c(h.p);
}
extern "C" void w3d_d40f_panel_build_8028ba38(Ptr32<Self> self) {
    Ptr32<Data> data = self->data;
    if (data->first.length() != 0) {
        Ptr32<Ref> slot = &self->label;
        if (w3d_named_suffix_802b1510(self->owner, data->first.text, slot, self->level + 30) < 0) {
            w3d_string_format(&self->error, lbl_803cfcfc, w3d::VA(data->first.text));
            String name(lbl_803cfd20);
            w3d_handle_set_name(&name, slot, self->level + 30);
        }
        if (self->label.p) {
            Add(self, self->label.p);
            Place(self, self->label.p);
        }
    }
    Ptr32<char> owner = self->owner;
    String text;
    if (data->file.length() != 0) {
        w3d_string_format(&text, data->file.text, w3d::VA(lbl_803cfd2c));
        if (w3d_named_suffix_802b1510(owner, text.text, &self->high, self->level + 29) < 0)
            w3d_string_format(&self->error, lbl_803cfcfc, w3d::VA(text.text));
        else {
            Add(self, self->high.p);
            Place(self, self->high.p);
        }
        w3d_string_format(&text, data->file.text, w3d::VA(lbl_803cfd38));
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
                w3d_string_format(&self->error, lbl_803cfcfc, w3d::VA(text.text));
            else {
                Add(self, self->image.p);
                Place(self, self->image.p);
            }
        }
    }
    Vec3 scale;
    Vec3 place;
    Ptr32<Vec3> pp = &place;
    const Vec3 &pos = data->transform;
    w3d_handle_set_name(&data->name, &self->part, self->level + 32);
    Add(self, self->part.p);
    Ptr32<Obj> label = w3d_empty_80343580(self->part.p);
    float size = tsonnet_c31_text_size_802b1880(owner);
    Ptr32<Vec3> sp = &scale;
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
        { Colour tint = *w3d_auto_80178f54(self->tint); d26j_set_colour_80173df0(self->back.p, &tint); }
        Ptr32<void> memory = w3d_heap_allocate_entry_a(4);
        self->named[0] = s11_named_handle_8025dffc(memory, w3d_auto_80263c24(data->colour), self->level + 32);
        self->named[1] = s11_named_handle_8025dffc(w3d_heap_allocate_entry_a(4), lbl_803cfd9c, self->level + 32);
        if (data->extra.length() != 0)
            self->named[2] = s11_named_handle_8025dffc(w3d_heap_allocate_entry_a(4), lbl_803cfdb0, self->level + 32);
        Vec3 box = lbl_8045e788;
        Ptr32<Vec3> bp = &box;
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
        { Ptr32<Vec3> q = &place; Move(self->back.p, q); }
    }
    d25f_panel_visibility_8028c160(self);
}


