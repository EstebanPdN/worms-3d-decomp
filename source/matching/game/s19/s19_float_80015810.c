extern unsigned fn_80162BA8(void);

float s19_random_unit_80015810(void) {
    unsigned r = fn_80162BA8() & 0x7fff;
    return (float)r * 3.0518509e-05f;
}
