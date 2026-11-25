struct F10SpeechObject{void**vtable;};struct F10SpeechVec{float x,y,z;};struct F10SpeechString;
extern "C" void init_8020c5c0(void*),finish_8020c5c4(void*),release_80341588(void*);extern "C" unsigned short*header_80341884(void*);extern "C" F10SpeechString*append_8020bf2c(F10SpeechString*,const char*);
struct F10SpeechString{const char*text;F10SpeechString(const F10SpeechString&o){init_8020c5c0(this);text=o.text;++*header_80341884(this);}~F10SpeechString(){finish_8020c5c4(this);release_80341588(this);}};
struct F10SpeechOwner{char p0[52];F10SpeechVec position;char p1[48];int handle;char p2[408];F10SpeechObject*voice;char p3[200];int specialVoice;};struct F10SpeechActor{char p[108];F10SpeechString soundbank;};struct F10SpeechContext{char p[108];F10SpeechObject*effects;};extern F10SpeechContext*context_804b1788;
extern const char voices_8039f824[],special0_8039f87c[],special1_8039f880[],separator_8039f884[];
extern "C" int option_800fc230(const char**,int*),compare_802ef234(const char*,const char*),blocked_8013f884(F10SpeechOwner*);extern "C" F10SpeechActor*actor_800fc6dc(int);
extern "C" void f10b_speak_checked_8013bd0c(F10SpeechOwner*s,const char*line){const char*option=voices_8039f824;int enabled=1;option_800fc230(&option,&enabled);if(enabled){if(compare_802ef234(line,special0_8039f87c)==0||compare_802ef234(line,special1_8039f880)==0)s->specialVoice=1;else s->specialVoice=0;if(!blocked_8013f884(s)){
 F10SpeechObject*&voice=s->voice;F10SpeechString path(actor_800fc6dc(s->handle)->soundbank);append_8020bf2c(&path,separator_8039f884);append_8020bf2c(&path,line);
 if(voice)((void(*)(F10SpeechObject*))voice->vtable[4])(voice);voice=0;F10SpeechObject*service=context_804b1788->effects;((void(*)(F10SpeechObject*,const char*,F10SpeechObject**))service->vtable[23])(service,path.text,&voice);
 {F10SpeechString transient(path);}
 ((void(*)(F10SpeechObject*,int,F10SpeechVec*))s->voice->vtable[14])(s->voice,3,&s->position);((void(*)(F10SpeechObject*))s->voice->vtable[5])(s->voice);
 }}}
