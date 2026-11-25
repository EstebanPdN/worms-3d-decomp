#include "w3d_ptr.h"
#line 1 "cx12b_child_scale_update_802c629c.cpp"
struct Vec3{float x,y,z;inline void set(float a,float b,float c){x=a;y=b;z=c;}};
struct Service;struct Vtable{Ptr32<void> unused[19];Ptr32<void (Ptr32<Service>, Ptr32<Vec3>, int)> position;Ptr32<void> gap[1];Ptr32<void (Ptr32<Service>, Ptr32<Vec3>, int)> scale;};struct Service{Ptr32<Vtable> vtable;};
struct Owner{unsigned char opaque[28];Ptr32<Service> child;int state,mode,unused40,count;Ptr32<Service> a; Ptr32<Service> b; Ptr32<Service> c;Vec3 position;float x,y;int extra;};

extern "C" float multiplier_803d8d1c[],z_803d8d20[];
extern "C" void w3d_cx12b_child_scale_update_802c629c(Ptr32<Owner> self,float x,float y){if(self->x!=x||self->y!=y){self->x=x;self->y=y;if(self->mode==1){Vec3 scale;scale.set(x*multiplier_803d8d1c[0],y*multiplier_803d8d1c[0],z_803d8d20[0]);if(self->a)self->a->vtable->scale(self->a,&scale,0);if(self->b)self->b->vtable->scale(self->b,&scale,0);if(self->c)self->c->vtable->scale(self->c,&scale,0);}}}




