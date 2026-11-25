#include "w3d_ptr.h"
#line 1 "d30s_guid_map_attach_80211a14.cpp"
/* GWMP8P rev0 0x80211a14. Stores a service in the map at +64, appends it to the list selected
 * by a 4-bit field at +32 (twelve-byte lists from +92), and forwards to the table slot at +20.
 * Real STLport 4.5.3 hash_map. The list class is hand-written from the original: its growth
 * works in bytes (capacity max(size + 1, size * 3 / 2) * 4) with no allocation fallback, and it
 * is not an STLport member. memcpy is declared variadic because the original clears cr1 first. */
#include "game/d30s/d30s_guid_map.h"
struct D30sRegistryBase { int w3d_r_s0() __asm__(W3D_SYM("_ZN16D30sRegistryBase2s0Ev")); int w3d_r_s1() __asm__(W3D_SYM("_ZN16D30sRegistryBase2s1Ev")); int w3d_r_s2() __asm__(W3D_SYM("_ZN16D30sRegistryBase2s2Ev")); int w3d_r_attach(Ptr32<D30sIface>) __asm__(W3D_SYM("_ZN16D30sRegistryBase6attachEP9D30sIface")); int w3d_r_detach(Ptr32<D30sIface>) __asm__(W3D_SYM("_ZN16D30sRegistryBase6detachEP9D30sIface"));  __attribute__((always_inline)) inline int s0() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D30sRegistryBase, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int s1() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D30sRegistryBase, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int s2() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D30sRegistryBase, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int attach(Ptr32<D30sIface> w3d_a0) { return ((int (*)(w3d_u32, Ptr32<D30sIface>))w3d::vfn(this->w3d_vptr_D30sRegistryBase, 5))(w3d::h2g(this), w3d_a0); }  __attribute__((always_inline)) inline int detach(Ptr32<D30sIface> w3d_a0) { return ((int (*)(w3d_u32, Ptr32<D30sIface>))w3d::vfn(this->w3d_vptr_D30sRegistryBase, 6))(w3d::h2g(this), w3d_a0); }  Ptr32<void> w3d_vptr_D30sRegistryBase; };
extern "C" Ptr32<void> w3d_handle_storage_allocate(unsigned);
extern "C" void w3d_handle_storage_release(Ptr32<void>);
extern "C" Ptr32<void> d30s_memcpy_802eee50(...);
template <class T> inline const T &d30s_max(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline const T &d30s_min(const T &a, const T &b) { return b < a ? b : a; }
template <class T> struct D30sList {
    Ptr32<T> start; Ptr32<T> finish; Ptr32<T> storage;
    void grow() {
        unsigned size = (Ptr32<char>)finish - (Ptr32<char>)start;
        unsigned capacity = d30s_max<int>(size + 1, size + (size >> 1)) * 4;
        Ptr32<char> fresh = (Ptr32<char>)w3d_handle_storage_allocate(capacity);
        if (start) {
            d30s_memcpy_802eee50(fresh, start, d30s_min(capacity, size));
            w3d_handle_storage_release(start);
        }
        start = (Ptr32<T>)fresh;
        finish = (Ptr32<T>)(fresh + size);
        storage = (Ptr32<T>)(fresh + capacity);
    }
    void push(const T &v) {
        if (finish == storage) grow();
        *finish = v;
        ++finish;
    }
};
struct D30sMember : D30sIface { char u[28] __attribute__((aligned(__alignof__(D30sIface)))); unsigned int rest:16; unsigned int kind:4; unsigned int reserved:12; };
struct D30sRegistry64 : D30sRegistryBase { char unknown[60] __attribute__((aligned(__alignof__(D30sRegistryBase)))); D30sIfaceMap services; char u2[28 - 28]; D30sList <Ptr32<D30sMember> > lists[16]; };
extern "C" int d30s_guid_map_attach_80211a14(Ptr32<D30sRegistry64> self, Ptr32<D30sMember> s) {
    self->services[w3d_auto_801fff3c(s)] = s;
    self->lists[s->kind].push(s);
    return self->attach(s);
}


