#include "w3d_ptr.h"
#line 1 "f16b_destroy_indexed_interfaces_8020ab2c.cpp"
// Inferred32-byte owner and vector views, uninstantiated here.
// Factory8020a9a8 allocates32B; constructor8020aad0 initializes through31.
extern "C" void fn_802134fc(Ptr32<void>);extern "C" void fn_80210990(Ptr32<void>,int);extern Ptr32<void> vt_80419430[]; extern Ptr32<void> vt_804181c0[];
struct F16bI180{Ptr32<Ptr32<void>> table;};struct F16bV180{Ptr32<Ptr32<F16bI180>> begin; Ptr32<Ptr32<F16bI180>> end; Ptr32<Ptr32<F16bI180>> capacity;~F16bV180(){if(begin)fn_802134fc(begin);}int size()const{return end-begin;}Ptr32<F16bI180> operator[](int i){return *(Ptr32<Ptr32<F16bI180>>)((Ptr32<char>)begin+(i<<2));}};
struct F16bB180{Ptr32<Ptr32<void>> table;unsigned node[4];~F16bB180(){table=vt_804181c0;fn_80210990(node,0);}};
struct F16bO180:F16bB180{F16bV180 held __attribute__((aligned(__alignof__(F16bB180))));~F16bO180();static void operator delete(void*);};
F16bO180::~F16bO180(){table=vt_80419430;for(int i=0,n=held.size();i<n;++i){Ptr32<F16bI180> p=held[i];((Ptr32<void (Ptr32<F16bI180>)>)p->table[4])(p);}}


