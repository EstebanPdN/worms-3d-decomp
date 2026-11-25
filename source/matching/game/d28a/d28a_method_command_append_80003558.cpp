// GWMP8P rev0 0x80003558. Allocates a 200-byte command with a kind, a
// 12-byte value and a copied method member, and appends it to the byte-
// counted pointer vector at +20. Names are inferred from the original
// instructions.
extern "C" unsigned char *w3d_handle_storage_allocate(unsigned int);
extern "C" void w3d_handle_storage_release(void *);
extern "C" void *memcpy(void *, const void *, ...);
inline const int &larger(const int &a, const int &b) { return a < b ? b : a; }
inline const unsigned int &smaller(const unsigned int &a, const unsigned int &b) { return b < a ? b : a; }
struct Plain { int a, b, c; };
struct MethodBase { int unknown[9]; virtual void dispatch(); };
struct MethodMember : MethodBase {
    virtual void dispatch();
    int rest[36];
    MethodMember();
};
struct CommandHead {
    int kind;
    Plain v;
    CommandHead(const Plain &p, int k) { v = p; kind = k; }
};
struct Command : CommandHead {
    MethodMember method;
    Command(const Plain &p, int k, const MethodMember &m) : CommandHead(p, k) { method = m; }
};
struct Storage {
    unsigned char *begin, *end, *capacity;
    void push(Command *const &value) {
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
            begin = fresh; end = fresh + used; capacity = fresh + allocated;
        }
        *(Command **)end = value;
        end += 4;
    }
};
struct Self { char unknown00[20]; Storage storage; };
extern "C" void w3d_d28a_method_command_append_80003558(Self *self, const Plain *p, int k, const MethodMember *m)
{
    Storage &st = self->storage;
    st.push(new Command(*p, k, *m));
}
