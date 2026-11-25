#include "w3d_ptr.h"
#line 1 "d33f_card_slot_display_80288c7c.cpp"
// GWMP8P rev0 0x80288c7c. Memory card slot display: looks up the record for
// a slot, fetches the action, slot and block texts, then colours the box
// list when the slot changed or pulses it otherwise.
struct Obj { Ptr32<Ptr32<void>> table; };
struct Key { Ptr32<const char> text; template <class W3dU> Key(Ptr32<W3dU> w3d_p) : Key((const char *)w3d_p.get()) {}
 Key(const char *p) : text(p) {} };
struct Colour {
    signed char r, g, b, a;
    void Set(int r0, int g0, int b0, int a0) { Ptr32<Colour> p = this; r = r0; p->g = g0; p->b = b0; p->a = a0; }
};
struct Record { char pad[8]; int present; int index; };
struct Screen { Ptr32<Ptr32<void>> table; char pad[72]; unsigned flags; };
struct CardPage {
    Ptr32<Ptr32<void>> table;
    char pad0[688 - 4];
    int current;
    int slot;
    int bytes;
    char pad1[704 - 700];
    int state;
    unsigned char shade;
    char pad2[904 - 709];
    Ptr32<void> boxes[5];
    Ptr32<void> extra;
    int extraIndex;
    char pad3[960 - 932];
    unsigned count;
    char pad4[968 - 964];
    int cardReady;
    Ptr32<const char> action;
    Ptr32<const char> slotText;
    Ptr32<const char> blockText;
    char pad5[1012 - 984];
    float timer;
    unsigned cardFlags;
};
extern char lbl_803cf960[], lbl_803cf970[], lbl_803cf980[], lbl_803cf98c[], lbl_803cf990[], lbl_803cf994[], lbl_803cf9a8[];
extern float lbl_803cf9c0[];
extern Ptr32<Screen> lbl_804b1788;
extern "C" Ptr32<Record> w3d_table_find_record_8028924c(Ptr32<CardPage>, int);
extern "C" int w3d_auto_800fc2b0(const Key &, Ptr32<Ptr32<const char>>);
extern "C" void w3d_s4_card_set_name(Ptr32<CardPage>, Ptr32<const char>, Ptr32<const char>);
extern "C" Ptr32<void> w3d_format_into_8035eb0c(Ptr32<char>, Ptr32<const char>, ...);
extern "C" void fn_80289290(Ptr32<CardPage>, Ptr32<Record>);
extern "C" void fn_802fb7ac(Ptr32<const char>, ...);
extern "C" int w3d_cc29b_fill_text_8018d35c(Ptr32<void>, Ptr32<const Colour>);
extern "C" int s9_fill_values_8018d434(Ptr32<void>, Ptr32<const Colour>);
extern "C" void d33f_card_slot_display_80288c7c(Ptr32<CardPage> self, int slot, int unused, int mode) {
    int changed = 0;
    if (self->slot != slot) {
        self->slot = slot;
        changed = 1;
    }
    Ptr32<Record> record = w3d_table_find_record_8028924c(self, slot);
    if (mode == 2)
        w3d_auto_800fc2b0(lbl_803cf960, &self->action);
    else
        w3d_auto_800fc2b0(lbl_803cf970, &self->action);
    char buffer[32];
    Ptr32<char> text = buffer;
    w3d_s4_card_set_name(self, lbl_803cf980, lbl_803cf98c);
    w3d_auto_800fc2b0(lbl_803cf980, &self->slotText);
    buffer[0] = 0;
    w3d_format_into_8035eb0c(text, lbl_803cf990, self->bytes / 8192);
    w3d_s4_card_set_name(self, lbl_803cf994, text);
    w3d_auto_800fc2b0(lbl_803cf994, &self->blockText);
    if (record != 0) {
        Ptr32<Colour> bright; Ptr32<Colour> dim;
        if (changed) {
            Colour white, black;
            bright = &white;
            dim = &black;
            self->current = record->index;
            fn_80289290(self, record);
            if (slot == -2) {
                fn_802fb7ac(lbl_803cf9a8);
                ((Ptr32<void (Ptr32<Screen>, int)>)lbl_804b1788->table[16])(lbl_804b1788, 0);
                lbl_804b1788->flags &= ~0x10000000;
                int n = 13;
                do {
                    ((Ptr32<int (Ptr32<CardPage>, int)>)self->table[8])(self, 0);
                    ((Ptr32<void (Ptr32<Screen>, int)>)lbl_804b1788->table[16])(lbl_804b1788, 0);
                } while (--n);
                lbl_804b1788->flags |= 0x10000000;
            }
            white.r = -1; bright->g = -1; bright->b = -1; bright->a = 0;
            black.r = 0; dim->g = 0; dim->b = 0; dim->a = 0;
            if (record->present == 0)
                return;
            for (unsigned i = 0; i < self->count; i++) {
                w3d_cc29b_fill_text_8018d35c(self->boxes[i], bright);
                s9_fill_values_8018d434(self->boxes[i], dim);
            }
            do { if (self->extra) {
                w3d_cc29b_fill_text_8018d35c(self->extra, bright);
                s9_fill_values_8018d434(self->extra, dim);
            } } while (0);
        } else {
            unsigned char shade = self->shade;
            Colour white;
            white.Set(-1, -1, -1, -1);
            Colour tint;
            tint.Set((shade >> 1) | 128, shade, shade, -1);
            dim = &tint;
            if (record->present == 0)
                return;
            for (unsigned i = 0; i < self->count; i++)
                w3d_cc29b_fill_text_8018d35c(self->boxes[i], &white);
            if (self->extra)
                w3d_cc29b_fill_text_8018d35c(self->extra, &white);
        }
        w3d_cc29b_fill_text_8018d35c(*(self->current + self->boxes), dim);
        if (self->extraIndex == self->current)
            w3d_cc29b_fill_text_8018d35c(self->extra, dim);
    } else {
        if (self->cardReady != 0 && !(self->cardFlags & 0x04000000)) {
            self->timer = lbl_803cf9c0[0];
            self->state = 3;
        }
        self->current = 0;
    }
}


