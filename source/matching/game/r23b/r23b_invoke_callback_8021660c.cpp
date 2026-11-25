// desc: Invoke the no-argument callback at +0x14 of the global callback block; names inferred.
// Global pointee ownership and callback behavior remain external. No implicit object argument is observed.
struct R23bCallbackBlock { unsigned unknown[5]; void (*invoke)(); };
extern R23bCallbackBlock *r23b_callbacks_804aba74;
extern "C" void w3d_r23b_invoke_callback_8021660c() { r23b_callbacks_804aba74->invoke(); }
