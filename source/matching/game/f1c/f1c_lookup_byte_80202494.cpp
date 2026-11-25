// Observed table view and key lookup at the original entry. Names are inferred.
// Volatile accesses preserve the original store/load order; original qualifiers are unknown.
struct Record {unsigned key; unsigned char value;};
struct Table {Record *begin,*end;};
struct Owner {char unused[124]; Table table;};
extern "C" Record *fn_8035a990(Record *,Record *,const unsigned *);
extern "C" unsigned fn_801fff18(unsigned);
extern "C" unsigned char f1c_lookup_byte_80202494(Owner *self,unsigned key) {
 volatile unsigned local[2]; local[0]=key;
 Table *table=&self->table;
 Record *found=fn_8035a990(((volatile Table *)table)->begin,((volatile Table *)table)->end,(const unsigned *)local);
 unsigned char result;
 if(found==table->end) result=fn_801fff18(key);
 else result=found->value;
 return result;
}
