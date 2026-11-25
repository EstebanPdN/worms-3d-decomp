/* AI plan factories and copies retaining their two queue references. */
typedef struct { unsigned char unknown00[44]; int references; } W3dS6CloneQueue;
typedef struct {int unknown; W3dS6CloneQueue *pointer;} W3dS6CloneRef;
static inline void s6_clone_ref_init(W3dS6CloneRef *ref) {ref->pointer=0;}
typedef struct { int kind; float score; int active; void *volatile vtable; int index,weapon; unsigned char unknown18[44]; int flags; W3dS6CloneRef first,second; unsigned char unknown58[16]; } W3dS6ClonePlan;
void *w3d_auto_8001523c(unsigned);
void *memcpy(void *,const void *,unsigned);
void w3d_path_cost_construct(W3dS6ClonePlan *);
extern unsigned char w3d_vtable_8040d7b8[],w3d_vtable_8040d780[],w3d_vtable_8040d5e8[];
extern const float w3d_f32_8036a478[],w3d_f32_8036a494[];
W3dS6ClonePlan *w3d_ai_clone_base_80012350(W3dS6ClonePlan *,W3dS6ClonePlan *);
W3dS6ClonePlan *w3d_ai_clone_weapon0_800124c4(W3dS6ClonePlan *,W3dS6ClonePlan *);
W3dS6ClonePlan *w3d_ai_create_base_80012318(W3dS6ClonePlan *src) {
    return w3d_ai_clone_base_80012350(w3d_auto_8001523c(104),src);
}
W3dS6ClonePlan *w3d_ai_clone_base_80012350(W3dS6ClonePlan *dst,W3dS6ClonePlan *src) {
    void *volatile saved;
    w3d_path_cost_construct(dst);
    dst->vtable=w3d_vtable_8040d7b8;
    s6_clone_ref_init(&dst->first); s6_clone_ref_init(&dst->second);
    saved=dst->vtable;
    memcpy(dst,src,104);
    dst->vtable=saved;
    dst->score=*w3d_f32_8036a478;
    if(src->first.pointer) { dst->first.pointer=src->first.pointer; dst->first.pointer->references++; }
    if(src->second.pointer) { dst->second.pointer=src->second.pointer; dst->second.pointer->references++; }
    dst->vtable=w3d_vtable_8040d780;
    return dst;
}
W3dS6ClonePlan *w3d_ai_create_weapon0_8001248c(W3dS6ClonePlan *src) {
    return w3d_ai_clone_weapon0_800124c4(w3d_auto_8001523c(104),src);
}
W3dS6ClonePlan *w3d_ai_clone_weapon0_800124c4(W3dS6ClonePlan *dst,W3dS6ClonePlan *src) {
    void *volatile saved;
    w3d_path_cost_construct(dst);
    dst->vtable=w3d_vtable_8040d7b8;
    s6_clone_ref_init(&dst->first); s6_clone_ref_init(&dst->second);
    saved=dst->vtable;
    memcpy(dst,src,104);
    dst->vtable=saved;
    dst->score=*w3d_f32_8036a494;
    if(src->first.pointer) { dst->first.pointer=src->first.pointer; dst->first.pointer->references++; }
    if(src->second.pointer) { dst->second.pointer=src->second.pointer; dst->second.pointer->references++; }
    dst->flags=327;
    dst->vtable=w3d_vtable_8040d5e8;
    dst->weapon=0;
    return dst;
}

extern unsigned char w3d_vtable_8040d5a8[];
extern const float w3d_f32_8036a498[];
W3dS6ClonePlan *w3d_ai_clone_weapon15_80012614(W3dS6ClonePlan *,W3dS6ClonePlan *);
W3dS6ClonePlan *w3d_ai_create_weapon15_800125dc(W3dS6ClonePlan *src) {
    return w3d_ai_clone_weapon15_80012614(w3d_auto_8001523c(104),src);
}
W3dS6ClonePlan *w3d_ai_clone_weapon15_80012614(W3dS6ClonePlan *dst,W3dS6ClonePlan *src) {
    void *volatile saved;
    w3d_path_cost_construct(dst);
    dst->vtable=w3d_vtable_8040d7b8;
    s6_clone_ref_init(&dst->first); s6_clone_ref_init(&dst->second);
    saved=dst->vtable;
    memcpy(dst,src,104);
    dst->vtable=saved;
    dst->score=*w3d_f32_8036a498;
    if(src->first.pointer) { dst->first.pointer=src->first.pointer; dst->first.pointer->references++; }
    if(src->second.pointer) { dst->second.pointer=src->second.pointer; dst->second.pointer->references++; }
    dst->flags=327;
    dst->vtable=w3d_vtable_8040d5a8;
    dst->weapon=15;
    return dst;
}

