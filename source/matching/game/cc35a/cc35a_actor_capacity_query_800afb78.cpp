
typedef unsigned int cc35a_u32;
struct cc35a_Vector_800afb78 {float x,y,z; cc35a_Vector_800afb78(const cc35a_Vector_800afb78& rhs){float a=rhs.x,b=rhs.y,c=rhs.z;x=a;y=b;z=c;}};
struct cc35a_Actor_800afb78 {char prefix[60]; cc35a_Vector_800afb78 point;char gap[12];int maximum;char gap2[104];void* context;char gap3[172];int spent;};
struct cc35a_Message_800afb78 {unsigned short id,unused;void* vtable;};
extern "C" {
void * cc35a_context_80341584(void*);void* cc35a_get_801797b4(void *);
void cc35a_query_800b0824(void*,void*,cc35a_Vector_800afb78*,cc35a_u32,int);
extern cc35a_u32 cc35a_result_804b1764;extern void* cc35a_arena_804b1754;extern int cc35a_state_804b1784;
void* cc35a_allocate_801613f0(void*,cc35a_u32);cc35a_u32 cc35a_id_8015f5a0(void*,int);
extern cc35a_u32 cc35a_cache_804ae434[2];extern char cc35a_vtable_8040db38[];
int cc35a_post_8016239c(void*);void cc35a_flush_800bd920();
extern cc35a_Vector_800afb78 cc35a_vector_8043ae38[];extern float cc35a_limit_803822d8[];
}
extern "C" bool cc35a_actor_capacity_query_800afb78(cc35a_Actor_800afb78* self,void* a,void* b,cc35a_u32* count,cc35a_u32* below){cc35a_get_801797b4((void *)cc35a_context_80341584(self->context));
 cc35a_u32 available=self->maximum<0 ? 10000 : self->maximum-self->spent;
 cc35a_query_800b0824(a,b,&self->point,available,1);
 *count=cc35a_result_804b1764;
 cc35a_Message_800afb78* message=(cc35a_Message_800afb78*)cc35a_allocate_801613f0(cc35a_arena_804b1754,8);
 message->id=cc35a_id_8015f5a0(cc35a_cache_804ae434,1);message->vtable=cc35a_vtable_8040db38;
 cc35a_post_8016239c(message);
 if(cc35a_state_804b1784==0)cc35a_flush_800bd920();
 cc35a_Vector_800afb78 point(cc35a_vector_8043ae38[0]);*below=point.y<cc35a_limit_803822d8[0];
 return *count<=available;
}
