#include "w3d_ptr.h"
#line 1 "f17a_construct_box_802946f0.cpp"
// Inferred factory-bounded220-byte external owner; unknown fields remain uninitialized.
struct F17aBoxBase_8015fef0{Ptr32<Ptr32<void>> table;char unknown[24];F17aBoxBase_8015fef0();};
struct F17aBoxText_803426b8{Ptr32<char> p;F17aBoxText_803426b8();};
struct F17aBoxHeld{Ptr32<void> p;F17aBoxHeld():p(0){}};
struct F17aBoxVec{unsigned x,y,z;};
struct F17aBoxPrefix:F17aBoxBase_8015fef0{unsigned word28 __attribute__((aligned(__alignof__(F17aBoxBase_8015fef0))));F17aBoxVec pos;unsigned unknown44;float scale48;unsigned unknown52,word56,word60,word64,word68,word72,word76;float value80,value84,value88,value92;unsigned unknown96[4];float value112,value116;F17aBoxHeld slots120,slots124,slots128,slots132,slots136,slots140,slots144,slots148,slots152,slots156;unsigned unknown160[3],word172;F17aBoxPrefix();};
extern char table_8041c230[];
inline F17aBoxPrefix::F17aBoxPrefix(){table=(Ptr32<Ptr32<void>>)table_8041c230;}
struct F17aBox:F17aBoxPrefix{F17aBoxText_803426b8 title __attribute__((aligned(__alignof__(F17aBoxPrefix))));unsigned word180;F17aBoxHeld slot184,slot188,slot192,slot196,slot200,slot204,slot208,slot212,slot216;F17aBox();};
extern const F17aBoxVec vec_8045e788[];extern const float scalar_803d0768[],scalar_803d076c[],scalar_803d0770[],scalar_803d0774[];
F17aBox::F17aBox(){pos=vec_8045e788[0];scale48=scalar_803d0768[0];word56=0;word76=1;word172=1;word180=-1;value84=scalar_803d0770[0];value88=scalar_803d0774[0];word60=0;word64=0;word28=0;word72=0;word68=0;float scalar=scalar_803d076c[0];value80=scalar;value92=scalar;value112=scalar;value116=scalar;}


