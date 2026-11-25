extern void * w3d_auto_800fc1f0(const char **, int *);

float s19_damage_scale_8000af90(float v) {
    struct { const char *name; int value; int extra[2]; } k;
    k.name = "DoubleDamage";
    w3d_auto_800fc1f0(&k.name, &k.value);
    if (v == 0.0f)
        v = 1.0f;
    if (k.value == 1)
        v += v;
    return v;
}
