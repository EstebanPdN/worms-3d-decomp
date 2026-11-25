// PPC32 original tile rows have eight output bytes; bounded copy leaves untouched padding.
typedef unsigned char Byte;
extern "C" void w3d_cc18b_byte_tile_copy_801d7f04(const Byte*source,unsigned pitch,unsigned width,unsigned height,unsigned x,unsigned y,Byte*out){unsigned rows=height-y,cols=width-x;if(rows>4)rows=4;if(cols>8)cols=8;unsigned row=0;if(row<rows){unsigned base=x*1+(unsigned)source;do{Byte*d=(Byte*)((unsigned)out+(row<<3));unsigned col=0;if(col<cols){const Byte*p=(const Byte*)(base+pitch*(row+y));do{*d++=*p++; ++col;}while(col<cols);}++row;}while(row<rows);}}

