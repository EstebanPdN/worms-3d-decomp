#include "w3d_ptr.h"
#line 1 "d31s_map_remove_801d2aac.cpp"
/* GWMP8P rev0 0x801d2aac. Removes entries from a real STLport 4.5.3 map keyed by id and interface.
 * With an interface it erases the one matching entry or returns E_FAIL; with none it collects the
 * iterators of every entry with that id in a vector<iterator>, then erases them. */
#include "compat/stlport_sn_oom.h"
#include <map>
#include <vector>
template <>Ptr32<_STL::_Rb_tree_node_base> _STL::_Rb_global<bool>::_M_increment(Ptr32<_STL::_Rb_tree_node_base>);
template <>Ptr32<_STL::_Rb_tree_node_base> _STL::_Rb_global<bool>::_Rebalance_for_erase(Ptr32<_STL::_Rb_tree_node_base>, Ptr32<_STL::_Rb_tree_node_base> &, Ptr32<_STL::_Rb_tree_node_base> &, Ptr32<_STL::_Rb_tree_node_base> &);
struct D31sMapIface {
    void w3d_r_query() __asm__(W3D_SYM("_ZN12D31sMapIface5queryEv"));
    void w3d_r_retain() __asm__(W3D_SYM("_ZN12D31sMapIface6retainEv"));
    void w3d_r_release() __asm__(W3D_SYM("_ZN12D31sMapIface7releaseEv"));
 __attribute__((always_inline)) inline void query() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D31sMapIface, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void retain() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D31sMapIface, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D31sMapIface, 4))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_D31sMapIface; };
struct D31sMapHeld {
    Ptr32<D31sMapIface> object;
    D31sMapHeld() : object(0) {}
    D31sMapHeld(const D31sMapHeld &o);
    ~D31sMapHeld() { if (object) object->release(); }
};
struct D31sMapKey {
    unsigned id;
    D31sMapHeld held;
};
struct D31sMapKeyLess {
    bool operator()(const D31sMapKey &a, const D31sMapKey &b) const;
 char w3d_empty; };
struct D31sMapValue {
    ~D31sMapValue();
 char w3d_empty; };
typedef _STL::map<D31sMapKey, D31sMapValue, D31sMapKeyLess> D31sKeyedMap;
struct D31sMapOwner {
    D31sKeyedMap::iterator find(Ptr32<D31sMapIface> held, unsigned id, D31sKeyedMap &map);
    int remove(Ptr32<D31sMapIface> held, unsigned id, D31sKeyedMap &map);
 char w3d_empty; };
int D31sMapOwner::remove(Ptr32<D31sMapIface> held, unsigned id, D31sKeyedMap &map) {
    if (held) {
        D31sKeyedMap::iterator it = find(held, id, map);
        D31sKeyedMap::iterator last = map.end();
        if (it != last) {
            map.erase(it);
            return 0;
        }
        return 0x80004005;
    }
    D31sKeyedMap::iterator i = map.begin();
    D31sKeyedMap::iterator last = map.end();
    _STL::vector<D31sKeyedMap::iterator> found;
    for (; i != last; ++i)
        if ((*i).first.id == id)
            found.push_back(i);
    for (_STL::vector<D31sKeyedMap::iterator>::iterator f = found.begin(); f != found.end(); ++f)
        map.erase(*f);
    return 0;
}


