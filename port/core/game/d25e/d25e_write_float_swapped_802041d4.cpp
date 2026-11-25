#include "w3d_ptr.h"
#line 1 "d25e_write_float_swapped_802041d4.cpp"
// (Worms 3D GameCube PAL, 0x802041d4).
//
// Stream writer: byte-swaps a float's bit pattern and writes the 4 bytes
// through 0x802047e0, returning its status.

extern "C" unsigned fn_802047e0(Ptr32<void>, Ptr32<const void>, unsigned);
union FW { float f; unsigned u; };
inline float Swap(float v) { FW w; w.f = v; unsigned x = w.u; unsigned r = x; return *(Ptr32<float>)&r; }
extern "C" unsigned w3d_d25e_write_float_swapped_802041d4(Ptr32<void> self, float value) { float s = Swap(value); return fn_802047e0(self, &s, 4); }


