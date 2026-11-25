#include "w3d_ptr.h"
#line 1 "d28a_method_command_append_80003558.cpp"
// GWMP8P rev0 0x80003558. Allocates a 200-byte command with a kind, a
// 12-byte value and a copied method member, and appends it to the byte-
// counted pointer vector at +20. Names are inferred from the original
// instructions.
extern "C" Ptr32<unsigned char> w3d_handle_storage_allocate(unsigned int);
extern "C" void w3d_handle_storage_release(Ptr32<void>);
extern "C" Ptr32<void> memcpy(Ptr32<void>, Ptr32<const void>, ...);
inline const int &larger(const int &a, const int &b) { return a < b ? b : a; }
inline const unsigned int &smaller(const unsigned int &a, const unsigned int &b) { return b < a ? b : a; }
struct Plain { int a, b, c; };
struct MethodBase { int unknown[9]; void w3d_r_dispatch() __asm__(W3D_SYM("_ZN10MethodBase8dispatchEv"));  __attribute__((always_inline)) inline void dispatch() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_MethodBase, 2))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_MethodBase; };
struct MethodMember : MethodBase {
    void w3d_r_dispatch() __asm__(W3D_SYM("_ZN12MethodMember8dispatchEv"));
    int rest[36] __attribute__((aligned(__alignof__(MethodBase))));
    MethodMember();
 __attribute__((always_inline)) inline void dispatch() { this->MethodBase::dispatch(); } };
struct CommandHead {
    int kind;
    Plain v;
    CommandHead(const Plain &p, int k) { v = p; kind = k; }
};
struct Command : CommandHead {
    MethodMember method __attribute__((aligned(__alignof__(CommandHead))));
    Command(const Plain &p, int k, const MethodMember &m) : CommandHead(p, k) { method = m; }
};
struct Storage {
    Ptr32<unsigned char> begin; Ptr32<unsigned char> end; Ptr32<unsigned char> capacity;
    void push(Ptr32<Command> const &value) {
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
            begin = fresh; end = fresh + used; capacity = fresh + allocated;
        }
        *(Ptr32<Ptr32<Command>>)end = value;
        end += 4;
    }
};
struct Self { char unknown00[20]; Storage storage; };
extern "C" void w3d_d28a_method_command_append_80003558(Ptr32<Self> self, Ptr32<const Plain> p, int k, Ptr32<const MethodMember> m)
{
    Storage &st = self->storage;
    st.push(new Command(*p, k, *m));
}


