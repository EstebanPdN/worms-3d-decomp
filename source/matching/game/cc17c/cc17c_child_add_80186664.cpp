/* Same growth shape as the admitted pointer-vector append 0x8020abe0 (cx10b): byte-addressed
 * pointer storage grown to max(used + 1, used * 3 / 2) entries. Inferred names. */
extern "C" void *allocate_80212fd4(unsigned int);
extern "C" void free_802134fc(void *);
extern "C" void *copy_802eee50(void *, const void *, unsigned int, ...);
static inline const int &maximum(const int &a, const int &b) { return a < b ? b : a; }
static inline const unsigned int &minimum(const unsigned int &a, const unsigned int &b) { return b < a ? b : a; }
template <class T> struct Cc17cSlots {
    unsigned char *begin, *end, *capacity;
    void push(T *const &value) {
        if (end == capacity) {
            unsigned int used = end - begin;
            unsigned int bytes = maximum((int)used + 1, (int)(used + (used >> 1))) << 2;
            unsigned char *data = (unsigned char *)allocate_80212fd4(bytes);
            if (begin) { copy_802eee50(data, begin, minimum(bytes, used)); free_802134fc(begin); }
            begin = data; end = data + used; capacity = data + bytes;
        }
        *(T **)end = value; end += 4;
    }
};
struct Cc17cNode;
/* Observed child slot +20 attaches to the parent; parent slots +76 and +100 (inferred roles). */
struct Cc17cNodeTable {
    char pad0[20];
    int (*attach)(Cc17cNode *, Cc17cNode *);
    char pad24[52];
    int (*set_state)(Cc17cNode *, int, int);
    char pad80[20];
    int (*state)(Cc17cNode *);
};
/* Observed: child pointer vector at +104. */
struct Cc17cNode { Cc17cNodeTable *vtable; char pad4[100]; Cc17cSlots<Cc17cNode> children; };
extern "C" int w3d_cc17c_child_add_80186664(Cc17cNode *self, Cc17cNode *child)
{
    self->children.push(child);
    child->vtable->attach(child, self);
    self->vtable->set_state(self, self->vtable->state(self), 1);
    return 0;
}
