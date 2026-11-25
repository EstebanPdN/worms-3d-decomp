#include "w3d_ptr.h"
#line 1 "d24i_setting_substitute_80103a5c.cpp"
// d24i: 0x80103a5c (488 bytes). Read a text setting and write it back with a
// placeholder replaced. The setting named by item +44 is read (0x800fc2b0); if
// absent, a copy of its name is made and dropped. Every occurrence of the
// pattern in item +52 is replaced by the text of item +56, using the same
// rebuild-and-share loop as d24i_string_replace_all_801099a4, and the result is
// written (0x800fc550) to the setting named by item +48; a failed write makes
// and drops a copy of that name.
struct d24i_String {
    Ptr32<char> text;
    d24i_String();
    template <class W3dU> d24i_String(Ptr32<W3dU> w3d_p) : d24i_String((const char *)w3d_p.get()) {}
 d24i_String(const char *);
    d24i_String(const d24i_String &);
    ~d24i_String();
    d24i_String &operator=(const d24i_String &other);
};
extern "C" void d24i_string_init_8020c5c0(Ptr32<d24i_String>);
extern "C" Ptr32<unsigned short> d24i_string_header_80341884(Ptr32<d24i_String>);
extern "C" void d24i_string_finish_8020c5c4(Ptr32<d24i_String>);
extern "C" void d24i_string_release_80341588(Ptr32<d24i_String>);
extern "C" Ptr32<d24i_String> d24i_string_prefix_8020c048(Ptr32<d24i_String>, Ptr32<const d24i_String>, int);
extern "C" Ptr32<d24i_String> d24i_string_append_8020bf2c(Ptr32<d24i_String>, Ptr32<const char>);
extern "C" void d24i_release_header_8020bb2c(Ptr32<unsigned short>);
extern "C" Ptr32<char> strstr(Ptr32<const char>, Ptr32<const char>);
inline d24i_String::d24i_String(const d24i_String &other) {
    d24i_string_init_8020c5c0(this);
    text = other.text;
    ++*d24i_string_header_80341884(this);
}
inline d24i_String::~d24i_String() {
    d24i_string_finish_8020c5c4(this);
    d24i_string_release_80341588(this);
}
inline d24i_String &d24i_String::operator=(const d24i_String &other) {
    // The allocation header begins six bytes before the text; its reference
    // counter is unsigned sixteen-bit.
    ++reinterpret_cast<unsigned short *>(w3d::R(other.text))[-3];
    Ptr32<unsigned short> header = reinterpret_cast<unsigned short *>(w3d::R(text)) - 3;
    if (--*header == 0)
        d24i_release_header_8020bb2c(header);
    text = other.text;
    return *this;
}
struct d24i_Key { Ptr32<const char> name; };
struct d24i_Item;
extern "C" Ptr32<d24i_String> d24i_item_text_80179170(Ptr32<d24i_Item>);
extern "C" int d24i_setting_read_800fc2b0(Ptr32<d24i_Key>, Ptr32<Ptr32<const char>>);
extern "C" int d24i_setting_write_800fc550(Ptr32<d24i_Key>, Ptr32<const char>);
struct d24i_Binding {
    unsigned char unknown00[44];
    Ptr32<d24i_Item> source;                   // +44
    Ptr32<d24i_Item> target;                   // +48
    Ptr32<d24i_Item> pattern;                  // +52
    Ptr32<d24i_Item> replacement;              // +56
};

extern "C" void d24i_setting_substitute_80103a5c(Ptr32<d24i_Binding> self) {
    d24i_Key key;
    Ptr32<const char> stored;
    key.name = d24i_item_text_80179170(self->source)->text;
    if (d24i_setting_read_800fc2b0(&key, &stored) < 0) {
        d24i_String copy(*d24i_item_text_80179170(self->source));
        return;
    }
    d24i_String value(stored);
    d24i_String result;
    unsigned length = reinterpret_cast<unsigned short *>(w3d::R(d24i_item_text_80179170(self->pattern)->text))[-2];
    Ptr32<char> found = strstr(value.text, d24i_item_text_80179170(self->pattern)->text);
    while (found) {
        const d24i_String &source = value;
        d24i_string_prefix_8020c048(&result, &source, found - value.text);
        d24i_string_append_8020bf2c(&result, d24i_item_text_80179170(self->replacement)->text);
        d24i_string_append_8020bf2c(&result, found + length);
        value = result;
        found = strstr(value.text, d24i_item_text_80179170(self->pattern)->text);
    }
    d24i_Key out;
    out.name = d24i_item_text_80179170(self->target)->text;
    if (d24i_setting_write_800fc550(&out, value.text) < 0) {
        d24i_String copy(*d24i_item_text_80179170(self->target));
    }
}


