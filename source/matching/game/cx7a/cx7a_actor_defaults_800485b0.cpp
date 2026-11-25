
// Base occupies +0..+0x1b. Observed word fields have no confirmed names;
// +0x1c and +0x48 use invalid sentinel -1, the remaining words become zero.
struct Cx7aActor {void *vtable;unsigned char base[24];int slot1c,slot20,slot24,slot28,slot2c,slot30,slot34,slot38,slot3c,slot40,slot44,slot48,slot4c,slot50;};
extern unsigned char vtable_8040e978[];
extern "C" int base_8015fef0(Cx7aActor *);
extern "C" Cx7aActor *w3d_cx7a_actor_defaults_800485b0(Cx7aActor *self) {base_8015fef0(self);self->vtable=vtable_8040e978;self->slot20=0;self->slot24=0;self->slot34=0;self->slot38=0;self->slot3c=0;self->slot40=0;self->slot50=0;self->slot1c=-1;self->slot30=0;self->slot44=0;self->slot4c=0;self->slot28=0;self->slot48=-1;self->slot2c=0;return self;}
