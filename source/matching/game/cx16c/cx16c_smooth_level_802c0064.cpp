
// Observed target/current scalars at +24/+28; constant identities from DOL.
struct Cx16cLevel { char reserved[24]; float target; float current; };
extern float cx16c_factor_803d8428[];
extern float cx16c_one_803d842c[];
extern float cx16c_upper_803d8430[];
extern float cx16c_lower_803d8434[];
extern "C" void cx16c_refresh_802bfc64(Cx16cLevel*);
extern "C" void w3d_cx16c_smooth_level_802c0064(Cx16cLevel *self) {
 float target=self->target,current=self->current;
 if(target!=current) {
  float factor=cx16c_factor_803d8428[0];
  float upper=cx16c_upper_803d8430[0];
  float next=current*(cx16c_one_803d842c[0]-factor)+target*factor;
  float delta=target-next;
  self->current=next;
  if(delta<upper && delta>cx16c_lower_803d8434[0]) self->current=target;
  cx16c_refresh_802bfc64(self);
 }
}
