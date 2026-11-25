#include "w3d_ptr.h"
#line 1 "d25d_worm_camera_bob_8014e170.cpp"
// GWMP8P rev0 0x8014e170. Worm flight or fall update: with upward speed
// above zero read the Worm.EyeLevelOffset setting, offset the position by
// it, add a 4.0 radius sine and cosine bob on the shared phase, send it to
// the camera if there is one, and either reverse the speed or post a land-
// clear message when fewer than 21 contacts exist. Otherwise, when grounded
// or dead, post the landing message, run landing 0x8014b498 and pick state 0
// or 9. Names are inferred; the two unused vectors are real dead stores in
// the original.
struct Vec { float x, y, z; Vec() {} Vec(float a, float b, float c) { x = a; y = b; z = c; } Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; } };
struct WordsV { int a, b, c; };
struct Key { Ptr32<const char> text; };
struct Worm {
    unsigned char u0[560]; Vec pos;
    unsigned char u572[104]; int vel0; float vel1; int vel2;
    unsigned char u688[28]; int grounded;
    unsigned char u720[40]; int state;
    unsigned char u764[60]; int health;
    unsigned char u828[324]; char coll[52]; char lim[156]; Ptr32<void> res;
};
struct Message { short id; Ptr32<const void> vt; };
extern "C" int setting_800fc270(Ptr32<Key>, Ptr32<void>);
extern "C" float w3d_cx9c_sinf_802e88ac(float);
extern "C" float w3d_cx9c_cosf_802e86d4(float);
extern "C" void pair_8005200c(Ptr32<void>, Ptr32<Vec>);
extern "C" unsigned coll_count_80141554(Ptr32<void>);
extern "C" int coll_a_80141574(Ptr32<void>);
extern "C" int coll_b_8014156c(Ptr32<void>);
extern "C" int res_80178d1c(Ptr32<void>);
extern "C" Ptr32<void> arena_801613f0(Ptr32<void>, int);
extern "C" Ptr32<void> clear_msg_801040d0(Ptr32<void>, int, int);
extern "C" int post_8016239c(Ptr32<void>);
extern "C" short msgid_8015f5a0(Ptr32<void>, int);
extern "C" void landing_8014b498(Ptr32<Worm>);
extern "C" int contact_801418c4(Ptr32<void>);
extern "C" int limit_8014c89c(Ptr32<void>);
extern "C" int check_80146b84(Ptr32<Worm>);
extern Ptr32<void> arena_804b1754;
extern Ptr32<void> cam_804aaa10;
extern float phase_804ab3ec;
extern int idcache_804afc10;
extern const unsigned char mvt_8040db38[];
extern const WordsV zero_8045e788[];
extern "C" void d25d_worm_camera_bob_8014e170(Ptr32<Worm> self) {
    Vec a(0.0f, 0.0f, 0.0f);
    Vec up(0.0f, 1.0f, 0.0f);
    Vec p = self->pos;
    if (self->vel1 > 0.0f) {
        { Key k; float off; k.text = "Worm.EyeLevelOffset"; setting_800fc270(&k, &off); p.y += off; }
        float s = w3d_cx9c_sinf_802e88ac(phase_804ab3ec);
        float r = 4.0f;
        p.x += s * r;
        float c = w3d_cx9c_cosf_802e86d4(phase_804ab3ec);
        p.z += c * r;
        if (cam_804aaa10) pair_8005200c(cam_804aaa10, &p);
        Ptr32<void> coll = self->coll;
        if (coll_count_80141554(coll) <= 20) {
            if (res_80178d1c(self->res)) {
                self->vel1 = -self->vel1;
            } else {
                int m = coll_a_80141574(coll);
                int n = coll_b_8014156c(coll);
                post_8016239c(clear_msg_801040d0(arena_801613f0(arena_804b1754, 8), m, n));
            }
            if (self->grounded) phase_804ab3ec = 0.0f;
            else phase_804ab3ec += 0.7853982f;
        }
    } else if (self->grounded || self->health < 0) {
        Ptr32<Message> m = (Ptr32<Message>)arena_801613f0(arena_804b1754, 8);
        m->id = msgid_8015f5a0(&idcache_804afc10, 1);
        m->vt = mvt_8040db38;
        post_8016239c(m);
        landing_8014b498(self);
        if ((self->grounded && contact_801418c4(self->coll) && limit_8014c89c(self->lim))
            || (self->health < 0 && check_80146b84(self))) {
            self->state = 0;
            *(Ptr32<WordsV>)&self->vel0 = zero_8045e788[0];
        } else self->state = 9;
    }
}


