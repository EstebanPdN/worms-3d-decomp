/* Diagnostic reconstructed source; inferred structure, no provenance claim. */
extern "C" const double sol35e7_threshold_803db440[];
inline unsigned int sol35e7_convert(double x, const double &threshold)
{
    if (x >= threshold) return (unsigned int)(int)(x-threshold) ^ 0x80000000u;
    return (int)x;
}
extern "C" unsigned int sol35e7_cast_v4(double x)
{
    return sol35e7_convert(x, sol35e7_threshold_803db440[0]);
}
