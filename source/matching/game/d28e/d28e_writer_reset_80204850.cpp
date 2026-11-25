// (Worms 3D GameCube PAL, 0x80204850).
//
// Reset a serializer: clears the 64-byte record vector at +28, the two tree
// maps at +44 and +60 (0x8035b84c, 0x8035b8a4), the state word at +24, and
// the word vector at +92.

template<class T> inline void v_dist(T *first, T *last, int &n) { n += last - first; }
template<class T> inline T *v_copy(T *first, T *last, T *out) {
    int n = 0;
    v_dist(first, last, n);
    for (; n > 0; --n) { *out = *first; ++first; ++out; }
    return out;
}
template<class T> inline void v_destroy(T *first, T *last) { for (; first != last; ++first) first->~T(); }
struct RbNode { int color; RbNode *parent; RbNode *left; RbNode *right; };
template<class T> struct Vec {
    T *start; T *finish; T *limit; int extra;
    T *begin() { return start; }
    T *end() { return finish; }
    void erase(T *first, T *last) {
        T *e = v_copy(last, finish, first);
        { T *l = finish; v_destroy(e, l); }
        finish = e;
    }
    void clear() { erase(begin(), end()); }
};
struct Rec { char u[64]; ~Rec() { } };
struct Word { int v; ~Word() { } };
struct Map1;
struct Map2;
extern "C" void w3d_auto_8035b84c(Map1 *, RbNode *);
extern "C" void w3d_auto_8035b8a4(Map2 *, RbNode *);
struct Map1 {
    int alloc; RbNode *header; unsigned count; int cmp;
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
    int alloc; RbNode *header; unsigned count; int cmp;
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
extern "C" void w3d_d28e_writer_reset_80204850(Self *self)
{
    self->recs.clear();
    self->a.clear();
    self->b.clear();
    self->count = 0;
    self->words.clear();
}
