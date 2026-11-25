
// Resolve the named detail position/orientation fields, at +0x1c/+0x20.
struct Cx7aDetail { unsigned char unknown[0x1c]; unsigned int position,orientation; };
extern const char position_803811c8[],orientation_803811d8[];
extern "C" int property_800fc1b0(const char **,unsigned int *);
extern "C" int refresh_800a57b0(Cx7aDetail *);
extern "C" void w3d_cx7a_detail_properties_read_800a5750(Cx7aDetail *self) { const char *position=position_803811c8; property_800fc1b0(&position,&self->position);const char *orientation=orientation_803811d8;property_800fc1b0(&orientation,&self->orientation);refresh_800a57b0(self); }
