// UNVERIFIED EXPERIMENT: compiler comparison failed; see build/r23b logs. Not a candidate.
// desc: Decrement the count at +0x810 and copy the last 8-byte pair to output; names inferred.
// Indexing shifts the whole object base before accessing pair fields at +0x10/+0x14.
struct R23bPairV2 { unsigned first, second; };
struct R23bPairStackV2 { unsigned unknown[4]; R23bPairV2 entries[256]; int count; };
extern "C" void w3d_r23b_pop_pair_v2_8020f8ac(R23bPairStackV2 *self, R23bPairV2 *out) {
 int i=--self->count;
 R23bPairStackV2 *shifted=reinterpret_cast<R23bPairStackV2 *>(reinterpret_cast<unsigned char *>(self)+(i*8));
 unsigned second=shifted->entries[0].second;
 unsigned first=shifted->entries[0].first;
 out->second=second; out->first=first;
}
