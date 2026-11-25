// Source-line access with bounded output and original missing-source diagnostic bytes.
struct cc39a_Runtime;struct cc39a_Source;struct cc39a_Line;

extern const char cc39a_unavailable_80398f30[];
extern "C" {
int cc39a_find_80102a34(cc39a_Runtime*,const char*,cc39a_Source**);
int cc39a_line_800ffca4(cc39a_Source*,unsigned,cc39a_Line**);
unsigned cc39a_length_800ffb70(cc39a_Line*);const char* cc39a_data_800ffb68(cc39a_Line*);
void* cc39a_copy_802eee50(...);
}
extern "C" int cc39a_script_source_line_80102890(cc39a_Runtime* self,const char* name,unsigned index,char* out){
 cc39a_Source* source=0;
 cc39a_find_80102a34(self,name,&source);
 if(!source){__builtin_memcpy(out,cc39a_unavailable_80398f30,21);return 0;}
 cc39a_Line* ref;
 int result=cc39a_line_800ffca4(source,index,&ref);
 if(result>=0){
  unsigned size=cc39a_length_800ffb70(ref);if(size>255)size=255;
  cc39a_copy_802eee50(out,cc39a_data_800ffb68(ref),size);out[size]=0;return 0;
 }
 return result;
}
