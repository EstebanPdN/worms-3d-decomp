// Original 0x801d7914. Four-byte RGBA input is split into GameCube AR/GB planes.
// Bounds clamp unsigned differences to four; original row stride and partial tile writes are retained.
struct cc41b_RGBA { unsigned char r,g,b,a; cc41b_RGBA(const unsigned char *p):r(p[0]),g(p[1]),b(p[2]),a(p[3]){} };
extern "C" void cc41b_tile_rgba_801d7914(const unsigned char *source,int stride,int right,int bottom,int x,int y,unsigned char *tile) {
 unsigned height=bottom-y,width=right-x;
 if(height>4)height=4;
 if(width>4)width=4;
 for(unsigned row=0;row<height;++row) {
  unsigned char *ar=tile+row*8,*gb=tile+row*8+32;
  const unsigned char *pixel=source+x*4+stride*(row+y);
  for(unsigned col=0;col<width;++col) {
   cc41b_RGBA value(pixel);pixel+=4;
   ar[0]=value.a;ar[1]=value.r;gb[0]=value.g;gb[1]=value.b;
   ar+=2;gb+=2;
  }
 }
}
