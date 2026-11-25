// Original 0x802c4998. Observed layout and operations; role inferred.
struct Vec3 {float x,y,z;Vec3(float a,float b,float c):x(a),y(b),z(c){} };
struct Item {void **v;};
struct Owner {char pad[56];Item *item;int enabled;char pad40[180];void *source;char padf8[16];int index;};
extern "C" void *fn_80343580(void *);
extern "C" float fn_8018c8bc(void *);
extern "C" float fn_8018c938(void *,int,int);
extern float value_803d87e4[],scale_803d87e8[],offset_803d87ec[];
extern "C" void w3d_offset_item_vector_802c4998(Owner *self) {
 if(self->item) {
  Vec3 v(value_803d87e4[0],value_803d87e4[0],value_803d87e4[0]);
  void *source=fn_80343580(self->source);
  float scale=fn_8018c8bc(source);
  float x=fn_8018c938(source,0,self->index);
  v.x += x-scale*scale_803d87e8[0];v.x-=offset_803d87ec[0];
  ((void(*)(Item*,Vec3*,int))self->item->v[19])(self->item,&v,0);
  self->enabled=1;
 }
}
