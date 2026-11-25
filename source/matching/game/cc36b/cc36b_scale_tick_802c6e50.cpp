// Observed partial countdown and render-node views. Field and type names are inferred;
// neither the matching frame nor these views establish original declarations or sizeof.
// The Vec3 constructor preserves original single-precision multiply/subtract order.
// Conversion bias is compiler-owned file-backed data; other constants remain external.
struct cc36b_Vec3 { float x,y,z; inline cc36b_Vec3(float a,float b,float c):x(a),y(b),z(c) {} };
struct cc36b_RenderNode { void **vtable; };
struct cc36b_ScaleState { char unknown0[28]; cc36b_RenderNode *node; char unknown32[56]; int countdown; char unknown92[4]; short mode; char unknown98[10]; int enabled; };
extern float cc36b_scale_step_y_803d8dd8[];
extern float cc36b_scale_identity_803d8ddc[];
extern float cc36b_scale_step_x_803d8de0[];
extern "C" int w3d_cc36b_scale_tick_802c6e50(cc36b_ScaleState *self) {
 if(self->enabled) {
  if(self->countdown!=-1) {
   float value=(float)self->countdown;
   float y=cc36b_scale_identity_803d8ddc[0]-value*cc36b_scale_step_y_803d8dd8[0];
   float x=cc36b_scale_identity_803d8ddc[0]-value*cc36b_scale_step_x_803d8de0[0];
   if(self->mode!=32) x=y;
   cc36b_Vec3 scale(x,y,cc36b_scale_identity_803d8ddc[0]);
   ((void (*)(cc36b_RenderNode *,cc36b_Vec3 *,int))self->node->vtable[21])(self->node,&scale,0);
   --self->countdown;
  } else {
   cc36b_Vec3 scale(cc36b_scale_identity_803d8ddc[0],cc36b_scale_identity_803d8ddc[0],cc36b_scale_identity_803d8ddc[0]);
   ((void (*)(cc36b_RenderNode *,cc36b_Vec3 *,int))self->node->vtable[21])(self->node,&scale,0);
  }
 }
 return 0;
}
