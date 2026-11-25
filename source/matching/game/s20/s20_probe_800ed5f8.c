typedef struct V3 { float x, y, z; } V3;
extern float lbl_8038b614[];
void w3d_s20_advance_position_800ed5f8(char *self) {
    V3 a;
    V3 b;
    V3 c;
    V3 *pos = (V3 *)(self + 48);
    V3 *vel = (V3 *)(self + 60);
    float k = lbl_8038b614[0];
    c.x = vel->x * k; c.y = vel->y * k; c.z = vel->z * k;
    b.x = c.x; b.y = c.y; b.z = c.z;
    c.x = pos->x + c.x; c.y = pos->y + c.y; c.z = pos->z + c.z;
    a.x = c.x; a.y = c.y; a.z = c.z;
    *pos = a;
}
