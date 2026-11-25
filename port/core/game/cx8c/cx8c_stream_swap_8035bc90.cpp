#include "w3d_ptr.h"
#line 1 "cx8c_stream_swap_8035bc90.cpp"
/* Observed: in-place byte swapping before and after stream transfer, original 0x8035bc90.
 * Buffer/stream roles are inferred from the access pattern; transfer stays an original extern. */
struct Cx8cStream;
extern "C" int cx8c_stream_transfer_802047e0(Ptr32<Cx8cStream>,Ptr32<void>,unsigned int);
static inline void cx8c_swap(Ptr32<unsigned int> buffer,unsigned int count) {
 for(unsigned int i=0;i<count;++i) {unsigned int v=buffer[i];buffer[i]= v;}
}
extern "C" void w3d_cx8c_stream_swap_8035bc90(Ptr32<Cx8cStream> self,Ptr32<unsigned int> buffer,unsigned int count) {
 cx8c_swap(buffer,count);cx8c_stream_transfer_802047e0(self,buffer,count*sizeof(unsigned int));cx8c_swap(buffer,count);
}


