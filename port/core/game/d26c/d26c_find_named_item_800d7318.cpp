#include "w3d_ptr.h"
#line 1 "d26c_find_named_item_800d7318.cpp"
// d26c: 0x800d7318. Find an item by name in a local copy of the global group table and return its position. Names are
// inferred; String is one word; the table's element layout is a partial view.
typedef unsigned int size_t;
extern "C" Ptr32<void> memcpy(Ptr32<void>, Ptr32<const void>, size_t);
extern "C" Ptr32<void> storage_alloc_80212fd4(size_t);
extern "C" void storage_free_802134fc(Ptr32<void>);
extern "C" int strcmp(Ptr32<const char>, Ptr32<const char>);
struct Vec3 {
    float x, y, z;
    Vec3(const Vec3 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct String {
    Ptr32<char> text;
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
struct Item { char u0[4]; Vec3 pos; char u16[44]; Ptr32<const char> name; };
template <class T> struct Vector {
    Ptr32<T> start; Ptr32<T> finish; Ptr32<T> eos;
    Vector() {}
    ~Vector() { if (start) storage_free_802134fc(start); }
    unsigned size() const { return finish - start; }
    T &operator[](unsigned i) { return start[i]; }
};
struct Group { char u0[20]; Vector <Ptr32<Item> > items; };
extern Vector <Ptr32<Group> > groups_8043bb64;
extern "C" int d26c_find_named_item_800d7318(Ptr32<void> self, Ptr32<const char> name, Ptr32<Vec3> out) {
    Vector <Ptr32<Group> > list;
    size_t n = (Ptr32<char>)groups_8043bb64.finish - (Ptr32<char>)groups_8043bb64.start;
    Ptr32<Ptr32<Group>> p = (Ptr32<Ptr32<Group>>)storage_alloc_80212fd4(n);
    Ptr32<Ptr32<Group>> e = (Ptr32<Ptr32<Group>>)((Ptr32<char>)p + n);
    list.start = p;
    list.finish = e;
    list.eos = e;
    memcpy(p, groups_8043bb64.start, n);
    for (unsigned i = 0; i < list.size(); i++) {
        Vector <Ptr32<Item> > &items = list[i]->items;
        for (unsigned j = 0; j < items.size(); j++) {
            String s(items[j]->name);
            if (strcmp(s.text, name) == 0) {
                Vec3 v(items[j]->pos);
                *out = v;
                return 1;
            }
        }
    }
    return 0;
}