extern unsigned char w3d_vtable_8040d568[];
extern const float w3d_f32_8036a49c[];
W3dS6ClonePlan *w3d_ai_clone_weapon20_80012768(W3dS6ClonePlan *,W3dS6ClonePlan *);
W3dS6ClonePlan *w3d_ai_create_weapon20_80012730(W3dS6ClonePlan *src) {
    return w3d_ai_clone_weapon20_80012768(w3d_auto_8001523c(104),src);
}
W3dS6ClonePlan *w3d_ai_clone_weapon20_80012768(W3dS6ClonePlan *dst,W3dS6ClonePlan *src) {
    void *volatile saved;
    w3d_path_cost_construct(dst);
    dst->vtable=w3d_vtable_8040d7b8;
    s6_clone_ref_init(&dst->first); s6_clone_ref_init(&dst->second);
    saved=dst->vtable;
    memcpy(dst,src,104);
    dst->vtable=saved;
    dst->score=*w3d_f32_8036a49c;
    if(src->first.pointer) { dst->first.pointer=src->first.pointer; dst->first.pointer->references++; }
    if(src->second.pointer) { dst->second.pointer=src->second.pointer; dst->second.pointer->references++; }
    dst->flags=327;
    dst->vtable=w3d_vtable_8040d568;
    dst->weapon=20;
    return dst;
}

extern unsigned char w3d_vtable_8040d528[];
extern const float w3d_f32_8036a4a0[];
W3dS6ClonePlan *w3d_ai_clone_weapon21_800128bc(W3dS6ClonePlan *,W3dS6ClonePlan *);
W3dS6ClonePlan *w3d_ai_create_weapon21_80012884(W3dS6ClonePlan *src) {
    return w3d_ai_clone_weapon21_800128bc(w3d_auto_8001523c(104),src);
}
W3dS6ClonePlan *w3d_ai_clone_weapon21_800128bc(W3dS6ClonePlan *dst,W3dS6ClonePlan *src) {
    void *volatile saved;
    w3d_path_cost_construct(dst);
    dst->vtable=w3d_vtable_8040d7b8;
    s6_clone_ref_init(&dst->first); s6_clone_ref_init(&dst->second);
    saved=dst->vtable;
    memcpy(dst,src,104);
    dst->vtable=saved;
    dst->score=*w3d_f32_8036a4a0;
    if(src->first.pointer) { dst->first.pointer=src->first.pointer; dst->first.pointer->references++; }
    if(src->second.pointer) { dst->second.pointer=src->second.pointer; dst->second.pointer->references++; }
    dst->vtable=w3d_vtable_8040d528;
    dst->weapon=21;
    dst->flags=335;
    return dst;
}

extern unsigned char w3d_vtable_8040d4e8[];
extern const float w3d_f32_8036a4a4[];
W3dS6ClonePlan *w3d_ai_clone_weapon1_80012a10(W3dS6ClonePlan *,W3dS6ClonePlan *);
W3dS6ClonePlan *w3d_ai_create_weapon1_800129d8(W3dS6ClonePlan *src) {
    return w3d_ai_clone_weapon1_80012a10(w3d_auto_8001523c(104),src);
}
W3dS6ClonePlan *w3d_ai_clone_weapon1_80012a10(W3dS6ClonePlan *dst,W3dS6ClonePlan *src) {
    void *volatile saved;
    w3d_path_cost_construct(dst);
    dst->vtable=w3d_vtable_8040d7b8;
    s6_clone_ref_init(&dst->first); s6_clone_ref_init(&dst->second);
    saved=dst->vtable;
    memcpy(dst,src,104);
    dst->vtable=saved;
    dst->score=*w3d_f32_8036a4a4;
    if(src->first.pointer) { dst->first.pointer=src->first.pointer; dst->first.pointer->references++; }
    if(src->second.pointer) { dst->second.pointer=src->second.pointer; dst->second.pointer->references++; }
    dst->vtable=w3d_vtable_8040d4e8;
    dst->weapon=1;
    dst->flags=335;
    return dst;
}

extern unsigned char w3d_vtable_8040d4a8[];
extern const float w3d_f32_8036a4a8[];
W3dS6ClonePlan *w3d_ai_clone_weapon2_80012b64(W3dS6ClonePlan *,W3dS6ClonePlan *);
W3dS6ClonePlan *w3d_ai_create_weapon2_80012b2c(W3dS6ClonePlan *src) {
    return w3d_ai_clone_weapon2_80012b64(w3d_auto_8001523c(104),src);
}
W3dS6ClonePlan *w3d_ai_clone_weapon2_80012b64(W3dS6ClonePlan *dst,W3dS6ClonePlan *src) {
    void *volatile saved;
    w3d_path_cost_construct(dst);
    dst->vtable=w3d_vtable_8040d7b8;
    s6_clone_ref_init(&dst->first); s6_clone_ref_init(&dst->second);
    saved=dst->vtable;
    memcpy(dst,src,104);
    dst->vtable=saved;
    dst->score=*w3d_f32_8036a4a8;
    if(src->first.pointer) { dst->first.pointer=src->first.pointer; dst->first.pointer->references++; }
    if(src->second.pointer) { dst->second.pointer=src->second.pointer; dst->second.pointer->references++; }
    dst->vtable=w3d_vtable_8040d4a8;
    dst->weapon=2;
    dst->flags=335;
    return dst;
}

