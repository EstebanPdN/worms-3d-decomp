#define F(p,T,o) (*(T*)((char*)(p)+(o)))
extern char vt_8041be80[];
extern "C" void fn_8020c5c4(void*);
extern "C" void fn_80341588(void*);
extern "C" void fn_802134fc(void*);
extern "C" void fn_80210abc(void*,int);
extern "C" void fn_801628ec(void*,int);
inline void release(void*p){if(p)(*(void(***)(void*))(p))[4](p);}
struct Range{char*begin;char*end;};
extern "C" void w3d_f5a_destroy_script_80270e58(void*self,int flags){
 *(void**)self=vt_8041be80;release(F(self,void*,92));release(F(self,void*,88));
 Range*range=(Range*)((char*)self+64);char*p=range->begin,*end=range->end;void*member=(char*)self+52;
 while(p!=end){fn_8020c5c4(p);fn_80341588(p);p+=4;}
 if(range->begin)fn_802134fc(range->begin);fn_80210abc(member,2);release(F(self,void*,28));fn_801628ec(self,flags);
}
