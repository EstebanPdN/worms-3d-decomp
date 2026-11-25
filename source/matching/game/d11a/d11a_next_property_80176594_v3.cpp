// Iterate occupied property slots, advancing the caller cursor and replacing
// its retained output reference. Partial views: full allocation sizes unknown.
struct d11a_Property;
struct d11a_PropertyTable {
 unsigned unknown[3];
 unsigned (*retain)(d11a_Property *);
 unsigned (*release)(d11a_Property *);
};
struct d11a_Property { d11a_PropertyTable *table; };
struct d11a_PropertyRegistry {
 unsigned char unknown0[24];
 d11a_Property **entries;
 unsigned char unknown28[2088];
 unsigned count;
};
extern "C" int d11a_next_property_80176594(d11a_PropertyRegistry *self,unsigned *cursor,d11a_Property **out)
{
 unsigned index=*cursor;
 d11a_Property **entries;
 while(true) {
   if(index>=self->count) return 0;
   d11a_Property **current=self->entries;
   d11a_Property *property=*(d11a_Property **)((index<<2)+(char *)current);
   entries=current;
   if(property) break;
   index=++*cursor;
 }
 if(*cursor>=self->count) return 0;
 index=(*cursor)++;
 if(entries[index]) entries[index]->table->retain(entries[index]);
 if(*out) (*out)->table->release(*out);
 *out=entries[index];
 return 1;
}
