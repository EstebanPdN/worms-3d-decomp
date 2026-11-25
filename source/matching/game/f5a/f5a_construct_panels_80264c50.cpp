// Partial observed layouts and semantic roles are inferred.
// The counted empty loop reproduces the observed eight-iteration loop.
inline void*operator new[](unsigned int,void*p){return p;}
inline void*operator new(unsigned int,void*p){return p;}
#define F(p,T,o) (*(T*)((char*)(p)+(o)))
extern "C" void*fn_8015fef0(void*);
struct Member_802afb20 {char storage[180];Member_802afb20();};
struct Row {int a[7];Row(){int*p=a;for(int i=7;i;i--)*p++=0;}};
struct Triple {int a[3];Triple(){int*p=a;for(int i=3;i;i--)*p++=0;}};
struct Pair{int a[2];Pair(){int*p=a;int i=1;do{*p++=0;}while(i--);}};
struct Point{int a,b;char unused0[12];float x,y;char unused1[24];float width,height;Point();};
extern const float c_803cb558[],c_803cb55c[],c_803cb560[],c_803cb564[],c_803cb568[];
inline Point::Point(){a=0;b=0;x=5.0f;y=5.0f;width=1.0f;height=0.0f;}
struct Color {unsigned char r,g,b,a;Color(int x,int y,int z,int w){r=x;g=y;b=z;a=w;}};
struct Owner {char base[28];Member_802afb20 member;void*secondary;void*held;Row rows[6];int arrayA[6],arrayB[6];int zero432,zero436;Triple triple;int zero452;Pair pair0,pair1,pair2,pair3;int zero488,unknown492,zero496,zero500;Color color0,color0copy,color1,color1copy,color2,color2copy,color3,color4;char unknown536[28];int zero564;float value568;int zero572;Point points[2];int zero696,zero700;float value704,value708;int zero712;float value716,value720;int zero724,zero728,zero732;};
extern char vt_8041bc00[],vt_8041bc50[];
extern "C" Owner*w3d_f5a_construct_panels_80264c50(Owner*self){
 fn_8015fef0(self);new(&self->member)Member_802afb20;self->secondary=vt_8041bc00;*(void**)self=vt_8041bc50;self->held=0;
 new(self->rows)Row[6];new(&self->triple)Triple;self->zero452=0;
 new(&self->pair0)Pair;new(&self->pair1)Pair;new(&self->pair2)Pair;new(&self->pair3)Pair;
 self->zero488=0;for(int i=8;i;i--){}
 self->zero564=0;new(self->points)Point[2];
 self->zero696=0;self->zero700=0;self->zero728=0;self->zero732=0;
 if(self->held)(*(void(***)(void*))(self->held))[4](self->held);self->held=0;
 for(int i=0;i<6;i++){self->arrayA[i]=0;self->arrayB[i]=0;}
 self->zero432=0;self->zero436=0;
 new(&self->color0)Color(0,160,105,255);*(int*)&self->color0copy=*(int*)&self->color0;
 new(&self->color1)Color(182,234,0,255);*(int*)&self->color1copy=*(int*)&self->color1;
 new(&self->color2)Color(255,200,0,255);*(int*)&self->color2copy=*(int*)&self->color2;
 new(&self->color3)Color(243,62,0,255);new(&self->color4)Color(13,38,88,150);
 self->value568=-1.0f;self->zero496=0;self->zero500=0;self->zero572=0;self->zero712=0;
 self->value704=1.5707963705062866f;self->value708=0.0f;self->value716=0.0f;self->value720=1.0f;self->zero724=0;return self;
}
