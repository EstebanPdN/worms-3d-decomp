// GWMP8P 0x80011950: damage score with lethal-hit bonus. Names inferred.
struct cc24a_DamageScore { int unknown0;float cost;char unknown8[56];unsigned char flagged; };
struct cc24a_DamageConfig {char unknown0[88];float widthScale,rangeScale;char unknown96[324];float damageScale;};
struct cc24a_DamageEntry {char unknown0[28];int health;};
struct cc24a_DamageEntries {cc24a_DamageEntry **begin;};
struct cc24a_DamageName {const char *text;};
extern cc24a_DamageConfig *cc24a_config_804aa6d8;
extern cc24a_DamageEntries *cc24a_entries_804aa750;
extern int cc24a_index_804aa6e8;
extern char cc24a_death_name_8036a358[];
extern float cc24a_flag_factor_8036a380[];
extern "C" void cc24a_reset_8000b2f8(cc24a_DamageScore*,int),cc24a_exposure_8000b7dc(cc24a_DamageScore*);
extern "C" int cc24a_float_property_800fc270(cc24a_DamageName*,float*);
extern "C" float cc24a_sum_8000b4c4(cc24a_DamageScore*,float,float,float,float);
extern "C" void cc24a_planner_damage_score_80011950(cc24a_DamageScore *self,float damage,float range){
 cc24a_reset_8000b2f8(self,1);
 if(cc24a_index_804aa6e8!=-1){
  cc24a_DamageEntry *entry=*(cc24a_DamageEntry**)((char*)cc24a_entries_804aa750->begin+(cc24a_index_804aa6e8<<2));
  if(damage>=(float)entry->health){// Preserve the original sixteen unused workspace bytes; source purpose unknown.
 struct cc24a_DamageWorkspace {cc24a_DamageName name;float bonus;unsigned char unknown[16];} work;work.name.text=cc24a_death_name_8036a358;cc24a_float_property_800fc270(&work.name,&work.bonus);damage+=work.bonus;}
 }
 self->cost+=cc24a_sum_8000b4c4(self,range,cc24a_config_804aa6d8->rangeScale,cc24a_config_804aa6d8->widthScale,damage);
 cc24a_exposure_8000b7dc(self);
 self->cost*=cc24a_config_804aa6d8->damageScale;
 if(self->flagged)self->cost*=cc24a_flag_factor_8036a380[0];
}
