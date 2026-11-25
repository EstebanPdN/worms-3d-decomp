// GWMP8P rev0 0x800a6c80. Input state, same object as 0x800a7148: handles a
// raw input event. Names are inferred. Mouse moves update position and
// scale; button events send press messages to bound items; wheel events send
// direction and amount messages. The local values in the mouse case and the
// button local are chosen because they give the original store order and
// registers.
inline void *operator new(unsigned int, void *place) throw() { return place; }
struct MessageKey { unsigned char bytes[8]; };
struct Item {
    int unknown00;
    MessageKey key;
    int kind;      // +12
    int button;    // +16
    int idle;      // +20
    int pressed;   // +24
};
struct List {
    Item **first, **last;
    int capacity;
    Item **begin() { return first; }
    Item **end() { return last; }
};
struct Entry {
    char name[36];
    List items;
    int active;
};
struct Table { Entry *start; };
struct Self {
    char u0[96];
    unsigned bits0 : 7;
    unsigned wheelFlip : 1;
    unsigned moved : 1;
    unsigned bit9 : 1;
    unsigned always : 1;
    unsigned bits11 : 21;
    int mouseX, mouseY;  // +100, +104
    char u108[16];
    float scaleX, scaleY;  // +124, +128
    char u132[32];
    unsigned first, last;  // +164, +168
    Table *table;  // +172
};
struct Event { char u0[8]; int kind; int button; short dx, dy; char u20[4]; float x, y, wheel; };
extern "C" unsigned int w3d_cached_message_id(void *, int);
extern "C" void w3d_auto_800a7ab8(Self *, unsigned short);
extern "C" void w3d_auto_800a7bb4(Self *, unsigned short, int);
extern "C" void s19_send_range_800a7d18(Self *, unsigned short, float, float);
extern "C" void k5a_message_text_send_800a7b24(Self *, unsigned short, const char *);
extern "C" void flush_pending_800a7fdc(Self *);
struct Runtime;
extern "C" int w3d_runtime_is_paused(Runtime *);
extern Runtime *g_runtime_804b1788;
extern MessageKey key_804ae298, key_804ae290, key_804ae2c0, key_804ae2c8, key_804ae2a8, key_804ae2b0;
extern "C" void d27h_input_event_800a6c80(Self *self, Event *ev) {
    int pressed = 0;
    switch (ev->kind) {
    case 0:
        {
            float *py = &self->scaleY;
            new (&self->scaleX) float(ev->x);
            new (py) float(ev->y);
        }
{ int x = self->mouseX + ev->dx; int y = self->mouseY + ev->dy; float a = self->scaleX * 320.0f; float b = self->scaleY * 240.0f; self->mouseX = x; self->mouseY = y; self->scaleX = a; self->scaleY = b; self->moved = 1; }
        if (w3d_runtime_is_paused(g_runtime_804b1788)) flush_pending_800a7fdc(self);
        break;
    case 2:
        w3d_auto_800a7ab8(self, w3d_cached_message_id(&key_804ae290, 1));
        pressed = 1;
    case 3:
        {
            unsigned last = self->last;
            int all = self->always;
            for (unsigned i = self->first; i <= last; i++) {
                Entry *e = &self->table->start[i];
                if (!all && e->active == 0) continue;
                for (Item **p = e->items.begin(); p != e->items.end(); p++) {
                    Item *it = *p;
                    if (it->kind != 5) continue;
                    int button = ev->button;
                    if (it->button != button) continue;
                    it->pressed = pressed;
                    if (it->idle != pressed) continue;
                    s19_send_range_800a7d18(self, w3d_cached_message_id(&it->key, 1), self->scaleX, self->scaleY);
                    k5a_message_text_send_800a7b24(self, w3d_cached_message_id(&key_804ae298, 1), e->name + 1);
                }
            }
        }
        break;
    case 4:
        w3d_auto_800a7ab8(self, w3d_cached_message_id(&key_804ae290, 1));
        if (self->wheelFlip) {
            if (ev->wheel > 0.0f) w3d_auto_800a7ab8(self, w3d_cached_message_id(&key_804ae2c0, 1));
            else w3d_auto_800a7ab8(self, w3d_cached_message_id(&key_804ae2c8, 1));
        } else {
            if (ev->wheel > 0.0f) w3d_auto_800a7ab8(self, w3d_cached_message_id(&key_804ae2a8, 1));
            else w3d_auto_800a7ab8(self, w3d_cached_message_id(&key_804ae2b0, 1));
        }
        {
            unsigned last = self->last;
            int all = self->always;
            for (unsigned i = self->first; i <= last; i++) {
                Entry *e = &self->table->start[i];
                if (!all && e->active == 0) continue;
                for (Item **p = e->items.begin(); p != e->items.end(); p++) {
                    Item *it = *p;
                    if (it->kind != 4) continue;
                    w3d_auto_800a7bb4(self, w3d_cached_message_id(&it->key, 1), (int)ev->wheel);
                    k5a_message_text_send_800a7b24(self, w3d_cached_message_id(&key_804ae298, 1), e->name + 1);
                }
            }
        }
        break;
    }
}
