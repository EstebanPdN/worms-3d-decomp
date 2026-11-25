struct sol35e2_String;
extern "C" void sol35e2_from_text_8020bb54(sol35e2_String *,const char *);
extern "C" void sol35e2_string_init_8020c5c0(sol35e2_String *);
extern "C" unsigned short *sol35e2_string_header_80341884(sol35e2_String *);
extern "C" void sol35e2_string_finish_8020c5c4(sol35e2_String *);
extern "C" void sol35e2_string_release_80341588(sol35e2_String *);
extern "C" void sol35e2_release_header_8020bb2c(unsigned short *);
extern const char sol35e2_failed_803cea20[];
struct sol35e2_String {
 char *text;
 sol35e2_String(const char *s);
 sol35e2_String(const sol35e2_String &s) {sol35e2_string_init_8020c5c0(this);text=s.text; ++*sol35e2_string_header_80341884(this);}
 ~sol35e2_String() {sol35e2_string_finish_8020c5c4(this);sol35e2_string_release_80341588(this);}
 sol35e2_String &operator=(const sol35e2_String &s) {
  ++((unsigned short *)s.text)[-3];
  unsigned short *header=(unsigned short *)text-3;
  if(--*header==0) sol35e2_release_header_8020bb2c(header);
  text=s.text;
  return *this;
 }
};
struct sol35e2_List {
 sol35e2_String *first;
 sol35e2_String *last;
 sol35e2_String *capacity;
 unsigned unknown0c;
 sol35e2_String &operator[](unsigned index) {
  return first[index];
 }
};
struct sol35e2_StringTable {
 unsigned char unknown00[28];
 sol35e2_List first, second, third, fourth, fifth;
};
extern "C" sol35e2_String sol35e2_choose_string_8027befc(sol35e2_StringTable *self,int kind,unsigned index) {
 sol35e2_String result(sol35e2_failed_803cea20);
 switch(kind) {
 case 0: result=self->first[index]; break;
 case 4: result=self->second[index]; break;
 case 3: result=self->third[index]; break;
 case 5: result=self->fourth[index]; break;
 case 6: result=self->fifth[index]; break;
 }
 return result;
}
