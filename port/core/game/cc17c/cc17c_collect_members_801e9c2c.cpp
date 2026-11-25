#include "w3d_ptr.h"
#line 1 "cc17c_collect_members_801e9c2c.cpp"
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
struct Cc17cMember;
struct Cc17cClass;
/* Observed class virtual slot +32 returns the member count. */
struct Cc17cClassTable { char pad0[32]; Ptr32<unsigned int (Ptr32<Cc17cClass>)> member_count; };
/* Observed: parent class at +20 (the root is its own parent), member pointer array at +48,
 * flattened member pointer vector at +60. */
struct Cc17cClass {
    Ptr32<Cc17cClassTable> vtable;
    unsigned char pad4[16];
    Ptr32<Cc17cClass> parent;
    unsigned char pad24[24];
    Ptr32<Ptr32<void>> members;
    unsigned char pad52[8];
    Cc17cSlots<Cc17cMember> all_members;
    Ptr32<Cc17cMember> member(unsigned int index) const { return (Ptr32<Cc17cMember>)*(Ptr32<Ptr32<void>>)((Ptr32<char>)members + (index << 2)); }
};
extern "C" void w3d_cc17c_collect_members_801e9c2c(Ptr32<Cc17cClass> self)
{
    Ptr32<Cc17cClass> chain[32];
    int depth = 0;
    Ptr32<Cc17cClass> klass = self;
    Ptr32<Ptr32<Cc17cClass>> slot = chain;
    Ptr32<Cc17cClass> previous;
    do {
        *slot = klass;
        previous = klass;
        klass = klass->parent;
        slot++;
        depth++;
    } while (klass != previous);
    while (depth) {
        klass = chain[--depth];
        unsigned int count = klass->vtable->member_count(klass);
        for (unsigned int j = 0; j < count; j++)
            self->all_members.push(klass->member(j));
    }
}


