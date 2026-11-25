#include "w3d_ptr.h"
#line 1 "cx9c_binary_name_find.cpp"
/* Observed signed count, four-byte string-pointer stride and strcmp followed
 * by an original reverse comparator. Search and key names are inferred. */
extern "C" int cx9c_strcmp_802ef234(Ptr32<const char>,Ptr32<const char>);
extern "C" int cx9c_name_greater_8010e698(Ptr32<Ptr32<const char> const>,Ptr32<Ptr32<const char> const>);
extern "C" Ptr32<Ptr32<const char>> w3d_cx9c_binary_name_find_80347194(Ptr32<Ptr32<const char>> base,int count,Ptr32<Ptr32<const char> const> key) {
 Ptr32<Ptr32<const char>> first=base; Ptr32<Ptr32<const char>> last=base+count;
 if(count)do {
  unsigned int length=last-first;Ptr32<Ptr32<const char>> middle=first+(length>>1);
  if(middle-base>=count)return middle;
  if(cx9c_strcmp_802ef234(*middle,*key)<0)first=middle+1;
  else if(!cx9c_name_greater_8010e698(middle,key))return middle;
  else last=middle-1;
 }while(first<=last);
 return first;
}


