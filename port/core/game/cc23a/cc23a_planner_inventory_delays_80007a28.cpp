#include "w3d_ptr.h"
#line 1 "cc23a_planner_inventory_delays_80007a28.cpp"
// Inventory property names are observed; role names inferred. All counters are 32 bit.
struct Cc23aHeld80007a28 {Ptr32<Ptr32<void>> dispatch;};
struct Cc23aHandle80007a28 {Ptr32<Cc23aHeld80007a28> p;unsigned int unknown04;};
struct Cc23aName80007a28 {Ptr32<const char> text;unsigned int unknown04;};
struct Cc23aTeam80007a28 {unsigned char unknown00[260];int flag104;};
extern "C" {
extern float lbl_804aa570;extern float lbl_80369568[];extern char lbl_80369550[];
extern int lbl_804aa6c0,lbl_804aa5a0;extern Ptr32<int> lbl_804aa5a8;
int fn_800fc1b0(Ptr32<Cc23aName80007a28>,Ptr32<Cc23aHandle80007a28>);Ptr32<void> fn_80341584(Ptr32<Cc23aHeld80007a28>);
Ptr32<void> fn_801797b4(Ptr32<void>);unsigned int fn_8025c3a8(Ptr32<void>,unsigned int);int fn_800fcec8(int,unsigned int);
Ptr32<Cc23aTeam80007a28> fn_800fc6dc(int);
}
extern "C" void cc23a_planner_inventory_delays_80007a28(){
 lbl_804aa570+=lbl_80369568[0];
 struct Workspace{Cc23aHandle80007a28 handle;Cc23aName80007a28 name;} q;
 q.handle.p=0;q.name.text=lbl_80369550;
 fn_800fc1b0(&q.name,&q.handle);
 unsigned int i=0;int zero=0,offZero=0,offValue=0;Ptr32<void> properties=fn_801797b4((Ptr32<void>)fn_80341584(q.handle.p));
 do {if(fn_8025c3a8(properties,i)==0) {
 int value=fn_800fcec8(lbl_804aa6c0,i);*(Ptr32<int>)w3d::G((offValue+(unsigned int)w3d::H(lbl_804aa5a8)))=value;
 }else *(Ptr32<int>)w3d::G((offZero+(unsigned int)w3d::H(lbl_804aa5a8)))=zero;
 ++i;offZero+=4;offValue+=4;
 }while(i<59);
 lbl_804aa5a0=fn_800fc6dc(lbl_804aa6c0)->flag104;
 if(lbl_804aa5a0){int count=59;Ptr32<int> cursor=lbl_804aa5a8;do{*cursor++=0;}while(--count);lbl_804aa5a8[47]=-1;}
 if(q.handle.p)((Ptr32<void (Ptr32<Cc23aHeld80007a28>)>)q.handle.p->dispatch[4])(q.handle.p);
}


