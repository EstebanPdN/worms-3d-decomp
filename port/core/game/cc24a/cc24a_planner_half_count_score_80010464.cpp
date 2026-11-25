#include "w3d_ptr.h"
#line 1 "cc24a_planner_half_count_score_80010464.cpp"
// GWMP8P 0x80010464: half-count weighted score; signed division rounds toward zero.
struct cc24a_HalfScore {int unknown0;float cost;char unknown8[8];int index;char unknown20[44];unsigned char flagged;};
struct cc24a_HalfEntry {char unknown0[8];int owner;};
struct cc24a_HalfRange {Ptr32<Ptr32<cc24a_HalfEntry>> begin;};
struct cc24a_HalfConfig {char unknown0[420];float scale;};
extern "C" {extern Ptr32<cc24a_HalfRange> cc24a_entries_804aa750;extern Ptr32<cc24a_HalfConfig> cc24a_config_804aa6d8;extern float cc24a_base_8036a120[],cc24a_flag_8036a124[];
 void cc24a_reset_8000b2f8(Ptr32<cc24a_HalfScore>,int),cc24a_exposure_8000b7dc(Ptr32<cc24a_HalfScore>);
 int cc24a_count_800155ac(int);
 float cc24a_weighted_8000b344(Ptr32<cc24a_HalfScore>,int,float,float);
}
extern "C" void cc24a_planner_half_count_score_80010464(Ptr32<cc24a_HalfScore> self){
 cc24a_reset_8000b2f8(self,1);
 int index=self->index;
 Ptr32<cc24a_HalfEntry> entry=*(Ptr32<Ptr32<cc24a_HalfEntry>>)((Ptr32<char>)cc24a_entries_804aa750->begin+(index<<2));
 int half=cc24a_count_800155ac(entry->owner)/2;
 self->cost+=cc24a_weighted_8000b344(self,index,cc24a_base_8036a120[0],(float)half);
 cc24a_exposure_8000b7dc(self);
 self->cost*=cc24a_config_804aa6d8->scale;
 if(self->flagged)self->cost*=cc24a_flag_8036a124[0];
}


