#include "w3d_ptr.h"
#line 1 "sol35b2_select_800e2368.cpp"
// Reference-ABI recovery from the original instructions at 800e2368.
// Offsets and function signatures are observed; semantic names are inferred.
// Position assignment is the native three-word aggregate copy. Mode zero
// shares the fallback route with other modes. index + base retains ordinary
// C++ pointer semantics; the result must lie in the property array.
// Virtual entries are represented as observed callable slots, with this in
// r3; the final dispatch table is at actor+112. These partial types do not
// establish original complete-class identities or portable vtable layouts.
// Layouts and names are inferred native GC32 views.
struct Sol35b2Position {float x,y,z;};
struct Sol35b2Node {Ptr32<Ptr32<void>> table;};
struct Sol35b2Actor {char unknown[112];Ptr32<Ptr32<void>> table;};
struct Sol35b2Selector {char unknown0[32];Ptr32<Sol35b2Node> source;int parameter;char unknown40[116];int sync;char unknown160[12];int mode;char unknown176[84];Ptr32<void> property;Ptr32<Ptr32<Sol35b2Node>> nodes;};
extern "C" Ptr32<Sol35b2Position> sol35b2_property_80189518(Ptr32<void>);
extern "C" Ptr32<void> sol35b2_sync_80341584(int);
extern "C" Ptr32<void> sol35b2_config_801797b4(Ptr32<void>);
extern "C" void sol35b2_select_800e2368(Ptr32<Sol35b2Selector> s,int index,Ptr32<Sol35b2Position> out) {
 switch(s->mode) {
 case 1: {Ptr32<Sol35b2Position> base=sol35b2_property_80189518(s->property); *out=*(index+base);break;}
 case 2: {
  Ptr32<Sol35b2Node> node=s->nodes[index];
  *out=*((Ptr32<Ptr32<Sol35b2Position> (Ptr32<Sol35b2Node>)>)node->table[25])(node);
  break;
 }
 case 0: default:
  Ptr32<void> configuration=sol35b2_config_801797b4(sol35b2_sync_80341584(s->sync));
  Ptr32<Sol35b2Node> node=s->source;
  Ptr32<Sol35b2Actor> actor=((Ptr32<Ptr32<Sol35b2Actor> (Ptr32<Sol35b2Node>, int)>)node->table[5])(node,index);
  ((Ptr32<void (Ptr32<Sol35b2Actor>, int, Ptr32<Sol35b2Position>, Ptr32<void>, int)>)actor->table[9])(actor,s->parameter,out,configuration,0);
  break;
 }
}


