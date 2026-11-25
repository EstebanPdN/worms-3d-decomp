
// Vector operators preserve native temporary copies and single-precision
// subtraction, reciprocal and multiply order. Global origin is runtime BSS.
struct tterra_a34_Vector {float x,y,z;tterra_a34_Vector(){};tterra_a34_Vector(float a,float b,float c):x(a),y(b),z(c){};tterra_a34_Vector(const tterra_a34_Vector& q){float a=q.x,b=q.y,c=q.z;x=a;y=b;z=c;}
 tterra_a34_Vector operator-(const tterra_a34_Vector& q)const{return tterra_a34_Vector(x-q.x,y-q.y,z-q.z);}
 tterra_a34_Vector operator*(float k)const{tterra_a34_Vector result(x*k,y*k,z*k);return result;}
};
extern tterra_a34_Vector tterra_a34_origin_8045e788[];
extern float tterra_a34_divisor_80387d2c[],tterra_a34_one_80387d30[];
extern int tterra_a34_hit_804b1764;
extern "C" void tterra_a34_trace_800b0824(const tterra_a34_Vector*,const tterra_a34_Vector*,tterra_a34_Vector*,int,int);
extern "C" bool tterra_a34_rope_trace_800cc070(void*,const tterra_a34_Vector* target,const tterra_a34_Vector* start){
 tterra_a34_Vector result(tterra_a34_origin_8045e788[0]);
 float reciprocal=tterra_a34_one_80387d30[0]/tterra_a34_divisor_80387d2c[0];
 tterra_a34_Vector delta=(*target-*start)*reciprocal;
 tterra_a34_trace_800b0824(start,&delta,&result,100,1);
 return tterra_a34_hit_804b1764<=100;
}
