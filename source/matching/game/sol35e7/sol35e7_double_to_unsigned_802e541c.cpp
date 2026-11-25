/* Reconstructed from the original PAL instructions at 0x802e541c.
 * Names and source structure are inferred; no upstream source provenance
 * has been established. Reference ABI: PPC32 big endian, binary64 double.
 *
 * This explicitly models the two signed conversions in the original.
 * For finite 0 <= x < 2^32 it produces truncation toward zero to unsigned32.
 * C++ does not specify a portable result for NaN, infinity, or values whose
 * truncated signed-conversion operand is outside the signed32 range.
 * The native instruction result/FP status in those cases is target-specific.
 * No claim about those cases on other compilers/platforms is made.
 */
typedef char sol35e7_int_is_32_bits[sizeof(int) == 4 ? 1 : -1];
typedef char sol35e7_unsigned_is_32_bits[sizeof(unsigned int) == 4 ? 1 : -1];
typedef char sol35e7_double_is_8_bytes[sizeof(double) == 8 ? 1 : -1];

extern "C" unsigned int sol35e7_double_to_unsigned_802e541c(double x)
{
    if (x >= 2147483648.0)
        return (unsigned int)(int)(x - 2147483648.0) ^ 0x80000000u;
    return (int)x;
}
