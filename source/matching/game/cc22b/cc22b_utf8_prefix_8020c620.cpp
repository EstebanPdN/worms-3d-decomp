// Original byte-boundary walk: counts non-continuation bytes without validating
// UTF-8. Returns bytes before the first lead byte beyond the requested count.
// Signed byte extension is observed, including for non-ASCII bytes.
extern "C" unsigned int w3d_cc22b_utf8_prefix_8020c620(const signed char **text,unsigned int limit)
{
 unsigned int characters=0,bytes=0;
 if(!limit) return 0;
 while(characters<=limit) {
  signed char byte=(*text)[bytes];
  if(!byte) break;
  if((byte&0xc0)!=0x80) {
   ++characters;
   if(characters>limit) break;
  }
  ++bytes;
 }
 return bytes;
}
