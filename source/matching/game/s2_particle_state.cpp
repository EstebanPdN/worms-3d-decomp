/* Bounded particle-state construction and coordinate helpers. */
extern "C" {
struct S2ParticleVec { float x, y, z; void zero(float value) { x = z = y = value; } };
struct S2ParticleVirtual { void (**vtable)(S2ParticleVirtual *); };
struct S2Particle {
    void *vtable; unsigned char pad04[32]; int state36; unsigned char pad28[216];
    void *secondaryVtable; unsigned char pad104[44]; unsigned int flags;
    S2ParticleVec minimum, maximum, center;
    unsigned char color344, color345; unsigned short pad346;
    S2ParticleVec offset;
    int handle; S2ParticleVirtual *resource;
    unsigned int extentX, extentY, extentZ;
    float value380; int mode;
};
struct S2ParticleRegistry { unsigned char pad00[34]; unsigned short count; };
struct S2ParticleMessage { unsigned short id, reserved; void *vtable; };
void *w3d_auto_800de930(unsigned int);
void w3d_auto_800de958(void *);
S2Particle *w3d_fn_80106bd0(S2Particle *);
void w3d_state_register(S2ParticleRegistry *, void *);
void w3d_fn_800e0678(S2Particle *);
void w3d_fn_800e06fc(S2Particle *, int);
extern S2ParticleRegistry w3d_obj_80361110[];
extern unsigned char w3d_obj_8040ffb8[], w3d_obj_804106d0[], w3d_obj_8040db38[];
extern const float w3d_f32_80399ac0[], w3d_f32_80399ac4[];
extern S2ParticleVec w3d_obj_8044becc[], w3d_obj_8044bec0[];
extern int w3d_obj_804b1850;

S2Particle *w3d_particle_create_80106afc()
{
    S2Particle *object = w3d_fn_80106bd0((S2Particle *)w3d_auto_800de930(388));
    w3d_state_register(w3d_obj_80361110, object ? (char *)object + 4 : 0);
    w3d_obj_80361110->count++;
    return object;
}


S2Particle *w3d_fn_80106bd0(S2Particle *self)
{
    struct { unsigned int first, second; } scratch;
    w3d_fn_800e0678(self);
    float zero = w3d_f32_80399ac0[0];
    self->secondaryVtable = w3d_obj_8040ffb8;
    self->vtable = w3d_obj_804106d0;
    self->state36 = 0;
    self->color344 = 255;
    self->resource = 0;
    self->flags = 0;
    self->color345 = 255;
    self->offset.zero(zero);
    self->handle = -1;
    self->center.zero(zero);
    self->extentZ = 200;
    self->value380 = w3d_f32_80399ac4[0];
    self->mode = 2;
    self->extentX = 200;
    self->extentY = 200;
    return self;
}


void w3d_particle_destroy_80106c88(S2Particle *self, int flags)
{
    self->secondaryVtable = w3d_obj_8040ffb8;
    self->vtable = w3d_obj_804106d0;
    if (self->resource) self->resource->vtable[4](self->resource);
    w3d_fn_800e06fc(self, 0);
    if (flags & 1) w3d_auto_800de958(self);
}


int w3d_particle_wrap_80107ab8(S2Particle *self, S2ParticleVec *point)
{
    int wrapped = 0;
    if (point->x >= self->maximum.x) {
        while (point->x > self->maximum.x) point->x -= (float)(self->extentX + self->extentX);
    } else if (point->x <= self->minimum.x) {
        while (point->x < self->minimum.x) point->x += (float)(self->extentX + self->extentX);
    }
    if (point->y > self->maximum.y) {
        while (point->y > self->maximum.y) point->y -= (float)(self->extentY + self->extentY);
        wrapped = 1;
    } else if (point->y < self->minimum.y) {
        while (point->y < self->minimum.y) point->y += (float)(self->extentY + self->extentY);
        wrapped = 1;
    }
    if (point->z > self->maximum.z) {
        while (point->z > self->maximum.z) point->z -= (float)(self->extentZ + self->extentZ);
    } else if (point->z < self->minimum.z) {
        while (point->z < self->minimum.z) point->z += (float)(self->extentZ + self->extentZ);
    }
    return wrapped;
}


void w3d_particle_update_bounds_80107ccc(S2Particle *self)
{
    S2ParticleVec extent;
    S2ParticleVec low, high;
    extent.x = (float)self->extentX;
    extent.y = (float)self->extentY;
    extent.z = (float)self->extentZ;
    low.x = self->center.x - extent.x;
    high.x = self->center.x + extent.x;
    low.y = self->center.y - extent.y;
    high.y = self->center.y + extent.y;
    high.z = self->center.z + extent.z;
    low.z = self->center.z - extent.z;
    self->minimum.x = low.x;
    self->maximum.x = high.x;
    self->minimum.y = low.y;
    self->maximum.y = high.y;
    self->maximum.z = high.z;
    self->minimum.z = low.z;
}


S2ParticleMessage *w3d_particle_vector_message_80108154(S2ParticleMessage *self, unsigned short id, int handle, const S2ParticleVec *first, const S2ParticleVec *second)
{
    self->id = id;
    self->vtable = w3d_obj_8040db38;
    *w3d_obj_8044becc = *first;
    *w3d_obj_8044bec0 = *second;
    w3d_obj_804b1850 = handle;
    return self;
}

}
