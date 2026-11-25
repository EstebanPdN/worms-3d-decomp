#include "w3d_ptr.h"
#line 1 "cx8b_transfer_begin_802e1a98.cpp"

struct Cx8bTransferEntry { unsigned int value,unknown04,unknown08; };
struct Cx8bTransferState { char unknown00[156]; unsigned int mode; char unknowna0[32]; int active; char unknownc4[32]; Cx8bTransferEntry entries[8]; char unknown144[20]; unsigned int address,size,offset,cached; };
struct Cx8bTransferOwner { unsigned int unknown00; Ptr32<Cx8bTransferState> state; };
extern "C" int fn_8031ada0(Ptr32<void>,unsigned int,unsigned int,unsigned int,unsigned int);
extern "C" int w3d_cx8b_transfer_begin_802e1a98(Ptr32<Cx8bTransferOwner> self,Ptr32<void> request) {
 Ptr32<Cx8bTransferState> state=self->state;
 if(fn_8031ada0(request,state->address,state->size,state->offset,state->mode)==0) {
 Ptr32<Cx8bTransferState> ready=self->state;ready->cached=ready->entries[ready->active].value;return 1;
 } else return 0;
}




