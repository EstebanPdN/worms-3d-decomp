
// Search the runtime's script collection by its returned shared-string name.
// Object names are inferred.
struct cc38a_Script;
struct cc38a_Array {cc38a_Script** begin;cc38a_Script** end;cc38a_Script** capacity;unsigned size()const{return end-begin;}cc38a_Script* at(unsigned i)const{return *(cc38a_Script**)((char*)begin+(i<<2));}};
struct cc38a_Runtime {unsigned char unknown[28];cc38a_Array scripts;};
struct cc38a_String {const char* text;cc38a_String(const cc38a_String&);~cc38a_String();};
extern "C" void cc38a_finish_8020c5c4(cc38a_String*);
extern "C" void cc38a_release_80341588(cc38a_String*);
inline cc38a_String::~cc38a_String(){cc38a_finish_8020c5c4(this);cc38a_release_80341588(this);}
extern "C" cc38a_String cc38a_name_800ffcdc(cc38a_Script*);
extern "C" int cc38a_compare_802ef234(const char*,const char*);
extern "C" int cc38a_script_find_80102a34(cc38a_Runtime* self,const char* name,cc38a_Script** output){
 *output=0;
 for(unsigned i=0;i<self->scripts.size();++i){
  *output=self->scripts.at(i);
  int comparison=cc38a_compare_802ef234(cc38a_name_800ffcdc(*output).text,name);
  if(comparison==0)return 1;
 }
 *output=0;return 0;
}
