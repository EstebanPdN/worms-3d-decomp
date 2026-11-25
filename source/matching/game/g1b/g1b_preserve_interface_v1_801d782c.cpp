// External receiver prefix only; never constructed locally.
struct G1bInterface {void **table;};
inline void retain(G1bInterface*p){if(p)((void(*)(G1bInterface*))p->table[3])(p);}
inline void release(G1bInterface*p){if(p)((void(*)(G1bInterface*))p->table[4])(p);}
// Complete native local held value: one pointer, with all constructor/destructor effects inline.
struct G1bHeld {G1bInterface*p;G1bHeld(G1bInterface*q):p(q){retain(p);}~G1bHeld(){release(p);}
G1bHeld&operator=(const G1bHeld&q){G1bInterface*old=p;p=q.p;retain(p);release(old);return *this;}
void clear(){G1bInterface*old=p;p=0;release(old);}};
struct G1bOwner {unsigned prefix[5];G1bHeld held;};
extern "C" void fn_801ea18c(G1bOwner*,void*);
extern "C" int g1b_preserve_interface_801d782c(G1bOwner*self,void*arg){
 G1bHeld saved(self->held.p);
 self->held.clear();
 fn_801ea18c(self,arg);
 self->held=saved;
 return 0;
}
