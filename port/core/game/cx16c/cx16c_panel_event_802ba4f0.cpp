#include "w3d_ptr.h"
#line 1 "cx16c_panel_event_802ba4f0.cpp"

// Event kind is the original halfword at offset zero; embedded context is +28.
struct Cx16cEvent { unsigned short kind; };
extern "C" int cx16c_base_event_8015fb34(Ptr32<void>,Ptr32<Cx16cEvent>);
extern "C" void cx16c_initialize_802ba5c4(Ptr32<void>);
extern "C" void cx16c_release_802ba680(Ptr32<void>);
extern "C" int cx16c_context_802b264c(Ptr32<void>);
extern "C" int cx16c_context_event_802aff9c(Ptr32<void>,Ptr32<Cx16cEvent>);
extern "C" int w3d_cx16c_panel_event_802ba4f0(Ptr32<void> self,Ptr32<Cx16cEvent> event) {
 Ptr32<void> context;
 switch(event->kind) {
 case 64:
  if(cx16c_base_event_8015fb34(self,event)>=0) {
   cx16c_initialize_802ba5c4(self);
   return 0;
  } else return (int)0x80004005U;
 case 66:
  cx16c_release_802ba680(self);
  return cx16c_base_event_8015fb34(self,event);
 default:
  context=(Ptr32<char>)self+28;
  if(cx16c_context_802b264c(context)) cx16c_context_event_802aff9c(context,event);
  return cx16c_base_event_8015fb34(self,event);
 }
 return cx16c_base_event_8015fb34(self,event);
}


