// GWMP8P rev0 0x8000affc. Issues the command sequence for a planned weapon
// shot from its flag word: optional waits, aim, selection, positioning,
// delay, fire and finish. Field names are inferred.
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    Vec operator*(float s) const { Vec r; r.x = x * s; r.y = y * s; r.z = z * s; return r; }
    Vec operator+(const Vec &o) const { Vec r; r.x = x + o.x; r.y = y + o.y; r.z = z + o.z; return r; }
};
struct Handle { int kind; void *object; };
struct Body { char unknown00[8]; int part; };
struct BodyList { Body **start; Body *&operator[](int i) { return start[i]; } };
struct Settings { char unknown00[48]; float settle; char unknown34[100]; float f152; char unknown9c[60]; float delay; };
struct WeaponPlan {
    char unknown00[16];
    int index16;
    int weapon;           /* +20 */
    Vec position;         /* +24 */
    Vec aim_vector;       /* +36 */
    Vec spot;             /* +48 */
    float power;          /* +60 */
    int unknown64;
    unsigned int flags;   /* +68 */
    int unknown72;
    void *first;          /* +76 */
    int unknown80;
    void *second;         /* +84 */
};
extern const char s_default_80369c14[], s_head_80369c1c[];
extern Settings *w3d_settings_804aa6d8;
extern BodyList *w3d_bodies_804aa750;
extern int g_wait_804aa58c, g_elapsed_804aa574;
extern Vec w3d_center_8041d3a0[];
extern "C" void w3d_command_create_19();
extern "C" void w3d_cx11a_command_finish_80009984(void **, int);
extern "C" void w3d_command_create_6(int);
extern "C" float cc24a_planner_influence_attenuation_800165cc(float, WeaponPlan *);
extern "C" void s19_randomize_three_80015910(Vec *, float);
extern "C" float cc25a_vector_elevation_angle_8001b734(Vec *);
extern "C" void w3d_command_create_1(int);
extern "C" void sol35a8_point_plan_8000831c(Vec *);
extern "C" void sol35a9_point_marker_80008098(Vec *);
extern "C" void w3d_command_create_3(int);
extern "C" void w3d_command_create_15(const char *);
extern "C" void sol35a9_point_plan11_v1_8000848c(const Vec *);
extern "C" void w3d_d17a_command_create_800085fc(float);
extern "C" void w3d_d17a_command_create_8000889c(float);
extern "C" void FUN_80007eac(Vec *);
extern "C" void w3d_d17a_command_create_16_80009014(int, float);
extern "C" void w3d_command_create_17(Vec *);
extern "C" int s19_weapons_dont_end_turn_800157cc();
extern "C" void w3d_command_create_7();
inline int Ms(float s) { return (int)(s * 1000.0f); }
extern "C" void w3d_d43a_weapon_plan_issue_8000affc(WeaponPlan *self, float power, int fuse)
{
    w3d_command_create_19();
    if (self->flags & 64) {
        if (self->first) w3d_cx11a_command_finish_80009984(&self->first, 1);
        w3d_command_create_6(500);
    } else if (!g_wait_804aa58c) {
        w3d_command_create_6(Ms(w3d_settings_804aa6d8->settle - (float)g_elapsed_804aa574 / 60.0f));
    }
    float spread = cc24a_planner_influence_attenuation_800165cc(power, self);
    Vec *v = &self->aim_vector;
    s19_randomize_three_80015910(v, spread);
    float angle = cc25a_vector_elevation_angle_8001b734(v);
    w3d_command_create_1(self->weapon);
    if (self->flags & 32) sol35a8_point_plan_8000831c(&self->spot);
    if (self->flags & 16) sol35a9_point_marker_80008098(&self->position);
    if (self->flags & 128) {
        w3d_command_create_3(1);
        w3d_command_create_15(s_default_80369c14);
    }
    if (self->flags & 2) {
        Vec o = w3d_center_8041d3a0[0] + self->aim_vector * 100000.0f;
        sol35a9_point_plan11_v1_8000848c(&o);
    }
    if (self->flags & 1024) sol35a9_point_plan11_v1_8000848c(&self->position);
    if (self->flags & 4096) w3d_command_create_15(s_head_80369c1c);
    if (self->flags & 4) w3d_d17a_command_create_800085fc(angle);
    if (self->flags & 8) w3d_d17a_command_create_8000889c(self->power);
    w3d_command_create_6((int)(w3d_settings_804aa6d8->delay * 1000.0f));
    if (self->flags & 1) FUN_80007eac(v);
    w3d_command_create_3(fuse);
    if (self->flags & 512) {
        w3d_d17a_command_create_16_80009014((*w3d_bodies_804aa750)[self->index16]->part, w3d_settings_804aa6d8->f152);
    }
    if (self->flags & 2048) w3d_command_create_17(&self->position);
    w3d_command_create_6(1000);
    if (self->flags & 4096) w3d_command_create_15(s_default_80369c14);
    if ((self->flags & 256) && self->second && !s19_weapons_dont_end_turn_800157cc())
        w3d_cx11a_command_finish_80009984(&self->second, 0);
    if (s19_weapons_dont_end_turn_800157cc()) w3d_command_create_7();
}
