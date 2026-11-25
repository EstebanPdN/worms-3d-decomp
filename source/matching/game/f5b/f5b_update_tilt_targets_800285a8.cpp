// All names, types, layouts and roles are inferred. 
struct Vec3{float x,y,z;Vec3(){}Vec3(const Vec3&o){float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;}Vec3 operator+(const Vec3&o)const{Vec3 r;r.x=x+o.x;r.y=y+o.y;r.z=z+o.z;return r;}};
extern "C" void fn_80028d10(void*);extern "C" void fn_80028e10(void*,int,int);extern "C" Vec3 fn_80028f48(void*);extern "C" const Vec3*fn_80178ec4(void*);
typedef int(*Set)(void*,const Vec3*,int);inline int dispatch(void*p,void**v,const Vec3&x,int mode){return ((Set)v[19])(p,&x,mode);}
struct Owner{char pad[28];int kind;int pad2;int value;void*first;void*second;Vec3 pos;char gap[52];void*offset;};
extern "C" int f5b_update_tilt_targets_800285a8(Owner*s,int value){int kind=s->kind;s->value=value;switch(kind){case 3:fn_80028d10(s);fn_80028e10(s,0,value);break;case 2:fn_80028e10(s,1,value);fn_80028d10(s);break;case 1:fn_80028d10(s);break;case 0:break;}void*p=s->first;void**v=*(void***)p;dispatch(p,v,s->pos+fn_80028f48(s)+*fn_80178ec4(s->offset),0);((Set)(*(void***)s->second)[19])(s->second,&s->pos,0);return 0;}
