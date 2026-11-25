/* Camera owner and active-worm point extraction. */
extern "C" {
struct S5CameraVec { float x,y,z; };
struct S5CameraObject { unsigned char reserved[80]; S5CameraVec position; };
struct S5CameraOwner { unsigned char reserved[272]; int handle; };
struct S5CameraKey { const char *text; };
extern const char w3d_str_80387f48[],w3d_str_803880c0[];
extern const float w3d_f32_80388130[];
S5CameraObject *w3d_camera_resolve_800fc6dc(int);
void * w3d_camera_read_int_800fc1f0(S5CameraKey *,int *);
void w3d_camera_read_float_800fc270(S5CameraKey *,float *);
static inline void s5_camera_set(S5CameraVec *out,float x,float y,float z) { out->x=x;out->y=y;out->z=z; }
static inline void s5_camera_copy(S5CameraVec *out,const S5CameraVec *source) { s5_camera_set(out,source->x,source->y,source->z); }
S5CameraVec *w3d_camera_owner_position_800cfcac(S5CameraVec *out,S5CameraOwner *owner)
{
    S5CameraObject *object=w3d_camera_resolve_800fc6dc(owner->handle);
    s5_camera_copy(out,&object->position);
    return out;
}
S5CameraVec *w3d_camera_active_position_800cfcfc(S5CameraVec *out)
{
    S5CameraVec position;
    S5CameraKey active; active.text=w3d_str_80387f48;
    int index;
    w3d_camera_read_int_800fc1f0(&active,&index);
    position=w3d_camera_resolve_800fc6dc(index)->position;
    S5CameraKey eye; eye.text=w3d_str_803880c0;
    float offset;
    w3d_camera_read_float_800fc270(&eye,&offset);
    s5_camera_copy(out,&position);
    return out;
}
S5CameraVec *w3d_camera_owner_raised_position_800cfd98(S5CameraVec *out,S5CameraOwner *owner)
{
    S5CameraObject *object=w3d_camera_resolve_800fc6dc(owner->handle);
    S5CameraVec position;
    s5_camera_copy(&position,&object->position);
    position.y+=*w3d_f32_80388130;
    s5_camera_copy(out,&position);
    return out;
}
}
