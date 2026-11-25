// PPC32 original tile rows have eight output bytes; bounded copy leaves untouched padding.
typedef unsigned char Byte;
extern "C" void w3d_cx14b_two_byte_tile_copy_801d7d78(const Byte*source,unsigned pitch,unsigned width,unsigned height,unsigned x,unsigned y,Byte*out){unsigned rows=height-y,cols=width-x;if(rows>4)rows=4;if(cols>4)cols=4;unsigned row=0;if(row<rows){unsigned base=x*2+(unsigned)source;do{Byte*d=(Byte*)((unsigned)out+(row<<3));unsigned col=0;if(col<cols){const Byte*p=(const Byte*)(base+pitch*(row+y));do{d[0]=p[0];d[1]=p[1];p+=2;d+=2; ++col;}while(col<cols);}++row;}while(row<rows);}}

