// (Worms 3D GameCube PAL, 0x801fa6bc).
//
// Per-frame update of a pad device: runs the rumble timer (motor call
// 0x80302104, shared two-tick delay), copies button and axis state to the
// last-frame vectors, decodes the port's status record into 16 button flags
// and eight axes (sticks scaled by 0.02 with Y negated, triggers by 1/255,
// clamped to [-1, 1]), fires each bound action whose button or axis changed,
// sends all changes to every listener, and returns its interface through out
// when given. Names are inferred from the arithmetic and the record layout.

struct PadStatus {
    unsigned short buttons; signed char stickX, stickY, substickX, substickY;
    unsigned char triggerL, triggerR; char pad[4];
};
extern PadStatus pads_8045e824[];
extern int delay_804ab910;
extern "C" void motor_80302104(int port, int on);
struct Event { int type; int kind; int port; int index; union { int i; float f; } value; };
struct Pad;
struct Binding {
    void (*fn)(Pad *, Event *);
    Event event;
};
template <class T> struct Vector { T *first, *last, *end; int pad; T &operator[](int i) { return first[i]; } };
typedef void (*Listener)(Pad *, Event *);
struct Pad {
    char p0[28]; int iface;
    Vector<unsigned char> buttons; Vector<float> axes; char p2[16]; Vector<float> extra;
    Vector<Binding> bindings; Vector<Listener> listeners; int port; char p4[76];
    Vector<unsigned char> lastButtons; Vector<float> lastAxes; Vector<float> lastExtra;
    int rumbleLeft; int rumbleTime;
    unsigned active : 1; unsigned rumbling : 1;
};
extern "C" int w3d_d27e_pad_update_801fa6bc(Pad *self, void **out) {
    if (self->active) {
        if (self->rumbleTime == 0) {
            self->rumbleLeft = 0;
            self->rumbling = 0;
        }
        if (delay_804ab910) {
            delay_804ab910--;
        } else {
            if (self->rumbleLeft == 0) {
                if (!self->rumbling) {
                    motor_80302104(self->port, 1);
                    self->rumbling = 1;
                    self->rumbleLeft = self->rumbleTime;
                    delay_804ab910 = 2;
                    goto count;
                }
            } else if (!self->rumbling) goto count;
            if (self->rumbleTime) {
                motor_80302104(self->port, 0);
                self->rumbling = 0;
            }
        count:
            if (self->rumbleLeft) self->rumbleLeft--;
        }
    }
    PadStatus *pad = &pads_8045e824[self->port];
    unsigned i = 0;
    Vector<Binding> &bindings = self->bindings;
    Event e;
    Event *pe = &e;
    Vector<Listener> &listeners = self->listeners;
    for (; i < 16; ++i) self->lastButtons[i] = self->buttons[i];
    for (i = 0; i < 8; ++i) self->lastAxes[i] = self->axes[i];
    for (i = 0; i < 4; ++i) self->lastExtra[i] = self->extra[i];
    for (i = 0; i < 16; ++i) {
        if ((pad->buttons >> i) & 1) self->buttons[i] = 1;
        else self->buttons[i] = 0;
    }
    float stick = 0.02f;
    float trigger = 0.003921569f;
    self->axes[0] = (float)pad->stickX * stick;
    self->axes[1] = -((float)pad->stickY * stick);
    self->axes[2] = 0.0f;
    self->axes[3] = (float)pad->substickX * stick;
    self->axes[4] = -((float)pad->substickY * stick);
    self->axes[5] = 0.0f;
    self->axes[6] = (float)(int)pad->triggerL * trigger;
    self->axes[7] = (float)(int)pad->triggerR * trigger;
    for (i = 0; i < 8; ++i) {
        if (self->axes[i] > 1.0f) self->axes[i] = 1.0f;
        else if (self->axes[i] < -1.0f) self->axes[i] = -1.0f;
    }
    for (Binding *b = self->bindings.first; b != bindings.last; ++b) {
        switch (b->event.kind) {
        case 0: {
            int n = b->event.index;
            int cur = self->buttons[n];
            if (cur != self->lastButtons[n]) {
                b->event.value.i = cur != 0;
                b->fn(self, &b->event);
            }
            break;
        }
        case 1:
            if (b->event.index == 0 && self->axes[0] != self->lastAxes[0]) {
                b->event.value.f = self->axes[0];
                b->fn(self, &b->event);
            }
            if (b->event.index == 1 && self->axes[1] != self->lastAxes[1]) {
                b->event.value.f = self->axes[1];
                b->fn(self, &b->event);
            }
            if (b->event.index == 3 && self->axes[3] != self->lastAxes[3]) {
                b->event.value.f = self->axes[3];
                b->fn(self, &b->event);
            }
            if (b->event.index == 4 && self->axes[4] != self->lastAxes[4]) {
                b->event.value.f = self->axes[4];
                b->fn(self, &b->event);
            }
            break;
        case 2:
            break;
        }
    }
    e.type = 2;
    pe->kind = 0;
    pe->port = self->port;
    pe->index = 0;
    for (Listener *l = self->listeners.first; l != listeners.last; ++l) {
        e.kind = 0;
        for (i = 0; i < 16; ++i) {
            if (self->buttons[i] != self->lastButtons[i]) {
                e.index = i;
                e.value.i = self->buttons[i] != 0;
                (*l)(self, &e);
            }
        }
        e.kind = 1;
        for (i = 0; i < 8; ++i) {
            if (self->axes[i] != self->lastAxes[i]) {
                e.index = i;
                e.value.f = self->axes[i];
                (*l)(self, &e);
            }
        }
    }
    if (out) *out = &self->iface;
    return 0;
}
