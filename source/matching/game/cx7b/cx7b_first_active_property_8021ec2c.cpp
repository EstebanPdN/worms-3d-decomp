struct Cx7bPropertyCollection { char unknown00[24]; unsigned int count; int unknown1c; void *entries[1]; };
struct Cx7bPropertyOwner { char unknown00[20]; Cx7bPropertyCollection *collection; };
extern "C" void *fn_80240994(void *);
extern "C" int fn_8021ed0c(void *);
extern "C" void *w3d_cx7b_first_active_property_8021ec2c(Cx7bPropertyOwner *self) {
 Cx7bPropertyCollection *collection=self->collection; unsigned int count=collection->count; void **entries=collection->entries;
 for(unsigned int i=0;i<count;++i) if(fn_8021ed0c(fn_80240994(entries[i]))) return entries[i];
 return 0;
}
