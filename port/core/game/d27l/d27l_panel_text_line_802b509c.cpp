#include "w3d_ptr.h"
#line 1 "d27l_panel_text_line_802b509c.cpp"
// GWMP8P rev0 0x802b509c. Panel text: splits the source text at backslashes
// and keeps the piece selected by the second-line flag, then looks it up as
// a text property and sets the item's text, or sets an error message on a
// failed lookup; a message already present is kept when the settings flag at
// +188 bit 30 is set. Field roles are inferred from calls and diagnostic
// strings.
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
extern "C" void fn_8020c510(Ptr32<Str>, Ptr32<const char>, ...);
extern "C" unsigned strcspn(Ptr32<const char>, Ptr32<const char>);
struct Res;
struct ResVt { char u0[16]; Ptr32<void (Ptr32<Res>)> destroy; };
struct Res { Ptr32<ResVt> vt; };
struct Handle {
    Ptr32<Res> r;
    Handle() { r = 0; }
    Handle(const Handle &);
    ~Handle() { if (r) r->vt->destroy(r); }
};
struct Key { Ptr32<const char> text; };
struct Source { char u0[68]; Str text; };
struct Settings { char u0[188]; unsigned flags; };
struct Self {
    char u0[40];
    Ptr32<Source> source;
    char u44[52];
    Ptr32<void> item;
    char u100[8];
    Str message;
    char u112[108];
    bool second;
};
extern Ptr32<Settings> settings_804b1788;
extern const char s_803d7e4c[], s_803d7e84[], s_803d7e88[];
extern "C" Ptr32<void> fn_80343744(Ptr32<void>);
extern "C" int fn_801790bc(Ptr32<void>, Ptr32<const char>);
extern "C" int fn_800fc1b0(Ptr32<Key>, Ptr32<Handle>);
extern "C" Ptr32<Ptr32<const char>> fn_80179170(Ptr32<void>);
extern "C" void d27l_panel_text_line_802b509c(Ptr32<Self> self) {
    Str rest;
    Str part;
    Ptr32<Source> source = self->source;
    rest.assign(source->text);
    int n = 0;
    if (!rest.len()) {
        fn_8020bd38(&part, s_803d7e4c);
    } else {
        do {
            Ptr32<char> s = rest.p;
            part.assign(rest);
            unsigned k = strcspn(s, s_803d7e84);
            if (s[k] == '\\') {
                fn_8020c3a0(&part, k);
                k++;
            }
            s = rest.p;
            fn_8020bd38(&rest, s + k);
            if (!self->second == n)
                break;
            n++;
        } while (rest.len());
    }
    if (!self->message.len() || !(settings_804b1788->flags & 0x40000000)) {
        Str copy(part);
        if (copy.len()) {
            Handle h;
            Key k;
            k.text = copy.p;
            if (fn_800fc1b0(&k, &h) >= 0) {
                Ptr32<void> item = fn_80343744(self->item);
                fn_801790bc(item, *fn_80179170(fn_80343744(h.r)));
            } else {
                fn_8020c510(&self->message, s_803d7e88, w3d::VA(copy.p));
                fn_801790bc(fn_80343744(self->item), self->message.p);
            }
        } else {
            fn_801790bc(fn_80343744(self->item), s_803d7e4c);
        }
    } else {
        fn_801790bc(fn_80343744(self->item), self->message.p);
    }
}


