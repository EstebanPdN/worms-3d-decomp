// External GC32 layouts; meanings of the observed clip slots are inferred.
struct Sol11aClipObject { unsigned char external_prefix[28]; void *mesh; unsigned char external_middle[24]; void *target; const char *resource; unsigned external_word; const char *clipA; const char *clipB; unsigned char external_tail[8]; int control; };
struct Sol11aServices { unsigned char external_prefix[108]; void *targets; };
extern Sol11aServices *services_804b1788;
extern const char no_target_803777b8[];
extern "C" int ready_8004e324(Sol11aClipObject *);
extern "C" int stop_801817e0(void *,int);
extern "C" int play_80181640(void *,const char *,int *,float,float,int,float);
extern "C" float scale_8004e544(Sol11aClipObject *,const char *,const char *);
extern "C" int check_8018179c(void *,int,int);
extern "C" void sol11a_target_clips_8004e5ac(Sol11aClipObject *self) {
 void *targets=services_804b1788->targets;
 ((void (*)(void *,const char *,void **))(*(void **)(*(char **)targets+92)))(targets,no_target_803777b8,&self->target);
 void *target=self->target;
 ((void (*)(void *))(*(void **)(*(char **)target+20)))(target);
 if(ready_8004e324(self)) {
  int temporary;
  stop_801817e0(self->mesh,self->control);
  play_80181640(self->mesh,self->clipB,&temporary,1.0f,0.0f,0,0.0f);
  float scale=scale_8004e544(self,self->resource,self->clipB);
  play_80181640(self->mesh,self->clipA,&self->control,1.0f,scale,1,0.0f);
  check_8018179c(self->mesh,self->control,1);
 }
}
