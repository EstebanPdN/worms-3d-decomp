
// Statistics text accumulation. Assignment is followed by a short-lived copy
// of the resulting shared string; this preserves its observed retain/release.
// An assignment result is a possible original source explanation, not proven.
struct cc38a_String_803426b8;
extern "C" void cc38a_base_8020c5c0(void*);
extern "C" unsigned short* cc38a_header_80341884(void*);
extern "C" void cc38a_assign_8020bd38(void*,const char*);
extern "C" void cc38a_finish_8020c5c4(void*);
extern "C" void cc38a_release_80341588(void*);
struct cc38a_String_803426b8 {
 char* text;cc38a_String_803426b8();
 cc38a_String_803426b8(const cc38a_String_803426b8& other){cc38a_base_8020c5c0(this);text=other.text;++*cc38a_header_80341884(this);}
 ~cc38a_String_803426b8(){cc38a_finish_8020c5c4(this);cc38a_release_80341588(this);}
 cc38a_String_803426b8 operator=(const char* value){cc38a_assign_8020bd38(this,value);return *this;}
};
extern const char cc38a_key_80399cfc[],cc38a_separator_80399d1c[];
extern "C" int cc38a_read_800fc2b0(const char**,const char**);
extern "C" int cc38a_write_800fc550(const char**,const char*);
extern "C" void * cc38a_append_8020bf2c(void*,const char*);
extern "C" void cc38a_stats_append_8010a01c(void* context,const char* text){
 cc38a_String_803426b8 result;
 const char* key=cc38a_key_80399cfc;const char* old;cc38a_read_800fc2b0(&key,&old);
 cc38a_assign_8020bd38(&result,old);
 (void)cc38a_String_803426b8(result);
 cc38a_append_8020bf2c(&result,text);cc38a_append_8020bf2c(&result,cc38a_separator_80399d1c);
 const char* outKey=cc38a_key_80399cfc;cc38a_write_800fc550(&outKey,result.text);
}
