#include "w3d_ptr.h"
#line 1 "cx16c_land_seed_refresh_80269f90.cpp"

// Original seed text uses a shared-string temporary and key/value stack pair.
struct Cx16cSeedText;
extern "C" Ptr32<void> cx16c_text_default_803426b8(Ptr32<Cx16cSeedText>);
extern "C" void cx16c_text_finish_8020c5c4(Ptr32<Cx16cSeedText>);
extern "C" void cx16c_text_release_80341588(Ptr32<Cx16cSeedText>);
struct Cx16cSeedText {
 Cx16cSeedText(const Cx16cSeedText &);
 Ptr32<const char> data;
 Cx16cSeedText() {}
 ~Cx16cSeedText() { cx16c_text_finish_8020c5c4(this);cx16c_text_release_80341588(this); }
};
struct Cx16cLand { char reserved[496]; int blocked; };
extern const char cx16c_seed_key_803cb8bc[];
extern const char cx16c_seed_format_803cb8d0[];
extern "C" int cx16c_seed_prepare_8026c54c(Ptr32<Cx16cLand>);
extern "C" int cx16c_seed_get_800fc230(Ptr32<Ptr32<const char>>,Ptr32<unsigned int>);
extern "C" int cx16c_seed_format_8020c510(Ptr32<Cx16cSeedText>,Ptr32<const char>,...);
extern "C" int cx16c_seed_set_8026c8a8(Ptr32<void>,Ptr32<const char>);
extern "C" int cx16c_land_state_8026c008(Ptr32<Cx16cLand>,int);
extern "C" int cx16c_land_refresh_8026bdf0(Ptr32<Cx16cLand>);
extern "C" int cx16c_land_notify_8026b3f0(Ptr32<Cx16cLand>);
extern "C" int w3d_cx16c_land_seed_refresh_80269f90(Ptr32<void>,Ptr32<Cx16cLand> self) {
 if(self->blocked) return 0;
 {
  Cx16cSeedText text;
  cx16c_seed_prepare_8026c54c(self);
  cx16c_text_default_803426b8(&text);
  Ptr32<const char> key=cx16c_seed_key_803cb8bc;
  unsigned seed;
  cx16c_seed_get_800fc230(&key,&seed);
  cx16c_seed_format_8020c510(&text,cx16c_seed_format_803cb8d0,seed);
  cx16c_seed_set_8026c8a8((Ptr32<char>)self+312,text.data);
  cx16c_land_state_8026c008(self,1);
  cx16c_land_refresh_8026bdf0(self);
  cx16c_land_notify_8026b3f0(self);
 }
 return 0;
}


