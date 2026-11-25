#include "w3d_ptr.h"
#line 1 "cc17b_name_hash_80177e28.cpp"
/* Observed ELF-style signed-byte string hash, reduced by owner modulus +2116.
   The original retains a length-service call although its result is unused. */
struct Cc17bNameTable { char pad[2116]; unsigned modulus; };
extern "C" {
unsigned fn_802ef9c0(Ptr32<const char>);
static inline unsigned cc17b_elf_hash(Ptr32<const char> name) {
 unsigned hash=0;
 while(*name) {
  hash<<=4;
  hash+=(signed char)*name;
  ++name;
  unsigned high=hash&0xf0000000u;
  if(high) { hash^=high>>24; hash^=high; }
 }
 return hash;
}
unsigned w3d_cc17b_name_hash_80177e28(Ptr32<Cc17bNameTable> self,Ptr32<const char> name) {
 fn_802ef9c0(name);
 unsigned hash=cc17b_elf_hash(name);
 return (hash%self->modulus)&65535;
}
}


