#include "w3d_ptr.h"
#line 1 "d24d_attach_named_8017e6d0.cpp"
// d24d: 0x8017e6d0 (208 bytes). Attach a named value to a keyed record: the
// owner's virtual slot 29 (+116) finds the record for the key byte, passed by
// address. The value's shared name (+36) is replaced by a temporary string
// built from the text (the header counter sits 6 bytes before the text), the
// value is appended to the record's list (+20) through 0x801ef174 (field 44,
// kind 3), the record state is marked dirty and the value is returned. The
// fourth argument is not read. Names and layouts are partial views.
struct d24d_String_8020bb54 {
 d24d_String_8020bb54(const d24d_String_8020bb54 &);
    Ptr32<char> text;
    template <class W3dU> d24d_String_8020bb54(Ptr32<W3dU> w3d_p) : d24d_String_8020bb54((const char *)w3d_p.get()) {}
 d24d_String_8020bb54(const char *);
    ~d24d_String_8020bb54();
    d24d_String_8020bb54 &operator=(const d24d_String_8020bb54 &other);
};
extern "C" void d24d_string_finish_8020c5c4(Ptr32<d24d_String_8020bb54>);
extern "C" void d24d_string_release_80341588(Ptr32<d24d_String_8020bb54>);
extern "C" void d24d_string_release_header_8020bb2c(Ptr32<void>);
inline d24d_String_8020bb54::~d24d_String_8020bb54() {
    d24d_string_finish_8020c5c4(this);
    d24d_string_release_80341588(this);
}
inline d24d_String_8020bb54 &d24d_String_8020bb54::operator=(const d24d_String_8020bb54 &other) {
    ++*(Ptr32<unsigned short>)(other.text - 6);
    Ptr32<unsigned short> header = (Ptr32<unsigned short>)(text - 6);
    if (--*header == 0) d24d_string_release_header_8020bb2c(header);
    text = other.text;
    return *this;
}
struct d24d_Value {
    unsigned char unknown00[36];
    d24d_String_8020bb54 name;           // +36
};
struct d24d_State {
    unsigned char unknown0[4];
    unsigned char flags; char w3d_tag_rest[3];                 // +7
    void touch() { flags |= 2; }
};
struct d24d_Record {
    Ptr32<void> unknown00;
    d24d_State state;                    // +4
    unsigned char unknown0c[8];
    Ptr32<void> list;                          // +20
};
struct d24d_Owner { Ptr32<Ptr32<void>> vtable; };
extern "C" void d24d_list_append_801ef174(Ptr32<void>, int, int, Ptr32<d24d_Value>);

extern "C" Ptr32<d24d_Value> d24d_attach_named_8017e6d0(Ptr32<d24d_Owner> owner, Ptr32<const char> name, unsigned char key, int unused, Ptr32<d24d_Value> value) {
    Ptr32<d24d_Record> record = ((Ptr32<Ptr32<d24d_Record> (Ptr32<d24d_Owner>, Ptr32<unsigned char>)>)owner->vtable[29])(owner, &key);
    Ptr32<void> list = record->list;
    value->name = d24d_String_8020bb54(name);
    d24d_list_append_801ef174(list, 44, 3, value);
    record->state.touch();
    return value;
}


