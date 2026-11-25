// Partial layout and semantic roles inferred.
struct Vec3 {float x,y,z;Vec3(float a,float b,float c):x(a),y(b),z(c){}void set(float a,float b,float c){x=a;y=b;z=c;}};
struct Item {void **v;};struct Owner {char pad[64];Item *item;int active;float x,y;int mode;char pad54[44];float scale;};
extern float value_803d8e1c[],value_803d8e20[],value_803d8e24[];
extern "C" void w3d_set_panel_vectors_802c7d24(Owner*self) {
 if(self->active && self->item){
  float zero=value_803d8e1c[0];
  Vec3 v(self->x,self->y,zero);
  ((void(*)(Item*,Vec3*,int))self->item->v[19])(self->item,&v,0);
  float factor,x;
  if(self->mode==1){x=self->scale*value_803d8e20[0];factor=self->scale;}
  else{x=zero-self->scale*value_803d8e20[0];factor=self->scale;}
  v.set(x,factor*value_803d8e20[0],value_803d8e24[0]);
  ((void(*)(Item*,Vec3*,int))self->item->v[21])(self->item,&v,0);
 }
}
