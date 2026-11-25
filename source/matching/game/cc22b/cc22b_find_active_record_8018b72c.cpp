// Original table stride 276, unsigned 16-bit live count, flags word at +8.
// Address addition is explicitly 32-bit, as on the original PowerPC target.
// Slot 64 receives the table record itself. Returned value is compared with key;
// its domain meaning is unknown, so the callback is named only by observed role.
struct Cc22bRecord;
struct Cc22bRecordTable { void *unknown[16]; int (*key)(Cc22bRecord *); };
struct Cc22bRecord {
 Cc22bRecordTable *vt; unsigned int unknown4,flags; char unknown12[264];
 bool active() const { return (flags&0xfffe)!=0; }
};
extern unsigned short cc22b_record_count_804b18ac;
extern Cc22bRecord *cc22b_records_804b18b0;
extern "C" unsigned int w3d_cc22b_find_active_record_8018b72c(int key)
{
 int i=0;
 for(;i<cc22b_record_count_804b18ac;++i) {
  Cc22bRecord *p=(Cc22bRecord *)((i*276)+(unsigned int)cc22b_records_804b18b0);
  if(p->active() && key==p->vt->key(p)) break;
 }
 return i==cc22b_record_count_804b18ac ? (unsigned int)-1 : (unsigned int)i;
}
