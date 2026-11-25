#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "genparam_80013a18.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

typedef struct { unsigned char unknown00[44]; int references; } W3dS6CloneQueue;
typedef struct {int unknown; Ptr32<W3dS6CloneQueue> pointer;} W3dS6CloneRef;
static inline void s6_clone_ref_init(Ptr32<W3dS6CloneRef> ref) {ref->pointer=0;}
typedef struct { int kind; float score; int active; Ptr32<void> volatile vtable; int index,weapon; unsigned char unknown18[44]; int flags; W3dS6CloneRef first,second; unsigned char unknown58[16]; } W3dS6ClonePlan;
Ptr32<void> w3d_auto_8001523c(unsigned);
Ptr32<void> memcpy(Ptr32<void>,Ptr32<const void>,unsigned);
void w3d_path_cost_construct(Ptr32<W3dS6ClonePlan>);
extern unsigned char w3d_vtable_8040d7b8[],w3d_vtable_8040d780[],w3d_vtable_8040d5e8[];
extern const float w3d_f32_8036a478[],w3d_f32_8036a494[];
extern unsigned char w3d_vtable_8040d148[];
extern const float w3d_f32_8036a4e0[];
extern unsigned char w3d_vtable_8040d568[];
extern const float w3d_f32_8036a49c[];
extern unsigned char w3d_vtable_8040d528[];
extern const float w3d_f32_8036a4a0[];
extern unsigned char w3d_vtable_8040d4e8[];
extern const float w3d_f32_8036a4a4[];
extern unsigned char w3d_vtable_8040d4a8[];
extern const float w3d_f32_8036a4a8[];
extern unsigned char w3d_vtable_8040d468[];
extern const float w3d_f32_8036a4ac[];
extern unsigned char w3d_vtable_8040d428[];
extern const float w3d_f32_8036a4b0[];
extern unsigned char w3d_vtable_8040d3e8[];
extern const float w3d_f32_8036a4b4[];

extern unsigned char w3d_vtable_8040d110[];
extern const float w3d_f32_8036a4e4[];

extern unsigned char w3d_vtable_8040d0a0[];
extern const float w3d_f32_8036a4ec[];

extern unsigned char w3d_vtable_8040d068[];
extern const float w3d_f32_8036a4f0[];

extern unsigned char w3d_vtable_8040d030[];
extern const float w3d_f32_8036a4f4[];

extern unsigned char w3d_vtable_8040cff8[];
extern const float w3d_f32_8036a4f8[];

extern unsigned char w3d_vtable_8040cf88[];
extern const float w3d_f32_8036a500[];

extern unsigned char w3d_vtable_8040cf50[];
extern const float w3d_f32_8036a504[];

extern unsigned char w3d_vtable_8040cee0[];
extern const float w3d_f32_8036a50c[];

extern unsigned char w3d_vtable_8040cea8[];
extern const float w3d_f32_8036a510[];

extern unsigned char w3d_vtable_8040ce70[];
extern const float w3d_f32_8036a514[];

extern unsigned char w3d_vtable_8040ce38[];
extern const float w3d_f32_8036a518[];

extern unsigned char w3d_vtable_8040cd90[];
extern const float w3d_f32_8036a524[];

extern unsigned char w3d_vtable_8040cd58[];
extern const float w3d_f32_8036a528[];


Ptr32<W3dS6ClonePlan> w3d_ai_clone_plan_80013a18(Ptr32<W3dS6ClonePlan> dst,Ptr32<W3dS6ClonePlan> src) {
    Ptr32<void> volatile saved;
    w3d_path_cost_construct(dst);
    dst->vtable=w3d_vtable_8040d7b8;
    s6_clone_ref_init(&dst->first); s6_clone_ref_init(&dst->second);
    saved=dst->vtable;
    memcpy(dst,src,104);
    dst->vtable=saved;
    dst->score=*w3d_f32_8036a4e0;
    if(src->first.pointer) { dst->first.pointer=src->first.pointer; dst->first.pointer->references++; }
    if(src->second.pointer) { dst->second.pointer=src->second.pointer; dst->second.pointer->references++; }
    dst->flags=368;
    dst->vtable=w3d_vtable_8040d148;
    dst->weapon=22;
    return dst;
}

