#include "w3d_ptr.h"
#line 1 "d24h_pool_add_800c53a0.cpp"
// Pool handle allocation (Worms 3D GameCube PAL, 0x800c53a0, 304 bytes).
//
// Allocates an object and a copy of the source's size-prefixed blob from the
// small-data arena 0x804af100, pops a free id, records the object and the new
// generation, updates statistics and returns the handle, id + generation * 128.
// The STLport-shaped vector is the model of d24j_register_node_8017d828.

extern "C" Ptr32<void> memmove(Ptr32<void>, Ptr32<const void>, unsigned);
extern "C" Ptr32<void> w3d_handle_storage_allocate(unsigned);
extern "C" Ptr32<void> w3d_handle_storage_fallback(unsigned);
extern "C" void w3d_handle_storage_release(Ptr32<void>);
inline void *operator new(__SIZE_TYPE__, void *place) throw() { return place; }
inline Ptr32<void> v_copy_trivial(Ptr32<const void> first, Ptr32<const void> last, Ptr32<void> result) {
    if (last != first) {
        unsigned n = (Ptr32<const char>)last - (Ptr32<const char>)first;
        return (Ptr32<char>)memmove(result, first, n) + n;
    }
    return result;
}
template<class T> inline const T &v_max(const T &a, const T &b) { return a < b ? b : a; }
template<class T> inline Ptr32<T> v_fill_n(T *out, unsigned n, const T &value) {
    for (; n > 0; --n, ++out) *out = value;
    return out;
}
struct VTrue { char w3d_empty; };
template<class T> struct VAlloc {
    static Ptr32<void> allocate_bytes(unsigned n) {
        Ptr32<void> p = w3d_handle_storage_allocate(n);
        if (p == 0) p = w3d_handle_storage_fallback(n);
        return p;
    }
    Ptr32<T> allocate(unsigned n) { return n ? (Ptr32<T>)allocate_bytes(n * sizeof(T)) : 0; }
    void deallocate(Ptr32<T> p, unsigned) { if (p) w3d_handle_storage_release(p); }
 char w3d_empty; };
template<class T> struct VEnd : VAlloc<T> { Ptr32<T> data __attribute__((aligned(__alignof__(VAlloc<T>)))); };
template<class T> struct Vector {
    Ptr32<T> start;
    Ptr32<T> finish;
    VEnd<T> end_of_storage;
    unsigned size() const { return finish - start; }
    void set(Ptr32<T> s, Ptr32<T> f, Ptr32<T> e) { start = s; finish = f; end_of_storage.data = e; }
    void insert_overflow(Ptr32<T> pos, const T &x, const VTrue &, unsigned fill_len, bool atend) {
        const unsigned old_size = size();
        const unsigned len = old_size + v_max(old_size, fill_len);
        Ptr32<T> new_start = end_of_storage.allocate(len);
        Ptr32<T> new_finish = (Ptr32<T>)v_copy_trivial(start, pos, new_start);
        new_finish = v_fill_n(w3d::R(new_finish), fill_len, x);
        if (!atend) new_finish = (Ptr32<T>)v_copy_trivial(pos, finish, new_finish);
        end_of_storage.deallocate(start, end_of_storage.data - start);
        set(new_start, new_finish, new_start + len);
    }
    Ptr32<T> erase(Ptr32<T> pos) {
        if (pos + 1 != finish) v_copy_trivial(pos + 1, finish, pos);
        --finish;
        return pos;
    }
    void push_back(const T &x) {
        if (finish != end_of_storage.data) { new (finish) T(x); ++finish; }
        else insert_overflow(finish, x, VTrue(), 1, true);
    }
};
struct Arena { int word; };
extern Arena lbl_804af100;
extern "C" Ptr32<void> w3d_heap_allocate(Ptr32<Arena>, unsigned);
struct Texture;
extern "C" Ptr32<Texture> w3d_empty_800f74cc(Ptr32<void>);
struct Blob { unsigned size; char data[1]; };
extern "C" Ptr32<Blob> w3d_auto_803446e0(Ptr32<void>);
extern "C" Ptr32<void> fn_802eee50(Ptr32<void>, Ptr32<const void>, unsigned);
extern "C" void w3d_set_800f7510(Ptr32<Texture>, Ptr32<void>);
extern "C" int w3d_set_800f7500(Ptr32<Texture>, unsigned);
extern "C" void w3d_set_800f7520(Ptr32<Texture>, Ptr32<Blob>);
extern "C" void w3d_d24h_order_insert_800c54d0(int, unsigned);
extern Vector<int> lbl_8043e438;
extern Vector<int> lbl_8043e448;
struct PoolStats { unsigned freed, added, unknown08, peak; };
extern PoolStats lbl_803f5718[];
extern int lbl_804a87d8[];
extern Ptr32<Texture> lbl_804a85d8[];
extern "C" int w3d_d24h_pool_add_800c53a0(Ptr32<void> source, unsigned order) {
    Ptr32<Texture> texture = w3d_empty_800f74cc(w3d_heap_allocate(&lbl_804af100, 16));
    Ptr32<Blob> copy = (Ptr32<Blob>)w3d_heap_allocate(&lbl_804af100, w3d_auto_803446e0(source)->size);
    Ptr32<Blob> blob = w3d_auto_803446e0(source);
    fn_802eee50(copy, blob, blob->size);
    w3d_set_800f7510(texture, copy->data);
    w3d_set_800f7500(texture, order);
    w3d_set_800f7520(texture, copy);
    Ptr32<int> top = lbl_8043e438.finish - 1;
    int id = *top;
    lbl_8043e438.finish = top;
    w3d_d24h_order_insert_800c54d0(id, order);
    int generation = lbl_804a87d8[id] + 1;
    lbl_804a85d8[id] = texture;
    lbl_804a87d8[id] = generation;
    Ptr32<PoolStats> stats = lbl_803f5718;
    stats->added++;
    unsigned count = lbl_8043e448.size();
    int handle = id + (generation << 7);
    stats->peak = v_max(stats->peak, count);
    return handle;
}


