#include "w3d_ptr.h"
#line 1 "cc24a_planner_named_score_8000da8c.cpp"
// Original 0x8000da8c: ordered single-precision plan-score accumulation.
struct cc24a_NamedScore { int unknown0; float cost; char unknown8[56]; unsigned char flagged; char unknown65[35]; float weight; bool flag()const{return flagged!=0;} };
struct cc24a_ScoreConfig { char unknown0[80]; float modeScale; char unknown84[8]; float rangeScale; char unknown96[332]; float namedScale; char unknown432[44]; float flaggedScale; };
struct cc24a_NameLookup { char unknown0[320]; int enabled; };
extern Ptr32<cc24a_ScoreConfig> cc24a_config_804aa6d8;
extern float cc24a_constant_80369eb8[];
extern "C" void cc24a_reset_8000b2f8(Ptr32<cc24a_NamedScore>,int);
extern "C" float cc24a_damage_8000d99c(Ptr32<cc24a_NamedScore>),cc24a_range_8000da0c(Ptr32<cc24a_NamedScore>),cc24a_count_8000da34(Ptr32<cc24a_NamedScore>);
extern "C" float cc24a_sum_8000b4c4(Ptr32<cc24a_NamedScore>,float,float,float,float),cc24a_distance_8000b5f4(Ptr32<cc24a_NamedScore>,float);
extern "C" Ptr32<cc24a_NameLookup> cc24a_lookup_80341710(Ptr32<cc24a_NamedScore>,int);
extern "C" void cc24a_exposure_8000b7dc(Ptr32<cc24a_NamedScore>);
extern "C" void cc24a_planner_named_score_8000da8c(Ptr32<cc24a_NamedScore> self){
 cc24a_reset_8000b2f8(self,0);
 float damage=cc24a_damage_8000d99c(self);
 float range=cc24a_range_8000da0c(self);
 self->cost+=cc24a_sum_8000b4c4(self,range,cc24a_config_804aa6d8->rangeScale,cc24a_constant_80369eb8[0],damage);
 self->cost+=cc24a_distance_8000b5f4(self,cc24a_count_8000da34(self));
 if(cc24a_lookup_80341710(self,0)->enabled){self->cost*=cc24a_config_804aa6d8->modeScale;if(self->flag()) self->cost*=cc24a_config_804aa6d8->flaggedScale;}
 cc24a_exposure_8000b7dc(self);
 self->cost=self->cost*cc24a_config_804aa6d8->namedScale*self->weight;
}


