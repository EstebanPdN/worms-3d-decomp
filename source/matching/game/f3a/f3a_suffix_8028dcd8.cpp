// Original text wrapper layout and uppercase suffix operations; symbol roles inferred.
extern "C" void fn_8020c5c0(void*),fn_8020c5c4(void*),fn_80341588(void*),fn_8020c2e8(void*);
extern "C" unsigned short*fn_80341884(void*);
extern "C" unsigned fn_802ef9c0(const char*);
extern "C" int fn_802ef234(const char*,const char*);
extern char ext_803cffc0[];
struct Text {char *data;Text(const Text&v){fn_8020c5c0(this);data=v.data;++*fn_80341884(this);}~Text(){fn_8020c5c4(this);fn_80341588(this);}};
extern "C" int w3d_f3a_suffix_8028dcd8(void*,Text input){Text text(input);fn_8020c2e8(&text);char *p=text.data;unsigned n=fn_802ef9c0(p);if(n>4 && fn_802ef234(p+n-4,ext_803cffc0)==0)return 1;return 0;}
