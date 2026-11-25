
struct Entry { const char *text; unsigned short value; unsigned short next; };
struct StringIndex { unsigned short *buckets; unsigned int mask; unsigned int count; Entry *entries; };
extern "C" int compare_802ef234(const char *,const char *);
extern "C" int w3d_cx9b_hashed_string_index_8020cbcc(StringIndex *self,const char *text,unsigned short *result) {
 const unsigned char *cursor=(const unsigned char *)text;
 unsigned int hash=5381;
 unsigned int byte=*cursor++;
 while(byte) {hash=((hash<<5)+hash)^byte;byte=*cursor++;}
 unsigned int link=self->buckets[hash&self->mask];
 while(link) {
  unsigned int index=link-1;
  Entry *entry=(Entry *)((unsigned char *)self->entries+(index<<3));
  if(compare_802ef234(entry->text,text)==0) { *result=entry->value;return 0; }
  link=entry->next;
 }
 return (int)0x80004005;
}


