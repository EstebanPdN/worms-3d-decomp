unsigned w3d_s21_reverse_bits_8021d7b0(int unused, unsigned value, int bits)
{
    unsigned result = 0;
    int i;
    for (i = 0; i < bits; i++) {
        if (value & 1)
            result |= 1 << (bits - i - 1);
        value >>= 1;
    }
    return result;
}
