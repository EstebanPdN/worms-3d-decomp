// Inferred current team-name availability check; partial GC32 layouts.
#define FIELD(p,T,o) (*reinterpret_cast<T *>(static_cast<char *>(p)+(o)))
struct sol35e6a_String_803426b8;
extern "C" void sol35e6a_finish_8020c5c4(sol35e6a_String_803426b8 *);
extern "C" void sol35e6a_release_80341588(sol35e6a_String_803426b8 *);
extern "C" void sol35e6a_assign_8020bd38(sol35e6a_String_803426b8 *,const char *);
struct sol35e6a_String_803426b8 {
 char *text;
 sol35e6a_String_803426b8();
 ~sol35e6a_String_803426b8() { sol35e6a_finish_8020c5c4(this); sol35e6a_release_80341588(this); }
};
struct Name { const char *text; Name(const char *p):text(p) {} };
struct ObjectRef {
 void *pointer;
 ObjectRef():pointer(0) {}
 ~ObjectRef() {
  if (pointer) {
   typedef void (*Release)(void *);
   FIELD(pointer,Release *,0)[4](pointer);
  }
 }
};
extern const char sol35e6a_property_803d09ec[];
extern const char sol35e6a_barracks_803d097c[];
extern "C" int sol35e6a_read_text_800fc2b0(const Name *,const char **);
extern "C" int sol35e6a_lookup_800fc1b0(const Name *,ObjectRef *);
extern "C" void sol35e6a_select_80341584(void *);
extern "C" void *sol35e6a_get_selected_801797b4();
extern "C" int sol35e6a_compare_802ef234(const char *,const char *);
extern "C" bool sol35e6a_team_name_check_8029d89c() {
 sol35e6a_String_803426b8 name;
 const char *input;
 sol35e6a_read_text_800fc2b0(&Name(sol35e6a_property_803d09ec),&input);
 sol35e6a_assign_8020bd38(&name,input);
 if (reinterpret_cast<unsigned short *>(name.text)[-2]==0 || *input==' ') return true;
 ObjectRef barracks;
 if (sol35e6a_lookup_800fc1b0(&Name(sol35e6a_barracks_803d097c),&barracks)>=0) {
  sol35e6a_select_80341584(barracks.pointer);
  void *selected=sol35e6a_get_selected_801797b4();
  void *array=FIELD(selected,void *,24);
  unsigned count=FIELD(array,unsigned,24);
  char *entries=static_cast<char *>(array)+32;
  for (unsigned i=0;i<count;++i) {
   void *entry=*reinterpret_cast<void **>((i<<2)+entries);
   if (sol35e6a_compare_802ef234(FIELD(entry,const char *,60),name.text)==0) {
    return FIELD(*reinterpret_cast<void **>((i<<2)+entries),int,44)!=0;
   }
  }
 }
 return false;
}
typedef char StringSize[sizeof(sol35e6a_String_803426b8)==4?1:-1];
typedef char RefSize[sizeof(ObjectRef)==4?1:-1];
