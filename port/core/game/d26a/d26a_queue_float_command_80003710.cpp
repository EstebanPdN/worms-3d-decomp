#include "w3d_ptr.h"
#line 1 "d26a_queue_float_command_80003710.cpp"
// GWMP8P rev0 0x80003710. Allocates a 16-byte command of kind 12 holding a
// float and appends it to the pointer vector at +20, growing the storage
// when full. Names are inferred from the original instructions.
extern "C" Ptr32<unsigned char> storage_allocate_80212fd4(unsigned int);
extern "C" void storage_release_802134fc(Ptr32<void>);
extern "C" Ptr32<void> storage_copy_802eee50(Ptr32<void>, Ptr32<const void>, ...);
extern "C" Ptr32<void> heap_alloc_801fe1d8(unsigned);
static inline const int &larger(const int &a, const int &b) { return a < b ? b : a; }
static inline const unsigned int &smaller(const unsigned int &a, const unsigned int &b) { return b < a ? b : a; }
inline void *operator new(__SIZE_TYPE__, void *p) { return p; }
struct Command { int kind; float value; int unknown8; int unknownc; Command(float v) { value = v; kind = 12; } };
struct Storage {
    Ptr32<unsigned char> begin; Ptr32<unsigned char> end; Ptr32<unsigned char> capacity;
    void push(Ptr32<Command> const &value, Ptr32<unsigned char> last, Ptr32<unsigned char> limit) {
        if (last == limit) {
            unsigned int used = last - begin;
            int next = used + 1;
            int grown = used + (used >> 1);
            unsigned int allocated = larger(next, grown) * 4;
            Ptr32<unsigned char> fresh = storage_allocate_80212fd4(allocated);
            if (begin) {
                storage_copy_802eee50(fresh, begin, smaller(allocated, used));
                storage_release_802134fc(begin);
            }
            Ptr32<unsigned char> e = fresh + used; Ptr32<unsigned char> c = fresh + allocated; begin = fresh; end = e; capacity = c;
        }
        *(Ptr32<Ptr32<Command>>)end = value;
        end += 4;
    }
};
struct Self { char unknown00[20]; Storage storage; };
extern "C" void w3d_d26a_queue_float_command_80003710(Ptr32<Self> self, float v)
{
    Ptr32<void> mem = heap_alloc_801fe1d8(16);
    Storage &s = self->storage;
    Ptr32<unsigned char> e = s.end; Ptr32<unsigned char> c = s.capacity;
    Ptr32<Command> cmd = new (mem) Command(v);
    s.push(cmd, e, c);
}


