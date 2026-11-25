#include "w3d_ptr.h"
#line 1 "cx7a_detail_properties_read_800a5750.cpp"

// Resolve the named detail position/orientation fields, at +0x1c/+0x20.
struct Cx7aDetail { unsigned char unknown[0x1c]; unsigned int position,orientation; };
extern const char position_803811c8[],orientation_803811d8[];
extern "C" int property_800fc1b0(Ptr32<Ptr32<const char>>,Ptr32<unsigned int>);
extern "C" int refresh_800a57b0(Ptr32<Cx7aDetail>);
extern "C" void w3d_cx7a_detail_properties_read_800a5750(Ptr32<Cx7aDetail> self) { Ptr32<const char> position=position_803811c8; property_800fc1b0(&position,&self->position);Ptr32<const char> orientation=orientation_803811d8;property_800fc1b0(&orientation,&self->orientation);refresh_800a57b0(self); }


