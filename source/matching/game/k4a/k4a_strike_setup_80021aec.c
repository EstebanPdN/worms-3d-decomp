typedef struct K4aStrike { char pad0[4]; int armed; char pad1[12]; float target[3]; } K4aStrike;
extern char w3d_str_8036c0e4[];
extern char w3d_str_8036c0fc[];
extern char w3d_str_8036c104[];
extern char w3d_str_8036c11c[];
extern char w3d_str_8036c12c[];
extern char w3d_str_8036c140[];
extern const float w3d_f32_8036c158[];
extern void *w3d_object_804aa8c8;
extern int s8_property_read_800fc5dc(const char **name, float *value);
extern int s8_property_write_800fc43c(const char **name, int value);
extern int FUN_80035714(void *object, const char *name, float value);

int k4a_strike_setup_80021aec(K4aStrike *self)
{
    const char *target_key;
    const char *target_key_b;
    const char *payload_key;
    const char *has_key;
    const char *water_key;
    target_key = w3d_str_8036c0e4;
    s8_property_read_800fc5dc(&target_key, self->target);
    FUN_80035714(w3d_object_804aa8c8, w3d_str_8036c0fc, w3d_f32_8036c158[0]);
    target_key_b = w3d_str_8036c104;
    s8_property_read_800fc5dc(&target_key_b, self->target);
    payload_key = w3d_str_8036c11c;
    s8_property_read_800fc5dc(&payload_key, self->target);
    has_key = w3d_str_8036c12c;
    s8_property_write_800fc43c(&has_key, 1);
    water_key = w3d_str_8036c140;
    s8_property_write_800fc43c(&water_key, 0);
    self->armed = 1;
    return 0;
}
