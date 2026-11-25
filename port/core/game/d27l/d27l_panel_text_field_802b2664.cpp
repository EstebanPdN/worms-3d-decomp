#include "w3d_ptr.h"
#line 1 "d27l_panel_text_field_802b2664.cpp"
// GWMP8P rev0 0x802b2664. Returns the backslash-separated field of a text
// selected by index: the string parameter is by value and destroyed here,
// the result goes through the hidden pointer. Index -1 or an empty text
// returns the empty string; when the index runs past the end the first field
// is returned. The first parameter (the panel) is unused.
extern "C" void fn_8020c5c4(Ptr32<void>), fn_80341588(Ptr32<void>), fn_8020bb2c(Ptr32<void>), fn_8020c5c0(Ptr32<void>);
struct Header {
    unsigned short refs, length, capacity;
    void release() {
        if (!--refs)
            fn_8020bb2c(this);
    }
};
extern "C" Ptr32<Header> fn_80341884(Ptr32<void>);
struct Str {
    Ptr32<char> p;
    Str();
    template <class W3dU> Str(Ptr32<W3dU> w3d_p) : Str((const char *)w3d_p.get()) {}
 Str(const char *);
    Str(const Str &o) {
        fn_8020c5c0(this);
        p = o.p;
        Ptr32<Header> h = fn_80341884(this);
        ++h->refs;
    }
    ~Str() {
        fn_8020c5c4(this);
        fn_80341588(this);
    }
    unsigned len() const { return *(Ptr32<unsigned short>)(p - 4); }
    void assign(const Str &o) {
        ++((Ptr32<Header>)(o.p - 6))->refs;
        ((Ptr32<Header>)(p - 6))->release();
        p = o.p;
    }
};
extern "C" Ptr32<void> fn_8020bd38(Ptr32<Str>, Ptr32<const char>);
extern "C" void fn_8020c3a0(Ptr32<Str>, unsigned);
extern "C" unsigned strcspn(Ptr32<const char>, Ptr32<const char>);
extern const char s_803d7a50[], s_803d7a1c[];
extern "C" Str d27l_panel_text_field_802b2664(Ptr32<void> self, Str text, int index) {
    Str result(s_803d7a50);
    if (index == -1 || !text.len())
        return result;
    result.assign(text);
    int n = 0;
    Str rest(text);
    Str part;
    while (rest.len()) {
        part.assign(rest);
        Ptr32<char> s = part.p;
        unsigned k = strcspn(s, s_803d7a1c);
        if (s[k] == '\\') {
            fn_8020c3a0(&part, k);
            if (!n)
                result.assign(part);
            k++;
        }
        if (n == index)
            return part;
        s = rest.p;
        n++;
        fn_8020bd38(&rest, s + k);
    }
    return result;
}


