// Partial script-editor and shared-string views inferred from observed offsets.
#define F(p,T,o) (*(T*)((char*)(p)+(o)))
extern "C" void fn_8020bb2c(void*),fn_80275cdc(void*),fn_80271518(void*,int),fn_80271c94(void*),fn_80275f18(void*),fn_8027a98c(void*);
extern "C" char*fn_802ef198(const char*,int);
extern const char* keys_804abb9c;
extern const char* keys_804abba0;
struct F14cHeader {unsigned short refs,length,capacity;void release(){if(!--refs)fn_8020bb2c(this);}};
struct F14cText {char*p;void assign(const F14cText&s){++((F14cHeader*)(s.p-6))->refs;((F14cHeader*)(p-6))->release();p=s.p;}};
inline const unsigned& f14c_min(const unsigned&a,const unsigned&b){return b<a?b:a;}
extern "C" void w3d_f14c_editor_key_80277494(void*self,int key){
 void*container=F(F(self,void*,88),void*,20);unsigned count=F(container,unsigned,24);void**items=(void**)((char*)container+32);
 if(key==32){fn_80275cdc(self);return;}
 if(key==27){fn_80271518(self,0);return;}
 if(key==110){++F(self,unsigned,84);F(self,unsigned,84)=f14c_min(F(self,unsigned,84),(count-1)/20);fn_80271c94(self);return;}
 if(key==112){--F(self,unsigned,84);F(self,unsigned,84)=f14c_min(F(self,unsigned,84),(count-1)/20);fn_80271c94(self);return;}
 char*found=fn_802ef198(keys_804abb9c,key);const char*keys=keys_804abb9c;
 if(!found){found=fn_802ef198(keys_804abba0,key);keys=keys_804abba0;if(!found)return;}
 unsigned index=(found-keys)+F(self,unsigned,84)*20;if(index>=count)return;
 if(keys==keys_804abba0){void*item=items[index];if(item)(*(void(***)(void*))(item))[3](item);void*old=F(self,void*,92);if(old)(*(void(***)(void*))(old))[4](old);F(self,void*,92)=item;fn_80275f18(self);return;}
 void*owner=F(self,void*,88);void*item=items[index];F(owner,F14cText,40).assign(F(item,F14cText,88));fn_8027a98c(self);fn_80271c94(self);
}
