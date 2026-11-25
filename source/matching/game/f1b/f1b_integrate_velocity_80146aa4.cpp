// Partial position/velocity state. A named scaled vector is materialized before
// the in-place add; this preserves single-precision intermediate rounding.
struct f1b_Vector {
 float x,y,z;
 f1b_Vector(){}
 f1b_Vector(float a,float b,float c):x(a),y(b),z(c){}
 f1b_Vector(const f1b_Vector &v){float a=v.x,b=v.y,c=v.z;x=a;y=b;z=c;}
 f1b_Vector operator*(float f)const{f1b_Vector out;out.x=x*f;out.y=y*f;out.z=z*f;return out;}
 f1b_Vector& operator+=(const f1b_Vector &v){x+=v.x;y+=v.y;z+=v.z;return *this;}
};
struct f1b_Motion { unsigned char unknown0[560];f1b_Vector position;unsigned char unknown572[104];f1b_Vector velocity; };
extern const float f1b_step_803a0fc0[],f1b_threshold_803a0fc4[],f1b_damp_803a0fc8[],f1b_target_803a0fcc[],f1b_ease_803a0fd0[];
extern "C" void f1b_integrate_velocity_80146aa4(f1b_Motion *self)
{
 f1b_Vector delta=self->velocity*f1b_step_803a0fc0[0];
 self->position+=delta;
 if(__builtin_fabsf(self->velocity.y)>f1b_threshold_803a0fc4[0])self->velocity.y*=f1b_damp_803a0fc8[0];
 else self->velocity.y=(f1b_target_803a0fcc[0]-self->velocity.y)*f1b_ease_803a0fd0[0]+self->velocity.y;
 self->velocity.x*=f1b_damp_803a0fc8[0];
 self->velocity.z*=f1b_damp_803a0fc8[0];
}
