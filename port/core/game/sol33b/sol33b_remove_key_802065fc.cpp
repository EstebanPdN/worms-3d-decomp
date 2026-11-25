#include "w3d_ptr.h"
#line 1 "sol33b_remove_key_802065fc.cpp"
// GC32 parallel key/string arrays. String storage uses its observed shared header.
// Field identities and names are inferred from 802065fc and its original callees.
// Requires a valid pointer/count pair and shared text with a six-byte header.
// Original spelling and portable behavior outside the GC32 ABI are not established.
extern "C" void sol33b_release_header_8020bb2c(Ptr32<void>);
struct Sol33bEraseStringBase {Ptr32<char> text;};
extern "C" void sol33b_finish_8020c5c4(Ptr32<Sol33bEraseStringBase>);
extern "C" void sol33b_release_80341588(Ptr32<Sol33bEraseStringBase>);
struct Sol33bEraseString:Sol33bEraseStringBase {
 Sol33bEraseString &operator=(const Sol33bEraseString &other) {
  ++*(Ptr32<unsigned short>)(other.text-6);
  Ptr32<unsigned short> header=(Ptr32<unsigned short>)(text-6);
  if(--*header==0)sol33b_release_header_8020bb2c(header);
  text=other.text;return *this;
 }
 ~Sol33bEraseString(){sol33b_finish_8020c5c4(this);sol33b_release_80341588(this);}
};
inline void sol33b_copy_strings(Ptr32<Sol33bEraseString> first,Ptr32<Sol33bEraseString> last,Ptr32<Sol33bEraseString> result) {
 int count=last-first;
 for(;count>0;--count,++first,++result)*result=*first;
}
struct Sol33bEraseStrings {Ptr32<Sol33bEraseString> first; Ptr32<Sol33bEraseString> last; Ptr32<Sol33bEraseString> limit;
 void erase(Ptr32<Sol33bEraseString> where){if(where+1!=last)sol33b_copy_strings(where+1,last,where);--last;last->~Sol33bEraseString();}
};
extern "C" Ptr32<int> find_int_8035c170(Ptr32<int>,Ptr32<int>,const int &);
struct Sol33bKeyArray {unsigned count,unknown_04;Ptr32<int> data; Ptr32<int> begin(){return data;}Ptr32<int> end(){return data+count;}Ptr32<int> find(const int &value){return find_int_8035c170(begin(),end(),value);} };
struct Sol33bParallelOwner {unsigned unknown[9];Sol33bKeyArray keys;Sol33bEraseStrings strings;};
extern "C" Ptr32<int> find_int_8035c170(Ptr32<int>,Ptr32<int>,const int &);
extern "C" void erase_keys_80210dd8(Ptr32<Sol33bKeyArray>,Ptr32<int>,Ptr32<int>);
extern "C" int sol33b_remove_key_802065fc(Ptr32<Sol33bParallelOwner> self,int key) {
 Ptr32<int> where=self->keys.find(key);
 if(where==self->keys.end())return (int)0x80004005;
 int index=where-self->keys.begin();
 erase_keys_80210dd8(&self->keys,where,where+1);
 self->strings.erase(self->strings.first+index);
 return 0;
}

typedef char Sol33bEraseStringSize[sizeof(Sol33bEraseString)==4?1:-1];
typedef char Sol33bKeyArraySize[sizeof(Sol33bKeyArray)==12?1:-1];


