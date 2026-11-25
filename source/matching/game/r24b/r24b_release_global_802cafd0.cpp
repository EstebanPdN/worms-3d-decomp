// desc: Invoke virtual release slot +0x10 if global is nonnull, then clear two global words; names inferred.
// Observed: held interface global 0x804b10b0, virtual slot +0x10,
// trailing global 0x804abce4 reset to zero. Owners remain external.
struct R24bReleaseObject;
struct R24bReleaseVtable {
    void (*unknown_00[4])();
    void (*release)(R24bReleaseObject *self);
};
struct R24bReleaseObject { const R24bReleaseVtable *vtable; };
extern "C" R24bReleaseObject *r24b_held_804b10b0;
extern "C" unsigned r24b_state_804abce4;
extern "C" void w3d_r24b_release_global_802cafd0()
{
    if (r24b_held_804b10b0)
        r24b_held_804b10b0->vtable->release(r24b_held_804b10b0);
    r24b_held_804b10b0 = 0;
    r24b_state_804abce4 = 0;
}
