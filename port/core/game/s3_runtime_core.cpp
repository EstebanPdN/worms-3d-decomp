#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s3_runtime_core.c"
/* Service forwarding, argument ownership, and runtime teardown. */
typedef struct S3Service S3Service;
typedef struct S3ServiceVtable {
 Ptr32<void (void)> unused00[15];
 Ptr32<int (Ptr32<S3Service>, Ptr32<unsigned char>)> set_a; Ptr32<int (Ptr32<S3Service>, Ptr32<unsigned char>)> set_b;
 Ptr32<void (void)> unused44[9];
 Ptr32<int (Ptr32<S3Service>)> query; Ptr32<int (Ptr32<S3Service>, int, int)> set_pair;
 Ptr32<void (void)> unused70[7];
 Ptr32<int (Ptr32<S3Service>, int)> lookup;
} S3ServiceVtable;
struct S3Service {Ptr32<S3ServiceVtable> vtable;};
typedef struct S3Context {unsigned char pad00[116];Ptr32<S3Service> service;} S3Context;
typedef struct S3Basic {Ptr32<void> vtable;} S3Basic;
typedef struct S3Message {unsigned short id;} S3Message;
typedef struct S3Tail {Ptr32<Ptr32<const char>> capacity;int spare;} S3Tail;
typedef struct S3Strings {Ptr32<Ptr32<const char>> begin; Ptr32<Ptr32<const char>> end;S3Tail tail;} S3Strings;
typedef struct S3Arguments {Ptr32<S3Strings> store;} S3Arguments;
typedef struct S3Interface S3Interface;
typedef struct S3Vtable {Ptr32<void (void)> unused[3];Ptr32<void (Ptr32<S3Interface>)> retain; Ptr32<void (Ptr32<S3Interface>)> release;} S3Vtable;
struct S3Interface {Ptr32<S3Vtable> vtable;};
typedef struct S3Runtime {
 Ptr32<void> vtable;unsigned char pad04[48-4];Ptr32<S3Interface> held_a;Ptr32<void> owned;
 unsigned char pad38[68-56];Ptr32<S3Interface> held_b; Ptr32<S3Interface> held_c;unsigned int flags;
} S3Runtime;
typedef struct S3RuntimeValue {Ptr32<S3Interface> held;unsigned int flags;} S3RuntimeValue;
extern Ptr32<S3Context> w3d_context_804b17ec;
extern Ptr32<S3Basic> w3d_service_804ab438;
extern void w3d_service_destroy_801628ec(Ptr32<S3Basic>,int);
extern int w3d_ctor_801628b0(Ptr32<S3Basic>);
extern Ptr32<void> w3d_vtable_80411028[]; extern Ptr32<void> w3d_vtable_804110e8[];
extern void w3d_fn_802cb01c(void);
extern int w3d_auto_8016293c(Ptr32<S3Basic>,Ptr32<S3Message>);
extern void w3d_auto_8015b1a8(Ptr32<S3Basic>);
extern Ptr32<void> w3d_heap_allocate_entry_a(unsigned int);
extern void w3d_string_base_finish(Ptr32<Ptr32<const char>>),w3d_string_release(Ptr32<Ptr32<const char>>),w3d_string_default(Ptr32<Ptr32<const char>>),w3d_string_assign(Ptr32<Ptr32<const char>>,Ptr32<const char>);
extern void w3d_handle_storage_release(Ptr32<void>),w3d_actor_member_delete_backend(Ptr32<void>);
extern void w3d_fn_80347570(Ptr32<S3Strings>,Ptr32<Ptr32<const char>>,unsigned int,Ptr32<Ptr32<const char>>);
extern void w3d_fn_8015d1ac(Ptr32<void>,int),w3d_fn_8015bedc(Ptr32<S3Runtime>,int);
extern Ptr32<S3RuntimeValue> w3d_runtime_value_804b1880;
static __inline__ void s3_release(Ptr32<S3Interface> object) {if(object) object->vtable->release(object);}

int w3d_runtime_service_lookup(int value) {Ptr32<S3Service> service=w3d_context_804b17ec->service;return service->vtable->lookup(service,value);}

int w3d_runtime_service_query(void) {Ptr32<S3Service> service=w3d_context_804b17ec->service;return service->vtable->query(service);}

