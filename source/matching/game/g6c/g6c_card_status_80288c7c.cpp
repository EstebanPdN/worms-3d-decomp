// External card/controller layouts are views only; neither is constructed here.
typedef unsigned int u32;
typedef unsigned char u8;
inline void *operator new(unsigned int,void *place) { return place; }
struct Colour {
    u8 r,g,b,a;
    Colour() {}
    Colour(u8 red,u8 green,u8 blue,u8 alpha) { r=red; g=green; b=blue; a=alpha; }
};
struct BlockText { char bytes[32]; BlockText() { bytes[0]=0; } operator char *() { return bytes; } };
struct Text;
struct HeldText { Text *p; };
struct Card {
    void (**vtable)();
    u8 unknown004[684];
    int selected, status, bytes, unknown700, state;
    u8 shade;
    u8 unknown709[195];
    HeldText items[5];
    Text *extra;
    int extraIndex;
    u8 unknown932[28];
    u32 count;
    int unknown964, active;
    const char *loading,*slot,*blocks;
    u8 unknown984[28];
    float timeout;
    u32 flags;
};
struct Record { int status; int unknown4; int hasText; int selected; };
struct Controller { void (**vtable)(); u8 unknown004[72]; u32 flags; };
extern Controller *controller_804b1788;
extern "C" {
Record *fn_8028924c(Card *,int);
int fn_800fc2b0(const char **,const char **);
void fn_80289d70(Card *,const char *,const char *);
int fn_8035eb0c(char *,const char *,...);
void fn_80289290(Card *,Record *);
int fn_802fb7ac(const char *,...);
int fn_8018d35c(Text *,const Colour *);
int fn_8018d434(Text *,const Colour *);
extern const char loading_803cf960[],saving_803cf970[],slot_803cf980[],slotvalue_803cf98c[],format_803cf990[],blocks_803cf994[],busy_803cf9a8[];
extern const float timeout_803cf9c0[];
}
static inline void pump(Controller *p) { ((void (*)(Controller *,int))p->vtable[16])(p,0); }
extern "C" void w3d_g6c_card_status_80288c7c(Card *self,int status,int unused,int operation) {
    bool changed=false;
    if(self->status!=status) { self->status=status; changed=true; }
    Record *record=fn_8028924c(self,status);
    if(operation==2) { const char *key=loading_803cf960; fn_800fc2b0(&key,&self->loading); }
    else { const char *key=saving_803cf970; fn_800fc2b0(&key,&self->loading); }
    fn_80289d70(self,slot_803cf980,slotvalue_803cf98c);
    { const char *key=slot_803cf980; fn_800fc2b0(&key,&self->slot); }
    BlockText blockText;
    fn_8035eb0c(blockText,format_803cf990,self->bytes/8192);
    fn_80289d70(self,blocks_803cf994,blockText);
    { const char *key=blocks_803cf994; fn_800fc2b0(&key,&self->blocks); }
    if(record) {
        Colour white, black, steadyWhite, selected;
        const Colour *normal, *highlight;
        if(changed) {
            self->selected=record->selected;
            fn_80289290(self,record);
            if(status==-2) {
                fn_802fb7ac(busy_803cf9a8);
                pump(controller_804b1788);
                controller_804b1788->flags &= ~0x10000000U;
                int frames=13;
                do {
                    ((void (*)(Card *,int))self->vtable[8])(self,0);
                    pump(controller_804b1788);
                } while(--frames);
                controller_804b1788->flags |= 0x10000000U;
            }
            normal=new(&white) Colour(255,255,255,0);
            highlight=new(&black) Colour(0,0,0,0);
            if(!record->hasText) return;
            u32 i=0;
            if(i<self->count) {
                HeldText *text=self->items;
                do { ++i; fn_8018d35c(text->p,normal); fn_8018d434((text++)->p,highlight); } while(i<self->count);
            }
            if(self->extra) { fn_8018d35c(self->extra,normal); fn_8018d434(self->extra,highlight); }

        } else {
            u8 shade=self->shade;
            normal=new(&steadyWhite) Colour(255,255,255,255);
            highlight=new(&selected) Colour((shade>>1)|128,shade,shade,255);
            if(!record->hasText) return;
            u32 i=0;
            if(i<self->count) {
                HeldText *text=self->items;
                do { ++i; fn_8018d35c((text++)->p,normal); } while(i<self->count);
            }
            if(self->extra) fn_8018d35c(self->extra,normal);

        }
        fn_8018d35c(self->items[self->selected].p,highlight);
        if(self->extraIndex==self->selected) fn_8018d35c(self->extra,highlight);
    } else {
        if(self->active && !(self->flags&0x04000000U)) { self->state=3; self->timeout=timeout_803cf9c0[0]; }
        self->selected=0;
    }
}
