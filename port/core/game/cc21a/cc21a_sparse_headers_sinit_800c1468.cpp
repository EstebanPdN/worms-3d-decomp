#include "w3d_ptr.h"
#line 1 "cc21a_sparse_headers_sinit_800c1468.cpp"
// Observed sparse16-byte header then12-byte range headers; meanings inferred.
inline void *operator new(__SIZE_TYPE__,void*p){return p;}
struct Cc21aTail {Ptr32<void> untouched; Ptr32<void> finish;Cc21aTail(){} void clear(){finish=0;}};
struct Cc21aSparse {Ptr32<void> begin; Ptr32<void> end;Cc21aTail tail;Cc21aSparse(){end=0;begin=0;tail.clear();}};
struct Cc21aRange {Ptr32<void> begin; Ptr32<void> end; Ptr32<void> capacity;Cc21aRange(){capacity=0;end=0;begin=0;}};
extern Cc21aSparse cc21a_lbl_8043c384;
extern Cc21aRange cc21a_lbl_8043c394;
extern Cc21aRange cc21a_lbl_8043c3a0;
extern "C" Ptr32<char> cc21a_lbl_804aada4;
extern "C" Ptr32<char> cc21a_lbl_804ae618;
extern "C" Ptr32<char> cc21a_lbl_804ae61c;
extern "C" Ptr32<char> cc21a_lbl_804ae620;
extern "C" Ptr32<char> cc21a_lbl_804ae624;
extern "C" Ptr32<char> cc21a_lbl_804ae628;
extern "C" Ptr32<char> cc21a_lbl_804ae62c;
extern "C" Ptr32<char> cc21a_lbl_804ae630;
extern "C" Ptr32<char> cc21a_lbl_804ae634;
extern "C" Ptr32<char> cc21a_lbl_804ae638;
extern "C" char cc21a_lbl_80360960[];
extern "C" char cc21a_lbl_803e7f80[];
extern "C" char cc21a_lbl_803618f0[];
extern "C" Ptr32<void> cc21a_fn_800bfee0();
extern "C" Ptr32<void> cc21a_fn_801629f8(Ptr32<void>,Ptr32<void>,Ptr32<void>,Ptr32<void>,int,int);
extern "C" void cc21a_sparse_headers_sinit_800c1468(int init,int priority){volatile char cc21a_frame[8];if(priority==0xffff&&init){cc21a_lbl_804ae618=cc21a_lbl_804aada4+16384;
cc21a_lbl_804ae61c=cc21a_lbl_804aada4;
cc21a_lbl_804ae620=cc21a_lbl_804aada4+736;
cc21a_lbl_804ae624=cc21a_lbl_804aada4+12400;
cc21a_lbl_804ae628=cc21a_lbl_804aada4;
cc21a_lbl_804ae62c=cc21a_lbl_804aada4+16368;
cc21a_lbl_804ae630=cc21a_lbl_804aada4+16304;
cc21a_lbl_804ae634=cc21a_lbl_804aada4+16176;
cc21a_lbl_804ae638=cc21a_lbl_804aada4;
cc21a_fn_801629f8(cc21a_lbl_80360960,cc21a_lbl_803e7f80,cc21a_lbl_803618f0,(Ptr32<void>)cc21a_fn_800bfee0,10,0);
new (&cc21a_lbl_8043c384) Cc21aSparse;
new (&cc21a_lbl_8043c394) Cc21aRange;
new (&cc21a_lbl_8043c3a0) Cc21aRange;
}}

