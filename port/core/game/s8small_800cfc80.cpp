#include "w3d_ptr.h"
#line 1 "s8small_800cfc80.cpp"
struct s8_TestObject { char pad0[44]; int value; };
extern "C" int s8_field_test_800cfc80(Ptr32<const s8_TestObject> p) { int result=0; if(p->value) result=1; return result; }


