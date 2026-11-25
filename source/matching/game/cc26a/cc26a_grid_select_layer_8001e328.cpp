// Original coordinate/layer selection, two layers.
typedef unsigned int cc26a_u32;
struct cc26a_VecE328 {float x,y,z;};
struct cc26a_GridE328 {unsigned char unknown[104];float spacing;unsigned char unknown108[8];cc26a_VecE328 origin;};
extern "C" float cc26a_hop_8001e2dc();
extern "C" float *cc26a_lower_8001e11c(cc26a_GridE328*,int,int,int);
extern "C" float *cc26a_upper_8001e1a0(cc26a_GridE328*,int,int,int);
inline float cc26a_absE328(float v){union {float f;cc26a_u32 u;} a;a.f=v;a.u&=0x7fffffff;return a.f;}
extern "C" int cc26a_grid_select_layer_8001e328(cc26a_GridE328 *self,const cc26a_VecE328 *point,short *x,short *z,cc26a_u32 *layer){
 int accepted=0,index=0;
 *x=(int)((point->x-self->origin.x)/self->spacing+0.5f);
 *z=(int)((point->z-self->origin.z)/self->spacing+0.5f);
 float height=cc26a_hop_8001e2dc();float nearest=1000000.0f;
 do{
  float lower=*cc26a_lower_8001e11c(self,*x,*z,index);
  float upper=*cc26a_upper_8001e1a0(self,*x,*z,index);
  float delta=cc26a_absE328((lower+upper)*0.5f-point->y);
  if(delta<nearest){*layer=index;nearest=delta;}
  if(upper-point->y<height && point->y-lower<height)accepted=1;
 }while(++index<=1);
 if(*layer>1)*layer=0;
 return accepted;
}
