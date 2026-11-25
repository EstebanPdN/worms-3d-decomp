#include "w3d_ptr.h"
#line 1 "f16c_effect_cleanup_800e3328.cpp"
// External52-byte receiver prefix; native held interface cleanup inferred.
extern "C" void arrayfree_801fe240(Ptr32<void>);
struct F16cEffectObject{Ptr32<Ptr32<void>> vtable;};
struct F16cEffectContext{char unknown0[108];Ptr32<F16cEffectObject> service;};extern Ptr32<F16cEffectContext> context_804b1788;
struct F16cEffectHeld{Ptr32<F16cEffectObject> p;
 void fade(){if(p&&((Ptr32<int (Ptr32<F16cEffectObject>)>)p->vtable[10])(p)){Ptr32<F16cEffectObject> service=context_804b1788->service;((Ptr32<void (Ptr32<F16cEffectObject>, Ptr32<Ptr32<F16cEffectObject>>, int)>)service->vtable[25])(service,&p,250);}}
~F16cEffectHeld(){if(p)((Ptr32<void (Ptr32<F16cEffectObject>)>)p->vtable[4])(p);}void reset(Ptr32<F16cEffectObject> value){if(p)((Ptr32<void (Ptr32<F16cEffectObject>)>)p->vtable[4])(p);p=value;}};
struct F16cEffectOwner{char unknown0[32];F16cEffectHeld held32;Ptr32<F16cEffectHeld> entries;F16cEffectHeld held40;int unknown44;F16cEffectHeld active;};
extern "C" void f16c_effect_cleanup_800e3328(Ptr32<F16cEffectOwner> self){
 self->active.fade();
 if(self->entries){Ptr32<F16cEffectHeld> end=self->entries+((Ptr32<unsigned int>)self->entries)[-2];while(self->entries!=end){--end;end->~F16cEffectHeld();}arrayfree_801fe240((Ptr32<char>)self->entries-8);}
 self->held40.reset(0);self->held32.reset(0);
}


