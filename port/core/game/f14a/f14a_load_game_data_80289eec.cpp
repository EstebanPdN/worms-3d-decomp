#include "w3d_ptr.h"
#line 1 "f14a_load_game_data_80289eec.cpp"
// Names and roles inferred. Handle locals occupy observed eight-byte stack slots;
// only their first words are accessed. No complete owner or resource type claimed.
struct F14aLoadIface { Ptr32<Ptr32<void>> table; };
struct F14aLoadHeld {
    Ptr32<F14aLoadIface> p; unsigned unobservedStorage;
    template <class W3dU> F14aLoadHeld(Ptr32<W3dU> w3d_p) : F14aLoadHeld((F14aLoadIface *)w3d_p.get()) {}
 F14aLoadHeld(F14aLoadIface *v):p(v) {
        if(p) ((Ptr32<void (Ptr32<F14aLoadIface>)>)p->table[3])(p);
    }
    ~F14aLoadHeld() { if(p) ((Ptr32<void (Ptr32<F14aLoadIface>)>)p->table[4])(p); }
};
struct F14aLoadCard { char unknown0[1016]; unsigned flags; };
struct F14aLoadData { Ptr32<void> data; unsigned unobservedStorage; unsigned w3d_capacity; };
// Original helper reads the state word at +0 and name pointer at +4.
struct F14aLoadCache { unsigned state; Ptr32<const char> name; };
extern "C" void fn_802fb7ac(Ptr32<const char>,...);
extern "C" Ptr32<F14aLoadIface> fn_80208aac(int); Ptr32<F14aLoadIface> fn_8020b680(Ptr32<void>);
extern "C" Ptr32<void> fn_802eee50(Ptr32<void>,Ptr32<const void>,unsigned);
extern "C" void fn_800fd5f4(Ptr32<F14aLoadIface>);
extern "C" Ptr32<void> fn_801613f0(Ptr32<void>,int);
extern "C" int fn_8015f5a0(Ptr32<F14aLoadCache>,int);
extern "C" Ptr32<void> fn_8010a8e0(Ptr32<void>,unsigned short,Ptr32<const char>);
extern "C" int fn_8016239c(Ptr32<void>);
extern "C" void fn_80280370(Ptr32<void>),fn_8028a6c0(Ptr32<F14aLoadCard>);
extern char text_803cfa90[], text_803cfaa4[], text_803cfaac[], type_80418de0[];
extern Ptr32<void> heap_804b1754; extern Ptr32<void> frontend_804abbac;
extern F14aLoadCache cache_804b0c44,cache_804b0c4c;
extern "C" void w3d_f14a_load_game_data_80289eec(Ptr32<F14aLoadCard> s,Ptr32<const void> input) {
    fn_802fb7ac(text_803cfa90);
    s->flags |= 0x40000000;
    F14aLoadHeld blob(fn_80208aac(1));
    ((Ptr32<void (Ptr32<F14aLoadIface>, unsigned int)>)blob.p->table[8])(blob.p,0x11800);
    F14aLoadData data;
    ((Ptr32<void (Ptr32<F14aLoadIface>, Ptr32<F14aLoadData>)>)blob.p->table[10])(blob.p,&data);
    fn_802eee50(data.data,input,0x11800);
    F14aLoadHeld service(fn_8020b680(type_80418de0));
    ((Ptr32<void (Ptr32<F14aLoadIface>, Ptr32<F14aLoadIface>)>)service.p->table[5])(service.p,blob.p);
    fn_800fd5f4(service.p);
    { Ptr32<void> message=fn_801613f0(heap_804b1754,12);
    unsigned short id=fn_8015f5a0(&cache_804b0c44,1);
    fn_8016239c(fn_8010a8e0(message,id,text_803cfaa4));
    }
    { Ptr32<void> message=fn_801613f0(heap_804b1754,12);
    unsigned short id=fn_8015f5a0(&cache_804b0c4c,1);
    fn_8016239c(fn_8010a8e0(message,id,text_803cfaac));
    }
    fn_80280370(frontend_804abbac);
    fn_8028a6c0(s);
}


