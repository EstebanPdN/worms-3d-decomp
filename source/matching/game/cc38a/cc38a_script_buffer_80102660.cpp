
// Script load/execute error paths. Partial runtime view preserves the Lua
// state offset.
struct cc38a_Lua;
struct cc38a_Runtime {unsigned char unknown[68];cc38a_Lua* state;};
struct cc38a_String_803426b8 {
 cc38a_String_803426b8(const cc38a_String_803426b8 &);char* text;cc38a_String_803426b8();~cc38a_String_803426b8();};
extern "C" void cc38a_finish_8020c5c4(cc38a_String_803426b8*);
extern "C" void cc38a_release_80341588(cc38a_String_803426b8*);
inline cc38a_String_803426b8::~cc38a_String_803426b8(){cc38a_finish_8020c5c4(this);cc38a_release_80341588(this);}
extern const char cc38a_format_80398e58[];
extern "C" int cc38a_load_802ddbd8(cc38a_Lua*,const char*,unsigned,const char*);
extern "C" int cc38a_top_802cd7f4(cc38a_Lua*);
extern "C" int cc38a_panic_80101f90(cc38a_Lua*);
extern "C" int cc38a_call_802ce73c(cc38a_Lua*,int,int,int);
extern "C" void cc38a_format_8020c510(cc38a_String_803426b8*,const char*,...);
extern "C" void cc38a_report_801022ec(cc38a_Runtime*,const char*);
extern "C" unsigned cc38a_script_buffer_80102660(cc38a_Runtime* self,const char* name,const char* data,unsigned size){
 if(cc38a_load_802ddbd8(self->state,data,size,name)){
  cc38a_top_802cd7f4(self->state);cc38a_panic_80101f90(self->state);
  cc38a_String_803426b8 message;cc38a_format_8020c510(&message,cc38a_format_80398e58,name);cc38a_report_801022ec(self,message.text);
 }else{
  if(cc38a_call_802ce73c(self->state,0,0,0)==0)return 0;
  cc38a_panic_80101f90(self->state);
 }
 return 0x80004005u;
}
