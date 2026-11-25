#include "w3d_ptr.h"
#line 1 "d40c_message_handler_800fda04.cpp"
// d40c: 0x800fda04. Logic message handler: start, stop, and on the hit id a
// forwarded effect whose alpha comes from the motion value. Each case
// returns through the base handler.
struct Message { unsigned short id; unsigned short Id() const { return id; } };
struct Vec3 { float x, y, z; };
struct Logic { unsigned char u[4]; };
extern "C" int base_8016293c(Ptr32<Logic>, Ptr32<Message>);
extern "C" void start_800fdc34(Ptr32<Logic>);
extern "C" void stop_800fdc7c(Ptr32<Logic>);
extern "C" int id_equals_8015f65c(unsigned short, Ptr32<int>);
extern "C" float motion_800668fc(Ptr32<Message>);
extern "C" void velocity_800668b8(Ptr32<Vec3>, Ptr32<Message>);
extern "C" int forward_800fdc80(int, int, Ptr32<Vec3>, int, int, int);
extern int cache_804af13c;
extern const float k_80398144[];
extern "C" int d40c_message_handler_800fda04(Ptr32<Logic> self, Ptr32<Message> m) {
    switch (m->Id()) {
    case 64:
        if (base_8016293c(self, m) >= 0) {
            start_800fdc34(self);
            return 0;
        }
        return 0x80004005;
    case 66:
        stop_800fdc7c(self);
        return base_8016293c(self, m);
    default:
        if (id_equals_8015f65c(m->Id(), &cache_804af13c)) {
            float v = motion_800668fc(m) * k_80398144[0];
            v = v + v;
            int a;
            if (v < k_80398144[0]) a = (unsigned char)v;
            else a = 255;
            Vec3 p;
            velocity_800668b8(&p, m);
            forward_800fdc80(0, a, &p, 500, -1, -1);
        }
        break;
    }
    return base_8016293c(self, m);
}


