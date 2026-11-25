/* Observed type chain: next +4, parent +20. Actor callback is vtable +36;
 * negative results stop traversal. Names and type meanings are inferred. */
struct Cx9cActor {void **vtable;};
struct Cx9cType {unsigned int opaque;Cx9cType *next;unsigned int other[3];Cx9cType *parent;};
extern "C" Cx9cActor *cx9c_first_8020fe00(Cx9cType *);
extern "C" Cx9cActor *cx9c_next_8020fe18(Cx9cType *,Cx9cActor *);
extern "C" Cx9cType *cx9c_types_8020ff3c();
static inline int cx9c_apply(Cx9cType *type,void *argument) {
 for(Cx9cActor *p=cx9c_first_8020fe00(type);p;p=cx9c_next_8020fe18(type,p)) {
  int result=((int (*)(Cx9cActor *,void *))p->vtable[9])(p,argument);
  if(result<0)return result;
 }
 return 0;
}
static inline bool cx9c_descends(Cx9cType *type,Cx9cType *base) {
 while(type!=base) {Cx9cType *parent=type->parent;if(type==parent)return false;type=parent;}
 return true;
}
extern "C" int w3d_cx9c_apply_actor_types_8034ad50(void *,void *argument,Cx9cType *type,int descendants) {
 int result=cx9c_apply(type,argument);
 if(result>=0) {
  if(descendants)for(Cx9cType *p=cx9c_types_8020ff3c();p;p=p->next) {
   if(cx9c_descends(p,type) && p!=type) {int r=cx9c_apply(p,argument);if(r<0)return r;}
  }
  result=0;
 }
 return result;
}
