struct TerraOnlyARayCandidates {float values[8];};
extern "C" int terra_only_a_fn_80040b0c(TerraOnlyARayCandidates*);
extern "C" int terra_only_a_fn_80040d84(TerraOnlyARayCandidates*);
extern "C" const float terra_only_a_lbl_80374790[],terra_only_a_lbl_80374794[];
static inline int terra_only_a_precedes(const float & a,const float & b){float zero=0.0f;return a<zero?0:(b<zero||a<=b?1:0);}
extern "C" int terra_only_a_ray_compare_widths_80040f18(TerraOnlyARayCandidates*self){
 float *p=self->values;
 if(terra_only_a_precedes(p[6],p[2])){p[6]=terra_only_a_lbl_80374794[0];return terra_only_a_fn_80040b0c(self);}
 if(terra_only_a_precedes(p[2],p[6])){p[2]=p[3];p[3]=terra_only_a_lbl_80374794[0];return terra_only_a_fn_80040d84(self);}
 return 0;
}