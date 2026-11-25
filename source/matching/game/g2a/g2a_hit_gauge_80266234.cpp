#define F(p,T,o) (*(T*)((char*)(p)+(o)))
extern "C" float fn_802e82c0(float);
struct G2aHitVector {float x,y,z;
 G2aHitVector(){}
 G2aHitVector(float a,float b,float c):x(a),y(b),z(c){}
 G2aHitVector(const G2aHitVector&s){float a=s.x,b=s.y,c=s.z;x=a;y=b;z=c;}
 G2aHitVector operator*(const G2aHitVector&s)const{G2aHitVector result(x*s.x,y*s.y,z*s.z);return result;}
 G2aHitVector operator-(const G2aHitVector&s)const{G2aHitVector result(x-s.x,y-s.y,z-s.z);return result;}
 float length()const{return fn_802e82c0(x*x+y*y+z*z);}
};
extern "C" void fn_802b22e4(G2aHitVector*,void*);
extern "C" unsigned fn_802b15e0(void*,double,double);
extern int mode_804abb4c;
extern const float radius_803cb5c4[],zero_803cb5c8[];
inline float hitAbs(float n){return n<zero_803cb5c8[0]?-n:n;}
extern "C" unsigned w3d_g2a_hit_gauge_80266234(float x,float y,void*self){
 if(!F(self,int,140))goto nohit;
 if(F(self,int,432)==1)return fn_802b15e0((char*)self+28,x,y);
 if(mode_804abb4c!=1)goto radial;
 nohit:return 0;
 radial:{
 G2aHitVector pos;fn_802b22e4(&pos,(char*)self+28);
 void*p=F(self,void*,112);G2aHitVector scale(*(*(const G2aHitVector*(***)(void*))(p))[27](p));
 G2aHitVector size(F(F(self,void*,40),G2aHitVector,20));size=size*scale;size.x*=radius_803cb5c4[0];
 G2aHitVector point(x,y,pos.z);float distance=(point-pos).length();
 distance=hitAbs(distance);size.x=hitAbs(size.x);return distance<=size.x;
 }
}
