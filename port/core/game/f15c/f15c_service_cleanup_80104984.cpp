#include "w3d_ptr.h"
#line 1 "f15c_service_cleanup_80104984.cpp"
// External564-byte receiver prefix; no constructor or allocation size asserted.
// Four-byte held-interface wrappers and native two-element arrays preserve cleanup.
// Global interface reset is an inferred native boundary; all original targets are witnessed.
// The copy call clears CR for varargs in the original; its zero-length behavior is preserved.
// External buffer view exposes only begin/end; capacity and ownership are unknown.
struct F15cCleanup2Object{Ptr32<Ptr32<void>> vtable;};
struct F15cCleanup2Held{Ptr32<F15cCleanup2Object> p;~F15cCleanup2Held(){if(p)((Ptr32<void (Ptr32<F15cCleanup2Object>)>)p->vtable[4])(p);}
void reset(Ptr32<F15cCleanup2Object> value){if(p)((Ptr32<void (Ptr32<F15cCleanup2Object>)>)p->vtable[4])(p);p=value;}};
struct F15cCleanup2Buffer{Ptr32<char> begin; Ptr32<char> end;};
extern F15cCleanup2Buffer buffer_8044b694[];
extern F15cCleanup2Held selected_804af1e8;
extern int active_804aafa4;
extern Ptr32<void> vtable_80410690[];
extern "C" Ptr32<void> copy_802eee50(Ptr32<void>,Ptr32<const void>,unsigned,...);
extern "C" void base_8015ff2c(Ptr32<void>,int);
struct F15cCleanup2Prefix {
 Ptr32<Ptr32<void>> vtable;char unknown4[24];F15cCleanup2Held first[2],second[2],held44,held48,held52;int field56;char unknown60[500];F15cCleanup2Held held560;
 ~F15cCleanup2Prefix(){vtable=vtable_80410690;active_804aafa4=0;field56=0;
  selected_804af1e8.reset(0);
  int bytes=buffer_8044b694[0].end-buffer_8044b694[0].begin;
  copy_802eee50(buffer_8044b694[0].begin,buffer_8044b694[0].end,0);
  buffer_8044b694[0].end-=bytes;
 }
};
extern "C" void f15c_service_cleanup_80104984(Ptr32<F15cCleanup2Prefix> self,int flags){self->~F15cCleanup2Prefix();base_8015ff2c(self,flags);}


