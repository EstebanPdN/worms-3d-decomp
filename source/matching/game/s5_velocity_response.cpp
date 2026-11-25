/* Resolves a vector into normal and tangential responses with a speed cutoff. */
extern "C" {
struct S5Velocity { float x,y,z; };
extern const float w3d_f32_803831a0[];
float w3d_sqrt_802e82c0(float);
/* 0x800c2494: vector temporaries and floating-point register allocation differ. */
#if 0
void w3d_velocity_response_800c2494(S5Velocity *velocity,S5Velocity *normal,float bounce,float friction,float cutoff)
{
    S5Velocity projected,tangent,unused;
    float dot=velocity->z*normal->z+(velocity->x*normal->x+velocity->y*normal->y);
    if (dot>*w3d_f32_803831a0) {
        float length=w3d_sqrt_802e82c0(velocity->z*velocity->z+(velocity->x*velocity->x+velocity->y*velocity->y));
        if (length<cutoff) goto stop;
        *velocity=*normal;
        float scale=length*bounce;
        velocity->x*=scale; velocity->y*=scale; velocity->z*=scale;
    } else {
        projected.x=normal->x; projected.y=normal->y; projected.z=normal->z;
        projected.x*=dot; projected.y*=dot; projected.z*=dot;
        tangent.x=velocity->x-projected.x;
        tangent.y=velocity->y-projected.y;
        tangent.z=velocity->z-projected.z;
        projected.x*=bounce; projected.y*=bounce; projected.z*=bounce;
        tangent.x*=friction; tangent.y*=friction; tangent.z*=friction;
        velocity->x=tangent.x-projected.x;
        velocity->y=tangent.y-projected.y;
        velocity->z=tangent.z-projected.z;
        if ((velocity->z*velocity->z+(velocity->x*velocity->x+velocity->y*velocity->y))<cutoff*cutoff) {
stop:
            velocity->z=velocity->x=velocity->y=*w3d_f32_803831a0;
        }
    }
}
#endif
}
