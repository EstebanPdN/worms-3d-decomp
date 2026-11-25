// Original 0x8001b830: bounded probe and horizontal hit-position cache.
struct cc25a_Vector1b830 {unsigned int x,y,z;};
extern float cc25a_limit_8036b054[],cc25a_margin_8036b060[];
extern cc25a_Vector1b830 cc25a_hit_8043ae20[],cc25a_position_8041e85c[],cc25a_probe_8041e780[];
extern unsigned int cc25a_hit_distance_804b1764;
extern float cc25a_cached_distance_804b1780;
extern "C" void cc25a_trace_800b0824(cc25a_Vector1b830*,const cc25a_Vector1b830*,cc25a_Vector1b830*,int,int);
extern "C" int cc25a_planner_trace_distance_8001b830(const cc25a_Vector1b830 *direction,float distance){
 if(distance>cc25a_limit_8036b054[0])distance=cc25a_limit_8036b054[0];
 cc25a_trace_800b0824(cc25a_probe_8041e780,direction,cc25a_probe_8041e780+2,10000,1);
 cc25a_cached_distance_804b1780=(float)cc25a_hit_distance_804b1764;
 cc25a_position_8041e85c[0]=cc25a_hit_8043ae20[0];
 return cc25a_cached_distance_804b1780>distance-10.0f;
}
