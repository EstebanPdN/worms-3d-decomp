#include "w3d_ptr.h"
#line 1 "cx12a_update_uv_80104d78.cpp"
// PPC32 observed offsets are explicit; semantic names below are inferred.
#define FIELD(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p)+(o)))
struct Cx12aNode {unsigned char unknown00[0x1c];float a,b,c,d,e;};struct Cx12aList {Ptr32<Ptr32<Cx12aNode>> begin; Ptr32<Ptr32<Cx12aNode>> end; Ptr32<Ptr32<Cx12aNode>> capacity;unsigned size()const{return (unsigned)((Ptr32<char>)end-(Ptr32<char>)begin)>>2;}};
extern Cx12aList list_8044b694;
extern unsigned char params_803fce44[];
extern const float initial_80399828[],rate_8039982c[],scale_80399838[],zero_8039983c[],one_80399840[];
extern "C" int query_800fc270(Ptr32<void>,Ptr32<float>);
extern "C" void w3d_cx12a_update_uv_80104d78(Ptr32<void> self,int ticks){
 if(list_8044b694.size()){
 float rate=initial_80399828[0];query_800fc270(params_803fce44+FIELD(self,int,0x40)*8,&rate);rate*=rate_8039982c[0];
 float delta=(float)ticks*rate;FIELD(self,float,0x48)+=delta;FIELD(self,float,0x4c)=delta*scale_80399838[0]+FIELD(self,float,0x4c);
 Ptr32<Ptr32<Cx12aNode>> end=list_8044b694.end;for(Ptr32<Ptr32<Cx12aNode>> it=list_8044b694.begin;it!=end;++it){Ptr32<Cx12aNode> n=*it;n->e=zero_8039983c[0];float x=FIELD(self,float,0x48);n->a=one_80399840[0];n->d=x;float y=FIELD(self,float,0x4c);n->b=zero_8039983c[0];n->c=y;}
 }
}


