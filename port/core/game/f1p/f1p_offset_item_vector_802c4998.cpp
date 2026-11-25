#include "w3d_ptr.h"
#line 1 "f1p_offset_item_vector_802c4998.cpp"
// Original 0x802c4998. Observed layout and operations; role inferred.
struct Vec3 {float x,y,z;Vec3(float a,float b,float c):x(a),y(b),z(c){} };
struct Item {Ptr32<Ptr32<void>> v;};
struct Owner {char pad[56];Ptr32<Item> item;int enabled;char pad40[180];Ptr32<void> source;char padf8[16];int index;};
extern "C" Ptr32<void> fn_80343580(Ptr32<void>);
extern "C" float fn_8018c8bc(Ptr32<void>);
extern "C" float fn_8018c938(Ptr32<void>,int,int);
extern float value_803d87e4[],scale_803d87e8[],offset_803d87ec[];
extern "C" void w3d_offset_item_vector_802c4998(Ptr32<Owner> self) {
 if(self->item) {
  Vec3 v(value_803d87e4[0],value_803d87e4[0],value_803d87e4[0]);
  Ptr32<void> source=fn_80343580(self->source);
  float scale=fn_8018c8bc(source);
  float x=fn_8018c938(source,0,self->index);
  v.x += x-scale*scale_803d87e8[0];v.x-=offset_803d87ec[0];
  ((Ptr32<void (Ptr32<Item>, Ptr32<Vec3>, int)>)self->item->v[19])(self->item,&v,0);
  self->enabled=1;
 }
}


