#include "w3d_ptr.h"
#line 1 "d30a_collect_named_80015960.cpp"
// GWMP8P rev0 0x80015960. Returns a new array of every item, in every group
// of the global group list, whose name equals the key's text, or null when
// none does. The engine array class grows by half with no allocator object;
// the group list is copied first. Names are inferred from the original
// instructions.
extern "C" Ptr32<void> w3d_handle_storage_allocate(unsigned int);
extern "C" void w3d_handle_storage_release(Ptr32<void>);
extern "C" Ptr32<void> memcpy_802eee50(Ptr32<void>, Ptr32<const void>, unsigned int, ...);
extern "C" int strcmp(Ptr32<const char>, Ptr32<const char>);
template <class T> inline const T &Max(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline const T &Min(const T &a, const T &b) { return b < a ? b : a; }
template <class T> struct Array {
    Ptr32<T> start; Ptr32<T> finish; Ptr32<T> storage_end;
    Array() { start = finish = storage_end = 0; }
    Array(const Array &o) {
        unsigned int n = (Ptr32<char>)o.finish - (Ptr32<char>)o.start;
        Ptr32<T> p = (Ptr32<T>)w3d_handle_storage_allocate(n);
        start = p; finish = (Ptr32<T>)((Ptr32<char>)p + n); storage_end = finish;
        memcpy_802eee50(p, o.start, n);
    }
    ~Array() { if (start) w3d_handle_storage_release(start); }
    int size() const { return finish - start; }
    bool empty() const { return start == finish; }
    T &operator[](unsigned int i) { return start[i]; }
    void grow() {
        unsigned int used = (Ptr32<char>)finish - (Ptr32<char>)start;
        int a = used + 1, b = used + (used >> 1);
        unsigned int bytes = Max(a, b) * 4;
        Ptr32<T> p = (Ptr32<T>)w3d_handle_storage_allocate(bytes);
        if (start) {
            memcpy_802eee50(p, start, Min(bytes, used));
            w3d_handle_storage_release(start);
        }
        start = p; finish = (Ptr32<T>)((Ptr32<char>)p + used); storage_end = (Ptr32<T>)((Ptr32<char>)p + bytes);
    }
    void push_back(const T &v) {
        if (finish == storage_end) grow();
        *finish = v;
        finish++;
    }
};
template <class T> inline Array<T> Clone(const Array<T> &a) { return Array<T>(a); }
struct Named { char pad[60]; Ptr32<const char> name; };
struct Group { char pad[20]; Array <Ptr32<Named> > items; };
struct Key { Ptr32<const char> text; };
extern Array <Ptr32<Group> > g_groups_8043bb64[];
extern "C" Ptr32<Array <Ptr32<Named> >> w3d_d30a_collect_named_80015960(Ptr32<Key> key)
{
    Array <Ptr32<Group> > groups = Clone(*g_groups_8043bb64);
    Ptr32<Array <Ptr32<Named> >> out = new Array<Ptr32<Named> >;
    for (unsigned int i = 0; i < groups.size(); i++) {
        Array <Ptr32<Named> > &items = groups[i]->items;
        for (unsigned int j = 0; j < items.size(); j++) {
            if (strcmp(key->text, items[j]->name) == 0) out->push_back(items[j]);
        }
    }
    if (out->empty()) { delete out; out = 0; }
    return out;
}


