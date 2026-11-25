// d24i: 0x80127ba0 (516 bytes). Set the language to entry `index` (above 9 keeps
// the current one, no change when equal). Saves the four NGC.Disc.* message
// settings into local strings (a 4-byte stride array: the string is one word), calls virtual +188 of
// the object at +100 of the service 0x804b1788 with 1, writes the settings back,
// refreshes 0x804b06a4 (0x80209968), stores the index at +176 and loads the entry
// name from 0x803fcd30 (0x800fd504, mode 1 then mode 2 on failure).
struct d24i_String {
    char *text;
    d24i_String();
    ~d24i_String();
};
extern "C" void d24i_string_finish_8020c5c4(d24i_String *);
extern "C" void d24i_string_release_80341588(d24i_String *);
inline d24i_String::~d24i_String() {
    d24i_string_finish_8020c5c4(this);
    d24i_string_release_80341588(this);
}
struct d24i_Key {
    const char *name;
    d24i_Key(const char *n) { name = n; }
};
struct d24i_Renderer;
struct d24i_RendererVtable {
    void *unknown00[47];
    void (*refresh)(d24i_Renderer *, int);   // +188
};
struct d24i_Renderer { d24i_RendererVtable *vtable; };
struct d24i_Service {
    unsigned char unknown00[100];
    d24i_Renderer *renderer;             // +100
};
struct d24i_Options {
    unsigned char unknown00[176];
    int selected;                        // +176
};
extern "C" int d24i_setting_read_800fc2b0(d24i_Key *, const char **);
extern "C" int d24i_setting_write_800fc550(d24i_Key *, const char *);
extern "C" d24i_String *d24i_string_assign_8020bd38(d24i_String *, const char *);
extern "C" void d24i_debug_802fb7ac(const char *, ...);
extern "C" void d24i_refresh_80209968(void *);
extern "C" int d24i_load_entry_800fd504(const char *, int, int);
extern d24i_Service *d24i_service_804b1788;
extern unsigned int d24i_state_804b06a4;
extern const char *d24i_entries_803fcd30[];
extern const char d24i_message_8039bd6c[], d24i_name_8039bd80[], d24i_name_8039bd94[], d24i_name_8039bda4[], d24i_name_8039bdb8[];

extern "C" void d24i_set_language_80127ba0(d24i_Options *self, unsigned index) {
    if (index > 9)
        index = self->selected;
    if (self->selected != (int)index) {
        d24i_debug_802fb7ac(d24i_message_8039bd6c);
        d24i_String saved[4];
        const char *stored;
        const char *first = d24i_name_8039bd80;
        d24i_Key key1(first);
        d24i_setting_read_800fc2b0(&key1, &stored);
        d24i_string_assign_8020bd38(&saved[0], stored);
        const char *second = d24i_name_8039bd94;
        d24i_Key key2(second);
        d24i_setting_read_800fc2b0(&key2, &stored);
        d24i_string_assign_8020bd38(&saved[1], stored);
        const char *third = d24i_name_8039bda4;
        d24i_Key key3(third);
        d24i_setting_read_800fc2b0(&key3, &stored);
        d24i_string_assign_8020bd38(&saved[2], stored);
        const char *fourth = d24i_name_8039bdb8;
        d24i_Key key4(fourth);
        d24i_setting_read_800fc2b0(&key4, &stored);
        d24i_string_assign_8020bd38(&saved[3], stored);
        d24i_service_804b1788->renderer->vtable->refresh(d24i_service_804b1788->renderer, 1);
        d24i_Key key5(first);
        d24i_setting_write_800fc550(&key5, saved[0].text);
        d24i_Key key6(second);
        d24i_setting_write_800fc550(&key6, saved[1].text);
        d24i_Key key7(third);
        d24i_setting_write_800fc550(&key7, saved[2].text);
        d24i_Key key8(fourth);
        d24i_setting_write_800fc550(&key8, saved[3].text);
        d24i_refresh_80209968(&d24i_state_804b06a4);
        self->selected = index;
        if (d24i_load_entry_800fd504(d24i_entries_803fcd30[index], 1, 1) < 0)
            d24i_load_entry_800fd504(d24i_entries_803fcd30[index], 1, 2);
    }
}
