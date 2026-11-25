// Original 0x80195ea8. Partial views name observed fields only; no full class size claim.
// Two single-precision parameters and fmadds preserve the original arithmetic tree.
struct cc41b_BlendEntry { int flags_and_index; unsigned words[2]; };
struct cc41b_BlendRange { cc41b_BlendEntry *begin,*end; unsigned unknown[2]; };
struct cc41b_BlendTable { unsigned char unknown[52]; cc41b_BlendRange *ranges; };
struct cc41b_BlendCache { unsigned unknown; cc41b_BlendEntry **entries; unsigned tail[3]; };
struct cc41b_BlendOwner { unsigned char unknown[24]; float *values; unsigned char gap[44]; cc41b_BlendTable *table; unsigned gap2; cc41b_BlendCache *caches; };
extern float cc41b_default_803a84a0[];
extern "C" float cc41b_evaluate_801961a8(cc41b_BlendEntry **,float);
extern "C" void cc41b_blend_channels_80195ea8(cc41b_BlendOwner *self,int index,int reset,float weight,float time) {
 cc41b_BlendRange *range=self->table->ranges+index;
 cc41b_BlendEntry *entry=range->begin,*end=range->end;
 int cached=0;
 do {
  float base=cc41b_default_803a84a0[0];
  if(reset==0) base=self->values[(unsigned short)entry->flags_and_index];
  if(entry->flags_and_index<0) {
   self->caches[index].entries[cached]=entry;
   float value=cc41b_evaluate_801961a8(self->caches[index].entries+cached,time);
   ++cached;
   self->values[(unsigned short)entry->flags_and_index]=value*weight+base;
  } else self->values[(unsigned short)entry->flags_and_index]=base;
  ++entry;
 } while(entry!=end);
}
