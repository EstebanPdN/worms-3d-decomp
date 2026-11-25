extern void w3d_auto_800fc270(const char **, float *);
extern int FUN_800fc4c8(const char **, float);

void s19_low_gravity_8008c6c0(void) {
    const char *gameDefault = "Low.Gravity.GameDefault";
    float value = 1.0f;
    const char *multiplier;
    w3d_auto_800fc270(&gameDefault, &value);
    multiplier = "Low.Gravity.Multiplier";
    FUN_800fc4c8(&multiplier, value);
}
