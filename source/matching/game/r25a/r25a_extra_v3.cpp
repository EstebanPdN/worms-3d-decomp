// PPC32 interface ABI, retain/release slots observed at +12/+16.
struct Interface;
struct Table { void *unknown[3]; void (*retain)(Interface *); void (*release)(Interface *); };
struct Interface { Table *table; };
struct ModeObject { unsigned char unknown[160]; int mode; unsigned char gap[12]; Interface *held; };
extern "C" {
Interface *fn_8020fcb4(const void *);
extern unsigned char lbl_80363b54[], lbl_80363ba4[];
}
extern "C" int w3d_r25a_select_mode_interface_801a92c8(ModeObject *self, int mode) {
    if (mode != self->mode) {
        Interface *next;
        if (mode == 0) next = fn_8020fcb4(lbl_80363b54);
        else next = fn_8020fcb4(lbl_80363ba4);
        if (next) next->table->retain(next);
        if (self->held) self->held->table->release(self->held);
        self->held = next;
    }
    self->mode = mode;
    return 0;
}
// Header is observed 16 bytes before the stored cursor; words are PPC32.
struct ListHeader { int count; int unknown; int *entries; void *owner; };
struct ListMember { int unknown; ListHeader *cursor; };
struct ListObject { unsigned char unknown[116]; ListMember list; };
extern "C" void fn_801ef174(void *, int, int, int);
extern "C" void fn_801f2758(ListHeader *, int);
extern "C" void w3d_r25a_release_list_entries_801ad060(ListObject *self) {
    ListHeader *header = self->list.cursor - 1;
    int *entry = header->entries;
    void *owner = header->owner;
    int *end = entry + header->count;
    while (entry != end) {
        fn_801ef174(owner, 44, 3, *entry);
        ++entry;
    }
    ListMember *list = &self->list;
    --list->cursor;
    fn_801f2758(list->cursor, 2);
}
