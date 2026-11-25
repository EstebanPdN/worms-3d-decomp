#include "w3d_ptr.h"
#line 1 "cx8c_copy_settings.cpp"
/* Observed field offsets, sizes, and call addresses; all semantic names inferred. */
struct Cx8cSettings {unsigned int words[8];};
struct Cx8cOwner {unsigned char unknown[116];Cx8cSettings settings;};
extern "C" int w3d_cx8c_copy_settings_80349a48(Ptr32<Cx8cOwner> self,Ptr32<const Cx8cSettings> value) {self->settings=*value;return 0;}


