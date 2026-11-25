// Inferred partial render-dispatch views. No complete object size is claimed.
struct cc43a_Renderer;
struct cc43a_RenderPart;
struct cc43a_RenderParts { unsigned char unknown00[24]; unsigned int count; unsigned int unknown1c; cc43a_RenderPart* entries[1]; };
struct cc43a_RenderState { unsigned char unknown00[6]; unsigned short callbackIndex; unsigned char unknown08[20]; cc43a_RenderParts* parts; };
struct cc43a_RenderVtable { void* unknown00[18]; cc43a_RenderState* (*state)(cc43a_Renderer*); };
struct cc43a_RenderBase;
typedef void (*cc43a_RenderCallback)(cc43a_RenderBase*,cc43a_RenderState*);
struct cc43a_RenderBase { unsigned char unknown00[24]; cc43a_RenderCallback* callbacks; };
struct cc43a_Renderer { cc43a_RenderVtable* vtable; cc43a_RenderBase base; unsigned char unknown20[180]; unsigned char current; };
struct cc43a_RenderInput { unsigned char unknown00[80]; cc43a_RenderParts* indices; };
extern "C" void cc43a_draw_part_8016d49c(cc43a_Renderer*,cc43a_RenderInput*,cc43a_RenderPart*,unsigned int);
extern "C" int cc43a_dispatch_parts_8016d984(cc43a_RenderBase* base,cc43a_RenderInput* input) {
 cc43a_Renderer* self=base ? (cc43a_Renderer*)((unsigned char*)base-4) : 0;
 if(input->indices->count==0) return 0;
 unsigned int i=0;
 cc43a_RenderState* state=self->vtable->state(self);
 unsigned int count=state->parts->count;
 cc43a_RenderPart** part=state->parts->entries;
 if(i<count) {
 cc43a_RenderBase* dispatchBase=&self->base;
 do {
  cc43a_draw_part_8016d49c(self,input,*part,i);
  ++part;
  if(++self->current<count) dispatchBase->callbacks[state->callbackIndex](dispatchBase,state);
 } while(++i<count);
 }
 self->current=0;
 return 0;
}