Ptr32<W3dS6ClonePlan> w3d_ai_clone_plan_80013b6c(Ptr32<W3dS6ClonePlan> dst,Ptr32<W3dS6ClonePlan> src) {
    Ptr32<void> volatile saved;
    w3d_path_cost_construct(dst);
    dst->vtable=w3d_vtable_8040d7b8;
    s6_clone_ref_init(&dst->first); s6_clone_ref_init(&dst->second);
    saved=dst->vtable;
    memcpy(dst,src,104);
    dst->vtable=saved;
    dst->score=*w3d_f32_8036a4e4;
    if(src->first.pointer) { dst->first.pointer=src->first.pointer; dst->first.pointer->references++; }
    if(src->second.pointer) { dst->second.pointer=src->second.pointer; dst->second.pointer->references++; }
    dst->flags=368;
    dst->vtable=w3d_vtable_8040d110;
    dst->weapon=25;
    return dst;
}

Ptr32<W3dS6ClonePlan> w3d_ai_clone_plan_80013cc8(Ptr32<W3dS6ClonePlan> dst,Ptr32<W3dS6ClonePlan> src) {
    Ptr32<void> volatile saved;
    w3d_path_cost_construct(dst);
    dst->vtable=w3d_vtable_8040d7b8;
    s6_clone_ref_init(&dst->first); s6_clone_ref_init(&dst->second);
    saved=dst->vtable;
    memcpy(dst,src,104);
    dst->vtable=saved;
    dst->score=*w3d_f32_8036a4ec;
    if(src->first.pointer) { dst->first.pointer=src->first.pointer; dst->first.pointer->references++; }
    if(src->second.pointer) { dst->second.pointer=src->second.pointer; dst->second.pointer->references++; }
    dst->flags=1092;
    dst->vtable=w3d_vtable_8040d0a0;
    dst->weapon=10;
    return dst;
}

Ptr32<W3dS6ClonePlan> w3d_ai_clone_plan_80013e1c(Ptr32<W3dS6ClonePlan> dst,Ptr32<W3dS6ClonePlan> src) {
    Ptr32<void> volatile saved;
    w3d_path_cost_construct(dst);
    dst->vtable=w3d_vtable_8040d7b8;
    s6_clone_ref_init(&dst->first); s6_clone_ref_init(&dst->second);
    saved=dst->vtable;
    memcpy(dst,src,104);
    dst->vtable=saved;
    dst->score=*w3d_f32_8036a4f0;
    if(src->first.pointer) { dst->first.pointer=src->first.pointer; dst->first.pointer->references++; }
    if(src->second.pointer) { dst->second.pointer=src->second.pointer; dst->second.pointer->references++; }
    dst->flags=1092;
    dst->vtable=w3d_vtable_8040d068;
    dst->weapon=11;
    return dst;
}

Ptr32<W3dS6ClonePlan> w3d_ai_clone_plan_80013f70(Ptr32<W3dS6ClonePlan> dst,Ptr32<W3dS6ClonePlan> src) {
    Ptr32<void> volatile saved;
    w3d_path_cost_construct(dst);
    dst->vtable=w3d_vtable_8040d7b8;
    s6_clone_ref_init(&dst->first); s6_clone_ref_init(&dst->second);
    saved=dst->vtable;
    memcpy(dst,src,104);
    dst->vtable=saved;
    dst->score=*w3d_f32_8036a4f4;
    if(src->first.pointer) { dst->first.pointer=src->first.pointer; dst->first.pointer->references++; }
    if(src->second.pointer) { dst->second.pointer=src->second.pointer; dst->second.pointer->references++; }
    dst->flags=1092;
    dst->vtable=w3d_vtable_8040d030;
    dst->weapon=12;
    return dst;
}

