#include "w3d_ptr.h"
#line 1 "d18f_list_panel_event_802b5a9c.cpp"
// List panel message handler (original 0x802b5a9c). Built with -mps-float: the
// paired-single FP mode explains the original 8-byte larger frame.

struct D18fEvent { unsigned short kind; };
struct D18fMessageId { unsigned hash; unsigned cached; };
struct D18fOwner { char pad_00[172]; int locked; };
struct D18fList;

struct D18fControl {
    char pad_00[12];
    Ptr32<D18fOwner> owner;
    char pad_10[84];
    int busy;
    char pad_68[8];
    int scrollable;
    char pad_74[32];
    int focused;
    char pad_98[8];
    int pointer_mode;
    char pad_a4[16];
    void w3d_r_slot_08() __asm__(W3D_SYM("_ZN11D18fControl7slot_08Ev"));
    void w3d_r_slot_0c() __asm__(W3D_SYM("_ZN11D18fControl7slot_0cEv"));
    void w3d_r_slot_10() __asm__(W3D_SYM("_ZN11D18fControl7slot_10Ev"));
    void w3d_r_slot_14() __asm__(W3D_SYM("_ZN11D18fControl7slot_14Ev"));
    void w3d_r_slot_18() __asm__(W3D_SYM("_ZN11D18fControl7slot_18Ev"));
    void w3d_r_slot_1c() __asm__(W3D_SYM("_ZN11D18fControl7slot_1cEv"));
    void w3d_r_slot_20() __asm__(W3D_SYM("_ZN11D18fControl7slot_20Ev"));
    void w3d_r_slot_24() __asm__(W3D_SYM("_ZN11D18fControl7slot_24Ev"));
    void w3d_r_slot_28() __asm__(W3D_SYM("_ZN11D18fControl7slot_28Ev"));
    void w3d_r_slot_2c() __asm__(W3D_SYM("_ZN11D18fControl7slot_2cEv"));
    void w3d_r_slot_30() __asm__(W3D_SYM("_ZN11D18fControl7slot_30Ev"));
    void w3d_r_release(int keep) __asm__(W3D_SYM("_ZN11D18fControl7releaseEi"));
 __attribute__((always_inline)) inline void slot_08() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D18fControl, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_0c() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D18fControl, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_10() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D18fControl, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_14() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D18fControl, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_18() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D18fControl, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_1c() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D18fControl, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_20() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D18fControl, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_24() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D18fControl, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_28() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D18fControl, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_2c() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D18fControl, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_30() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D18fControl, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release(int w3d_a0) { ((void (*)(w3d_u32, int))w3d::vfn(this->w3d_vptr_D18fControl, 13))(w3d::h2g(this), w3d_a0); }  Ptr32<void> w3d_vptr_D18fControl; };

struct D18fHandlerBase {
    char pad_00[28];
};

struct D18fListPanel : D18fHandlerBase, D18fControl {
    char pad_d4[48] __attribute__((aligned(__alignof__(D18fHandlerBase)), aligned(__alignof__(D18fControl))));
    int scroll_from;
    int scroll_to;
    char pad_10c[16];
    Ptr32<D18fList> list;
    char pad_120[4];
    int state;
    int selected;
    int picked;
    int handle_event(Ptr32<D18fEvent> event);
};

extern int d18f_input_locked_804abb48;
extern D18fMessageId d18f_id_reset0_804b1058;
extern D18fMessageId d18f_id_reset1_804b1060;
extern D18fMessageId d18f_id_point_804b1018;
extern D18fMessageId d18f_id_drag_804b1050;
extern D18fMessageId d18f_id_up_804b1020;
extern D18fMessageId d18f_id_down_804b1028;
extern D18fMessageId d18f_id_accept_804b1030;
extern D18fMessageId d18f_id_back_804b1038;
extern D18fMessageId d18f_id_left_804b1040;
extern D18fMessageId d18f_id_right_804b1048;
extern "C" int d18f_base_event_8015fb34(Ptr32<D18fListPanel> self, Ptr32<D18fEvent> event);
extern "C" void d18f_panel_open_802b6248(Ptr32<D18fListPanel> self);
extern "C" void d18f_panel_close_802b66c4(Ptr32<D18fListPanel> self);
extern "C" void d18f_panel_reset_802ba0cc(Ptr32<D18fListPanel> self);
extern "C" int d18f_control_ready_802b264c(Ptr32<D18fControl> control);
extern "C" void d18f_control_event_802aff9c(Ptr32<D18fControl> control, Ptr32<D18fEvent> event);
extern "C" int d18f_message_id_equals_8015f65c(unsigned kind, Ptr32<void> id);
extern "C" void d18f_event_point_80069a50(Ptr32<D18fEvent> event, Ptr32<float> x, Ptr32<float> y);
extern "C" int d18f_panel_hit_802b8260(Ptr32<D18fListPanel> self, float x, float y, Ptr32<int> column, Ptr32<int> row);
extern "C" void d18f_panel_show_802b83ac(Ptr32<D18fListPanel> self, int row, int immediate);
extern "C" void d18f_list_select_802bc8b4(Ptr32<D18fList> list, int row);
extern "C" int d18f_panel_hit_item_802b9bac(Ptr32<D18fListPanel> self, float x, float y);
extern "C" int d18f_panel_hit_frame_802b9cf4(Ptr32<D18fListPanel> self, float x, float y);
extern "C" void d18f_panel_confirm_802b98dc(Ptr32<D18fListPanel> self);
extern "C" void d18f_panel_finish_802b88b0(Ptr32<D18fListPanel> self, int accepted);
extern "C" unsigned d18f_list_count_802bc71c(Ptr32<D18fList> list);

