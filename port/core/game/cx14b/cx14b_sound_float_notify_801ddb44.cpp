#include "w3d_ptr.h"
#line 1 "cx14b_sound_float_notify_801ddb44.cpp"

// PPC32: property floats start +20; vector count +48 and data +56. Listener slot +76 accepts index and float.
struct Interface{Ptr32<Ptr32<void>> table;};struct Vector{int count,capacity;Ptr32<Ptr32<Interface>> data;};struct Sound{char pad[20];float values[7];Vector listeners;};
extern "C" const double epsilon_803b0270[];
extern "C" int w3d_cx14b_sound_float_notify_801ddb44(Ptr32<Sound> self,int index,float value){if(__builtin_fabsf(self->values[index]-value)>epsilon_803b0270[0]){self->values[index]=value;int n=self->listeners.count;if(n>0){Ptr32<Vector> v=&self->listeners;int off=n*4;do{off-=4;Ptr32<Interface> p=*(Ptr32<Ptr32<Interface>>)w3d::G((off+(unsigned)w3d::H(v->data)));--n;((Ptr32<int (Ptr32<Interface>, int, float)>)p->table[19])(p,index,value);}while(n>0);}}return 0;}




