// Names and roles inferred; partial owner and twelve-byte selection-entry views.
// Four-byte RGBA temporaries are observed. Native conditional lifetime and
// iterator APIs preserve original evaluation; no complete owner allocation claim.
// Partial selection and twelve-byte entry views; field roles inferred.
struct F15aValueIface{void**table;};
struct F15aValueEntry{F15aValueIface*p;int value;int unknown;};
struct F15aValueArray{F15aValueEntry*begin,*end;int unknown;F15aValueEntry*beginIt()const{return begin;}F15aValueEntry*endIt()const{return end;}unsigned size()const{return end-begin;}};
struct F15aValueView{char unknown[140];int bright;char unknown144[32];int notify;char unknown180[28];void**baseTable;char unknown212[12];F15aValueArray entries;int unknown236;int selected;};
struct F15aValueColour{signed char r,g,b,a;F15aValueColour(int rr,int gg,int bb,int aa):r(rr),g(gg),b(bb),a(aa){}};
extern "C" F15aValueIface*fn_8034357c(F15aValueIface*);
extern "C" int fn_80173df0(F15aValueIface*,const F15aValueColour&);
#define VCALL(P,N,T) ((T)((P)->table[N]))
inline void setColour(F15aValueView*s,F15aValueEntry*p){const F15aValueColour&colour=s->bright==0?F15aValueColour(180,180,180,255):F15aValueColour(255,255,255,255);fn_80173df0(fn_8034357c(p->p),colour);}
extern "C" void w3d_f15a_select_value_80286b40(F15aValueView*s,int value){
 if(s->entries.size()){
  F15aValueEntry*p=s->entries.beginIt();int index=0;bool found=false;
  for(;p!=s->entries.endIt();++p,++index){
   if(p->value==value){s->selected=index;if(p->p){VCALL(p->p,22,void(*)(F15aValueIface*,int))(p->p,1);{const F15aValueColour&colour=s->bright==0?F15aValueColour(180,180,180,255):F15aValueColour(255,255,255,255);found=true;fn_80173df0(fn_8034357c(p->p),colour);}}}
   else if(p->p)VCALL(p->p,22,void(*)(F15aValueIface*,int))(p->p,0);
  }
  if(!found){p=s->entries.beginIt();if(p->p){VCALL(p->p,22,void(*)(F15aValueIface*,int))(p->p,1);setColour(s,p);}s->selected=0;}
  if(s->notify)((void(*)(void*))s->baseTable[14])((char*)s+28);
 }
}
