#include "w3d_ptr.h"
#line 1 "d24a_step_describe_800178b4.cpp"
/* Describes an AI plan step (0x800178b4): runs the base description (0x8000756c),
 * then appends "-> " and the name of the table entry selected by +44 to the output
 * string. Field and type names are inferred from the original instructions; the
 * unit owns no data. */
struct String;
extern "C" void w3d_string_init_8020c5c0(Ptr32<String>);
extern "C" Ptr32<unsigned short> w3d_string_header_80341884(Ptr32<String>);
extern "C" void w3d_string_finish_8020c5c4(Ptr32<String>);
extern "C" void w3d_string_release_80341588(Ptr32<String>);
extern "C" int w3d_string_append_8020bf2c(Ptr32<String>, Ptr32<const char>);
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
    String &operator+=(const String &o) {
        w3d_string_append_8020bf2c(this, o.text);
        return *this;
    }
};
inline String operator+(String a, const String &b)
{
    a += b;
    return a;
}
inline String Prefixed(const String &p, const String &n) { return p + n; }
struct Named { char unknown00[4]; String name; };
struct Table {
    Ptr32<Ptr32<Named>> first;
    Ptr32<Named> & operator[](int i) { return first[i]; }
};
extern Ptr32<Table> w3d_ai_table_804aa750;
struct Step { char unknown00[44]; int target; };
extern "C" void w3d_describe_8000756c(Ptr32<Step>, Ptr32<String>);
extern "C" char w3d_string_8036a7e4[]; /* "-> " */

extern "C" void w3d_d24a_step_describe_800178b4(Ptr32<Step> self, Ptr32<String> out)
{
    w3d_describe_8000756c(self, out);
    *out += Prefixed(String(w3d_string_8036a7e4), (*w3d_ai_table_804aa750)[self->target]->name);
}


