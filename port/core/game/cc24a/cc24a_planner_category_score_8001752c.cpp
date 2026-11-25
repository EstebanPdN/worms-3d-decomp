#include "w3d_ptr.h"
#line 1 "cc24a_planner_category_score_8001752c.cpp"
// GWMP8P 0x8001752c: apply pickup/category-specific scoring. Role names inferred.
struct cc24a_CategoryEntry {char unknown0[28];int kind;};
struct cc24a_CategoryScore {int unknown0;float cost;char unknown8[36];Ptr32<cc24a_CategoryEntry> entry;float fallbackScale;};
struct cc24a_CategoryConfig {char unknown0[44];float kind0Scale;char unknown48[148];float countThreshold;char unknown200[4];float kind2Scale;float ownerScale;float kind1Scale;char unknown216[4];float initialBonus;};
struct cc24a_CategoryOwner {char unknown0[136];int active;};
extern "C" {extern Ptr32<cc24a_CategoryConfig> cc24a_config_804aa6d8;extern int cc24a_owner_804aa6c0;
 void cc24a_falloff_80017380(Ptr32<cc24a_CategoryScore>);Ptr32<cc24a_CategoryOwner> cc24a_owner_query_80015540();int cc24a_count_800155ac(int);
}
extern "C" void cc24a_planner_category_score_8001752c(Ptr32<cc24a_CategoryScore> self){
 self->cost+=cc24a_config_804aa6d8->initialBonus;
 cc24a_falloff_80017380(self);
 if(self->entry){switch(self->entry->kind){
 case 0:self->cost*=cc24a_config_804aa6d8->kind0Scale;break;
 case 1:{self->cost*=cc24a_config_804aa6d8->kind1Scale;
  if(cc24a_owner_query_80015540()->active)self->cost*=cc24a_config_804aa6d8->ownerScale;
  int count=cc24a_count_800155ac(cc24a_owner_804aa6c0);
  if(count>0 && (float)count<=cc24a_config_804aa6d8->countThreshold)self->cost*=cc24a_config_804aa6d8->countThreshold/(float)count;
  break;}
 case 2:self->cost*=cc24a_config_804aa6d8->kind2Scale;break;
 }}else self->cost*=self->fallbackScale;
}


