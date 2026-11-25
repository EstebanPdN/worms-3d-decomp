#include "w3d_ptr.h"
#line 1 "f1p_previous_mission_8027e1ec.cpp"
// Partial observed cache, string, global and owner layouts; roles inferred.
extern "C" void fn_8020c5c4(Ptr32<void>),fn_80341588(Ptr32<void>),fn_8015f558(Ptr32<void>,int);
struct String{
 String(const String &); String() {}Ptr32<char> text;~String(){fn_8020c5c4(this);fn_80341588(this);}};
struct CallerString{Ptr32<char> text;~CallerString(){fn_8020c5c4(this);fn_80341588(this);}};
struct CacheBase{int prefix[2];~CacheBase(){fn_8015f558(this,2);}};
struct Cache_8015f704:CacheBase{String name __attribute__((aligned(__alignof__(CacheBase))));template <class W3dU> Cache_8015f704(Ptr32<W3dU> w3d_p) : Cache_8015f704((const char *)w3d_p.get()) {}
 Cache_8015f704(const char*);};
struct Message;struct Owner{char unknown[64];int state;};struct Global{char unknown[208];int mode;};
extern Ptr32<void> queue_804b1754; extern Ptr32<void> app_804b1788;extern Ptr32<Global> global_804aaabc;extern int depth_804abb5c,count_804abb60;
extern char change_803cfff0[],menu_803d0000[];
extern "C" Ptr32<Message> fn_801613f0(Ptr32<void>,int); Ptr32<Message> fn_8010a8e0(Ptr32<Message>,unsigned short,Ptr32<const char>);
extern "C" unsigned fn_8015f5a0(Ptr32<Cache_8015f704>,int);
extern "C" void fn_80129878(Ptr32<void>),fn_800fde38(),fn_800a7e14(int,Ptr32<const char>);
extern "C" int fn_8016239c(Ptr32<Message>);
inline void post(Ptr32<Cache_8015f704> cache,const CallerString&name){Ptr32<Message> m=fn_801613f0(queue_804b1754,12);fn_8016239c(fn_8010a8e0(m,fn_8015f5a0(cache,1),name.text));}
struct Key{Ptr32<const char> text;template <class W3dU> Key(Ptr32<W3dU> w3d_p) : Key((const char *)w3d_p.get()) {}
 Key(const char*p):text(p){}};
extern char current_803ceab4[],find_803cea44[],first_803ceaf0[],awarded_803cec70[],mission_803ce9a0[],campaign_803cec80[],empty_803ceb40[],populate_803ceac8[],challenge_803cec94[],addchallenge_803ceca8[],tutorial_803cecbc[];
extern "C" int fn_800fc43c(Ptr32<Key>,int);
inline void postEmpty(Ptr32<Cache_8015f704> cache){Ptr32<Message> m=fn_801613f0(queue_804b1754,12);fn_8016239c(fn_8010a8e0(m,fn_8015f5a0(cache,1),find_803cea44));}
inline void postChallenge(Ptr32<Cache_8015f704> cache){Ptr32<Message> m=fn_801613f0(queue_804b1754,12);fn_8016239c(fn_8010a8e0(m,fn_8015f5a0(cache,1),challenge_803cec94));}
inline void postFirst(Ptr32<Cache_8015f704> cache){Ptr32<Message> m=fn_801613f0(queue_804b1754,12);fn_8016239c(fn_8010a8e0(m,fn_8015f5a0(cache,1),first_803ceaf0));}

extern char retry_803cea38[],next_803ceb44[],previous_803ceb30[],campaigntext_803ceadc[],tutorialtext_803cecd0[];
extern "C" int fn_800fc230(Ptr32<Key>,Ptr32<int>),fn_8027be7c(Ptr32<void>,int);
extern "C" void fn_8027d2ac(Ptr32<void>);
inline void postCampaign(const Cache_8015f704&cache){Ptr32<Message> m=fn_801613f0(queue_804b1754,12);fn_8016239c(fn_8010a8e0(m,fn_8015f5a0((Ptr32<Cache_8015f704>)&cache,1),campaigntext_803ceadc));}
inline void postTutorial(const Cache_8015f704&cache){Ptr32<Message> m=fn_801613f0(queue_804b1754,12);fn_8016239c(fn_8010a8e0(m,fn_8015f5a0((Ptr32<Cache_8015f704>)&cache,1),tutorialtext_803cecd0));}
extern "C" void w3d_previous_mission_8027e1ec(Ptr32<void> self){
 Key current(current_803ceab4);int index;fn_800fc230(&current,&index);
 Key retry(retry_803cea38);fn_800fc43c(&retry,0);
 Key type(mission_803ce9a0);int mode;fn_800fc230(&type,&mode);
 int category=mode;
 if(index==0){Key previous(previous_803ceb30);fn_800fc43c(&previous,0);return;}
 --index;Key selected(current_803ceab4);fn_800fc43c(&selected,index);
 switch(category){case 0:postCampaign(Cache_8015f704(populate_803ceac8));break;case 3:postTutorial(Cache_8015f704(populate_803ceac8));break;case 4:goto update;}
update: fn_8027d2ac(self);
}


