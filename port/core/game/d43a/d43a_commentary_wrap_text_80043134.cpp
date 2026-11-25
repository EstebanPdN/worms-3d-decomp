#include "w3d_ptr.h"
#line 1 "d43a_commentary_wrap_text_80043134.cpp"
// GWMP8P rev0 0x80043134. Splits commentary text into lines of the display
// width, breaking at a space or hyphen, and appends each line with half the
// remaining time.
struct String;
extern "C" void w3d_string_init_8020c5c0(Ptr32<String>);
extern "C" Ptr32<unsigned short> w3d_string_header_80341884(Ptr32<String>);
extern "C" void w3d_string_finish_8020c5c4(Ptr32<String>);
extern "C" void w3d_string_release_80341588(Ptr32<String>);
extern "C" void w3d_string_release_header_8020bb2c(Ptr32<void>);
struct String {
    Ptr32<const char> text;
    template <class W3dU> String(Ptr32<W3dU> w3d_p) : String((const char *)w3d_p.get()) {}
 String(const char *);
    String(const String &o) {
        w3d_string_init_8020c5c0(this);
        text = o.text;
        ++*w3d_string_header_80341884(this);
    }
    ~String() { w3d_string_finish_8020c5c4(this); w3d_string_release_80341588(this); }
    Ptr32<unsigned short> header() const { return (Ptr32<unsigned short>)(text - 6); }
    unsigned short length() const { return *(Ptr32<unsigned short>)(text - 4); }
    static void release(Ptr32<unsigned short> h) { if (--*h == 0) w3d_string_release_header_8020bb2c(h); }
    String &operator=(const String &x) {
        ++*x.header();
        release(header());
        text = x.text;
        return *this;
    }
};
extern "C" Ptr32<String> w3d_string_append_8020bf2c(Ptr32<String>, Ptr32<const char>);
extern "C" Ptr32<String> w3d_string_prefix_8020c048(Ptr32<String>, Ptr32<const String>, unsigned);
extern "C" Ptr32<String> w3d_string_suffix_8020c0fc(Ptr32<String>, Ptr32<const String>, unsigned);
struct Commentary {
    char unknown00[260];
    unsigned width;
};
extern "C" void w3d_commentary_append_80042d04(Ptr32<Commentary>, String, unsigned);
extern unsigned w3d_time_804aa978;
extern String w3d_empty_string_804b06a0[];
extern "C" void w3d_d43a_commentary_wrap_text_80043134(Ptr32<Commentary> self, String text, unsigned time)
{
    String rest = text;
    while (rest.length() != 0) {
        Ptr32<const char> s = rest.text;
        unsigned n = rest.header()[1];
        unsigned len = n;
        if (len < self->width) {
            w3d_commentary_append_80042d04(self, rest, time);
            rest = *w3d_empty_string_804b06a0;
        } else {
            if (time == 0) time = w3d_time_804aa978;
            time >>= 1;
            Ptr32<const char> p = s + self->width;
            n = self->width;
            if (len != 0) {
                while (p > s && *p != ' ' && *p != '-') {
                    --p;
                    --n;
                }
                if (p == s) {
                    String t("");
                    w3d_string_prefix_8020c048(&t, &rest, self->width);
                    w3d_string_append_8020bf2c(&t, "-");
                    w3d_commentary_append_80042d04(self, t, time);
                    w3d_string_suffix_8020c0fc(&rest, &rest, rest.length() - self->width);
                } else {
                    String t("");
                    w3d_string_prefix_8020c048(&t, &rest, n);
                    w3d_commentary_append_80042d04(self, t, time);
                    w3d_string_suffix_8020c0fc(&rest, &rest, rest.length() - n);
                }
            }
        }
    }
}


