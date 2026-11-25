#include "w3d_ptr.h"
#line 1 "cx16c_probe_stream_open_8021d8b4.cpp"

// Observed temporary is a 24-byte stream object at stack +8.
struct Cx16cTemporaryStream { unsigned words[6]; };
extern "C" Ptr32<void> cx16c_construct_80207fec(Ptr32<Cx16cTemporaryStream>);
extern "C" int cx16c_open_802080a0(Ptr32<Cx16cTemporaryStream>,Ptr32<void>,int);
extern "C" int cx16c_release_8020810c(Ptr32<Cx16cTemporaryStream>);
extern "C" void cx16c_destroy_8020803c(Ptr32<Cx16cTemporaryStream>,int);
extern "C" int w3d_cx16c_probe_stream_open_8021d8b4(Ptr32<void> source) {
 Cx16cTemporaryStream temp;
 cx16c_construct_80207fec(&temp);
 if(cx16c_open_802080a0(&temp,source,1)<0) {
  cx16c_destroy_8020803c(&temp,2);
  return 0;
 } else {
  cx16c_release_8020810c(&temp);
  cx16c_destroy_8020803c(&temp,2);
  return 1;
 }
}


