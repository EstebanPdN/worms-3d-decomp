// GWMP8P 0x8001210c: average health of entries with owners, then relative weighted cost.
struct cc24a_AverageEntry {char unknown0[8];int owner;char unknown12[16];int health;};
struct cc24a_AverageRange {cc24a_AverageEntry **begin,**end;int size(){return end-begin;}};
struct cc24a_AveragePlan {int unknown0;float cost;};
extern "C" {extern cc24a_AverageRange *cc24a_entries_804aa750;extern float cc24a_zero_8036a45c[];void cc24a_reset_8000b2f8(cc24a_AveragePlan*,int);float cc24a_weighted_8000b344(cc24a_AveragePlan*,int,float,float);}
extern "C" void cc24a_planner_relative_health_score_8001210c(cc24a_AveragePlan *self){
 cc24a_reset_8000b2f8(self,0);
 float total=cc24a_zero_8036a45c[0];int count=0;int size=cc24a_entries_804aa750->size();
 for(int i=0;i<size;++i){cc24a_AverageEntry *entry=*(cc24a_AverageEntry**)((char*)cc24a_entries_804aa750->begin+(i<<2));if(entry->owner!=-1){++count;total+=(float)entry->health;}}
 // Preserve original zero-count division and native conversion; no invented guard.
 int average=(int)(total/(float)count);
 for(int j=0;j<size;++j){cc24a_AverageEntry *entry=*(cc24a_AverageEntry**)((char*)cc24a_entries_804aa750->begin+(j<<2));if(entry->owner!=-1)self->cost+=cc24a_weighted_8000b344(self,j,cc24a_zero_8036a45c[0],(float)(entry->health-average));}
}
