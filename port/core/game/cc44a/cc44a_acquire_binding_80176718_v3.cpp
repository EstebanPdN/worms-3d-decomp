#include "w3d_ptr.h"
#line 1 "cc44a_acquire_binding_80176718_v3.cpp"
// Partial native views. The pool stride is witnessed by mulli 24, not inferred
// from a stack frame. Indirect callback return types are unknown except bind's
// signed status result; reference callback results are discarded.
struct cc44a_Binding;
struct cc44a_BindingVtable { unsigned int unknown[3]; Ptr32<void (Ptr32<cc44a_Binding>)> retain; Ptr32<void (Ptr32<cc44a_Binding>)> release; };
struct cc44a_Binding {
 Ptr32<cc44a_BindingVtable> vtable;
 unsigned int value;
 unsigned short group;
 unsigned short unknown10;
 unsigned int state;
 unsigned int context;
 unsigned int unknown20;
};
struct cc44a_Group;
struct cc44a_GroupVtable { unsigned int unknown[14]; Ptr32<int (Ptr32<cc44a_Group>, Ptr32<cc44a_Binding>)> bind; };
struct cc44a_Group { Ptr32<cc44a_GroupVtable> vtable; };
struct cc44a_FreeIndices { Ptr32<unsigned int> begin; Ptr32<unsigned int> end; };
struct cc44a_Bindings {
 unsigned char unknown0[24];
 Ptr32<Ptr32<cc44a_Group>> groups;
 unsigned char unknown28[2068];
 Ptr32<cc44a_Binding> pool;
 unsigned int unknown2100;
 cc44a_FreeIndices free;
};
struct cc44a_BindingName { Ptr32<const char> text; };
// Callee reads name's leading pointer, writes a 16-bit group, returns full signed status.
extern "C" int cc44a_lookup_group_80177eb0(Ptr32<cc44a_Bindings>, Ptr32<const cc44a_BindingName>, Ptr32<unsigned short>);
extern "C" int cc44a_acquire_binding_80176718(Ptr32<cc44a_Bindings> self,Ptr32<const cc44a_BindingName> name,unsigned int value,unsigned int context,Ptr32<Ptr32<cc44a_Binding>> out) {
 unsigned short group;
 int status=cc44a_lookup_group_80177eb0(self,name,&group);
 if(status>=0) {
   Ptr32<cc44a_FreeIndices> free=&self->free;
   if ((unsigned int)(free->end-free->begin)==0) return (int)0x80004005u;
   Ptr32<unsigned int> next=free->end-1;
   unsigned int index=*next;
   // Native 32-bit pool-address arithmetic preserves the witnessed index/base order.
   unsigned int offset=index * 24;
   free->end=next;
   Ptr32<cc44a_Binding> binding=(Ptr32<cc44a_Binding>)w3d::G((offset + (unsigned int)w3d::H(self->pool)));
   if(binding) binding->vtable->retain(binding);
   if(*out) (*out)->vtable->release(*out);
   *out=binding;
   binding->value=value;
   (*out)->state=0;
   (*out)->group=group;
   (*out)->context=context;
   Ptr32<cc44a_Group> target=self->groups[group];
   status=target->vtable->bind(target,*out);
 }
 return status;
}


