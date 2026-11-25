// GWMP8P rev0 0x80003710. Allocates a 16-byte command of kind 12 holding a
// float and appends it to the pointer vector at +20, growing the storage
// when full. Names are inferred from the original instructions.
extern "C" unsigned char *storage_allocate_80212fd4(unsigned int);
extern "C" void storage_release_802134fc(void *);
extern "C" void *storage_copy_802eee50(void *, const void *, ...);
extern "C" void *heap_alloc_801fe1d8(unsigned);
static inline const int &larger(const int &a, const int &b) { return a < b ? b : a; }
static inline const unsigned int &smaller(const unsigned int &a, const unsigned int &b) { return b < a ? b : a; }
inline void *operator new(unsigned, void *p) { return p; }
struct Command { int kind; float value; int unknown8; int unknownc; Command(float v) { value = v; kind = 12; } };
struct Storage {
    unsigned char *begin, *end, *capacity;
    void push(Command *const &value, unsigned char *last, unsigned char *limit) {
        if (last == limit) {
            unsigned int used = last - begin;
            int next = used + 1;
            int grown = used + (used >> 1);
            unsigned int allocated = larger(next, grown) * 4;
            unsigned char *fresh = storage_allocate_80212fd4(allocated);
            if (begin) {
                storage_copy_802eee50(fresh, begin, smaller(allocated, used));
                storage_release_802134fc(begin);
            }
            unsigned char *e = fresh + used; unsigned char *c = fresh + allocated; begin = fresh; end = e; capacity = c;
        }
        *(Command **)end = value;
        end += 4;
    }
};
struct Self { char unknown00[20]; Storage storage; };
extern "C" void w3d_d26a_queue_float_command_80003710(Self *self, float v)
{
    void *mem = heap_alloc_801fe1d8(16);
    Storage &s = self->storage;
    unsigned char *e = s.end, *c = s.capacity;
    Command *cmd = new (mem) Command(v);
    s.push(cmd, e, c);
}
