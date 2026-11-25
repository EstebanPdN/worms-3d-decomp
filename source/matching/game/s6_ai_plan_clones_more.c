/* AI plan factories and copies retaining their two queue references. */
typedef struct { unsigned char unknown00[44]; int references; } W3dS6CloneQueue;
typedef struct {int unknown; W3dS6CloneQueue *pointer;} W3dS6CloneRef;
static inline void s6_clone_ref_init(W3dS6CloneRef *ref) {ref->pointer=0;}
typedef struct { int kind; float score; int active; void *volatile vtable; int index,weapon; unsigned char unknown18[44]; int flags; W3dS6CloneRef first,second; unsigned char unknown58[16]; } W3dS6ClonePlan;
void *w3d_auto_8001523c(unsigned);
void *memcpy(void *,const void *,unsigned);
void w3d_path_cost_construct(W3dS6ClonePlan *);
extern unsigned char w3d_vtable_8040d7b8[];

extern unsigned char w3d_vtable_8040d368[];
extern const float w3d_f32_8036a4bc[];
W3dS6ClonePlan *w3d_ai_clone_weapon14_800130bc(W3dS6ClonePlan *,W3dS6ClonePlan *);
W3dS6ClonePlan *w3d_ai_create_weapon14_80013084(W3dS6ClonePlan *src) {
    return w3d_ai_clone_weapon14_800130bc(w3d_auto_8001523c(104),src);
}
W3dS6ClonePlan *w3d_ai_clone_weapon14_800130bc(W3dS6ClonePlan *dst,W3dS6ClonePlan *src) {
    void *volatile saved;
    w3d_path_cost_construct(dst);
    dst->vtable=w3d_vtable_8040d7b8;
    s6_clone_ref_init(&dst->first); s6_clone_ref_init(&dst->second);
    saved=dst->vtable;
    memcpy(dst,src,104);
    dst->vtable=saved;
    dst->score=*w3d_f32_8036a4bc;
    if(src->first.pointer) { dst->first.pointer=src->first.pointer; dst->first.pointer->references++; }
    if(src->second.pointer) { dst->second.pointer=src->second.pointer; dst->second.pointer->references++; }
    dst->flags=471;
    dst->vtable=w3d_vtable_8040d368;
    dst->weapon=14;
    return dst;
}

extern unsigned char w3d_vtable_8040d328[];
extern const float w3d_f32_8036a4c0[];
W3dS6ClonePlan *w3d_ai_clone_weapon16_80013210(W3dS6ClonePlan *,W3dS6ClonePlan *);
W3dS6ClonePlan *w3d_ai_create_weapon16_800131d8(W3dS6ClonePlan *src) {
    return w3d_ai_clone_weapon16_80013210(w3d_auto_8001523c(104),src);
}
W3dS6ClonePlan *w3d_ai_clone_weapon16_80013210(W3dS6ClonePlan *dst,W3dS6ClonePlan *src) {
    void *volatile saved;
    w3d_path_cost_construct(dst);
    dst->vtable=w3d_vtable_8040d7b8;
    s6_clone_ref_init(&dst->first); s6_clone_ref_init(&dst->second);
    saved=dst->vtable;
    memcpy(dst,src,104);
    dst->vtable=saved;
    dst->score=*w3d_f32_8036a4c0;
    if(src->first.pointer) { dst->first.pointer=src->first.pointer; dst->first.pointer->references++; }
    if(src->second.pointer) { dst->second.pointer=src->second.pointer; dst->second.pointer->references++; }
    dst->flags=471;
    dst->vtable=w3d_vtable_8040d328;
    dst->weapon=16;
    return dst;
}

extern unsigned char w3d_vtable_8040d2a8[];
extern const float w3d_f32_8036a4c8[];
W3dS6ClonePlan *w3d_ai_clone_weapon9_8001336c(W3dS6ClonePlan *,W3dS6ClonePlan *);
W3dS6ClonePlan *w3d_ai_create_weapon9_80013334(W3dS6ClonePlan *src) {
    return w3d_ai_clone_weapon9_8001336c(w3d_auto_8001523c(104),src);
}
W3dS6ClonePlan *w3d_ai_clone_weapon9_8001336c(W3dS6ClonePlan *dst,W3dS6ClonePlan *src) {
    void *volatile saved;
    w3d_path_cost_construct(dst);
    dst->vtable=w3d_vtable_8040d7b8;
    s6_clone_ref_init(&dst->first); s6_clone_ref_init(&dst->second);
    saved=dst->vtable;
    memcpy(dst,src,104);
    dst->vtable=saved;
    dst->score=*w3d_f32_8036a4c8;
    if(src->first.pointer) { dst->first.pointer=src->first.pointer; dst->first.pointer->references++; }
    if(src->second.pointer) { dst->second.pointer=src->second.pointer; dst->second.pointer->references++; }
    dst->vtable=w3d_vtable_8040d2a8;
    dst->weapon=9;
    dst->flags=4935;
    return dst;
}

