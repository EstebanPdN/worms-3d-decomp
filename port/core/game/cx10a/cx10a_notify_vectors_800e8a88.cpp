#include "w3d_ptr.h"
#line 1 "cx10a_notify_vectors_800e8a88.cpp"
// Observed PPC32 vectors +0x3c/+0x48, four interface pointers +0xa8..+0xb4, vtable +0x38.
struct Cx10aNotifyVector {float x,y,z;};
struct Cx10aNotify;
struct Cx10aNotifyTable {Ptr32<void (void)> unused[14];Ptr32<void (Ptr32<Cx10aNotify>, int, Ptr32<const Cx10aNotifyVector>)> send;};
struct Cx10aNotify {Ptr32<Cx10aNotifyTable> table;};
struct Cx10aNotifyOwner {unsigned char unknown00[0x3c];Cx10aNotifyVector position,direction;unsigned char unknown54[0x54];Ptr32<Cx10aNotify> first; Ptr32<Cx10aNotify> second; Ptr32<Cx10aNotify> third; Ptr32<Cx10aNotify> fourth;};
extern "C" void w3d_cx10a_notify_vectors_800e8a88(Ptr32<Cx10aNotifyOwner> self){
if(self->first){self->first->table->send(self->first,3,&self->position);self->first->table->send(self->first,4,&self->direction);}
if(self->second){self->second->table->send(self->second,3,&self->position);self->second->table->send(self->second,4,&self->direction);}
if(self->third){self->third->table->send(self->third,3,&self->position);self->third->table->send(self->third,4,&self->direction);}
if(self->fourth){self->fourth->table->send(self->fourth,3,&self->position);self->fourth->table->send(self->fourth,4,&self->direction);}
}


