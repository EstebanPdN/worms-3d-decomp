#include "w3d_ptr.h"
#line 1 "cc17a_refresh_label_80048fcc.cpp"
// Observed held HUD at +68, marker at +28, marker mode at +148.
struct Cc17aVec3{float x,y,z;Cc17aVec3(){}Cc17aVec3(const Cc17aVec3&o,float d){float a=o.x,b=o.y+d,c=o.z;x=a;z=c;y=b;}Cc17aVec3(float a,float b,float c){x=a;y=b;z=c;}};
struct Cc17aColor{unsigned char r,g,b,a;Cc17aColor(unsigned char x,unsigned char y,unsigned char z,unsigned char w){r=x;g=y;b=z;a=w;}};
struct Cc17aHud;struct Cc17aVtable{Ptr32<void (void)> unknown[10];Ptr32<void (Ptr32<Cc17aHud>, Ptr32<const Cc17aVec3>)> position;Ptr32<void (Ptr32<Cc17aHud>, int)> mode;};
struct Cc17aHud{Ptr32<Cc17aVtable> vtable;};struct Cc17aMarker{char pad[40];Cc17aVec3 position;char pad34[96];int mode;};struct Cc17aLabel{char pad[20];unsigned owner;int unknown;Ptr32<void> marker;char pad20[36];Ptr32<void> hud;void cc17a_refresh();};
extern char service_80410a10[];extern const float offset_8037673c[];extern unsigned style_804af3b4;extern Ptr32<void> context_804b178c;
extern "C" Ptr32<void> service_8020b680(Ptr32<void>); Ptr32<void> lookup_80164fc8(Ptr32<void>); Ptr32<void> dispatch_80164514(Ptr32<void>,Ptr32<void>,unsigned);extern "C" void publish_8011adf8(Ptr32<Cc17aHud>,Ptr32<const Cc17aColor>,Ptr32<const void>);
inline void Cc17aLabel::cc17a_refresh(){Ptr32<Cc17aLabel> self=this;if(!self->hud){Ptr32<void> service=service_8020b680(service_80410a10);self->hud=dispatch_80164514(context_804b178c,service,self->owner);}Ptr32<Cc17aHud> h=(Ptr32<Cc17aHud>)lookup_80164fc8(self->hud);Ptr32<Cc17aMarker> m=(Ptr32<Cc17aMarker>)lookup_80164fc8(self->marker);Cc17aColor c(200,200,200,255);publish_8011adf8(h,&c,&style_804af3b4);h->vtable->mode(h,m->mode);Cc17aVec3 position(m->position,offset_8037673c[0]);h->vtable->position(h,&position);}

extern "C" void w3d_cc17a_refresh_label_80048fcc(Ptr32<Cc17aLabel> self){self->cc17a_refresh();}


