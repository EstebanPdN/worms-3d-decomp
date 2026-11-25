/* A list of members, each holding a real STLport 4.5.3 set of its owners. Clearing the list
 * erases the owner from each member's target set and deletes the member. The class and slot
 * names are inferred; the set of unsigned keys comes from the cmplw compares and the admitted
 * tree members 0x80351ea0, 0x80351ef8 and 0x80352010. */
#ifndef D30S_MEMBER_LIST_H
#define D30S_MEMBER_LIST_H
#include "compat/stlport_sn_oom.h"
#include <list>
#include <set>
typedef std::set<unsigned> D30sOwnerSet;
typedef D30sOwnerSet::_Rep_type D30sOwnerTree;
template <> void D30sOwnerTree::_M_erase(_STL::_Rb_tree_node<unsigned> *);
template <> _STL::_Rb_tree_node_base *_STL::_Rb_global<bool>::_M_increment(_STL::_Rb_tree_node_base *);
template <> _STL::_Rb_tree_node_base *_STL::_Rb_global<bool>::_Rebalance_for_erase(_STL::_Rb_tree_node_base *, _STL::_Rb_tree_node_base *&, _STL::_Rb_tree_node_base *&, _STL::_Rb_tree_node_base *&);
extern "C" void w3d_actor_member_delete_backend(void *);
struct D30sUnknown { virtual void *get(); virtual int retain(); virtual int release(); };
template <class T> struct D30sHold {
    T *p;
    D30sHold(T *q) { p = q; p->retain(); }
    ~D30sHold() { p->release(); }
};
struct D30sTarget : D30sUnknown { D30sOwnerSet owners; };
struct D30sMember { virtual D30sTarget *target(); };
inline void d30s_unlink_owner(void *owner, D30sTarget *target) {
    unsigned key = (unsigned)owner;
    D30sHold<D30sTarget> hold(target);
    target->owners.erase(key);
}
struct D30sMemberList : D30sUnknown {
    std::list<D30sMember *> members;
    void clear_members() {
        D30sHold<D30sMemberList> guard(this);
        std::list<D30sMember *>::const_iterator it = members.begin();
        std::list<D30sMember *>::const_iterator e = members.end();
        for (; it != e; ++it) {
            d30s_unlink_owner(this, (*it)->target());
            w3d_actor_member_delete_backend(*it);
        }
        members.erase(members.begin(), members.end());
    }
};
#endif
