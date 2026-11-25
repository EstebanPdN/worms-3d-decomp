#include "w3d_ptr.h"
#line 1 "d28l_textbox_place_cursor_802a21ec.cpp"
// GWMP8P rev0 0x802a21ec. Places a text box cursor: finds the line holding
// the character index, works out its position from the box alignment flags
// (low two bits vertical, next two horizontal) and the text and range
// widths, moves the cursor node and hides it when a masked box scrolls it
// out of range. Names are inferred; the local copy of the caption position
// is written by the original.
struct Vec {
    float x, y, z;
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
};
struct Color {
    signed char r, g, b;
    unsigned char a;
    Color(int x, int y, int z, int w) { r = x; g = y; b = z; a = w; }
};
struct Text;
struct TextVt { char u0[100]; Ptr32<w3d::Ref32<Vec>(Ptr32<Text>)> position; };
struct Text { Ptr32<TextVt> vt; };
struct Line { Ptr32<Text> text; unsigned count; };
struct LineList { Ptr32<Ptr32<Line>> first; Ptr32<Ptr32<Line>> last; Ptr32<Ptr32<Line>> end() { return last; } };
struct Node;
struct NodeVt { char u0[76]; Ptr32<void (Ptr32<Node>, Ptr32<Vec>, int)> place; };
struct Node { Ptr32<NodeVt> vt; };
struct Desc {
    char u0[20];
    Vec v20;
    char u32[92];
    int align;
};
struct Panel {
    char u0[12];
    Ptr32<Desc> desc;
};
struct Self {
    char u0[28];
    Panel panel;
    char u44[264];
    Ptr32<Text> caption;
    char u312[4];
    float w316;
    char u320[16];
    LineList lines;
    char u344[32];
    int masked;
    char u380[12];
    Ptr32<Node> node;
    char u396[8];
    unsigned cursor;
    int line;
};
extern int aligns_80401c50[];
extern "C" float fn_802b1880(Ptr32<Panel>);
extern "C" float fn_8018c8bc(Ptr32<Text>);
extern "C" float fn_8018c938(Ptr32<Text>, int, unsigned);
extern "C" void fn_802a2524(Ptr32<Self>);
extern "C" int fn_80173df0(Ptr32<Node>, Ptr32<Color>);
extern "C" void d28l_textbox_place_cursor_802a21ec(Ptr32<Self> self) {
    Ptr32<Desc> d = self->panel.desc;
    Vec pos(0.0f, 0.0f, 0.0f);
    self->line = 0;
    int flags = aligns_80401c50[d->align];
    unsigned cursor = self->cursor;
    Ptr32<Ptr32<Line>> it = self->lines.first;
    if (self->masked) {
        flags = (flags & 0xc) + 1;
    }
    switch (flags & 3) {
    case 1:
        pos.y = 0.0f - fn_802b1880(&self->panel) * 0.5f;
        break;
    case 0:
        pos.y = 0.0f;
        break;
    case 2:
        pos.y = fn_802b1880(&self->panel) * 0.5f;
        break;
    }
    for (; it != self->lines.end(); it++) {
        if ((*it)->count >= cursor) {
            float width = fn_8018c8bc((*it)->text);
            float range = fn_8018c938((*it)->text, 0, cursor);
            pos = (*it)->text->vt->position((*it)->text);
            switch (flags & 0xc) {
            case 4:
                pos.x = pos.x + range;
                break;
            case 0:
                pos.x += range - width * 0.5f;
                break;
            case 8:
                pos.x = pos.x - (width - range);
                break;
            }
            switch (flags & 3) {
            case 1:
                pos.y = pos.y - fn_802b1880(&self->panel) * 0.5f;
                break;
            case 2:
                pos.y = fn_802b1880(&self->panel) * 0.5f + pos.y;
                break;
            }
            break;
        }
        cursor -= (*it)->count;
        self->line++;
    }
    int alpha = 255;
    fn_802a2524(self);
    self->node->vt->place(self->node, &pos, 0);
    if (self->masked) {
        const Vec &v = d->v20;
        float hi = v.y - self->w316 - fn_802b1880(&self->panel) * 0.5f;
        float lo = fn_802b1880(&self->panel) * 0.5f + (0.0f - v.y + self->w316);
        Vec &o = self->caption->vt->position(self->caption);
        Vec box(o.x, o.y, o.z); hi -= box.y; lo -= box.y;
        if (pos.y < lo || pos.y > hi) {
            alpha = 0;
        }
    }
    Color c(-1, -1, -1, alpha);
    fn_80173df0(self->node, &c);
}