Ptr32<W3dS6ClonePlan> w3d_ai_clone_plan_800140c4(Ptr32<W3dS6ClonePlan> dst,Ptr32<W3dS6ClonePlan> src) {
    Ptr32<void> volatile saved;
    w3d_path_cost_construct(dst);
    dst->vtable=w3d_vtable_8040d7b8;
    s6_clone_ref_init(&dst->first); s6_clone_ref_init(&dst->second);
    saved=dst->vtable;
    memcpy(dst,src,104);
    dst->vtable=saved;
    dst->score=*w3d_f32_8036a4f8;
    if(src->first.pointer) { dst->first.pointer=src->first.pointer; dst->first.pointer->references++; }
    if(src->second.pointer) { dst->second.pointer=src->second.pointer; dst->second.pointer->references++; }
    dst->flags=1092;
    dst->vtable=w3d_vtable_8040cff8;
    dst->weapon=13;
    return dst;
}

Ptr32<W3dS6ClonePlan> w3d_ai_clone_plan_80014220(Ptr32<W3dS6ClonePlan> dst,Ptr32<W3dS6ClonePlan> src) {
    Ptr32<void> volatile saved;
    w3d_path_cost_construct(dst);
    dst->vtable=w3d_vtable_8040d7b8;
    s6_clone_ref_init(&dst->first); s6_clone_ref_init(&dst->second);
    saved=dst->vtable;
    memcpy(dst,src,104);
    dst->vtable=saved;
    dst->score=*w3d_f32_8036a500;
    if(src->first.pointer) { dst->first.pointer=src->first.pointer; dst->first.pointer->references++; }
    if(src->second.pointer) { dst->second.pointer=src->second.pointer; dst->second.pointer->references++; }
    dst->flags=1345;
    dst->vtable=w3d_vtable_8040cf88;
    dst->weapon=4;
    return dst;
}

Ptr32<W3dS6ClonePlan> w3d_ai_clone_plan_80014374(Ptr32<W3dS6ClonePlan> dst,Ptr32<W3dS6ClonePlan> src) {
    Ptr32<void> volatile saved;
    w3d_path_cost_construct(dst);
    dst->vtable=w3d_vtable_8040d7b8;
    s6_clone_ref_init(&dst->first); s6_clone_ref_init(&dst->second);
    saved=dst->vtable;
    memcpy(dst,src,104);
    dst->vtable=saved;
    dst->score=*w3d_f32_8036a504;
    if(src->first.pointer) { dst->first.pointer=src->first.pointer; dst->first.pointer->references++; }
    if(src->second.pointer) { dst->second.pointer=src->second.pointer; dst->second.pointer->references++; }
    dst->flags=1345;
    dst->vtable=w3d_vtable_8040cf50;
    dst->weapon=7;
    return dst;
}

Ptr32<W3dS6ClonePlan> w3d_ai_clone_plan_800144c8(Ptr32<W3dS6ClonePlan> dst,Ptr32<W3dS6ClonePlan> src) {
    Ptr32<void> volatile saved;
    w3d_path_cost_construct(dst);
    dst->vtable=w3d_vtable_8040d7b8;
    s6_clone_ref_init(&dst->first); s6_clone_ref_init(&dst->second);
    saved=dst->vtable;
    memcpy(dst,src,104);
    dst->vtable=saved;
    dst->score=*w3d_f32_8036a50c;
    if(src->first.pointer) { dst->first.pointer=src->first.pointer; dst->first.pointer->references++; }
    if(src->second.pointer) { dst->second.pointer=src->second.pointer; dst->second.pointer->references++; }
    dst->flags=1353;
    dst->vtable=w3d_vtable_8040cee0;
    dst->weapon=1;
    return dst;
}

Ptr32<W3dS6ClonePlan> w3d_ai_clone_plan_8001461c(Ptr32<W3dS6ClonePlan> dst,Ptr32<W3dS6ClonePlan> src) {
    Ptr32<void> volatile saved;
    w3d_path_cost_construct(dst);
    dst->vtable=w3d_vtable_8040d7b8;
    s6_clone_ref_init(&dst->first); s6_clone_ref_init(&dst->second);
    saved=dst->vtable;
    memcpy(dst,src,104);
    dst->vtable=saved;
    dst->score=*w3d_f32_8036a510;
    if(src->first.pointer) { dst->first.pointer=src->first.pointer; dst->first.pointer->references++; }
    if(src->second.pointer) { dst->second.pointer=src->second.pointer; dst->second.pointer->references++; }
    dst->flags=1353;
    dst->vtable=w3d_vtable_8040cea8;
    dst->weapon=2;
    return dst;
}

