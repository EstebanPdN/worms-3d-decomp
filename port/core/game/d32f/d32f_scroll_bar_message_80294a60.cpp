#include "w3d_ptr.h"
#line 1 "d32f_scroll_bar_message_80294a60.cpp"
// GWMP8P rev0 0x80294a60. Scroll bar message handler: init and reset cases
// go through the base handler; while this bar has the focus, wheel, press,
// release and key messages move the position, step through the arrows, or
// start and stop the thumb drag. Observed partial layouts, roles inferred.
struct Cache { int v[2]; };
extern Cache lbl_804b0d94, lbl_804b0d6c, lbl_804b0d74, lbl_804b0d7c, lbl_804b0d84, lbl_804b0d64, lbl_804b0d5c;
extern float lbl_803d0778[], lbl_803d077c[], lbl_803d0780[], lbl_803d0784[], lbl_803d0788[];
struct Message { unsigned short id; };
struct Input { char pad[96]; unsigned int low:24; unsigned int grabbed:1; unsigned int high:7; };
extern Ptr32<Input> lbl_804aac54;
extern int lbl_804abb5c, lbl_804abb48;
struct Vec { float x, y, z; };
struct Box;
extern "C" int fn_8015fb34(Ptr32<Box>, Ptr32<Message>);
extern "C" void fn_802950c8(Ptr32<Box>), fn_80295204(Ptr32<Box>), fn_80296410(Ptr32<Box>, float), fn_80296598(Ptr32<Box>, int);
extern "C" int fn_8015f65c(unsigned short, Ptr32<Cache>);
extern "C" void fn_80069a50(Ptr32<Message>, Ptr32<float>, Ptr32<float>);
extern "C" Vec fn_8029662c(Ptr32<Box>);
struct Box {
    char pad0[44]; float y; float height; char pad52[4]; int a, b; char pad64[4]; int dragging; char pad72[8];
    float low, high, step, pos, pad96, scale; float offset, size, up, down; char pad120[40]; float halfwidth, arrow; char pad168[48]; int owner;
    bool Enabled() { return (b != 0) & (a != 0); }
    void SetDrag(int on) { dragging = on; lbl_804aac54->grabbed = on; fn_80296598(this, 0); }
};
extern "C" int d32f_scroll_bar_message_80294a60(Ptr32<Box> self, Ptr32<Message> m) {
    switch (m->id) {
    case 64:
        if (fn_8015fb34(self, m) >= 0) {
            fn_802950c8(self);
            break;
        }
        return 0x80004005;
    case 66:
        fn_80295204(self);
        return fn_8015fb34(self, m);
    default:
        if (lbl_804abb5c != self->owner || lbl_804abb48 != 0)
            return fn_8015fb34(self, m);
        if (fn_8015f65c(m->id, &lbl_804b0d94)) {
            float x, y;
            fn_80069a50(m, &x, &y);
            float k = lbl_803d0778[0] / self->scale;
            x = (self->y - y) * k;
            self->y = y;
            float v = self->pos + x;
            if (v > self->high) v = self->high;
            if (v < self->low) v = self->low;
            fn_80296410(self, v);
        } else if (fn_8015f65c(m->id, &lbl_804b0d6c) && self->Enabled()) {
            float x, y;
            fn_80069a50(m, &x, &y);
            self->y = y;
            Vec p = fn_8029662c(self);
            if (x > p.x + self->halfwidth || x < p.x - self->halfwidth) break;
            float half = self->height * lbl_803d077c[0];
            float top = p.y + half, bottom;
            if (y > top || y < (bottom = p.y - half)) break;
            float arrow = self->arrow * lbl_803d0780[0];
            arrow += arrow;
            float thumbTop = self->size * lbl_803d077c[0] + (self->offset + p.y);
            float thumbBottom = thumbTop - self->size;
            float upEdge = top - arrow;
            float downEdge = bottom + arrow;
            if (y <= top && y >= upEdge) {
                fn_80296410(self, self->pos - lbl_803d0778[0]);
                self->up = lbl_803d0784[0];
                return 0;
            }
            if (y <= downEdge && y >= bottom) {
                fn_80296410(self, self->pos + lbl_803d0778[0]);
                self->down = lbl_803d0784[0];
                return 0;
            }
            if (y <= thumbTop && y >= thumbBottom && self->scale != lbl_803d0788[0])
                self->SetDrag(1);
            else if (y <= upEdge && y >= thumbTop && self->scale != lbl_803d0788[0])
                fn_80296410(self, self->pos - self->step);
            else if (y <= thumbBottom && y >= downEdge && self->scale != lbl_803d0788[0])
                fn_80296410(self, self->pos + self->step);
        } else if (fn_8015f65c(m->id, &lbl_804b0d74)) {
            float x, y;
            fn_80069a50(m, &x, &y);
            self->SetDrag(0);
        } else if (self->Enabled() && fn_8015f65c(m->id, &lbl_804b0d7c)) {
            float v = self->pos - lbl_803d0778[0];
            if (v < self->low) v = self->low;
            fn_80296410(self, v);
        } else if (self->Enabled() && fn_8015f65c(m->id, &lbl_804b0d84)) {
            float v = self->pos + lbl_803d0778[0];
            if (v > self->high) v = self->high;
            fn_80296410(self, v);
        } else if (self->Enabled() && fn_8015f65c(m->id, &lbl_804b0d64)) {
            fn_80296410(self, self->pos + self->step);
        } else if (self->Enabled() && fn_8015f65c(m->id, &lbl_804b0d5c)) {
            fn_80296410(self, self->pos - self->step);
        } else
            return fn_8015fb34(self, m);
    }
    return 0;
}


