typedef struct K2aRef { void **vtable; } K2aRef;
typedef struct K2aStateOwner { char pad0[164]; K2aRef *held; char pad_a8[516]; unsigned int state; } K2aStateOwner;

void k2a_state_release_8013f1c0(K2aStateOwner *self)
{
    switch (self->state) {
    case 1: case 2: case 5: case 6:
    case 0x14: case 0x15: case 0x22: case 0x24:
        if (self->held != 0)
            ((void (*)(K2aRef *))self->held->vtable[4])(self->held);
        self->held = 0;
        break;
    default:
        break;
    }
}
