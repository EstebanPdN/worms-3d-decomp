// External record/owner ABI views. No external objects constructed locally.
struct G1bInterface {void **table;};
struct G1bId {unsigned words[4];};
struct G1bRecord {G1bInterface *object;G1bId id;char *name;};
struct G1bRecordOwner {unsigned prefix[5];G1bRecord *begin;};
extern "C" void fn_8020bb2c(void*);
inline void assignName(char **out,const G1bRecord &record){
 char *name=record.name;
 ++*(unsigned short*)(name-6);
 unsigned short *header=(unsigned short*)(*out-6);
 if(--*header==0)fn_8020bb2c(header);
 *out=record.name;
}
extern "C" int g1b_get_record_801af73c(G1bRecordOwner*self,int index,G1bId*out,G1bInterface**object,char**name){
 *out=(*(G1bRecord*)((unsigned)self->begin+index*24)).id;
 G1bInterface *target=(*(G1bRecord*)((unsigned)self->begin+index*24)).object;*object=target;
 ((void(*)(G1bInterface*))target->table[3])(target);
 if(name)assignName(name,*(G1bRecord*)((unsigned)self->begin+index*24));
 return 0;
}
