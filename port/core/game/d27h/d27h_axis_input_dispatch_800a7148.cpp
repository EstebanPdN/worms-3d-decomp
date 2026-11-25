#include "w3d_ptr.h"
#line 1 "d27h_axis_input_dispatch_800a7148.cpp"
// GWMP8P rev0 0x800a7148. Input state, same object as 0x800a7488: dispatches
// an analog axis event to every bound item of the active entries. Names are
// inferred. The axis value is stepped to thirds and kept with a scale of 1
// in a two-float local; modes 0, 1 and 2 send the level, or a press when
// past the negative or positive dead zone.
struct MessageKey { unsigned char bytes[8]; };
struct Item {
    int unknown00;
    MessageKey key;
    int kind;      // +12
    int device;    // +16
    int button;    // +20
    int inverted;  // +24
    float level;   // +28
    int mode;      // +32
    int state;     // +36
};
struct List {
    Ptr32<Ptr32<Item>> first; Ptr32<Ptr32<Item>> last;
    int capacity;
    Ptr32<Ptr32<Item>> begin() { return first; }
    Ptr32<Ptr32<Item>> end() { return last; }
};
struct Entry {
    char name[36];
    List items;
    int active;
};
struct Table { Ptr32<Entry> start; };
struct Self {
    char u0[88];
    float deadzone;  // +88
    char u92[4];
    unsigned int bits21:21; unsigned int always:1; unsigned int bits10:10;
    char u100[64];
    unsigned first, last;  // +164, +168
    Ptr32<Table> table;  // +172
};
struct Event { char u0[8]; int button; unsigned char device; char u13[3]; float value; };
extern "C" unsigned int w3d_cached_message_id(Ptr32<void>, int);
extern "C" void w3d_auto_800a7ab8(Ptr32<Self>, unsigned short);
extern "C" void s19_send_float_800a7ca0(Ptr32<Self>, unsigned short, float);
extern "C" void k5a_message_text_send_800a7b24(Ptr32<Self>, unsigned short, Ptr32<const char>);
extern MessageKey key_804ae298, key_804ae290;
struct Axis { float value; float scale; Axis() {} Axis(float x, float y) { value = x; scale = y; } };
extern "C" void d27h_axis_input_dispatch_800a7148(Ptr32<Self> self, Ptr32<Event> ev) {
    float v = ev->value;
    if (__builtin_fabsf(v) <= self->deadzone) v = 0.0f;
    int neg = v < -self->deadzone;
    int pos = v > self->deadzone;
    Axis a((int)(v * 3.1f) / 3.0f, 1.0f);
    unsigned last = self->last;
    int all = self->always;
    for (unsigned i = self->first; i <= last; i++) {
        Ptr32<Entry> e = &self->table->start[i];
        if (!all && e->active == 0) continue;
        for (Ptr32<Ptr32<Item>> p = e->items.begin(); p != e->items.end(); p++) {
            Ptr32<Item> it = *p;
            if (it->kind != 1) continue;
            int button = ev->button;
            if (it->button != button || it->device != ev->device) continue;
            switch (it->mode) {
            case 0:
                if (it->level != a.value) {
                    if (it->inverted) {
                        s19_send_float_800a7ca0(self, w3d_cached_message_id(&it->key, 1), -a.value);
                        k5a_message_text_send_800a7b24(self, w3d_cached_message_id(&key_804ae298, 1), e->name + 1);
                    } else {
                        s19_send_float_800a7ca0(self, w3d_cached_message_id(&it->key, 1), a.value);
                        k5a_message_text_send_800a7b24(self, w3d_cached_message_id(&key_804ae298, 1), e->name + 1);
                    }
                    w3d_auto_800a7ab8(self, w3d_cached_message_id(&key_804ae290, 1));
                }
                it->level = a.value;
                break;
            case 1:
                if (it->inverted == neg && it->state != neg) {
                    w3d_auto_800a7ab8(self, w3d_cached_message_id(&it->key, 1));
                    k5a_message_text_send_800a7b24(self, w3d_cached_message_id(&key_804ae298, 1), e->name + 1);
                    if (neg) w3d_auto_800a7ab8(self, w3d_cached_message_id(&key_804ae290, 1));
                }
                it->state = neg;
                it->level = v;
                break;
            case 2:
                if (it->inverted == pos && it->state != pos) {
                    w3d_auto_800a7ab8(self, w3d_cached_message_id(&it->key, 1));
                    k5a_message_text_send_800a7b24(self, w3d_cached_message_id(&key_804ae298, 1), e->name + 1);
                    if (pos) w3d_auto_800a7ab8(self, w3d_cached_message_id(&key_804ae290, 1));
                }
                it->state = pos;
                it->level = v;
                break;
            }
        }
    }
}


