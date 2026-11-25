
// Nested collision query over two dynamic arrays. Array end/begin differences
// are signed pointer differences converted to the original unsigned count.
struct cc38a_Bounds;
struct cc38a_Array {cc38a_Bounds** begin;cc38a_Bounds** end;cc38a_Bounds** capacity;unsigned size()const{return end-begin;} cc38a_Bounds* at(unsigned i)const{return *(cc38a_Bounds**)((char*)begin+(i<<2));} };
struct cc38a_Group {unsigned char unknown[16];cc38a_Array bounds;};
extern "C" int cc38a_intersects_800c59cc(cc38a_Bounds*,cc38a_Bounds*);
extern "C" int cc38a_group_intersects_800f65cc(void* context,cc38a_Group* a,cc38a_Group* b){
 for(unsigned i=0;i<a->bounds.size();++i)
  for(unsigned j=0;j<b->bounds.size();++j)
   if(cc38a_intersects_800c59cc(a->bounds.at(i),b->bounds.at(j)))return 1;
 return 0;
}
