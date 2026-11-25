// External52-byte receiver prefix; native held interface cleanup inferred.
extern "C" void arrayfree_801fe240(void*);
struct F16cEffectObject{void **vtable;};
struct F16cEffectContext{char unknown0[108];F16cEffectObject *service;};extern F16cEffectContext *context_804b1788;
struct F16cEffectHeld{F16cEffectObject*p;
 void fade(){if(p&&((int(*)(F16cEffectObject*))p->vtable[10])(p)){F16cEffectObject*service=context_804b1788->service;((void(*)(F16cEffectObject*,F16cEffectObject**,int))service->vtable[25])(service,&p,250);}}
~F16cEffectHeld(){if(p)((void(*)(F16cEffectObject*))p->vtable[4])(p);}void reset(F16cEffectObject *value){if(p)((void(*)(F16cEffectObject*))p->vtable[4])(p);p=value;}};
struct F16cEffectOwner{char unknown0[32];F16cEffectHeld held32;F16cEffectHeld *entries;F16cEffectHeld held40;int unknown44;F16cEffectHeld active;};
extern "C" void f16c_effect_cleanup_800e3328(F16cEffectOwner*self){
 self->active.fade();
 if(self->entries){F16cEffectHeld*end=self->entries+((unsigned*)self->entries)[-2];while(self->entries!=end){--end;end->~F16cEffectHeld();}arrayfree_801fe240((char*)self->entries-8);}
 self->held40.reset(0);self->held32.reset(0);
}
