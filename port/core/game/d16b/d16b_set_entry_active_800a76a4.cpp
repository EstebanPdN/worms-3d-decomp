#include "w3d_ptr.h"
#line 1 "d16b_set_entry_active_800a76a4.cpp"
// Input/selection state: sets the active flag of the entry whose name
// matches, or of every entry when the name is empty (recursively). Turning an
// active entry off first resets its items exactly as 0x800a7488 does (inline
// copy): types 0 and 5 clear a latch, type 2 clears a flag, type 1 resets a
// float level to 0.0, announcing items that return to idle. Partial observed
// layouts; cached names are original data referenced by address. The 0.0f
// literal is this function's original literal-pool word at 0x803814cc (owned
// initialized data, 4 bytes). Built with the original paired-single float
// switch (-mps-float), which reserves the 8 frame bytes that pair the saved
// FPR.
struct d16b_MessageKey { unsigned char bytes[8]; };
struct d16b_ResetItem {
    int unknown00;
    d16b_MessageKey key;
    int type;
    int unknown10;
    int idle;
    int latch;
    union { float level; int flag; };
    int mode;
    int armed;
};
struct d16b_ResetList {
    Ptr32<Ptr32<d16b_ResetItem>> first; Ptr32<Ptr32<d16b_ResetItem>> last;
    int capacity;
    Ptr32<Ptr32<d16b_ResetItem>> begin() { return first; }
    Ptr32<Ptr32<d16b_ResetItem>> end() { return last; }
};
struct d16b_ResetEntry {
    char name[36];
    d16b_ResetList items;
    int active;
};
struct d16b_ResetState;
struct d16b_ResetTable { Ptr32<d16b_ResetEntry> data; };
struct d16b_ResetState {
    unsigned char unknown00[172];
    Ptr32<d16b_ResetTable> entries;
};
extern "C" unsigned int w3d_cached_message_id(Ptr32<void>, int);
extern "C" void w3d_auto_800a7ab8(Ptr32<d16b_ResetState>, unsigned short);
extern "C" void s19_send_float_800a7ca0(Ptr32<d16b_ResetState>, unsigned short, float);
extern "C" void k5a_message_text_send_800a7b24(Ptr32<d16b_ResetState>, unsigned short, Ptr32<const char>);
extern d16b_MessageKey w3d_text_key_804ae298;

inline void d16b_reset_items(Ptr32<d16b_ResetState> self, Ptr32<d16b_ResetEntry> entry) {
    for (Ptr32<Ptr32<d16b_ResetItem>> p = entry->items.begin(); p != entry->items.end(); p++) {
        Ptr32<d16b_ResetItem> item = *p;
        switch (item->type) {
        case 0:
            if (item->latch != 0) {
                item->latch = 0;
                if (item->idle == 0) {
                    w3d_auto_800a7ab8(self, w3d_cached_message_id(&item->key, 1));
                    k5a_message_text_send_800a7b24(self, w3d_cached_message_id(&w3d_text_key_804ae298, 1), entry->name + 1);
                }
            }
            break;
        case 1:
            if (item->level != 0.0f) {
                switch (item->mode) {
                case 0:
                    s19_send_float_800a7ca0(self, w3d_cached_message_id(&item->key, 1), 0.0f);
                    k5a_message_text_send_800a7b24(self, w3d_cached_message_id(&w3d_text_key_804ae298, 1), entry->name + 1);
                    break;
                case 1:
                case 2:
                    if (item->armed != 0) {
                        item->level = 0.0f;
                        item->armed = 0;
                        if (item->latch == 0) {
                            w3d_auto_800a7ab8(self, w3d_cached_message_id(&item->key, 1));
                            k5a_message_text_send_800a7b24(self, w3d_cached_message_id(&w3d_text_key_804ae298, 1), entry->name + 1);
                        }
                    }
                    break;
                }
                item->level = 0.0f;
            }
            break;
        case 2:
            if (item->flag != 0) {
                item->flag = 0;
                if (item->latch == 0) {
                    w3d_auto_800a7ab8(self, w3d_cached_message_id(&item->key, 1));
                    k5a_message_text_send_800a7b24(self, w3d_cached_message_id(&w3d_text_key_804ae298, 1), entry->name + 1);
                }
            }
            break;
        case 3:
        case 4:
            break;
        case 5:
            if (item->latch != 0) {
                item->latch = 0;
                if (item->idle == 0) {
                    w3d_auto_800a7ab8(self, w3d_cached_message_id(&item->key, 1));
                    k5a_message_text_send_800a7b24(self, w3d_cached_message_id(&w3d_text_key_804ae298, 1), entry->name + 1);
                }
            }
            break;
        }
    }
}

extern "C" int strcmp(Ptr32<const char>, Ptr32<const char>);

extern "C" void d16b_set_entry_active_800a76a4(Ptr32<d16b_ResetState> self, Ptr32<const char> name, int active) {
    if (name[0] == 0) {
        for (unsigned int i = 0; i < 15; i++)
            d16b_set_entry_active_800a76a4(self, self->entries->data[i].name + 1, active);
        return;
    }
    for (unsigned int i = 0; i < 15; i++) {
        Ptr32<d16b_ResetEntry> entry = &self->entries->data[i];
        if (strcmp(entry->name + 1, name) == 0) {
            if (entry->active != 0 && active == 0)
                d16b_reset_items(self, entry);
            entry->active = active;
            return;
        }
    }
}


