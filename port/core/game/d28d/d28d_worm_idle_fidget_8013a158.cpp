#include "w3d_ptr.h"
#line 1 "d28d_worm_idle_fidget_8013a158.cpp"
// GWMP8P rev0 0x8013a158. Random worm idle fidget. Names are inferred from
// use and the speech strings. The play callee's argument order is chosen for
// the argument moves.
struct Mesh;
struct Obj { Ptr32<Ptr32<void>> vtable; };
struct Vec { float x, y, z; };
struct Service { Ptr32<Ptr32<void>> vtable; };
struct System { char u0[108]; Ptr32<Service> service; };
extern Ptr32<System> system_804b1788;
struct Worm { char u0[52]; Vec pos; char u40[48]; int index; char u74[356]; int cue472; char u1dc[16]; int cue492; char u1f0[36]; Ptr32<Obj> f532; char u218[200]; int f736; };
struct Info { char u0[170]; unsigned short hp; };
extern "C" Ptr32<void> registry_80343810();
extern "C" unsigned free_801981f8(Ptr32<void>);
extern "C" void reset_8013c54c(Ptr32<Worm>, Ptr32<Mesh>);
extern "C" int control_801817e0(Ptr32<Mesh>, int);
extern "C" int play_801359ec(Ptr32<Worm>, Ptr32<Mesh>, Ptr32<const char>, float, float, Ptr32<int>, float);
extern "C" unsigned rand_80162c20();
extern "C" Ptr32<Info> query_800fc6dc(int);
extern "C" void speak_8013bd0c(Ptr32<Worm>, Ptr32<const char>);
extern Ptr32<const char> n_804ab100; extern Ptr32<const char> n_804ab16c; extern Ptr32<const char> n_804ab1ec; extern Ptr32<const char> n_804ab1f0; extern Ptr32<const char> n_804ab1f4; extern Ptr32<const char> n_804ab1f8; extern Ptr32<const char> n_804ab1fc; extern Ptr32<const char> n_804ab200; extern Ptr32<const char> n_804ab204; extern Ptr32<const char> n_804ab208; extern Ptr32<const char> n_804ab20c; extern Ptr32<const char> n_804ab220; extern Ptr32<const char> n_804ab224; extern Ptr32<const char> n_804ab228; extern Ptr32<const char> n_804ab22c; extern Ptr32<const char> n_804ab230; extern Ptr32<const char> n_804ab234; extern Ptr32<const char> n_804ab238; extern Ptr32<const char> n_804ab23c; extern Ptr32<const char> n_804ab240; extern Ptr32<const char> n_804ab244; extern Ptr32<const char> n_804ab248; extern Ptr32<const char> n_804ab24c; extern Ptr32<const char> n_804af7e4; extern Ptr32<const char> n_804af7e8; extern Ptr32<const char> n_804af7ec;

