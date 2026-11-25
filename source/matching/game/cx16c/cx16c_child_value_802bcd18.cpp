
// Observed child pointer range at +56/+60; changed cached value at +96.
struct Cx16cRange { void **begin; void **end; void **capacity; };
struct Cx16cPanel { char reserved[56]; Cx16cRange children; char gap[96-68]; int value; };
extern "C" void cx16c_apply_802c0cb4(void*,int);
static inline void **cx16c_end(Cx16cRange *range) { return range->end; }
extern "C" void w3d_cx16c_child_value_802bcd18(Cx16cPanel *self,int value) {
 if(self->value!=value) {
  self->value=value;
  for(void **it=self->children.begin; it!=cx16c_end(&self->children);) {
   void *child=*it++;
   cx16c_apply_802c0cb4(child,value);
  }
 }
}
