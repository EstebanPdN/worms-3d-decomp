#include "w3d_ptr.h"
#line 1 "d16f_choice_panel_event_802a83d0.cpp"
// Choice panel message handler (original 0x802a83d0).
// GC32 reconstruction from the original instructions; class and field names
// are inferred. Message 64 runs the base handler and opens the panel (E_FAIL
// 0x80004005 when the base handler fails); message 66 closes it. Other
// messages go to the embedded control when it is ready: while input is not
// locked, the control is idle and the panel state is 1, a pointer message
// picks a choice at the event position (directly, or after the control
// accepts the point, then activates the control and posts a "selected"
// string message with the owner's name); four choice messages select the
// current entry's choice 0-3 and a cancel message cancels the panel. Unhandled
// or successfully selected messages are forwarded to the control, and every
// path except message 64 ends in the base handler.
//
// The panel inherits the control as its second base at +28: the control's
// vtable pointer follows its 180 data bytes (g++ 2.95 places it after the
// fields), so the virtual calls load it from this+208 and pass this+28.
// 4-byte vtable entries after an 8-byte header, hence -fvtable-thunks. The
// class views are partial: no vtable or member is defined here.

struct D16fEvent { unsigned short kind; };
struct D16fMessage;
struct D16fMessageId { unsigned hash; unsigned cached; };
struct D16fOwner { char pad_00[88]; Ptr32<const char> name; };

struct D16fControl {
    char pad_00[12];
    Ptr32<D16fOwner> owner;
    char pad_10[84];
    int busy;
    char pad_68[44];
    int direct;
    char pad_98[28];
    int w3d_r_slot_08() __asm__(W3D_SYM("_ZN11D16fControl7slot_08Ev"));
    void w3d_r_slot_0c() __asm__(W3D_SYM("_ZN11D16fControl7slot_0cEv"));
    void w3d_r_slot_10() __asm__(W3D_SYM("_ZN11D16fControl7slot_10Ev"));
    void w3d_r_set_active(int active) __asm__(W3D_SYM("_ZN11D16fControl10set_activeEi"));
    void w3d_r_slot_18() __asm__(W3D_SYM("_ZN11D16fControl7slot_18Ev"));
    void w3d_r_slot_1c() __asm__(W3D_SYM("_ZN11D16fControl7slot_1cEv"));
    void w3d_r_slot_20() __asm__(W3D_SYM("_ZN11D16fControl7slot_20Ev"));
    void w3d_r_slot_24() __asm__(W3D_SYM("_ZN11D16fControl7slot_24Ev"));
    void w3d_r_slot_28() __asm__(W3D_SYM("_ZN11D16fControl7slot_28Ev"));
    void w3d_r_slot_2c() __asm__(W3D_SYM("_ZN11D16fControl7slot_2cEv"));
    int w3d_r_accepts(float x, float y) __asm__(W3D_SYM("_ZN11D16fControl7acceptsEff"));
 __attribute__((always_inline)) inline int slot_08() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D16fControl, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_0c() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D16fControl, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_10() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D16fControl, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void set_active(int w3d_a0) { ((void (*)(w3d_u32, int))w3d::vfn(this->w3d_vptr_D16fControl, 5))(w3d::h2g(this), w3d_a0); }  __attribute__((always_inline)) inline void slot_18() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D16fControl, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_1c() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D16fControl, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_20() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D16fControl, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_24() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D16fControl, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_28() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D16fControl, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_2c() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D16fControl, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int accepts(float w3d_a0, float w3d_a1) { return ((int (*)(w3d_u32, float, float))w3d::vfn(this->w3d_vptr_D16fControl, 12))(w3d::h2g(this), w3d_a0, w3d_a1); }  Ptr32<void> w3d_vptr_D16fControl; };

struct D16fEntry { int choice[4]; char pad_10[56]; };

// Message-handler base state (28 bytes); its handler is the original 0x8015fb34.
struct D16fHandlerBase {
    char pad_00[28];
};

struct D16fChoicePanel : D16fHandlerBase, D16fControl {
    char pad_d4[28] __attribute__((aligned(__alignof__(D16fHandlerBase)), aligned(__alignof__(D16fControl))));
    int state;
    char pad_f4[44];
    D16fEntry entries[10];
    char pad_3f0[64];
    int entry_index;
    int handle_event(Ptr32<D16fEvent> event);
};

