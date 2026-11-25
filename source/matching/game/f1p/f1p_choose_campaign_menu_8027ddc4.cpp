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
extern "C" void w3d_choose_campaign_menu_8027ddc4(void*,int mode){
 Key current(current_803ceab4);fn_800fc43c(&current,9999);
 Key awarded(awarded_803cec70);fn_800fc43c(&awarded,0);
 switch(mode){
 case 0:{Key key(mission_803ce9a0);fn_800fc43c(&key,0);Cache_8015f704 cache(campaign_803cec80);postEmpty(&cache);break;}
 case 4:{Key key(mission_803ce9a0);fn_800fc43c(&key,4);Key missionCurrent(current_803ceab4);fn_800fc43c(&missionCurrent,0);Cache_8015f704 cache(populate_803ceac8);postChallenge(&cache);Cache_8015f704 team(addchallenge_803ceca8);postFirst(&team);break;}
 case 3:{Key key(mission_803ce9a0);fn_800fc43c(&key,3);Cache_8015f704 cache(tutorial_803cecbc);postEmpty(&cache);break;}
 }
}
