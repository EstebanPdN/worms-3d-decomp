/* Observed: the object keeps a clamped offset vector at +96, scaled by an
   integer base at +92. The vector is copied into a stack local, shifted by
   the amount the caller's value exceeds base+1000 (scaled by the factor at
   0x80377898), and forwarded through virtual slot 40 of the object's vtable. */
struct E15aVec3 {
 float x;
 float y;
 float z;
};
struct E15aObject {
 void (**vtable)();   /* +0 */
 unsigned char unknown[88];
 int base;            /* +92 */
 E15aVec3 offset;     /* +96 */
};
extern "C" {
extern const float lbl_80377898[];
void w3d_e15a_offset_query_8004ed24(E15aObject *self,unsigned int value) {
 int base=self->base;
 E15aVec3 local;
 const E15aVec3 *in=&self->offset;
 E15aVec3 *out=&local;
 out->x=in->x;
 out->y=in->y;
 out->z=in->z;
 if (value>(unsigned int)(base+1000)) {
  unsigned int delta=value;
  delta-=1000;
  delta-=base;
  local.y=(float)delta*lbl_80377898[0]+local.y;
 }
 ((void (*)(E15aObject *,E15aVec3 *))self->vtable[10])(self,out);
}
}
