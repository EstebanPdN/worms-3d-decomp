#include "w3d_ptr.h"
#line 1 "d28e_bind_source_801a31ec.cpp"
// (Worms 3D GameCube PAL, 0x801a31ec).
//
// Store the source object and argument, keep the result of the source's
// table slot at +20, resize the parallel pointer vectors at +36 and +60 to
// the global table size, copy the global item list into the first vector and
// resize the second pair through 0x801a2d68.

extern "C" Ptr32<void> alloc_80212fd4(unsigned);
extern "C" void free_802134fc(Ptr32<void>);
extern "C" Ptr32<void> memcpy_802eee50(Ptr32<void>, Ptr32<const void>, unsigned, ...);
extern "C" Ptr32<void> memmove_802eeef4(Ptr32<void>, Ptr32<const void>, unsigned);
inline const int &v_max(const int &a, const int &b) { return a < b ? b : a; }
inline const unsigned &v_min(const unsigned &a, const unsigned &b) { return b < a ? b : a; }
template<class T> struct Slots {
    Ptr32<char> begin; Ptr32<char> end; Ptr32<char> cap;
    unsigned size() const { return (Ptr32<T>)end - (Ptr32<T>)begin; }
    T &operator[](unsigned i) { return ((Ptr32<T>)begin)[i]; }
    void erase(Ptr32<char> first, Ptr32<char> last) {
        unsigned gone = last - first;
        memcpy_802eee50(first, last, end - last);
        end -= gone;
    }
    void insert(Ptr32<char> pos, unsigned n, const T &x) {
        unsigned at = (Ptr32<T>)pos - (Ptr32<T>)begin;
        if (pos + n * sizeof(T) > cap) {
            unsigned used = end - begin;
            unsigned c = cap - begin;
            unsigned bytes = v_max((int)(c + (n - ((Ptr32<T>)cap - (Ptr32<T>)pos))), (int)(c + (c >> 1))) << 2;
            Ptr32<char> data = (Ptr32<char>)alloc_80212fd4(bytes);
            if (begin) { memcpy_802eee50(data, begin, v_min(bytes, used)); free_802134fc(begin); }
            begin = data; end = data + used; cap = data + bytes;
            pos = begin + at * sizeof(T);
        }
        if (pos == end) {
            for (unsigned i = 0; i < n; i++) *(Ptr32<T>)(end + i * sizeof(T)) = x;
            end += n * sizeof(T);
        } else {
            T y = x;
            memmove_802eeef4(pos + n * sizeof(T), pos, end - pos);
            end += n * sizeof(T);
            for (unsigned i = 0; i < n; i++) *(Ptr32<T>)pos = y;
        }
    }
    void resize(unsigned n, const T &x = T()) {
        if (n < size()) erase(begin + n * sizeof(T), end);
        else insert(end, n - size(), x);
    }
};
struct Item;
struct ItemTable { char u[20]; Ptr32<Ptr32<void> (Ptr32<Item>)> get; };
struct Item { Ptr32<ItemTable> table; };
struct Src { char u[20]; Slots <Ptr32<void> > items; };
extern unsigned lbl_804b18d8;
extern Ptr32<Src> lbl_804ab74c;
struct Self { char u[20]; Ptr32<Item> item; Ptr32<void> arg; Ptr32<void> got; char u32[4]; Slots <Ptr32<void> > a; char u1[12]; Slots <Ptr32<void> > b; };
extern "C" void fn_801a2d68(Ptr32<Self>, unsigned);
extern "C" void w3d_d28e_bind_source_801a31ec(Ptr32<Self> self, Ptr32<void> arg, Ptr32<Item> item)
{
    self->arg = arg;
    self->item = item;
    self->got = item->table->get(item);
    self->b.resize(lbl_804b18d8);
    self->a.resize(lbl_804b18d8);
    for (unsigned i = 0; i < lbl_804b18d8; i++) self->a[i] = lbl_804ab74c->items[i];
    fn_801a2d68(self, 1);
}


