// Observed GC32 fields; collection and iterator identities remain inferred.
struct Entry { unsigned char value, unknown; unsigned short index; };
struct Data { char pad[24]; int count; int unknown; Entry entries[1]; };
struct Input { char pad[76]; Data *data; };
struct Owner { char pad[696]; unsigned char *map; int active; };
extern "C" void *fn_802eefe0(void *, int, unsigned);
struct Iterator {
    Entry *cursor;
    unsigned left;
    Iterator(Entry *p, unsigned n): cursor(p), left(n) {}
    unsigned sum() { unsigned total = 0; for (unsigned i=0; i<left; ++i, ++cursor) total += cursor->value; return total; }
};
extern "C" void tterra_a32_map_8007bb54(Owner *owner, Input *input) {
    Data *data = input->data;
    int count = data->count;
    Entry *entries = data->entries;
    if (!count) { fn_802eefe0(owner->map, 150, 2916); owner->active = count; }
    else {
        unsigned n = count - 1;
        Iterator it(entries, n);
        unsigned sum = it.sum();
        owner->active = 1;
        fn_802eefe0(owner->map, (unsigned char)(sum / n), 2916);
        for (unsigned i=0; i<n; ++i, ++entries) owner->map[entries->index] = entries->value;
    }
}
