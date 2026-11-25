// d26c: 0x800d4584. Update an aim from digital and analogue input: wrap the yaw into 0..2 pi on the two turn buttons,
// apply the stick axes, then ease on the other two buttons. Names and Desc fields are inferred. The leading 0.0f of the
// pool stays extern (the owned pool starts 8-aligned at 2 pi).
struct Desc { char u0[88]; float zoom; char u92[20]; float scale; char u116[4]; float rate; char u124[40]; float roll; };
struct Input { unsigned buttons; int u4; int dx; int dy; };
struct Aim { char u0[136]; void *h136; char u140[36]; float yaw; float pitch; };
extern "C" void *empty_80341584(void *);
extern "C" Desc *desc_801797b4(void *);
extern "C" void ease_800d47f0(Aim *, int, float);
extern "C" void ease_800d4734(Aim *, int, float);
extern float zero_80388d04[];
extern "C" void d26c_aim_update_800d4584(Aim *self, Input *in, float dt) {
    Desc *d = desc_801797b4(empty_80341584(self->h136));
    if (in->buttons & 0x08000000) {
        float zero = zero_80388d04[0];
        float yaw = self->yaw - d->rate * dt;
        self->yaw = yaw;
        if (yaw < zero) {
            do yaw += 6.2831855f; while (yaw < zero);
            self->yaw = yaw;
        }
    }
    if (in->buttons & 0x04000000) {
        float yaw = d->rate * dt + self->yaw;
        self->yaw = yaw;
        if (yaw > 6.2831855f) {
            do yaw -= 6.2831855f; while (yaw > 6.2831855f);
            self->yaw = yaw;
        }
    }
    self->yaw -= (float)in->dx * d->rate * dt * d->scale;
    self->pitch -= (float)in->dy * d->zoom * dt * d->roll;
    if (in->buttons & 0x02000000 || in->dy) ease_800d47f0(self, 0, d->zoom * dt);
    if (in->buttons & 0x01000000 || in->dy) ease_800d4734(self, 0, d->zoom * dt);
}
