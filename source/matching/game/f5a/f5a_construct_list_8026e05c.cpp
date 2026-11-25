inline void *operator new(unsigned int,void*p){return p;}
extern "C" void *fn_8015fef0(void*);
struct Member_802afb20{char storage[180];Member_802afb20();};
struct Pair{int a[2];Pair(){int *p=a;int count=1;do{*p++=0;}while(count--);}};
struct Owner{char base[28];Member_802afb20 member;void*secondary;int held;Pair pair;int a[3],b[3];int zero248,unknown252,zero256,zero260,zero264,zero268,zero272,zero276,zero280,zero284,zero288,zero292,zero296,zero300,zero304;float value308,value312;};
extern char vt_8041bd60[],vt_8041bdb0[];extern const float zero_803cbde4[];
extern "C" Owner *w3d_f5a_construct_list_8026e05c(Owner*self){
 fn_8015fef0(self);new(&self->member)Member_802afb20;
 self->secondary=vt_8041bd60;*(void**)self=vt_8041bdb0;self->held=0;
 new(&self->pair)Pair;
 self->zero268=0;self->zero248=0;self->zero272=0;self->zero276=0;self->zero280=0;self->zero288=0;self->zero292=0;self->zero296=0;self->zero300=0;self->zero304=0;self->zero256=0;self->zero260=0;self->value308=zero_803cbde4[0];self->zero264=0;self->zero284=0;self->value312=zero_803cbde4[0];
 for(int i=0;i<3;i++){self->a[i]=0;self->b[i]=0;}return self;
}
