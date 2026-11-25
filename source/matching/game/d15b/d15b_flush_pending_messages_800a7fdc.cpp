// Input/selection state (same object as the 0x800a5fdc initializer): when a
// pending flag is set, sends the current range under one of two cached
// message names, then for every entry in the active window (all entries, or
// only active ones) sends each type-3 item's message with the two stored
// values followed by the entry's name text; finally clears the stored values
// and the pending flag. Partial observed layouts; cached names are original
// data referenced by address; no owned initialized data.
struct d15b_MessageKey { unsigned char bytes[8]; };
struct d15b_Item {
    int unknown00;
    d15b_MessageKey key;
    int type;
};
struct d15b_ItemList {
    d15b_Item **first, **last;
    int capacity;
    d15b_Item **begin() { return first; }
    d15b_Item **end() { return last; }
};
struct d15b_Entry {
    char name[36];
    d15b_ItemList items;
    int active;
};
struct d15b_EntryTable { d15b_Entry *data; };
struct d15b_MessageState {
    unsigned char unknown00[96];
    unsigned int unknown60_high : 7;
    unsigned int alternate : 1;
    unsigned int pending : 1;
    unsigned int unknown60_mid : 1;
    unsigned int all_entries : 1;
    unsigned int unknown60_low : 21;
    int first_value;
    int second_value;
    unsigned char unknown6c[16];
    float low, high;
    unsigned char unknown84[32];
    unsigned int window_start, window_end;
    d15b_EntryTable *entries;
};
extern "C" unsigned int w3d_cached_message_id(void *, int);
extern "C" void s19_send_range_800a7d18(d15b_MessageState *, unsigned short, float, float);
extern "C" void w3d_auto_800a7c24(d15b_MessageState *, unsigned short, int, int);
extern "C" void k5a_message_text_send_800a7b24(d15b_MessageState *, unsigned short, const char *);
extern d15b_MessageKey w3d_range_key_804ae2b8, w3d_range_key_804ae2a0, w3d_text_key_804ae298;

extern "C" void d15b_flush_pending_messages_800a7fdc(d15b_MessageState *self) {
    if (!self->pending)
        return;
    if (self->alternate)
        s19_send_range_800a7d18(self, w3d_cached_message_id(&w3d_range_key_804ae2b8, 1), self->low, self->high);
    else
        s19_send_range_800a7d18(self, w3d_cached_message_id(&w3d_range_key_804ae2a0, 1), self->low, self->high);
    unsigned int end = self->window_end;
    bool all = self->all_entries;
    for (unsigned int i = self->window_start; i <= end; i++) {
        d15b_Entry *entry = &self->entries->data[i];
        if (!all && !entry->active)
            continue;
        for (d15b_Item **p = entry->items.begin(); p != entry->items.end(); p++) {
            d15b_Item *item = *p;
            if (item->type == 3) {
                w3d_auto_800a7c24(self, w3d_cached_message_id(&item->key, 1), self->first_value, self->second_value);
                k5a_message_text_send_800a7b24(self, w3d_cached_message_id(&w3d_text_key_804ae298, 1), entry->name + 1);
            }
        }
    }
    self->first_value = 0;
    self->second_value = 0;
    self->pending = 0;
}
