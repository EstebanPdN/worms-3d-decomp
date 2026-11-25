
// Observed child pointer range at +56/+60; changed cached value at +100.
struct Cx16cRange { void **begin; void **end; void **capacity; };
struct Cx16cPanel { char reserved[56]; Cx16cRange children; char gap[100-68]; int value; };
extern "C" void cx16c_apply_802bfba4(void*,int);
static inline void **cx16c_end(Cx16cRange *range) { return range->end; }
extern "C" void w3d_cx16c_child_value_802bcc40(Cx16cPanel *self,int value) {
 if(self->value!=value) {
  self->value=value;
  for(void **it=self->children.begin; it!=cx16c_end(&self->children);) {
   void *child=*it++;
   cx16c_apply_802bfba4(child,value);
  }
 }
}
