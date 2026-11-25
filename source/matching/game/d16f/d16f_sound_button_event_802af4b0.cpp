// Sound button control message handler (original 0x802af4b0).
// GC32 reconstruction from the original instructions; class and field names
// are inferred. Message 64 runs the base handler and starts the button
// (E_FAIL 0x80004005 when the base handler fails); message 66 stops it.
// Otherwise, when the embedded control is ready, the button is active, input
// is not locked and the control is idle, ten interface messages play one of
// the configuration's sound names (72, 76, 80, 84, 116, 120) when the name is
// not empty, the configuration is not read-only (flag 4) and the control is
// enabled; two press/release pairs track a pressed and a held state and
// play the matching sound on release. Other messages are forwarded to the
// control; every path except message 64 and the handled messages ends in the
// base handler.
//
// The control is the second base at +28 (vptr after its 180 data bytes),
// hence -fvtable-thunks. The class views are partial: no vtable or member is
// defined here.

struct D16fEvent { unsigned short kind; };
struct D16fMessageId { unsigned hash; unsigned cached; };

struct D16fConfig {
    char pad_00[11];
    unsigned char flags;
    char pad_0c[60];
    char *sound_72;
    char *sound_76;
    char *sound_80;
    char *sound_84;
    char pad_58[28];
    char *sound_116;
    char *sound_120;
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

struct D16fSoundButton : D16fHandlerBase, D16fControl {
    int active;
    int held;
    int pressed;
    int handle_event(D16fEvent *event);
    void play(const char *sound);
};

extern int d16f_input_locked_804abb48;
extern D16fMessageId d16f_id_804b0f6c;
extern D16fMessageId d16f_id_804b0f2c;
extern D16fMessageId d16f_id_804b0f34;
extern D16fMessageId d16f_id_804b0f74;
extern D16fMessageId d16f_id_804b0f3c;
extern D16fMessageId d16f_id_804b0f44;
extern D16fMessageId d16f_id_804b0f4c;
extern D16fMessageId d16f_id_804b0f54;
extern D16fMessageId d16f_id_804b0f5c;
extern D16fMessageId d16f_id_804b0f64;
extern "C" int d16f_base_event_8015fb34(D16fSoundButton *self, D16fEvent *event);
extern "C" void d16f_button_start_802af894(D16fSoundButton *self);
extern "C" void d16f_button_stop_802af924(D16fSoundButton *self);
extern "C" int d16f_control_ready_802b264c(D16fControl *control);
extern "C" int d16f_control_event_802aff9c(D16fControl *control, D16fEvent *event);
extern "C" int d16f_message_id_equals_8015f65c(unsigned kind, void *id);
extern "C" void d16f_play_sound_802b1258(const char *name);

inline void D16fSoundButton::play(const char *sound)
{
    if (*(unsigned short *)(sound - 4) && ((config->flags ^ 4) & 4) && enabled)
        d16f_play_sound_802b1258(sound);
}

int D16fSoundButton::handle_event(D16fEvent *event)
{
    switch (event->kind) {
    case 64:
        if (d16f_base_event_8015fb34(this, event) >= 0) {
            d16f_button_start_802af894(this);
            return 0;
        } else
            return (int)0x80004005U;
    case 66:
        d16f_button_stop_802af924(this);
        break;
    default:
        if (d16f_control_ready_802b264c(this)) {
            if (active && d16f_input_locked_804abb48 == 0 && busy == 0) {
                if (d16f_message_id_equals_8015f65c(event->kind, &d16f_id_804b0f6c)) {
                    play(config->sound_120);
                    return 0;
                }
                if (d16f_message_id_equals_8015f65c(event->kind, &d16f_id_804b0f2c)) {
                    pressed = 1;
                    return 0;
                }
                if (d16f_message_id_equals_8015f65c(event->kind, &d16f_id_804b0f34)) {
                    if (pressed)
                        play(config->sound_120);
                    pressed = 0;
                    return 0;
                }
                if (d16f_message_id_equals_8015f65c(event->kind, &d16f_id_804b0f74)) {
                    play(config->sound_116);
                    return 0;
                }
                if (d16f_message_id_equals_8015f65c(event->kind, &d16f_id_804b0f3c)) {
                    held = 1;
                    return 0;
                }
                if (d16f_message_id_equals_8015f65c(event->kind, &d16f_id_804b0f44)) {
                    if (held)
                        play(config->sound_116);
                    held = 0;
                    return 0;
                }
                if (d16f_message_id_equals_8015f65c(event->kind, &d16f_id_804b0f4c)) {
                    play(config->sound_84);
                    return 0;
                }
                if (d16f_message_id_equals_8015f65c(event->kind, &d16f_id_804b0f54)) {
                    play(config->sound_80);
                    return 0;
                }
                if (d16f_message_id_equals_8015f65c(event->kind, &d16f_id_804b0f5c)) {
                    play(config->sound_76);
                    return 0;
                }
                if (d16f_message_id_equals_8015f65c(event->kind, &d16f_id_804b0f64)) {
                    play(config->sound_72);
                    return 0;
                }
            }
            d16f_control_event_802aff9c(this, event);
        }
        break;
    }
    return d16f_base_event_8015fb34(this, event);
}
