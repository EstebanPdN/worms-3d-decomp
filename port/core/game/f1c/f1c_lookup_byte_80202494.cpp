#include "w3d_ptr.h"
#line 1 "f1c_lookup_byte_80202494.cpp"
// Observed table view and key lookup at the original entry. Names are inferred.
// Volatile accesses preserve the original store/load order; original qualifiers are unknown.
struct Record {unsigned key; unsigned char value;};
struct Table {Ptr32<Record> begin; Ptr32<Record> end;};
struct Owner {char unused[124]; Table table;};
extern "C" Ptr32<Record> fn_8035a990(Ptr32<Record>,Ptr32<Record>,Ptr32<const unsigned int>);
extern "C" unsigned fn_801fff18(unsigned);
extern "C" unsigned char f1c_lookup_byte_80202494(Ptr32<Owner> self,unsigned key) {
 volatile unsigned local[2]; local[0]=key;
 Ptr32<Table> table=&self->table;
 Ptr32<Record> found=fn_8035a990(((Ptr32<volatile Table>)table)->begin,((Ptr32<volatile Table>)table)->end,(Ptr32<const unsigned int>)local);
 unsigned char result;
 if(found==table->end) result=fn_801fff18(key);
 else result=found->value;
 return result;
}


