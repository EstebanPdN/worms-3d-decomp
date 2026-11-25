// Angle-limit controller message handler (GWMP8P 0x80026c40, 468 bytes).
// Message 64: forward to the base handler and, on success, run the
// initializer at 0x80026e74 (failure returns E_FAIL 0x80004005). Message 66:
// notify 0x80027328 and forward to the base handler. Other messages are
// compared with six cached message ids (equality helper 0x8015f65c):
//   - the first saves both channels' current values, runs 0x8002709c and sets
//     the channels to -pi/2 and +pi/2 (original floats at 0x8036cae4/0x8036cae8);
//   - the next four set the first or second limit flag to 1 or 0;
//   - the sixth queries the message (0x800a8334) and forwards a nonzero value;
//   - unmatched messages go to the base handler.
// The message id is read once; the switch uses an unsigned view of a signed
// 16-bit copy, which reproduces the original separate switch operand register.
// Cached ids and floats are original objects referenced by address; this unit
// owns no initialized data.

struct D15aAngleOwner_80026c40
{
    char unknown0[36];
    void *channelA;     // +36
    void *channelB;     // +40
    char unknown44[32];
    int firstLimit;     // +76
    int secondLimit;    // +80
    char unknown84[4];
    float savedB;       // +88
    float savedA;       // +92
};

extern unsigned w3d_d15a_msg_save_804acb5c;
extern unsigned w3d_d15a_msg_first_on_804acb1c;
extern unsigned w3d_d15a_msg_first_off_804acb24;
extern unsigned w3d_d15a_msg_second_on_804acb2c;
extern unsigned w3d_d15a_msg_second_off_804acb34;
extern unsigned w3d_d15a_msg_query_804acb3c;
extern float w3d_d15a_minus_half_pi_8036cae4[];
extern float w3d_d15a_half_pi_8036cae8[];

extern "C" {
int w3d_d15a_base_messages_8015fb34(void *self, void *msg);
void w3d_d15a_angle_initialize_80026e74(void *self);
void w3d_d15a_angle_notify_80027328(void *self);
int w3d_message_id_equals_cache(unsigned short id, unsigned *cache);
void *w3d_d15a_channel_value_80342a74(void *channel);
float w3d_d15a_value_get_80178df0(void *value);
int w3d_d15a_value_set_80178dfc(void *value, const float *source);
void w3d_d15a_angle_apply_8002709c(void *self);
void w3d_d15a_angle_limits_800272b0(void *self, int first, int second);
void w3d_d15a_message_query_800a8334(void *msg, int *scratch, int *value);
void w3d_d15a_angle_forward_80027388(void *self, int value);

int w3d_d15a_angle_messages_80026c40(D15aAngleOwner_80026c40 *self, unsigned short *msg)
{
    unsigned short id = *msg;
    short signedId = id;
    switch ((unsigned short)signedId)
    {
    case 64:
        if (w3d_d15a_base_messages_8015fb34(self, msg) >= 0)
        {
            w3d_d15a_angle_initialize_80026e74(self);
            return 0;
        }
        return 0x80004005;
    case 66:
        w3d_d15a_angle_notify_80027328(self);
        goto fallback;
    default:
        if (w3d_message_id_equals_cache(id, &w3d_d15a_msg_save_804acb5c))
        {
            self->savedA = w3d_d15a_value_get_80178df0(w3d_d15a_channel_value_80342a74(self->channelA));
            self->savedB = w3d_d15a_value_get_80178df0(w3d_d15a_channel_value_80342a74(self->channelB));
            w3d_d15a_angle_apply_8002709c(self);
            void *a = w3d_d15a_channel_value_80342a74(self->channelA);
            float low = *w3d_d15a_minus_half_pi_8036cae4;
            w3d_d15a_value_set_80178dfc(a, &low);
            void *b = w3d_d15a_channel_value_80342a74(self->channelB);
            float high = *w3d_d15a_half_pi_8036cae8;
            w3d_d15a_value_set_80178dfc(b, &high);
        }
        else if (w3d_message_id_equals_cache(id, &w3d_d15a_msg_first_on_804acb1c))
            w3d_d15a_angle_limits_800272b0(self, 1, self->secondLimit);
        else if (w3d_message_id_equals_cache(id, &w3d_d15a_msg_first_off_804acb24))
            w3d_d15a_angle_limits_800272b0(self, 0, self->secondLimit);
        else if (w3d_message_id_equals_cache(id, &w3d_d15a_msg_second_on_804acb2c))
            w3d_d15a_angle_limits_800272b0(self, self->firstLimit, 1);
        else if (w3d_message_id_equals_cache(id, &w3d_d15a_msg_second_off_804acb34))
            w3d_d15a_angle_limits_800272b0(self, self->firstLimit, 0);
        else
        {
            if (!w3d_message_id_equals_cache(id, &w3d_d15a_msg_query_804acb3c))
            {
            fallback:
                return w3d_d15a_base_messages_8015fb34(self, msg);
            }
            int scratch;
            int value;
            w3d_d15a_message_query_800a8334(msg, &scratch, &value);
            if (value)
                w3d_d15a_angle_forward_80027388(self, value);
        }
    }
    return 0;
}
}
