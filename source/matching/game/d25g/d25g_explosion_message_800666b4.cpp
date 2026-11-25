/* Worms 3D GameCube PAL 0x800666b4. Fills an explosion message: message id and type table, position and impulse vectors, five floats. Doubles the five floats when the DoubleDamage setting is 1, then publishes the original position, impulse and floats to the Explosion.* settings. Returns the message. Field and type names are inferred from the original instructions; strings and globals are external views of original data. */
struct MessageCache { unsigned short id; unsigned char unknown[6]; };
struct Vec3 { float x, y, z; };
struct Key { const char *text; Key(const char *t) { text = t; } };
extern MessageCache msg_804ad5a8;
extern char vt_8040db38[];
extern const char s_80379f74[], s_80379f84[], s_80379fa0[], s_80379fbc[], s_80379fdc[], s_80379ff8[], s_8037a014[], s_8037a030[];
extern "C" int message_id_8015f5a0(MessageCache *, int);
extern "C" int read_int_800fc1f0(Key *, int *);
extern "C" int write_vec_800fc5dc(Key *, const Vec3 *);
extern "C" int write_float_800fc4c8(Key *, float);
struct Explosion {
    unsigned short id;
    const void *vtable;
    Vec3 position;
    Vec3 impulse;
    float wormDamage, impulseScale, wormRadius, landRadius, impulseRadius;
};
extern "C" Explosion *w3d_d25g_explosion_message_800666b4(Explosion *self, const Vec3 &p, const Vec3 &i, float a, float b, float c, float d, float e)
{
    self->id = message_id_8015f5a0(&msg_804ad5a8, 1);
    self->vtable = vt_8040db38;
    self->position = p;
    self->impulse = i;
    self->wormDamage = a;
    self->impulseScale = b;
    self->wormRadius = c;
    self->landRadius = d;
    self->impulseRadius = e;
    int doubled;
    { Key k(s_80379f74); read_int_800fc1f0(&k, &doubled); }
    if (doubled == 1) {
        self->wormDamage += self->wormDamage;
        self->impulseScale += self->impulseScale;
        self->wormRadius += self->wormRadius;
        self->landRadius += self->landRadius;
        self->impulseRadius += self->impulseRadius;
    }
    { Key k(s_80379f84); write_vec_800fc5dc(&k, &p); }
    { Key k(s_80379fa0); write_vec_800fc5dc(&k, &i); }
    { Key k(s_80379fbc); write_float_800fc4c8(&k, a); }
    { Key k(s_80379fdc); write_float_800fc4c8(&k, b); }
    { Key k(s_80379ff8); write_float_800fc4c8(&k, c); }
    { Key k(s_8037a014); write_float_800fc4c8(&k, d); }
    { Key k(s_8037a030); write_float_800fc4c8(&k, e); }
    return self;
}
