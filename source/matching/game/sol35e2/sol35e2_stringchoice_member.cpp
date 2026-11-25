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
struct sol35e2_StringTable {unsigned char unknown00[28];sol35e2_String *first;unsigned char unknown20[12];sol35e2_String *second;unsigned char unknown30[12];sol35e2_String *third;unsigned char unknown40[12];sol35e2_String *fourth;unsigned char unknown50[12];sol35e2_String *fifth; sol35e2_String choose(int, unsigned);};
sol35e2_String sol35e2_StringTable::choose(int kind,unsigned index) {
 sol35e2_StringTable *self = this;
 sol35e2_String result(sol35e2_failed_803cea20);
 sol35e2_String *list;
 switch(kind) {
 case 0:list=self->first;break;
 case 4:list=self->second;break;
 case 3:list=self->third;break;
 case 5:list=self->fourth;break;
 case 6:list=self->fifth;break;
 default:goto done;
 }
 result=*reinterpret_cast<sol35e2_String *>((index<<2)+reinterpret_cast<char *>(list));
 done:return result;
}
