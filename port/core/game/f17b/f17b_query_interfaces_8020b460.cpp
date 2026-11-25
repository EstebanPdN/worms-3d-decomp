#include "w3d_ptr.h"
#line 1 "f17b_query_interfaces_8020b460.cpp"
// Inferred interface-query map entry: optional16-byte key, byte adjustment,
// callback/sentinel. External key and object views remain unowned and partial.
extern "C" int fn_802eedc0(Ptr32<const void>,Ptr32<const void>,unsigned);
extern unsigned char key_8040c950[];
struct F17bQueryEntry{Ptr32<const void> key;int adjustment;unsigned callback;};
struct F17bQueryTarget{Ptr32<Ptr32<void>> table;};
extern "C" int f17b_query_8020b460(Ptr32<char> self,Ptr32<const F17bQueryEntry> entry,Ptr32<const void> key,Ptr32<Ptr32<void>> out){
 if(!out)return 0x80004003;*out=0;
 if(fn_802eedc0(key,key_8040c950,16)!=0)goto scan;
 found:{Ptr32<F17bQueryTarget> target=(Ptr32<F17bQueryTarget>)(self+entry->adjustment);((Ptr32<void (Ptr32<F17bQueryTarget>)>)target->table[3])(target);*out=target;return 0;}
scan:
 int result;
 for(;entry->callback;++entry){bool wildcard=entry->key==0;if(wildcard||fn_802eedc0(entry->key,key,16)==0){if(entry->callback==1)goto found;result=((Ptr32<int (Ptr32<char>, Ptr32<const void>, Ptr32<Ptr32<void>>, int)>)w3d::G(entry->callback))(self,key,out,entry->adjustment);if(result==0)goto done;if(!wildcard&&result<0)goto done;}}
 result=0x80004002;done:return result;
}