int D18fListPanel::handle_event(Ptr32<D18fEvent> event)
{
    switch (event->kind) {
    case 64:
        if (d18f_base_event_8015fb34(this, event) >= 0) {
            d18f_panel_open_802b6248(this);
            return 0;
        } else
            return (int)0x80004005U;
    case 66:
        d18f_panel_close_802b66c4(this);
        return d18f_base_event_8015fb34(this, event);
    default:
        if (d18f_message_id_equals_8015f65c(event->kind, &d18f_id_reset0_804b1058))
            d18f_panel_reset_802ba0cc(this);
        if (d18f_message_id_equals_8015f65c(event->kind, &d18f_id_reset1_804b1060))
            d18f_panel_reset_802ba0cc(this);
        if (!d18f_control_ready_802b264c(this))
            return d18f_base_event_8015fb34(this, event);
        if (d18f_input_locked_804abb48 == 0 && busy == 0) {
            Ptr32<D18fOwner> o = owner;
            if (d18f_message_id_equals_8015f65c(event->kind, &d18f_id_point_804b1018)) {
                if (state == 1 && pointer_mode == 1) {
                    float x, y;
                    int column, row;
                    d18f_event_point_80069a50(event, &x, &y);
                    if (d18f_panel_hit_802b8260(this, x, y, &column, &row) == 1 && column != -1) {
                        d18f_panel_show_802b83ac(this, row, 1);
                        d18f_list_select_802bc8b4(list, row);
                        selected = row;
                        picked = column;
                        return 0;
                    }
                }
            } else if (d18f_message_id_equals_8015f65c(event->kind, &d18f_id_drag_804b1050)) {
                if (state == 1 && pointer_mode == 1) {
                    float x, y;
                    d18f_event_point_80069a50(event, &x, &y);
                    if (d18f_panel_hit_item_802b9bac(this, x, y) == 1) {
                        if (selected != -1) {
                            d18f_panel_confirm_802b98dc(this);
                            d18f_panel_finish_802b88b0(this, 1);
                            if (o->locked == 0)
                                release(0);
                        }
                    } else if (d18f_panel_hit_frame_802b9cf4(this, x, y) == 1)
                        release(0);
                    return 0;
                }
            } else if (d18f_message_id_equals_8015f65c(event->kind, &d18f_id_up_804b1020)
                       && state == 1 && focused == 1 && pointer_mode == 1) {
                if (list) {
                    if (--selected < 0)
                        selected = 0;
                    scroll_to = 0;
                    scroll_from = 2000;
                    d18f_panel_show_802b83ac(this, selected, 0);
                    d18f_list_select_802bc8b4(list, selected);
                    picked = -1;
                }
                return d18f_base_event_8015fb34(this, event);
            } else if (d18f_message_id_equals_8015f65c(event->kind, &d18f_id_down_804b1028)
                       && state == 1 && focused == 1 && pointer_mode == 1) {
                if (list) {
                    selected++;
                    if ((float)selected >= (float)d18f_list_count_802bc71c(list))
                        selected = d18f_list_count_802bc71c(list) - 1;
                    if (selected < 0)
                        selected = 0;
                    scroll_to = 2000;
                    scroll_from = 0;
                    d18f_panel_show_802b83ac(this, selected, 0);
                    d18f_list_select_802bc8b4(list, selected);
                    picked = -1;
                }
                return d18f_base_event_8015fb34(this, event);
            } else if (d18f_message_id_equals_8015f65c(event->kind, &d18f_id_accept_804b1030)
                       && state == 1 && focused == 1) {
                if (scrollable) {
                    if (pointer_mode == 1) {
                        if (selected != -1) {
                            d18f_panel_confirm_802b98dc(this);
                            d18f_panel_finish_802b88b0(this, 1);
                        }
                        if (o->locked == 0)
                            release(0);
                    } else
                        release(1);
                }
                return 0;
            } else if (d18f_message_id_equals_8015f65c(event->kind, &d18f_id_back_804b1038)
                       && state == 1 && focused == 1 && pointer_mode == 1) {
                release(0);
                return d18f_base_event_8015fb34(this, event);
            } else if (d18f_message_id_equals_8015f65c(event->kind, &d18f_id_left_804b1040)
                       && pointer_mode == 1)
                return d18f_base_event_8015fb34(this, event);
            else if (d18f_message_id_equals_8015f65c(event->kind, &d18f_id_right_804b1048)
                     && pointer_mode == 1)
                return d18f_base_event_8015fb34(this, event);
        }
        d18f_control_event_802aff9c(this, event);
        return d18f_base_event_8015fb34(this, event);
    }
}


