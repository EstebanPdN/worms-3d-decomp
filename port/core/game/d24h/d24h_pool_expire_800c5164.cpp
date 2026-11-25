#include "w3d_ptr.h"
#line 1 "d24h_pool_expire_800c5164.cpp"
// Pool expiry (Worms 3D GameCube PAL, 0x800c5164, 568 bytes).
//
// Removes expired pool objects and restarts the scan after each removal.
// The STLport-shaped vector follows d24j_register_node_8017d828. Names are
// inferred.

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
struct Texture;
struct Arena { int word; };
extern Arena lbl_804af100;
extern "C" unsigned w3d_get_800f7508(Ptr32<Texture>);
extern "C" Ptr32<void> w3d_get_800f7518(Ptr32<Texture>);
extern "C" Ptr32<void> w3d_get_800f7528(Ptr32<Texture>);
extern "C" void w3d_auto_800f74d0(Ptr32<Texture>, int);
extern "C" int fn_8016239c(Ptr32<void>);
extern "C" void w3d_heap_release(Ptr32<Arena>, Ptr32<void>);
extern Vector<int> lbl_8043e438;
extern Vector<int> lbl_8043e448;
struct PoolStats { unsigned freed, added, expired, peak; };
extern PoolStats lbl_803f5718[];
extern Ptr32<Texture> lbl_804a85d8[];
extern "C" int w3d_d24h_pool_expire_800c5164(Ptr32<void> self, unsigned now) {
    for (Ptr32<int> it = lbl_8043e448.start; it != lbl_8043e448.finish; ) {
        int id = *it;
        Ptr32<Texture> texture = lbl_804a85d8[id];
        if (now > w3d_get_800f7508(texture)) {
            Ptr32<void> message = w3d_get_800f7518(texture);
            Ptr32<void> blob = w3d_get_800f7528(texture);
            if (texture) w3d_auto_800f74d0(texture, 3);
            lbl_804a85d8[id] = 0;
            lbl_8043e438.push_back(id);
            lbl_8043e448.erase(it);
            fn_8016239c(message);
            lbl_803f5718[0].expired++;
            w3d_heap_release(&lbl_804af100, blob);
            it = lbl_8043e448.start;
        } else it++;
    }
    return 10;
}


