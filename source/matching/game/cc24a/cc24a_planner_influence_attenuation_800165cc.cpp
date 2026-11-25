// GWMP8P 0x800165cc: sum positive field influences and attenuate the supplied value.
struct cc24a_Influence;struct cc24a_InfluencePlan;struct cc24a_InfluenceVec {float x,y,z;};
struct cc24a_InfluenceRange {cc24a_Influence **begin,**end;int size(){return end-begin;}};
struct cc24a_InfluenceConfig {char unknown0[280];float scale;};
extern "C" {extern cc24a_InfluenceRange *cc24a_entries_804aa6fc;extern cc24a_InfluenceConfig *cc24a_config_804aa6d8;extern cc24a_InfluenceVec cc24a_origin_8041d3a0[];extern float cc24a_zero_8036a674[],cc24a_one_8036a678[];
 float cc24a_influence_800167ac(cc24a_Influence*,cc24a_InfluencePlan*,const cc24a_InfluenceVec*);
}
extern "C" float cc24a_planner_influence_attenuation_800165cc(float value,cc24a_InfluencePlan *plan){
 // Original extra stack extent is observed; source purpose unknown.
 float total=0.0f;
 const cc24a_InfluenceVec &origin=cc24a_origin_8041d3a0[0];
 for(int i=0;i<cc24a_entries_804aa6fc->size();++i){
  cc24a_Influence *entry=*(cc24a_Influence**)((char*)cc24a_entries_804aa6fc->begin+(i<<2));
  float weight=cc24a_influence_800167ac(entry,plan,&origin);
  if(weight>0.0f)total+=weight;
 }
 if(total>0.0f)return value/(cc24a_config_804aa6d8->scale*total+1.0f);
 return value;
}
