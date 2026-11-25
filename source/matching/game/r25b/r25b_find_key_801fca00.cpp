// Inferred registry cursor. Observed cursor fields: current +0, end +4,
// key +8, category +12. Registry rows are 12 bytes; entry key pointer is +12.
struct R25bEntry {
    unsigned reserved[3];
    const void *key;
};
struct R25bRegistryRow {
    R25bEntry **begin;
    R25bEntry **end;
    unsigned reserved;
};
struct R25bCursor {
    R25bEntry **current;
    R25bEntry **end;
    const void *key;
    int category;
};
extern R25bRegistryRow r25b_registry_8045e890[];
// Observed memcmp call, comparing exactly 16 bytes; ownership external.
extern "C" int r25b_compare_802eedc0(const void *, const void *, unsigned);
extern "C" R25bCursor *w3d_r25b_find_key_801fca00(R25bCursor *cursor, int category, const void *key)
{
    cursor->key = key;
    R25bRegistryRow *row = &r25b_registry_8045e890[category];
    cursor->category = category;
    cursor->current = row->begin;
    cursor->end = row->end;
    while (cursor->current != cursor->end) {
        if (r25b_compare_802eedc0((*cursor->current)->key, cursor->key, 16) == 0)
            break;
        ++cursor->current;
    }
    return cursor;
}
