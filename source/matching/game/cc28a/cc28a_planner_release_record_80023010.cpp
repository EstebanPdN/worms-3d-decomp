// Remove one owned record and signal the transition to an empty work count.
struct cc28a_Record_80023010 {unsigned int unknown;const char *name;unsigned int payload[2];};
struct cc28a_Owner_80023010 {unsigned char unknown[12];cc28a_Record_80023010 *record;};
struct cc28a_Range_80023010 {cc28a_Record_80023010 **begin,**end,**limit;};
struct cc28a_Message_80023010 {unsigned short id,pad;void *type;};
extern cc28a_Range_80023010 cc28a_records_804200a4[];
extern unsigned int cc28a_heap_804aca40,cc28a_name_804aca4c;
extern void *cc28a_count_804aca48,*cc28a_messages_804b1754;
extern unsigned char cc28a_type_8040db38[];
extern "C" int cc28a_format_803434d4(char*,const char*,...);
extern "C" void cc28a_release_80209920(unsigned int*,cc28a_Record_80023010*);
extern "C" void *cc28a_copy_802eee50(void*,const void*,...);
extern "C" int cc28a_read_80178c48(void*);
extern "C" int cc28a_write_80178c54(void*,const int*);
extern "C" cc28a_Message_80023010 *cc28a_allocate_801613f0(void*,int);
extern "C" unsigned int cc28a_id_8015f5a0(unsigned int*,int);
extern "C" int cc28a_post_8016239c(cc28a_Message_80023010*);
inline void cc28a_erasecopy_80023010(cc28a_Record_80023010 **where,cc28a_Record_80023010 **next,cc28a_Record_80023010 **last){cc28a_copy_802eee50(where,next,(char*)last-(char*)where);}
inline void cc28a_setcount_80023010(void *property,int value){cc28a_write_80178c54(property,&value);}
extern "C" int cc28a_planner_release_record_80023010(cc28a_Owner_80023010 *self){
 struct {char name[128];} local;
 cc28a_Record_80023010 **end=cc28a_records_804200a4->end;
 for(cc28a_Record_80023010 **cursor=cc28a_records_804200a4->begin;cursor!=end;++cursor){
  if(self->record==*cursor){
   cc28a_format_803434d4(local.name,self->record->name);
   cc28a_release_80209920(&cc28a_heap_804aca40,*cursor);
   cc28a_Record_80023010 **next=cursor+1,**last=cc28a_records_804200a4->end;
   if(next!=last)cc28a_erasecopy_80023010(cursor,next,last-1);
   --cc28a_records_804200a4->end;
   int count=cc28a_read_80178c48(cc28a_count_804aca48)-1;
   cc28a_setcount_80023010(cc28a_count_804aca48,count);
   if(count==0){
    cc28a_Message_80023010 *msg=cc28a_allocate_801613f0(cc28a_messages_804b1754,8);
    msg->id=cc28a_id_8015f5a0(&cc28a_name_804aca4c,1);msg->type=cc28a_type_8040db38;cc28a_post_8016239c(msg);
   }
   return 0;
  }
 }
 return (int)0x80004005;
}
