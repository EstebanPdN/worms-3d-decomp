// UNVERIFIED EXPERIMENT: compiler comparison failed; see build/r23b logs. Not a candidate.
// desc: Reverse the requested low bits of the unsigned input into a zero accumulator; names inferred.
// Valid caller contract requires bitCount in 0..32; original signed count+1 guard retained.
extern "C" unsigned w3d_r23b_reverse_bits_8021d7b0(unsigned unused, unsigned input, int bitCount) {
 unsigned result=0;
 if(bitCount+1>1) {
 int remaining=bitCount;
 --bitCount;
 do {
 if(input&1) result|=1u<<bitCount;
 input>>=1;
 --bitCount;
 }while(--remaining!=0);
 }
 return result;
}
