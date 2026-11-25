// All semantic roles and layouts inferred. Independent vector/matrix types.
struct F7HeadingVec{float x,y,z;F7HeadingVec(){}F7HeadingVec(float a,float b,float c){x=a;y=b;z=c;}F7HeadingVec(const F7HeadingVec&o){float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;}const float*data()const{return &x;}float norm2()const{return x*x+y*y+z*z;}void scale(float k){x*=k;y*=k;z*=k;}};
struct F7HeadingBasis{float m[9];F7HeadingBasis(){}F7HeadingBasis(float,float,float,float);};struct F7HeadingTranslation{float x,y,z;F7HeadingTranslation();};
struct F7HeadingMatrix{F7HeadingBasis basis;F7HeadingTranslation translation;};inline void*operator new(unsigned int,void*p){return p;}
extern const float zero_80389874[],one_80389878[];extern "C" float sqrt_802e82c0(float);
struct F7HeadingOwner{char p[88];float angle;char p2[40];float magnitude;};
extern "C" F7HeadingVec f7b_heading_800dbaf4(F7HeadingOwner*s){float zero=zero_80389874[0],one=one_80389878[0];F7HeadingVec v(zero,zero,one);F7HeadingMatrix m;new(&m.basis)F7HeadingBasis(zero,one,zero,s->angle);F7HeadingVec q;const float*e=v.data();const float*a=m.basis.m,*b=m.basis.m+3,*c=m.basis.m+6;const float*d=&m.translation.x;q.x=e[0]*a[0]+e[1]*b[0]+e[2]*c[0]+d[0];q.y=e[0]*a[1]+e[1]*b[1]+e[2]*c[1]+d[1];q.z=e[0]*a[2]+e[1]*b[2]+e[2]*c[2]+d[2];q.scale(one/sqrt_802e82c0(q.norm2()));q.scale(s->magnitude);return q;}
