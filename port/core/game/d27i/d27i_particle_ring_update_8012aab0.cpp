#include "w3d_ptr.h"
#line 1 "d27i_particle_ring_update_8012aab0.cpp"
// GWMP8P rev0 0x8012aab0. Particle update: the first 100 slots grow and fade
// with age and respawn at a random source point with a spinning angle; the
// other 50 only fade and are parked with an old time.
struct Mesh;
struct V3 { float x, y, z; void set(float a, float b, float c) { x = a; y = b; z = c; } };
struct V2 { float x, y; };
inline V2 &at(Ptr32<V2> t, unsigned short k) { return *(Ptr32<V2>)((k << 3) + (Ptr32<char>)t); }
struct Rgba { unsigned char r, g, b, a; };
struct Info { unsigned short count; char u2[54]; };
struct Source;
struct SourceVt { char u0[40]; Ptr32<Ptr32<V2> (Ptr32<Source>, Ptr32<Info>)> points; };
struct Source { char u0[2792]; Ptr32<SourceVt> vt; };
struct Particles { char u0[328]; unsigned times[150]; char u928[0]; Ptr32<Mesh> mesh; char u932[8]; unsigned last; };
extern Ptr32<Source> source_804b183c;
extern "C" Ptr32<V3> pos_80189518(Ptr32<Mesh>);
extern "C" Ptr32<unsigned int> col_80189760(Ptr32<Mesh>);
extern "C" Ptr32<V2> size_8018963c(Ptr32<Mesh>);
extern "C" Ptr32<float> rot_80189574(Ptr32<Mesh>);
extern "C" unsigned rnd_8015ff5c(Ptr32<Particles>);
extern "C" int d27i_particle_ring_update_8012aab0(Ptr32<Particles> self, unsigned now) {
    Ptr32<Source> src = source_804b183c;
    if (src) {
        Info info;
        Ptr32<V2> pts = src->vt->points(src, &info);
        if (pts) {
            Ptr32<Mesh> m = self->mesh;
            unsigned short i = 0;
            Ptr32<V3> pos = pos_80189518(m);
            Ptr32<unsigned int> col = col_80189760(m);
            Ptr32<V2> size = size_8018963c(m);
            Ptr32<float> rot = rot_80189574(m);
            float angle = (float)(rnd_8015ff5c(self) % 360) * 3.14159274f / 180.0f;
            do {
                unsigned age = now - self->times[i];
                if (age <= 2047) {
                    float s = (float)age * 0.01f;
                    size[i].x = s;
                    size[i].y = s;
                    ((Ptr32<Rgba>)&col[i])->a = 255 - (age >> 3);
                    angle += 1.3f;
                } else {
                    unsigned short k = rnd_8015ff5c(self) % info.count;
                    self->times[i] = now;
                    rot[i] = angle;
                    col[i] = 0xffffffff;

pos[i].set(pts[k].x, pts[k].y, -0.5f);
                    size[i].x = 0.0f;
                    size[i].y = 0.0f;
                }
                i++;
            } while (i <= 99);
            i = 100;
            do {
                unsigned age = now - self->times[i];
                if (age <= 2047) {
                    float s = (float)age * 0.01f;
                    size[i].x = s;
                    size[i].y = s;
                    ((Ptr32<Rgba>)&col[i])->a = 255 - (age >> 3);
                } else {
                    size[i].x = 0.0f;
                    size[i].y = 0.0f;
                    self->times[i] = now - 2148;
                }
                i++;
            } while (i <= 149);
            self->last = now;
        }
    }
    return 0;
}


