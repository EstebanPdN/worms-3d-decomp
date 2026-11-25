
struct cc32a_String_803426b8 {
 cc32a_String_803426b8(const cc32a_String_803426b8 &);char *text;cc32a_String_803426b8();~cc32a_String_803426b8();};
struct cc32a_Briefing_80030140 {char p[36];void *resource;char q[24];void *duration;int shown,active;unsigned int deadline;};
struct cc32a_Context_80030140 {char p[52];unsigned int now;};
extern "C" {char **fn_80179170(void*);void fn_800306a4(cc32a_Briefing_80030140*);void *fn_803426b8(void*);int fn_800fc2b0(const char**,char**);void *fn_8020c510(void*,const char*,...);int fn_800fc550(const char**,const char*);void fn_80030260(cc32a_Briefing_80030140*);int fn_80178d1c(void*);cc32a_Context_80030140 *fn_80165254();void fn_8020c5c4(void*);void fn_80341588(void*);extern const char cc32a_error_80373088[],cc32a_key_803730b0[];}
inline cc32a_String_803426b8::~cc32a_String_803426b8(){fn_8020c5c4(this);fn_80341588(this);}
extern "C" void cc32a_briefing_text_80030140(cc32a_Briefing_80030140 *s){
 if(*((unsigned short*)*fn_80179170(s->resource)-2)==0)fn_800306a4(s);
 else {char *text=0;cc32a_String_803426b8 temp;const char *key=*fn_80179170(s->resource);
 if(fn_800fc2b0(&key,&text)<0){fn_8020c510(&temp,cc32a_error_80373088,*fn_80179170(s->resource));text=temp.text;}
 const char *dest=cc32a_key_803730b0;fn_800fc550(&dest,text);if(!s->shown)fn_80030260(s);
 if(fn_80178d1c(s->duration)==0)s->active=0;else{s->active=1;unsigned int now=fn_80165254()->now;s->deadline=now+fn_80178d1c(s->duration);}
 
 }
}
