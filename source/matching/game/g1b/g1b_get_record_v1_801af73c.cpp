// External record/owner ABI views. No external objects constructed locally.
struct G1bInterface {void **table;};
struct G1bId {unsigned words[4];};
struct G1bRecord {G1bInterface *object;G1bId id;char *name;};
struct G1bRecordOwner {unsigned prefix[5];G1bRecord *begin;};
extern "C" void fn_8020bb2c(void*);
inline void assignName(char **out,char *const &name){
 ++*(unsigned short*)(name-6);
 char *old=*out;
 if(--*(unsigned short*)(old-6)==0)fn_8020bb2c(old-6);
 *out=name;
}
extern "C" int g1b_get_record_801af73c(G1bRecordOwner*self,int index,G1bId*out,G1bInterface**object,char**name){
 *out=(*(G1bRecord*)((char*)self->begin+index*24)).id;
 G1bInterface *target=(*(G1bRecord*)((char*)self->begin+index*24)).object;*object=target;
 ((void(*)(G1bInterface*))target->table[3])(target);
 if(name)assignName(name,(*(G1bRecord*)((char*)self->begin+index*24)).name);
 return 0;
}
