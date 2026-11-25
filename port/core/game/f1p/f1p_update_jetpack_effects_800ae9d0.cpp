#include "w3d_ptr.h"
#line 1 "f1p_update_jetpack_effects_800ae9d0.cpp"
// Observed jetpack effect state and service interfaces; names and signatures inferred.
struct F1pJetVec{float x,y,z;};struct F1pJetIface{Ptr32<Ptr32<void>> table;int playing(){return ((Ptr32<int (Ptr32<F1pJetIface>)>)table[9])(this);}void start(){((Ptr32<void (Ptr32<F1pJetIface>)>)table[5])(this);}void stop(){((Ptr32<void (Ptr32<F1pJetIface>)>)table[6])(this);}void position(Ptr32<const F1pJetVec> p){((Ptr32<void (Ptr32<F1pJetIface>, int, Ptr32<const F1pJetVec>)>)table[14])(this,3,p);}};
struct F1pJetOwner{char unknown[84];Ptr32<F1pJetIface> first; Ptr32<F1pJetIface> engine; Ptr32<F1pJetIface> voice;};struct F1pJetContext{char unknown[108];Ptr32<F1pJetIface> effects;};extern Ptr32<F1pJetContext> context_804b1788;extern char start_8038214c[],end_803821e8[];
inline void jetEnd(Ptr32<F1pJetOwner> s){Ptr32<F1pJetIface> &voice=s->voice;s->engine->stop();if(voice)((Ptr32<void (Ptr32<F1pJetIface>)>)voice->table[4])(voice);voice=0;Ptr32<F1pJetIface> service=context_804b1788->effects;if(service)((Ptr32<void (Ptr32<F1pJetIface>, Ptr32<const char>, Ptr32<Ptr32<F1pJetIface>>)>)service->table[23])(service,end_803821e8,&voice);s->voice->start();}
inline void jetStart(Ptr32<F1pJetOwner> s){Ptr32<F1pJetIface> &voice=s->voice;s->engine->start();if(voice)((Ptr32<void (Ptr32<F1pJetIface>)>)voice->table[4])(voice);voice=0;Ptr32<F1pJetIface> service=context_804b1788->effects;if(service)((Ptr32<void (Ptr32<F1pJetIface>, Ptr32<const char>, Ptr32<Ptr32<F1pJetIface>>)>)service->table[23])(service,start_8038214c,&voice);s->voice->start();}
inline void jetFirstStart(Ptr32<F1pJetOwner> s){if(s->first->playing()==0)s->first->start();}
extern "C" void w3d_update_jetpack_effects_800ae9d0(Ptr32<F1pJetOwner> s,int on,int keep,Ptr32<const F1pJetVec> position){if(on){if(s->engine->playing()==0)jetStart(s);jetFirstStart(s);}else if(keep){if(s->engine->playing()==1)jetEnd(s);jetFirstStart(s);}else{if(s->engine->playing()==1)jetEnd(s);if(s->first->playing()==1)s->first->stop();}s->first->position(position);s->engine->position(position);s->voice->position(position);}