extern unsigned char w3d_vtable_8040d268[];
extern const float w3d_f32_8036a4cc[];
W3dS6ClonePlan *w3d_ai_clone_weapon8_800134c0(W3dS6ClonePlan *,W3dS6ClonePlan *);
W3dS6ClonePlan *w3d_ai_create_weapon8_80013488(W3dS6ClonePlan *src) {
    return w3d_ai_clone_weapon8_800134c0(w3d_auto_8001523c(104),src);
}
W3dS6ClonePlan *w3d_ai_clone_weapon8_800134c0(W3dS6ClonePlan *dst,W3dS6ClonePlan *src) {
    void *volatile saved;
    w3d_path_cost_construct(dst);
    dst->vtable=w3d_vtable_8040d7b8;
    s6_clone_ref_init(&dst->first); s6_clone_ref_init(&dst->second);
    saved=dst->vtable;
    memcpy(dst,src,104);
    dst->vtable=saved;
    dst->score=*w3d_f32_8036a4cc;
    if(src->first.pointer) { dst->first.pointer=src->first.pointer; dst->first.pointer->references++; }
    if(src->second.pointer) { dst->second.pointer=src->second.pointer; dst->second.pointer->references++; }
    dst->flags=4423;
    dst->vtable=w3d_vtable_8040d268;
    dst->weapon=8;
    return dst;
}

extern unsigned char w3d_vtable_8040d228[];
extern const float w3d_f32_8036a4d0[];
W3dS6ClonePlan *w3d_ai_clone_weapon30_80013614(W3dS6ClonePlan *,W3dS6ClonePlan *);
W3dS6ClonePlan *w3d_ai_create_weapon30_800135dc(W3dS6ClonePlan *src) {
    return w3d_ai_clone_weapon30_80013614(w3d_auto_8001523c(104),src);
}
W3dS6ClonePlan *w3d_ai_clone_weapon30_80013614(W3dS6ClonePlan *dst,W3dS6ClonePlan *src) {
    void *volatile saved;
    w3d_path_cost_construct(dst);
    dst->vtable=w3d_vtable_8040d7b8;
    s6_clone_ref_init(&dst->first); s6_clone_ref_init(&dst->second);
    saved=dst->vtable;
    memcpy(dst,src,104);
    dst->vtable=saved;
    dst->score=*w3d_f32_8036a4d0;
    if(src->first.pointer) { dst->first.pointer=src->first.pointer; dst->first.pointer->references++; }
    if(src->second.pointer) { dst->second.pointer=src->second.pointer; dst->second.pointer->references++; }
    dst->flags=4423;
    dst->vtable=w3d_vtable_8040d228;
    dst->weapon=30;
    return dst;
}

extern unsigned char w3d_vtable_8040d1b8[];
extern const float w3d_f32_8036a4d8[];
W3dS6ClonePlan *w3d_ai_clone_weapon3_80013770(W3dS6ClonePlan *,W3dS6ClonePlan *);
W3dS6ClonePlan *w3d_ai_create_weapon3_80013738(W3dS6ClonePlan *src) {
    return w3d_ai_clone_weapon3_80013770(w3d_auto_8001523c(104),src);
}
W3dS6ClonePlan *w3d_ai_clone_weapon3_80013770(W3dS6ClonePlan *dst,W3dS6ClonePlan *src) {
    void *volatile saved;
    w3d_path_cost_construct(dst);
    dst->vtable=w3d_vtable_8040d7b8;
    s6_clone_ref_init(&dst->first); s6_clone_ref_init(&dst->second);
    saved=dst->vtable;
    memcpy(dst,src,104);
    dst->vtable=saved;
    dst->score=*w3d_f32_8036a4d8;
    if(src->first.pointer) { dst->first.pointer=src->first.pointer; dst->first.pointer->references++; }
    if(src->second.pointer) { dst->second.pointer=src->second.pointer; dst->second.pointer->references++; }
    dst->flags=368;
    dst->vtable=w3d_vtable_8040d1b8;
    dst->weapon=3;
    return dst;
}

extern unsigned char w3d_vtable_8040d180[];
extern const float w3d_f32_8036a4dc[];
W3dS6ClonePlan *w3d_ai_clone_weapon19_800138c4(W3dS6ClonePlan *,W3dS6ClonePlan *);
W3dS6ClonePlan *w3d_ai_create_weapon19_8001388c(W3dS6ClonePlan *src) {
    return w3d_ai_clone_weapon19_800138c4(w3d_auto_8001523c(104),src);
}
W3dS6ClonePlan *w3d_ai_clone_weapon19_800138c4(W3dS6ClonePlan *dst,W3dS6ClonePlan *src) {
    void *volatile saved;
    w3d_path_cost_construct(dst);
    dst->vtable=w3d_vtable_8040d7b8;
    s6_clone_ref_init(&dst->first); s6_clone_ref_init(&dst->second);
    saved=dst->vtable;
    memcpy(dst,src,104);
    dst->vtable=saved;
    dst->score=*w3d_f32_8036a4dc;
    if(src->first.pointer) { dst->first.pointer=src->first.pointer; dst->first.pointer->references++; }
    if(src->second.pointer) { dst->second.pointer=src->second.pointer; dst->second.pointer->references++; }
    dst->flags=368;
    dst->vtable=w3d_vtable_8040d180;
    dst->weapon=19;
    return dst;
}

W3dS6ClonePlan *w3d_fn_80013a18(W3dS6ClonePlan *,W3dS6ClonePlan *);
W3dS6ClonePlan *w3d_ai_create_plan_800139e0(W3dS6ClonePlan *src) {
    return w3d_fn_80013a18(w3d_auto_8001523c(104),src);
}
