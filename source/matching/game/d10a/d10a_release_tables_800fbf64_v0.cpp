// Inferred release of held interface tables. Only the reference callbacks are
// described; the concrete dynamic types and complete vtables are not known.
struct d10a_Interface;
struct d10a_InterfaceTable { unsigned unknown[3]; unsigned (*retain)(d10a_Interface *); unsigned (*release)(d10a_Interface *); };
struct d10a_Interface { d10a_InterfaceTable *table; };
struct d10a_Held {
 d10a_Interface *object;
 d10a_Held &operator=(d10a_Interface *next) {
   if(next) next->table->retain(next);
   if(object) object->table->release(object);
   object=next;
   return *this;
 }
};
extern d10a_Held d10a_held_8044a524[],d10a_held_8044a584[],d10a_held_8044a5e4[];
extern d10a_Held d10a_held_8044a564[],d10a_held_8044a5c4[],d10a_held_8044a574[],d10a_held_8044a5d4[];
extern "C" void d10a_release_tables_800fbf64()
{
 for(unsigned i=0;i<16;++i) {
   d10a_held_8044a524[i]=0;
   d10a_held_8044a584[i]=0;
   d10a_held_8044a5e4[i]=0;
 }
 for(unsigned i=0;i<4;++i) {
   d10a_held_8044a564[i]=0;
   d10a_held_8044a5c4[i]=0;
   d10a_held_8044a574[i]=0;
 }
 for(unsigned i=0;i<4;++i) d10a_held_8044a5d4[i]=0;
}
