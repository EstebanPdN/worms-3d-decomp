
// Script file loading with source/bytecode fallback. Native stream storage
// records witnessed constructor fields, while metadata tail is uninterpreted.
struct cc38a_Runtime;
struct cc38a_Stream_80207fec {unsigned words[6];cc38a_Stream_80207fec();~cc38a_Stream_80207fec();};
extern "C" void cc38a_stream_finish_8020803c(cc38a_Stream_80207fec*,int);
inline cc38a_Stream_80207fec::~cc38a_Stream_80207fec(){cc38a_stream_finish_8020803c(this,2);}
struct cc38a_String_803426b8 {
 cc38a_String_803426b8(const cc38a_String_803426b8 &);const char* text;cc38a_String_803426b8();~cc38a_String_803426b8();};
extern "C" void cc38a_finish_8020c5c4(cc38a_String_803426b8*);
extern "C" void cc38a_release_80341588(cc38a_String_803426b8*);
inline cc38a_String_803426b8::~cc38a_String_803426b8(){cc38a_finish_8020c5c4(this);cc38a_release_80341588(this);}
extern const char cc38a_lua_80398e48[],cc38a_lub_80398e50[];
extern "C" void cc38a_assign_8020bd38(cc38a_String_803426b8*,const char*);
extern "C" void * cc38a_append_8020bf2c(cc38a_String_803426b8*,const char*);
extern "C" int cc38a_open_802080a0(cc38a_Stream_80207fec*,const char*,int);
struct cc38a_Metadata {unsigned size;unsigned unknown[3];};
extern "C" void cc38a_stat_802081c8(cc38a_Stream_80207fec*,cc38a_Metadata*);
extern "C" char* cc38a_allocate_801fe0b8(unsigned);
extern "C" int cc38a_read_80208298(cc38a_Stream_80207fec*,char*,unsigned,int);
extern "C" int cc38a_close_8020810c(cc38a_Stream_80207fec*);
extern "C" int cc38a_execute_80102660(cc38a_Runtime*,const char*,const char*,unsigned);
extern "C" void cc38a_free_801fe160(void*);
extern "C" int cc38a_script_file_80102530(cc38a_Runtime* self,const char* name){
 cc38a_Stream_80207fec stream;cc38a_String_803426b8 path;
 cc38a_assign_8020bd38(&path,name);cc38a_append_8020bf2c(&path,cc38a_lua_80398e48);
 int result=cc38a_open_802080a0(&stream,path.text,1);
 if(result<0){cc38a_assign_8020bd38(&path,name);cc38a_append_8020bf2c(&path,cc38a_lub_80398e50);
 result=cc38a_open_802080a0(&stream,path.text,1);if(result<0)return result;}
 cc38a_Metadata meta;cc38a_stat_802081c8(&stream,&meta);
 unsigned size=meta.size;char* data=cc38a_allocate_801fe0b8(size);
 cc38a_read_80208298(&stream,data,size,0);cc38a_close_8020810c(&stream);
 result=cc38a_execute_80102660(self,name,data,size);cc38a_free_801fe160(data);return result;
}
