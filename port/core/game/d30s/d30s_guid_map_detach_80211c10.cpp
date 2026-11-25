#include "w3d_ptr.h"
#line 1 "d30s_guid_map_detach_80211c10.cpp"
/* GWMP8P rev0 0x80211c10. Erases a service from the map at +64 if present, then forwards to
 * the registry's table slot at +24. Real STLport 4.5.3 hash_map; the slot names are inferred. */
#include "game/d30s/d30s_guid_map.h"
struct D30sRegistryBase { int w3d_r_s0() __asm__(W3D_SYM("_ZN16D30sRegistryBase2s0Ev")); int w3d_r_s1() __asm__(W3D_SYM("_ZN16D30sRegistryBase2s1Ev")); int w3d_r_s2() __asm__(W3D_SYM("_ZN16D30sRegistryBase2s2Ev")); int w3d_r_attach(Ptr32<D30sIface>) __asm__(W3D_SYM("_ZN16D30sRegistryBase6attachEP9D30sIface")); int w3d_r_detach(Ptr32<D30sIface>) __asm__(W3D_SYM("_ZN16D30sRegistryBase6detachEP9D30sIface"));  __attribute__((always_inline)) inline int s0() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D30sRegistryBase, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int s1() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D30sRegistryBase, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int s2() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D30sRegistryBase, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int attach(Ptr32<D30sIface> w3d_a0) { return ((int (*)(w3d_u32, Ptr32<D30sIface>))w3d::vfn(this->w3d_vptr_D30sRegistryBase, 5))(w3d::h2g(this), w3d_a0); }  __attribute__((always_inline)) inline int detach(Ptr32<D30sIface> w3d_a0) { return ((int (*)(w3d_u32, Ptr32<D30sIface>))w3d::vfn(this->w3d_vptr_D30sRegistryBase, 6))(w3d::h2g(this), w3d_a0); }  Ptr32<void> w3d_vptr_D30sRegistryBase; };
struct D30sRegistry64 : D30sRegistryBase { char unknown[60] __attribute__((aligned(__alignof__(D30sRegistryBase)))); D30sIfaceMap services; };
extern "C" int d30s_guid_map_detach_80211c10(Ptr32<D30sRegistry64> self, Ptr32<D30sIface> service) {
    D30sIfaceMap &m = self->services;
    D30sIfaceMap::iterator it = m.find(w3d_auto_801fff3c(service));
    bool missing = it == m.end();
    if (!missing) m.erase(it);
    return self->detach(service);
}


