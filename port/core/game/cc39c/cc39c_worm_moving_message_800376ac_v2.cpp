#include "w3d_ptr.h"
#line 1 "cc39c_worm_moving_message_800376ac_v2.cpp"
// cc39c: 0x800376ac (280 bytes), handle two cached message ids.
// Observed in the original DOL: the halfword id at +0 of the message is tested
// against the r13 caches 0x804ad040 and 0x804ad048 (0x8015f65c). For the first,
// the state behind the handle at +136 (identity 0x80341584, then 0x801797b4)
// is read, a temporary engine string is built from the message text (+8,
// 0x8010a8fc) and compared with the original "WormMoving" literal (0x80373dd0);
// when equal, the optional context query 0x8015abcc (called with the owner,
// which it does not read) returns zero and the state's word at +168 is set,
// 0x80035714 (returns 0) receives the r13 pointer 0x804aa8c8, the original
// "Default" literal (0x80373e44) and the float at 0x80373e60 (0.0f). For the
// second id, the integer property "Payload.Deleted.Id" (0x80373e4c) is read
// through 0x800fc230; when it equals the owner's word at +208 the float at +820
// of the 0x804aa8c8 object receives 0x80373e60.
// All names and views are inferred; unknown bytes are not recovered layout.
struct cc39c_MessageCache { unsigned int unknown00[2]; };
struct cc39c_Message { unsigned short id; unsigned short unknown02; unsigned int unknown04; Ptr32<const char> text; };
struct cc39c_Handle;
struct cc39c_MoveState { unsigned char unknown00[168]; int moving; };        // +168
struct cc39c_Sounds { unsigned char unknown00[820]; float level; };         // +820
struct cc39c_WormOwner {
    unsigned char unknown00[136];
    Ptr32<cc39c_Handle> handle;                // +136
    unsigned char unknown8c[68];
    int id;                              // +208
};
extern "C" {
int cc39c_message_is_8015f65c(int, Ptr32<cc39c_MessageCache>);
Ptr32<cc39c_Handle> cc39c_handle_cast_80341584(Ptr32<cc39c_Handle>);
Ptr32<cc39c_MoveState> cc39c_move_state_801797b4(Ptr32<cc39c_Handle>);
Ptr32<const char> cc39c_message_text_8010a8fc(Ptr32<cc39c_Message>);
Ptr32<void> cc39c_string_from_text_8020bb54(Ptr32<void>, Ptr32<const char>);
void cc39c_string_base_finish_8020c5c4(Ptr32<void>);
void cc39c_string_release_80341588(Ptr32<void>);
int cc39c_strcmp_802ef234(Ptr32<const char>, Ptr32<const char>);
int cc39c_context_query_8015abcc(Ptr32<cc39c_WormOwner>);
int cc39c_play_named_80035714(Ptr32<cc39c_Sounds>, Ptr32<const char>, float);
int cc39c_read_int_property_800fc230(Ptr32<Ptr32<const char>>, Ptr32<int>);
extern cc39c_MessageCache cc39c_message_804ad040, cc39c_message_804ad048;
extern Ptr32<cc39c_Sounds> cc39c_sounds_804aa8c8;
extern const char cc39c_worm_moving_80373dd0[], cc39c_default_80373e44[], cc39c_deleted_id_80373e4c[];
extern const float cc39c_zero_80373e60[];
}
struct cc39c_String {
 cc39c_String(const cc39c_String &);
    Ptr32<const char> text;
    template <class W3dU> cc39c_String(Ptr32<W3dU> w3d_p) : cc39c_String((const char *)w3d_p.get()) {}
 cc39c_String(const char *s) { cc39c_string_from_text_8020bb54(this, s); }
    ~cc39c_String() { cc39c_string_base_finish_8020c5c4(this); cc39c_string_release_80341588(this); }
    int compare(Ptr32<const char> other) const { return cc39c_strcmp_802ef234(text, other); }
};
// The text check is an inline helper (string temporary scoped to it), as in the
// admitted cc17d name reset.
static inline void cc39c_check_worm_moving(Ptr32<cc39c_WormOwner> self, Ptr32<cc39c_MoveState> state, Ptr32<cc39c_Message> message) {
    cc39c_String text(cc39c_message_text_8010a8fc(message));
    if (text.compare(cc39c_worm_moving_80373dd0) == 0
        && !cc39c_context_query_8015abcc(self) && state->moving)
        cc39c_play_named_80035714(cc39c_sounds_804aa8c8, cc39c_default_80373e44, cc39c_zero_80373e60[0]);
}
extern "C" void cc39c_worm_moving_message_800376ac(Ptr32<cc39c_WormOwner> self, Ptr32<cc39c_Message> message) {
    int id = message->id;
    if (cc39c_message_is_8015f65c(id, &cc39c_message_804ad040)) {
        Ptr32<cc39c_MoveState> state = cc39c_move_state_801797b4(cc39c_handle_cast_80341584(self->handle));
        cc39c_check_worm_moving(self, state, message);
    } else if (cc39c_message_is_8015f65c(id, &cc39c_message_804ad048)) {
        Ptr32<const char> key = cc39c_deleted_id_80373e4c;
        int value;
        cc39c_read_int_property_800fc230(&key, &value);
        if (value == self->id)
            cc39c_sounds_804aa8c8->level = cc39c_zero_80373e60[0];
    }
}


