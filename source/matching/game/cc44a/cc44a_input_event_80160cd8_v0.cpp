// Inferred event view: observed word offsets only; original class identity unknown.
struct cc44a_Input;
struct cc44a_Event {
    unsigned int unknown0;
    int kind;
    unsigned int device;
    unsigned int code;
    union { int button; float axis; } value;
};
extern cc44a_Input *cc44a_input_804b17f0;
// All three return the signed callback-dispatch result (8015fc84).
// Device is received as a full GPR and narrowed by the callee's byte store.
extern "C" int cc44a_press_80160628(cc44a_Input *, unsigned int, unsigned int);
extern "C" int cc44a_release_80160698(cc44a_Input *, unsigned int, unsigned int);
extern "C" int cc44a_axis_80160708(cc44a_Input *, unsigned int, unsigned int, float);
extern "C" double fabs(double);
extern "C" int cc44a_input_event_80160cd8(void *, const cc44a_Event *event) {
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
        float result;
        if (magnitude < 0.2f) result = 0.0f;
        else if (magnitude > value) result = -(magnitude - 0.2f) / 0.8f;
        else result = (magnitude - 0.2f) / 0.8f;
        cc44a_axis_80160708(cc44a_input_804b17f0, event->device, event->code, result);
        break;
    }
    }
    return 0;
}
