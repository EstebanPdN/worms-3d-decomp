// Complete observed matrix footprints: input affine matrix48B, output matrix64B.
struct Vector3 {float x,y,z;void set(float a,float b,float c){x=a;y=b;z=c;}};
struct Vector4:Vector3 {float w;};
struct Matrix4 {Vector4 rows[4];};
struct Matrix34 {Vector3 rows[4];};
// External partial views; these objects are never locally constructed.
struct Event {void**table;char unknown4[16];Matrix34 transform;unsigned unknown68;Vector3 diagonal;};
struct Callback {unsigned unknown;unsigned short unknown4,index;};
struct List {char unknown[24];unsigned count;unsigned unknown28;Callback*entries[1];};
struct Current {char unknown[44];List*callbacks;};
struct Secondary {char unknown[20];Current*current;void**callbacks;};
struct Owner {char unknown[48];unsigned revision;unsigned unknown52;Matrix4*matrix;};
extern "C" void fn_801f68c8(Matrix4*,const Matrix34*,const Matrix4*);
extern char type_80363a14[];
extern float zero_803aa0f8[];
extern "C" int g2b_scoped_matrix_801aa9dc(char*self,Event*event){
 Owner*owner=self?(Owner*)(self-4):0;
 Matrix4 matrix;
 fn_801f68c8(&matrix,&event->transform,owner->matrix);
 void*type=((void*(*)(Event*))event->table[5])(event);
 if(type==type_80363a14){
  matrix.rows[0].set(event->diagonal.x,*zero_803aa0f8,*zero_803aa0f8);
  matrix.rows[1].set(*zero_803aa0f8,event->diagonal.y,*zero_803aa0f8);
  matrix.rows[2].set(*zero_803aa0f8,*zero_803aa0f8,event->diagonal.z);
 }
 Matrix4*saved=owner->matrix;
 owner->matrix=&matrix;++owner->revision;
 Secondary*direct=(Secondary*)((char*)owner+4);
 Secondary*secondary=owner?direct:0;
 List*list=direct->current->callbacks;
 Callback**begin=list->entries;
 Callback**end=begin+list->count;
 int result=0;
 for(;begin!=end;++begin){Callback*callback=*begin;result=((int(*)(Secondary*,Callback*))secondary->callbacks[callback->index])(secondary,callback);if(result<0)goto done;}
 result=0;
 done:owner->matrix=saved;++owner->revision;return result;
}
