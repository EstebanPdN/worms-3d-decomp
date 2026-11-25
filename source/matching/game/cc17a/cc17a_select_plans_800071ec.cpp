// Inferred AI work queues; two pointer endpoints and cost at +4 are observed.
struct Cc17aQueue {void **begin,**end;};struct Cc17aPlan{unsigned word;float cost;};
extern Cc17aQueue *volatile pending_804aa560;extern Cc17aQueue *selected_804aa558;extern int flag_804aa57c;extern const float terminal_8036951c[];
extern "C" void empty_800072b0(),sort_800076c4(Cc17aQueue*,int),push_800075c4(Cc17aQueue*,Cc17aPlan*),state_800068a8(int);
extern "C" Cc17aPlan *pop_800075b0(Cc17aQueue*);
inline bool empty(volatile Cc17aQueue*q){void**end=q->end;void**begin=q->begin;return begin==end;}
extern "C" void w3d_cc17a_select_plans_800071ec(){
 Cc17aQueue *initial=pending_804aa560;if(initial->begin==initial->end){empty_800072b0();}
 else {int count=0;sort_800076c4(initial,1);
  if(!empty(pending_804aa560)){float terminal=terminal_8036951c[0];do{Cc17aPlan*p=pop_800075b0(pending_804aa560);push_800075c4(selected_804aa558,p);if(p->cost==terminal)flag_804aa57c=1;++count;}while(count<30 && !empty(pending_804aa560));}
  state_800068a8(3);
 }
}
