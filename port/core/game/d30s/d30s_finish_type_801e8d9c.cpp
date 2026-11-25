#include "w3d_ptr.h"
#line 1 "d30s_finish_type_801e8d9c.cpp"
/* GWMP8P rev0 0x801e8d9c. On first use constructs the static receiver at 0x8045e06c, connects it
 * to the signal from 0x80210610 with a pointer to member, registers its destructor at 0x801e8d70,
 * then registers the type and collects its members. The signal, connection and member classes
 * are inferred. The three-argument construct-at-address stands in for the original's static local
 * definition, whose guard and object live at fixed addresses. */
#include "game/d30s/d30s_member_list.h"
#pragma interface
extern "C" Ptr32<void> w3d_heap_allocate_entry_a(unsigned);
extern "C" int atexit(Ptr32<void (void)>);
extern "C" int w3d_d28e_register_type_801e90fc(Ptr32<void>);
extern "C" void w3d_cc17c_collect_members_801e9c2c(Ptr32<void>);
inline void *operator new(__SIZE_TYPE__, void *p, int) { return p; }

struct D30sFinishRecv; typedef w3d::Pmf<D30sFinishRecv, void(Ptr32<void>)> D30sFinishMethod;
struct D30sRecvBase : D30sUnknown { D30sOwnerSet owners __attribute__((aligned(__alignof__(D30sUnknown)))); D30sRecvBase() { W3D_SET_VPTR(this->D30sUnknown::w3d_vptr_D30sUnknown, w3d_vt___vt_12D30sRecvBase, "__vt_12D30sRecvBase"); } };
struct D30sFinishRecv : D30sRecvBase { D30sFinishRecv() { W3D_SET_VPTR(this->D30sRecvBase::w3d_vptr_D30sUnknown, w3d_vt___vt_14D30sFinishRecv, "__vt_14D30sFinishRecv"); } Ptr32<void> w3d_r_get() __asm__(W3D_SYM("_ZN14D30sFinishRecv3getEv")); void on_event(Ptr32<void>);  __attribute__((always_inline)) inline Ptr32<void> get() { return this->D30sRecvBase::get(); } };
struct D30sFinishSlot : D30sMember {
    Ptr32<D30sFinishRecv> target_ __attribute__((aligned(__alignof__(D30sMember))));
    D30sFinishMethod pmf;
    D30sFinishSlot(Ptr32<D30sFinishRecv> r, D30sFinishMethod p) : target_(r), pmf(p) { W3D_SET_VPTR(this->D30sMember::w3d_vptr_D30sMember, w3d_vt___vt_14D30sFinishSlot, "__vt_14D30sFinishSlot"); }
    Ptr32<D30sTarget> w3d_r_target() __asm__(W3D_SYM("_ZN14D30sFinishSlot6targetEv"));
    void *operator new(__SIZE_TYPE__ n) { return w3d_heap_allocate_entry_a(n); }
 __attribute__((always_inline)) inline Ptr32<D30sTarget> target() { return this->D30sMember::target(); } };
extern "C" Ptr32<D30sMemberList> w3d_local_static_80210610();
struct D30sConnectHold {
    Ptr32<D30sMemberList> list;
    Ptr32<D30sMember> member;
    template <class W3dU> D30sConnectHold(Ptr32<W3dU> w3d_p) : D30sConnectHold((D30sMemberList *)w3d_p.get()) {}
 D30sConnectHold(D30sMemberList *l) { list = l; l->retain(); }
    ~D30sConnectHold() { list->release(); }
};
inline void d30s_finish_connect(Ptr32<D30sMemberList> l, Ptr32<D30sFinishRecv> r, D30sFinishMethod p) {
    D30sConnectHold c(l);
    c.member = new D30sFinishSlot(r, p);
    _STL::list <Ptr32<D30sMember> >::iterator it = l->members.insert(l->members.end(), c.member);
    unsigned key = (unsigned)w3d::H(l);
    D30sHold<D30sRecvBase> h(r);
    r->owners.insert(key);
}
struct D30sFinishReceiver : D30sFinishRecv { D30sFinishReceiver() { W3D_SET_VPTR(this->D30sFinishRecv::w3d_vptr_D30sUnknown, w3d_vt___vt_18D30sFinishReceiver, "__vt_18D30sFinishReceiver");  d30s_finish_connect(w3d_local_static_80210610(), this, &D30sFinishRecv::on_event); } };
extern D30sFinishRecv d30s_receiver_8045e06c;
extern int d30s_receiver_guard_804b057c;
extern "C" void w3d_d30s_receiver_dtor_801e8d70();
extern "C" void d30s_finish_type_801e8d9c(Ptr32<void> x) {
    if (!d30s_receiver_guard_804b057c) {
        new ((Ptr32<void>)&d30s_receiver_8045e06c, 0) D30sFinishReceiver;
        d30s_receiver_guard_804b057c = 1;
        atexit(w3d_d30s_receiver_dtor_801e8d70);
    }
    w3d_d28e_register_type_801e90fc(x);
    w3d_cc17c_collect_members_801e9c2c(x);
}


