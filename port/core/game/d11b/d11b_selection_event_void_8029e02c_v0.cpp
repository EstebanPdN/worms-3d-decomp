#include "w3d_ptr.h"
#line 1 "d11b_selection_event_void_8029e02c_v0.cpp"
// Observed message ID is unsigned sixteen-bit. Owner/base/configuration are
// partial views; full class identities and sizes remain unknown.
struct d11b_SelectionEvent { unsigned short id; };
struct d11b_EventConfiguration { unsigned char unknown00[8]; unsigned char flags; char w3d_tag_rest[3]; };
struct d11b_EventSlider;
struct d11b_EventBase;
struct d11b_EventOwner {
    unsigned char unknown00[40]; Ptr32<d11b_EventConfiguration> config;
    unsigned char unknown2c[84]; int blocked;
    unsigned char unknown84[8]; int enabled;
    unsigned char unknown90[32]; int selected;
    unsigned char unknownb4[8]; int ready;
    unsigned char unknownc0[184]; Ptr32<d11b_EventSlider> slider;
    unsigned int unknown17c; float position;
};
struct d11b_EventCache { unsigned int state; Ptr32<const char> text; };
extern int d11b_event_blocked_804abb48;
extern d11b_EventCache d11b_previous_event_804b0e5c,d11b_next_event_804b0e64;
extern const float d11b_event_step_803d1cfc[];
extern "C" int d11b_event_base_handler_8015fb34(Ptr32<d11b_EventOwner>,Ptr32<d11b_SelectionEvent>);
extern "C" void d11b_event_setup_8029e584(Ptr32<d11b_EventOwner>);
extern "C" void d11b_event_reset_8029ea40(Ptr32<d11b_EventOwner>);
extern "C" int d11b_event_current_context_802b264c(Ptr32<d11b_EventBase>);
extern "C" int d11b_event_equals_8015f65c(unsigned int,Ptr32<d11b_EventCache>);
extern "C" void d11b_event_set_slider_80296410(Ptr32<d11b_EventSlider>,float);
extern "C" void d11b_event_forward_802aff9c(Ptr32<d11b_EventBase>,Ptr32<d11b_SelectionEvent>);
extern "C" int d11b_selection_event_void_8029e02c(Ptr32<d11b_EventOwner> self,Ptr32<d11b_SelectionEvent> event) {
    switch(event->id) {
    case 64:
        if(d11b_event_base_handler_8015fb34(self,event)>=0) {d11b_event_setup_8029e584(self);return 0;}
        return static_cast<int>(0x80004005u);
    case 66: d11b_event_reset_8029ea40(self);break;
    default:
        if(d11b_event_current_context_802b264c(reinterpret_cast<d11b_EventBase *>(w3d::R(reinterpret_cast<unsigned char *>(w3d::R(self))+28)))) {
            if(!d11b_event_blocked_804abb48 && !self->blocked && self->selected && ((self->config->flags^4)&4) && self->enabled && self->ready && self->slider) {
                if(d11b_event_equals_8015f65c(event->id,&d11b_previous_event_804b0e5c)) {
                    d11b_event_set_slider_80296410(self->slider,self->position-d11b_event_step_803d1cfc[0]);return 0;
                }
                if(d11b_event_equals_8015f65c(event->id,&d11b_next_event_804b0e64)) {
                    d11b_event_set_slider_80296410(self->slider,self->position+d11b_event_step_803d1cfc[0]);return 0;
                }
            }
            d11b_event_forward_802aff9c(reinterpret_cast<d11b_EventBase *>(w3d::R(reinterpret_cast<unsigned char *>(w3d::R(self))+28)),event);
        }
    }
    return d11b_event_base_handler_8015fb34(self,event);
}


