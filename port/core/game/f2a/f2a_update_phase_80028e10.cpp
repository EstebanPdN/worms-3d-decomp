#include "w3d_ptr.h"
#line 1 "f2a_update_phase_80028e10.cpp"
// Original entry 0x80028e10; phase and field meanings are inferred.
// The unused vector preserves the frame reservation observed around conversions.
struct Vec{float x,y,z;Vec(){}};
struct Obj {char p[28];int state;unsigned start;char q[12];float output;char r[24];float origin;char s[8];Ptr32<void> a; Ptr32<void> b;char t[12];Ptr32<void> duration;};
extern "C" {int fn_80178c48(Ptr32<void>);float fn_80178df0(Ptr32<void>);float fn_802e88ac(float);extern float lbl_8036cec8[],lbl_8036cecc[],lbl_8036ced0[],lbl_8036ced4[],lbl_8036ced8[];
void w3d_f2a_update_phase_80028e10(Ptr32<Obj> p,int choose,unsigned now){Vec reservation;unsigned elapsed=now-p->start;int duration=fn_80178c48(p->duration);float phase=(float)elapsed/(float)duration;float angle=phase*lbl_8036cec8[0];fn_802e88ac(angle*lbl_8036cecc[0]);float weight=fn_802e88ac(angle*lbl_8036ced0[0]+lbl_8036ced4[0]);if(phase>lbl_8036ced8[0]){switch(p->state){case 3:p->state=0;p->output=fn_80178df0(p->b);break;case 2:p->state=1;p->output=fn_80178df0(p->a);break;}}float target=fn_80178df0(choose?w3d::R(p->b):w3d::R(p->a));float from=p->origin;p->output=(target-from)*weight+from;}}


