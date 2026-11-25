struct K4aPropValue { int value; };
struct K4aOwner { char pad0[36]; void *holder_ref; unsigned int index_source; };
extern "C" unsigned int w3d_auto_80178c48(void *);
extern "C" void *w3d_empty_8034357c(void *);
extern "C" K4aPropValue FUN_800fd388(...);
extern "C" int FUN_80173df0(void *holder, K4aPropValue *value);

extern "C" void k4a_owner_apply_property_8003d0a0(K4aOwner *self)
{
    unsigned int index = w3d_auto_80178c48((void *)self->index_source);
    if (index <= 15) {
        void *holder = w3d_empty_8034357c(self->holder_ref);
        K4aPropValue value = FUN_800fd388(index);
        FUN_80173df0(holder, &value);
    }
}
