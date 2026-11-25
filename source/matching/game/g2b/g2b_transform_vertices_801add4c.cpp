// Native vector and matrix members are external views, with no local construction.
struct Vector3 {float x,y,z;};
struct Matrix34 {Vector3 x,y,z,t;void transform(Vector3*out,const Vector3*in)const{out->x=in->x*x.x+in->y*y.x+in->z*z.x+t.x;out->y=in->x*x.y+in->y*y.y+in->z*z.y+t.y;out->z=in->x*x.z+in->y*y.z+in->z*z.z+t.z;}};
struct Interface {void**table;};
inline void retain(Interface*p){if(p)((void(*)(Interface*))p->table[3])(p);}
inline void release(Interface*p){if(p)((void(*)(Interface*))p->table[4])(p);}
struct Header {unsigned unknown;unsigned short type;char unknown6[18];unsigned count;unsigned short locks,unknown30;Vector3 vertices[1];};
struct VertexObject {void**table;char unknown[16];Header*array;};
struct Owner {void**table;char unknown4[40];Matrix34*matrix;char unknown48[48];VertexObject*next;};
extern "C" int fn_801f76b8(const Matrix34*,double);
extern "C" VertexObject*fn_8020fcb4(void*);
extern "C" Vector3*fn_801ef048(Header**,unsigned,unsigned,int);
extern char type_80363064[];
extern "C" int g2b_transform_vertices_801add4c(char*self,VertexObject*input){
 Owner*owner=self?(Owner*)(self-4):0;
 if((((unsigned(*)(Owner*))owner->table[15])(owner)&2) && !fn_801f76b8(owner->matrix,0.00001)){
  VertexObject*result=fn_8020fcb4(type_80363064);
  retain((Interface*)result);release((Interface*)owner->next);owner->next=result;
  const Matrix34*matrix=owner->matrix;
  unsigned count=input->array->count;
  const Vector3*in=input->array->vertices;
  Header*header=result->array;
  Vector3*out;
  if(header->type==1 && count==header->count){++header->locks;out=header->vertices;}
  else out=fn_801ef048(&result->array,count,12,1);
  for(unsigned i=0;i<count;++i){matrix->transform(out,in);++out;++in;}
 }
 return 0;
}
