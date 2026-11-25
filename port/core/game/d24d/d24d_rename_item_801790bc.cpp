#include "w3d_ptr.h"
#line 1 "d24d_rename_item_801790bc.cpp"
// d24d: 0x801790bc (180 bytes). Rename the object's data record: when the
// shared name at data +28 already equals the text return 1; otherwise build a
// string from the text, replace the record's name with it (the counter sits 6
// bytes before the text), destroy the string, run the refresh 0x80178b5c and
// return 0. The record pointer is a local read before the string is built;
// the string's address is taken from the constructor's argument register, the
// natural result of the named local declared after the pointer.
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
struct d24d_Data {
    unsigned char unknown00[28];
    d24d_String_8020bb54 name;           // +28
};
struct d24d_Item {
    Ptr32<void> unknown00;
    Ptr32<d24d_Data> data;                     // +4
};
extern "C" int strcmp(Ptr32<const char>, Ptr32<const char>);
extern "C" int d24d_item_refresh_80178b5c(Ptr32<d24d_Item>);

extern "C" int d24d_rename_item_801790bc(Ptr32<d24d_Item> self, Ptr32<const char> name) {
    if (strcmp(self->data->name.text, name) == 0) return 1;
    {
        Ptr32<d24d_Data> data = self->data;
        d24d_String_8020bb54 text(name);
        data->name = text;
    }
    d24d_item_refresh_80178b5c(self);
    return 0;
}