Ptr32<W3dS6ClonePlan> w3d_ai_clone_plan_80014770(Ptr32<W3dS6ClonePlan> dst,Ptr32<W3dS6ClonePlan> src) {
    Ptr32<void> volatile saved;
    w3d_path_cost_construct(dst);
    dst->vtable=w3d_vtable_8040d7b8;
    s6_clone_ref_init(&dst->first); s6_clone_ref_init(&dst->second);
    saved=dst->vtable;
    memcpy(dst,src,104);
    dst->vtable=saved;
    dst->score=*w3d_f32_8036a514;
    if(src->first.pointer) { dst->first.pointer=src->first.pointer; dst->first.pointer->references++; }
    if(src->second.pointer) { dst->second.pointer=src->second.pointer; dst->second.pointer->references++; }
    dst->flags=1353;
    dst->vtable=w3d_vtable_8040ce70;
    dst->weapon=6;
    return dst;
}

Ptr32<W3dS6ClonePlan> w3d_ai_clone_plan_800148c4(Ptr32<W3dS6ClonePlan> dst,Ptr32<W3dS6ClonePlan> src) {
    Ptr32<void> volatile saved;
    w3d_path_cost_construct(dst);
    dst->vtable=w3d_vtable_8040d7b8;
    s6_clone_ref_init(&dst->first); s6_clone_ref_init(&dst->second);
    saved=dst->vtable;
    memcpy(dst,src,104);
    dst->vtable=saved;
    dst->score=*w3d_f32_8036a518;
    if(src->first.pointer) { dst->first.pointer=src->first.pointer; dst->first.pointer->references++; }
    if(src->second.pointer) { dst->second.pointer=src->second.pointer; dst->second.pointer->references++; }
    dst->flags=1345;
    dst->vtable=w3d_vtable_8040ce38;
    dst->weapon=33;
    return dst;
}

Ptr32<W3dS6ClonePlan> w3d_ai_clone_plan_80014b74(Ptr32<W3dS6ClonePlan> dst,Ptr32<W3dS6ClonePlan> src) {
    Ptr32<void> volatile saved;
    w3d_path_cost_construct(dst);
    dst->vtable=w3d_vtable_8040d7b8;
    s6_clone_ref_init(&dst->first); s6_clone_ref_init(&dst->second);
    saved=dst->vtable;
    memcpy(dst,src,104);
    dst->vtable=saved;
    dst->score=*w3d_f32_8036a524;
    if(src->first.pointer) { dst->first.pointer=src->first.pointer; dst->first.pointer->references++; }
    if(src->second.pointer) { dst->second.pointer=src->second.pointer; dst->second.pointer->references++; }
    dst->flags=1345;
    dst->vtable=w3d_vtable_8040cd90;
    dst->weapon=24;
    return dst;
}

Ptr32<W3dS6ClonePlan> w3d_ai_clone_plan_80014cc8(Ptr32<W3dS6ClonePlan> dst,Ptr32<W3dS6ClonePlan> src) {
    Ptr32<void> volatile saved;
    w3d_path_cost_construct(dst);
    dst->vtable=w3d_vtable_8040d7b8;
    s6_clone_ref_init(&dst->first); s6_clone_ref_init(&dst->second);
    saved=dst->vtable;
    memcpy(dst,src,104);
    dst->vtable=saved;
    dst->score=*w3d_f32_8036a528;
    if(src->first.pointer) { dst->first.pointer=src->first.pointer; dst->first.pointer->references++; }
    if(src->second.pointer) { dst->second.pointer=src->second.pointer; dst->second.pointer->references++; }
    dst->flags=1345;
    dst->vtable=w3d_vtable_8040cd58;
    dst->weapon=23;
    return dst;
}

}
