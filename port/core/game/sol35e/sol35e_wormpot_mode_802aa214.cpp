#include "w3d_ptr.h"
#line 1 "sol35e_wormpot_mode_802aa214.cpp"
// Switch the wormpot mode of an owner object.
//
// Observed layout of the owner (offsets read here):
//   +0x1c : sub-object passed to the mode-change helper 0x802b0990
//   +0x28 : pointer to the object that carries the mode payload
//   +0x8c : guard word tested before the start notification
//   +0xb0 : current mode
// Observed layout of the payload carrier:
//   +0x0b : flag byte; bit 2 is tested inverted
//   +0x9c : pointer to a payload whose count is the halfword just before it
//
// The mode helper runs first, then either the start path (three conditions
// and a payload notification) or the stop path.

struct sol35e_W3dPotPayload {
    unsigned char unknown00[8];         // +0x00
    unsigned char flags;                // PPC +0x0b, anfitrión +8
    unsigned char w3d_tag_rest[3];
    unsigned char unknown0c[0x90];      // +0x0c..+0x9c
    Ptr32<unsigned short> payload;            // +0x9c
};

struct sol35e_W3dPotOwner {
    unsigned char unknown00[0x1c];      // +0x00
    unsigned char subObject[12];        // +0x1c
    Ptr32<sol35e_W3dPotPayload> carrier;             // +0x28
    unsigned char unknown2c[0x60];      // +0x2c..+0x8c
    unsigned int guard;                 // +0x8c
    unsigned char unknown90[0x20];      // +0x90..+0xb0
    int mode;                           // +0xb0
};

// Original 0x802b0990 consumes both r3 (subobject) and r4 (requested mode).
extern "C" void w3d_pot_mode_helper_802b0990(Ptr32<void> subObject,int mode);

// Payload notification 0x802b1258, called with the carrier's payload pointer.
extern "C" void w3d_pot_payload_notify_802b1258(Ptr32<unsigned short> payload);

// Start notification 0x802aa33c (already recovered).
extern "C" void w3d_s4_wormpot_start(Ptr32<sol35e_W3dPotOwner> self);

// Stop notification 0x802aa3a4 (already recovered).
extern "C" void w3d_s4_wormpot_stop(Ptr32<sol35e_W3dPotOwner> self);

extern "C" void sol35e_wormpot_mode_802aa214(Ptr32<sol35e_W3dPotOwner> self, int mode)
{
    if (self->mode == mode)
        return;
    w3d_pot_mode_helper_802b0990(self->subObject,mode);
    if (mode) {
        Ptr32<sol35e_W3dPotPayload> carrier = self->carrier;
        Ptr32<unsigned short> payload = carrier->payload;
        if (payload[-2] != 0 && ((carrier->flags ^ 4) & 4) != 0 && self->guard != 0)
            w3d_pot_payload_notify_802b1258(payload);
        w3d_s4_wormpot_start(self);
    } else {
        w3d_s4_wormpot_stop(self);
    }
}

// Partial layouts describe only offsets observed in this function.
typedef char sol35e_owner_carrier_offset[__builtin_offsetof(sol35e_W3dPotOwner,carrier)==0x28?1:-1];


