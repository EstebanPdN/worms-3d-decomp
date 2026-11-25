// Partial panel layout. Typed slot storage preserves the witnessed separate base
// address and indexed cursor; original full owner identity/sizeof unknown.
struct d11b_PanelResource;
struct d11b_PanelResourceTable { unsigned int unknown00[4]; void (*release)(d11b_PanelResource *); };
struct d11b_PanelResource { d11b_PanelResourceTable *vtable; };
struct d11b_Panel {
    unsigned char unknown00[48]; d11b_PanelResource *held;
    unsigned char unknown34[32]; d11b_PanelResource *first,*second,*slots[32];
    unsigned int state[4];
};
extern "C" void d11b_release_panel_resource_8015fd1c(d11b_PanelResource *);
extern "C" void d11b_clear_active_panel_802c4380(d11b_Panel *);
extern int d11b_active_panel_804abb54,d11b_resource_count_804abb60,d11b_panel_count_804abb5c;
extern "C" void d11b_clear_panel_802c29d0(d11b_Panel *self) {
    if(self->first)d11b_release_panel_resource_8015fd1c(self->first);
    if(self->second)d11b_release_panel_resource_8015fd1c(self->second);
    unsigned int i=0;
    d11b_PanelResource **storage=self->slots;
    d11b_PanelResource *empty=0;
    do {
        d11b_PanelResource **slot=storage+i;
        if(*slot)d11b_release_panel_resource_8015fd1c(*slot);
        *slot=empty;
        ++i;
    } while(i<32);
    self->first=0;self->second=0;
    self->state[0]=0;self->state[1]=0;self->state[2]=0;self->state[3]=0;
    if(self->held)self->held->vtable->release(self->held);
    self->held=0;
    d11b_clear_active_panel_802c4380(self);
    d11b_active_panel_804abb54=0;
    d11b_resource_count_804abb60-=6;
    --d11b_panel_count_804abb5c;
}
