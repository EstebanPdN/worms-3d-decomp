#include "w3d_ptr.h"
#line 1 "f15c_component_cleanup_80068648.cpp"
// GWMP8P rev0 native cleanup. External receiver prefix only; never allocated here.
// Factory8006849c allocates400 bytes; constructor80068570 constructs string arrays
// at160 and280, using the shared+120 member receiver. Four tail bytes are unmodeled.
// The shared240-byte group is inferred from constructor/destructor address lifetimes.
// Each string owns one pointer; each held interface is released through vtable+16.
extern "C" void finish_8020c5c4(Ptr32<void>),release_80341588(Ptr32<void>),handle_80126230(Ptr32<void>,int),base_8015ff2c(Ptr32<void>,int);
extern Ptr32<void> vtable_8040ef28[];
extern int selected_804aaa9c;
struct F15cHeldObject {Ptr32<Ptr32<void>> vtable;};
struct F15cHeld {Ptr32<F15cHeldObject> p;~F15cHeld(){if(p)((Ptr32<void (Ptr32<F15cHeldObject>)>)p->vtable[4])(p);}};
struct F15cDtorString {Ptr32<const char> text;~F15cDtorString(){finish_8020c5c4(this);release_80341588(this);}};
struct F15cStringGroup {char unknown0[40];F15cDtorString first[10];char unknown80[80];F15cDtorString second[10];char unknown200[40];};
struct F15cOwnerCleanup {
 Ptr32<Ptr32<void>> vtable;char unknown4[24];F15cHeld held28,held32;char unknown36[60];F15cHeld held96,held100;Ptr32<void> handle;F15cHeld held108;char unknown112[8];
 F15cStringGroup group120;char unknown360[4];F15cDtorString name364,name368;F15cHeld held372,held376,held380,held384,held388,held392;
 ~F15cOwnerCleanup(){vtable=vtable_8040ef28;selected_804aaa9c=0;if(handle){handle_80126230(handle,3);handle=0;}}
};
extern "C" void f15c_component_cleanup_80068648(Ptr32<F15cOwnerCleanup> self,int flags){self->~F15cOwnerCleanup();base_8015ff2c(self,flags);}


