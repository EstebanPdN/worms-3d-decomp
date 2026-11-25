#include "w3d_ptr.h"
#line 1 "cx7b_text_copy_terminated_80217c6c.cpp"
// Observed three arguments: destination, source, and a char terminator.
extern "C" unsigned int strlen(Ptr32<const char>);
extern "C" Ptr32<void> memcpy(Ptr32<void>,Ptr32<const void>,unsigned int);
extern "C" Ptr32<char> w3d_cx7b_text_copy_terminated_80217c6c(Ptr32<char> destination,Ptr32<const char> source,int terminator) {
 unsigned int size=strlen(source); memcpy(destination,source,size);
 destination+=size; *destination=terminator;
 if((signed char)terminator) ++destination;
 return destination;
}



