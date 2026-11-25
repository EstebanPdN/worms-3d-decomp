// Roles and deque view are inferred.
extern "C" void fn_8020c5c4(void*),fn_80341588(void*);
struct Text_8020bb54 {
 Text_8020bb54(const Text_8020bb54 &);char*data;Text_8020bb54(const char*p);~Text_8020bb54(){fn_8020c5c4(this);fn_80341588(this);}};
struct Deque {char pad[16];unsigned *current;void *unused;unsigned *end;};
struct Owner {char pad[72];char first[20],second[28];Deque queue;};
extern "C" int fn_800fc2b0(char **,char **);
extern "C" int fn_800c467c(void *,char *);
extern "C" void fn_8035f16c(Deque *,unsigned *);
extern char name_803d004c[];
inline void append(Deque*q,unsigned&value){if(q->current!=q->end-1){if(q->current)*q->current=value;++q->current;}else fn_8035f16c(q,&value);}
extern "C" void w3d_f3a_comment_8028ebe0(Owner*s,Text_8020bb54 input,unsigned value){
 char *name=name_803d004c,*out;
 fn_800fc2b0(&name,&out);
 fn_800c467c(s->first,input.data);
 append(&s->queue,value);
 Text_8020bb54 text(out);fn_800c467c(s->second,text.data);
}
