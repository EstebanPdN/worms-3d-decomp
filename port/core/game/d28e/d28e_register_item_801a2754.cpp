#include "w3d_ptr.h"
#line 1 "d28e_register_item_801a2754.cpp"
// (Worms 3D GameCube PAL, 0x801a2754).
//
// Register an item in two parallel pointer vectors at +36 and +60. When the
// object's kind field is 3 both vectors are resized to the global table size
// at 0x804b18d8, the item is stored at its index in the first and zero in
// the second; the special object at 0x80365094 instead calls 0x801a2d68 with
// one entry.

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
struct Item { char u[20]; unsigned short index; };
struct Kind { char u[32]; unsigned int :16; unsigned int kind:4; unsigned int :12; int Type() const { return kind; } };
extern unsigned lbl_804b18d8;
extern Kind lbl_80365094[];
struct Self { char u[36]; Slots <Ptr32<Item> > a; char u1[12]; Slots <Ptr32<Item> > b; };
extern "C" void fn_801a2d68(Ptr32<Self>, unsigned);
extern "C" void w3d_d28e_register_item_801a2754(Ptr32<Self> self, Ptr32<Kind> k, Ptr32<Item> item)
{
    if (k->Type() == 3) {
        self->b.resize(lbl_804b18d8);
        self->a.resize(lbl_804b18d8);
        self->a[item->index] = item;
        self->b[item->index] = 0;
    } else if (k == lbl_80365094) fn_801a2d68(self, 1);
}


