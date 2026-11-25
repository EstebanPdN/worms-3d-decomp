#include "w3d_ptr.h"
#line 1 "sol32b_erase_entry_801af48c.cpp"
// Observed original 0x801af48c; GC32 only, 32-bit pointers and original shared-string domain.
// The five leading owner words are unmodeled observed-offset storage.
// GC32 observed vector entry: held interface, four copied words and shared string.
// Semantic identities of the four copied words remain unknown.
extern "C" void release_header_8020bb2c(Ptr32<void>);
struct Sol32bStringBase { Ptr32<char> text; };
extern "C" void finish_string_8020c5c4(Ptr32<Sol32bStringBase>);
extern "C" void release_string_80341588(Ptr32<Sol32bStringBase>);
struct Sol32bString : Sol32bStringBase {
 Sol32bString &operator=(const Sol32bString &other) {
  ++*(Ptr32<unsigned short>)(other.text - 6);
  Ptr32<unsigned short> header=(Ptr32<unsigned short>)(text-6);
  if (--*header == 0) release_header_8020bb2c(header);
  text = other.text;
  return *this;
 }
 ~Sol32bString() { finish_string_8020c5c4(this); release_string_80341588(this); }
};
struct Sol32bInterface { Ptr32<unsigned int> vtable; void release() { ((Ptr32<void (Ptr32<Sol32bInterface>)>)w3d::G(vtable[4]))(this); } };
struct Sol32bWords { unsigned a,b,c,d; };
struct Sol32bEntry { Ptr32<Sol32bInterface> object; Sol32bWords words; Sol32bString name;
 Sol32bEntry &operator=(const Sol32bEntry &other) {object=other.object;words=other.words;name=other.name;return *this;}
};
inline void sol32b_copy_entries(Ptr32<Sol32bEntry> first,Ptr32<Sol32bEntry> last,Ptr32<Sol32bEntry> result) {
 int count=last-first;
 for(;count>0;--count,++first,++result) *result=*first;
}
struct Sol32bEntryVector {
 Ptr32<Sol32bEntry> first; Ptr32<Sol32bEntry> last; Ptr32<Sol32bEntry> limit;
 void erase(Ptr32<Sol32bEntry> where) {
  Ptr32<Sol32bEntry> next=where+1;
  if(next!=last) {
   sol32b_copy_entries(next,last,where);
  }
  --last;
  last->~Sol32bEntry();
 }
};
struct Sol32bEntryOwner { unsigned unknown[5]; Sol32bEntryVector entries; };
typedef char Sol32bEntrySize[sizeof(Sol32bEntry)==24?1:-1];
extern "C" int sol32b_erase_entry_801af48c(Ptr32<Sol32bEntryOwner> self,int index) {
 Ptr32<Sol32bEntry> where=self->entries.first+index;
 where->object->release();
 self->entries.erase(where);
 return 0;
}

typedef char Sol32bPointerSize[sizeof(Ptr32<void>)==4?1:-1];
typedef char Sol32bVectorSize[sizeof(Sol32bEntryVector)==12?1:-1];