extern int d16f_input_locked_804abb48;
extern Ptr32<void> d16f_message_queue_804b1754;
extern D16fMessageId d16f_id_point_804b0f1c;
extern D16fMessageId d16f_id_choice0_804b0eec;
extern D16fMessageId d16f_id_choice1_804b0ef4;
extern D16fMessageId d16f_id_choice2_804b0f0c;
extern D16fMessageId d16f_id_choice3_804b0f14;
extern D16fMessageId d16f_id_cancel_804b0efc;
extern D16fMessageId d16f_id_selected_804b0f24;
extern "C" int d16f_base_event_8015fb34(Ptr32<D16fChoicePanel> self, Ptr32<D16fEvent> event);
extern "C" void d16f_panel_open_802a90b8(Ptr32<D16fChoicePanel> self);
extern "C" void d16f_panel_close_802a9f54(Ptr32<D16fChoicePanel> self);
extern "C" int d16f_control_ready_802b264c(Ptr32<D16fControl> control);
extern "C" int d16f_control_event_802aff9c(Ptr32<D16fControl> control, Ptr32<D16fEvent> event);
extern "C" int d16f_message_id_equals_8015f65c(unsigned kind, Ptr32<void> id);
extern "C" void d16f_event_point_80069a50(Ptr32<D16fEvent> event, Ptr32<float> x, Ptr32<float> y);
extern "C" int d16f_panel_pick_802ab5c0(Ptr32<D16fChoicePanel> self, float x, float y);
extern "C" int d16f_panel_select_802aa8a4(Ptr32<D16fChoicePanel> self, int choice);
extern "C" void d16f_panel_cancel_802aaa8c(Ptr32<D16fChoicePanel> self);
extern "C" Ptr32<void> d16f_arena_alloc_801613f0(Ptr32<void> arena, unsigned size);
extern "C" unsigned d16f_cached_message_id_8015f5a0(Ptr32<void> id, int create);
extern "C" Ptr32<D16fMessage> d16f_message_string_init_8010a8e0(Ptr32<void> message, unsigned short id, Ptr32<const char> text);
extern "C" int d16f_message_post_8016239c(Ptr32<D16fMessage> message);

int D16fChoicePanel::handle_event(Ptr32<D16fEvent> event)
{
    switch (event->kind) {
    case 64:
        if (d16f_base_event_8015fb34(this, event) >= 0) {
            d16f_panel_open_802a90b8(this);
            return 0;
        } else
            return (int)0x80004005U;
    case 66:
        d16f_panel_close_802a9f54(this);
        return d16f_base_event_8015fb34(this, event);
    default: {
        if (d16f_control_ready_802b264c(this)) {
            if (d16f_input_locked_804abb48 == 0 && busy == 0 && state == 1) {
                int forward = 1;
                if (d16f_message_id_equals_8015f65c(event->kind, &d16f_id_point_804b0f1c)) {
                    float x, y;
                    d16f_event_point_80069a50(event, &x, &y);
                    if (direct) {
                        int choice = d16f_panel_pick_802ab5c0(this, x, y);
                        if (choice)
                            d16f_panel_select_802aa8a4(this, choice);
                    } else if (accepts(x, y)) {
                        d16f_panel_select_802aa8a4(this, d16f_panel_pick_802ab5c0(this, x, y));
                        set_active(1);
                        Ptr32<void> memory = d16f_arena_alloc_801613f0(d16f_message_queue_804b1754, 12);
                        d16f_message_post_8016239c(d16f_message_string_init_8010a8e0(memory,
                            d16f_cached_message_id_8015f5a0(&d16f_id_selected_804b0f24, 1), owner->name));
                    }
                    return 0;
                }
                if (d16f_message_id_equals_8015f65c(event->kind, &d16f_id_choice0_804b0eec))
                    forward = d16f_panel_select_802aa8a4(this, entries[entry_index].choice[0]);
                else if (d16f_message_id_equals_8015f65c(event->kind, &d16f_id_choice1_804b0ef4))
                    forward = d16f_panel_select_802aa8a4(this, entries[entry_index].choice[1]);
                else if (d16f_message_id_equals_8015f65c(event->kind, &d16f_id_choice2_804b0f0c))
                    forward = d16f_panel_select_802aa8a4(this, entries[entry_index].choice[2]);
                else if (d16f_message_id_equals_8015f65c(event->kind, &d16f_id_choice3_804b0f14))
                    forward = d16f_panel_select_802aa8a4(this, entries[entry_index].choice[3]);
                else if (d16f_message_id_equals_8015f65c(event->kind, &d16f_id_cancel_804b0efc)) {
                    d16f_panel_cancel_802aaa8c(this);
                    return d16f_base_event_8015fb34(this, event);
                }
                if (forward)
                    d16f_control_event_802aff9c(this, event);
            } else
                d16f_control_event_802aff9c(this, event);
        }
        return d16f_base_event_8015fb34(this, event);
    }
    }
}



