/* Service forwarding, argument ownership, and runtime teardown. */
typedef struct S3Service S3Service;
typedef struct S3ServiceVtable {
 void (*unused00[15])(void);
 int (*set_a)(S3Service *,unsigned char *),(*set_b)(S3Service *,unsigned char *);
 void (*unused44[9])(void);
 int (*query)(S3Service *),(*set_pair)(S3Service *,int,int);
 void (*unused70[7])(void);
 int (*lookup)(S3Service *,int);
} S3ServiceVtable;
struct S3Service {S3ServiceVtable *vtable;};
typedef struct S3Context {unsigned char pad00[116];S3Service *service;} S3Context;
typedef struct S3Basic {void *vtable;} S3Basic;
typedef struct S3Message {unsigned short id;} S3Message;
typedef struct S3Tail {const char **capacity;int spare;} S3Tail;
typedef struct S3Strings {const char **begin,**volatile end;S3Tail tail;} S3Strings;
typedef struct S3Arguments {S3Strings *store;} S3Arguments;
typedef struct S3Interface S3Interface;
typedef struct S3Vtable {void (*unused[3])(void);void (*retain)(S3Interface *),(*release)(S3Interface *);} S3Vtable;
struct S3Interface {S3Vtable *vtable;};
typedef struct S3Runtime {
 void *vtable;unsigned char pad04[48-4];S3Interface *held_a;void *owned;
 unsigned char pad38[68-56];S3Interface *held_b,*held_c;unsigned int flags;
} S3Runtime;
typedef struct S3RuntimeValue {S3Interface *held;unsigned int flags;} S3RuntimeValue;
extern S3Context *w3d_context_804b17ec;
extern S3Basic *w3d_service_804ab438;
extern void w3d_ctor_801628b0(S3Basic *),w3d_service_destroy_801628ec(S3Basic *,int);
extern void *w3d_vtable_80411028[],*w3d_vtable_804110e8[];
extern void w3d_fn_802cb01c(void);
extern int w3d_auto_8016293c(S3Basic *,S3Message *);
extern void w3d_auto_8015b1a8(S3Basic *);
extern void *w3d_heap_allocate_entry_a(unsigned int);
extern void w3d_string_base_finish(const char **),w3d_string_release(const char **),w3d_string_default(const char **),w3d_string_assign(const char **,const char *);
extern void w3d_handle_storage_release(void *),w3d_actor_member_delete_backend(void *);
extern void w3d_fn_80347570(S3Strings *,const char **,unsigned int,const char **);
extern void w3d_fn_8015d1ac(void *,int),w3d_fn_8015bedc(S3Runtime *,int);
extern S3RuntimeValue *w3d_runtime_value_804b1880;
static __inline__ void s3_release(S3Interface *object) {if(object) object->vtable->release(object);}

int w3d_runtime_service_lookup(int value) {S3Service *service=w3d_context_804b17ec->service;return service->vtable->lookup(service,value);}

int w3d_runtime_service_query(void) {S3Service *service=w3d_context_804b17ec->service;return service->vtable->query(service);}

int w3d_runtime_service_set_pair(int first,int second) {S3Service *service=w3d_context_804b17ec->service;return service->vtable->set_pair(service,first,second);}

int w3d_runtime_service_set_byte_a(unsigned char value) {S3Service *service=w3d_context_804b17ec->service;return service->vtable->set_a(service,&value);}

int w3d_runtime_service_set_byte_b(unsigned char value) {S3Service *service=w3d_context_804b17ec->service;return service->vtable->set_b(service,&value);}

S3Basic *w3d_runtime_singleton_construct(S3Basic *self) {w3d_ctor_801628b0(self);self->vtable=w3d_vtable_80411028;w3d_service_804ab438=self;return self;}

void w3d_runtime_singleton_destroy(S3Basic *self,int flags) {self->vtable=w3d_vtable_80411028;w3d_fn_802cb01c();w3d_service_804ab438=0;w3d_service_destroy_801628ec(self,flags);}

int w3d_runtime_singleton_dispatch(S3Basic *self,S3Message *message) {
 if(message->id==64) {
  if(w3d_auto_8016293c(self,message)>=0) {w3d_auto_8015b1a8(self);return 0;}
  return (int)0x80004005;
 }
 return w3d_auto_8016293c(self,message);
}

static __inline__ void s3_tail_clear(S3Tail *tail) {tail->spare=0;}
static __inline__ S3Arguments s3_arguments_wrap(S3Strings *store) {S3Arguments value;value.store=store;return value;}
S3Arguments *w3d_arguments_construct(S3Arguments *self) {
 struct {S3Arguments value;int unused;} local;
 S3Strings *store=(S3Strings *)w3d_heap_allocate_entry_a(16);
 store->begin=0;store->end=0;s3_tail_clear(&store->tail);
 local.value=s3_arguments_wrap(store);
 *self=local.value;return self;
}

void w3d_arguments_destroy(S3Arguments *self,int flags) {
 S3Strings *store=self->store;
 if(store) {
  const char **p,*const *end=store->end;
  for(p=store->begin;p!=end;p++) {w3d_string_base_finish(p);w3d_string_release(p);}
  if(store->begin) w3d_handle_storage_release(store->begin);
  w3d_actor_member_delete_backend(store);
 }
 if(flags&1) w3d_actor_member_delete_backend(self);
}

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

void w3d_runtime_destroy_owned_resources(S3Runtime *self) {
 self->vtable=w3d_vtable_804110e8;
 if(self->owned) w3d_fn_8015d1ac(self->owned,3);
 self->owned=0;
 if(self->flags&0x800000) {
  S3RuntimeValue *value=w3d_runtime_value_804b1880;
  if(value) {s3_release(value->held);w3d_actor_member_delete_backend(value);}
  w3d_runtime_value_804b1880=0;
 }
 s3_release(self->held_c);self->held_c=0;s3_release(self->held_b);s3_release(self->held_a);
 w3d_fn_8015bedc(self,0);
}
