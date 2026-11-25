// Partial native views. The pool stride is witnessed by mulli 24, not inferred
// from a stack frame. Indirect callback return types are unknown except bind's
// signed status result; reference callback results are discarded.
struct cc44a_Binding;
struct cc44a_BindingVtable { unsigned int unknown[3]; void (*retain)(cc44a_Binding *); void (*release)(cc44a_Binding *); };
struct cc44a_Binding {
 cc44a_BindingVtable *vtable;
 unsigned int value;
 unsigned short group;
 unsigned short unknown10;
 unsigned int state;
 unsigned int context;
 unsigned int unknown20;
};
struct cc44a_Group;
struct cc44a_GroupVtable { unsigned int unknown[14]; int (*bind)(cc44a_Group *, cc44a_Binding *); };
struct cc44a_Group { cc44a_GroupVtable *vtable; };
struct cc44a_FreeIndices { unsigned int *begin,*end; };
struct cc44a_Bindings {
 unsigned char unknown0[24];
 cc44a_Group **groups;
 unsigned char unknown28[2068];
 cc44a_Binding *pool;
 unsigned int unknown2100;
 cc44a_FreeIndices free;
};
struct cc44a_BindingName { const char *text; };
// Callee reads name's leading pointer, writes a 16-bit group, returns full signed status.
extern "C" int cc44a_lookup_group_80177eb0(cc44a_Bindings *, const cc44a_BindingName *, unsigned short *);
extern "C" int cc44a_acquire_binding_80176718(cc44a_Bindings *self,const cc44a_BindingName *name,unsigned int value,unsigned int context,cc44a_Binding **out) {
 unsigned short group;
 int status=cc44a_lookup_group_80177eb0(self,name,&group);
 if(status>=0) {
   cc44a_FreeIndices *free=&self->free;
   if ((unsigned int)(free->end-free->begin)==0) return (int)0x80004005u;
   unsigned int *next=free->end-1;
   unsigned int index=*next;
   // Native 32-bit pool-address arithmetic preserves the witnessed index/base order.
   unsigned int offset=index * 24;
   free->end=next;
   cc44a_Binding *binding=(cc44a_Binding *)(offset + (unsigned int)self->pool);
   if(binding) binding->vtable->retain(binding);
   if(*out) (*out)->vtable->release(*out);
   *out=binding;
   binding->value=value;
   (*out)->state=0;
   (*out)->group=group;
   (*out)->context=context;
   cc44a_Group *target=self->groups[group];
   status=target->vtable->bind(target,*out);
 }
 return status;
}
