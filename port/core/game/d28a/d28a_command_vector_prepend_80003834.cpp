#include "w3d_ptr.h"
#line 1 "d28a_command_vector_prepend_80003834.cpp"
// GWMP8P rev0 0x80003834. Allocates a 16-byte command with a kind and a
// 12-byte value and inserts it at the front of the byte-counted pointer
// vector at +20. Names are inferred from the original instructions.
extern "C" Ptr32<unsigned char> w3d_handle_storage_allocate(unsigned int);
extern "C" void w3d_handle_storage_release(Ptr32<void>);
extern "C" Ptr32<void> memcpy(Ptr32<void>, Ptr32<const void>, ...);
extern "C" Ptr32<void> memmove(Ptr32<void>, Ptr32<const void>, unsigned);
inline const int &larger(const int &a, const int &b) { return a < b ? b : a; }
inline const unsigned int &smaller(const unsigned int &a, const unsigned int &b) { return b < a ? b : a; }
struct Plain { int a, b, c; };
struct Command { int kind; Plain v; Command(const Plain &p, int k) { v = p; kind = k; } };
struct Storage {
    Ptr32<unsigned char> begin; Ptr32<unsigned char> end; Ptr32<unsigned char> capacity;
    void insert(Ptr32<unsigned char> where, Ptr32<Command> const &value) {
        int index = (Ptr32<Ptr32<Command>>)where - (Ptr32<Ptr32<Command>>)begin;
        if (end == capacity) {
            unsigned int used = end - begin;
            int next = used + 1;
            int grown = used + (used >> 1);
            unsigned int allocated = larger(next, grown) * 4;
            Ptr32<unsigned char> fresh = w3d_handle_storage_allocate(allocated);
            if (begin) {
                memcpy(fresh, begin, smaller(allocated, used));
                w3d_handle_storage_release(begin);
            }
            where = fresh + index * 4;
            Ptr32<unsigned char> e = fresh + used; Ptr32<unsigned char> c = fresh + allocated; begin = fresh; end = e; capacity = c;
        }
        if (where == end) {
            *(Ptr32<Ptr32<Command>>)where = value;
            end += 4;
        } else {
            Ptr32<Command> keep = value;
            memmove(where + 4, where, end - where);
            end += 4;
            *(Ptr32<Ptr32<Command>>)where = keep;
        }
    }
};
struct Self { char unknown00[20]; Storage storage; };
extern "C" void w3d_d28a_command_vector_prepend_80003834(Ptr32<Self> self, Ptr32<const Plain> p, int k)
{
    Ptr32<unsigned char> first = self->storage.begin;
    Storage &st = self->storage;
    st.insert(first, new Command(*p, k));
}


