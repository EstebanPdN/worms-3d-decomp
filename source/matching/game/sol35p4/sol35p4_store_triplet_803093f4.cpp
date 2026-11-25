// GWMP8P rev0 observed stores at receiver +28,+32,+36. Full SDK type,
// original name and complete API signature are unknown. Both observed callers
// load single-precision inputs with lfs. This partial GC32 view
// requires aligned, live writable storage and does not establish ownership.
struct Sol35p4Triplet28 {
    unsigned char unknown_prefix[28];
    float first, second, third;
};
extern "C" void sol35p4_store_triplet_803093f4(
    Sol35p4Triplet28 *self, float first, float second, float third) {
    self->first = first;
    self->second = second;
    self->third = third;
}
