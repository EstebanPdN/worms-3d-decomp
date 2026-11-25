// desc: Query the handle at +0x18, optionally store its count and compare against the expected count; names inferred.
// Observed: handle at +0x18; argument r4 is unused; r5 is expected count;
// r6 is an optional output. The query implementation remains external.
struct R24bCountObject {
    unsigned char unknown_00[0x18];
    unsigned handle;
};

extern "C" int r24b_query_802e4cfc(unsigned handle);

extern "C" unsigned w3d_r24b_query_count_8021907c(
    R24bCountObject *self, unsigned unused, int expected, int *output)
{
    const int preserved_expected = expected;
    const unsigned handle = self->handle;
    int *const preserved_output = output;
    const int actual = r24b_query_802e4cfc(handle);
    if (preserved_output)
        *preserved_output = actual;
    unsigned status = 0x80004005u;
    if (actual == preserved_expected)
        status = 0;
    return status;
}
