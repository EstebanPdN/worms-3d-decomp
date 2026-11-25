
struct Mount { void *object; const signed char *prefix; unsigned int unknown; };
// Inferred PPC32 vector: first +20, end +24; mount records are twelve bytes.
struct MountTable { unsigned char reserved[20]; Mount *first; Mount *end; };
extern "C" void *w3d_cx9b_mount_prefix_lookup_80206230(MountTable *table,const signed char *path,const signed char **remainder) {
 Mount *mount=table->first;
 Mount *best=table->end;
 unsigned int length=0;
 Mount *end=best;
 for(;mount!=end;++mount) {
  unsigned int matched=0;
  const signed char *prefix=mount->prefix;
  while(path[matched] && path[matched]==prefix[matched]) ++matched;
  if(matched==length && path[length]=='/' && prefix[length]==0) best=mount;
  else if(matched>length) { length=matched; best=mount; }
 }
 if(best==end) return 0;
 if(remainder) *remainder=path+length;
 return best->object;
}


