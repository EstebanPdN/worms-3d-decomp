// Names and partial matrix/vector API are inferred from original instructions.
struct F13bV { float x,y,z; };
struct F13bM { F13bV x; float xw; F13bV y; float yw; F13bV z; float zw; F13bV t; float tw; };
inline void transformParts(F13bV& out,const F13bV& v,const F13bV& mx,const F13bV& my,const F13bV& mz,const F13bV& mt){
 float y=v.y,x=v.x,z=v.z;
 out.x=x*mx.x+y*my.x+z*mz.x+mt.x;
 out.y=x*mx.y+y*my.y+z*mz.y+mt.y;
 out.z=x*mx.z+y*my.z+z*mz.z+mt.z;
}
inline void transform(F13bV&out,const F13bV&v,const F13bM&m){transformParts(out,v,m.x,m.y,m.z,m.t);}
inline void scale(F13bV& v,float w){v.x*=w;v.y*=w;v.z*=w;}
inline void addscaled(F13bV& v,const F13bV& t,float w){v.x=w*t.x+v.x;v.y=w*t.y+v.y;v.z=w*t.z+v.z;}
extern "C" void f13b_skin_801a1250(const F13bV* src,unsigned influences,const float*weights,const F13bM*const*matrices,F13bV*dst,int count){
 while(count--){
  F13bV sum;transform(sum,*src,*matrices[0]);scale(sum,weights[0]);
  for(unsigned i=1;i<influences;++i){float w=weights[i];if(w!=0.0f){F13bV temp;transform(temp,*src,*matrices[i]);addscaled(sum,temp,w);}}
  weights+=influences;*dst=sum;++src;++dst;
 }
}
