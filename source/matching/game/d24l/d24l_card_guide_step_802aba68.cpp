// GWMP8P rev0 0x802aba68, ./NGC/memguideinit.c: card guide state machine step.
extern "C" int w3d_card_status_802abfdc(int);
struct Guide { int card; int state; int result; int status; int pad16; int phase; int pad24; int a28; char pad32[28]; int a60; char pad64[116]; int a180; char pad184[240]; int a424; };
extern "C" void w3d_cc17d_desc_setup_802abc28(Guide *), w3d_s4_memguide_probe_step(Guide *), w3d_check_card_802abd94(Guide *), w3d_auto_802abedc(Guide *), w3d_auto_802abf58(Guide *);
extern "C" void OSPanic(const char *, int, const char *, ...);
extern "C" int d24l_card_guide_step_802aba68(Guide *self, int value)
{
 int s = w3d_card_status_802abfdc(self->card);
 if (self->status != (int)0xdeadf00d && s != self->status) self->status = s;
 self->a28 = value;
 self->a60 = value;
 self->a424 = value;
 self->a180 = value;
 switch (self->state) {
 case 160: w3d_cc17d_desc_setup_802abc28(self); break;
 case 161: w3d_s4_memguide_probe_step(self); break;
 case 162: w3d_check_card_802abd94(self); break;
 case 163: w3d_auto_802abedc(self); break;
 case 164: w3d_auto_802abf58(self); break;
 case 1: self->state = 160; self->phase = 0; return 1;
 case 3: self->state = 160; self->phase = 0; return 3;
 case 4: self->state = 160; self->phase = 0; return 4;
 case 0: self->state = 160; self->phase = 0; return 0;
 case 2:  self->phase = 0; self->state = 161; self->status = 0;  return 2;
 default: OSPanic("./NGC/memguideinit.c", 264, "Illegal state in CARDGuide1Init\n"); return 0;
 }
  if (self->result >= 0) return -1;
 return self->result; 
}
