// Observed native stream word operations; class and field names are inferred.
inline unsigned swap_word(unsigned value) {
    return (value << 24) | ((value & 0xff00) << 8) |
           ((value >> 8) & 0xff00) | (value >> 24);
}
extern "C" void fn_802047e0(void *, const void *, unsigned);
extern "C" void sol35d5_write_float_802041d4(void *stream, float value) {
    union Bits { float real; unsigned word; } bits;
    bits.real = value;
    unsigned encoded = swap_word(bits.word);
    fn_802047e0(stream, &encoded, 4);
}
