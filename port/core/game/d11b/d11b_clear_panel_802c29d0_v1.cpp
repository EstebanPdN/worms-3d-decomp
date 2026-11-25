#include "w3d_ptr.h"
#line 1 "d11b_clear_panel_802c29d0_v1.cpp"
// Partial panel layout. Typed slot storage preserves the witnessed separate base
// address and indexed cursor; original full owner identity/sizeof unknown.
struct d11b_PanelResource;
struct d11b_PanelResourceTable { unsigned int unknown00[4]; Ptr32<void (Ptr32<d11b_PanelResource>)> release; };
struct d11b_PanelResource { Ptr32<d11b_PanelResourceTable> vtable; };
struct d11b_Panel {
    unsigned char unknown00[48]; Ptr32<d11b_PanelResource> held;
    unsigned char unknown34[32]; Ptr32<d11b_PanelResource> first; Ptr32<d11b_PanelResource> second; Ptr32<d11b_PanelResource> slots[32];
    unsigned int state[4];
};
extern "C" void d11b_release_panel_resource_8015fd1c(Ptr32<d11b_PanelResource>);
extern "C" void d11b_clear_active_panel_802c4380(Ptr32<d11b_Panel>);
extern int d11b_active_panel_804abb54,d11b_resource_count_804abb60,d11b_panel_count_804abb5c;
extern "C" void d11b_clear_panel_802c29d0(Ptr32<d11b_Panel> self) {
    if(self->first)d11b_release_panel_resource_8015fd1c(self->first);
    if(self->second)d11b_release_panel_resource_8015fd1c(self->second);
    unsigned int i=0;
    Ptr32<Ptr32<d11b_PanelResource>> storage=self->slots;
    Ptr32<d11b_PanelResource> empty=0;
    do {
        Ptr32<Ptr32<d11b_PanelResource>> slot=storage+i;
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


