// Spinner message handler (original 0x8028b008).
// GC32 reconstruction from the original instructions; class and field names
// are inferred. Message 64 runs the base handler and opens the spinner
// (E_FAIL 0x80004005 when the base handler fails); message 66 resets it.
// Other messages are handled when the embedded control is ready and input is
// not locked: the edit message starts editing (one wrapping increment, a
// sound for the configured name and the editing flag) when the control is
// editable and enabled; the up/down messages and the pointer-up/down messages
// on an accepted point step the value inside [0, count - 1]; four leave
// messages clear the editing flag. A step that cannot be made reports an edge
// to the control. Unhandled messages go to the control's handler, and every
// path except message 64 ends in the base handler.
//
// Every handled path ends in its own 'return base(...)' and the unhandled
// path falls into the final one with no label before it: the first return
// cross-jumps into that fall-in tail through a new label, which is outside
// jump.c's jump_chain, so the five identical edge-report blocks (each ending
// a different return) are never cross-jumped with each other. A shared
// 'break' to one final return puts an old label there and merges them.
// 0x802aff9c returns nothing (r3 is left unset on its exits); declaring it
// void keeps the original r3-then-r4 argument copy order.
//
// The spinner inherits the control as its second base at +28 (vtable pointer
// after the control's 180 data bytes, -fvtable-thunks). The class views are
// partial: no vtable or member is defined here.

struct D17fEvent { unsigned short kind; };
struct D17fMessageId { unsigned hash; unsigned cached; };

struct D17fConfig {
    char pad_00[11];
    unsigned char flags;
    char pad_0c[116];
    char *name;
};

struct D17fControl {
    char pad_00[12];
    D17fConfig *config;
    char pad_10[84];
    int busy;
    char pad_68[8];
    int enabled;
    char pad_74[44];
    int mode;
    char pad_a4[16];
    virtual int slot_08();
    virtual void slot_0c();
    virtual void slot_10();
    virtual void slot_14();
    virtual void slot_18();
    virtual void slot_1c();
    virtual void slot_20();
    virtual void slot_24();
    virtual void slot_28();
    virtual void slot_2c();
    virtual int accepts(float x, float y);
};

struct D17fHandlerBase {
    char pad_00[28];
};

struct D17fSpinner : D17fHandlerBase, D17fControl {
    char pad_d4[76];
    unsigned value;
    int edit_started;
    int edit_changed;
    char pad_12c[8];
    unsigned count;
    int handle_event(D17fEvent *event);
    void announce(D17fConfig *config);
    void begin_edit(D17fConfig *config);
    void step_up();
    void step_down();
    void press_up(D17fConfig *config);
    void press_down(D17fConfig *config);
};

extern int d17f_input_locked_804abb48;
extern D17fMessageId d17f_id_edit_804b0c54;
extern D17fMessageId d17f_id_up_804b0c84;
extern D17fMessageId d17f_id_down_804b0c8c;
extern D17fMessageId d17f_id_point_down_804b0c74;
extern D17fMessageId d17f_id_point_up_804b0c64;
extern D17fMessageId d17f_id_leave_a_804b0c7c;
extern D17fMessageId d17f_id_leave_b_804b0c6c;
extern D17fMessageId d17f_id_leave_c_804b0c9c;
extern D17fMessageId d17f_id_leave_d_804b0c5c;
extern "C" int d17f_base_event_8015fb34(D17fSpinner *self, D17fEvent *event);
extern "C" void d17f_spinner_open_8028b4bc(D17fSpinner *self);
extern "C" void d17f_spinner_reset_8028b750(D17fSpinner *self);
extern "C" int d17f_control_ready_802b264c(D17fControl *control);
extern "C" void d17f_control_event_802aff9c(D17fControl *control, D17fEvent *event);
extern "C" int d17f_control_edge_802b22b0(D17fControl *control);
extern "C" int d17f_message_id_equals_8015f65c(unsigned kind, void *id);
extern "C" void d17f_event_point_80069a50(D17fEvent *event, float *x, float *y);
extern "C" void d17f_spinner_increment_8028c508(D17fSpinner *self, int steps, int wrap);
extern "C" void d17f_spinner_decrement_8028c5b4(D17fSpinner *self, int steps, int wrap);
extern "C" void d17f_spinner_set_editing_8028c6b0(D17fSpinner *self, int editing);
extern "C" void d17f_play_sound_802b1258(const char *name);

