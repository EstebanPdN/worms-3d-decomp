#include "w3d_ptr.h"
#line 1 "d29i_allies_list_fill_8011577c.cpp"
// d29i: 0x8011577c. Allies option list fill: resolves the list from +100,
// builds two label tables titled Worms with width 30.0, and adds rows
// FE.Allies:%d, FE.Skills:12 and value %d for indexes 0 to 3.
struct Type { unsigned char unknown00[20]; Ptr32<const Type> parent; };
struct Object;
struct ObjectVtable {
    Ptr32<void> unknown00[3];
    Ptr32<void (Ptr32<Object>)> retain;       // +12
    Ptr32<void (Ptr32<Object>)> release;      // +16
    Ptr32<Ptr32<const Type> (Ptr32<Object>)> type;  // +20
    Ptr32<int (Ptr32<Object>)> kind;          // +24
    Ptr32<void> unknown1c;
    Ptr32<Ptr32<const char> (Ptr32<Object>)> name;  // +32
};
struct Object { Ptr32<ObjectVtable> vtable; };
struct Key { Ptr32<const char> name; };
// Owned type descriptor released through 0x80178474 (two written words).
struct Descriptor_80178474 {
    Ptr32<void> value;
    unsigned tag;
    Descriptor_80178474() : value(0), tag(58280) {}
    ~Descriptor_80178474();
};
struct Handle {
    Ptr32<Object> value;
    Handle() : value(0) {}
    template <class W3dU> Handle(Ptr32<W3dU> w3d_p) : Handle((Object *)w3d_p.get()) {}
 Handle(Object *next) : value(next) { if (value) value->vtable->retain(value); }
    Handle(const Handle &);
    ~Handle() { if (value) value->vtable->release(value); }
    void assign(Ptr32<Object> next) {
        if (next) {
            next->vtable->retain(next);
            if (value) value->vtable->release(value);
            value = next;
        }
    }
};
struct ArrayHeader {
    unsigned char unknown00[4];
    unsigned short kind;   // +4
    unsigned char unknown06[18];
    int count;             // +24
    unsigned short locks;  // +28
    unsigned char unknown1e[2];
    Ptr32<char> data[1];         // +32
};
struct ArrayRef { Ptr32<ArrayHeader> header; };
struct Field { unsigned char unknown00[24]; int count; };
struct List {
    unsigned char unknown00[28];
    ArrayRef values;    // +28
    Ptr32<Field> field;       // +32
};
struct Labels {
    unsigned char unknown00[24];
    ArrayRef names;     // +24
    unsigned char unknown1c[8];
    float width;        // +36
    Ptr32<char> title;        // +40
    unsigned char unknown2c[4];
    ArrayRef ids;       // +48
};
struct String {
    Ptr32<char> text;
    String();
    template <class W3dU> String(Ptr32<W3dU> w3d_p) : String((const char *)w3d_p.get()) {}
 String(const char *);
    String(const String &);
    ~String();
};
extern "C" void string_finish_8020c5c4(Ptr32<String>);
extern "C" void string_release_80341588(Ptr32<String>);
inline String::~String() {
    string_finish_8020c5c4(this);
    string_release_80341588(this);
}
extern "C" Ptr32<void> as_table_80341584(Ptr32<Object>);
extern "C" Ptr32<Object> table_get_80179598(Ptr32<void>, Ptr32<Descriptor_80178474>);
extern "C" void list_begin_801ef380(Ptr32<Object>, int, int, int, int);
extern "C" Ptr32<Ptr32<char>> array_lock_801ef048(Ptr32<ArrayRef>, int, int, int);
extern "C" Ptr32<Object> create_8020b680(Ptr32<const void>);
extern "C" void string_release_8020bb2c(Ptr32<void>);
extern "C" void string_assign_8020bd38(Ptr32<Ptr32<char>>, Ptr32<const char>);
extern "C" void string_format_8020c510(Ptr32<String>, Ptr32<const char>, ...);
extern "C" void list_append_801ef174(Ptr32<Object>, int, int, Ptr32<Object>);
static inline Ptr32<Ptr32<char>> grow(Ptr32<ArrayRef> array, int count) {
    Ptr32<ArrayHeader> header = array->header;
    if (header->kind == 1 && count == header->count) {
        ++header->locks;
        return header->data;
    }
    return array_lock_801ef048(array, count, 4, 2);
}
static inline void clear(Ptr32<ArrayRef> array) {
    Ptr32<ArrayHeader> header = array->header;
    if (header->kind == 1 && header->count == 0)
        ++header->locks;
    else
        array_lock_801ef048(array, 0, 4, 0);
}
struct Owner { unsigned char unknown00[100]; Ptr32<Object> source; };
extern const char class_80419e88[], n_8039a488[], f_8039a778[], f_8039a49c[], f_8039a4c8[];
extern const float width_8039a788[];
static inline void set_title(Ptr32<Labels> t) {
    String name(n_8039a488);
    Ptr32<char> text = name.text;
    ++*(Ptr32<unsigned short>)(text - 6);
    Ptr32<char> old = t->title;
    Ptr32<unsigned short> header = (Ptr32<unsigned short>)(old - 6);
    unsigned short n = --*header;
    if (n == 0) string_release_8020bb2c(header);
    t->title = name.text;
}
static inline void store(int index, Ptr32<Ptr32<char>> slot, const String &s) {
    Ptr32<char> text = s.text;
    ++*(Ptr32<unsigned short>)(text - 6);
    Ptr32<char> old = *(Ptr32<Ptr32<char>>)w3d::G((index + (int)w3d::H(slot)));
    Ptr32<unsigned short> header = (Ptr32<unsigned short>)(old - 6);
    unsigned short n = --*header;
    if (n == 0) string_release_8020bb2c(header);
    *(Ptr32<Ptr32<char>>)w3d::G((index + (int)w3d::H(slot))) = s.text;
}
static inline void set(Handle &h, Ptr32<Object> next) {
    if (next) next->vtable->retain(next);
    if (h.value) h.value->vtable->release(h.value);
    h.value = next;
}
extern "C" void d29i_allies_list_fill_8011577c(Ptr32<Owner> self) {
    Descriptor_80178474 descriptor;
    Handle list;
    {
        Handle value(table_get_80179598(as_table_80341584(self->source), &descriptor));
        list.assign(value.value);
    }
    Ptr32<List> l = (Ptr32<List>)list.value;
    list_begin_801ef380(list.value, 32, 0, 0, l->field->count);
    clear(&((Ptr32<List>)list.value)->values);
    String text;
    Handle a, b;
    Ptr32<const char> cls = class_80419e88;
    set(a, create_8020b680(cls));
    set(b, create_8020b680(cls));
    {
        Ptr32<Labels> t = (Ptr32<Labels>)a.value;
        String name(n_8039a488);
        Ptr32<char> text = name.text;
        ++*(Ptr32<unsigned short>)(text - 6);
        Ptr32<char> old = t->title;
        Ptr32<unsigned short> header = (Ptr32<unsigned short>)(old - 6);
        unsigned short n = --*header;
        if (n == 0) string_release_8020bb2c(header);
        t->title = name.text;
    }
    ((Ptr32<Labels>)a.value)->width = 30.0f;
    {
        Ptr32<Labels> t = (Ptr32<Labels>)b.value;
        String name(n_8039a488);
        Ptr32<char> text = name.text;
        ++*(Ptr32<unsigned short>)(text - 6);
        Ptr32<char> old = t->title;
        Ptr32<unsigned short> header = (Ptr32<unsigned short>)(old - 6);
        unsigned short n = --*header;
        if (n == 0) string_release_8020bb2c(header);
        t->title = name.text;
    }
    ((Ptr32<Labels>)b.value)->width = 30.0f;
    for (unsigned i = 0; i <= 3; i++) {
        Ptr32<ArrayRef> n1 = &((Ptr32<Labels>)a.value)->names;
        int c1 = n1->header->count;
        Ptr32<Ptr32<char>> s1 = grow(n1, c1 + 1);
        Ptr32<ArrayRef> n2 = &((Ptr32<Labels>)b.value)->names;
        int c2 = n2->header->count;
        Ptr32<Ptr32<char>> s2 = grow(n2, c2 + 1);
        string_format_8020c510(&text, f_8039a778, i);
        c1 <<= 2;
        store(c1, s1, text);
        string_format_8020c510(&text, f_8039a49c);
        c2 <<= 2;
        store(c2, s2, text);
        Ptr32<ArrayRef> v = &((Ptr32<List>)list.value)->values;
        int c3 = v->header->count;
        Ptr32<Ptr32<char>> s3 = grow(v, c3 + 1);
        {
            String t;
            string_format_8020c510(&t, f_8039a4c8, i);
            c3 <<= 2;
            store(c3, s3, t);
        }
    }
    list_append_801ef174(list.value, 32, 0, a.value);
    list_append_801ef174(list.value, 32, 0, b.value);
}


