#include "w3d_ptr.h"
#line 1 "cc22a_planner_score_partition_80006cc0.cpp"
// Observed planner lists and score records. Semantic names are inferred.
struct Cc22aPlan80006cc0 { unsigned int unknown00; float score04; int active08; Ptr32<Ptr32<void>> dispatch0c; };
struct Cc22aList80006cc0 { Ptr32<Ptr32<Cc22aPlan80006cc0>> begin; Ptr32<Ptr32<Cc22aPlan80006cc0>> end; bool empty() const {return begin==end;} Ptr32<Cc22aPlan80006cc0> & first(){return *begin;} Ptr32<Cc22aPlan80006cc0> & last(){return end[-1];} };
struct Cc22aTuning80006cc0 { unsigned char unknown00[20]; float scale14; };
extern "C" {
extern Ptr32<Cc22aList80006cc0> lbl_804aa558; extern Ptr32<Cc22aList80006cc0> lbl_804aa55c; extern Ptr32<Cc22aList80006cc0> lbl_804aa560;
extern Ptr32<Cc22aTuning80006cc0> lbl_804aa6d8;
extern int lbl_804aa59c,lbl_804aa57c;
extern float lbl_804aa570; extern float lbl_80369504[],lbl_80369508[],lbl_8036950c[],lbl_80369510[];
Ptr32<Cc22aPlan80006cc0> fn_800075b0(Ptr32<Cc22aList80006cc0>);
void fn_800075c4(Ptr32<Cc22aList80006cc0>,Ptr32<Cc22aPlan80006cc0>);
void fn_8001644c(Ptr32<Cc22aPlan80006cc0>);float fn_80016978();void fn_800158b8(Ptr32<float>,float);
void fn_800076c4(Ptr32<Cc22aList80006cc0>,int);void fn_800068a8(int);
}
extern "C" void cc22a_planner_score_partition_80006cc0() {
Ptr32<Cc22aPlan80006cc0> p=fn_800075b0(lbl_804aa558);
if(p->score04==lbl_80369504[0]) {
 p->score04=lbl_80369508[0]; ((Ptr32<void (Ptr32<Cc22aPlan80006cc0>)>)p->dispatch0c[5])(p);
 fn_8001644c(p);
 if(lbl_804aa59c) p->score04*=fn_80016978();
 fn_800158b8(&p->score04,lbl_804aa6d8->scale14);
 lbl_804aa570+=lbl_8036950c[0];
}
fn_800075c4(lbl_804aa55c,p);
if(lbl_804aa558->empty()) {
 lbl_804aa57c=0;fn_800076c4(lbl_804aa55c,0);
 int count=0;lbl_804aa570+=lbl_80369510[0];
 if(!lbl_804aa55c->empty()) {
 do {++count; Ptr32<Cc22aPlan80006cc0> next=fn_800075b0(lbl_804aa55c);fn_800075c4(lbl_804aa558,next);if(count>39) break;} while(!lbl_804aa55c->empty());
 while(!lbl_804aa55c->empty()) {Ptr32<Cc22aPlan80006cc0> next=fn_800075b0(lbl_804aa55c);fn_800075c4(lbl_804aa560,next);}
 }
 if(!lbl_804aa560->empty()) {
 fn_800076c4(lbl_804aa560,1);
 for(;;) { if(lbl_804aa558->first()->score04 >= lbl_804aa560->last()->score04) break;
 Ptr32<Cc22aPlan80006cc0> swap=lbl_804aa558->first();
 lbl_804aa558->first()=lbl_804aa560->last();lbl_804aa560->last()=swap;
 fn_800076c4(lbl_804aa560,1);fn_800076c4(lbl_804aa558,0);
 }
 }
 fn_800068a8(3);
}
}


