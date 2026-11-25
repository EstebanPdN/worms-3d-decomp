#include "w3d_ptr.h"
#line 1 "native_buffer_construction.cpp"
/* Reference-ABI reconstruction; inferred type and function names.
 * Complete original bodies are admitted only through explicit linked proofs.
 * This is not a portable native object model. Caller storage, virtual hooks,
 * request/base construction, and backend behavior remain external obligations.
 * The unsigned 32-bit counter preserves original modular PPC arithmetic.
 * Three shared0 names are reference-link aliases of one original storage cell;
 * they never define new storage or establish historical declarations.
 */
namespace w3d_reference_construction {
/* Exact complete recovered bodies; external request/base/backend dependencies remain unresolved.
 * Observed ABI prefixes; inferred names. Unknown subobjects remain bytes.
 * All backend calls are unresolved dependencies, never successful defaults. */
typedef unsigned int u32;
typedef unsigned short u16;
struct RequestView { volatile u32 state; u32 source,destination,backing,serial,extent; unsigned char backend[32]; };
struct BufferView { u32 base; u16 units,records; u32 state; RequestView request; u32 flags; };
struct ObjectView;
struct VTableView {
 Ptr32<void> reserved[3]; Ptr32<void (Ptr32<ObjectView>)> acquire; Ptr32<void (Ptr32<ObjectView>)> release;
 Ptr32<void> gap14; Ptr32<void (Ptr32<ObjectView>, Ptr32<void>, Ptr32<void (void)>, u32)> callback; Ptr32<void> gap1c[4];
 Ptr32<Ptr32<ObjectView> (Ptr32<ObjectView>)> get; Ptr32<void> gap30[2]; Ptr32<void (Ptr32<ObjectView>, u32)> set38;
 Ptr32<void (Ptr32<ObjectView>, Ptr32<void>)> set3c; Ptr32<void (Ptr32<ObjectView>, u32)> set40; Ptr32<void> gap44[3];
 Ptr32<void (Ptr32<ObjectView>, Ptr32<void>, u32)> set50;
};
struct ObjectView { Ptr32<VTableView> table; };
struct HookView { Ptr32<ObjectView> p;
 void assign(Ptr32<ObjectView> other) { if(other)other->table->acquire(other); if(p)p->table->release(p);p=other; }
};
struct StateView { unsigned char prefix[0x18]; u32 flags; u32 unknown1c; u32 unknown20; u16 request_flags; u16 unknown26; HookView a; u32 unknown2c; HookView b,c; RequestView request; u32 tail; };
inline void reset_request(Ptr32<volatile RequestView> q) {q->state=0;q->serial=~0u;q->extent=0;q->source=0;q->destination=0;q->backing=0;}
extern "C" {
extern u32 w3d_ref_buffer_mode;
extern Ptr32<StateView> w3d_original_801902e8(Ptr32<StateView>);
extern Ptr32<ObjectView> w3d_original_8020b680(Ptr32<void>);
extern void w3d_original_80210370(Ptr32<void>);
extern void w3d_original_8017ea68();
extern unsigned char w3d_ref_construction_desc0[],w3d_ref_construction_desc1[],w3d_ref_construction_desc2[],w3d_ref_construction_desc3[],w3d_ref_construction_desc5[],w3d_ref_construction_desc8[],w3d_ref_construction_desc9[],w3d_ref_construction_desc4[],w3d_ref_construction_desc7[],w3d_ref_construction_config_name[],w3d_ref_construction_config_data[],w3d_ref_construction_callback_data[];
extern u32 w3d_ref_buffer_state_instances;
extern HookView w3d_ref_construction_shared0_set40,w3d_ref_construction_shared0_set50;
extern HookView w3d_ref_construction_shared0,w3d_ref_construction_shared1,w3d_ref_construction_shared2,w3d_ref_construction_shared3,w3d_ref_construction_shared4,w3d_ref_construction_shared5,w3d_ref_construction_shared6,w3d_ref_construction_shared7,w3d_ref_construction_shared8,w3d_ref_construction_shared9;
extern VTableView w3d_ref_buffer_state_vtable;
extern void w3d_original_80190384(Ptr32<StateView>,u32);
extern void w3d_original_8019800c(Ptr32<BufferView>);
extern Ptr32<void> w3d_original_80343944();
extern void w3d_original_8020f660(Ptr32<void>,Ptr32<RequestView>);
extern void w3d_original_8020f35c(Ptr32<RequestView>,u32);
extern void w3d_original_801fe1f8(Ptr32<void>);
extern void w3d_original_8034cc0c(Ptr32<RequestView>);

Ptr32<BufferView> w3d_buffer_construct(Ptr32<BufferView> m) {
 w3d_original_8034cc0c(&m->request);
 m->base=0;m->units=0;m->flags &= 0x3fffffffu;m->records=0;m->state=0;w3d_ref_buffer_mode=0;return m;
}
void w3d_buffer_destroy(Ptr32<BufferView> m,u32 flags) {
 if(w3d_ref_buffer_mode==0) {w3d_original_8019800c(m);w3d_original_8020f660(w3d_original_80343944(),&m->request);}
 else {reset_request(&m->request);}
 w3d_original_8020f35c(&m->request,2);
 if(flags&1)w3d_original_801fe1f8(m);
}
u32 w3d_buffer_state_reset(Ptr32<StateView> s) {
 s->flags &= ~0x8000u;
 s->a.assign(0);s->b.assign(0);s->c.assign(0);
 if(s->request_flags&0x20)w3d_original_8020f660(w3d_original_80343944(),&s->request);
 return 0;
}
void w3d_buffer_state_destroy(Ptr32<StateView> s,u32 flags) {
 *(Ptr32<Ptr32<VTableView>>)s = &w3d_ref_buffer_state_vtable;
 s->a.assign(0);
 if(--w3d_ref_buffer_state_instances==0) {
 w3d_ref_construction_shared0.assign(0);w3d_ref_construction_shared1.assign(0);w3d_ref_construction_shared2.assign(0);w3d_ref_construction_shared3.assign(0);
 w3d_ref_construction_shared5.assign(0);w3d_ref_construction_shared6.assign(0);w3d_ref_construction_shared7.assign(0);w3d_ref_construction_shared8.assign(0);w3d_ref_construction_shared9.assign(0);w3d_ref_construction_shared4.assign(0);
 }
 w3d_original_8020f35c(&s->request,2);
 if(s->c.p)s->c.p->table->release(s->c.p);
 if(s->b.p)s->b.p->table->release(s->b.p);
 if(s->a.p)s->a.p->table->release(s->a.p);
 w3d_original_80190384(s,flags);
}

Ptr32<StateView> w3d_buffer_state_construct(Ptr32<StateView> s) {
 w3d_original_801902e8(s);
 s->a.p=0;s->b.p=0;s->c.p=0;
 *(Ptr32<Ptr32<VTableView>>)s=&w3d_ref_buffer_state_vtable;
 w3d_original_8034cc0c(&s->request);
 s->request_flags=0;
 if(w3d_ref_buffer_state_instances==0) {
 w3d_ref_construction_shared0.assign(w3d_original_8020b680(&w3d_ref_construction_desc0));w3d_ref_construction_shared1.assign(w3d_original_8020b680(&w3d_ref_construction_desc1));
 w3d_ref_construction_shared2.assign(w3d_original_8020b680(&w3d_ref_construction_desc2));w3d_ref_construction_shared3.assign(w3d_original_8020b680(&w3d_ref_construction_desc3));
 Ptr32<void> duplicate_descriptor=&w3d_ref_construction_desc5;
 w3d_ref_construction_shared5.assign(w3d_original_8020b680(duplicate_descriptor));w3d_ref_construction_shared6.assign(w3d_original_8020b680(duplicate_descriptor));
 w3d_ref_construction_shared8.assign(w3d_original_8020b680(&w3d_ref_construction_desc8));w3d_ref_construction_shared9.assign(w3d_original_8020b680(&w3d_ref_construction_desc9));
 w3d_ref_construction_shared4.assign(w3d_original_8020b680(&w3d_ref_construction_desc4));
 Ptr32<ObjectView> v=w3d_ref_construction_shared0_set40.p;v->table->set40(v,1);
 v=w3d_ref_construction_shared0_set50.p;v->table->set50(v,&w3d_ref_construction_config_name,5);
 v=w3d_ref_construction_shared3.p;v->table->set38(v,2);
 v=w3d_ref_construction_shared6.p;v->table->set3c(v,&w3d_ref_construction_config_data);
 w3d_original_80210370(&w3d_ref_construction_callback_data);
 Ptr32<ObjectView> p=w3d_original_8020b680(&w3d_ref_construction_desc7);w3d_ref_construction_shared7.assign(p);
 Ptr32<ObjectView> q=p->table->get(p);
 q->table->callback(q,&w3d_ref_construction_callback_data,w3d_original_8017ea68,0);
 }
 ++w3d_ref_buffer_state_instances;s->tail=0;return s;
}

}

typedef char Request_size_is_56[(sizeof(RequestView)==56)?1:-1];
typedef char Buffer_size_is_72[(sizeof(BufferView)==72)?1:-1];
typedef char State_size_is_116[(sizeof(StateView)==116)?1:-1];

} // namespace w3d_reference_construction


