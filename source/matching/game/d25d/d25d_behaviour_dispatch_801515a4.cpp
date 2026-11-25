// GWMP8P rev0 0x801515a4. Worm AI behaviour step: clear the movement and
// input fields, then, when a behaviour is active, run the handler for its
// kind (2, 5, 7..16) with an output vector. Store the x and z of the result
// as the move input, clamping the length of that horizontal vector to 1.
// Names are inferred.
struct V3 { float x, y, z;
  V3() {}
  V3(float a, float b, float c) { x = a; y = b; z = c; }
  float len2() const { return x * x + y * y + z * z; }
  void scale(float k) { x *= k; y *= k; z *= k; }
};
struct Self { char pad[304]; int behaviour; int kind; char pad2[276]; float mx; float mz; int f596; int f600; char pad3[8]; int f612; int f616; int f620; int f624; char pad4[4]; int f632; int f636; char pad5[96]; int f736; };
extern "C" void w3d_actor_c_8015287c(Self *);
extern "C" void f6b_aim_80151784(Self *, V3 *);
extern "C" void f5b_choose_801518f8(Self *, V3 *);
extern "C" void d24d_aim_update_80151a14(Self *, V3 *);
extern "C" void w3d_actor_c_80151c78(Self *, V3 *);
extern "C" void f6b_height_80151d64(Self *, V3 *);
extern "C" void fn_80151ea4(Self *, V3 *);
extern "C" void fn_80152474(Self *, V3 *);
extern "C" void w3d_empty_80152690(Self *, V3 *);
extern "C" void w3d_actor_c_80152694(Self *, V3 *);
extern "C" void d15d_actor_80152730(Self *, V3 *);
extern "C" float sqrtf_802e82c0(float);
extern "C" void d25d_behaviour_dispatch_801515a4(Self *self) {
    w3d_actor_c_8015287c(self);
    self->f632 = 0; self->f636 = 0; self->f616 = 0; self->f612 = 0; self->f620 = 0; self->f624 = 0; self->f736 = 0; self->f600 = 0;
    self->mz = 0.0f; self->mx = 0.0f;
    self->f596 = 0;
    V3 v(0.0f, 0.0f, 0.0f);
    if (self->behaviour) {
        switch (self->kind) {
        case 5: f6b_aim_80151784(self, &v); break;
        case 2: f5b_choose_801518f8(self, &v); break;
        case 7: d24d_aim_update_80151a14(self, &v); break;
        case 8: case 9: case 10: w3d_actor_c_80151c78(self, &v); break;
        case 11: f6b_height_80151d64(self, &v); break;
        case 12: fn_80151ea4(self, &v); break;
        case 13: fn_80152474(self, &v); break;
        case 14: w3d_empty_80152690(self, &v); break;
        case 15: w3d_actor_c_80152694(self, &v); break;
        case 16: d15d_actor_80152730(self, &v); break;
        }
    }
    self->mx = v.x;
    self->mz = v.z;
    V3 t(v.x, 0.0f, v.z);
    float l = t.len2();
    if (l > 1.0f) t.scale(1.0f / sqrtf_802e82c0(l));
    self->mx = t.x;
    self->mz = t.z;
}
