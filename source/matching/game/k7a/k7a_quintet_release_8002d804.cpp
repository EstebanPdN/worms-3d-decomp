struct K7aPart { const void **vtable; };
struct K7aQuintet
{
    const void *vtable;
    unsigned short refs;     // +4
    char pad6[86];
    K7aPart *parts[5];       // +92
};
extern "C" const void *w3d_vtable_8040e430[];
extern "C" void w3d_registry_unlink_8002d734(K7aQuintet *self);
extern "C" void w3d_fn_8004dc38(K7aQuintet *self, int flags);

extern "C" unsigned short w3d_k7a_quintet_release_8002d804(K7aQuintet *self)
{
    unsigned short remaining = --self->refs;
    if (remaining == 0)
    {
        w3d_registry_unlink_8002d734(self);
        if (self)
        {
            self->vtable = w3d_vtable_8040e430;
            K7aPart **begin = self->parts;
            if (begin)
            {
                K7aPart **p = begin + 5;
                while (self->parts != p)
                {
                    p--;
                    if (*p)
                        ((void (*)(K7aPart *))(*p)->vtable[4])(*p);
                }
            }
            w3d_fn_8004dc38(self, 3);
        }
    }
    return remaining;
}
