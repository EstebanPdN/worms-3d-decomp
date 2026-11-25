// UNVERIFIED EXPERIMENT: compiler comparison failed; see build/r23b logs. Not a candidate.
// desc: Return one when forced or when object flag 0x20000000 at +0x108 is set; names inferred.
struct R23bFlagObject { unsigned char unknown[0x108]; unsigned flags; };
extern "C" int w3d_r23b_force_or_flag_801fb0c0(R23bFlagObject *self, int force) {
 if(force) return 1;
 int result=1;
 if(self->flags & 0x20000000u) return result;
 return 0;
}
