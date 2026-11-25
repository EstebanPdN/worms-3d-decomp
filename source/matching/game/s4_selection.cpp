extern "C" {
struct S4Object { void (**vtable)(); };
struct S4Text { char *text; int gap; };
struct S4Config { unsigned char pad[11]; unsigned char flags; unsigned char pad12[112]; char *name; unsigned char pad128[12]; int wrap; };
struct S4Entry { S4Object *object; int value; char *text; };
struct S4Selection {
    void *vtable; unsigned char pad4[24]; unsigned char base[12]; S4Config *config;
    unsigned char pad44[96]; int enabled; unsigned char pad144[32]; int active;
    unsigned char pad180[28]; void *secondaryVtable; int mode,unknown216,busy;
    S4Entry *begin,*end,*capacity; int unknown236; unsigned int selected;
    S4Object *children[3]; S4Object *current,*pending,*first,*second;
};
void w3d_ctor_8015fef0(void *);
void w3d_selection_base_construct_802afb20(void *);
void w3d_selection_base_reset_802b0fec(void *);
void w3d_selection_clear_80285ee0(void *);
void w3d_selection_activate_802b0990(void *,int);
void w3d_selection_name_802b1258(const char *);
int w3d_selection_edge_802b22b0(void *);
void w3d_selection_highlight_80286b40(S4Selection *,int);
int w3d_auto_80178c48(void *);
int w3d_auto_80178d1c(void *);
void *w3d_empty_803426b4(void *);
void *w3d_constructor_native_cast(void *);
extern unsigned char w3d_vtable_8041bf90[],w3d_vtable_8041bf40[];
// Deferred: constructor stack layout and store scheduling differ after four attempts.
#if 0
S4Selection *w3d_s4_selection_construct(S4Selection *self)
{
    w3d_ctor_8015fef0(self);
    w3d_selection_base_construct_802afb20(self->base);
    self->secondaryVtable=w3d_vtable_8041bf40;
    self->vtable=w3d_vtable_8041bf90;
    struct S4Pair { S4Entry *begin,*end; };
    S4Pair empty={0,0};
    *(S4Pair *)&self->begin=empty;
    int *tail=(int *)((char *)self+232); tail[1]=0;
    struct { S4Object **pointer; int gap; } local;
    local.pointer=self->children;
    S4Object **child=local.pointer;
    for(int i=3;i;--i) *child++=0;
    self->selected=0; self->busy=0; self->current=0; self->pending=0; self->first=0; self->second=0;
    self->mode=0; self->unknown216=0;
    return self;
}
#endif
void w3d_s4_selection_reset(S4Selection *self)
{
    if(self->pending) ((void (*)(S4Object *))self->pending->vtable[4])(self->pending);
    self->pending=0;
    w3d_selection_clear_80285ee0(self);
    w3d_selection_base_reset_802b0fec(self->base);
}
void w3d_selection_visibility_802870fc(S4Selection *self);
void w3d_s4_selection_set_active(S4Selection *self,int active)
{
    if(self->active != active) {
        if(active) {
            S4Config *config=self->config;
            if(*(unsigned short *)(config->name-4) && ((config->flags^4)&4) && self->enabled)
                w3d_selection_name_802b1258(config->name);
            *(int *)((char *)self->first+16)=1;
            *(int *)((char *)self->second+16)=1;
        } else {
            *(int *)((char *)self->first+16)=active;
            *(int *)((char *)self->second+16)=active;
        }
    }
    w3d_selection_activate_802b0990(self->base,active);
    w3d_selection_visibility_802870fc(self);
}
int w3d_s4_selection_value_changed(void *,S4Selection *self)
{
    int value;
    if(self->busy) return 0;
    int kind=((int (*)(S4Object *))self->current->vtable[6])(self->current);
    switch(kind) {
    case 0: value=w3d_auto_80178c48(w3d_empty_803426b4(self->current)); break;
    case 1: value=w3d_auto_80178d1c(w3d_constructor_native_cast(self->current)); break;
    }
    w3d_selection_highlight_80286b40(self,value);
    return 0;
}
int w3d_s4_selection_navigate(S4Selection *self,int direction)
{
    struct S4Range { S4Entry *begin,*end; };
    S4Range *range=(S4Range *)((char *)self+224);
    int count=range->end-range->begin;
    S4Config *config=self->config;
    if(count==0) return 0;
    if(direction==1) {
        unsigned int old=self->selected++;
        if(self->selected >= (unsigned int)(range->end-range->begin)) {
            if(config->wrap==1) self->selected=0;
            else {self->selected=old; w3d_selection_edge_802b22b0(self->base);}
        }
    } else if(self->selected==0) {
        if(config->wrap==1) self->selected=count-1;
        else w3d_selection_edge_802b22b0(self->base);
    } else --self->selected;
    return self->begin[self->selected].value;
}
// Deferred: boolean branch lowering differs after three attempts.
#if 0
void w3d_selection_visibility_802870fc(S4Selection *self)
{
    int other=self->active^1;
    int active=self->active;
    int enabled=self->enabled;
    int disabled=enabled^1;
    if(!enabled) {
        bool hidden;
        if(self->children[2]) hidden=false; else hidden=true;
        other=hidden;
        active=0;
    }
    if(self->children[0]) ((void (*)(S4Object *,int))self->children[0]->vtable[22])(self->children[0],other);
    if(self->children[1]) ((void (*)(S4Object *,int))self->children[1]->vtable[22])(self->children[1],active);
    if(self->children[2]) ((void (*)(S4Object *,int))self->children[2]->vtable[22])(self->children[2],disabled);
}
#endif
}
