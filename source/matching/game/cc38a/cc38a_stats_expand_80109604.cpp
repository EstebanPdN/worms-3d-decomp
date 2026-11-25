
// Expand four named statistics tokens in property-supplied text before output.
// The original property status gates construction and all cleanup.
struct cc38a_Stats;
struct cc38a_String_8020bb54 {
 cc38a_String_8020bb54(const cc38a_String_8020bb54 &);char* text;cc38a_String_8020bb54(const char*);~cc38a_String_8020bb54();};
extern "C" void cc38a_finish_8020c5c4(cc38a_String_8020bb54*);
extern "C" void cc38a_release_80341588(cc38a_String_8020bb54*);
inline cc38a_String_8020bb54::~cc38a_String_8020bb54(){cc38a_finish_8020c5c4(this);cc38a_release_80341588(this);}
extern const char cc38a_source_80399c1c[],cc38a_team_token_80399c5c[],cc38a_team_80399c64[],cc38a_worm_token_80399c74[],cc38a_worm_80399c78[],cc38a_index_token_80399c88[],cc38a_index_80399c8c[],cc38a_value_token_80399c98[],cc38a_value_80399c9c[];
extern "C" int cc38a_property_800fc2b0(const char**,const char**);
extern "C" void cc38a_expand_801096f0(cc38a_Stats*,cc38a_String_8020bb54*,const char*,const char*);
extern "C" void cc38a_output_8010a01c(cc38a_Stats*,const char*);
extern "C" void cc38a_stats_expand_80109604(cc38a_Stats* self){
 const char* text=0;const char* key=cc38a_source_80399c1c;
 if(cc38a_property_800fc2b0(&key,&text)>=0){
  cc38a_String_8020bb54 result(text);
  cc38a_expand_801096f0(self,&result,cc38a_team_token_80399c5c,cc38a_team_80399c64);
  cc38a_expand_801096f0(self,&result,cc38a_worm_token_80399c74,cc38a_worm_80399c78);
  cc38a_expand_801096f0(self,&result,cc38a_index_token_80399c88,cc38a_index_80399c8c);
  cc38a_expand_801096f0(self,&result,cc38a_value_token_80399c98,cc38a_value_80399c9c);
  cc38a_output_8010a01c(self,result.text);
 }
}
