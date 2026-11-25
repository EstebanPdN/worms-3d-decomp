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
template <> void D30sOwnerTree::_M_erase(Ptr32<_STL::_Rb_tree_node < unsigned int >>);
template <>Ptr32<_STL::_Rb_tree_node_base> _STL::_Rb_global<bool>::_M_increment(Ptr32<_STL::_Rb_tree_node_base>);
template <>Ptr32<_STL::_Rb_tree_node_base> _STL::_Rb_global<bool>::_Rebalance_for_erase(Ptr32<_STL::_Rb_tree_node_base>, Ptr32<_STL::_Rb_tree_node_base> &, Ptr32<_STL::_Rb_tree_node_base> &, Ptr32<_STL::_Rb_tree_node_base> &);
extern "C" void w3d_actor_member_delete_backend(Ptr32<void>);
struct D30sUnknown { Ptr32<void> w3d_r_get() __asm__(W3D_SYM("_ZN11D30sUnknown3getEv")); int w3d_r_retain() __asm__(W3D_SYM("_ZN11D30sUnknown6retainEv")); int w3d_r_release() __asm__(W3D_SYM("_ZN11D30sUnknown7releaseEv"));  __attribute__((always_inline)) inline Ptr32<void> get() { return ((Ptr32<void> (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D30sUnknown, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int retain() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D30sUnknown, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int release() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D30sUnknown, 4))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_D30sUnknown;  D30sUnknown() { W3D_SET_VPTR(this->w3d_vptr_D30sUnknown, w3d_vt___vt_11D30sUnknown, "__vt_11D30sUnknown"); } };
template <class T> struct D30sHold {
    Ptr32<T> p;
    template <class W3dU> D30sHold<T>(Ptr32<W3dU> w3d_p) : D30sHold<T>((T *)w3d_p.get()) {}
 D30sHold(T *q) { p = q; p->retain(); }
    ~D30sHold() { p->release(); }
};
struct D30sTarget : D30sUnknown { D30sOwnerSet owners __attribute__((aligned(__alignof__(D30sUnknown)))); };
struct D30sMember { Ptr32<D30sTarget> w3d_r_target() __asm__(W3D_SYM("_ZN10D30sMember6targetEv"));  __attribute__((always_inline)) inline Ptr32<D30sTarget> target() { return ((Ptr32<D30sTarget> (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D30sMember, 2))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_D30sMember;  D30sMember() { W3D_SET_VPTR(this->w3d_vptr_D30sMember, w3d_vt___vt_10D30sMember, "__vt_10D30sMember"); } };
inline void d30s_unlink_owner(Ptr32<void> owner, Ptr32<D30sTarget> target) {
    unsigned key = (unsigned)w3d::H(owner);
    D30sHold<D30sTarget> hold(target);
    target->owners.erase(key);
}
struct D30sMemberList : D30sUnknown {
    _STL::list <Ptr32<D30sMember> > members;
    void clear_members() {
        D30sHold<D30sMemberList> guard(this);
        _STL::list <Ptr32<D30sMember> >::const_iterator it = members.begin();
        _STL::list <Ptr32<D30sMember> >::const_iterator e = members.end();
        for (; it != e; ++it) {
            d30s_unlink_owner(this, (*it)->target());
            w3d_actor_member_delete_backend(*it);
        }
        members.erase(members.begin(), members.end());
    }
};
#endif
