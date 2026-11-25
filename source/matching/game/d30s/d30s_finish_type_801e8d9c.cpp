/* GWMP8P rev0 0x801e8d9c. On first use constructs the static receiver at 0x8045e06c, connects it
 * to the signal from 0x80210610 with a pointer to member, registers its destructor at 0x801e8d70,
 * then registers the type and collects its members. The signal, connection and member classes
 * are inferred. The three-argument construct-at-address stands in for the original's static local
 * definition, whose guard and object live at fixed addresses. */
#include "game/d30s/d30s_member_list.h"
#pragma interface
extern "C" void *w3d_heap_allocate_entry_a(unsigned);
extern "C" int atexit(void (*)());
extern "C" int w3d_d28e_register_type_801e90fc(void *);
extern "C" void w3d_cc17c_collect_members_801e9c2c(void *);
inline void *operator new(unsigned, void *p, int) { return p; }

struct D30sFinishRecv; typedef void (D30sFinishRecv::*D30sFinishMethod)(void *);
struct D30sRecvBase : D30sUnknown { D30sOwnerSet owners; D30sRecvBase() {} };
struct D30sFinishRecv : D30sRecvBase { D30sFinishRecv() {} virtual void *get(); void on_event(void *); };
struct D30sFinishSlot : D30sMember {
    D30sFinishRecv *target_;
    D30sFinishMethod pmf;
    D30sFinishSlot(D30sFinishRecv *r, D30sFinishMethod p) : target_(r), pmf(p) {}
    virtual D30sTarget *target();
    void *operator new(unsigned n) { return w3d_heap_allocate_entry_a(n); }
};
extern "C" D30sMemberList *w3d_local_static_80210610();
struct D30sConnectHold {
    D30sMemberList *list;
    D30sMember *member;
    D30sConnectHold(D30sMemberList *l) { list = l; l->retain(); }
    ~D30sConnectHold() { list->release(); }
};
inline void d30s_finish_connect(D30sMemberList *l, D30sFinishRecv *r, D30sFinishMethod p) {
    D30sConnectHold c(l);
    c.member = new D30sFinishSlot(r, p);
    std::list<D30sMember *>::iterator it = l->members.insert(l->members.end(), c.member);
    unsigned key = (unsigned)l;
    D30sHold<D30sRecvBase> h(r);
    r->owners.insert(key);
}
struct D30sFinishReceiver : D30sFinishRecv { D30sFinishReceiver() { d30s_finish_connect(w3d_local_static_80210610(), this, &D30sFinishRecv::on_event); } };
extern D30sFinishRecv d30s_receiver_8045e06c;
extern int d30s_receiver_guard_804b057c;
extern "C" void w3d_d30s_receiver_dtor_801e8d70();
extern "C" void d30s_finish_type_801e8d9c(void *x) {
    if (!d30s_receiver_guard_804b057c) {
        new ((void *)&d30s_receiver_8045e06c, 0) D30sFinishReceiver;
        d30s_receiver_guard_804b057c = 1;
        atexit(w3d_d30s_receiver_dtor_801e8d70);
    }
    w3d_d28e_register_type_801e90fc(x);
    w3d_cc17c_collect_members_801e9c2c(x);
}
