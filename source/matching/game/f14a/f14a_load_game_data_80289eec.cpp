// Names and roles inferred. Handle locals occupy observed eight-byte stack slots;
// only their first words are accessed. No complete owner or resource type claimed.
struct F14aLoadIface { void **table; };
struct F14aLoadHeld {
    F14aLoadIface *p; unsigned unobservedStorage;
    F14aLoadHeld(F14aLoadIface *v):p(v) {
        if(p) ((void(*)(F14aLoadIface*))p->table[3])(p);
    }
    ~F14aLoadHeld() { if(p) ((void(*)(F14aLoadIface*))p->table[4])(p); }
};
struct F14aLoadCard { char unknown0[1016]; unsigned flags; };
struct F14aLoadData { void *data; unsigned unobservedStorage; };
// Original helper reads the state word at +0 and name pointer at +4.
struct F14aLoadCache { unsigned state; const char *name; };
extern "C" void fn_802fb7ac(const char*,...);
extern "C" F14aLoadIface *fn_80208aac(int), *fn_8020b680(void*);
extern "C" void *fn_802eee50(void*,const void*,unsigned);
extern "C" void fn_800fd5f4(F14aLoadIface*);
extern "C" void *fn_801613f0(void*,int);
extern "C" int fn_8015f5a0(F14aLoadCache*,int);
extern "C" void *fn_8010a8e0(void*,unsigned short,const char*);
extern "C" int fn_8016239c(void*);
extern "C" void fn_80280370(void*),fn_8028a6c0(F14aLoadCard*);
extern char text_803cfa90[], text_803cfaa4[], text_803cfaac[], type_80418de0[];
extern void *heap_804b1754, *frontend_804abbac;
extern F14aLoadCache cache_804b0c44,cache_804b0c4c;
extern "C" void w3d_f14a_load_game_data_80289eec(F14aLoadCard *s,const void *input) {
    fn_802fb7ac(text_803cfa90);
    s->flags |= 0x40000000;
    F14aLoadHeld blob(fn_80208aac(1));
    ((void(*)(F14aLoadIface*,unsigned))blob.p->table[8])(blob.p,0x11800);
    F14aLoadData data;
    ((void(*)(F14aLoadIface*,F14aLoadData*))blob.p->table[10])(blob.p,&data);
    fn_802eee50(data.data,input,0x11800);
    F14aLoadHeld service(fn_8020b680(type_80418de0));
    ((void(*)(F14aLoadIface*,F14aLoadIface*))service.p->table[5])(service.p,blob.p);
    fn_800fd5f4(service.p);
    { void *message=fn_801613f0(heap_804b1754,12);
    unsigned short id=fn_8015f5a0(&cache_804b0c44,1);
    fn_8016239c(fn_8010a8e0(message,id,text_803cfaa4));
    }
    { void *message=fn_801613f0(heap_804b1754,12);
    unsigned short id=fn_8015f5a0(&cache_804b0c4c,1);
    fn_8016239c(fn_8010a8e0(message,id,text_803cfaac));
    }
    fn_80280370(frontend_804abbac);
    fn_8028a6c0(s);
}
