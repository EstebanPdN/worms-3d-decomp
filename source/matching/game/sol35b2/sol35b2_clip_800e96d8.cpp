// Native clip-rate setup from the instructions at 800e96d8.
// Complete type identities, member names and semantics are inferred.
// The rate and cap are real local floats whose addresses are selected by a
// reference-return minimum. This preserves the observed unordered-compare
// behavior and temporary lifetimes without fabricated stack storage.
// The empty-text test compares original pointer identity, not string content.
// duration is a genuine native out parameter: the external lookup must write
// it for the requested name. An unwritten value is outside this source's
// defined-input contract. The clip output is passed onward and not read here.
struct Sol35b2ClipOwner {char unknown[28];int sync;void *mesh;};
struct Sol35b2ClipConfig {char unknown[228];int service;};
struct Sol35b2ClipName {const char *text;};
extern char sol35b2_empty_8038b1f8[];
extern const float sol35b2_rate_scale_8038b288[],sol35b2_rate_cap_8038b28c[],sol35b2_blend_8038b290[];
extern "C" void * sol35b2_sync_80341584(int);
extern "C" Sol35b2ClipConfig *sol35b2_config_801797b4(void *);
extern "C" void *sol35b2_service_8015ae3c(int *);
extern "C" void *sol35b2_identity_80341348(void *);
extern "C" int sol35b2_duration_8017fc90(void *,const char *,float *);
extern "C" int sol35b2_play_80181640(void *,const char *,int *,int,float,float,float);
inline const float &sol35b2_min(const float &a,const float &b) {return b<a?b:a;}
extern "C" void sol35b2_clip_800e96d8(Sol35b2ClipOwner *s,unsigned ticks,const Sol35b2ClipName *name) {
 if(name->text!=sol35b2_empty_8038b1f8) {Sol35b2ClipConfig *config=sol35b2_config_801797b4((void *)sol35b2_sync_80341584(s->sync));
  void *service=sol35b2_identity_80341348(sol35b2_service_8015ae3c(&config->service));
  float duration;sol35b2_duration_8017fc90(service,name->text,&duration);
  float rate=(float)ticks/(duration*sol35b2_rate_scale_8038b288[0]);
  float cap=sol35b2_rate_cap_8038b28c[0];
  const float &limited=sol35b2_min(rate,cap);
  int clip;
  sol35b2_play_80181640(s->mesh,name->text,&clip,0,limited,sol35b2_blend_8038b290[0],sol35b2_blend_8038b290[0]);
 }
}
