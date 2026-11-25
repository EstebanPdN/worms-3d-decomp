// Native object layout view for 800ffe54. Names and complete type identities
// are inferred. The common initialization helper takes the observed empty
// word by value, retaining it across base/member construction. It initializes
// real object fields only. Triple members are three adjacent observed words.
// The string assignment boundary returns its destination in r3, as observed
// in 8020bd58 (and forwarded through 8020bd38).
struct Sol35bTriple {int a,b,c; inline void clear(int value) {c=value;b=value;a=value;} };
struct Sol35bString {char *text;};
struct Sol35bScript {
 void *vtable;char base[24];Sol35bTriple first;int field40;
 int fields44[6];int field68;char unknown72[260];char tagged332[24];int field356;
 Sol35bString name360,name364;int state368;Sol35bTriple triple372,triple384;
};
extern char sol35b_vtable_804105f8[];
extern "C" {
int sol35b_base_801628b0(Sol35bScript *);
void sol35b_tag_80207fec(void *);
void * sol35b_string_803426b8(Sol35bString *);
Sol35bString * sol35b_assign_8020bd38(Sol35bString *,const char *);
void sol35b_state_8010272c(Sol35bScript *,int);
}
inline Sol35bScript *sol35b_initialize_script(Sol35bScript *s,int empty) {
 Sol35bString *name=&s->name360;
 sol35b_base_801628b0(s);
 s->vtable=sol35b_vtable_804105f8;
 s->first.clear(empty);
 s->fields44[0]=empty;s->fields44[1]=empty;s->fields44[2]=empty;
 s->fields44[3]=empty;s->fields44[4]=empty;s->fields44[5]=empty;
 sol35b_tag_80207fec(s->tagged332);
 sol35b_string_803426b8(name);
 sol35b_string_803426b8(&s->name364);
 s->triple372.clear(empty);s->triple384.clear(empty);s->field68=empty;
 sol35b_assign_8020bd38(name,0);
 s->field40=empty;s->field356=empty;s->state368=1;
 sol35b_state_8010272c(s,2);
 return s;
}
extern "C" Sol35bScript *sol35b_script_construct_800ffe54(Sol35bScript *s) {return sol35b_initialize_script(s,0);}
