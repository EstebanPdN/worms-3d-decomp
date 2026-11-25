// d24i: 0x80103c44 (612 bytes). Format the current value of a setting into its
// item. The value named by item +56 is looked up (0x800fc1b0) as a retained
// handle; if absent, a copy of the name is made and dropped. Otherwise the
// value's kind (virtual +24) selects a format: 2 float, 0 and 1 integer readers,
// 4 text. The result renames item +56 (0x801790bc) and 0x80103a5c re-syncs the
// setting. An unknown kind drops a copy of the name, calls the value's virtual
// +28 and writes the error text 0x803994ec to the setting named by item +48.
struct d24i_String {
    char *text;
    d24i_String();
    d24i_String(const char *);
    d24i_String(const d24i_String &);
    ~d24i_String();
};
extern "C" void d24i_string_init_8020c5c0(d24i_String *);
extern "C" unsigned short *d24i_string_header_80341884(d24i_String *);
extern "C" void d24i_string_finish_8020c5c4(d24i_String *);
extern "C" void d24i_string_release_80341588(d24i_String *);
inline d24i_String::d24i_String(const d24i_String &other) {
    d24i_string_init_8020c5c0(this);
    text = other.text;
    ++*d24i_string_header_80341884(this);
}
inline d24i_String::~d24i_String() {
    d24i_string_finish_8020c5c4(this);
    d24i_string_release_80341588(this);
}
struct d24i_Key { const char *name; };
struct d24i_Item;
struct d24i_Value;
struct d24i_ValueVtable {
    void *unknown00[4];
    void (*release)(d24i_Value *);       // +16
    void *unknown14;
    int (*kind)(d24i_Value *);           // +24
    void (*report)(d24i_Value *);        // +28
};
struct d24i_Value { d24i_ValueVtable *vtable; };
struct d24i_Handle {
    d24i_Value *value;
    d24i_Handle() { value = 0; }
    ~d24i_Handle() { if (value) value->vtable->release(value); }
};
extern "C" d24i_String *d24i_item_text_80179170(d24i_Item *);
extern "C" int d24i_setting_lookup_800fc1b0(d24i_Key *, d24i_Handle *);
extern "C" int d24i_setting_write_800fc550(d24i_Key *, const char *);
extern "C" int d24i_item_rename_801790bc(d24i_Item *, const char *);
extern "C" void d24i_string_format_8020c510(d24i_String *, const char *, ...);
extern "C" d24i_Item *d24i_as_float_80342a74(d24i_Value *);
extern "C" d24i_Item *d24i_as_int_803426b4(d24i_Value *);
extern "C" d24i_Item *d24i_as_text_80343744(d24i_Value *);
extern "C" d24i_Item *d24i_as_bool_80342a78(d24i_Value *);
extern "C" float d24i_read_float_80178df0(d24i_Item *);
extern "C" int d24i_read_int_80178c48(d24i_Item *);
extern "C" int d24i_read_bool_80178d1c(d24i_Item *);
extern const char d24i_format_float_80399480[], d24i_format_int_80399484[], d24i_format_text_80399488[], d24i_format_bool_8039948c[], d24i_error_803994ec[];
struct d24i_Binding {
    unsigned char unknown00[48];
    d24i_Item *target;                   // +48
    unsigned char unknown34[4];
    d24i_Item *name;                     // +56
};
extern "C" void d24i_setting_substitute_80103a5c(d24i_Binding *);

extern "C" void d24i_setting_format_80103c44(d24i_Binding *self) {
    d24i_Handle handle;
    d24i_Key key;
    key.name = d24i_item_text_80179170(self->name)->text;
    if (d24i_setting_lookup_800fc1b0(&key, &handle) < 0) {
        d24i_String copy(*d24i_item_text_80179170(self->name));
        return;
    }
    d24i_String text;
    switch (handle.value->vtable->kind(handle.value)) {
    case 2:
        d24i_string_format_8020c510(&text, d24i_format_float_80399480, d24i_read_float_80178df0(d24i_as_float_80342a74(handle.value)));
        break;
    case 0:
        d24i_string_format_8020c510(&text, d24i_format_int_80399484, d24i_read_int_80178c48(d24i_as_int_803426b4(handle.value)));
        break;
    case 4:
        d24i_string_format_8020c510(&text, d24i_format_text_80399488, d24i_item_text_80179170(d24i_as_text_80343744(handle.value))->text);
        break;
    case 1:
        d24i_string_format_8020c510(&text, d24i_format_bool_8039948c, d24i_read_bool_80178d1c(d24i_as_bool_80342a78(handle.value)));
        break;
    default: {
        { d24i_String copy(*d24i_item_text_80179170(self->name)); }
        handle.value->vtable->report(handle.value);
        d24i_Key target;
        target.name = d24i_item_text_80179170(self->target)->text;
        d24i_setting_write_800fc550(&target, d24i_error_803994ec);
        return;
    }
    }
    d24i_item_rename_801790bc(self->name, text.text);
    d24i_setting_substitute_80103a5c(self);
}
