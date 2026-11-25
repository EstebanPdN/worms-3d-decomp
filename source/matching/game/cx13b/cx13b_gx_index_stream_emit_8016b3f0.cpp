
// Hardware FIFO is an external volatile halfword port, witnessed at 0xcc008000.
extern "C" volatile unsigned short fifo_cc008000[];extern "C" void begin_803089c8(int,int,unsigned int);
extern "C" void w3d_cx13b_gx_index_stream_emit_8016b3f0(int primitive,unsigned int mask,unsigned int count){begin_803089c8(primitive,0,count);unsigned short i=0;if(i<count)do{if(mask&3)fifo_cc008000[0]=i;if(mask&12)fifo_cc008000[0]=i;if(mask&48)fifo_cc008000[0]=i;if(mask&384)fifo_cc008000[0]=i;++i;}while(i<count);}

