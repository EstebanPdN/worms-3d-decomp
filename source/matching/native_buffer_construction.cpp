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
 void *reserved[3]; void (*acquire)(ObjectView *); void (*release)(ObjectView *);
 void *gap14; void (*callback)(ObjectView *,void *,void (*)(),u32); void *gap1c[4];
 ObjectView *(*get)(ObjectView *); void *gap30[2]; void (*set38)(ObjectView *,u32);
 void (*set3c)(ObjectView *,void *); void (*set40)(ObjectView *,u32); void *gap44[3];
 void (*set50)(ObjectView *,void *,u32);
};
struct ObjectView { VTableView *table; };
struct HookView { ObjectView *p;
 void assign(ObjectView *other) { if(other)other->table->acquire(other); if(p)p->table->release(p);p=other; }
};
struct StateView { unsigned char prefix[0x18]; u32 flags; u32 unknown1c; u32 unknown20; u16 request_flags; u16 unknown26; HookView a; u32 unknown2c; HookView b,c; RequestView request; u32 tail; };
inline void reset_request(volatile RequestView *q) {q->state=0;q->serial=~0u;q->extent=0;q->source=0;q->destination=0;q->backing=0;}
extern "C" {
extern u32 w3d_ref_buffer_mode;
extern StateView *w3d_original_801902e8(StateView *);
extern ObjectView *w3d_original_8020b680(void *);
extern void w3d_original_80210370(void *);
extern void w3d_original_8017ea68();
extern unsigned char w3d_ref_construction_desc0[],w3d_ref_construction_desc1[],w3d_ref_construction_desc2[],w3d_ref_construction_desc3[],w3d_ref_construction_desc5[],w3d_ref_construction_desc8[],w3d_ref_construction_desc9[],w3d_ref_construction_desc4[],w3d_ref_construction_desc7[],w3d_ref_construction_config_name[],w3d_ref_construction_config_data[],w3d_ref_construction_callback_data[];
extern u32 w3d_ref_buffer_state_instances;
extern HookView w3d_ref_construction_shared0_set40,w3d_ref_construction_shared0_set50;
extern HookView w3d_ref_construction_shared0,w3d_ref_construction_shared1,w3d_ref_construction_shared2,w3d_ref_construction_shared3,w3d_ref_construction_shared4,w3d_ref_construction_shared5,w3d_ref_construction_shared6,w3d_ref_construction_shared7,w3d_ref_construction_shared8,w3d_ref_construction_shared9;
extern VTableView w3d_ref_buffer_state_vtable;
extern void w3d_original_80190384(StateView *,u32);
extern void w3d_original_8019800c(BufferView *);
extern void *w3d_original_80343944();
extern void w3d_original_8020f660(void *,RequestView *);
extern void w3d_original_8020f35c(RequestView *,u32);
extern void w3d_original_801fe1f8(void *);
extern void w3d_original_8034cc0c(RequestView *);

BufferView *w3d_buffer_construct(BufferView *m) {
 w3d_original_8034cc0c(&m->request);
 m->base=0;m->units=0;m->flags &= 0x3fffffffu;m->records=0;m->state=0;w3d_ref_buffer_mode=0;return m;
}
void w3d_buffer_destroy(BufferView *m,u32 flags) {
 if(w3d_ref_buffer_mode==0) {w3d_original_8019800c(m);w3d_original_8020f660(w3d_original_80343944(),&m->request);}
 else {reset_request(&m->request);}
 w3d_original_8020f35c(&m->request,2);
 if(flags&1)w3d_original_801fe1f8(m);
}
u32 w3d_buffer_state_reset(StateView *s) {
 s->flags &= ~0x8000u;
 s->a.assign(0);s->b.assign(0);s->c.assign(0);
 if(s->request_flags&0x20)w3d_original_8020f660(w3d_original_80343944(),&s->request);
 return 0;
}
void w3d_buffer_state_destroy(StateView *s,u32 flags) {
 *(VTableView **)s = &w3d_ref_buffer_state_vtable;
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

StateView *w3d_buffer_state_construct(StateView *s) {
 w3d_original_801902e8(s);
 s->a.p=0;s->b.p=0;s->c.p=0;
 *(VTableView **)s=&w3d_ref_buffer_state_vtable;
 w3d_original_8034cc0c(&s->request);
 s->request_flags=0;
 if(w3d_ref_buffer_state_instances==0) {
 w3d_ref_construction_shared0.assign(w3d_original_8020b680(&w3d_ref_construction_desc0));w3d_ref_construction_shared1.assign(w3d_original_8020b680(&w3d_ref_construction_desc1));
 w3d_ref_construction_shared2.assign(w3d_original_8020b680(&w3d_ref_construction_desc2));w3d_ref_construction_shared3.assign(w3d_original_8020b680(&w3d_ref_construction_desc3));
 void *duplicate_descriptor=&w3d_ref_construction_desc5;
 w3d_ref_construction_shared5.assign(w3d_original_8020b680(duplicate_descriptor));w3d_ref_construction_shared6.assign(w3d_original_8020b680(duplicate_descriptor));
 w3d_ref_construction_shared8.assign(w3d_original_8020b680(&w3d_ref_construction_desc8));w3d_ref_construction_shared9.assign(w3d_original_8020b680(&w3d_ref_construction_desc9));
 w3d_ref_construction_shared4.assign(w3d_original_8020b680(&w3d_ref_construction_desc4));
 ObjectView *v=w3d_ref_construction_shared0_set40.p;v->table->set40(v,1);
 v=w3d_ref_construction_shared0_set50.p;v->table->set50(v,&w3d_ref_construction_config_name,5);
 v=w3d_ref_construction_shared3.p;v->table->set38(v,2);
 v=w3d_ref_construction_shared6.p;v->table->set3c(v,&w3d_ref_construction_config_data);
 w3d_original_80210370(&w3d_ref_construction_callback_data);
 ObjectView *p=w3d_original_8020b680(&w3d_ref_construction_desc7);w3d_ref_construction_shared7.assign(p);
 ObjectView *q=p->table->get(p);
 q->table->callback(q,&w3d_ref_construction_callback_data,w3d_original_8017ea68,0);
 }
 ++w3d_ref_buffer_state_instances;s->tail=0;return s;
}

}

typedef char Request_size_is_56[(sizeof(RequestView)==56)?1:-1];
typedef char Buffer_size_is_72[(sizeof(BufferView)==72)?1:-1];
typedef char State_size_is_116[(sizeof(StateView)==116)?1:-1];

} // namespace w3d_reference_construction
