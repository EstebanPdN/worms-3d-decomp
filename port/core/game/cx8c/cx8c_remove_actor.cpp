#include "w3d_ptr.h"
#line 1 "cx8c_remove_actor.cpp"
/* Layout offsets and call addresses observed in the original. Names and object roles are inferred. */
struct Cx8cActor {unsigned char unknown[32];unsigned int identifier;};
struct Cx8cEntry {unsigned char unknown[6];unsigned short identifier;};
struct Cx8cTable {unsigned int count,unknown;Ptr32<Ptr32<Cx8cEntry>> begin;};
struct Cx8cOwner {unsigned char unknown[136];Cx8cTable table;};
extern "C" void cx8c_erase_801f2a30(Ptr32<Cx8cTable>,Ptr32<Ptr32<Cx8cEntry>>,Ptr32<Ptr32<Cx8cEntry>>);
extern "C" unsigned int w3d_cx8c_remove_actor_8034bdb8(Ptr32<Cx8cOwner> self,Ptr32<Cx8cActor> actor) {
 unsigned int id=actor->identifier>>22;Ptr32<Ptr32<Cx8cEntry>> first=self->table.begin; Ptr32<Ptr32<Cx8cEntry>> last=first+self->table.count;
 for(;first!=last;++first) if((*first)->identifier==id) {cx8c_erase_801f2a30(&self->table,first,first+1);return 0;}
 return 0x80004005;
}


