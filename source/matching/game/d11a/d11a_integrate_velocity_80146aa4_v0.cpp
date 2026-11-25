// Partial position/velocity state. A named scaled vector is materialized before
// the in-place add; this preserves single-precision intermediate rounding.
struct d11a_Vector {
 float x,y,z;
 d11a_Vector(){}
 d11a_Vector(float a,float b,float c):x(a),y(b),z(c){}
 d11a_Vector(const d11a_Vector &v){float a=v.x,b=v.y,c=v.z;x=a;y=b;z=c;}
 d11a_Vector operator*(float f)const{return d11a_Vector(x*f,y*f,z*f);}
 d11a_Vector& operator+=(const d11a_Vector &v){x+=v.x;y+=v.y;z+=v.z;return *this;}
};
struct d11a_Motion { unsigned char unknown0[560];d11a_Vector position;unsigned char unknown572[104];d11a_Vector velocity; };
extern const float d11a_step_803a0fc0[],d11a_threshold_803a0fc4[],d11a_damp_803a0fc8[],d11a_target_803a0fcc[],d11a_ease_803a0fd0[];
extern "C" double fabs(double);
extern "C" void d11a_integrate_velocity_80146aa4(d11a_Motion *self)
{
 d11a_Vector scaled=self->velocity*d11a_step_803a0fc0[0];
 self->position+=scaled;
 float y=self->velocity.y;
 if(fabs(y)>d11a_threshold_803a0fc4[0])y*=d11a_damp_803a0fc8[0];
 else y=(d11a_target_803a0fcc[0]-y)*d11a_ease_803a0fd0[0]+y;
 self->velocity.y=y;
 self->velocity.x*=d11a_damp_803a0fc8[0];
 self->velocity.z*=d11a_damp_803a0fc8[0];
}
