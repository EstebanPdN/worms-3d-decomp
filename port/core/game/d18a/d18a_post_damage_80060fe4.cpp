#include "w3d_ptr.h"
#line 1 "d18a_post_damage_80060fe4.cpp"
/* Post a damage message at a position and update the owner's absolute speed
 * (0x80060fe4); based on cc39c's v6 draft, whose only remaining difference
 * was the 8-byte frame gap. The body state behind the handle at +192
 * (identity 0x80341584, then 0x801797b4) is read; a 52-byte message
 * allocated from the r13 queue 0x804b1754 (0x801613f0) is constructed by
 * 0x800666b4 (returns the message) with the position twice, 0.0f as the
 * first three and fifth floats and the state's float at +220 as the fourth,
 * and posted (0x8016239c). A copy of the position, lowered by that float,
 * goes to 0x800eca14 and to 0x800e5ca4 (with the state's word at +348, zero
 * and 0.0f). The owner's float at +52 then becomes the larger of its
 * absolute value (sign bit cleared through an integer copy) times the handle
 * float behind +312 and the handle float behind +308 (0x80178df0), selected
 * through references as by an inlined max; finally 0x800eb6e4 runs.
 * Arguments r4..r6 are not read. Names and views are inferred; unknown bytes
 * are not recovered layout. Built with -mps-float (frame keeps 8 bytes below
 * the save area for the saved FPR). */
struct d18a_Vec3 { float x, y, z; };
struct d18a_Handle;
struct d18a_Queue;
struct d18a_DamageMessage;                                   // 52 bytes requested
struct d18a_BodyState {
    unsigned char unknown00[220];
    float height_;                       // +220
    unsigned char unknown_e0[124];
    unsigned int material;               // +348
    float height() const { return height_; }
};
struct d18a_Damageable {
    unsigned char unknown00[52];
    float speed;                         // +52
    unsigned char unknown38[136];
    Ptr32<d18a_Handle> body;                  // +192
    unsigned char unknown_c4[112];
    Ptr32<d18a_Handle> limit;                 // +308
    Ptr32<d18a_Handle> scale;                 // +312
};
extern "C" {
Ptr32<d18a_Handle> d18a_handle_cast_80341584(Ptr32<d18a_Handle>);
Ptr32<d18a_BodyState> d18a_body_state_801797b4(Ptr32<d18a_Handle>);
Ptr32<void> d18a_message_alloc_801613f0(Ptr32<d18a_Queue>, unsigned int);
Ptr32<d18a_DamageMessage> d18a_damage_message_800666b4(Ptr32<d18a_DamageMessage>, Ptr32<const d18a_Vec3>, Ptr32<const d18a_Vec3>,
                                                   float, float, float, float, float);
int d18a_post_current_8016239c(Ptr32<d18a_DamageMessage>);
void d18a_apply_point_800eca14(Ptr32<d18a_Damageable>, Ptr32<d18a_Vec3>);
int d18a_forward_point_800e5ca4(Ptr32<d18a_Vec3>, unsigned int, int, float);
float d18a_handle_float_80178df0(Ptr32<d18a_Handle>);
void d18a_update_800eb6e4(Ptr32<d18a_Damageable>);
extern Ptr32<d18a_Queue> d18a_queue_804b1754;
}
template <class T> inline const T &d18a_max(const T &a, const T &b) { return a < b ? b : a; }
// Absolute value through the integer bits of the stored float.
inline float d18a_abs(const float &value) {
    unsigned int bits = *(Ptr32<const unsigned int>)&value & 0x7fffffff;
    return *(Ptr32<float>)&bits;
}
extern "C" void w3d_d18a_post_damage_80060fe4(Ptr32<d18a_Damageable> self, int, int, int, Ptr32<const d18a_Vec3> position) {
    Ptr32<d18a_BodyState> state = d18a_body_state_801797b4(d18a_handle_cast_80341584(self->body));
    d18a_post_current_8016239c(d18a_damage_message_800666b4(
        (Ptr32<d18a_DamageMessage>)d18a_message_alloc_801613f0(d18a_queue_804b1754, 52), position, position,
        0.0f, 0.0f, 0.0f, state->height(), 0.0f));
    d18a_Vec3 point = *position;
    point.y -= state->height();
    d18a_apply_point_800eca14(self, &point);
    d18a_forward_point_800e5ca4(&point, state->material, 0, 0.0f);
    self->speed = d18a_max(d18a_abs(self->speed) * d18a_handle_float_80178df0(self->scale),
                            d18a_handle_float_80178df0(self->limit));
    d18a_update_800eb6e4(self);
}


