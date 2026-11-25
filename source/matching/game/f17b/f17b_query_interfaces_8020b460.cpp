// Inferred interface-query map entry: optional16-byte key, byte adjustment,
// callback/sentinel. External key and object views remain unowned and partial.
extern "C" int fn_802eedc0(const void*,const void*,unsigned);
extern unsigned char key_8040c950[];
struct F17bQueryEntry{const void*key;int adjustment;unsigned callback;};
struct F17bQueryTarget{void**table;};
extern "C" int f17b_query_8020b460(char*self,const F17bQueryEntry*entry,const void*key,void**out){
 if(!out)return 0x80004003;*out=0;
 if(fn_802eedc0(key,key_8040c950,16)!=0)goto scan;
 found:{F17bQueryTarget*target=(F17bQueryTarget*)(self+entry->adjustment);((void(*)(F17bQueryTarget*))target->table[3])(target);*out=target;return 0;}
scan:
 int result;
 for(;entry->callback;++entry){bool wildcard=entry->key==0;if(wildcard||fn_802eedc0(entry->key,key,16)==0){if(entry->callback==1)goto found;result=((int(*)(char*,const void*,void**,int))entry->callback)(self,key,out,entry->adjustment);if(result==0)goto done;if(!wildcard&&result<0)goto done;}}
 result=0x80004002;done:return result;
}
