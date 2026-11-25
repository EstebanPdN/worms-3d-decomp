// d19c: 0x800d6904 (284 bytes). Earthquake random impulse (f3b's quake1 draft,
// without its padding local): while offset 92 is clear, read the
// "Earthquake.ImpulseMagnitudeMax"/"...Min" settings the first time (max still
// 0.0), then build a direction from three unit random samples (x and z mapped
// to -1..1, y fixed at 0.5), scale it by a random fraction of the magnitude
// range and store it at +40. The "random impulse" meaning is inferred.
// Built with -mps-float: the function saves f31 (1.0f) and the unflagged build
// differed only by the 8-byte frame gap below the register save area.
// The vector's user copy constructor reads all three components before
// writing, as the original copy to +40 does.
struct d19c_Vec3 {
    float x, y, z;
    d19c_Vec3() {}
    d19c_Vec3(const d19c_Vec3 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    d19c_Vec3 operator*(float f) const { d19c_Vec3 r; r.x = x * f; r.y = y * f; r.z = z * f; return r; }
};
struct d19c_Quake {
    unsigned char unknown00[40];
    d19c_Vec3 impulse;                   // +40
    unsigned char unknown52[40];
    int disabled;                        // +92
    unsigned char unknown96[40];
    float magnitude_max;                 // +136
    float magnitude_min;                 // +140
};
extern "C" float d19c_random_unit_80162bc8(void);
extern "C" int d19c_settings_read_float_800fc270(const char **, float *);

extern "C" void d19c_quake_random_impulse_800d6904(d19c_Quake *self) {
    if (!self->disabled) {
        if (self->magnitude_max == 0.0f) {
            const char *max_key = "Earthquake.ImpulseMagnitudeMax";
            d19c_settings_read_float_800fc270(&max_key, &self->magnitude_max);
            const char *min_key = "Earthquake.ImpulseMagnitudeMin";
            d19c_settings_read_float_800fc270(&min_key, &self->magnitude_min);
        }
        d19c_Vec3 direction;
        float sample = d19c_random_unit_80162bc8();
        direction.x = sample + sample - 1.0f;
        direction.y = 0.5f;
        sample = d19c_random_unit_80162bc8();
        direction.z = sample + sample - 1.0f;
        float scale = d19c_random_unit_80162bc8() * (self->magnitude_max - self->magnitude_min);
        d19c_Vec3 impulse = direction * scale;
        self->impulse = impulse;
    }
}
