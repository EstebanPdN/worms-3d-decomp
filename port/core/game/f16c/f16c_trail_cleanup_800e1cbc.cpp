#include "w3d_ptr.h"
#line 1 "f16c_trail_cleanup_800e1cbc.cpp"
// Partial external layouts and inferred lifetime ownership only; never allocated.
extern "C" void arrayfree_801fe240(Ptr32<void>),base_800df684(Ptr32<void>),mark_80122af8(Ptr32<void>);
struct F16cTrailType{char unknown0[20];Ptr32<F16cTrailType> parent;};extern F16cTrailType type_803613b0[];
struct F16cTrailObject{Ptr32<Ptr32<void>> vtable;};extern "C" Ptr32<F16cTrailObject> lookup_80164fc8(int);
inline bool isTrail(Ptr32<F16cTrailType> p){while(p!=type_803613b0){if(p==p->parent)return false;p=p->parent;}return true;}
struct F16cTrailHeld{Ptr32<F16cTrailObject> p;~F16cTrailHeld(){if(p)((Ptr32<void (Ptr32<F16cTrailObject>)>)p->vtable[4])(p);}void reset(Ptr32<F16cTrailObject> value){if(p)((Ptr32<void (Ptr32<F16cTrailObject>)>)p->vtable[4])(p);p=value;}};
struct F16cTrailBase{int unknown0;Ptr32<F16cTrailObject> held4;~F16cTrailBase(){base_800df684(this);}};
struct F16cTrailOwner{
 char unknown0[28];F16cTrailBase base;char unknown36[104];unsigned count;char unknown144[28];int mode;char unknown176[88];Ptr32<F16cTrailHeld> entries;char unknown268[28];int handle;Ptr32<F16cTrailObject> held;
 ~F16cTrailOwner(){
 if(mode==3){Ptr32<F16cTrailObject> object=lookup_80164fc8(handle);if(object){Ptr32<F16cTrailType> type=((Ptr32<Ptr32<F16cTrailType> (Ptr32<F16cTrailObject>)>)object->vtable[5])(object);if(isTrail(type))mark_80122af8(object);}}
 if(entries){for(unsigned i=0;i<count;++i){if(entries[i].p){((Ptr32<void (Ptr32<F16cTrailObject>, int)>)entries[i].p->vtable[22])(entries[i].p,0);entries[i].reset(0);}}
 if(entries){Ptr32<F16cTrailHeld> end=entries+((Ptr32<unsigned int>)entries)[-2];while(entries!=end){--end;end->~F16cTrailHeld();}arrayfree_801fe240((Ptr32<char>)entries-8);}entries=0;}
 if(held)((Ptr32<void (Ptr32<F16cTrailObject>)>)held->vtable[4])(held);held=0;
 }
};
extern "C" void f16c_trail_cleanup_800e1cbc(Ptr32<F16cTrailOwner> self){self->~F16cTrailOwner();}


