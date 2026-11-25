#include "w3d_ptr.h"
#line 1 "d43l_list_value_apply_802b98dc.cpp"
// GWMP8P rev0 0x802b98dc. Applies the selected list entry's text to the
// named property: looks the property up by name, reports a missing one, and
// otherwise stores the text as an int, a second numeric kind or a string
// according to the property's type.
extern "C" void fn_8020c5c4(Ptr32<void>), fn_80341588(Ptr32<void>), fn_8020c5c0(Ptr32<void>), fn_8020bb2c(Ptr32<void>);
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
inline void use(Str) {}
extern "C" void fn_8020c510(Ptr32<Str>, Ptr32<const char>, ...);
struct Value;
struct ValueVt { char u0[16]; Ptr32<void (Ptr32<Value>)> destroy; char u20[4]; Ptr32<int (Ptr32<Value>)> type; };
struct Value { Ptr32<ValueVt> vt; };
struct Handle {
    Ptr32<Value> r;
    Handle() { r = 0; }
    Handle(const Handle &);
    ~Handle() { if (r) r->vt->destroy(r); }
};
struct Key { Ptr32<const char> text; };
struct List { char u0[24]; unsigned count; char u28[4]; Str items[1]; };
struct Data { char u0[28]; Ptr32<List> list; };
struct Source { char u0[164]; Str name; };
struct Self {
    char u0[40];
    Ptr32<Source> source;
    char u44[64];
    Str message;
    char u112[144];
    int busy;
    char u260[20];
    Ptr32<void> holder;
    char u284[12];
    int index;
};
extern const char s_803d7fd0[];
extern "C" void fn_802b8be0(Ptr32<Self>);
extern "C" int fn_800fc1b0(Ptr32<Key>, Ptr32<Handle>);
extern "C" Ptr32<void> fn_80341584(Ptr32<void>);
extern "C" Ptr32<Data> fn_801797b4(Ptr32<void>);
extern "C" int atoi(Ptr32<const char>);
extern "C" Ptr32<void> fn_803426b4(Ptr32<Value>); Ptr32<void> fn_80342a78(Ptr32<Value>); Ptr32<void> fn_80343744(Ptr32<Value>);
extern "C" int fn_80178c54(Ptr32<void>, Ptr32<int>), fn_80178d28(Ptr32<void>, Ptr32<int>);
extern "C" int fn_801790bc(Ptr32<void>, Ptr32<const char>);
extern "C" void d43l_list_value_apply_802b98dc(Ptr32<Self> self) {
    if (self->index != -1 && self->holder) {
        Ptr32<Source> source = self->source;
        fn_802b8be0(self);
        if (source->name.len()) {
            self->busy = 1;
            Handle h;
            Key k;
            k.text = source->name.p;
            if (fn_800fc1b0(&k, &h) < 0) {
                use(source->name);
                fn_8020c510(&self->message, s_803d7fd0, w3d::VA(source->name.p));
            } else {
                Str value;
                Ptr32<List> list = fn_801797b4(fn_80341584(self->holder))->list;
                if (list->count > (unsigned)self->index) {
                    unsigned offset = self->index * 4;
                    Ptr32<char> items; do { items = (Ptr32<char>)list + 32; } while (0);
                    const Str &item = *(Ptr32<const Str>)w3d::G((offset + (int)w3d::H(items)));
                    value.assign(item);
                    Ptr32<const char> text = value.p;
                    switch (h.r->vt->type(h.r)) {
                    case 0: {
                        int n = atoi(text);
                        fn_80178c54(fn_803426b4(h.r), &n);
                        break;
                    }
                    case 1: {
                        int n = atoi(text);
                        fn_80178d28(fn_80342a78(h.r), &n);
                        break;
                    }
                    case 4:
                        fn_801790bc(fn_80343744(h.r), value.p);
                        break;
                    }
                }
            }
            self->busy = 0;
        }
    }
}


