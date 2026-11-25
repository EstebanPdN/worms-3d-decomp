// d24d: 0x8017e6d0 (208 bytes). Attach a named value to a keyed record: the
// owner's virtual slot 29 (+116) finds the record for the key byte, passed by
// address. The value's shared name (+36) is replaced by a temporary string
// built from the text (the header counter sits 6 bytes before the text), the
// value is appended to the record's list (+20) through 0x801ef174 (field 44,
// kind 3), the record state is marked dirty and the value is returned. The
// fourth argument is not read. Names and layouts are partial views.
struct d24d_String_8020bb54 {
 d24d_String_8020bb54(const d24d_String_8020bb54 &);
    char *text;
    d24d_String_8020bb54(const char *);
    ~d24d_String_8020bb54();
    d24d_String_8020bb54 &operator=(const d24d_String_8020bb54 &other);
};
extern "C" void d24d_string_finish_8020c5c4(d24d_String_8020bb54 *);
extern "C" void d24d_string_release_80341588(d24d_String_8020bb54 *);
extern "C" void d24d_string_release_header_8020bb2c(void *);
inline d24d_String_8020bb54::~d24d_String_8020bb54() {
    d24d_string_finish_8020c5c4(this);
    d24d_string_release_80341588(this);
}
inline d24d_String_8020bb54 &d24d_String_8020bb54::operator=(const d24d_String_8020bb54 &other) {
    ++*(unsigned short *)(other.text - 6);
    unsigned short *header = (unsigned short *)(text - 6);
    if (--*header == 0) d24d_string_release_header_8020bb2c(header);
    text = other.text;
    return *this;
}
struct d24d_Value {
    unsigned char unknown00[36];
    d24d_String_8020bb54 name;           // +36
};
struct d24d_State {
    unsigned char unknown0[7];
    unsigned char flags;                 // +7
    void touch() { flags |= 2; }
};
struct d24d_Record {
    void *unknown00;
    d24d_State state;                    // +4
    unsigned char unknown0c[8];
    void *list;                          // +20
};
struct d24d_Owner { void **vtable; };
extern "C" void d24d_list_append_801ef174(void *, int, int, d24d_Value *);

extern "C" d24d_Value *d24d_attach_named_8017e6d0(d24d_Owner *owner, const char *name, unsigned char key, int unused, d24d_Value *value) {
    d24d_Record *record = ((d24d_Record *(*)(d24d_Owner *, unsigned char *))owner->vtable[29])(owner, &key);
    void *list = record->list;
    value->name = d24d_String_8020bb54(name);
    d24d_list_append_801ef174(list, 44, 3, value);
    record->state.touch();
    return value;
}
