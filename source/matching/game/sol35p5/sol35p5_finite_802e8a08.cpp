// Experimental GC32 big-endian double classifier, not admitted.
// Original stfd/lwz selects the high 32-bit representation word, clears
// sign and tests unsigned subtraction against the infinity exponent.
// The union representation view follows this compiler's native extension;
// original API name/type identity and ISO C++ portability are not proved.
extern "C" int sol35p5_finite_802e8a08(double value) {
    union Representation { double value; unsigned words[2]; } bits;
    bits.value = value;
    return ((bits.words[0] & 0x7fffffffu) - 0x7ff00000u) >> 31;
}
