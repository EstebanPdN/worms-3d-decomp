// External voice prefix only; no local object construction.
struct G1bVoice {unsigned prefix[2];int state,active;unsigned unknown[3];void**table;};
extern "C" int fn_801e4fcc();
extern "C" double fn_801e5460(G1bVoice*,void*);
extern "C" double fn_801e51c8(G1bVoice*,void*);
extern "C" double fn_801e5314(G1bVoice*,void*);
extern "C" double fn_801e560c(G1bVoice*,void*);
extern "C" void fn_801e5908(G1bVoice*,double);
extern "C" void fn_801e5960(G1bVoice*,double);
extern "C" void fn_801e50b8(G1bVoice*);
extern "C" void g1b_update_voice_801e50c8(G1bVoice*self,void*context){
 if(self->state==0&&fn_801e4fcc()!=0&&self->active){
 double volume=fn_801e5460(self,context);
 double facing=fn_801e51c8(self,context);
 double pan=fn_801e5314(self,context);
 double pitch=fn_801e560c(self,context);
 ((void(*)(G1bVoice*,double))self->table[5])(self,volume);
 ((void(*)(G1bVoice*,double))self->table[4])(self,facing);
 fn_801e5908(self,pan);fn_801e5960(self,pitch);fn_801e50b8(self);
 }
}
