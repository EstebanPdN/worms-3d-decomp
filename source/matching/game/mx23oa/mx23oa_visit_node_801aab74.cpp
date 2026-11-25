// Scene visitor entry for one node kind, reached through the visitor's
// secondary base at +4 (null-checked conversion back to the primary).
// Same receiver family as g2b_scoped_matrix_801aa9dc: the secondary base keeps
// its callback table at +24 and callbacks are selected by the halfword at +6.
// All structs are external partial views with observed offsets only; names
// are inferred. The channel byte stays unset when the flag field is 3, as in
// the original (the callee then receives the saved register unchanged).
struct Mx23oaVisitCallback {unsigned unknown;unsigned short unknown4,index;};
struct Mx23oaVisitNode {
 char unknown[20];
 char bounds[28];               // +20: passed to the bounds test 0x801a9cbc
 Mx23oaVisitCallback*enter;     // +48
 Mx23oaVisitCallback*leave;     // +52
 unsigned flags;                // +56: bits 1..2 select a channel
};
struct Mx23oaVisitSecondary {char unknown[24];void**callbacks;};
struct Mx23oaVisitOwner {
 char unknown[44];
 void*current;                  // +44: restored after the bounds test
 char unknown48[180];
 unsigned short range228,range230;
 char unknown232[72];
 unsigned char channel[2];      // +304/+305
};
extern "C" int fn_801a9cbc(Mx23oaVisitOwner*,char*);
extern "C" void fn_801aa15c(Mx23oaVisitOwner*,int,Mx23oaVisitNode*);
extern "C" int mx23oa_visit_node_801aab74(Mx23oaVisitSecondary*self,Mx23oaVisitNode*node){
 Mx23oaVisitOwner*owner=self?(Mx23oaVisitOwner*)((char*)self-4):0;
 void*current=owner->current;
 Mx23oaVisitCallback*enter;
 if(current){
  if(!fn_801a9cbc(owner,node->bounds))return 0;
  owner->current=current;
  enter=node->enter;
  if(enter&&((int(*)(Mx23oaVisitSecondary*,Mx23oaVisitCallback*))self->callbacks[enter->index])(self,enter))return 0;
 }else{
  enter=node->enter;
  if(!enter)return 0;
 }
 unsigned char channel;
 switch((int)((node->flags>>1)&3)){
 case 0:case 2:channel=owner->channel[0];break;
 case 1:channel=owner->channel[1];break;
 }
 if(node->leave)((int(*)(Mx23oaVisitSecondary*,Mx23oaVisitCallback*))self->callbacks[node->leave->index])(self,node->leave);
 else owner->range230=owner->range228=0;
 fn_801aa15c(owner,channel,node);
 return 0;
}