extern unsigned char w3d_vtable_8040d468[];
extern const float w3d_f32_8036a4ac[];
W3dS6ClonePlan *w3d_ai_clone_weapon6_80012cb8(W3dS6ClonePlan *,W3dS6ClonePlan *);
W3dS6ClonePlan *w3d_ai_create_weapon6_80012c80(W3dS6ClonePlan *src) {
    return w3d_ai_clone_weapon6_80012cb8(w3d_auto_8001523c(104),src);
}
W3dS6ClonePlan *w3d_ai_clone_weapon6_80012cb8(W3dS6ClonePlan *dst,W3dS6ClonePlan *src) {
    void *volatile saved;
    w3d_path_cost_construct(dst);
    dst->vtable=w3d_vtable_8040d7b8;
    s6_clone_ref_init(&dst->first); s6_clone_ref_init(&dst->second);
    saved=dst->vtable;
    memcpy(dst,src,104);
    dst->vtable=saved;
    dst->score=*w3d_f32_8036a4ac;
    if(src->first.pointer) { dst->first.pointer=src->first.pointer; dst->first.pointer->references++; }
    if(src->second.pointer) { dst->second.pointer=src->second.pointer; dst->second.pointer->references++; }
    dst->vtable=w3d_vtable_8040d468;
    dst->weapon=6;
    dst->flags=335;
    return dst;
}

extern unsigned char w3d_vtable_8040d428[];
extern const float w3d_f32_8036a4b0[];
W3dS6ClonePlan *w3d_ai_clone_weapon34_80012e0c(W3dS6ClonePlan *,W3dS6ClonePlan *);
W3dS6ClonePlan *w3d_ai_create_weapon34_80012dd4(W3dS6ClonePlan *src) {
    return w3d_ai_clone_weapon34_80012e0c(w3d_auto_8001523c(104),src);
}
W3dS6ClonePlan *w3d_ai_clone_weapon34_80012e0c(W3dS6ClonePlan *dst,W3dS6ClonePlan *src) {
    void *volatile saved;
    w3d_path_cost_construct(dst);
    dst->vtable=w3d_vtable_8040d7b8;
    s6_clone_ref_init(&dst->first); s6_clone_ref_init(&dst->second);
    saved=dst->vtable;
    memcpy(dst,src,104);
    dst->vtable=saved;
    dst->score=*w3d_f32_8036a4b0;
    if(src->first.pointer) { dst->first.pointer=src->first.pointer; dst->first.pointer->references++; }
    if(src->second.pointer) { dst->second.pointer=src->second.pointer; dst->second.pointer->references++; }
    dst->vtable=w3d_vtable_8040d428;
    dst->weapon=34;
    dst->flags=335;
    return dst;
}

extern unsigned char w3d_vtable_8040d3e8[];
extern const float w3d_f32_8036a4b4[];
W3dS6ClonePlan *w3d_ai_clone_weapon5_80012f60(W3dS6ClonePlan *,W3dS6ClonePlan *);
W3dS6ClonePlan *w3d_ai_create_weapon5_80012f28(W3dS6ClonePlan *src) {
    return w3d_ai_clone_weapon5_80012f60(w3d_auto_8001523c(104),src);
}
W3dS6ClonePlan *w3d_ai_clone_weapon5_80012f60(W3dS6ClonePlan *dst,W3dS6ClonePlan *src) {
    void *volatile saved;
    w3d_path_cost_construct(dst);
    dst->vtable=w3d_vtable_8040d7b8;
    s6_clone_ref_init(&dst->first); s6_clone_ref_init(&dst->second);
    saved=dst->vtable;
    memcpy(dst,src,104);
    dst->vtable=saved;
    dst->score=*w3d_f32_8036a4b4;
    if(src->first.pointer) { dst->first.pointer=src->first.pointer; dst->first.pointer->references++; }
    if(src->second.pointer) { dst->second.pointer=src->second.pointer; dst->second.pointer->references++; }
    dst->flags=327;
    dst->vtable=w3d_vtable_8040d3e8;
    dst->weapon=5;
    return dst;
}
