// Original GC32 leaf: count at byte82, twelve-byte records at byte88,
// unsigned key at record+8. Fields and unknown prefix have no inferred meaning.
struct Sol34cKeyRecord { unsigned first,second; void *key; };
struct Sol34cRecordOwner {
 unsigned char unknown0[82]; unsigned char count; unsigned char unknown83[5];
 Sol34cKeyRecord records[1];
};
typedef char Sol34cRecordSize[(sizeof(Sol34cKeyRecord)==12)?1:-1];
typedef char Sol34cOwnerSize[(sizeof(Sol34cRecordOwner)==100)?1:-1];
extern "C" int sol34c_erase_record_key_80340994(Sol34cRecordOwner *self,void *key) {
 for(int index=0;index<self->count;++index) {
  if(self->records[index].key==key) {
   for(;index<=(int)self->count-2;++index)
    self->records[index]=self->records[index+1];
   --self->count;
   return 1;
  }
 }
 return 0;
}
