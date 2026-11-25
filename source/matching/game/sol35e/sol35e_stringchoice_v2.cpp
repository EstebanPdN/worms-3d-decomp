struct sol35e_String;
extern "C" void sol35e_from_text_8020bb54(sol35e_String *,const char *);
extern "C" void sol35e_string_init_8020c5c0(sol35e_String *);
extern "C" unsigned short *sol35e_string_header_80341884(sol35e_String *);
extern "C" void sol35e_string_finish_8020c5c4(sol35e_String *);
extern "C" void sol35e_string_release_80341588(sol35e_String *);
extern "C" void sol35e_release_header_8020bb2c(unsigned short *);
extern const char sol35e_failed_803cea20[];
struct sol35e_String {
 char *text;
 sol35e_String(const char *s);
 sol35e_String(const sol35e_String &s) {sol35e_string_init_8020c5c0(this);text=s.text; ++*sol35e_string_header_80341884(this);}
 ~sol35e_String() {sol35e_string_finish_8020c5c4(this);sol35e_string_release_80341588(this);}
 sol35e_String &operator=(const sol35e_String &s) {
  ++((unsigned short *)s.text)[-3];
  unsigned short *header=(unsigned short *)text-3;
  if(--*header==0) sol35e_release_header_8020bb2c(header);
  text=s.text;
  return *this;
 }
};
struct sol35e_StringTable {unsigned char unknown00[28];sol35e_String *first;unsigned char unknown20[12];sol35e_String *second;unsigned char unknown30[12];sol35e_String *third;unsigned char unknown40[12];sol35e_String *fourth;unsigned char unknown50[12];sol35e_String *fifth;};
inline void *operator new(unsigned,void *place) {return place;}
extern "C" sol35e_String *sol35e_choose_string_8027befc(sol35e_String *out,sol35e_StringTable *self,int kind,unsigned index) {
 sol35e_String result(sol35e_failed_803cea20);
 sol35e_String *list;
 switch(kind) {
 case 0:list=self->first;break;
 case 4:list=self->second;break;
 case 3:list=self->third;break;
 case 5:list=self->fourth;break;
 case 6:list=self->fifth;break;
 default:goto done;
 }
 result=*reinterpret_cast<sol35e_String *>((index<<2)+reinterpret_cast<char *>(list));
 done:new(out) sol35e_String(result);return out;
}
