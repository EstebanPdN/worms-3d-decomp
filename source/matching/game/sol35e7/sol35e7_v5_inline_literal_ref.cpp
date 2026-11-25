/* Diagnostic reconstructed source; inferred structure, no provenance claim. */
inline unsigned int sol35e7_convert(double x, const double &threshold)
{
    if (x >= threshold) return (unsigned int)(int)(x-threshold) ^ 0x80000000u;
    return (int)x;
}
extern "C" unsigned int sol35e7_cast_v5(double x)
{
    return sol35e7_convert(x, 2147483648.0);
}
