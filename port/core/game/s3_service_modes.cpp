#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s3_service_modes.c"
/* Worm selection and service mode helpers, with observed field offsets. */
typedef struct S3Interface S3Interface;
typedef struct S3Vtable {Ptr32<void (void)> unused[3]; Ptr32<void (Ptr32<S3Interface>)> retain;Ptr32<void (Ptr32<S3Interface>)> release;} S3Vtable;
struct S3Interface {Ptr32<S3Vtable> vtable;};
typedef struct S3Choice {Ptr32<void> vtable;unsigned char pad04[28-4];Ptr32<S3Interface> held[9];int enabled,pending,previous;} S3Choice;
typedef struct S3ModeVtable {Ptr32<void (void)> unused[6];Ptr32<int (Ptr32<void>)> query;} S3ModeVtable;
typedef struct S3Mode {
 unsigned char pad00[8];float first;
 unsigned char pad0c[20-12];float second;
 unsigned char pad18[40-24];Ptr32<S3Interface> held_a;
 unsigned char pad2c[52-44];int state;Ptr32<S3Interface> held_b;Ptr32<const char> text;Ptr32<S3Interface> coefficient; Ptr32<S3Interface> held_c;Ptr32<S3ModeVtable> vtable;
} S3Mode;
typedef struct S3Cache {int id;Ptr32<const char> name;} S3Cache;
typedef struct S3Message {unsigned short id,pad02;Ptr32<void> type;} S3Message;
typedef struct S3Vec {float x,y,z;} S3Vec;
typedef struct S3VecLocal {S3Vec value;int unused;} S3VecLocal;
extern void w3d_actor_base_destroy(Ptr32<S3Choice>,int);
extern int w3d_actor_base_initialize(Ptr32<S3Choice>);
extern Ptr32<void> w3d_vtable_80410f80[]; extern Ptr32<void> w3d_vtable_80410ff0[];
extern const char w3d_str_803a3fd0[];
extern int w3d_fn_800fc43c(Ptr32<Ptr32<const char>>,int);
extern volatile int w3d_flag_804ab40c;
extern Ptr32<void> w3d_global_804b1754; extern Ptr32<void> w3d_type_8040db38[];
extern S3Cache w3d_cache_804affc8;
extern Ptr32<S3Message> w3d_fn_801613f0(Ptr32<void>,int);
extern short w3d_cached_message_id(Ptr32<S3Cache>,int);
extern void w3d_auto_8015fd1c(Ptr32<S3Choice>);
extern int w3d_message_post_current(Ptr32<S3Message>);
extern Ptr32<void> w3d_scene_804aa8c8; extern Ptr32<void> w3d_fallback_804b1924;
extern Ptr32<void> w3d_fn_80033208(Ptr32<void>,Ptr32<void>);
extern void w3d_string_base_finish(Ptr32<Ptr32<const char>>),w3d_string_release(Ptr32<Ptr32<const char>>);
extern unsigned char w3d_heap_804b0044;
extern void w3d_heap_release(Ptr32<void>,Ptr32<void>);
extern float w3d_auto_80178df0(Ptr32<S3Interface>);
extern Ptr32<void> w3d_global_804b1760;
extern int w3d_fn_80020834(Ptr32<void>),w3d_fn_800b0788(Ptr32<S3Vec>,Ptr32<S3Vec>);
static __inline__ void s3_release(Ptr32<S3Interface> object) {if(object) object->vtable->release(object);}
static __inline__ void s3_vec_set(Ptr32<S3Vec> out,float x,float y,float z) {out->x=x;out->y=y;out->z=z;}
static __inline__ void s3_difference(Ptr32<S3Vec> out,Ptr32<const S3Vec> a,Ptr32<const S3Vec> b) {s3_vec_set(out,a->x-b->x,a->y-b->y,a->z-b->z);}

Ptr32<S3Choice> w3d_choose_worm_construct(Ptr32<S3Choice> self) {
 Ptr32<const char> key;
 w3d_actor_base_initialize(self); self->vtable=w3d_vtable_80410f80;
 self->held[0]=0;self->held[1]=0;self->held[2]=0;self->held[3]=0;self->held[4]=0;self->held[5]=0;self->held[6]=0;self->held[7]=0;self->held[8]=0;
 key=w3d_str_803a3fd0;w3d_fn_800fc43c(&key,1);return self;
}

#if 0 /* 0x80159538: two global-store setup instructions differ after two revisions. */
void w3d_choose_worm_destroy(S3Choice *self,int flags) {
 const char *key;
 self->vtable=w3d_vtable_80410f80; w3d_flag_804ab40c=0;
 key=w3d_str_803a3fd0;w3d_fn_800fc43c(&key,0);
 s3_release(self->held[8]);s3_release(self->held[7]);s3_release(self->held[6]);s3_release(self->held[5]);s3_release(self->held[4]);s3_release(self->held[3]);s3_release(self->held[2]);s3_release(self->held[1]);s3_release(self->held[0]);
 w3d_actor_base_destroy(self,flags);
}
#endif

void w3d_choose_worm_finish(Ptr32<S3Choice> self) {
 Ptr32<S3Message> message=w3d_fn_801613f0(w3d_global_804b1754,8);
 message->id=w3d_cached_message_id(&w3d_cache_804affc8,1);message->type=w3d_type_8040db38;
 w3d_message_post_current(message);w3d_flag_804ab40c=0;w3d_auto_8015fd1c(self);
}

#if 0 /* 0x80159fec: fallback branch layout and first call argument setup differ after one revision. */
void *w3d_service_query_scene_twice(void *self,void *value) {
 void *scene=w3d_scene_804aa8c8;
 if(!scene) return w3d_fallback_804b1924;
 w3d_fn_80033208(scene,value);return w3d_fn_80033208(scene,value);
}
#endif

void w3d_service_mode_destroy(Ptr32<S3Mode> self,int flags) {
 self->vtable=(Ptr32<S3ModeVtable>)w3d_vtable_80410ff0;
 s3_release(self->held_c);s3_release(self->coefficient);
 w3d_string_base_finish(&self->text);w3d_string_release(&self->text);
 s3_release(self->held_b);s3_release(self->held_a);
 if(flags&1) w3d_heap_release(&w3d_heap_804b0044,self);
}

int w3d_service_mode_virtual_query(Ptr32<S3Mode> self) {return self->vtable->query(self);}

int w3d_service_mode_is_inactive(Ptr32<S3Mode> self) {return self->state==0;}

#if 0 /* 0x8015ab54: small-struct and floating register layout differ after three revisions. */
void w3d_service_mode_raise_limits(S3Mode *self,float first,float second) {
 struct {float value;int unused;} a,b;
 float limit;
 a.value=first;b.value=second;
 limit=w3d_auto_80178df0(self->coefficient)+a.value;
 if(self->first<limit) self->first=limit;
 limit=w3d_auto_80178df0(self->coefficient)+b.value;
 if(self->second<limit) self->second=limit;
}
#endif

int w3d_service_optional_context_query(void) {
 int result=0;
 if(w3d_global_804b1760) result=w3d_fn_80020834(w3d_global_804b1760);
 return result;
}

#if 0 /* 0x8015ac04: vector subtraction temporary allocation differs after three revisions. */
int w3d_service_segment_test_inverse(void *self,S3Vec *a,S3Vec *b) {
 S3VecLocal direction,temporary;
 float x=b->x-a->x,y=b->y-a->y,z=b->z-a->z;
 s3_vec_set(&direction.value,x,y,z);s3_vec_set(&temporary.value,x,y,z);
 return w3d_fn_800b0788(a,&direction.value)^1;
}
#endif

}
