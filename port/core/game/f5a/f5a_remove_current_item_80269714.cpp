#include "w3d_ptr.h"
#line 1 "f5a_remove_current_item_80269714.cpp"
#define F(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char*)w3d::AG(p)+(o)))
struct Handle {Ptr32<void> p;Handle(const Handle&h):p(h.p){}~Handle(){if(p)(*(Ptr32<Ptr32<Ptr32<void (Ptr32<void>)>>>)(p))[4](p);}operator Ptr32<void>() const { return (void *)this->operator void *(); }
 operator void*()const{return p;}};
extern Ptr32<void> instance_804abb7c;
extern "C" Handle fn_8026d850(Ptr32<void>);
extern "C" void fn_8026d8e8(Ptr32<void>,int);
extern "C" void fn_8015fd1c(Ptr32<void>);
extern "C" void fn_802b1f98(Ptr32<void>);
inline Ptr32<void> at(Ptr32<void> p,unsigned i){return (*(Ptr32<Ptr32<Ptr32<Ptr32<void> (Ptr32<void>, unsigned int)>>>)(p))[29](p,i);}
inline unsigned count(Ptr32<void> p){return (*(Ptr32<Ptr32<Ptr32<unsigned int (Ptr32<void>)>>>)(p))[30](p);}
inline void remove(Ptr32<void> p,Ptr32<void> q){(*(Ptr32<Ptr32<Ptr32<void (Ptr32<void>, Ptr32<void>)>>>)(p))[24](p,q);}
extern "C" void w3d_f5a_remove_current_item_80269714(Ptr32<void> self,int mode){
 if(mode==1){
 if(fn_8026d850(instance_804abb7c)){
 for(unsigned i=0;i<count(F(self,void*,112));i++){
 if(at(F(self,void*,112),i)==(Ptr32<void>)fn_8026d850(instance_804abb7c)){
 (*(Ptr32<Ptr32<Ptr32<void (Ptr32<void>, Ptr32<void>)>>>)(F(self,void*,112)))[24](F(self,void*,112),fn_8026d850(instance_804abb7c));fn_8026d8e8(instance_804abb7c,0);break;
 }
 }
 }
 fn_8015fd1c(self);
 }else fn_802b1f98((Ptr32<char>)self+28);
}


