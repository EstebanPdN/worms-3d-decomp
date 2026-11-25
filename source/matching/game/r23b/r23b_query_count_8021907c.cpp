// UNVERIFIED EXPERIMENT: compiler comparison failed; see build/r23b logs. Not a candidate.
// desc: Query the handle at +0x18, optionally store its count, and return zero only for the expected count; names inferred.
// +0x18 handle and external query behavior are unresolved. The second argument is unused in the observed body.
struct R23bCountObject { unsigned char unknown[0x18]; unsigned handle; };
extern "C" int r23b_query_802e4cfc(unsigned handle);
extern "C" unsigned w3d_r23b_query_count_8021907c(R23bCountObject *self, unsigned unused, int expected, int *out) {
 int actual=r23b_query_802e4cfc(self->handle);
 if(out) *out=actual;
 unsigned result=0x80004005u;
 if(actual==expected) result=0;
 return result;
}
