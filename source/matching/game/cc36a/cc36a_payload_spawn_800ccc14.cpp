
// Original 800ccc14 returns a spawn position by value. The observed native
// copy constructor uses float temporaries; assignment copies the three words.
// Transform and actor layouts below are partial evidence-backed views only.
struct cc36a_Vector {float x,y,z;cc36a_Vector(){};cc36a_Vector(const cc36a_Vector& other){float a=other.x,b=other.y,c=other.z;x=a;y=b;z=c;}};
struct cc36a_Translation_80343740:cc36a_Vector {cc36a_Translation_80343740();};
struct cc36a_Transform {float basis[9];cc36a_Translation_80343740 translation;};
struct cc36a_Mesh {unsigned char gap[56];cc36a_Vector position;};
struct cc36a_Rope {unsigned char gap[40];void* mesh;};
extern cc36a_Vector cc36a_origin_8045e788[];
extern const char cc36a_name_80387df8[];
extern "C" void* cc36a_mesh_80343584(void*);
extern "C" int cc36a_lookup_80181e3c(void*,const char*,cc36a_Transform*);
extern "C" cc36a_Mesh* cc36a_transform_80181e18(void*);
extern "C" cc36a_Vector cc36a_payload_spawn_800ccc14(cc36a_Rope* self){
 if(self->mesh){
  cc36a_Transform transform;
  void* mesh=cc36a_mesh_80343584(self->mesh);
  cc36a_Vector position;
  if(cc36a_lookup_80181e3c(mesh,cc36a_name_80387df8,&transform)>=0)position=transform.translation;
  else position=cc36a_transform_80181e18(mesh)->position;
  return position;
 }
 return cc36a_origin_8045e788[0];
}
