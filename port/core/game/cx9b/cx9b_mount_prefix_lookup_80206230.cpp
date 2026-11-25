#include "w3d_ptr.h"
#line 1 "cx9b_mount_prefix_lookup_80206230.cpp"

struct Mount { Ptr32<void> object; Ptr32<const signed char> prefix; unsigned int unknown; };
// Inferred PPC32 vector: first +20, end +24; mount records are twelve bytes.
struct MountTable { unsigned char reserved[20]; Ptr32<Mount> first; Ptr32<Mount> end; };
extern "C" Ptr32<void> w3d_cx9b_mount_prefix_lookup_80206230(Ptr32<MountTable> table,Ptr32<const signed char> path,Ptr32<Ptr32<const signed char>> remainder) {
 Ptr32<Mount> mount=table->first;
 Ptr32<Mount> best=table->end;
 unsigned int length=0;
 Ptr32<Mount> end=best;
 for(;mount!=end;++mount) {
  unsigned int matched=0;
  Ptr32<const signed char> prefix=mount->prefix;
  while(path[matched] && path[matched]==prefix[matched]) ++matched;
  if(matched==length && path[length]=='/' && prefix[length]==0) best=mount;
  else if(matched>length) { length=matched; best=mount; }
 }
 if(best==end) return 0;
 if(remainder) *remainder=path+length;
 return best->object;
}




