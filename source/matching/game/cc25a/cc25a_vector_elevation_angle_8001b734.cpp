// Original 0x8001b734: angle from the horizontal plane, inferred from up-vector dot and acos.
struct cc25a_Vec1b734 {float x,y,z;
 cc25a_Vec1b734(const cc25a_Vec1b734&v){x=v.x;y=v.y;z=v.z;}
 cc25a_Vec1b734(float a,float b,float c){x=a;y=b;z=c;}
 float dot(const cc25a_Vec1b734&v)const{float vz=v.z;return z*vz+(x*v.x+y*v.y);}
 void scale(float s){x*=s;y*=s;z*=s;}
};
extern float cc25a_zero_8036b048[],cc25a_one_8036b04c[],cc25a_halfpi_8036b050[];
extern "C" float cc25a_sqrt_802e82c0(float);
extern "C" float cc25a_acos_802e79e0(float);
extern "C" float cc25a_vector_elevation_angle_8001b734(const cc25a_Vec1b734 *v){
 if(v->x==0.0f && v->y==0.0f && v->z==0.0f)return 0.0f;
 cc25a_Vec1b734 unit(*v);
 unit.scale(1.0f/cc25a_sqrt_802e82c0(unit.dot(unit)));
 cc25a_Vec1b734 up(0.0f,1.0f,0.0f);
 return 1.5707963705062866f-cc25a_acos_802e79e0(up.dot(unit));
}
