// Only complete native shared-string, held-pointer and owned-descriptor values
// are local. Team and array storage are external views, never constructed.
typedef unsigned int u32;
typedef unsigned short u16;
extern "C" void fn_8020c5c4(void*),fn_80341588(void*),fn_8020bb2c(void*),fn_8020bb54(void*,const char*);
struct Text_803426b8 {
    char *p;
    Text_803426b8();
    Text_803426b8(const char *s) { fn_8020bb54(this,s); }
    ~Text_803426b8() { fn_8020c5c4(this); fn_80341588(this); }
    void assign(const Text_803426b8 &s) {
        ++*(u16*)(s.p-6);
        if(--*(u16*)(p-6)==0) fn_8020bb2c(p-6);
        p=s.p;
    }
};
struct Object {void (**vtable)();};
struct Held {
    Object *p;
    Held():p(0){}
    Held(Object *q):p(q) { if(p)((void(*)(Object*))p->vtable[3])(p); }
    ~Held() { if(p)((void(*)(Object*))p->vtable[4])(p); }
    void assign(Object *q) { if(q) { ((void(*)(Object*))q->vtable[3])(q); if(p)((void(*)(Object*))p->vtable[4])(p); p=q; } }
};
struct Owned_80178474 {void *p;u32 tag;Owned_80178474():p(0),tag(58280){}~Owned_80178474();};
struct Key {const char *p;Key(const char *s):p(s){}};
struct ArrayHeader {
    u32 unknown0; u16 storageKind; u16 unknown6;
    u32 unknown8[4];u32 count;u16 locks;u16 unknown30;
};
struct TeamView {
    Object base; unsigned char unknown004[20];
    Text_803426b8 speech,flag;
    int weapon,grave,skill,mode;
    unsigned char unknown048[8];
    ArrayHeader *worms;
};
extern "C" {
int fn_800fc1b0(const Key&,Held*),fn_800fc2b0(const Key&,const char**),fn_800fc230(const Key&,int*);
Object *fn_80341584(Object*),*fn_80179598(Object*,Owned_80178474*);
void *fn_801ef048(ArrayHeader**,u32,u32,int);
int fn_8020c510(Text_803426b8*,const char*,...),fn_8020bd38(Text_803426b8*,const char*);
char *fn_802ef198(const char*,int);
extern const char store_803d0940[],wormkey_803d0a0c[],digits_803d0a60[],numberformat_803d0a6c[],flag_803d0a3c[],speech_803d0a48[],weapon_803d0a2c[],skill_803d0a54[],grave_803d0a20[];
}
extern "C" void w3d_g6c_team_properties_80297b8c() {
    Owned_80178474 owned;
    Held resource;
    if(fn_800fc1b0(Key(store_803d0940),&resource)<0) return;
    Held data;
    {Held found(fn_80179598(fn_80341584(resource.p),&owned)); data.assign(found.p);}
    TeamView *team=(TeamView*)data.p;
    ArrayHeader *header=team->worms;
    u32 count=header->count;
    Text_803426b8 *worms;
    if(header->storageKind==1) {worms=(Text_803426b8*)(header+1);++header->locks;}
    else worms=(Text_803426b8*)fn_801ef048(&team->worms,count,4,2);
    Text_803426b8 key;
    for(u32 i=0;i<count;++i) {
        fn_8020c510(&key,wormkey_803d0a0c,i+1);
        const char *name;
        fn_800fc2b0(Key(key.p),&name);
        for(const char *scan=name;*scan;++scan) {
            if(!fn_802ef198(digits_803d0a60,*scan)) {
                if(*scan) { fn_8020bd38(worms+i,name); goto nextWorm; }
                break;
            }
        }
        fn_8020c510(worms+i,numberformat_803d0a6c,name);
        nextWorm:;
    }
    const char *value;
    fn_800fc2b0(Key(flag_803d0a3c),&value);
    team->flag.assign(Text_803426b8(value));
    team->mode=0;
    fn_800fc2b0(Key(speech_803d0a48),&value);
    team->speech.assign(Text_803426b8(value));
    int number;
    fn_800fc230(Key(weapon_803d0a2c),&number);team->weapon=number;
    fn_800fc230(Key(skill_803d0a54),&number);team->skill=number;
    fn_800fc230(Key(grave_803d0a20),&number);team->grave=number;
}
