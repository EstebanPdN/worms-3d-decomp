#include "w3d_ptr.h"
#line 1 "g1b_preserve_interface_v1_801d782c.cpp"
// External receiver prefix only; never constructed locally.
struct G1bInterface {Ptr32<Ptr32<void>> table;};
inline void retain(Ptr32<G1bInterface> p){if(p)((Ptr32<void (Ptr32<G1bInterface>)>)p->table[3])(p);}
inline void release(Ptr32<G1bInterface> p){if(p)((Ptr32<void (Ptr32<G1bInterface>)>)p->table[4])(p);}
// Complete native local held value: one pointer, with all constructor/destructor effects inline.
struct G1bHeld {Ptr32<G1bInterface> p;template <class W3dU> G1bHeld(Ptr32<W3dU> w3d_p) : G1bHeld((G1bInterface *)w3d_p.get()) {}
 G1bHeld(G1bInterface*q):p(q){retain(p);}~G1bHeld(){release(p);}
G1bHeld&operator=(const G1bHeld&q){Ptr32<G1bInterface> old=p;p=q.p;retain(p);release(old);return *this;}
void clear(){Ptr32<G1bInterface> old=p;p=0;release(old);}};
struct G1bOwner {unsigned prefix[5];G1bHeld held;};
extern "C" void fn_801ea18c(Ptr32<G1bOwner>,Ptr32<void>);
extern "C" int g1b_preserve_interface_801d782c(Ptr32<G1bOwner> self,Ptr32<void> arg){
 G1bHeld saved(self->held.p);
 self->held.clear();
 fn_801ea18c(self,arg);
 self->held=saved;
 return 0;
}


