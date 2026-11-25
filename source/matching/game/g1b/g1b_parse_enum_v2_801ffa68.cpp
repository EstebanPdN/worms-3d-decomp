extern "C" unsigned fn_802ef9c0(const char*);
extern "C" int fn_802ef234(const char*,const char*);
extern "C" int fn_802ed89c(const char*);
// External null-terminated label table; no objects are constructed locally.
// Preserves the original numeric fallback bound (number of labels minus one).
extern "C" int g1b_parse_enum_801ffa68(void*unused,unsigned*out,const char*text,const char*const*table){
 unsigned count=0,prefix=fn_802ef9c0(table[0]);
 for(const char*const*p=table+1;*p;++p,++count){
  unsigned i=0;
  for(;i<prefix;++i)if(table[0][i]!=(*p)[i]){prefix=i;break;}
 }
 for(unsigned i=0;table[i];++i){
  if(fn_802ef234(table[i],text)==0||fn_802ef234(table[i]+prefix,text)==0){*out=i;return 0;}
 }
 unsigned value=fn_802ed89c(text);if(value<count){*out=value;return 0;}return 0x80004005;
}
