// GWMP8P rev0 0x80003834. Allocates a 16-byte command with a kind and a
// 12-byte value and inserts it at the front of the byte-counted pointer
// vector at +20. Names are inferred from the original instructions.
extern "C" unsigned char *w3d_handle_storage_allocate(unsigned int);
extern "C" void w3d_handle_storage_release(void *);
extern "C" void *memcpy(void *, const void *, ...);
extern "C" void *memmove(void *, const void *, unsigned);
inline const int &larger(const int &a, const int &b) { return a < b ? b : a; }
inline const unsigned int &smaller(const unsigned int &a, const unsigned int &b) { return b < a ? b : a; }
struct Plain { int a, b, c; };
struct Command { int kind; Plain v; Command(const Plain &p, int k) { v = p; kind = k; } };
struct Storage {
    unsigned char *begin, *end, *capacity;
    void insert(unsigned char *where, Command *const &value) {
        int index = (Command **)where - (Command **)begin;
        if (end == capacity) {
            unsigned int used = end - begin;
            int next = used + 1;
            int grown = used + (used >> 1);
            unsigned int allocated = larger(next, grown) * 4;
            unsigned char *fresh = w3d_handle_storage_allocate(allocated);
            if (begin) {
                memcpy(fresh, begin, smaller(allocated, used));
                w3d_handle_storage_release(begin);
            }
            where = fresh + index * 4;
            unsigned char *e = fresh + used, *c = fresh + allocated; begin = fresh; end = e; capacity = c;
        }
        if (where == end) {
            *(Command **)where = value;
            end += 4;
        } else {
            Command *keep = value;
            memmove(where + 4, where, end - where);
            end += 4;
            *(Command **)where = keep;
        }
    }
};
struct Self { char unknown00[20]; Storage storage; };
extern "C" void w3d_d28a_command_vector_prepend_80003834(Self *self, const Plain *p, int k)
{
    unsigned char *first = self->storage.begin;
    Storage &st = self->storage;
    st.insert(first, new Command(*p, k));
}
