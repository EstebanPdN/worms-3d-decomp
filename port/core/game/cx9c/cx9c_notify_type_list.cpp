#include "w3d_ptr.h"
#line 1 "cx9c_notify_type_list.cpp"
/* Inferred type-gated observer notification. Type parent+20, flags+32;
 * manager embeds a lock at +12 and a circular list at +16 (header+4).
 * List nodes contain next/previous pointers and a subscriber at +8.
 * Native member-pointer thunk vtables use the observed four-byte entries.
 */
struct Cx9cType{unsigned char opaque[20];Ptr32<Cx9cType> parent;unsigned char other[8];unsigned int flags;};
extern "C" Cx9cType cx9c_base_type_80365788;
class Cx9cLock{public:void w3d_r_unused0() __asm__(W3D_SYM("_ZN8Cx9cLock7unused0Ev"));void w3d_r_retain() __asm__(W3D_SYM("_ZN8Cx9cLock6retainEv"));void w3d_r_release() __asm__(W3D_SYM("_ZN8Cx9cLock7releaseEv")); __attribute__((always_inline)) inline void unused0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Cx9cLock, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void retain() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Cx9cLock, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Cx9cLock, 4))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Cx9cLock; };
class Cx9cSubscriber{public:void w3d_r_unused0() __asm__(W3D_SYM("_ZN14Cx9cSubscriber7unused0Ev"));void w3d_r_notify(unsigned int) __asm__(W3D_SYM("_ZN14Cx9cSubscriber6notifyEj")); __attribute__((always_inline)) inline void unused0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Cx9cSubscriber, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void notify(unsigned int w3d_a0) { ((void (*)(w3d_u32, unsigned int))w3d::vfn(this->w3d_vptr_Cx9cSubscriber, 3))(w3d::h2g(this), w3d_a0); }  Ptr32<void> w3d_vptr_Cx9cSubscriber; };
struct Cx9cListNode{Ptr32<Cx9cListNode> next; Ptr32<Cx9cListNode> previous;Ptr32<Cx9cSubscriber> subscriber;};
struct Cx9cListIterator{
 Ptr32<Cx9cListNode> node;
 Cx9cListIterator(){}
 template <class W3dU> Cx9cListIterator(Ptr32<W3dU> w3d_p) : Cx9cListIterator((Cx9cListNode *)w3d_p.get()) {}
 Cx9cListIterator(Cx9cListNode *p):node(p){}
 Cx9cListIterator(const Cx9cListIterator &other):node(other.node){}
 Ptr32<Cx9cSubscriber> operator*()const{return node->subscriber;}
 bool operator!=(const Cx9cListIterator &other)const{return node!=other.node;}
 Cx9cListIterator &operator++(){node=node->next;return *this;}
};
struct Cx9cConstListIterator{
 Ptr32<Cx9cListNode> node;
 Cx9cConstListIterator(const Cx9cListIterator &other):node(other.node){}
 Ptr32<Cx9cSubscriber> operator*()const{return node->subscriber;}
 bool operator!=(Cx9cListNode *other)const{return node!=other;}
 Cx9cConstListIterator &operator++(){node=node->next;return *this;}
 Cx9cConstListIterator operator++(int){Cx9cConstListIterator old=*this;node=node->next;return old;}
};
struct Cx9cList{unsigned int allocator;Ptr32<Cx9cListNode> header;
 Cx9cListIterator begin(){return Cx9cListIterator(header->next);}
 Cx9cListIterator end(){return Cx9cListIterator(header);}
};
struct Cx9cManager{unsigned char opaque[12];Cx9cLock lock;Cx9cList observers;};
extern "C" Ptr32<Cx9cManager> cx9c_manager_801ea954();
struct Cx9cScopedLock{Ptr32<Cx9cLock> p;template <class W3dU> Cx9cScopedLock(Ptr32<W3dU> w3d_p) : Cx9cScopedLock((Cx9cLock *)w3d_p.get()) {}
 Cx9cScopedLock(Cx9cLock*x):p(x){p->retain();}~Cx9cScopedLock(){p->release();}};
static inline bool cx9c_descends(Ptr32<Cx9cType> type,Ptr32<const Cx9cType> base){while(type!=base){Ptr32<Cx9cType> parent=type->parent;if(type==parent)return false;type=parent;}return true;}
extern "C" void w3d_cx9c_notify_type_list_80356c10(Ptr32<void>,Ptr32<Cx9cType> type)
{
 if(cx9c_descends(type,&cx9c_base_type_80365788)){
  Ptr32<Cx9cManager> manager=cx9c_manager_801ea954();unsigned int identifier=type->flags>>22;
  Cx9cScopedLock lock(&manager->lock);
  Cx9cConstListIterator current=manager->observers.begin();Ptr32<Cx9cListNode> end=manager->observers.end().node;
  while(current!=end){Ptr32<Cx9cListNode> next=current.node->next;(*current)->notify(identifier);current.node=next;}
 }
}


