// GWMP8P rev0 0x80015960. Returns a new array of every item, in every group
// of the global group list, whose name equals the key's text, or null when
// none does. The engine array class grows by half with no allocator object;
// the group list is copied first. Names are inferred from the original
// instructions.
extern "C" void *w3d_handle_storage_allocate(unsigned int);
extern "C" void w3d_handle_storage_release(void *);
extern "C" void *memcpy_802eee50(void *, const void *, unsigned int, ...);
extern "C" int strcmp(const char *, const char *);
template <class T> inline const T &Max(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline const T &Min(const T &a, const T &b) { return b < a ? b : a; }
template <class T> struct Array {
    T *start, *finish, *storage_end;
    Array() { start = finish = storage_end = 0; }
    Array(const Array &o) {
        unsigned int n = (char *)o.finish - (char *)o.start;
        T *p = (T *)w3d_handle_storage_allocate(n);
        start = p; finish = (T *)((char *)p + n); storage_end = finish;
        memcpy_802eee50(p, o.start, n);
    }
    ~Array() { if (start) w3d_handle_storage_release(start); }
    int size() const { return finish - start; }
    bool empty() const { return start == finish; }
    T &operator[](unsigned int i) { return start[i]; }
    void grow() {
        unsigned int used = (char *)finish - (char *)start;
        int a = used + 1, b = used + (used >> 1);
        unsigned int bytes = Max(a, b) * 4;
        T *p = (T *)w3d_handle_storage_allocate(bytes);
        if (start) {
            memcpy_802eee50(p, start, Min(bytes, used));
            w3d_handle_storage_release(start);
        }
        start = p; finish = (T *)((char *)p + used); storage_end = (T *)((char *)p + bytes);
    }
    void push_back(const T &v) {
        if (finish == storage_end) grow();
        *finish = v;
        finish++;
    }
};
template <class T> inline Array<T> Clone(const Array<T> &a) { return Array<T>(a); }
struct Named { char pad[60]; const char *name; };
struct Group { char pad[20]; Array<Named *> items; };
struct Key { const char *text; };
extern Array<Group *> g_groups_8043bb64[];
extern "C" Array<Named *> *w3d_d30a_collect_named_80015960(Key *key)
{
    Array<Group *> groups = Clone(*g_groups_8043bb64);
    Array<Named *> *out = new Array<Named *>;
    for (unsigned int i = 0; i < groups.size(); i++) {
        Array<Named *> &items = groups[i]->items;
        for (unsigned int j = 0; j < items.size(); j++) {
            if (strcmp(key->text, items[j]->name) == 0) out->push_back(items[j]);
        }
    }
    if (out->empty()) { delete out; out = 0; }
    return out;
}
