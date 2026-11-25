// Original 0x801d7914. Four-byte RGBA input is split into GameCube AR/GB planes.
// Bounds clamp unsigned differences to four; original row stride and partial tile writes are retained.
struct cc41b_RGBA { unsigned char c[4]; cc41b_RGBA(const unsigned char *p){for(int i=0;i<4;++i)c[i]=p[i];} };
inline void cc41b_row(const unsigned char *pixel,unsigned width,unsigned char *ar,unsigned char *gb) {
 for(unsigned col=0;col<width;++col) {
  cc41b_RGBA value(pixel);pixel+=4;
  ar[0]=value.c[3];ar[1]=value.c[0];gb[0]=value.c[1];gb[1]=value.c[2];
  ar+=2;gb+=2;
 }
}
extern "C" void cc41b_tile_rgba_801d7914(const unsigned char *source,int stride,int right,int bottom,int x,int y,unsigned char *tile) {
 unsigned height=bottom-y,width=right-x;
 if(height>4)height=4;
 if(width>4)width=4;
 for(unsigned row=0;row<height;++row) {
  unsigned char *ar=tile+row*8,*gb=tile+row*8+32;
  cc41b_row(x*4+source+stride*(row+y),width,ar,gb);
 }
}
