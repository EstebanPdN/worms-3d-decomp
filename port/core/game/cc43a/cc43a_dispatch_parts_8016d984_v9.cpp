#include "w3d_ptr.h"
#line 1 "cc43a_dispatch_parts_8016d984_v9.cpp"
// The iterator is an inferred pointer holder, not an original symbol. Its
// lifetime reproduces the witnessed loop-entry pointer copy without padding.
// The entries member marks the start of a variable tail; no fixed bound is inferred.
// Inferred partial render-dispatch views. No complete object size is claimed.
struct cc43a_Renderer;
struct cc43a_RenderPart;
struct cc43a_RenderParts { unsigned char unknown00[24]; unsigned int count; unsigned int unknown1c; Ptr32<cc43a_RenderPart> entries[1]; };
struct cc43a_RenderState { unsigned char unknown00[6]; unsigned short callbackIndex; unsigned char unknown08[20]; Ptr32<cc43a_RenderParts> parts; };
struct cc43a_RenderVtable { Ptr32<void> unknown00[18]; Ptr32<Ptr32<cc43a_RenderState> (Ptr32<cc43a_Renderer>)> state; };
struct cc43a_RenderBase;
typedef Ptr32<void (Ptr32<cc43a_RenderBase>, Ptr32<cc43a_RenderState>)> cc43a_RenderCallback;
struct cc43a_RenderBase { unsigned char unknown00[24]; Ptr32<cc43a_RenderCallback> callbacks; };
struct cc43a_Renderer { Ptr32<cc43a_RenderVtable> vtable; cc43a_RenderBase base; unsigned char unknown20[180]; unsigned char current; };
struct cc43a_RenderInput { unsigned char unknown00[80]; Ptr32<cc43a_RenderParts> indices; };
extern "C" void cc43a_draw_part_8016d49c(Ptr32<cc43a_Renderer>,Ptr32<cc43a_RenderInput>,Ptr32<cc43a_RenderPart>,unsigned int);
struct cc43a_PartIterator { Ptr32<Ptr32<cc43a_RenderPart>> pointer; template <class W3dU> cc43a_PartIterator(Ptr32<W3dU> w3d_p) : cc43a_PartIterator((Ptr32<cc43a_RenderPart> *)w3d_p.get()) {}
 cc43a_PartIterator(Ptr32<cc43a_RenderPart> *p):pointer(p){} };
extern "C" int cc43a_dispatch_parts_8016d984(Ptr32<cc43a_RenderBase> base,Ptr32<cc43a_RenderInput> input) {
 Ptr32<cc43a_Renderer> self=base ? w3d::R((Ptr32<cc43a_Renderer>)((Ptr32<unsigned char>)base-4)) : 0;
 if(input->indices->count==0) return 0;
 unsigned int i=0;
 Ptr32<cc43a_RenderState> state=self->vtable->state(self);
 unsigned int count=state->parts->count;
 Ptr32<Ptr32<cc43a_RenderPart>> part=state->parts->entries;
 if(i<count) {
 cc43a_PartIterator it(part);
 Ptr32<cc43a_RenderBase> dispatchBase=&self->base;
 do {
  cc43a_draw_part_8016d49c(self,input,*it.pointer,i);
  ++it.pointer;
  if(++self->current<count) dispatchBase->callbacks[state->callbackIndex](dispatchBase,state);
 } while(++i<count);
 }
 self->current=0;
 return 0;
}


