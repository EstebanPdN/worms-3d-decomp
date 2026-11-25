#include "w3d_ptr.h"
#line 1 "cc43b_update_controls_80260144_v1.cpp"
// Partial views preserve observed offsets; original names and full sizes unknown.
struct cc43b_Control;
struct cc43b_ControlVtable { unsigned int unknown00[22]; Ptr32<void (Ptr32<cc43b_Control>, unsigned int)> set; };
struct cc43b_Control { Ptr32<cc43b_ControlVtable> vtable; };
struct cc43b_Core {
    unsigned char unknown00[8]; unsigned char flags; char w3d_tag_rest[3];
    unsigned char unknown0c[104]; float amount;
    unsigned char unknown78[24]; unsigned int available;
};
struct cc43b_ControlsOwner {
    unsigned char unknown00[40]; Ptr32<cc43b_Core> core;
    unsigned char unknown2c[96]; unsigned int phase;
    unsigned char unknown90[32]; unsigned int state;
    unsigned char unknownb4[52]; Ptr32<cc43b_Control> first; Ptr32<cc43b_Control> second; Ptr32<cc43b_Control> third;
};
extern float cc43b_zero_803cab98[];
extern "C" void cc43b_update_controls_80260144(Ptr32<cc43b_ControlsOwner> self) {
    unsigned int first=self->state^1U;
    unsigned int second=self->state;
    unsigned int third=self->phase^1U;
    if (!self->phase) {
        if (self->third) {
            if (self->core->amount==cc43b_zero_803cab98[0]) { first=0; second=0; }
            if (!self->core->available) { first=0; second=0; third=1; }
        } else { first=1; second=0; }
    }
    if (self->first) self->first->vtable->set(self->first,first);
    if (self->second) self->second->vtable->set(self->second,second);
    if (((self->core->flags^4U)&4U)==0) {
        if (self->third) self->third->vtable->set(self->third,1);
    } else {
        if (self->third) self->third->vtable->set(self->third,third);
    }
}


