#define F(p,T,o) (*(T*)((char*)(p)+(o)))
struct Handle {void*p;Handle(const Handle&h):p(h.p){}~Handle(){if(p)(*(void(***)(void*))(p))[4](p);}operator void*()const{return p;}};
extern void*instance_804abb7c;
extern "C" Handle fn_8026d850(void*);
extern "C" void fn_8026d8e8(void*,int);
extern "C" void fn_8015fd1c(void*);
extern "C" void fn_802b1f98(void*);
inline void*at(void*p,unsigned i){return (*(void*(***)(void*,unsigned))(p))[29](p,i);}
inline unsigned count(void*p){return (*(unsigned(***)(void*))(p))[30](p);}
inline void remove(void*p,void*q){(*(void(***)(void*,void*))(p))[24](p,q);}
extern "C" void w3d_f5a_remove_current_item_80269714(void*self,int mode){
 if(mode==1){
 if(fn_8026d850(instance_804abb7c)){
 for(unsigned i=0;i<count(F(self,void*,112));i++){
 if(at(F(self,void*,112),i)==(void*)fn_8026d850(instance_804abb7c)){
 (*(void(***)(void*,void*))(F(self,void*,112)))[24](F(self,void*,112),fn_8026d850(instance_804abb7c));fn_8026d8e8(instance_804abb7c,0);break;
 }
 }
 }
 fn_8015fd1c(self);
 }else fn_802b1f98((char*)self+28);
}