inline void D17fSpinner::announce(D17fConfig *config)
{
    if (*(unsigned short *)(config->name - 4) && ((this->config->flags ^ 4) & 4) && enabled)
        d17f_play_sound_802b1258(config->name);
}

inline void D17fSpinner::begin_edit(D17fConfig *config)
{
    if (!((this->config->flags ^ 4) & 4) || !enabled)
        d17f_control_edge_802b22b0(this);
    else {
        d17f_spinner_increment_8028c508(this, 1, 1);
        announce(config);
        edit_started = 1;
        edit_changed = 0;
        d17f_spinner_set_editing_8028c6b0(this, 1);
    }
}

inline void D17fSpinner::step_up()
{
    if (!enabled || value >= count - 1)
        d17f_control_edge_802b22b0(this);
    else
        d17f_spinner_increment_8028c508(this, 1, 0);
}

inline void D17fSpinner::step_down()
{
    if (!enabled || value == 0)
        d17f_control_edge_802b22b0(this);
    else
        d17f_spinner_decrement_8028c5b4(this, 1, 0);
}

inline void D17fSpinner::press_down(D17fConfig *config)
{
    if (value == 0 || !enabled)
        d17f_control_edge_802b22b0(this);
    else {
        d17f_spinner_decrement_8028c5b4(this, 1, 0);
        announce(config);
    }
}

inline void D17fSpinner::press_up(D17fConfig *config)
{
    if (value >= count - 1 || !enabled)
        d17f_control_edge_802b22b0(this);
    else {
        d17f_spinner_increment_8028c508(this, 1, 0);
        announce(config);
    }
}

int D17fSpinner::handle_event(D17fEvent *event)
{
    D17fConfig *config = this->config;
    switch (event->kind) {
    case 64:
        if (d17f_base_event_8015fb34(this, event) >= 0) {
            d17f_spinner_open_8028b4bc(this);
            return 0;
        } else
            return (int)0x80004005U;
    case 66:
        d17f_spinner_reset_8028b750(this);
        return d17f_base_event_8015fb34(this, event);
    default:
        if (!d17f_control_ready_802b264c(this))
            return d17f_base_event_8015fb34(this, event);
        if (d17f_input_locked_804abb48 == 0 && busy == 0) {
            if (d17f_message_id_equals_8015f65c(event->kind, &d17f_id_edit_804b0c54)) {
                begin_edit(config);
                return d17f_base_event_8015fb34(this, event);
            }
            else if (d17f_message_id_equals_8015f65c(event->kind, &d17f_id_up_804b0c84) && mode == 1) {
                step_up();
                return d17f_base_event_8015fb34(this, event);
            }
            else if (d17f_message_id_equals_8015f65c(event->kind, &d17f_id_down_804b0c8c) && mode == 1) {
                step_down();
                return d17f_base_event_8015fb34(this, event);
            }
            else if (d17f_message_id_equals_8015f65c(event->kind, &d17f_id_point_down_804b0c74) && mode == 1) {
                float x, y;
                d17f_event_point_80069a50(event, &x, &y);
                if (accepts(x, y)) {
                    press_down(config);
                    return d17f_base_event_8015fb34(this, event);
                }
            } else if (d17f_message_id_equals_8015f65c(event->kind, &d17f_id_point_up_804b0c64) && mode == 1) {
                float x, y;
                d17f_event_point_80069a50(event, &x, &y);
                if (accepts(x, y)) {
                    press_up(config);
                    return d17f_base_event_8015fb34(this, event);
                }
            } else if (d17f_message_id_equals_8015f65c(event->kind, &d17f_id_leave_a_804b0c7c)
                       || d17f_message_id_equals_8015f65c(event->kind, &d17f_id_leave_b_804b0c6c)
                       || d17f_message_id_equals_8015f65c(event->kind, &d17f_id_leave_c_804b0c9c)
                       || d17f_message_id_equals_8015f65c(event->kind, &d17f_id_leave_d_804b0c5c)) {
                d17f_spinner_set_editing_8028c6b0(this, 0);
                return d17f_base_event_8015fb34(this, event);
            }
        }
        d17f_control_event_802aff9c(this, event);
        return d17f_base_event_8015fb34(this, event);
    }
}
