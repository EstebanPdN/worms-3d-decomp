// Inferred vector layout and algorithm; no original symbols survive.
struct F7Vec{float x,y,z;F7Vec(){}F7Vec(const F7Vec&o){float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;} F7Vec operator-(const F7Vec&o)const{F7Vec r;r.x=x-o.x;r.y=y-o.y;r.z=z-o.z;return r;}void operator*=(float a){x*=a;y*=a;z*=a;}void operator+=(const F7Vec&o){x+=o.x;y+=o.y;z+=o.z;}bool near(const F7Vec&o,float e)const{int n=3;int off=0;do{if((float)__builtin_fabs(((const float*)this)[off]-((const float*)&o)[off])>e)return false;off++;}while(--n);return true;}};
struct F7Interp{char p[40];float state;char p2[16];F7Vec value;char p3[40];void*target;char p4[20];void*rate;};
extern const float epsilon_80379db0[],zero_80379db4[];
extern "C" const F7Vec* get_80178ec4(void*);extern "C" float get_80178df0(void*);extern "C" void set_800649e8(F7Interp*,int),update_80064198(F7Interp*);
extern "C" int f7b_interpolate_800647cc(F7Interp*s){int done=0;F7Vec target=*get_80178ec4(s->target);if(target.near(s->value,0.3f)){done=1;s->value=target;if(s->state==zero_80379db4[0])set_800649e8(s,0);}else{F7Vec delta=target-s->value;delta*=get_80178df0(s->rate);s->value+=delta;}update_80064198(s);return done;}
