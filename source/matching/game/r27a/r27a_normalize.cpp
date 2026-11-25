struct Vec {float x,y,z;Vec(const Vec &v):x(v.x),y(v.y),z(v.z){} inline float length2()const{return x*x+y*y+z*z;} inline void scale(float s){x*=s;y*=s;z*=s;} };
struct Obj {void **v;};
extern "C" {float fn_802e82c0(float);void fn_8003ebdc(Obj*,Vec*);extern float lbl_80374670[],lbl_80374674[];
void r27a_normalize_8003eb1c(Obj *self,int a,int b,const Vec *v){((int(*)(Obj*,int,int,const Vec*))self->v[10])(self,a,b,v);Vec local(*v);float d=fn_802e82c0(local.length2());local.scale(lbl_80374670[0]/d);if(local.y>lbl_80374674[0])fn_8003ebdc(self,&local);}}
