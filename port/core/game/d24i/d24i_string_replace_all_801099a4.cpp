#include "w3d_ptr.h"
#line 1 "d24i_string_replace_all_801099a4.cpp"
// d24i: 0x801099a4 (276 bytes). Replace every occurrence of `from` in `target`
// with `to`. Each round rebuilds a local string from the text before the match,
// the replacement and the text after the match (skipping the length held in
// the header of `from`), then shares the result back into `target`. The unused
// first argument is the implicit object of the original member function. The
// append (0x8020bf2c) and prefix (0x8020c048) helpers both return their string.
struct d24i_String {
 d24i_String(const d24i_String &);
    Ptr32<char> text;
    d24i_String();
    template <class W3dU> d24i_String(Ptr32<W3dU> w3d_p) : d24i_String((const char *)w3d_p.get()) {}
 d24i_String(const char *);
    ~d24i_String();
    d24i_String &operator=(const d24i_String &other);
};
extern "C" void d24i_string_finish_8020c5c4(Ptr32<d24i_String>);
extern "C" void d24i_string_release_80341588(Ptr32<d24i_String>);
extern "C" Ptr32<d24i_String> d24i_string_prefix_8020c048(Ptr32<d24i_String>, Ptr32<const d24i_String>, int);
extern "C" Ptr32<d24i_String> d24i_string_append_8020bf2c(Ptr32<d24i_String>, Ptr32<const char>);
extern "C" void d24i_release_header_8020bb2c(Ptr32<unsigned short>);
extern "C" Ptr32<char> strstr(Ptr32<const char>, Ptr32<const char>);
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

extern "C" void d24i_string_replace_all_801099a4(Ptr32<void>, Ptr32<d24i_String> target, Ptr32<const char> from_text, Ptr32<const char> to_text) {
    d24i_String result;
    d24i_String from(from_text);
    unsigned length = reinterpret_cast<unsigned short *>(w3d::R(from.text))[-2];
    d24i_String to(to_text);
    Ptr32<char> found = strstr(target->text, from.text);
    while (found) {
        d24i_string_prefix_8020c048(&result, target, found - target->text);
        d24i_string_append_8020bf2c(&result, to.text);
        d24i_string_append_8020bf2c(&result, found + length);
        *target = result;
        found = strstr(target->text, from.text);
    }
}


