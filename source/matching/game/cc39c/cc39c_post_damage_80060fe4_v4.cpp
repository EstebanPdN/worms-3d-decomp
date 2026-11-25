// cc39c: 0x80060fe4 (280 bytes), post a damage message at a position and
// update the owner's absolute speed.
// Observed in the original DOL: the body state behind the handle at +192
// (identity 0x80341584, then 0x801797b4) is read; a 52-byte message allocated
// from the r13 queue 0x804b1754 (0x801613f0) is constructed by 0x800666b4
// (returns the message) with the position twice, the float at 0x80379294
// (0.0f) as the first three and fifth floats and the state's float at +220 as
// the fourth, and posted (0x8016239c). A copy of the position, lowered by that
// float, goes to 0x800eca14 and to 0x800e5ca4 (with the state's word at +348,
// zero and the 0.0f float in f1, which 0x800e5ca4 forwards untouched). The
// owner's float at +52 then becomes the larger of its absolute value (sign bit
// cleared through an integer copy) times the handle float behind +312 and the
// handle float behind +308 (0x80178df0), selected through references as by an
// inlined max; finally 0x800eb6e4 (void) runs. Arguments r4..r6 are not read.
// All names and views are inferred; unknown bytes are not recovered layout.
struct cc39c_Vec3 { float x, y, z; };
struct cc39c_Handle;
struct cc39c_Queue;
struct cc39c_DamageMessage;                                   // 52 bytes requested
struct cc39c_BodyState {
    unsigned char unknown00[220];
    float height_;                       // +220
    unsigned char unknown_e0[124];
    unsigned int material;               // +348
    float height() const { return height_; }
};
struct cc39c_Damageable {
    unsigned char unknown00[52];
    float speed;                         // +52
    unsigned char unknown38[136];
    cc39c_Handle *body;                  // +192
    unsigned char unknown_c4[112];
    cc39c_Handle *limit;                 // +308
    cc39c_Handle *scale;                 // +312
};
extern "C" {
cc39c_Handle *cc39c_handle_cast_80341584(cc39c_Handle *);
cc39c_BodyState *cc39c_body_state_801797b4(cc39c_Handle *);
void *cc39c_message_alloc_801613f0(cc39c_Queue *, unsigned int);
cc39c_DamageMessage *cc39c_damage_message_800666b4(cc39c_DamageMessage *, const cc39c_Vec3 *, const cc39c_Vec3 *,
                                                   float, float, float, float, float);
int cc39c_post_current_8016239c(cc39c_DamageMessage *);
void cc39c_apply_point_800eca14(cc39c_Damageable *, cc39c_Vec3 *);
int cc39c_forward_point_800e5ca4(cc39c_Vec3 *, unsigned int, int, float);
float cc39c_handle_float_80178df0(cc39c_Handle *);
void cc39c_update_800eb6e4(cc39c_Damageable *);
extern cc39c_Queue *cc39c_queue_804b1754;
extern float cc39c_zero_80379294[];          // reloaded after calls: not const
}
template <class T> inline const T &cc39c_max(const T &a, const T &b) { return a < b ? b : a; }
// Absolute value through the integer bits of the stored float.
inline float cc39c_abs(const float &value) {
    unsigned int bits = *(const unsigned int *)&value & 0x7fffffff;
    return *(float *)&bits;
}
extern "C" void cc39c_post_damage_80060fe4(cc39c_Damageable *self, int, int, int, const cc39c_Vec3 *position) {
    cc39c_BodyState *state = cc39c_body_state_801797b4(cc39c_handle_cast_80341584(self->body));
    cc39c_post_current_8016239c(cc39c_damage_message_800666b4(
        (cc39c_DamageMessage *)cc39c_message_alloc_801613f0(cc39c_queue_804b1754, 52), position, position,
        cc39c_zero_80379294[0], cc39c_zero_80379294[0], cc39c_zero_80379294[0], state->height(), cc39c_zero_80379294[0]));
    cc39c_Vec3 point = *position;
    point.y -= state->height();
    cc39c_apply_point_800eca14(self, &point);
    cc39c_forward_point_800e5ca4(&point, state->material, 0, cc39c_zero_80379294[0]);
    float magnitude = cc39c_abs(self->speed);
    float scaled = magnitude * cc39c_handle_float_80178df0(self->scale);
    self->speed = cc39c_max(scaled, cc39c_handle_float_80178df0(self->limit));
    cc39c_update_800eb6e4(self);
}
