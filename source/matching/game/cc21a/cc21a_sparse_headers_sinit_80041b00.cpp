// Observed sparse16-byte header then12-byte range headers; meanings inferred.
inline void *operator new(unsigned,void*p){return p;}
struct Cc21aTail {void*untouched,*finish;Cc21aTail(){} void clear(){finish=0;}};
struct Cc21aSparse {void*begin,*end;Cc21aTail tail;Cc21aSparse(){end=0;begin=0;tail.clear();}};
struct Cc21aRange {void*begin,*end,*capacity;Cc21aRange(){capacity=0;end=0;begin=0;}};
extern Cc21aSparse cc21a_lbl_804273ec;
extern Cc21aRange cc21a_lbl_804273fc;
extern "C" char *cc21a_lbl_804aa94c;
extern "C" char *cc21a_lbl_804ad1bc;
extern "C" char *cc21a_lbl_804ad1c0;
extern "C" char *cc21a_lbl_804ad1c4;
extern "C" char *cc21a_lbl_804ad1c8;
extern "C" char *cc21a_lbl_804ad1cc;
extern "C" char *cc21a_lbl_804ad1d0;
extern "C" char *cc21a_lbl_804ad1d4;
extern "C" char *cc21a_lbl_804ad1d8;
extern "C" char *cc21a_lbl_804ad1dc;
extern "C" char cc21a_lbl_80360030[];
extern "C" char cc21a_lbl_803e7a24[];
extern "C" char cc21a_lbl_803618f0[];
extern "C" void * cc21a_fn_8003f16c();
extern "C" void*cc21a_fn_801629f8(void*,void*,void*,void*,int,int);
extern "C" void cc21a_sparse_headers_sinit_80041b00(int init,int priority){volatile char cc21a_frame[8];if(priority==0xffff&&init){cc21a_lbl_804ad1bc=cc21a_lbl_804aa94c+16384;
cc21a_lbl_804ad1c0=cc21a_lbl_804aa94c;
cc21a_lbl_804ad1c4=cc21a_lbl_804aa94c+736;
cc21a_lbl_804ad1c8=cc21a_lbl_804aa94c+12400;
cc21a_lbl_804ad1cc=cc21a_lbl_804aa94c;
cc21a_lbl_804ad1d0=cc21a_lbl_804aa94c+16368;
cc21a_lbl_804ad1d4=cc21a_lbl_804aa94c+16304;
cc21a_lbl_804ad1d8=cc21a_lbl_804aa94c+16176;
cc21a_lbl_804ad1dc=cc21a_lbl_804aa94c;
cc21a_fn_801629f8(cc21a_lbl_80360030,cc21a_lbl_803e7a24,cc21a_lbl_803618f0,(void*)cc21a_fn_8003f16c,10,0);
new (&cc21a_lbl_804273ec) Cc21aSparse;
new (&cc21a_lbl_804273fc) Cc21aRange;
}}