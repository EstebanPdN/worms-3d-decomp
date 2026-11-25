// Partial interface: virtual slots at +12 and +16 retain and release a reference.
struct Ref { virtual void reserved(); virtual void retain(); virtual void release(); };
struct Owner { char unknown[32]; unsigned flags; Ref *held; void attach(Ref *p) { held = p; } };
extern "C" int r27b_attach_801f3044(Owner *owner, Ref *incoming) {
    if (incoming) incoming->retain();
    if (owner->held) owner->held->release();
    owner->attach(incoming);
    owner->flags &= 0x7fffffff;
    return 0;
}
