/* Timer property handles and related resource lifecycle. */
extern "C" {
struct Object { void **vtable; };
struct Timer { void *vtable; char unknown04[24]; Object *refs[18]; char unknown64[36]; Object *last[15]; };
struct Effect { void *vtable; char unknown04[24]; Object *refs[4]; char unknown2c[12]; Object *props[10]; char unknown60[12]; Object *target; char unknown70[4]; unsigned char flag; char unknown75[3]; int state; };
struct Key { const char *name; };
struct Ref { Object *value; int reserved; Ref() {value=0;} ~Ref() { if(value) ((void (*)(Object *))value->vtable[4])(value); } };
inline void assign(Object *&slot,Object *value) { if(value) ((void (*)(Object *))value->vtable[3])(value); if(slot) ((void (*)(Object *))slot->vtable[4])(slot); slot=value; }
void w3d_actor_base_initialize(Timer *);
void w3d_actor_base_destroy(Timer *,int);
void w3d_ctor_8015fef0(Effect *);
void w3d_base_destroy_8015ff2c(Effect *,int);
Object *w3d_constructor_native_cast(Object *);
void w3d_constructor_lookup_name(Key *,Object **);
int w3d_fn_800fc43c(Key *,int);
extern char w3d_obj_80410a70[],w3d_obj_80410ab0[];
extern const char w3d_str_8039afbc[],w3d_str_8039afd0[];
// Excluded after two attempts: two argument-address setup instructions differ.
#if 0
Timer *w3d_timer_construct_8011bf6c(Timer *self) {
    w3d_actor_base_initialize(self);
    self->vtable=w3d_obj_80410a70;
    self->refs[0]=0;
    self->refs[1]=0;
    self->refs[2]=0;
    self->refs[3]=0;
    self->refs[4]=0;
    self->refs[5]=0;
    self->refs[6]=0;
    self->refs[7]=0;
    self->refs[8]=0;
    self->refs[9]=0;
    self->refs[10]=0;
    self->refs[11]=0;
    self->refs[12]=0;
    self->refs[13]=0;
    self->refs[14]=0;
    self->refs[15]=0;
    self->refs[16]=0;
    self->refs[17]=0;
    self->last[0]=0;
    self->last[1]=0;
    self->last[2]=0;
    self->last[3]=0;
    self->last[4]=0;
    self->last[5]=0;
    self->last[6]=0;
    self->last[7]=0;
    self->last[8]=0;
    self->last[9]=0;
    self->last[10]=0;
    self->last[11]=0;
    self->last[12]=0;
    self->last[13]=0;
    self->last[14]=0;
    struct { Object *actor; int reserved; Key key; } local;
    local.key.name=w3d_str_8039afbc;
    local.actor=0;
    w3d_constructor_lookup_name(&local.key,&local.actor);
    assign(self->last[13],w3d_constructor_native_cast(local.actor));
    if(local.actor) ((void (*)(Object *))local.actor->vtable[4])(local.actor);
    return self;
}
#endif
void w3d_timer_destroy_8011c0ac(Timer *self,int flags) {
    self->vtable=w3d_obj_80410a70;
    if(self->last[14]) ((void (*)(Object *))self->last[14]->vtable[4])(self->last[14]);
    if(self->last[13]) ((void (*)(Object *))self->last[13]->vtable[4])(self->last[13]);
    if(self->last[12]) ((void (*)(Object *))self->last[12]->vtable[4])(self->last[12]);
    if(self->last[11]) ((void (*)(Object *))self->last[11]->vtable[4])(self->last[11]);
    if(self->last[10]) ((void (*)(Object *))self->last[10]->vtable[4])(self->last[10]);
    if(self->last[9]) ((void (*)(Object *))self->last[9]->vtable[4])(self->last[9]);
    if(self->last[8]) ((void (*)(Object *))self->last[8]->vtable[4])(self->last[8]);
    if(self->last[7]) ((void (*)(Object *))self->last[7]->vtable[4])(self->last[7]);
    if(self->last[6]) ((void (*)(Object *))self->last[6]->vtable[4])(self->last[6]);
    if(self->last[5]) ((void (*)(Object *))self->last[5]->vtable[4])(self->last[5]);
    if(self->last[4]) ((void (*)(Object *))self->last[4]->vtable[4])(self->last[4]);
    if(self->last[3]) ((void (*)(Object *))self->last[3]->vtable[4])(self->last[3]);
    if(self->last[2]) ((void (*)(Object *))self->last[2]->vtable[4])(self->last[2]);
    if(self->last[1]) ((void (*)(Object *))self->last[1]->vtable[4])(self->last[1]);
    if(self->last[0]) ((void (*)(Object *))self->last[0]->vtable[4])(self->last[0]);
    if(self->refs[17]) ((void (*)(Object *))self->refs[17]->vtable[4])(self->refs[17]);
    if(self->refs[16]) ((void (*)(Object *))self->refs[16]->vtable[4])(self->refs[16]);
    if(self->refs[15]) ((void (*)(Object *))self->refs[15]->vtable[4])(self->refs[15]);
    if(self->refs[14]) ((void (*)(Object *))self->refs[14]->vtable[4])(self->refs[14]);
    if(self->refs[13]) ((void (*)(Object *))self->refs[13]->vtable[4])(self->refs[13]);
    if(self->refs[12]) ((void (*)(Object *))self->refs[12]->vtable[4])(self->refs[12]);
    if(self->refs[11]) ((void (*)(Object *))self->refs[11]->vtable[4])(self->refs[11]);
    if(self->refs[10]) ((void (*)(Object *))self->refs[10]->vtable[4])(self->refs[10]);
    if(self->refs[9]) ((void (*)(Object *))self->refs[9]->vtable[4])(self->refs[9]);
    if(self->refs[8]) ((void (*)(Object *))self->refs[8]->vtable[4])(self->refs[8]);
    if(self->refs[7]) ((void (*)(Object *))self->refs[7]->vtable[4])(self->refs[7]);
    if(self->refs[6]) ((void (*)(Object *))self->refs[6]->vtable[4])(self->refs[6]);
    if(self->refs[5]) ((void (*)(Object *))self->refs[5]->vtable[4])(self->refs[5]);
    if(self->refs[4]) ((void (*)(Object *))self->refs[4]->vtable[4])(self->refs[4]);
    if(self->refs[3]) ((void (*)(Object *))self->refs[3]->vtable[4])(self->refs[3]);
    if(self->refs[2]) ((void (*)(Object *))self->refs[2]->vtable[4])(self->refs[2]);
    if(self->refs[1]) ((void (*)(Object *))self->refs[1]->vtable[4])(self->refs[1]);
    if(self->refs[0]) ((void (*)(Object *))self->refs[0]->vtable[4])(self->refs[0]);
    w3d_actor_base_destroy(self,flags);
}
void w3d_timer_clear_elapsed_8011d6a4() {
    Key key; key.name=w3d_str_8039afd0;
    w3d_fn_800fc43c(&key,0);
}
inline void resetEffect(Effect *self) {
    self->props[0]=0; self->props[1]=0;
    assign(self->props[2],0); assign(self->props[3],0);
    assign(self->refs[0],0); assign(self->refs[1],0); assign(self->refs[2],0);
    self->props[4]=0; self->flag=0; self->state=0;
    assign(self->target,0); assign(self->props[8],0); assign(self->props[9],0);
}
// Excluded after two attempts: null-reference initialization and register layout differ.
#if 0
Effect *w3d_effect_construct_8011da38(Effect *self) {
    w3d_ctor_8015fef0(self);
    self->props[2]=0;
    self->refs[0]=0;
    self->vtable=w3d_obj_80410ab0;
    self->refs[1]=0; self->refs[2]=0; self->refs[3]=0;
    self->props[3]=0; self->props[5]=0; self->props[6]=0; self->props[7]=0;
    self->props[8]=0; self->props[9]=0; self->target=0;
    resetEffect(self);
    return self;
}
#endif
void w3d_effect_destroy_8011dbc0(Effect *self,int flags) {
    self->vtable=w3d_obj_80410ab0;
    if(self->target) ((void (*)(Object *))self->target->vtable[6])(self->target);
    assign(self->target,0);
    if(self->props[9]) ((void (*)(Object *))self->props[9]->vtable[4])(self->props[9]);
    if(self->props[8]) ((void (*)(Object *))self->props[8]->vtable[4])(self->props[8]);
    if(self->props[7]) ((void (*)(Object *))self->props[7]->vtable[4])(self->props[7]);
    if(self->props[6]) ((void (*)(Object *))self->props[6]->vtable[4])(self->props[6]);
    if(self->props[5]) ((void (*)(Object *))self->props[5]->vtable[4])(self->props[5]);
    if(self->props[3]) ((void (*)(Object *))self->props[3]->vtable[4])(self->props[3]);
    if(self->props[2]) ((void (*)(Object *))self->props[2]->vtable[4])(self->props[2]);
    if(self->props[1]) ((void (*)(Object *))self->props[1]->vtable[4])(self->props[1]);
    if(self->props[0]) ((void (*)(Object *))self->props[0]->vtable[4])(self->props[0]);
    if(self->refs[3]) ((void (*)(Object *))self->refs[3]->vtable[4])(self->refs[3]);
    if(self->refs[2]) ((void (*)(Object *))self->refs[2]->vtable[4])(self->refs[2]);
    if(self->refs[1]) ((void (*)(Object *))self->refs[1]->vtable[4])(self->refs[1]);
    if(self->refs[0]) ((void (*)(Object *))self->refs[0]->vtable[4])(self->refs[0]);
    w3d_base_destroy_8015ff2c(self,flags);
}
}
