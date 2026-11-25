
// Original seed text uses a shared-string temporary and key/value stack pair.
struct Cx16cSeedText;
extern "C" void * cx16c_text_default_803426b8(Cx16cSeedText*);
extern "C" void cx16c_text_finish_8020c5c4(Cx16cSeedText*);
extern "C" void cx16c_text_release_80341588(Cx16cSeedText*);
struct Cx16cSeedText {
 Cx16cSeedText(const Cx16cSeedText &);
 const char *data;
 Cx16cSeedText() {}
 ~Cx16cSeedText() { cx16c_text_finish_8020c5c4(this);cx16c_text_release_80341588(this); }
};
struct Cx16cLand { char reserved[496]; int blocked; };
extern const char cx16c_seed_key_803cb8bc[];
extern const char cx16c_seed_format_803cb8d0[];
extern "C" int cx16c_seed_prepare_8026c54c(Cx16cLand*);
extern "C" int cx16c_seed_get_800fc230(const char**,unsigned*);
extern "C" int cx16c_seed_format_8020c510(Cx16cSeedText*,const char*,...);
extern "C" int cx16c_seed_set_8026c8a8(void*,const char*);
extern "C" int cx16c_land_state_8026c008(Cx16cLand*,int);
extern "C" int cx16c_land_refresh_8026bdf0(Cx16cLand*);
extern "C" int cx16c_land_notify_8026b3f0(Cx16cLand*);
extern "C" int w3d_cx16c_land_seed_refresh_80269f90(void*,Cx16cLand *self) {
 if(self->blocked) return 0;
 {
  Cx16cSeedText text;
  cx16c_seed_prepare_8026c54c(self);
  cx16c_text_default_803426b8(&text);
  const char *key=cx16c_seed_key_803cb8bc;
  unsigned seed;
  cx16c_seed_get_800fc230(&key,&seed);
  cx16c_seed_format_8020c510(&text,cx16c_seed_format_803cb8d0,seed);
  cx16c_seed_set_8026c8a8((char*)self+312,text.data);
  cx16c_land_state_8026c008(self,1);
  cx16c_land_refresh_8026bdf0(self);
  cx16c_land_notify_8026b3f0(self);
 }
 return 0;
}
