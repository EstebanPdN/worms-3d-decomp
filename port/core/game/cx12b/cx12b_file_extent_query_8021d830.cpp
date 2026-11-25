#include "w3d_ptr.h"
#line 1 "cx12b_file_extent_query_8021d830.cpp"

struct Stream {unsigned int words[6];};struct Extent {unsigned int value,opaque[3];};
extern "C" void construct_80207fec(Ptr32<Stream>);extern "C" int open_802080a0(Ptr32<Stream>,Ptr32<const char>,int);extern "C" void extent_802081c8(Ptr32<Stream>,Ptr32<Extent>);extern "C" int close_8020810c(Ptr32<Stream>);extern "C" void destroy_8020803c(Ptr32<Stream>,int);
extern "C" unsigned int w3d_cx12b_file_extent_query_8021d830(Ptr32<const char> path) {
 Stream s;construct_80207fec(&s);
 if(open_802080a0(&s,path,1)<0){destroy_8020803c(&s,2);return 0;}else{Extent out;extent_802081c8(&s,&out);close_8020810c(&s);unsigned int value=out.value;destroy_8020803c(&s,2);return value;}
}




