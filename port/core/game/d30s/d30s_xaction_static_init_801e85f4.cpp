#include "w3d_ptr.h"
#line 1 "d30s_xaction_static_init_801e85f4.cpp"
/* GWMP8P rev0 0x801e85f4. Static initializer of the "XAction" unit: constructs the receiver at
 * 0x8045e010 and connects it to the second signal of 0x801ea954 with a pointer to member, then
 * registers the type node at 0x8045e030 and the class at 0x803ea088. Class and field names are
 * inferred. The three-argument construct-at-address stands in for a file-scope object definition. */
#include "game/d30s/d30s_member_list.h"
#pragma interface
extern "C" Ptr32<void> w3d_heap_allocate_entry_a(unsigned);
inline void *operator new(__SIZE_TYPE__, void *p, int) { return p; }
struct D30sXactionRecvBase : D30sUnknown { D30sOwnerSet owners __attribute__((aligned(__alignof__(D30sUnknown)))); D30sXactionRecvBase() { W3D_SET_VPTR(this->D30sUnknown::w3d_vptr_D30sUnknown, w3d_vt___vt_19D30sXactionRecvBase, "__vt_19D30sXactionRecvBase"); } };
struct D30sXactionRecv : D30sXactionRecvBase { D30sXactionRecv() { W3D_SET_VPTR(this->D30sXactionRecvBase::w3d_vptr_D30sUnknown, w3d_vt___vt_15D30sXactionRecv, "__vt_15D30sXactionRecv"); } Ptr32<void> w3d_r_get() __asm__(W3D_SYM("_ZN15D30sXactionRecv3getEv")); void on_event(Ptr32<void>);  __attribute__((always_inline)) inline Ptr32<void> get() { return this->D30sXactionRecvBase::get(); } };
typedef w3d::Pmf<D30sXactionRecv, void(Ptr32<void>)> D30sXactionMethod;
struct D30sXactionSlot : D30sMember {
    Ptr32<D30sXactionRecv> target_ __attribute__((aligned(__alignof__(D30sMember))));
    D30sXactionMethod pmf;
    D30sXactionSlot(Ptr32<D30sXactionRecv> r, D30sXactionMethod p) : target_(r), pmf(p) { W3D_SET_VPTR(this->D30sMember::w3d_vptr_D30sMember, w3d_vt___vt_15D30sXactionSlot, "__vt_15D30sXactionSlot"); }
    Ptr32<D30sTarget> w3d_r_target() __asm__(W3D_SYM("_ZN15D30sXactionSlot6targetEv"));
    void *operator new(__SIZE_TYPE__ n) { return w3d_heap_allocate_entry_a(n); }
 __attribute__((always_inline)) inline Ptr32<D30sTarget> target() { return this->D30sMember::target(); } };
struct D30sXactionSignals { D30sMemberList first, second; };
extern "C" Ptr32<D30sXactionSignals> w3d_local_static_801ea954();
struct D30sXactionHold {
    Ptr32<D30sMemberList> list;
    Ptr32<D30sMember> member;
    template <class W3dU> D30sXactionHold(Ptr32<W3dU> w3d_p) : D30sXactionHold((D30sMemberList *)w3d_p.get()) {}
 D30sXactionHold(D30sMemberList *l) { list = l; l->retain(); }
    ~D30sXactionHold() { list->release(); }
};
inline void d30s_xaction_connect(Ptr32<D30sMemberList> l, Ptr32<D30sXactionRecv> r, D30sXactionMethod p) {
    D30sXactionHold c(l);
    c.member = new D30sXactionSlot(r, p);
    _STL::list <Ptr32<D30sMember> >::iterator it = l->members.insert(l->members.end(), c.member);
    unsigned key = (unsigned)w3d::H(l);
    D30sHold<D30sXactionRecvBase> h(r);
    r->owners.insert(key);
}
struct D30sXactionReceiver : D30sXactionRecv { D30sXactionReceiver() { W3D_SET_VPTR(this->D30sXactionRecv::w3d_vptr_D30sUnknown, w3d_vt___vt_19D30sXactionReceiver, "__vt_19D30sXactionReceiver");  d30s_xaction_connect(&w3d_local_static_801ea954()->second, this, &D30sXactionRecv::on_event); } };
extern D30sXactionRecv recv_8045e010;
struct D30sXactionTriple { Ptr32<void> a; Ptr32<void> b; Ptr32<void> c; };
extern D30sXactionTriple three_8045e024;
struct D30sXactionType { Ptr32<void> u0; Ptr32<const char> name; Ptr32<void> u8; Ptr32<void (void)> init; int kind; Ptr32<void> data; };
extern D30sXactionType type_8045e030;
extern const char name_803b0998[];
extern char data_8045e124[];
extern "C" int w3d_d24e_free_registry_801e8128();
extern "C" void w3d_s21_insert_sorted_80200af8(Ptr32<D30sXactionType>);
extern const char tag_8036573c[];
extern const char tag_803ea088[];
extern "C" Ptr32<void> fn_801e8330();
extern "C" int fn_801e74d0(Ptr32<void>);
extern "C" Ptr32<void> w3d_s21_construct_801e7174(Ptr32<const void>, Ptr32<const void>, Ptr32<const void>, Ptr32<void (void)>, int, Ptr32<void (void)>);
extern "C" void d30s_xaction_static_init_801e85f4(int initialize, int priority) {
    if (priority == 0xffff && initialize) {
        new ((Ptr32<void>)&recv_8045e010, 0) D30sXactionReceiver;
        three_8045e024.c = 0;
        three_8045e024.b = 0;
        three_8045e024.a = 0;
        type_8045e030.name = name_803b0998;
        type_8045e030.u8 = 0;
        type_8045e030.init = (Ptr32<void (void)>)w3d_d24e_free_registry_801e8128;
        type_8045e030.kind = 10;
        type_8045e030.data = data_8045e124;
        w3d_s21_insert_sorted_80200af8(&type_8045e030);
        w3d_s21_construct_801e7174(tag_8036573c, tag_803ea088, tag_8036573c, (Ptr32<void (void)>)fn_801e8330, 1, (Ptr32<void (void)>)fn_801e74d0);
    }
}


