#include "w3d_ptr.h"
#line 1 "cc17a_select_plans_800071ec.cpp"
// Inferred AI work queues; two pointer endpoints and cost at +4 are observed.
struct Cc17aQueue {Ptr32<Ptr32<void>> begin; Ptr32<Ptr32<void>> end;};struct Cc17aPlan{unsigned word;float cost;};
extern Ptr32<Cc17aQueue> volatile pending_804aa560;extern Ptr32<Cc17aQueue> selected_804aa558;extern int flag_804aa57c;extern const float terminal_8036951c[];
extern "C" void empty_800072b0(),sort_800076c4(Ptr32<Cc17aQueue>,int),push_800075c4(Ptr32<Cc17aQueue>,Ptr32<Cc17aPlan>),state_800068a8(int);
extern "C" Ptr32<Cc17aPlan> pop_800075b0(Ptr32<Cc17aQueue>);
inline bool empty(Ptr32<volatile Cc17aQueue> q){Ptr32<Ptr32<void>> end=q->end;Ptr32<Ptr32<void>> begin=q->begin;return begin==end;}
extern "C" void w3d_cc17a_select_plans_800071ec(){
 Ptr32<Cc17aQueue> initial=pending_804aa560;if(initial->begin==initial->end){empty_800072b0();}
 else {int count=0;sort_800076c4(initial,1);
  if(!empty(pending_804aa560)){float terminal=terminal_8036951c[0];do{Ptr32<Cc17aPlan> p=pop_800075b0(pending_804aa560);push_800075c4(selected_804aa558,p);if(p->cost==terminal)flag_804aa57c=1;++count;}while(count<30 && !empty(pending_804aa560));}
  state_800068a8(3);
 }
}


