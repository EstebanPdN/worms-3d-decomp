#include "w3d_ptr.h"
// Port (v29): los huecos viven en core/native/tabla_recursos.cpp (4096 en vez de 1920).
extern "C" Ptr32<void> *w3d_restab_slots(void);
extern "C" unsigned w3d_restab_cap(void);
#line 1 "cc17b_pool_next_8017d6f4.cpp"
/* Observed fixed table: six header words and 1920 four-byte entries.
   The index is advanced in the caller's storage; negative indices are unsigned. */
struct Cc17bSlotPool { unsigned header[6]; unsigned slots[1920]; };
extern "C" int w3d_cc17b_pool_next_8017d6f4(Ptr32<Cc17bSlotPool> self,Ptr32<unsigned int> index,Ptr32<unsigned int> output) {
 // Port (v29): recorre la tabla nativa (core/native/tabla_recursos.cpp).
 Ptr32<unsigned> *slots=(Ptr32<unsigned> *)w3d_restab_slots(); const unsigned cap=w3d_restab_cap(); (void)self;
 for(;*index<cap;++*index) if(slots[*index]) break;
 if(*index==cap) return 0;
 else { *output=(unsigned)w3d::H(slots[*index]); ++*index; return 1; }
}


