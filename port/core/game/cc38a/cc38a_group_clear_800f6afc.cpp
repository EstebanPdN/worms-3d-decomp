#include "w3d_ptr.h"
#line 1 "cc38a_group_clear_800f6afc.cpp"

// Collision-manager reset. Partial layouts preserve observed pointer fields,
// arrays and counters without asserting the unknown complete class declaration.
struct cc38a_Group;
extern "C" void cc38a_destroy_800f6ca0(Ptr32<cc38a_Group>,int);
extern "C" Ptr32<void> cc38a_move_802eee50(Ptr32<void>,Ptr32<const void>,unsigned,...);
struct cc38a_Array {Ptr32<Ptr32<cc38a_Group>> begin;Ptr32<Ptr32<cc38a_Group>> end;Ptr32<Ptr32<cc38a_Group>> capacity;
 unsigned size()const{return end-begin;}
 Ptr32<cc38a_Group> & at(unsigned i){return *(Ptr32<Ptr32<cc38a_Group>>)((Ptr32<char>)begin+(i<<2));}
 void clear(){Ptr32<Ptr32<cc38a_Group>> first=begin;Ptr32<Ptr32<cc38a_Group>> last=end;int bytes=(Ptr32<char>)last-(Ptr32<char>)first;cc38a_move_802eee50(first,last,0);end=(Ptr32<Ptr32<cc38a_Group>>)((Ptr32<char>)end-bytes);}
};
struct cc38a_Interface;
struct cc38a_Table {Ptr32<void> unknown[4];Ptr32<void (Ptr32<cc38a_Interface>)> release;};
struct cc38a_Interface {Ptr32<cc38a_Table> table;};
struct cc38a_Held {Ptr32<cc38a_Interface> p;void clear(Ptr32<cc38a_Interface> value=0){if(p)p->table->release(p);p=value;}};
struct cc38a_Manager {unsigned char unknown[44];cc38a_Array groups,other;unsigned char gap68[20];cc38a_Held slots[200];cc38a_Held held;unsigned char gap892[2168];unsigned count,active;void finish(unsigned value){held.clear();count=value;active=value;}};
extern "C" void cc38a_group_clear_800f6afc(Ptr32<cc38a_Manager> self){
 unsigned i;
 for(i=0;i<self->groups.size();++i){Ptr32<cc38a_Group> p=self->groups.at(i);if(p)cc38a_destroy_800f6ca0(p,3);self->groups.at(i)=0;}
 self->groups.clear();self->other.clear();
 for(i=0;i<200;++i)self->slots[i].clear();
 self->finish(0);
}


