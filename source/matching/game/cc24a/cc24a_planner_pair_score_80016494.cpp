// GWMP8P 0x80016494: multiplicative pair interactions on current plan score.
struct cc24a_PairPlan {int unknown0;float cost;char unknown8[8];int index;};
struct cc24a_PairRange {cc24a_PairPlan **begin,**end;int size(){return end-begin;}};
extern "C" {extern cc24a_PairRange *cc24a_pairs_804aa6f8;extern float cc24a_zero_8036a65c[],cc24a_scale_8036a660[],cc24a_one_8036a664[];float cc24a_factor_80016564(cc24a_PairPlan*,cc24a_PairPlan*);}
extern "C" void cc24a_planner_pair_score_80016494(cc24a_PairPlan *self){
 // Original extra stack extent is observed; source purpose unknown.
 if(self->index!=-1){int size=cc24a_pairs_804aa6f8->size();
 for(int i=0;i<size;++i){cc24a_PairPlan *pair=*(cc24a_PairPlan**)((char*)cc24a_pairs_804aa6f8->begin+(i<<2));
 float factor=cc24a_factor_80016564(pair,self);
 if(factor>0.0f){float product=factor*pair->cost;self->cost*=product*0.5f+(1.0f-product);}
 }}
}
