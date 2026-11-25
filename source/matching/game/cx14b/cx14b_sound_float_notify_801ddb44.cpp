
// PPC32: property floats start +20; vector count +48 and data +56. Listener slot +76 accepts index and float.
struct Interface{void**table;};struct Vector{int count,capacity;Interface**data;};struct Sound{char pad[20];float values[7];Vector listeners;};
extern "C" const double epsilon_803b0270[];
extern "C" int w3d_cx14b_sound_float_notify_801ddb44(Sound*self,int index,float value){if(__builtin_fabsf(self->values[index]-value)>epsilon_803b0270[0]){self->values[index]=value;int n=self->listeners.count;if(n>0){Vector*v=&self->listeners;int off=n*4;do{off-=4;Interface*p=*(Interface**)(off+(unsigned)v->data);--n;((int(*)(Interface*,int,float))p->table[19])(p,index,value);}while(n>0);}}return 0;}


