struct Vec3{float x,y,z;inline void set(float a,float b,float c){x=a;y=b;z=c;}};
struct Service;struct Vtable{void *unused[19];void (*position)(Service*,Vec3*,int);void *gap[1];void (*scale)(Service*,Vec3*,int);};struct Service{Vtable*vtable;};
struct Owner{unsigned char opaque[28];Service*child;int state,mode,unused40,count;Service*a,*b,*c;Vec3 position;float x,y;int extra;};

extern "C" float step_803d8d08[],one_803d8d0c[];
extern "C" int w3d_k8c_child_scale_countdown_802c5f4c(Owner*self){if(self->child){Vec3 v;if(self->count!=-1){float f=one_803d8d0c[0]-(float)self->count*step_803d8d08[0];v.set(f,f,one_803d8d0c[0]);self->child->vtable->scale(self->child,&v,0);self->count--;}else{v.set(one_803d8d0c[0],one_803d8d0c[0],one_803d8d0c[0]);self->child->vtable->scale(self->child,&v,0);}}return 0;}

