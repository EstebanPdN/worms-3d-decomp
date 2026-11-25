struct T264Interface {
    void **vtable;
};
struct T264Holder {
    char unknown[32];
    unsigned flags;
    T264Interface *held;
};
extern "C" int t264_iface_801f3044(T264Holder *self, T264Interface *value)
{
    if (value)
        ((void (*)(T264Interface *))value->vtable[3])(value);
    if (self->held)
        ((void (*)(T264Interface *))self->held->vtable[4])(self->held);
    self->flags &= 0x7fffffff;
    self->held = value;
    return 0;
}