int w3d_runtime_service_set_pair(int first,int second) {Ptr32<S3Service> service=w3d_context_804b17ec->service;return service->vtable->set_pair(service,first,second);}

int w3d_runtime_service_set_byte_a(unsigned char value) {Ptr32<S3Service> service=w3d_context_804b17ec->service;return service->vtable->set_a(service,&value);}

int w3d_runtime_service_set_byte_b(unsigned char value) {Ptr32<S3Service> service=w3d_context_804b17ec->service;return service->vtable->set_b(service,&value);}

Ptr32<S3Basic> w3d_runtime_singleton_construct(Ptr32<S3Basic> self) {w3d_ctor_801628b0(self);self->vtable=w3d_vtable_80411028;w3d_service_804ab438=self;return self;}

void w3d_runtime_singleton_destroy(Ptr32<S3Basic> self,int flags) {self->vtable=w3d_vtable_80411028;w3d_fn_802cb01c();w3d_service_804ab438=0;w3d_service_destroy_801628ec(self,flags);}

int w3d_runtime_singleton_dispatch(Ptr32<S3Basic> self,Ptr32<S3Message> message) {
 if(message->id==64) {
  if(w3d_auto_8016293c(self,message)>=0) {w3d_auto_8015b1a8(self);return 0;}
  return (int)0x80004005;
 }
 return w3d_auto_8016293c(self,message);
}

static __inline__ void s3_tail_clear(Ptr32<S3Tail> tail) {tail->spare=0;}
static __inline__ S3Arguments s3_arguments_wrap(Ptr32<S3Strings> store) {S3Arguments value;value.store=store;return value;}
#if 0 /* 0x8015b254: eight-byte stack gap differs after three revisions. */
S3Arguments *w3d_arguments_construct(S3Arguments *self) {
 struct {S3Arguments value;int unused;} local;
 S3Strings *store=(S3Strings *)w3d_heap_allocate_entry_a(16);
 store->begin=0;store->end=0;s3_tail_clear(&store->tail);
 local.value=s3_arguments_wrap(store);
 *self=local.value;return self;
}
#endif

void w3d_arguments_destroy(Ptr32<S3Arguments> self,int flags) {
 Ptr32<S3Strings> store=self->store;
 if(store) {
  Ptr32<Ptr32<const char>> p; Ptr32<Ptr32<const char> const> end=store->end;
  for(p=store->begin;p!=end;p++) {w3d_string_base_finish(p);w3d_string_release(p);}
  if(store->begin) w3d_handle_storage_release(store->begin);
  w3d_actor_member_delete_backend(store);
 }
 if(flags&1) w3d_actor_member_delete_backend(self);
}

#if 0 /* 0x8015b330: condition-register preservation and loop scheduling differ after two revisions. */
int w3d_arguments_assign_vector(S3Arguments *self,int count,const char **values) {
 S3Strings *store=self->store;const char *empty;
 w3d_string_default(&empty);
 if((unsigned int)count<(unsigned int)(store->end-store->begin)) {
  const char **new_end=store->begin+count,**p,*const *end=store->end;
  for(p=new_end;p!=end;p++) {w3d_string_base_finish(p);w3d_string_release(p);}
  store->end=new_end;
 } else w3d_fn_80347570(store,store->end,count-(store->end-store->begin),&empty);
 w3d_string_base_finish(&empty);w3d_string_release(&empty);
 if(count>0) {int remaining=count;unsigned int i=0;do {w3d_string_assign(&store->begin[i],values[i]);i++;} while(--remaining);}
 return 0;
}
#endif

void w3d_runtime_destroy_owned_resources(Ptr32<S3Runtime> self) {
 self->vtable=w3d_vtable_804110e8;
 if(self->owned) w3d_fn_8015d1ac(self->owned,3);
 self->owned=0;
 if(self->flags&0x800000) {
  Ptr32<S3RuntimeValue> value=w3d_runtime_value_804b1880;
  if(value) {s3_release(value->held);w3d_actor_member_delete_backend(value);}
  w3d_runtime_value_804b1880=0;
 }
 s3_release(self->held_c);self->held_c=0;s3_release(self->held_b);s3_release(self->held_a);
 w3d_fn_8015bedc(self,0);
}

}
