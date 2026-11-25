#include "w3d_ptr.h"
#line 1 "cc23a_path_pending_release_800062ec.cpp"
// Pending allocation range at observed path-search offset.
struct Cc23aPending800062ec {Ptr32<Ptr32<void>> begin; Ptr32<Ptr32<void>> end;bool empty(){return begin==end;}Ptr32<void> pop(){Ptr32<Ptr32<void>> next=end-1;Ptr32<void> p=*next;end=next;return p;}};
struct Cc23aPath800062ec {unsigned char unknown00[0x8024];Cc23aPending800062ec pending;};
extern "C" {void fn_8034144c();void fn_80015264(Ptr32<void>);}
extern "C" void cc23a_path_pending_release_800062ec(Ptr32<Cc23aPath800062ec> self){
 while(!self->pending.empty()) {Ptr32<void> p=self->pending.pop();if(p){fn_8034144c();fn_80015264(p);}}
}


