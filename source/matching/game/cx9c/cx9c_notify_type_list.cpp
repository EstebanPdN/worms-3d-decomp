/* Inferred type-gated observer notification. Type parent+20, flags+32;
 * manager embeds a lock at +12 and a circular list at +16 (header+4).
 * List nodes contain next/previous pointers and a subscriber at +8.
 * Native member-pointer thunk vtables use the observed four-byte entries.
 */
struct Cx9cType{unsigned char opaque[20];Cx9cType *parent;unsigned char other[8];unsigned int flags;};
extern "C" Cx9cType cx9c_base_type_80365788;
class Cx9cLock{public:virtual void unused0();virtual void retain();virtual void release();};
class Cx9cSubscriber{public:virtual void unused0();virtual void notify(unsigned int);};
struct Cx9cListNode{Cx9cListNode *next,*previous;Cx9cSubscriber *subscriber;};
struct Cx9cListIterator{
 Cx9cListNode *node;
 Cx9cListIterator(){}
 Cx9cListIterator(Cx9cListNode *p):node(p){}
 Cx9cListIterator(const Cx9cListIterator &other):node(other.node){}
 Cx9cSubscriber *operator*()const{return node->subscriber;}
 bool operator!=(const Cx9cListIterator &other)const{return node!=other.node;}
 Cx9cListIterator &operator++(){node=node->next;return *this;}
};
struct Cx9cConstListIterator{
 Cx9cListNode *node;
 Cx9cConstListIterator(const Cx9cListIterator &other):node(other.node){}
 Cx9cSubscriber *operator*()const{return node->subscriber;}
 bool operator!=(Cx9cListNode *other)const{return node!=other;}
 Cx9cConstListIterator &operator++(){node=node->next;return *this;}
 Cx9cConstListIterator operator++(int){Cx9cConstListIterator old=*this;node=node->next;return old;}
};
struct Cx9cList{unsigned int allocator;Cx9cListNode *header;
 Cx9cListIterator begin(){return Cx9cListIterator(header->next);}
 Cx9cListIterator end(){return Cx9cListIterator(header);}
};
struct Cx9cManager{unsigned char opaque[12];Cx9cLock lock;Cx9cList observers;};
extern "C" Cx9cManager *cx9c_manager_801ea954();
struct Cx9cScopedLock{Cx9cLock*p;Cx9cScopedLock(Cx9cLock*x):p(x){p->retain();}~Cx9cScopedLock(){p->release();}};
static inline bool cx9c_descends(Cx9cType *type,const Cx9cType *base){while(type!=base){Cx9cType*parent=type->parent;if(type==parent)return false;type=parent;}return true;}
extern "C" void w3d_cx9c_notify_type_list_80356c10(void*,Cx9cType *type)
{
 if(cx9c_descends(type,&cx9c_base_type_80365788)){
  Cx9cManager*manager=cx9c_manager_801ea954();unsigned int identifier=type->flags>>22;
  Cx9cScopedLock lock(&manager->lock);
  Cx9cConstListIterator current=manager->observers.begin();Cx9cListNode *end=manager->observers.end().node;
  while(current!=end){Cx9cListNode *next=current.node->next;(*current)->notify(identifier);current.node=next;}
 }
}
