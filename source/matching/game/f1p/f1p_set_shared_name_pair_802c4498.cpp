// Observed by-value shared-string ownership and partial resource panel state.
extern "C" void fn_8020c5c4(void*),fn_80341588(void*),fn_8020bb2c(void*);extern "C" int fn_802ef234(const char*,const char*);
struct F1pPairOwnedText{
 F1pPairOwnedText(const F1pPairOwnedText &); F1pPairOwnedText() {}char*text;~F1pPairOwnedText(){fn_8020c5c4(this);fn_80341588(this);}};struct F1pPairNameHeader{unsigned short refs,length,capacity;void release(){if(!--refs)fn_8020bb2c(this);}};
struct F1pPairNameTextView{char*text;void assign(const F1pPairOwnedText&s){++((F1pPairNameHeader*)(s.text-6))->refs;((F1pPairNameHeader*)(text-6))->release();text=s.text;}};
struct F1pPairNameOwner{char unknown[36];int active;char unknown40[208];F1pPairNameTextView first,second;};extern "C" void fn_802c459c(F1pPairNameOwner*);
extern "C" void w3d_set_shared_name_pair_802c4498(F1pPairNameOwner*s,F1pPairOwnedText second,F1pPairOwnedText first){if(fn_802ef234(s->first.text,first.text)!=0||fn_802ef234(s->second.text,second.text)!=0){s->first.assign(first);s->second.assign(second);if(s->active)fn_802c459c(s);}}
