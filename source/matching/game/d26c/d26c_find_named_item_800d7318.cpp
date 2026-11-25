// d26c: 0x800d7318. Find an item by name in a local copy of the global group table and return its position. Names are
// inferred; String is one word; the table's element layout is a partial view.
typedef unsigned long size_t;
extern "C" void *memcpy(void *, const void *, size_t);
extern "C" void *storage_alloc_80212fd4(size_t);
extern "C" void storage_free_802134fc(void *);
extern "C" int strcmp(const char *, const char *);
struct Vec3 {
    float x, y, z;
    Vec3(const Vec3 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct String {
    char *text;
    String(const char *);
    String(const String &);
    ~String();
};
extern "C" void string_finish_8020c5c4(String *);
extern "C" void string_release_80341588(String *);
inline String::~String() {
    string_finish_8020c5c4(this);
    string_release_80341588(this);
}
struct Item { char u0[4]; Vec3 pos; char u16[44]; const char *name; };
template <class T> struct Vector {
    T *start, *finish, *eos;
    Vector() {}
    ~Vector() { if (start) storage_free_802134fc(start); }
    unsigned size() const { return finish - start; }
    T &operator[](unsigned i) { return start[i]; }
};
struct Group { char u0[20]; Vector<Item *> items; };
extern Vector<Group *> groups_8043bb64;
extern "C" int d26c_find_named_item_800d7318(void *self, const char *name, Vec3 *out) {
    Vector<Group *> list;
    size_t n = (char *)groups_8043bb64.finish - (char *)groups_8043bb64.start;
    Group **p = (Group **)storage_alloc_80212fd4(n);
    Group **e = (Group **)((char *)p + n);
    list.start = p;
    list.finish = e;
    list.eos = e;
    memcpy(p, groups_8043bb64.start, n);
    for (unsigned i = 0; i < list.size(); i++) {
        Vector<Item *> &items = list[i]->items;
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
