/* Optional owner queries and trail detachment. */
extern "C" {
struct S5TrailVec { float x,y,z; };
struct S5TrailHandle { int value; S5TrailHandle() { value=-1; } };
struct S5TrailOwner { unsigned char reserved[28]; int owner_handle; S5TrailHandle trail_handle; };
extern S5TrailVec w3d_zero_vector_8045e788[];
extern const float w3d_f32_80387e24[];
void *w3d_owner_resolve_80164fc8(int);
void w3d_owner_vector_800d1104(S5TrailVec *,void *);
float w3d_getf_800d1128(void *);
int w3d_get_800d1c14(void *);
void w3d_trail_graphic_entity_set_flag_80122af8(void *);
static inline void s5_trail_vector_set(S5TrailVec *value,float x,float y,float z) { value->x=x; value->y=y; value->z=z; }
S5TrailVec *w3d_trail_owner_vector_800cd0d0(S5TrailVec *output,S5TrailOwner *owner)
{
    void *object=w3d_owner_resolve_80164fc8(owner->owner_handle);
    if(!object) {
        s5_trail_vector_set(output,w3d_zero_vector_8045e788->x,w3d_zero_vector_8045e788->y,w3d_zero_vector_8045e788->z);
    } else w3d_owner_vector_800d1104(output,object);
    return output;
}
float w3d_trail_owner_float_800cd13c(S5TrailOwner *owner)
{
    void *object=w3d_owner_resolve_80164fc8(owner->owner_handle);
    float value;
    if(object) value=w3d_getf_800d1128(object);
    else value=*w3d_f32_80387e24;
    return value;
}
int w3d_trail_owner_value_800cd7fc(S5TrailOwner *owner)
{
    void *object=w3d_owner_resolve_80164fc8(owner->owner_handle);
    int value;
    if(object) value=w3d_get_800d1c14(object);
    else value=0;
    return value;
}
/* 0x800cd990: invalid-handle temporary is rematerialized instead of held in r30 after three attempts. */
#if 0
void w3d_trail_release_entity_800cd990(S5TrailOwner *owner)
{
    S5TrailHandle invalid;
    if(owner->trail_handle.value!=-1) {
        void *object=w3d_owner_resolve_80164fc8(owner->trail_handle.value);
        if(object) w3d_trail_graphic_entity_set_flag_80122af8(object);
        owner->trail_handle=invalid;
    }
}
#endif
}
