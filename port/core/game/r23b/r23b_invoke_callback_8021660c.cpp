#include "w3d_ptr.h"
#line 1 "r23b_invoke_callback_8021660c.cpp"
// desc: Invoke the no-argument callback at +0x14 of the global callback block; names inferred.
// Global pointee ownership and callback behavior remain external. No implicit object argument is observed.
struct R23bCallbackBlock { unsigned unknown[5]; Ptr32<void (void)> invoke; };
extern Ptr32<R23bCallbackBlock> r23b_callbacks_804aba74;
extern "C" void w3d_r23b_invoke_callback_8021660c() { r23b_callbacks_804aba74->invoke(); }


