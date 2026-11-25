// GC32 parallel key/string arrays. String storage uses its observed shared header.
// Field identities and names are inferred from 802065fc and its original callees.
// Requires a valid pointer/count pair and shared text with a six-byte header.
// Original spelling and portable behavior outside the GC32 ABI are not established.
extern "C" void sol33b_release_header_8020bb2c(void *);
struct Sol33bEraseStringBase {char *text;};
extern "C" void sol33b_finish_8020c5c4(Sol33bEraseStringBase *);
extern "C" void sol33b_release_80341588(Sol33bEraseStringBase *);
struct Sol33bEraseString:Sol33bEraseStringBase {
 Sol33bEraseString &operator=(const Sol33bEraseString &other) {
  ++*(unsigned short *)(other.text-6);
  unsigned short *header=(unsigned short *)(text-6);
  if(--*header==0)sol33b_release_header_8020bb2c(header);
  text=other.text;return *this;
 }
 ~Sol33bEraseString(){sol33b_finish_8020c5c4(this);sol33b_release_80341588(this);}
};
inline void sol33b_copy_strings(Sol33bEraseString *first,Sol33bEraseString *last,Sol33bEraseString *result) {
 int count=last-first;
 for(;count>0;--count,++first,++result)*result=*first;
}
struct Sol33bEraseStrings {Sol33bEraseString *first,*last,*limit;
 void erase(Sol33bEraseString *where){if(where+1!=last)sol33b_copy_strings(where+1,last,where);--last;last->~Sol33bEraseString();}
};
extern "C" int *find_int_8035c170(int *,int *,const int &);
struct Sol33bKeyArray {unsigned count,unknown_04;int *data; int *begin(){return data;}int *end(){return data+count;}int *find(const int &value){return find_int_8035c170(begin(),end(),value);} };
struct Sol33bParallelOwner {unsigned unknown[9];Sol33bKeyArray keys;Sol33bEraseStrings strings;};
extern "C" int *find_int_8035c170(int *,int *,const int &);
extern "C" void erase_keys_80210dd8(Sol33bKeyArray *,int *,int *);
extern "C" int sol33b_remove_key_802065fc(Sol33bParallelOwner *self,int key) {
 int *where=self->keys.find(key);
 if(where==self->keys.end())return (int)0x80004005;
 int index=where-self->keys.begin();
 erase_keys_80210dd8(&self->keys,where,where+1);
 self->strings.erase(self->strings.first+index);
 return 0;
}

typedef char Sol33bEraseStringSize[sizeof(Sol33bEraseString)==4?1:-1];
typedef char Sol33bKeyArraySize[sizeof(Sol33bKeyArray)==12?1:-1];