inline void say(Ptr32<Service> s, Ptr32<Worm> self, Ptr32<const char> line) {
    ((Ptr32<void (Ptr32<Service>, Ptr32<const char>, Ptr32<Ptr32<Obj>>)>)s->vtable[23])(s, line, &self->f532);
    ((Ptr32<void (Ptr32<Obj>)>)self->f532->vtable[5])(self->f532);
    ((Ptr32<void (Ptr32<Obj>, int, Ptr32<const Vec>)>)self->f532->vtable[14])(self->f532, 3, &self->pos);
}
extern "C" void d28d_worm_idle_fidget_8013a158(Ptr32<Worm> self, Ptr32<Mesh> mesh, int full) {
    if (free_801981f8(registry_80343810()) <= 51199) {
        reset_8013c54c(self, mesh);
        control_801817e0(mesh, -1);
        play_801359ec(self, mesh, n_804ab100, 1.0f, 0.0f, &self->cue492, 0.0f);
        play_801359ec(self, mesh, n_804ab16c, 1.0f, -1.0f, &self->cue472, 0.0f);
        return;
    }
    if (free_801981f8(registry_80343810()) <= 0x18fff) full = 0;
    unsigned n;
    if (full && (rand_80162c20() & 3) == 0) n = rand_80162c20() % 23;
    else n = rand_80162c20() % 7;
    reset_8013c54c(self, mesh);
    control_801817e0(mesh, -1);
    play_801359ec(self, mesh, n_804ab100, 1.0f, 0.0f, &self->cue492, 0.0f);
    if (query_800fc6dc(self->index)->hp <= 49) {
        Ptr32<int> c = &self->cue472;
        play_801359ec(self, mesh, n_804ab1ec, 1.0f, -1.0f, c, 0.0f);
        play_801359ec(self, mesh, n_804ab1f0, 1.0f, -1.0f, c, 0.0f);
        play_801359ec(self, mesh, n_804ab1f4, 1.0f, -1.0f, c, 0.0f);
        return;
    }
    switch ((int)n) {
    case 0: play_801359ec(self, mesh, n_804ab1f8, 1.0f, -1.0f, &self->cue472, 0.0f); break;
    case 1: play_801359ec(self, mesh, n_804ab1fc, 1.0f, -1.0f, &self->cue472, 0.0f); break;
    case 2: play_801359ec(self, mesh, n_804ab200, 1.0f, -1.0f, &self->cue472, 0.0f); break;
    case 3: play_801359ec(self, mesh, n_804ab204, 1.0f, -1.0f, &self->cue472, 0.0f); break;
    case 4: play_801359ec(self, mesh, n_804ab208, 1.0f, -1.0f, &self->cue472, 0.0f); break;
    case 5: play_801359ec(self, mesh, n_804ab20c, 1.0f, -1.0f, &self->cue472, 0.0f); break;
    case 6: if (self->f736) play_801359ec(self, mesh, n_804ab244, 1.0f, -1.0f, &self->cue472, 0.0f); break;
    case 7: play_801359ec(self, mesh, n_804ab220, 1.0f, -1.0f, &self->cue472, 0.0f); { Ptr32<Service> s = system_804b1788->service; if (s) say(s, self, "Worm.HeadScratch"); } break;
    case 8: play_801359ec(self, mesh, n_804ab224, 1.0f, -1.0f, &self->cue472, 0.0f); { Ptr32<Service> s = system_804b1788->service; if (s) say(s, self, "Worm.Wriggle"); } break;
    case 9: play_801359ec(self, mesh, n_804ab228, 1.0f, -1.0f, &self->cue472, 0.0f); { Ptr32<Service> s = system_804b1788->service; if (s) say(s, self, "Worm.Brows"); } break;
    case 10: play_801359ec(self, mesh, n_804ab22c, 1.0f, -1.0f, &self->cue472, 0.0f); break;
    case 11: play_801359ec(self, mesh, n_804ab230, 1.0f, -1.0f, &self->cue472, 0.0f); { Ptr32<Service> s = system_804b1788->service; if (s) say(s, self, "Worm.Flap"); } break;
    case 12: case 13: play_801359ec(self, mesh, n_804ab234, 1.0f, -1.0f, &self->cue472, 0.0f); { Ptr32<Service> s = system_804b1788->service; if (s) say(s, self, "Worm.Nips"); } break;
    case 14: case 15: play_801359ec(self, mesh, n_804ab238, 1.0f, -1.0f, &self->cue472, 0.0f); break;
    case 16: play_801359ec(self, mesh, n_804ab23c, 1.0f, -1.0f, &self->cue472, 0.0f); { Ptr32<Service> s = system_804b1788->service; if (s) say(s, self, "Worm.Periscope"); } break;
    case 17: play_801359ec(self, mesh, n_804ab240, 1.0f, -1.0f, &self->cue472, 0.0f); { Ptr32<Service> s = system_804b1788->service; if (s) say(s, self, "Worm.Periscope"); } break;
    case 18: play_801359ec(self, mesh, n_804af7e4, 1.0f, -1.0f, &self->cue472, 0.0f); speak_8013bd0c(self, "Yawn"); break;
    case 19: play_801359ec(self, mesh, n_804af7e8, 1.0f, -1.0f, &self->cue472, 0.0f); { Ptr32<Service> s = system_804b1788->service; if (s) say(s, self, "Worm.Tash"); } break;
    case 20: play_801359ec(self, mesh, n_804af7ec, 1.0f, -1.0f, &self->cue472, 0.0f); speak_8013bd0c(self, "Sneeze"); break;
    case 21: play_801359ec(self, mesh, n_804ab248, 1.0f, -1.0f, &self->cue472, 0.0f); break;
    case 22: play_801359ec(self, mesh, n_804ab24c, 1.0f, -1.0f, &self->cue472, 0.0f); break;
    }
}


