// Native12-byte word carrier preserves original position copies without interpreting payload.
struct Cc23aWords8000b4c4{unsigned int words[3];};
struct Cc23aPlan8000b4c4{unsigned char unknown00[76];void *held4c;unsigned char unknown50[8];Cc23aWords8000b4c4 saved58;};
struct Cc23aRange8000b4c4{void **begin,**end;int size(){return end-begin;}};
extern "C" {extern Cc23aRange8000b4c4 *lbl_804aa750;extern Cc23aWords8000b4c4 lbl_8041d3a0[],lbl_8041d3ac[];extern float lbl_80369c58[];float fn_8000b418(Cc23aPlan8000b4c4 *,int,float);float fn_8000b344(Cc23aPlan8000b4c4 *,int,float,float);}
extern "C" float cc23a_planner_sum_weighted_costs_8000b4c4(Cc23aPlan8000b4c4 *self,float range,float factor,float blend,float multiplier){
 float total=0.0f;if(self->held4c)lbl_8041d3a0[0]=self->saved58;
 int i=0,count=lbl_804aa750->size();
 for(;i<count;++i){float weight=fn_8000b418(self,i,range)*factor;if(weight>0.0f)total+=fn_8000b344(self,i,blend,weight*multiplier);}
 lbl_8041d3a0[0]=lbl_8041d3ac[0];return total;
}
