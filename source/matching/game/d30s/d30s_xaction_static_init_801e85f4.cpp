/* GWMP8P rev0 0x801e85f4. Static initializer of the "XAction" unit: constructs the receiver at
 * 0x8045e010 and connects it to the second signal of 0x801ea954 with a pointer to member, then
 * registers the type node at 0x8045e030 and the class at 0x803ea088. Class and field names are
 * inferred. The three-argument construct-at-address stands in for a file-scope object definition. */
#include "game/d30s/d30s_member_list.h"
#pragma interface
extern "C" void *w3d_heap_allocate_entry_a(unsigned);
inline void *operator new(unsigned, void *p, int) { return p; }
struct D30sXactionRecvBase : D30sUnknown { D30sOwnerSet owners; D30sXactionRecvBase() {} };
struct D30sXactionRecv : D30sXactionRecvBase { D30sXactionRecv() {} virtual void *get(); void on_event(void *); };
typedef void (D30sXactionRecv::*D30sXactionMethod)(void *);
struct D30sXactionSlot : D30sMember {
    D30sXactionRecv *target_;
    D30sXactionMethod pmf;
    D30sXactionSlot(D30sXactionRecv *r, D30sXactionMethod p) : target_(r), pmf(p) {}
    virtual D30sTarget *target();
    void *operator new(unsigned n) { return w3d_heap_allocate_entry_a(n); }
};
struct D30sXactionSignals { D30sMemberList first, second; };
extern "C" D30sXactionSignals *w3d_local_static_801ea954();
struct D30sXactionHold {
    D30sMemberList *list;
    D30sMember *member;
    D30sXactionHold(D30sMemberList *l) { list = l; l->retain(); }
    ~D30sXactionHold() { list->release(); }
};
inline void d30s_xaction_connect(D30sMemberList *l, D30sXactionRecv *r, D30sXactionMethod p) {
    D30sXactionHold c(l);
    c.member = new D30sXactionSlot(r, p);
    std::list<D30sMember *>::iterator it = l->members.insert(l->members.end(), c.member);
    unsigned key = (unsigned)l;
    D30sHold<D30sXactionRecvBase> h(r);
    r->owners.insert(key);
}
struct D30sXactionReceiver : D30sXactionRecv { D30sXactionReceiver() { d30s_xaction_connect(&w3d_local_static_801ea954()->second, this, &D30sXactionRecv::on_event); } };
extern D30sXactionRecv recv_8045e010;
struct D30sXactionTriple { void *a, *b, *c; };
extern D30sXactionTriple three_8045e024;
struct D30sXactionType { void *u0; const char *name; void *u8; void (*init)(); int kind; void *data; };
extern D30sXactionType type_8045e030;
extern const char name_803b0998[];
extern char data_8045e124[];
extern "C" int w3d_d24e_free_registry_801e8128();
extern "C" void w3d_s21_insert_sorted_80200af8(D30sXactionType *);
extern const char tag_8036573c[];
extern const char tag_803ea088[];
extern "C" void * fn_801e8330();
extern "C" int fn_801e74d0(void *);
extern "C" void * w3d_s21_construct_801e7174(const void *, const void *, const void *, void (*)(), int, void (*)());
extern "C" void d30s_xaction_static_init_801e85f4(int initialize, int priority) {
    if (priority == 0xffff && initialize) {
        new ((void *)&recv_8045e010, 0) D30sXactionReceiver;
        three_8045e024.c = 0;
        three_8045e024.b = 0;
        three_8045e024.a = 0;
        type_8045e030.name = name_803b0998;
        type_8045e030.u8 = 0;
        type_8045e030.init = (void (*)())w3d_d24e_free_registry_801e8128;
        type_8045e030.kind = 10;
        type_8045e030.data = data_8045e124;
        w3d_s21_insert_sorted_80200af8(&type_8045e030);
        w3d_s21_construct_801e7174(tag_8036573c, tag_803ea088, tag_8036573c, (void (*)())fn_801e8330, 1, (void (*)())fn_801e74d0);
    }
}
