#include "w3d_ptr.h"
#line 1 "cc38a_script_file_80102530.cpp"

// Script file loading with source/bytecode fallback. Native stream storage
// records witnessed constructor fields, while metadata tail is uninterpreted.
struct cc38a_Runtime;
struct cc38a_Stream_80207fec {unsigned words[6];cc38a_Stream_80207fec();~cc38a_Stream_80207fec();};
extern "C" void cc38a_stream_finish_8020803c(Ptr32<cc38a_Stream_80207fec>,int);
inline cc38a_Stream_80207fec::~cc38a_Stream_80207fec(){cc38a_stream_finish_8020803c(this,2);}
struct cc38a_String_803426b8 {
 cc38a_String_803426b8(const cc38a_String_803426b8 &);Ptr32<const char> text;cc38a_String_803426b8();~cc38a_String_803426b8();};
extern "C" void cc38a_finish_8020c5c4(Ptr32<cc38a_String_803426b8>);
extern "C" void cc38a_release_80341588(Ptr32<cc38a_String_803426b8>);
inline cc38a_String_803426b8::~cc38a_String_803426b8(){cc38a_finish_8020c5c4(this);cc38a_release_80341588(this);}
extern const char cc38a_lua_80398e48[],cc38a_lub_80398e50[];
extern "C" void cc38a_assign_8020bd38(Ptr32<cc38a_String_803426b8>,Ptr32<const char>);
extern "C" Ptr32<void> cc38a_append_8020bf2c(Ptr32<cc38a_String_803426b8>,Ptr32<const char>);
extern "C" int cc38a_open_802080a0(Ptr32<cc38a_Stream_80207fec>,Ptr32<const char>,int);
struct cc38a_Metadata {unsigned size;unsigned unknown[3];};
extern "C" void cc38a_stat_802081c8(Ptr32<cc38a_Stream_80207fec>,Ptr32<cc38a_Metadata>);
extern "C" Ptr32<char> cc38a_allocate_801fe0b8(unsigned);
extern "C" int cc38a_read_80208298(Ptr32<cc38a_Stream_80207fec>,Ptr32<char>,unsigned,int);
extern "C" int cc38a_close_8020810c(Ptr32<cc38a_Stream_80207fec>);
extern "C" int cc38a_execute_80102660(Ptr32<cc38a_Runtime>,Ptr32<const char>,Ptr32<const char>,unsigned);
extern "C" void cc38a_free_801fe160(Ptr32<void>);
extern "C" int cc38a_script_file_80102530(Ptr32<cc38a_Runtime> self,Ptr32<const char> name){
 cc38a_Stream_80207fec stream;cc38a_String_803426b8 path;
 cc38a_assign_8020bd38(&path,name);cc38a_append_8020bf2c(&path,cc38a_lua_80398e48);
 int result=cc38a_open_802080a0(&stream,path.text,1);
 if(result<0){cc38a_assign_8020bd38(&path,name);cc38a_append_8020bf2c(&path,cc38a_lub_80398e50);
 result=cc38a_open_802080a0(&stream,path.text,1);if(result<0)return result;}
 cc38a_Metadata meta;cc38a_stat_802081c8(&stream,&meta);
 unsigned size=meta.size;Ptr32<char> data=cc38a_allocate_801fe0b8(size);
 cc38a_read_80208298(&stream,data,size,0);cc38a_close_8020810c(&stream);
 result=cc38a_execute_80102660(self,name,data,size);cc38a_free_801fe160(data);return result;
}


