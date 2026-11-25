/* GWMP8P rev0 0x801d2aac. Removes entries from a real STLport 4.5.3 map keyed by id and interface.
 * With an interface it erases the one matching entry or returns E_FAIL; with none it collects the
 * iterators of every entry with that id in a vector<iterator>, then erases them. */
#include "compat/stlport_sn_oom.h"
#include <map>
#include <vector>
template <> _STL::_Rb_tree_node_base *_STL::_Rb_global<bool>::_M_increment(_STL::_Rb_tree_node_base *);
template <> _STL::_Rb_tree_node_base *_STL::_Rb_global<bool>::_Rebalance_for_erase(_STL::_Rb_tree_node_base *, _STL::_Rb_tree_node_base *&, _STL::_Rb_tree_node_base *&, _STL::_Rb_tree_node_base *&);
struct D31sMapIface {
    virtual void query();
    virtual void retain();
    virtual void release();
};
struct D31sMapHeld {
    D31sMapIface *object;
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
};
struct D31sMapValue {
    ~D31sMapValue();
};
typedef _STL::map<D31sMapKey, D31sMapValue, D31sMapKeyLess> D31sKeyedMap;
struct D31sMapOwner {
    D31sKeyedMap::iterator find(D31sMapIface *held, unsigned id, D31sKeyedMap &map);
    int remove(D31sMapIface *held, unsigned id, D31sKeyedMap &map);
};
int D31sMapOwner::remove(D31sMapIface *held, unsigned id, D31sKeyedMap &map) {
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
