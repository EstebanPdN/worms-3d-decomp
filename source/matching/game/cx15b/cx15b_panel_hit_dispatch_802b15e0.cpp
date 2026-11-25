// Inferred UI names; observed PPC32 layout uses four-byte pointers. Float vectors and matrices retain original member offsets.
typedef unsigned int u32;typedef unsigned char u8;
#define FIELD(p,T,o) (*(T *)((char *)(p)+(o)))
struct Vec{float x,y,z;inline Vec(float a,float b,float c):x(a),y(b),z(c){}inline Vec(const Vec&o){float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;}inline Vec operator+(const Vec&o)const{return Vec(x+o.x,y+o.y,z+o.z);}};
extern "C" {extern int mode_804abb4c;}
extern "C" int w3d_cx15b_panel_hit_dispatch_802b15e0(float x,float y,void *self){if(FIELD(self,int,112)&&(FIELD(self,int,160)||mode_804abb4c!=1)){void *bounds=FIELD(self,void *,12);Vec center=FIELD(bounds,Vec,32),extent=FIELD(bounds,Vec,20);if(x>=center.x-extent.x&&x<=center.x+extent.x&&y>=center.y-extent.y&&y<=center.y+extent.y){((void (*)(void *))FIELD(FIELD(self,void *,180),void *,56))(self);return 1;}}return 0;}

