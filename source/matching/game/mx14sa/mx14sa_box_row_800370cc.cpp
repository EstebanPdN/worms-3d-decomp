// External GC32 views of the four-byte named handle and its owning array.
extern "C" void *allocate_801fe1d8(unsigned);
struct Mx14saBox_8025dffc {
 void *object;
 Mx14saBox_8025dffc(const char *,unsigned);
 static void *operator new(unsigned n) { return allocate_801fe1d8(n); }
};
struct Mx14saRow { unsigned observed_prefix[9]; Mx14saBox_8025dffc *boxes[10]; };
struct Mx14saRowVector {
 float x,y,z;
 Mx14saRowVector(float a,float b,float c) {x=a;y=b;z=c;}
 void operator+=(const Mx14saRowVector &v) {x+=v.x;y+=v.y;z+=v.z;}
};
extern const char text_80373d40[];
extern const float value_80373d50[],value_80373d54[],value_80373d58[],value_80373d5c[],value_80373d60[],value_80373d64[],value_80373d68[];
extern "C" void scale_8025e128(Mx14saBox_8025dffc *,float,float,float);
extern "C" void position_8025ee60(Mx14saBox_8025dffc *,Mx14saRowVector *);
extern "C" void mx14sa_box_row_800370cc(Mx14saRow *self) {
 Mx14saRowVector position(value_80373d50[0],value_80373d54[0],value_80373d58[0]);
 Mx14saRowVector scale(value_80373d58[0],value_80373d5c[0],value_80373d58[0]);
 Mx14saRowVector step(value_80373d60[0],value_80373d64[0],value_80373d58[0]);
 for(unsigned i=0;i<10;++i) {
  self->boxes[i]=new Mx14saBox_8025dffc(text_80373d40,(unsigned char)(i%5+28));
  scale_8025e128(self->boxes[i],value_80373d60[0],value_80373d5c[0],value_80373d68[0]);
  position_8025ee60(self->boxes[i],&position);
  position+=step;
 }
}
