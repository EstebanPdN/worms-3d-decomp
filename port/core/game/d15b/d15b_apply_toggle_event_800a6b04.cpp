#include "w3d_ptr.h"
#line 1 "d15b_apply_toggle_event_800a6b04.cpp"
// Input/selection state (same object as the 0x800a5fdc initializer): applies
// an incoming toggle event. A nonzero value sends the selection message and
// starts a 500-tick timed hold for the event id; zero clears the hold. Then
// every type-0 item in the active window whose id matches stores the value
// and, when its expected value equals it, sends its message and entry name.
// Partial observed layouts; cached names are original data referenced by
// address; no owned initialized data.
struct d15b_MessageKey { unsigned char bytes[8]; };
struct d15b_Item {
    int unknown00;
    d15b_MessageKey key;
    int type;
    int id;
    int expected;
    int value;
};
struct d15b_ToggleEvent {
    unsigned char unknown00[8];
    int id;
    int value;
    int Id() const { return id; }
};
struct d15b_EngineContext { unsigned char unknown00[52]; int tick; };
struct d15b_ItemList {
    Ptr32<Ptr32<d15b_Item>> first; Ptr32<Ptr32<d15b_Item>> last;
    int capacity;
    Ptr32<Ptr32<d15b_Item>> begin() { return first; }
    Ptr32<Ptr32<d15b_Item>> end() { return last; }
};
struct d15b_Entry {
    char name[36];
    d15b_ItemList items;
    int active;
};
struct d15b_EntryTable { Ptr32<d15b_Entry> data; };
struct d15b_MessageState {
    unsigned char unknown00[56];
    int hold_id;
    int hold_start;
    int hold_end;
    unsigned char unknown44[28];
    unsigned int unknown60_low:21; unsigned int all_entries:1; unsigned int unknown60_mid:1; unsigned int pending:1; unsigned int alternate:1; unsigned int unknown60_high:7;
    int first_value;
    int second_value;
    unsigned char unknown6c[16];
    float low, high;
    unsigned char unknown84[32];
    unsigned int window_start, window_end;
    Ptr32<d15b_EntryTable> entries;
    void start_hold(int id);
};
extern "C" Ptr32<d15b_EngineContext> w3d_engine_get_context(void);
extern "C" void w3d_empty_800a8148(Ptr32<d15b_MessageState>, int);
inline void d15b_MessageState::start_hold(int id) {
    hold_start = w3d_engine_get_context()->tick;
    hold_end = w3d_engine_get_context()->tick + 500;
    w3d_empty_800a8148(this, id);
}
extern "C" unsigned int w3d_cached_message_id(Ptr32<void>, int);
extern "C" void w3d_auto_800a7ab8(Ptr32<d15b_MessageState>, unsigned short);
extern "C" void k5a_message_text_send_800a7b24(Ptr32<d15b_MessageState>, unsigned short, Ptr32<const char>);
extern d15b_MessageKey w3d_select_key_804ae290, w3d_text_key_804ae298;

extern "C" void d15b_apply_toggle_event_800a6b04(Ptr32<d15b_MessageState> self, Ptr32<d15b_ToggleEvent> event) {
    if (event->value != 0) {
        w3d_auto_800a7ab8(self, w3d_cached_message_id(&w3d_select_key_804ae290, 1));
        self->start_hold(event->id);
    } else {
        self->hold_id = 0;
        self->hold_start = 0;
    }
    unsigned int end = self->window_end;
    bool all = self->all_entries;
    for (unsigned int i = self->window_start; i <= end; i++) {
        Ptr32<d15b_Entry> entry = &self->entries->data[i];
        if (!all && !entry->active)
            continue;
        for (Ptr32<Ptr32<d15b_Item>> p = entry->items.begin(); p != entry->items.end(); p++) {
            Ptr32<d15b_Item> item = *p;
            if (item->type == 0 && item->id == event->Id()) {
                item->value = event->value;
                if (item->expected == event->value) {
                    w3d_auto_800a7ab8(self, w3d_cached_message_id(&item->key, 1));
                    k5a_message_text_send_800a7b24(self, w3d_cached_message_id(&w3d_text_key_804ae298, 1), entry->name + 1);
                }
            }
        }
    }
}


