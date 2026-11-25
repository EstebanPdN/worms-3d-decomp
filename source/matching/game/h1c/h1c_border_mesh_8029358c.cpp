// Observed border mesh generation. Interface roles and dimensions are inferred;
// all engine objects remain borrowed partial views. Local geometry extents come
// from the original 20-element constructor loop, twelve-byte vertex stride,
// six-word box assignment and four-word sphere assignment.
namespace H1cBorder {
template<class T> inline T& field(void* object,unsigned offset){return *reinterpret_cast<T*>(static_cast<char*>(object)+offset);}
struct Vec3 {float x,y,z; Vec3(){} void set(float a,float b,float c){x=a;y=b;z=c;} };
struct Box {Vec3 minimum,maximum;};
struct Sphere {Vec3 centre;float radius;};
struct Held {
 void* object;
 Held(void* p):object(p){if(object){typedef void(*Fn)(void*);field<Fn*>(object,0)[3](object);}}
 ~Held(){if(object){typedef void(*Fn)(void*);field<Fn*>(object,0)[4](object);}}
};
inline const float& minimum(const float&a,const float&b){return b<a?b:a;}
}
using namespace H1cBorder;
extern "C" void*fn_801750d4(void*);
extern "C" void*fn_801ef048(void*,unsigned,int,int);
extern "C" void fn_801f55ec(Sphere*,const Box*);
extern const float zero_803d06f0[];
extern const unsigned char vertex_order_80401880[];
extern "C" void w3d_h1c_border_mesh_8029358c(void** source,float border,float width,float height,float inset){
 if(width<border || height<border+inset){border=minimum(width,height);inset=zero_803d06f0[0];}
 const Held& instance=Held(fn_801750d4(*source));
 const Held& mesh=Held(field<void*>(field<void*>(instance.object,44),32));
 const Held& geometry=Held(field<void*>(mesh.object,48));
 const Held& vertices=Held(field<void*>(geometry.object,80));
 void* array=static_cast<char*>(vertices.object)+20;
 void* header=field<void*>(array,0);
 unsigned count=field<unsigned>(header,24);
 Vec3* output;
 if(field<unsigned short>(header,4)==1){++field<unsigned short>(header,28);output=reinterpret_cast<Vec3*>(static_cast<char*>(header)+32);}
 else output=static_cast<Vec3*>(fn_801ef048(array,count,12,2));
 Vec3 points[20];
 for(unsigned i=0;i<4;++i){points[i].y=height;points[i+4].y=height-border;points[i+8].y=border-height;points[i+12].y=-height;}
 for(unsigned i=0;i<4;++i){points[i*4].x=-width;points[i*4+1].x=border-width;points[i*4+2].x=width-border;points[i*4+3].x=width;}
 points[16].set(width-border,height-border-inset,zero_803d06f0[0]);
 points[17].set(width,height-border-inset,zero_803d06f0[0]);
 points[18].set(width-border,border-height+inset,zero_803d06f0[0]);
 points[19].set(width,border-height+inset,zero_803d06f0[0]);
 for(unsigned i=0;i<count;++i){*output=points[vertex_order_80401880[i]];output->z=zero_803d06f0[0];++output;}
 field<unsigned char>(mesh.object,11)&=~1u;
 Box box; box.minimum.set(-width,-height,zero_803d06f0[0]);box.maximum.set(width,height,zero_803d06f0[0]);
 Sphere sphere;fn_801f55ec(&sphere,&box);
 field<Box>(geometry.object,20)=box;
 field<Sphere>(mesh.object,20)=sphere;
 field<int>(mesh.object,40)=0;
}
