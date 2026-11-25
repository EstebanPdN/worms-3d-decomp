// GWMP8P rev0 0x8029ec80. Lays out a text list: fits the text at decreasing
// sizes and, for a scrolling list, adds a blank line, a rule of hyphens and
// another blank line. Names are inferred. Line height is zero in the
// constructor; callers overwrite it, and flow deletes that dead store where
// no call follows.
#include "compat/stlport_sn_oom.h"
#include <vector>
#include <stl/_algobase.h>
extern const char text_empty_803d0f78[], text_space_803d0f60[], text_hyphen_803d1db8[];
extern "C" void w3d_string_release_header(unsigned short *);
struct Text {
    char *text;
    Text();
    Text(const char *);
    Text(const Text &);
    ~Text();
    Text &operator=(const Text &o) {
        ++*(unsigned short *)(o.text - 6);
        unsigned short *header = (unsigned short *)(text - 6);
        if (--*header == 0) w3d_string_release_header(header);
        text = o.text;
        return *this;
    }
};
extern "C" void w3d_string_base_finish(Text *);
extern "C" void w3d_string_release(Text *);
inline Text::~Text() { w3d_string_base_finish(this); w3d_string_release(this); }
extern "C" Text *w3d_string_assign(Text *, const char *);
extern "C" Text *w3d_string_append(Text *, const char *);
struct Obj { virtual void s0(); virtual void s1(); virtual void release(); };
struct Ref { Obj *p; Ref() : p(0) {} Ref &operator=(Obj *q) { if (p) p->release(); p = q; return *this; } };
struct Line {
    Ref ref; int length; Text text; float height; int index;
    Line() { ref = 0; length = 0; w3d_string_assign(&text, text_empty_803d0f78); index = 0; height = 0.0f; }
};
struct Style {
    char u0[20]; float w, h; char u28[100]; int fitted; char u132[8]; Text key; char u144[4]; int wrap; int shrink;
};
struct Font;
extern "C" Font *w3d_runtime_service_lookup(const Text &);
extern "C" Font *w3d_empty_8034435c(Font *);
extern "C" float s9_permute_8018b4cc(Font *, const char *);
extern "C" float w3d_cx9c_floorf_802e87d4(float);
struct Part;
extern "C" float tsonnet_c31_text_size_802b1880(Part *);
struct List {
    char u0[28]; char part[12]; Style *style; char u44[224]; float total; char u272[16];
    int mode; int ticks; float u296; float rate; char u304[12]; float margin; char u320[16];
    _STL::vector<Line *> lines; char u352[28]; float zero;
};
extern char buffer_80470930[];
extern char *lbl_804b0e6c;
extern float k5_803d1dbc[];
extern "C" void d25l_expand_text_properties_8029eb3c(const char *);
extern "C" void d24l_text_list_lines_8029f598(List *, const char *, float, float);
extern "C" void d25l_text_list_scroll_box_b_802a047c(List *);
extern "C" void w3d_s4_text_list_remove_box(List *);
extern "C" void fn_802a0f98(List *, float, float, float);
extern "C" void fn_802a06ac(List *, float, float, float);
extern "C" void w3d_empty_802a0c44(List *);
extern "C" void d41l_text_list_layout_8029ec80(List *self, const char *text) {
    Style *st = self->style;
    float margin = self->margin;
    float size = tsonnet_c31_text_size_802b1880((Part *)self->part);
    if (size < k5_803d1dbc[0]) size = k5_803d1dbc[0];
    float height = 0.0f;
    lbl_804b0e6c = buffer_80470930;
    d25l_expand_text_properties_8029eb3c(text);
    {
        char **out = &lbl_804b0e6c;
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
                float s = tsonnet_c31_text_size_802b1880((Part *)self->part);
                Line *top = new Line;
                top->height = s;
                w3d_string_assign(&top->text, text_space_803d0f60);
                top->length = 2;
                self->lines.push_back(top);
                room /= s;
                top->index = self->lines.size();
                Line *rule = new Line;
                Font *font = w3d_empty_8034435c(w3d_runtime_service_lookup(st->key));
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
                Line *end = new Line;
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
