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
 while(index<self->count) {
   if(self->entries[index]) {entries=self->entries;break;}
   index=++*cursor;
 }
 if(*cursor>=self->count) return 0;
 index=(*cursor)++;
 if(entries[index]) entries[index]->table->retain(entries[index]);
 if(*out) (*out)->table->release(*out);
 *out=entries[index];
 return 1;
}
