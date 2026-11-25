#include "w3d_ptr.h"
#line 1 "f3a_phase_8026d19c.cpp"
// Observed three-float payload with forty reserved frame bytes; original type is unknown.
struct Vec3 { float x,y,z; float reserved[10]; Vec3(float a,float b,float c):x(a),y(b),z(c) {} void set(float a,float b,float c){x=a;y=b;z=c;} };
struct Object { Ptr32<Ptr32<void>> vt; };
struct State { char pad[72]; Ptr32<Object> first; Ptr32<Object> second; int unused,time; };
extern const float step_803cbd04[],limit_803cbd08[],reset_803cbd0c[],zero_803cbd10[],offset_803cbd14[];
extern float phase_804abb80,phase_804abb84;
inline void apply(Ptr32<Object> o,Ptr32<Vec3> p) { ((Ptr32<void (Ptr32<Object>, Ptr32<Vec3>, int)>)o->vt[20])(o,p,0); }
extern "C" int w3d_f3a_phase_8026d19c(Ptr32<State> s,int time) {
 int ticks=time-s->time;
 if(ticks>100) ticks=100;
 if(ticks>19) {
 float step=step_803cbd04[0],limit=limit_803cbd08[0],reset=reset_803cbd0c[0],zero=zero_803cbd10[0],offset=offset_803cbd14[0];
 do {
  phase_804abb80+=step; phase_804abb84+=step;
  if(phase_804abb80>limit)phase_804abb80=reset;
  if(s->first) {
   Vec3 p(zero,phase_804abb84,zero); apply(s->first,&p);
   p.set(offset,zero,zero);
   if(s->second)apply(s->second,&p);
  }
  ticks-=20;
 } while(ticks>19);
 }
 s->time=time-ticks;return 0;
}


