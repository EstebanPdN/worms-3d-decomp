// Original incremental grid cell sampling with previous-layer terminal inheritance.
struct cc27a_VecE590 {float x,y,z;};
struct cc27a_GridE590 {char unknown[104];float spacing,sentinel;char unknown112[4];cc27a_VecE590 minimum,maximum;unsigned int unknown140;float height;int restart;};
extern float cc27a_drop_804aa78c,cc27a_step_804aa790;
extern "C" unsigned char*cc27a_byte_8001dff8(cc27a_GridE590*,int,int,int);
extern "C" float*cc27a_low_8001e11c(cc27a_GridE590*,int,int,int);
extern "C" float*cc27a_high_8001e1a0(cc27a_GridE590*,int,int,int);
extern "C" int cc27a_sample_8001e7e0(cc27a_GridE590*,const cc27a_VecE590*,const cc27a_VecE590*,float*,float*,unsigned char*);
extern "C" float cc27a_hop_8001e2dc(cc27a_GridE590*);
extern "C" int cc27a_grid_sample_cell_8001e590(cc27a_GridE590*self,int x,int z,int layer){
 struct {cc27a_VecE590 origin;unsigned int unknown20;cc27a_VecE590 direction;unsigned int unknown36;unsigned char flag;char unknown41[3];float low,high;char unknown52[8];} w;
 if(layer>0 && *cc27a_byte_8001dff8(self,x,z,layer-1)==1){
  *cc27a_low_8001e11c(self,x,z,layer)=self->sentinel;
  *cc27a_high_8001e1a0(self,x,z,layer)=self->sentinel;
  *cc27a_byte_8001dff8(self,x,z,layer)=1;
 }else{
  w.origin.x=(float)x*self->spacing+self->minimum.x;
  w.origin.z=(float)z*self->spacing+self->minimum.z;
  if(self->restart){w.origin.y=self->maximum.y+cc27a_step_804aa790;self->restart=0;w.origin.y-=cc27a_drop_804aa78c;}
  else w.origin.y=self->height;
  w.direction.x=0.0f;w.direction.z=0.0f;w.direction.y=(self->minimum.y-(cc27a_step_804aa790+cc27a_step_804aa790)-w.origin.y)*0.001f;
  if(cc27a_sample_8001e7e0(self,&w.origin,&w.direction,&w.low,&w.high,&w.flag)){
   *cc27a_low_8001e11c(self,x,z,layer)=w.low;
   *cc27a_high_8001e1a0(self,x,z,layer)=w.high;
   *cc27a_byte_8001dff8(self,x,z,layer)=w.flag;
   float gap=w.high-w.low;if(gap>cc27a_hop_8001e2dc(self))*cc27a_byte_8001dff8(self,x,z,layer)=3;
   self->height=w.low-cc27a_step_804aa790;
  }else{self->height-=cc27a_step_804aa790;return 0;}
 }
 return 1;
}