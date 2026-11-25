#include "w3d_ptr.h"
#line 1 "cc17c_child_add_80186664.cpp"
/* Same growth shape as the admitted pointer-vector append 0x8020abe0 (cx10b): byte-addressed
 * pointer storage grown to max(used + 1, used * 3 / 2) entries. Inferred names. */
extern "C" Ptr32<void> allocate_80212fd4(unsigned int);
extern "C" void free_802134fc(Ptr32<void>);
extern "C" Ptr32<void> copy_802eee50(Ptr32<void>, Ptr32<const void>, unsigned int, ...);
static inline const int &maximum(const int &a, const int &b) { return a < b ? b : a; }
static inline const unsigned int &minimum(const unsigned int &a, const unsigned int &b) { return b < a ? b : a; }
template <class T> struct Cc17cSlots {
    Ptr32<unsigned char> begin; Ptr32<unsigned char> end; Ptr32<unsigned char> capacity;
    void push(Ptr32<T> const &value) {
        if (end == capacity) {
            unsigned int used = end - begin;
            unsigned int bytes = maximum((int)used + 1, (int)(used + (used >> 1))) << 2;
            Ptr32<unsigned char> data = (Ptr32<unsigned char>)allocate_80212fd4(bytes);
            if (begin) { copy_802eee50(data, begin, minimum(bytes, used)); free_802134fc(begin); }
            begin = data; end = data + used; capacity = data + bytes;
        }
        *(Ptr32<Ptr32<T>>)end = value; end += 4;
    }
};
struct Cc17cNode;
/* Observed child slot +20 attaches to the parent; parent slots +76 and +100 (inferred roles). */
struct Cc17cNodeTable {
    char pad0[20];
    Ptr32<int (Ptr32<Cc17cNode>, Ptr32<Cc17cNode>)> attach;
    char pad24[52];
    Ptr32<int (Ptr32<Cc17cNode>, int, int)> set_state;
    char pad80[20];
    Ptr32<int (Ptr32<Cc17cNode>)> state;
};
/* Observed: child pointer vector at +104. */
struct Cc17cNode { Ptr32<Cc17cNodeTable> vtable; char pad4[100]; Cc17cSlots<Cc17cNode> children; };
extern "C" int w3d_cc17c_child_add_80186664(Ptr32<Cc17cNode> self, Ptr32<Cc17cNode> child)
{
    self->children.push(child);
    child->vtable->attach(child, self);
    self->vtable->set_state(self, self->vtable->state(self), 1);
    return 0;
}


