#include "w3d_ptr.h"
#line 1 "d41l_text_list_layout_8029ec80.cpp"
// GWMP8P rev0 0x8029ec80. Lays out a text list: fits the text at decreasing
// sizes and, for a scrolling list, adds a blank line, a rule of hyphens and
// another blank line. Names are inferred. Line height is zero in the
// constructor; callers overwrite it, and flow deletes that dead store where
// no call follows.
#include "compat/stlport_sn_oom.h"
#include <vector>
#include <stl/_algobase.h>
extern const char text_empty_803d0f78[], text_space_803d0f60[], text_hyphen_803d1db8[];
extern "C" void w3d_string_release_header(Ptr32<unsigned short>);
struct Text {
    Ptr32<char> text;
    Text();
    template <class W3dU> Text(Ptr32<W3dU> w3d_p) : Text((const char *)w3d_p.get()) {}
 Text(const char *);
    Text(const Text &);
    ~Text();
    Text &operator=(const Text &o) {
        ++*(Ptr32<unsigned short>)(o.text - 6);
        Ptr32<unsigned short> header = (Ptr32<unsigned short>)(text - 6);
        if (--*header == 0) w3d_string_release_header(header);
        text = o.text;
        return *this;
    }
};
extern "C" void w3d_string_base_finish(Ptr32<Text>);
extern "C" void w3d_string_release(Ptr32<Text>);
inline Text::~Text() { w3d_string_base_finish(this); w3d_string_release(this); }
extern "C" Ptr32<Text> w3d_string_assign(Ptr32<Text>, Ptr32<const char>);
extern "C" Ptr32<Text> w3d_string_append(Ptr32<Text>, Ptr32<const char>);
struct Obj { void w3d_r_s0() __asm__(W3D_SYM("_ZN3Obj2s0Ev")); void w3d_r_s1() __asm__(W3D_SYM("_ZN3Obj2s1Ev")); void w3d_r_release() __asm__(W3D_SYM("_ZN3Obj7releaseEv"));  __attribute__((always_inline)) inline void s0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Obj, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Obj, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Obj, 4))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Obj; };
struct Ref { Ptr32<Obj> p; Ref() : p(0) {} template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((Obj *)w3d_p.get()); }
 Ref &operator=(Obj *q) { if (p) p->release(); p = q; return *this; } };
struct Line {
    Ref ref; int length; Text text; float height; int index;
    Line() { ref = 0; length = 0; w3d_string_assign(&text, text_empty_803d0f78); index = 0; height = 0.0f; }
};
struct Style {
    char u0[20]; float w, h; char u28[100]; int fitted; char u132[8]; Text key; char u144[4]; int wrap; int shrink;
};
struct Font;
extern "C" Ptr32<Font> w3d_runtime_service_lookup(const Text &);
extern "C" Ptr32<Font> w3d_empty_8034435c(Ptr32<Font>);
extern "C" float s9_permute_8018b4cc(Ptr32<Font>, Ptr32<const char>);
extern "C" float w3d_cx9c_floorf_802e87d4(float);
struct Part;
extern "C" float tsonnet_c31_text_size_802b1880(Ptr32<Part>);
struct List {
    char u0[28]; char part[12]; Ptr32<Style> style; char u44[224]; float total; char u272[16];
    int mode; int ticks; float u296; float rate; char u304[12]; float margin; char u320[16];
    _STL::vector <Ptr32<Line> > lines; char u352[28]; float zero;
};
extern char buffer_80470930[];
extern Ptr32<char> lbl_804b0e6c;
extern float k5_803d1dbc[];
extern "C" void d25l_expand_text_properties_8029eb3c(Ptr32<const char>);
extern "C" void d24l_text_list_lines_8029f598(Ptr32<List>, Ptr32<const char>, float, float);
extern "C" void d25l_text_list_scroll_box_b_802a047c(Ptr32<List>);
extern "C" void w3d_s4_text_list_remove_box(Ptr32<List>);
extern "C" void fn_802a0f98(Ptr32<List>, float, float, float);
extern "C" void fn_802a06ac(Ptr32<List>, float, float, float);
extern "C" void w3d_empty_802a0c44(Ptr32<List>);
extern "C" void d41l_text_list_layout_8029ec80(Ptr32<List> self, Ptr32<const char> text) {
    Ptr32<Style> st = self->style;
    float margin = self->margin;
    float size = tsonnet_c31_text_size_802b1880((Ptr32<Part>)self->part);
    if (size < k5_803d1dbc[0]) size = k5_803d1dbc[0];
    float height = 0.0f;
    lbl_804b0e6c = buffer_80470930;
    d25l_expand_text_properties_8029eb3c(text);
    {
        Ptr32<Ptr32<char>> out = &lbl_804b0e6c;
        *(*out)++ = 0;
    }
    float width;
    int done = 0;
    do {
        if (st->fitted == 0) {
            width = self->style->w * 2.0f;
            height = self->style->h * 2.0f;
        } else {
            width = (self->style->w - margin) * 2.0f;
            height = (self->style->h - margin) * 2.0f;
        }
        d24l_text_list_lines_8029f598(self, buffer_80470930, size, width);
        if (self->total > height && self->lines.size() > 1) {
            int shrink = st->shrink;
            if (shrink == 1) {
                self->ticks = 200;
                self->rate = 0.01f;
                self->mode = shrink;
                float room = (self->style->h - self->margin) * 2.0f;
                float s = tsonnet_c31_text_size_802b1880((Ptr32<Part>)self->part);
                Ptr32<Line> top = new Line;
                top->height = s;
                w3d_string_assign(&top->text, text_space_803d0f60);
                top->length = 2;
                self->lines.push_back(top);
                room /= s;
                top->index = self->lines.size();
                Ptr32<Line> rule = new Line;
                Ptr32<Font> font = w3d_empty_8034435c(w3d_runtime_service_lookup(st->key));
                float dash = s9_permute_8018b4cc(font, text_hyphen_803d1db8);
                unsigned n = (unsigned)(width / (dash * s));
                unsigned half = n >> 1;
                rule->height = s;
                Text dashes(text_empty_803d0f78);
                for (unsigned i = 0; i < half; i++) w3d_string_append(&dashes, text_hyphen_803d1db8);
                rule->text = dashes;
                rule->length = half + 1;
                rule->index = 0;
                self->lines.push_back(rule);
                Ptr32<Line> end = new Line;
                end->height = s;
                w3d_string_assign(&end->text, text_space_803d0f60);
                end->length = 2;
                self->lines.push_back(end);
                end->index = self->lines.size();
                w3d_cx9c_floorf_802e87d4(room);
                self->u296 = self->total / s; self->u296 += 2.0f;
                self->zero = 0.0f;
                done = 1;
            } else if (st->wrap) {
                if (size <= k5_803d1dbc[0]) done = 1;
                else size -= 1.0f;
            } else {
                d25l_text_list_scroll_box_b_802a047c(self);
                done = 1;
            }
        } else {
            self->mode = 0;
            w3d_s4_text_list_remove_box(self);
            done = 1;
        }
    } while (!done);
    if (self->mode == 1) fn_802a0f98(self, size, width, height);
    else fn_802a06ac(self, size, width, height);
    w3d_empty_802a0c44(self);
}


