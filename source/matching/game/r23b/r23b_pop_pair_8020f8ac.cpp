// UNVERIFIED EXPERIMENT: compiler comparison failed; see build/r23b logs. Not a candidate.
// desc: Decrement the stack count at +0x810 and copy its last pair to the output; names inferred.
// Observed: pair array +0x10, stride 8, signed count +0x810. Caller must supply a nonempty stack.
struct R23bPair { unsigned first, second; };
struct R23bPairStack { unsigned unknown[4]; R23bPair entries[256]; int count; };
extern "C" void w3d_r23b_pop_pair_8020f8ac(R23bPairStack *self, R23bPair *out) {
 int i=--self->count;
 unsigned second=self->entries[i].second;
 unsigned first=self->entries[i].first;
 out->second=second; out->first=first;
}
