#include "w3d_ptr.h"
#line 1 "cc44a_input_event_80160cd8_v1.cpp"
// DOL literals decoded independently: 803a467c=0.125f, 803a4680=0.0f,
// 803a4684=0.875f. Preserve the comparison order and single-precision arithmetic.
// Inferred event view: observed word offsets only; original class identity unknown.
struct cc44a_Input;
struct cc44a_Event {
    unsigned int unknown0;
    int kind;
    unsigned int device;
    unsigned int code;
    union { int button; float axis; } value;
};
extern Ptr32<cc44a_Input> cc44a_input_804b17f0;
// All three return the signed callback-dispatch result (8015fc84).
// Device is received as a full GPR and narrowed by the callee's byte store.
extern "C" int cc44a_press_80160628(Ptr32<cc44a_Input>, unsigned int, unsigned int);
extern "C" int cc44a_release_80160698(Ptr32<cc44a_Input>, unsigned int, unsigned int);
extern "C" int cc44a_axis_80160708(Ptr32<cc44a_Input>, unsigned int, unsigned int, float);
extern "C" double fabs(double);
extern "C" int cc44a_input_event_80160cd8(Ptr32<void>, Ptr32<const cc44a_Event> event) {
    switch(event->kind) {
    case 0:
        if(event->value.button == 1)
            cc44a_press_80160628(cc44a_input_804b17f0, event->device, event->code);
        else
            cc44a_release_80160698(cc44a_input_804b17f0, event->device, event->code);
        break;
    case 1: {
        float value = event->value.axis;
        float magnitude = fabs(value);
        if (magnitude < 0.125f) value = 0.0f;
        else if (magnitude > value) value = -(magnitude - 0.125f) / 0.875f;
        else value = (magnitude - 0.125f) / 0.875f;
        cc44a_axis_80160708(cc44a_input_804b17f0, event->device, event->code, value);
        break;
    }
    }
    return 0;
}


