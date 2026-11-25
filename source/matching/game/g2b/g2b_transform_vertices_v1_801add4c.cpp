// Native vector and matrix members are external views, with no local construction.
struct Vector3 {float x,y,z;const float*data()const{return &x;}};
struct Matrix34 {Vector3 x,y,z,t;void transform(Vector3*out,const Vector3*in,unsigned count)const{const float*a=x.data(),*b=y.data(),*c=z.data(),*d=t.data();for(unsigned i=0;i<count;++i){out->x=in->x*a[0]+in->y*b[0]+in->z*c[0]+d[0];out->y=in->x*a[1]+in->y*b[1]+in->z*c[1]+d[1];out->z=in->x*a[2]+in->y*b[2]+in->z*c[2]+d[2];++out;++in;}}};
struct Interface {void**table;};
inline void retain(Interface*p){if(p)((void(*)(Interface*))p->table[3])(p);}
inline void release(Interface*p){if(p)((void(*)(Interface*))p->table[4])(p);}
struct Header;
extern "C" Vector3*fn_801ef048(Header**,unsigned,unsigned,int);
inline unsigned count(const Header*p){return *(const unsigned*)((const char*)p+24);}
inline Vector3*vertices(Header*p){return (Vector3*)((char*)p+32);}
struct Array {Header*header;Vector3*lock(unsigned n){Header*p=header;if(*(unsigned short*)((char*)p+4)==1&&n==count(p)){++*(unsigned short*)((char*)p+28);return vertices(p);}return fn_801ef048(&header,n,12,1);}};
struct VertexObject {void**table;char unknown[16];Array array;};
struct Owner {void**table;char unknown4[40];Matrix34*matrix;char unknown48[48];VertexObject*next;};
extern "C" int fn_801f76b8(const Matrix34*,double);
extern "C" VertexObject*fn_8020fcb4(void*);
extern "C" Vector3*fn_801ef048(Header**,unsigned,unsigned,int);
extern char type_80363064[];
extern "C" int g2b_transform_vertices_801add4c(char*self,VertexObject*input){
 Owner*owner=self?(Owner*)(self-4):0;
 if((((unsigned(*)(Owner*))owner->table[15])(owner)&2) && !fn_801f76b8(owner->matrix,0.00001f)){
  VertexObject*result=fn_8020fcb4(type_80363064);
  retain((Interface*)result);release((Interface*)owner->next);owner->next=result;
  const Matrix34*matrix=owner->matrix;
  unsigned n=count(input->array.header);
  const Vector3*in=vertices(input->array.header);
  Vector3*out=result->array.lock(n);
  matrix->transform(out,in,n);
 }
 return 0;
}
