// Original 0x802c4d3c: observed vector setup; field meanings inferred.
// Locally named binary32 constants retain the original constant-pool order.
struct Vec3 {
 float x,y,z;Vec3(){}Vec3(float a,float b,float c):x(a),y(b),z(c){}
 Vec3(const Vec3 &v){float a=v.x,b=v.y,c=v.z;x=a;y=b;z=c;}
 void set(float a,float b,float c){x=a;y=b;z=c;}
 Vec3 operator*(float s)const {Vec3 r;r.x=x*s;r.y=y*s;r.z=z*s;return r;}
 void negate(){x=-x;y=-y;z=-z;}
};
struct Owner {char pad[268];Vec3 position,ratio,delta,factors;float scale;};
extern "C" void w3d_setup_vectors_802c4d3c(Owner *self,const Vec3 *position,const Vec3 *size) {
 const float width=214.0f,height=155.0f,one=1.0f;
 self->scale=10.0f;
 self->position=*position;
 Vec3 normal(width,height,one);
 self->delta=self->position*(1.0f/self->scale);
 self->delta.negate();self->delta.z=0.0f;
 self->ratio.set(size->x/normal.x,size->y/normal.y,1.0f);
 self->factors.set((1.0f-self->ratio.x)/self->scale,(1.0f-self->ratio.y)/self->scale,0.0f);
}
