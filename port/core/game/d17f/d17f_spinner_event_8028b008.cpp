#include "w3d_ptr.h"
#line 1 "d17f_spinner_event_8028b008.cpp"
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
    char pad_00[8];
    unsigned char flags; char w3d_tag_rest[3];
    char pad_0c[116];
    Ptr32<char> name;
};

struct D17fControl {
    char pad_00[12];
    Ptr32<D17fConfig> config;
    char pad_10[84];
    int busy;
    char pad_68[8];
    int enabled;
    char pad_74[44];
    int mode;
    char pad_a4[16];
    int w3d_r_slot_08() __asm__(W3D_SYM("_ZN11D17fControl7slot_08Ev"));
    void w3d_r_slot_0c() __asm__(W3D_SYM("_ZN11D17fControl7slot_0cEv"));
    void w3d_r_slot_10() __asm__(W3D_SYM("_ZN11D17fControl7slot_10Ev"));
    void w3d_r_slot_14() __asm__(W3D_SYM("_ZN11D17fControl7slot_14Ev"));
    void w3d_r_slot_18() __asm__(W3D_SYM("_ZN11D17fControl7slot_18Ev"));
    void w3d_r_slot_1c() __asm__(W3D_SYM("_ZN11D17fControl7slot_1cEv"));
    void w3d_r_slot_20() __asm__(W3D_SYM("_ZN11D17fControl7slot_20Ev"));
    void w3d_r_slot_24() __asm__(W3D_SYM("_ZN11D17fControl7slot_24Ev"));
    void w3d_r_slot_28() __asm__(W3D_SYM("_ZN11D17fControl7slot_28Ev"));
    void w3d_r_slot_2c() __asm__(W3D_SYM("_ZN11D17fControl7slot_2cEv"));
    int w3d_r_accepts(float x, float y) __asm__(W3D_SYM("_ZN11D17fControl7acceptsEff"));
 __attribute__((always_inline)) inline int slot_08() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D17fControl, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_0c() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D17fControl, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_10() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D17fControl, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_14() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D17fControl, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_18() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D17fControl, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_1c() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D17fControl, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_20() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D17fControl, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_24() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D17fControl, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_28() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D17fControl, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_2c() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D17fControl, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int accepts(float w3d_a0, float w3d_a1) { return ((int (*)(w3d_u32, float, float))w3d::vfn(this->w3d_vptr_D17fControl, 12))(w3d::h2g(this), w3d_a0, w3d_a1); }  Ptr32<void> w3d_vptr_D17fControl; };

struct D17fHandlerBase {
    char pad_00[28];
};

struct D17fSpinner : D17fHandlerBase, D17fControl {
    char pad_d4[76] __attribute__((aligned(__alignof__(D17fHandlerBase)), aligned(__alignof__(D17fControl))));
    unsigned value;
    int edit_started;
    int edit_changed;
    char pad_12c[8];
    unsigned count;
    int handle_event(Ptr32<D17fEvent> event);
    void announce(Ptr32<D17fConfig> config);
    void begin_edit(Ptr32<D17fConfig> config);
    void step_up();
    void step_down();
    void press_up(Ptr32<D17fConfig> config);
    void press_down(Ptr32<D17fConfig> config);
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
extern "C" int d17f_base_event_8015fb34(Ptr32<D17fSpinner> self, Ptr32<D17fEvent> event);
extern "C" void d17f_spinner_open_8028b4bc(Ptr32<D17fSpinner> self);
extern "C" void d17f_spinner_reset_8028b750(Ptr32<D17fSpinner> self);
extern "C" int d17f_control_ready_802b264c(Ptr32<D17fControl> control);
extern "C" void d17f_control_event_802aff9c(Ptr32<D17fControl> control, Ptr32<D17fEvent> event);
extern "C" int d17f_control_edge_802b22b0(Ptr32<D17fControl> control);
extern "C" int d17f_message_id_equals_8015f65c(unsigned kind, Ptr32<void> id);
extern "C" void d17f_event_point_80069a50(Ptr32<D17fEvent> event, Ptr32<float> x, Ptr32<float> y);
extern "C" void d17f_spinner_increment_8028c508(Ptr32<D17fSpinner> self, int steps, int wrap);
extern "C" void d17f_spinner_decrement_8028c5b4(Ptr32<D17fSpinner> self, int steps, int wrap);
extern "C" void d17f_spinner_set_editing_8028c6b0(Ptr32<D17fSpinner> self, int editing);
extern "C" void d17f_play_sound_802b1258(Ptr32<const char> name);

inline void D17fSpinner::announce(Ptr32<D17fConfig> config)
{
    if (*(Ptr32<unsigned short>)(config->name - 4) && ((this->config->flags ^ 4) & 4) && enabled)
        d17f_play_sound_802b1258(config->name);
}

inline void D17fSpinner::begin_edit(Ptr32<D17fConfig> config)
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

inline void D17fSpinner::press_down(Ptr32<D17fConfig> config)
{
    if (value == 0 || !enabled)
        d17f_control_edge_802b22b0(this);
    else {
        d17f_spinner_decrement_8028c5b4(this, 1, 0);
        announce(config);
    }
}

inline void D17fSpinner::press_up(Ptr32<D17fConfig> config)
{
    if (value >= count - 1 || !enabled)
        d17f_control_edge_802b22b0(this);
    else {
        d17f_spinner_increment_8028c508(this, 1, 0);
        announce(config);
    }
}

int D17fSpinner::handle_event(Ptr32<D17fEvent> event)
{
    Ptr32<D17fConfig> config = this->config;
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


