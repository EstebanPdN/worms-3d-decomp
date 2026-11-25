#include "w3d_ptr.h"
#line 1 "sol11a_target_clips_8004e5ac.cpp"
// External GC32 layouts; meanings of the observed clip slots are inferred.
struct Sol11aClipObject { unsigned char external_prefix[28]; Ptr32<void> mesh; unsigned char external_middle[24]; Ptr32<void> target; Ptr32<const char> resource; unsigned external_word; Ptr32<const char> clipA; Ptr32<const char> clipB; unsigned char external_tail[8]; int control; };
struct Sol11aServices { unsigned char external_prefix[108]; Ptr32<void> targets; };
extern Ptr32<Sol11aServices> services_804b1788;
extern const char no_target_803777b8[];
extern "C" int ready_8004e324(Ptr32<Sol11aClipObject>);
extern "C" int stop_801817e0(Ptr32<void>,int);
extern "C" int play_80181640(Ptr32<void>,Ptr32<const char>,Ptr32<int>,float,float,int,float);
extern "C" float scale_8004e544(Ptr32<Sol11aClipObject>,Ptr32<const char>,Ptr32<const char>);
extern "C" int check_8018179c(Ptr32<void>,int,int);
extern "C" void sol11a_target_clips_8004e5ac(Ptr32<Sol11aClipObject> self) {
 Ptr32<void> targets=services_804b1788->targets;
 ((Ptr32<void (Ptr32<void>, Ptr32<const char>, Ptr32<Ptr32<void>>)>)(*(Ptr32<Ptr32<void>>)(*(Ptr32<Ptr32<char>>)targets+92)))(targets,no_target_803777b8,&self->target);
 Ptr32<void> target=self->target;
 ((Ptr32<void (Ptr32<void>)>)(*(Ptr32<Ptr32<void>>)(*(Ptr32<Ptr32<char>>)target+20)))(target);
 if(ready_8004e324(self)) {
  int temporary;
  stop_801817e0(self->mesh,self->control);
  play_80181640(self->mesh,self->clipB,&temporary,1.0f,0.0f,0,0.0f);
  float scale=scale_8004e544(self,self->resource,self->clipB);
  play_80181640(self->mesh,self->clipA,&self->control,1.0f,scale,1,0.0f);
  check_8018179c(self->mesh,self->control,1);
 }
}


