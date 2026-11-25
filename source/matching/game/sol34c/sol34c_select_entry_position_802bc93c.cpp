// GC32 reconstruction from original instructions. Entry-pointer iteration and
// numeric positions are observed; original class and method names are unknown.
struct Sol34cPositionEntry { unsigned words[15]; float fixed,scaled; };
struct Sol34cPositionState {
 unsigned words[12]; float extent; unsigned word52;
 Sol34cPositionEntry **begin,**end; unsigned word64;
 float position; unsigned word72; float scale;
};
extern "C" int sol34c_entry_id_802bd2bc(Sol34cPositionEntry *);
extern "C" void sol34c_apply_position_802bc790(Sol34cPositionState *,float);
extern "C" float sol34c_current_position_802bc778(Sol34cPositionState *);
extern "C" unsigned sol34c_nested_count_802bc71c(Sol34cPositionState *);
typedef char Sol34cPointerWidth[(sizeof(void*)==4)?1:-1];
typedef char Sol34cEntrySize[(sizeof(Sol34cPositionEntry)==68)?1:-1];
typedef char Sol34cStateSize[(sizeof(Sol34cPositionState)==80)?1:-1];
extern "C" float sol34c_select_entry_position_802bc93c(Sol34cPositionState *self,int id,int apply) {
 float initial=(float)id;
 Sol34cPositionEntry **it=self->begin;
 float result;
 if(it!=self->end) {
  do {
   if(sol34c_entry_id_802bd2bc(*it)==id) {
    if((*it)->fixed!=0.0f) {
     if(apply) sol34c_apply_position_802bc790(self,(float)id);
     return (float)id;
    }
    if((*it)->scaled!=0.0f) {
     float extent=self->extent,scale=self->scale;
     if(scale<extent) {
      result=(initial+1.0f)-(extent+extent)/(scale+scale);
      goto finish;
     }
    }
    float current=sol34c_current_position_802bc778(self);
    float count=(float)sol34c_nested_count_802bc71c(self);
    if(current<=count && count-self->position<current && apply)
     sol34c_apply_position_802bc790(self,count-current);
    return self->position;
   }
   ++it;
  } while(it!=self->end);
 }
 result=(float)id;
 if(self->position<=result)
  result=(initial+1.0f)-(self->extent+self->extent)/(self->scale+self->scale);
finish:
 if(apply) sol34c_apply_position_802bc790(self,result);
 return result;
}
