#include "w3d_ptr.h"
#line 1 "f1p_pool_write_scaled_entry_80264348.cpp"
// Observed pool-entry update at 0x80264348. Names and layouts inferred.
// The empty local object preserves the original stack reservation; no assembly.
// Constants remain original external data, not owned by this source unit.
struct Vec2 { float x,y; };
extern "C" Ptr32<void> fn_8015ae3c(Ptr32<void>);
extern "C" Ptr32<void> fn_80343808(Ptr32<void>);
extern "C" int fn_80171ee0(Ptr32<void>,int);
extern "C" Ptr32<void> fn_80171fa0(Ptr32<void>);
extern "C" void fn_8020c5c4(Ptr32<void>);
extern "C" void fn_80341588(Ptr32<void>);
extern float value_803cb280[];
extern float value_803cb284[];
extern "C" void w3d_pool_write_scaled_entry_80264348(Ptr32<void> name,int index,float value) {
    struct Pad { int x,y; Pad() {} ~Pad() {} }; Pad padding;
    Ptr32<void> pool=fn_80343808(fn_8015ae3c(name));
    fn_80171ee0(pool,79);
    Ptr32<void> entries=fn_80171fa0(pool);
    Vec2 pair; pair.y=value*value_803cb280[0]; pair.x=value_803cb284[0];
    *(Ptr32<float>)((Ptr32<char>)entries+index*8)=pair.x;
    *(Ptr32<float>)((Ptr32<char>)entries+index*8+4)=pair.y;
    fn_8020c5c4(name);
    fn_80341588(name);
}


