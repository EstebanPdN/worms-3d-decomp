/* Activates a low-gravity utility once and posts its inventory messages. */
extern "C" {
struct S5GravityKey { const char *text; };
struct S5GravityVec { float x,y,z; };
struct S5GravityUtility { unsigned char reserved[36]; int activated; };
struct S5GravityName { unsigned value; const char *name; };
struct S5GravityMessage { unsigned short id; unsigned short reserved; void *vtable; };
extern const char w3d_str_8038304c[],w3d_str_80383060[],w3d_str_80383078[];
extern const float w3d_f32_8038308c[],w3d_f32_80383090[];
extern unsigned char w3d_message_vtable_8040db38[];
extern S5GravityName w3d_gravity_delete_804ae684,w3d_gravity_inventory_804ae694;
extern void *w3d_message_pool_804b1754;
void w3d_read_float_800fc270(S5GravityKey *,float *);
void w3d_write_float_800fc4c8(S5GravityKey *,float);
void *w3d_message_allocate_801613f0(void *,unsigned);
unsigned w3d_cached_message_id(S5GravityName *,int);
int w3d_message_post_current(void *);
void *w3d_int_message_init_80125fdc(void *,unsigned short,int);
void w3d_low_gravity_position_800c1b20(S5GravityVec *,S5GravityUtility *);
void w3d_effect_at_position_800e5ca4(float,S5GravityVec *,const char *,int);
void w3d_auto_8015fd1c(S5GravityUtility *);
/* 0x800c1a14: constant/name setup scheduling differs after seven attempts. */
#if 0
void w3d_low_gravity_activate_800c1a14(S5GravityUtility *utility)
{
    S5GravityVec position;
    if (!utility->activated) {
        struct { S5GravityKey name; float multiplier; S5GravityKey output; } local;
        local.multiplier=*w3d_f32_8038308c;
        local.name.text=w3d_str_8038304c;
        utility->activated=1;
        w3d_read_float_800fc270(&local.name,&local.multiplier);
        local.output.text=w3d_str_80383060;
        w3d_write_float_800fc4c8(&local.output,local.multiplier);
        S5GravityMessage *message=(S5GravityMessage*)w3d_message_allocate_801613f0(w3d_message_pool_804b1754,8);
        message->id=w3d_cached_message_id(&w3d_gravity_delete_804ae684,1);
        message->vtable=w3d_message_vtable_8040db38;
        w3d_message_post_current(message);
        void *inventory=w3d_message_allocate_801613f0(w3d_message_pool_804b1754,12);
        w3d_message_post_current(w3d_int_message_init_80125fdc(inventory,w3d_cached_message_id(&w3d_gravity_inventory_804ae694,1),44));
        w3d_low_gravity_position_800c1b20(&position,utility);
        w3d_effect_at_position_800e5ca4(*w3d_f32_80383090,&position,w3d_str_80383078,0);
        w3d_auto_8015fd1c(utility);
    }
}
#endif
}
