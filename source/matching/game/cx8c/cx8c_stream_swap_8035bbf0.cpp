/* Observed: in-place byte swapping before and after stream transfer, original 0x8035bbf0.
 * Buffer/stream roles are inferred from the access pattern; transfer stays an original extern. */
struct Cx8cStream;
extern "C" int cx8c_stream_transfer_802047e0(Cx8cStream *,void *,unsigned int);
static inline void cx8c_swap(unsigned short *buffer,unsigned int count) {
 for(unsigned int i=0;i<count;++i) {unsigned short v=buffer[i];buffer[i]=(unsigned short)(((v&0xff)<<8)|(v>>8));}
}
extern "C" void w3d_cx8c_stream_swap_8035bbf0(Cx8cStream *self,unsigned short *buffer,unsigned int count) {
 cx8c_swap(buffer,count);cx8c_stream_transfer_802047e0(self,buffer,count*sizeof(unsigned short));cx8c_swap(buffer,count);
}
