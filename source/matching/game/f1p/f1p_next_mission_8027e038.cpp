// Partial observed cache, string, global and owner layouts; roles inferred.
extern "C" void fn_8020c5c4(void*),fn_80341588(void*),fn_8015f558(void*,int);
struct String{
 String(const String &); String() {}char*text;~String(){fn_8020c5c4(this);fn_80341588(this);}};
struct CallerString{char*text;~CallerString(){fn_8020c5c4(this);fn_80341588(this);}};
struct CacheBase{int prefix[2];~CacheBase(){fn_8015f558(this,2);}};
struct Cache_8015f704:CacheBase{String name;Cache_8015f704(const char*);};
struct Message;struct Owner{char unknown[64];int state;};struct Global{char unknown[208];int mode;};
extern void*queue_804b1754,*app_804b1788;extern Global*global_804aaabc;extern int depth_804abb5c,count_804abb60;
extern char change_803cfff0[],menu_803d0000[];
extern "C" Message*fn_801613f0(void*,int),*fn_8010a8e0(Message*,unsigned short,const char*);
extern "C" unsigned fn_8015f5a0(Cache_8015f704*,int);
extern "C" void fn_80129878(void*),fn_800fde38(),fn_800a7e14(int,const char*);
extern "C" int fn_8016239c(Message*);
inline void post(Cache_8015f704*cache,const CallerString&name){Message*m=fn_801613f0(queue_804b1754,12);fn_8016239c(fn_8010a8e0(m,fn_8015f5a0(cache,1),name.text));}
struct Key{const char*text;Key(const char*p):text(p){}};
extern char current_803ceab4[],find_803cea44[],first_803ceaf0[],awarded_803cec70[],mission_803ce9a0[],campaign_803cec80[],empty_803ceb40[],populate_803ceac8[],challenge_803cec94[],addchallenge_803ceca8[],tutorial_803cecbc[];
extern "C" int fn_800fc43c(Key*,int);
inline void postEmpty(Cache_8015f704*cache){Message*m=fn_801613f0(queue_804b1754,12);fn_8016239c(fn_8010a8e0(m,fn_8015f5a0(cache,1),find_803cea44));}
inline void postChallenge(Cache_8015f704*cache){Message*m=fn_801613f0(queue_804b1754,12);fn_8016239c(fn_8010a8e0(m,fn_8015f5a0(cache,1),challenge_803cec94));}
inline void postFirst(Cache_8015f704*cache){Message*m=fn_801613f0(queue_804b1754,12);fn_8016239c(fn_8010a8e0(m,fn_8015f5a0(cache,1),first_803ceaf0));}

extern char retry_803cea38[],next_803ceb44[],previous_803ceb30[],campaigntext_803ceadc[],tutorialtext_803cecd0[];
extern "C" int fn_800fc230(Key*,int*),fn_8027be7c(void*,int);
extern "C" void fn_8027d2ac(void*);
inline void postCampaign(const Cache_8015f704&cache){Message*m=fn_801613f0(queue_804b1754,12);fn_8016239c(fn_8010a8e0(m,fn_8015f5a0((Cache_8015f704*)&cache,1),campaigntext_803ceadc));}
inline void postTutorial(const Cache_8015f704&cache){Message*m=fn_801613f0(queue_804b1754,12);fn_8016239c(fn_8010a8e0(m,fn_8015f5a0((Cache_8015f704*)&cache,1),tutorialtext_803cecd0));}
extern "C" void w3d_next_mission_8027e038(void*self){
 Key current(current_803ceab4);int index;fn_800fc230(&current,&index);
 Key retry(retry_803cea38);fn_800fc43c(&retry,0);
 Key type(mission_803ce9a0);int mode;fn_800fc230(&type,&mode);
 int category=mode;
 unsigned last=fn_8027be7c(self,category)-1;
 if((unsigned)(index+1)>last){Key next(next_803ceb44);fn_800fc43c(&next,0);return;}
 ++index;Key selected(current_803ceab4);fn_800fc43c(&selected,index);
 switch(category){case 0:postCampaign(Cache_8015f704(populate_803ceac8));break;case 3:postTutorial(Cache_8015f704(populate_803ceac8));break;case 4:goto update;}
update: fn_8027d2ac(self);
}
