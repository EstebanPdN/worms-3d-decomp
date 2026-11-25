// Inferred stream API prefix; receiver is external and never allocated here.
struct F18bStreamPrefix;
// Original 0x802047e0 returns a 32-bit status; mode one returns zero,
// mode two forwards virtual write status, other modes return 0x80004005.
extern "C" unsigned fn_802047e0(F18bStreamPrefix *,const void *,unsigned);
extern "C" unsigned f18b_write_float_802041d4(F18bStreamPrefix *self,float value){
 union FloatWord { float value; unsigned bits; } word;
 word.value=value;
 const unsigned &bits=word.bits;
 unsigned swapped=(bits<<24)|((bits&0xff00)<<8)|((bits>>8)&0xff00)|(bits>>24);
 return fn_802047e0(self,&swapped,4);
}
