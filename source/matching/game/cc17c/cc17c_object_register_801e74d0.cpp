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
/* Observed: the registered object keeps its table index in the top 10 bits of the word at +32. */
struct Cc17cRegistered { unsigned char pad0[32]; unsigned int index : 10; unsigned int rest : 22; };
extern Cc17cSlots<Cc17cRegistered> lbl_8045e024;
extern "C" Cc17cRegistered **fn_80356474(Cc17cRegistered **, Cc17cRegistered **, Cc17cRegistered *const &);
extern "C" int fn_801ffea8(Cc17cRegistered *);
extern "C" int fn_801e7e24(Cc17cRegistered *);
extern int lbl_804ab894;
extern "C" int w3d_cc17c_object_register_801e74d0(Cc17cRegistered *object)
{
    Cc17cRegistered *none = 0;
    Cc17cRegistered *entry = object;
    Cc17cRegistered **slot = fn_80356474((Cc17cRegistered **)lbl_8045e024.begin, (Cc17cRegistered **)lbl_8045e024.end, none);
    if (slot == (Cc17cRegistered **)lbl_8045e024.end) {
        object->index = slot - (Cc17cRegistered **)lbl_8045e024.begin;
        lbl_8045e024.push(entry);
    } else {
        *slot = entry;
        object->index = slot - (Cc17cRegistered **)lbl_8045e024.begin;
    }
    fn_801ffea8(object);
    if (lbl_804ab894) return fn_801e7e24(entry);
    return 0;
}
