// Original 0x802c7d24. Three float local components are witnessed by stores and callbacks.
// Original constants independently decoded: 803d8e1c=0, 803d8e20=0.5, 803d8e24=1.
// Partial views only. No object-size or referenced data ownership claim.
struct cc41b_VisualVector { float x,y,z; cc41b_VisualVector(float a,float b,float c):x(a),y(b),z(c){} void set(float a,float b,float c){x=a;y=b;z=c;} };
struct cc41b_Visual;
struct cc41b_VisualVtable { void *unknown[19]; void (*position)(cc41b_Visual *,const cc41b_VisualVector &,int); void *unknown50; void (*scale)(cc41b_Visual *,const cc41b_VisualVector &,int); };
struct cc41b_Visual { cc41b_VisualVtable *vtable; };
struct cc41b_VisualOwner { unsigned char unknown[64]; cc41b_Visual *visual; int enabled; float x,y; int mode; unsigned char gap[44]; float size; };
extern float cc41b_visualZero_803d8e1c[],cc41b_visualHalf_803d8e20[],cc41b_visualOne_803d8e24[];
extern "C" void cc41b_update_visual_802c7d24(cc41b_VisualOwner *self) {
 if(self->enabled && self->visual) {
  float zero=cc41b_visualZero_803d8e1c[0];
  self->visual->vtable->position(self->visual,cc41b_VisualVector(self->x,self->y,zero),0);
  float x;
  if(self->mode==1)x=self->size*cc41b_visualHalf_803d8e20[0];
  else x=zero-self->size*cc41b_visualHalf_803d8e20[0];
  self->visual->vtable->scale(self->visual,cc41b_VisualVector(x,self->size*cc41b_visualHalf_803d8e20[0],cc41b_visualOne_803d8e24[0]),0);
 }
}
