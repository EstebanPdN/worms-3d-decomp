#include "w3d_ptr.h"
#line 1 "cc17c_pending_flush_801fc8ac.cpp"
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
/* Observed pending node: next at +0, bucket index at +4, optional callback at +20. */
struct Cc17cPending {
    Ptr32<Cc17cPending> next;
    int bucket;
    unsigned char pad8[12];
    Ptr32<void (Ptr32<Cc17cPending>)> callback;
};
extern Ptr32<Cc17cPending> lbl_804b05d8;
extern Cc17cSlots<Cc17cPending> lbl_8045e890[];
extern "C" void w3d_cc17c_pending_flush_801fc8ac(void)
{
    for (Ptr32<Cc17cPending> node = lbl_804b05d8; node; node = node->next) {
        lbl_8045e890[node->bucket].push(node);
        if (node->callback) node->callback(node);
    }
    lbl_804b05d8 = 0;
}


