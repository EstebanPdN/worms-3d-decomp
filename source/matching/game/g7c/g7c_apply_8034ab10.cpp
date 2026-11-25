// All node/actor/type/context structures are external views, never local values.
struct TypeView {char unknown00[20];TypeView *parent;};
struct ActorView;
struct ActorTable {void *slots[5];TypeView *(*type)(ActorView *);void *slots6[3];int (*apply)(ActorView *,void *);};
struct ActorView {ActorTable *table;};
struct NodeView {unsigned short unknown00[3],child,unknown08,next;ActorView *actor;unsigned int unknown10,handle;char unknown18[12];};
struct RegistryView {NodeView *nodes;};
struct ContextView {char unknown00[60];unsigned int mode;};
extern "C" {
extern TypeView g7c_type_803618f0[];
extern TypeView g7c_type_80361860[];
extern TypeView g7c_type_803617d0[];
ContextView *g7c_context_80165254();
ActorView *g7c_actor_8034b974(RegistryView *,unsigned int);
}
static inline bool derives(TypeView *type,const TypeView *base){
 for(;;){if(type==base)return true;TypeView *next=type->parent;if(type==next)return false;type=next;}
}
static inline NodeView *lookup(RegistryView *self,unsigned int handle){
 if(handle==~0u)return 0;
 NodeView *node=&self->nodes[handle&4095];
 return node->handle==handle?node:0;
}
extern "C" int w3d_g7c_apply_8034ab10(RegistryView *self,void *argument,unsigned int handle,int children){
 NodeView *node=lookup(self,handle);
 if(!node)return (int)0x80004005u;
 g7c_context_80165254();
 unsigned int mode;
 if(derives(node->actor->table->type(node->actor),g7c_type_803618f0))mode=8;
 else if(derives(node->actor->table->type(node->actor),g7c_type_80361860))mode=6;
 else if(derives(node->actor->table->type(node->actor),g7c_type_803617d0))mode=7;
 else goto apply;
 g7c_context_80165254()->mode=mode;
apply:
 int result=node->actor->table->apply(node->actor,argument);
 if(result>=0 && children){
  unsigned int handles[256];int count=0;
  unsigned int index=node->child;
  if(index){
   NodeView *nodes=self->nodes;unsigned int *out=handles;
   do{++count;NodeView *child=&nodes[index];*out++=child->handle;index=child->next;}while(index);
  }
  unsigned int *cursor=handles;
  for(int i=0;i<count;++i,++cursor){
   ActorView *actor=g7c_actor_8034b974(self,*cursor);
   if(actor)result=actor->table->apply(actor,argument);
   if(result<0)return result;
  }
 }
 return result;
}
