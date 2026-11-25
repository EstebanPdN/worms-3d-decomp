// GWMP8P rev0, observed partial layouts. Built with -mfast-cast: the alpha
// float-to-byte conversions are quantized psq_st (u8) stores.
// Field and slot names describe observed use only; they do not establish the
// original class identities. The panel frame callee takes its byte by const
// reference, so each call builds its own temporary (frame slots 8 and 9).
struct D22fIface;
struct D22fVec3;
// Observed slots: 9 queries the resource, 19/21 take a vector and a flag.
struct D22fIfaceTable {
 void *slots0[9];
 int (*query)(D22fIface *);
 void *slots10[9];
 void (*set_position)(D22fIface *, D22fVec3 *, int);
 void *slots20[1];
 void (*set_scale)(D22fIface *, D22fVec3 *, int);
};
struct D22fIface { D22fIfaceTable *vtable; };
struct D22fVec3 {
 float x, y, z;
 D22fVec3 &set(float a, float b, float c) { x = a; y = b; z = c; return *this; }
 D22fVec3 &operator+=(const D22fVec3 &o) { x += o.x; y += o.y; z += o.z; return *this; }
 D22fVec3 &operator-=(const D22fVec3 &o) { x -= o.x; y -= o.y; z -= o.z; return *this; }
};
struct D22fColour { signed char r, g, b; unsigned char a; };
struct D22fFader {
 unsigned words0[7];
 D22fIface *node;
 unsigned words32[4];
 void *mesh;
 void *timer;
 void *panel;
 int state;
 unsigned words64[43];
 D22fIface *resource;
 int resource_active;
 unsigned words244[6];
 D22fVec3 position;
 D22fVec3 scale;
 D22fVec3 position_step;
 D22fVec3 scale_step;
 float fade;
 int direction;
};
typedef char D22fFaderSize[(sizeof(D22fFader) == 324) ? 1 : -1];
extern "C" int w3d_auto_80178d1c(void *timer);
extern "C" int w3d_panel_set_frame_80173f88(void *panel, const unsigned char &frame);
extern "C" void w3d_active_resource_clear_802c4380(D22fFader *self);
extern "C" void w3d_auto_8015fd1c(D22fFader *self);
extern "C" int w3d_mesh_set_colour_80173df0(void *mesh, D22fColour *colour);

extern "C" int d22f_fader_update_802c256c(D22fFader *self, unsigned time)
{
 unsigned ticks = time / w3d_auto_80178d1c(self->timer);
 if (self->panel != 0) {
  if ((ticks & 1) != 0) {
   w3d_panel_set_frame_80173f88(self->panel, 0);
   self->state = 0;
  } else {
   w3d_panel_set_frame_80173f88(self->panel, self->state != 1);
  }
 }
 if (self->resource && self->resource_active) {
  if (!self->resource->vtable->query(self->resource))
   w3d_active_resource_clear_802c4380(self);
 }
 if (self->node && self->fade != 0.0f) {
  D22fVec3 *position;
  D22fVec3 *scale;
  if (self->direction == 0) self->fade = self->fade - 1.0f;
  else self->fade = self->fade + 1.0f;
  if (self->fade == 0.0f) {
   if (self->direction == 0) {
    position = &self->position.set(0.0f, 0.0f, 0.0f);
    scale = &self->scale.set(1.0f, 1.0f, 1.0f);
   } else {
    scale = &self->scale;
    w3d_auto_8015fd1c(self);
    position = &self->position;
   }
  } else if (self->direction == 0) {
   position = &(self->position += self->position_step);
   scale = &(self->scale += self->scale_step);
  } else {
   position = &(self->position -= self->position_step);
   scale = &(self->scale -= self->scale_step);
  }
  self->node->vtable->set_position(self->node, position, 0);
  self->node->vtable->set_scale(self->node, scale, 0);
  if (self->mesh) {
   unsigned char alpha;
   if (self->direction == 0) alpha = 115 - (unsigned char)(self->fade * 10.0f);
   else alpha = (unsigned char)(-self->fade * 10.0f) + 5;
   D22fColour colour;
   D22fColour *c = &colour;
   c->r = -2; c->g = -22; c->b = -43; c->a = alpha;
   w3d_mesh_set_colour_80173df0(self->mesh, c);
  }
 }
 return 0;
}
