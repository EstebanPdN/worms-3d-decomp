// Inferred external object views, never complete local constructions.
struct Message { unsigned short id; };
struct Cache {unsigned flagsAndId;char*name;};
struct Panel;
struct State { char unknown0[11];unsigned char flags;char unknown12[104];char*commands; };
struct Choice {char unknown0[40];State*state;char unknown44[84];int disabled;char unknown132[8];int enabled;};
extern int global_804abb48;
extern Cache cache_804b0ed8,cache_804b0ec8,cache_804b0ee0,cache_804b0ed0;
extern "C" int fn_8015fb34(Choice*,Message*);
extern "C" void fn_802a4cbc(Choice*),fn_802a4f98(Choice*);
extern "C" int fn_802b264c(Panel*);
extern "C" int fn_8015f65c(unsigned,Cache*);
extern "C" int fn_802a7980(Choice*),fn_802a7998(Choice*);
extern "C" void fn_802b22b0(Panel*),fn_802a6e3c(Choice*),fn_802a6ee4(Choice*);
extern "C" void fn_802b1258(const char*);
extern "C" void fn_802aff9c(Panel*,Message*);
struct StringHeader {unsigned short references,length,capacity;};
inline unsigned length(const char*text) {return ((const StringHeader*)(text-6))->length;}
extern "C" int g1p_choice_message_802a47a4(Choice*self,Message*message) {
 switch(message->id) {
 case 64:
  if(fn_8015fb34(self,message)>=0) {fn_802a4cbc(self);return 0;}
  return (int)0x80004005u;
 case 66:fn_802a4f98(self);break;
 default:
  
  if(fn_802b264c((Panel*)((char*)self+28))) {
   if(!global_804abb48&&!self->disabled) {
    if((fn_8015f65c(message->id,&cache_804b0ed8)||fn_8015f65c(message->id,&cache_804b0ec8))&&fn_802a7980(self)==1&&fn_802a7998(self)==0) {
     State*state=self->state;
     if(((state->flags^4)&4)==0||!self->enabled)fn_802b22b0((Panel*)((char*)self+28));
     else {
      fn_802a6e3c(self);
      if(length(state->commands)&&((self->state->flags^4)&4)&&self->enabled)fn_802b1258(state->commands);
     }
     return 0;
    }
    if((fn_8015f65c(message->id,&cache_804b0ee0)||fn_8015f65c(message->id,&cache_804b0ed0))&&fn_802a7980(self)==1&&fn_802a7998(self)==0) {
     State*state=self->state;
     if(((state->flags^4)&4)==0||!self->enabled)fn_802b22b0((Panel*)((char*)self+28));
     else {
      fn_802a6ee4(self);
      if(length(state->commands)&&((self->state->flags^4)&4)&&self->enabled)fn_802b1258(state->commands);
     }
     return 0;
    }
   }
   fn_802aff9c((Panel*)((char*)self+28),message);
  }
  break;
 }
 return fn_8015fb34(self,message);
}
