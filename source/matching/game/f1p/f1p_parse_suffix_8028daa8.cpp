// String representation and semantic roles inferred from original instructions.
extern "C" void fn_8020c5c0(void*),fn_8020c5c4(void*),fn_80341588(void*),fn_8020bb2c(void*);
extern "C" unsigned short *fn_80341884(void*);
struct Header {unsigned short refs,length,capacity;};inline void acquire(Header*h){++h->refs;}inline void release(Header*h){if(--h->refs==0)fn_8020bb2c(h);}
struct String {char *text;String(const String&o){fn_8020c5c0(this);text=o.text;++*fn_80341884(this);}~String(){fn_8020c5c4(this);fn_80341588(this);}int length()const{return *(unsigned short*)(text-4);}String &operator=(const String&o){acquire((Header*)(o.text-6));release((Header*)(text-6));text=o.text;return *this;}};
struct Temp_803426b8 {
 Temp_803426b8(const Temp_803426b8 &);char *text;Temp_803426b8();~Temp_803426b8(){fn_8020c5c4(this);fn_80341588(this);}};
extern const char fallback_803cffac[],separator_803cffbc[];
extern "C" void fn_8020bd38(String*,const char*),fn_8020c3a0(String*,int);
extern "C" int fn_8020c0fc(Temp_803426b8*,String*,int);
extern "C" char *fn_802efd14(const char*,const char*);
extern "C" int fn_802ed8c4(const char*);
extern "C" int w3d_parse_suffix_8028daa8(void*,String*input){int result=0;char*begin=input->text;if(!input->length())fn_8020bd38(input,fallback_803cffac);else{char*split=fn_802efd14(begin,separator_803cffbc);String stem(*input);if(split){int index=split-begin;fn_8020c3a0(&stem,index);if(input->length()-1!=index){Temp_803426b8 tail;int n=input->length()-1;n-=index;fn_8020c0fc(&tail,input,n);result=fn_802ed8c4(tail.text);}}*input=stem;}return result;}
