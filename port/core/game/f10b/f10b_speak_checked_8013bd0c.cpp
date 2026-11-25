#include "w3d_ptr.h"
#line 1 "f10b_speak_checked_8013bd0c.cpp"
struct F10SpeechObject{Ptr32<Ptr32<void>> vtable;};struct F10SpeechVec{float x,y,z;};struct F10SpeechString;
extern "C" void init_8020c5c0(Ptr32<void>),finish_8020c5c4(Ptr32<void>),release_80341588(Ptr32<void>);extern "C" Ptr32<unsigned short> header_80341884(Ptr32<void>);extern "C" Ptr32<F10SpeechString> append_8020bf2c(Ptr32<F10SpeechString>,Ptr32<const char>);
struct F10SpeechString{Ptr32<const char> text;F10SpeechString(const F10SpeechString&o){init_8020c5c0(this);text=o.text;++*header_80341884(this);}~F10SpeechString(){finish_8020c5c4(this);release_80341588(this);}};
struct F10SpeechOwner{char p0[52];F10SpeechVec position;char p1[48];int handle;char p2[408];Ptr32<F10SpeechObject> voice;char p3[200];int specialVoice;};struct F10SpeechActor{char p[108];F10SpeechString soundbank;};struct F10SpeechContext{char p[108];Ptr32<F10SpeechObject> effects;};extern Ptr32<F10SpeechContext> context_804b1788;
extern const char voices_8039f824[],special0_8039f87c[],special1_8039f880[],separator_8039f884[];
extern "C" int option_800fc230(Ptr32<Ptr32<const char>>,Ptr32<int>),compare_802ef234(Ptr32<const char>,Ptr32<const char>),blocked_8013f884(Ptr32<F10SpeechOwner>);extern "C" Ptr32<F10SpeechActor> actor_800fc6dc(int);
extern "C" void f10b_speak_checked_8013bd0c(Ptr32<F10SpeechOwner> s,Ptr32<const char> line){Ptr32<const char> option=voices_8039f824;int enabled=1;option_800fc230(&option,&enabled);if(enabled){if(compare_802ef234(line,special0_8039f87c)==0||compare_802ef234(line,special1_8039f880)==0)s->specialVoice=1;else s->specialVoice=0;if(!blocked_8013f884(s)){
 Ptr32<F10SpeechObject> &voice=s->voice;F10SpeechString path(actor_800fc6dc(s->handle)->soundbank);append_8020bf2c(&path,separator_8039f884);append_8020bf2c(&path,line);
 if(voice)((Ptr32<void (Ptr32<F10SpeechObject>)>)voice->vtable[4])(voice);voice=0;Ptr32<F10SpeechObject> service=context_804b1788->effects;((Ptr32<void (Ptr32<F10SpeechObject>, Ptr32<const char>, Ptr32<Ptr32<F10SpeechObject>>)>)service->vtable[23])(service,path.text,&voice);
 {F10SpeechString transient(path);}
 ((Ptr32<void (Ptr32<F10SpeechObject>, int, Ptr32<F10SpeechVec>)>)s->voice->vtable[14])(s->voice,3,&s->position);((Ptr32<void (Ptr32<F10SpeechObject>)>)s->voice->vtable[5])(s->voice);
 }}}


