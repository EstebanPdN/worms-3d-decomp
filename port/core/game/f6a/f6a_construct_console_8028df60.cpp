#include "w3d_ptr.h"
#line 1 "f6a_construct_console_8028df60.cpp"
// Partial observed console state and container layouts; semantic roles inferred.
inline void*operator new(__SIZE_TYPE__,void*p){return p;}
extern "C" Ptr32<void> fn_801628b0(Ptr32<void>);
struct Names_800c4598{char storage[20];Names_800c4598();};
struct Text_803426b8{Ptr32<char> text;Text_803426b8();};
struct Four{int a,b,c,d;Four(){a=0;b=0;c=0;d=0;}};
struct Tail{int unknown,a;Tail(){a=0;}};
extern "C" void fn_8035ec68(Ptr32<void>,unsigned);
struct Deque{Four map,iterator;Tail begin,end;Deque(){fn_8035ec68(this,0);}};
struct Owner{char base[28];int a,b,c,d,e,f,g,h;int zero60,zero64,unknown68;Names_800c4598 names,history;Text_803426b8 name,previous;Deque deque;};
extern char vt_8041c1b0[];extern Ptr32<Owner> instance_804abbf4;
inline void initialize(Ptr32<Owner> self,int zero){self->a=zero;self->b=zero;self->c=zero;self->d=zero;self->e=zero;self->f=zero;self->g=zero;self->h=zero;*(Ptr32<Ptr32<void>>)self=vt_8041c1b0;new(&self->names)Names_800c4598;new(&self->history)Names_800c4598;new(&self->name)Text_803426b8;new(&self->previous)Text_803426b8;new(&self->deque)Deque;instance_804abbf4=self;self->zero60=zero;self->zero64=zero;}
extern "C" Ptr32<Owner> w3d_f6a_construct_console_8028df60(Ptr32<Owner> self){fn_801628b0(self);initialize(self,0);volatile char original_frame_unknown[16];return self;}


