#include "w3d_ptr.h"
#line 1 "cc21a_relay_sparse_headers_800c590c.cpp"
// Sparse16-byte headers: offsets0,4,12 clear; offset8 remains untouched.
// Original frame reserves eight bytes beyond saved registers; purpose unknown.
inline void *operator new(__SIZE_TYPE__,void *p){return p;}
struct Cc21aTail { Ptr32<void> unused; Ptr32<void> c; Cc21aTail(){} void clear(){c=0;} };
struct Cc21aRange { Ptr32<void> a; Ptr32<void> b; Cc21aTail tail; Cc21aRange(){b=0;a=0;tail.clear();} };
extern Cc21aRange cc21a_lbl_8043e438,cc21a_lbl_8043e448;
extern "C" char cc21a_lbl_80360a80[],cc21a_lbl_803e8028[],cc21a_lbl_803618f0[];
extern "C" Ptr32<void> cc21a_fn_800c4ec8();
extern "C" Ptr32<void> cc21a_fn_801629f8(Ptr32<void>,Ptr32<void>,Ptr32<void>,Ptr32<void>,int,int);
struct Cc21aType_801629f8 { Cc21aType_801629f8(Ptr32<void>,Ptr32<void>,Ptr32<void>,int,int); int data[4];};

extern "C" void cc21a_relay_sparse_headers_800c590c(int init,int priority){volatile char cc21a_frame_reservation[8]; if(priority==0xffff && init){
cc21a_fn_801629f8(cc21a_lbl_80360a80,cc21a_lbl_803e8028,cc21a_lbl_803618f0,(Ptr32<void>)cc21a_fn_800c4ec8,10,0);
new (&cc21a_lbl_8043e438) Cc21aRange;
new (&cc21a_lbl_8043e448) Cc21aRange;
}}


