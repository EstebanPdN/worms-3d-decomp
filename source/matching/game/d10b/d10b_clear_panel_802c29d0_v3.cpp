// Partial panel layout. Typed slot storage preserves the witnessed separate base
// address and indexed cursor; original full owner identity/sizeof unknown.
struct d10b_PanelResource;
struct d10b_PanelResourceTable { unsigned int unknown00[4]; void (*release)(d10b_PanelResource *); };
struct d10b_PanelResource { d10b_PanelResourceTable *vtable; };
struct d10b_Panel {
    unsigned char unknown00[48]; d10b_PanelResource *held;
    unsigned char unknown34[32]; d10b_PanelResource *first,*second,*slots[32];
    unsigned int state[4];
    inline d10b_PanelResource **slot(unsigned int offset) { return reinterpret_cast<d10b_PanelResource **>(offset+reinterpret_cast<char *>(slots)); }
};
extern "C" void d10b_release_panel_resource_8015fd1c(d10b_PanelResource *);
extern "C" void d10b_clear_active_panel_802c4380(d10b_Panel *);
extern int d10b_active_panel_804abb54,d10b_resource_count_804abb60,d10b_panel_count_804abb5c;
extern "C" void d10b_clear_panel_802c29d0(d10b_Panel *self) {
    if(self->first)d10b_release_panel_resource_8015fd1c(self->first);
    if(self->second)d10b_release_panel_resource_8015fd1c(self->second);
    unsigned int i=0;
    unsigned char *storage=reinterpret_cast<unsigned char *>(self->slots);
    unsigned int offset=0;
    do {
        d10b_PanelResource **slot=self->slot(offset);
        if(*slot)d10b_release_panel_resource_8015fd1c(*slot);
        *slot=0;
        ++i;
        offset+=sizeof(d10b_PanelResource *);
    } while(i<32);
    self->first=0;self->second=0;
    self->state[0]=0;self->state[1]=0;self->state[2]=0;self->state[3]=0;
    if(self->held)self->held->vtable->release(self->held);
    self->held=0;
    d10b_clear_active_panel_802c4380(self);
    d10b_active_panel_804abb54=0;
    d10b_resource_count_804abb60-=6;
    --d10b_panel_count_804abb5c;
}
