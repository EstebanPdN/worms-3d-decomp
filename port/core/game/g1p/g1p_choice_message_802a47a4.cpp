#include "w3d_ptr.h"
#line 1 "g1p_choice_message_802a47a4.cpp"
// Inferred external object views, never complete local constructions.
struct Message { unsigned short id; };
struct Cache {unsigned flagsAndId;Ptr32<char> name;};
struct Panel;
struct State { char unknown0[8];unsigned char flags; char w3d_tag_rest[3];char unknown12[104];Ptr32<char> commands; };
struct Choice {char unknown0[40];Ptr32<State> state;char unknown44[84];int disabled;char unknown132[8];int enabled;};
extern int global_804abb48;
extern Cache cache_804b0ed8,cache_804b0ec8,cache_804b0ee0,cache_804b0ed0;
extern "C" int fn_8015fb34(Ptr32<Choice>,Ptr32<Message>);
extern "C" void fn_802a4cbc(Ptr32<Choice>),fn_802a4f98(Ptr32<Choice>);
extern "C" int fn_802b264c(Ptr32<Panel>);
extern "C" int fn_8015f65c(unsigned,Ptr32<Cache>);
extern "C" int fn_802a7980(Ptr32<Choice>),fn_802a7998(Ptr32<Choice>);
extern "C" void fn_802b22b0(Ptr32<Panel>),fn_802a6e3c(Ptr32<Choice>),fn_802a6ee4(Ptr32<Choice>);
extern "C" void fn_802b1258(Ptr32<const char>);
extern "C" void fn_802aff9c(Ptr32<Panel>,Ptr32<Message>);
struct StringHeader {unsigned short references,length,capacity;};
inline unsigned length(Ptr32<const char> text) {return ((Ptr32<const StringHeader>)(text-6))->length;}
extern "C" int g1p_choice_message_802a47a4(Ptr32<Choice> self,Ptr32<Message> message) {
 switch(message->id) {
 case 64:
  if(fn_8015fb34(self,message)>=0) {fn_802a4cbc(self);return 0;}
  return (int)0x80004005u;
 case 66:fn_802a4f98(self);break;
 default:
  
  if(fn_802b264c((Ptr32<Panel>)((Ptr32<char>)self+28))) {
   if(!global_804abb48&&!self->disabled) {
    if((fn_8015f65c(message->id,&cache_804b0ed8)||fn_8015f65c(message->id,&cache_804b0ec8))&&fn_802a7980(self)==1&&fn_802a7998(self)==0) {
     Ptr32<State> state=self->state;
     if(((state->flags^4)&4)==0||!self->enabled)fn_802b22b0((Ptr32<Panel>)((Ptr32<char>)self+28));
     else {
      fn_802a6e3c(self);
      if(length(state->commands)&&((self->state->flags^4)&4)&&self->enabled)fn_802b1258(state->commands);
     }
     return 0;
    }
    if((fn_8015f65c(message->id,&cache_804b0ee0)||fn_8015f65c(message->id,&cache_804b0ed0))&&fn_802a7980(self)==1&&fn_802a7998(self)==0) {
     Ptr32<State> state=self->state;
     if(((state->flags^4)&4)==0||!self->enabled)fn_802b22b0((Ptr32<Panel>)((Ptr32<char>)self+28));
     else {
      fn_802a6ee4(self);
      if(length(state->commands)&&((self->state->flags^4)&4)&&self->enabled)fn_802b1258(state->commands);
     }
     return 0;
    }
   }
   fn_802aff9c((Ptr32<Panel>)((Ptr32<char>)self+28),message);
  }
  break;
 }
 return fn_8015fb34(self,message);
}


