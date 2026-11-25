// Native vector copy preserves the original local float stores and subsequent word copy.
struct Cc23aVector8000b6bc{float x,y,z;Cc23aVector8000b6bc(const Cc23aVector8000b6bc &p){float a=p.x,b=p.y,c=p.z;x=a;y=b;z=c;}
 float distance2(const Cc23aVector8000b6bc &p){float a=x-p.x,b=y-p.y,c=z-p.z;return c*c+(a*a+b*b);}};
struct Cc23aPlan8000b6bc{unsigned int unknown00[3];void **dispatch0c;unsigned char unknown10[8];Cc23aVector8000b6bc origin18;unsigned char unknown24[28];unsigned char flag40;unsigned char unknown41[3];unsigned int flags44;
 bool already(){return flag40!=0;}};
extern "C" {extern Cc23aVector8000b6bc lbl_8041e85c[],lbl_8041d3a0[];extern float lbl_80369c64[];void fn_8000753c(Cc23aPlan8000b6bc *);}
extern "C" int cc23a_planner_requeue_offset_8000b6bc(Cc23aPlan8000b6bc *self,int result){
 if(result==0 && !self->already() && ((int (*)(Cc23aPlan8000b6bc *))self->dispatch0c[11])(self)){
 Cc23aVector8000b6bc point(lbl_8041e85c[0]);
 // Original rejects only less-than; unordered distances continue.
 if(point.distance2(lbl_8041d3a0[0])<lbl_80369c64[0])goto done;
 Cc23aPlan8000b6bc *copy=((Cc23aPlan8000b6bc *(*)(Cc23aPlan8000b6bc *))self->dispatch0c[9])(self);
 if(!(self->flags44&16))copy->origin18=point;
 copy->flag40=1;fn_8000753c(copy);
 }
 done:
 return result;
}
