#include "w3d_ptr.h"
#line 1 "d28e_writer_reset_80204850.cpp"
// (Worms 3D GameCube PAL, 0x80204850).
//
// Reset a serializer: clears the 64-byte record vector at +28, the two tree
// maps at +44 and +60 (0x8035b84c, 0x8035b8a4), the state word at +24, and
// the word vector at +92.

template<class T> inline void v_dist(T *first, T *last, int &n) { n += last - first; }
template<class T> inline Ptr32<T> v_copy(T *first, T *last, T *out) {
    int n = 0;
    v_dist(w3d::R(first), w3d::R(last), n);
    for (; n > 0; --n) { *out = *first; ++first; ++out; }
    return out;
}
template<class T> inline void v_destroy(T *first, T *last) { for (; first != last; ++first) first->~T(); }
struct RbNode { int color; Ptr32<RbNode> parent; Ptr32<RbNode> left; Ptr32<RbNode> right; };
template<class T> struct Vec {
    Ptr32<T> start; Ptr32<T> finish; Ptr32<T> limit; int extra;
    Ptr32<T> begin() { return start; }
    Ptr32<T> end() { return finish; }
    void erase(Ptr32<T> first, Ptr32<T> last) {
        Ptr32<T> e = v_copy(w3d::R(last), w3d::R(finish), w3d::R(first));
        { Ptr32<T> l = finish; v_destroy(w3d::R(e), w3d::R(l)); }
        finish = e;
    }
    void clear() { erase(begin(), end()); }
};
struct Rec { char u[64]; ~Rec() { } };
struct Word { int v; ~Word() { } };
struct Map1;
struct Map2;
extern "C" void w3d_auto_8035b84c(Ptr32<Map1>, Ptr32<RbNode>);
extern "C" void w3d_auto_8035b8a4(Ptr32<Map2>, Ptr32<RbNode>);
struct Map1 {
    int alloc; Ptr32<RbNode> header; unsigned count; int cmp;
    void clear() {
        if (count != 0) {
            w3d_auto_8035b84c(this, header->parent);
            header->left = header;
            header->parent = 0;
            header->right = header;
            count = 0;
        }
    }
};
struct Map2 {
    int alloc; Ptr32<RbNode> header; unsigned count; int cmp;
    void clear() {
        if (count != 0) {
            w3d_auto_8035b8a4(this, header->parent);
            header->left = header;
            header->parent = 0;
            header->right = header;
            count = 0;
        }
    }
};
struct Self { char u[24]; int count; Vec<Rec> recs; Map1 a; Map2 b; char u76[16]; Vec<Word> words; };
extern "C" void w3d_d28e_writer_reset_80204850(Ptr32<Self> self)
{
    self->recs.clear();
    self->a.clear();
    self->b.clear();
    self->count = 0;
    self->words.clear();
}


