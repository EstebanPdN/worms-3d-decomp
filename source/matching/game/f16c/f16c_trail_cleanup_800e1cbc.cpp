// Partial external layouts and inferred lifetime ownership only; never allocated.
extern "C" void arrayfree_801fe240(void*),base_800df684(void*),mark_80122af8(void*);
struct F16cTrailType{char unknown0[20];F16cTrailType*parent;};extern F16cTrailType type_803613b0[];
struct F16cTrailObject{void**vtable;};extern "C" F16cTrailObject *lookup_80164fc8(int);
inline bool isTrail(F16cTrailType*p){while(p!=type_803613b0){if(p==p->parent)return false;p=p->parent;}return true;}
struct F16cTrailHeld{F16cTrailObject*p;~F16cTrailHeld(){if(p)((void(*)(F16cTrailObject*))p->vtable[4])(p);}void reset(F16cTrailObject*value){if(p)((void(*)(F16cTrailObject*))p->vtable[4])(p);p=value;}};
struct F16cTrailBase{int unknown0;F16cTrailObject *held4;~F16cTrailBase(){base_800df684(this);}};
struct F16cTrailOwner{
 char unknown0[28];F16cTrailBase base;char unknown36[104];unsigned count;char unknown144[28];int mode;char unknown176[88];F16cTrailHeld *entries;char unknown268[28];int handle;F16cTrailObject *held;
 ~F16cTrailOwner(){
 if(mode==3){F16cTrailObject*object=lookup_80164fc8(handle);if(object){F16cTrailType*type=((F16cTrailType*(*)(F16cTrailObject*))object->vtable[5])(object);if(isTrail(type))mark_80122af8(object);}}
 if(entries){for(unsigned i=0;i<count;++i){if(entries[i].p){((void(*)(F16cTrailObject*,int))entries[i].p->vtable[22])(entries[i].p,0);entries[i].reset(0);}}
 if(entries){F16cTrailHeld*end=entries+((unsigned*)entries)[-2];while(entries!=end){--end;end->~F16cTrailHeld();}arrayfree_801fe240((char*)entries-8);}entries=0;}
 if(held)((void(*)(F16cTrailObject*))held->vtable[4])(held);held=0;
 }
};
extern "C" void f16c_trail_cleanup_800e1cbc(F16cTrailOwner*self){self->~F16cTrailOwner();}
