// desc: Prepare when flag 0x200000 is clear, then invoke the callback at +0x18 without arguments; names inferred.
// Observed: callback pointer at +0x18, flags at +0x20.
// External preparation and callback ownership/signature beyond no arguments
// at this call site remain unresolved; the callback is not null-checked.
struct R24bReadyObject {
    unsigned char unknown_00[0x18];
    void (*callback)();
    unsigned unknown_1c;
    unsigned flags;
};
extern "C" int r24b_prepare_80210370(R24bReadyObject *self);
extern "C" void w3d_r24b_invoke_ready_callback_8020fcb4(R24bReadyObject *self)
{
    if (!(self->flags & 0x200000u))
        r24b_prepare_80210370(self);
    self->callback();
}
