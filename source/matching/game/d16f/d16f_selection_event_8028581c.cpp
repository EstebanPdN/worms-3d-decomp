// Value selection control message handler (original 0x8028581c).
// GC32 reconstruction from the original instructions; class and field names
// are inferred (the layout agrees with the admitted s4_selection unit:
// configuration at +40, enabled at +140, updating flag at +220, bound
// property at +256). Message 64 runs the base handler and opens the control
// (E_FAIL 0x80004005 when the base handler fails); message 66 resets it.
// Otherwise, when the embedded control is ready, input is not locked and the
// control is idle, two "next" and two "previous" messages step the selection
// by one: a read-only configuration (flag 4) or a disabled control reports an
// edge; otherwise the navigated value is written to the bound property
// (property kinds 0 and 1), highlighted, and the configuration's name is
// announced when it is not empty and the control is still editable. Other
// messages are forwarded to the control; all paths except 64 and the steps
// end in the base handler.
//
// The control is the second base at +28 (vptr after its 180 data bytes);
// the property interface uses 4-byte vtable entries after an 8-byte header
// (kind at 24), hence -fvtable-thunks. The class views are partial: no vtable
// or member is defined here.

struct D16fEvent { unsigned short kind; };
struct D16fMessageId { unsigned hash; unsigned cached; };

struct D16fConfig {
    char pad_00[11];
    unsigned char flags;
    char pad_0c[108];
    char *name;
};

struct D16fProperty {
    virtual int query_interface();
    virtual void retain();
    virtual void release();
    virtual void slot_14();
    virtual int kind();
};

struct D16fControl {
    char pad_00[12];
    D16fConfig *config;
    char pad_10[84];
    int busy;
    char pad_68[8];
    int enabled;
    char pad_74[64];
    virtual int slot_08();
};

struct D16fHandlerBase {
    char pad_00[28];
};

struct D16fValueSelection : D16fHandlerBase, D16fControl {
    char pad_d4[8];
    int updating;
    char pad_e0[32];
    D16fProperty *current;
    int handle_event(D16fEvent *event);
    void step(int direction);
};

extern int d16f_input_locked_804abb48;
extern D16fMessageId d16f_id_next_a_804b0b9c;
extern D16fMessageId d16f_id_next_b_804b0bac;
extern D16fMessageId d16f_id_previous_a_804b0ba4;
extern D16fMessageId d16f_id_previous_b_804b0bb4;
extern "C" int d16f_base_event_8015fb34(D16fValueSelection *self, D16fEvent *event);
extern "C" void d16f_selection_open_80285b28(D16fValueSelection *self);
extern "C" void d16f_selection_reset_80285c9c(D16fValueSelection *self);
extern "C" int d16f_control_ready_802b264c(D16fControl *control);
extern "C" int d16f_control_event_802aff9c(D16fControl *control, D16fEvent *event);
extern "C" int d16f_control_edge_802b22b0(D16fControl *control);
extern "C" int d16f_message_id_equals_8015f65c(unsigned kind, void *id);
extern "C" int d16f_selection_navigate_80286da4(D16fValueSelection *self, int direction);
extern "C" void d16f_selection_highlight_80286b40(D16fValueSelection *self, int value);
extern "C" void d16f_selection_announce_802b1258(const char *name);
extern "C" D16fProperty *d16f_view_kind0_803426b4(D16fProperty *property);
extern "C" int d16f_update_kind0_80178c54(D16fProperty *property, const int *value);
extern "C" D16fProperty *d16f_view_kind1_80342a78(D16fProperty *property);
extern "C" int d16f_update_kind1_80178d28(D16fProperty *property, const int *value);

inline void D16fValueSelection::step(int direction)
{
    D16fConfig *config = this->config;
    if (!((config->flags ^ 4) & 4) || !enabled) {
        d16f_control_edge_802b22b0(this);
        return;
    }
    int value = d16f_selection_navigate_80286da4(this, direction);
    updating = 1;
    if (current) {
        switch (current->kind()) {
        case 0:
            d16f_update_kind0_80178c54(d16f_view_kind0_803426b4(current), &value);
            break;
        case 1:
            d16f_update_kind1_80178d28(d16f_view_kind1_80342a78(current), &value);
            break;
        }
    }
    d16f_selection_highlight_80286b40(this, value);
    updating = 0;
    if (*(unsigned short *)(config->name - 4) && ((this->config->flags ^ 4) & 4) && enabled)
        d16f_selection_announce_802b1258(config->name);
}

int D16fValueSelection::handle_event(D16fEvent *event)
{
    switch (event->kind) {
    case 64:
        if (d16f_base_event_8015fb34(this, event) >= 0) {
            d16f_selection_open_80285b28(this);
            return 0;
        } else
            return (int)0x80004005U;
    case 66:
        d16f_selection_reset_80285c9c(this);
        return d16f_base_event_8015fb34(this, event);
    default:
        if (d16f_control_ready_802b264c(this)) {
            if (d16f_input_locked_804abb48 == 0 && busy == 0) {
                if (d16f_message_id_equals_8015f65c(event->kind, &d16f_id_next_a_804b0b9c)
                    || d16f_message_id_equals_8015f65c(event->kind, &d16f_id_next_b_804b0bac)) {
                    step(1);
                    return 0;
                }
                if (d16f_message_id_equals_8015f65c(event->kind, &d16f_id_previous_a_804b0ba4)
                    || d16f_message_id_equals_8015f65c(event->kind, &d16f_id_previous_b_804b0bb4)) {
                    step(0);
                    return 0;
                }
            }
            d16f_control_event_802aff9c(this, event);
        }
        return d16f_base_event_8015fb34(this, event);
    }
}
