struct K7aBoundsOwner
{
    char pad0[308];
    float min_x;        // +308
    float min_z;        // +312
    float min_y;        // +316
    float max_x;        // +320
    float max_z;        // +324
    float max_y;        // +328
    float center_x;     // +332
    float center_z;     // +336
    float center_y;     // +340
    char pad344[24];
    unsigned int half_x;    // +368
    unsigned int half_z;    // +372
    unsigned int half_y;    // +376
};

extern "C" void w3d_k7a_bounds_expand_80107ccc(K7aBoundsOwner *self)
{
    volatile char frame_pad[32];
    float hx = (float)self->half_x;
    float hz = (float)self->half_z;
    float hy = (float)self->half_y;
    self->min_x = self->center_x - hx;
    self->max_x = self->center_x + hx;
    self->min_z = self->center_z - hz;
    self->max_z = self->center_z + hz;
    self->min_y = self->center_y - hy;
    self->max_y = self->center_y + hy;
}
