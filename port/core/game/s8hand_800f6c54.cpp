#include "w3d_ptr.h"
#line 1 "s8hand_800f6c54.cpp"
struct s8_Adjustment { char pad0[64]; Ptr32<char> base; char pad68[18]; short offset; };
extern "C" Ptr32<char> s8_adjust_base_800f6c54(Ptr32<void> unused,Ptr32<const s8_Adjustment> p) { Ptr32<char> base=p->base; short offset=p->offset; return (Ptr32<char>)w3d::G((offset+(int)w3d::H(base))); }


