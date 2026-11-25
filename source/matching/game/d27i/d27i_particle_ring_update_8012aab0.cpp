// GWMP8P rev0 0x8012aab0. Particle update: the first 100 slots grow and fade
// with age and respawn at a random source point with a spinning angle; the
// other 50 only fade and are parked with an old time.
struct Mesh;
struct V3 { float x, y, z; void set(float a, float b, float c) { x = a; y = b; z = c; } };
struct V2 { float x, y; };
inline V2 &at(V2 *t, unsigned short k) { return *(V2 *)((k << 3) + (char *)t); }
struct Rgba { unsigned char r, g, b, a; };
struct Info { unsigned short count; char u2[54]; };
struct Source;
struct SourceVt { char u0[40]; V2 *(*points)(Source *, Info *); };
struct Source { char u0[2792]; SourceVt *vt; };
struct Particles { char u0[328]; unsigned times[150]; char u928[0]; Mesh *mesh; char u932[8]; unsigned last; };
extern Source *source_804b183c;
extern "C" V3 *pos_80189518(Mesh *);
extern "C" unsigned *col_80189760(Mesh *);
extern "C" V2 *size_8018963c(Mesh *);
extern "C" float *rot_80189574(Mesh *);
extern "C" unsigned rnd_8015ff5c(Particles *);
extern "C" int d27i_particle_ring_update_8012aab0(Particles *self, unsigned now) {
    Source *src = source_804b183c;
    if (src) {
        Info info;
        V2 *pts = src->vt->points(src, &info);
        if (pts) {
            Mesh *m = self->mesh;
            unsigned short i = 0;
            V3 *pos = pos_80189518(m);
            unsigned *col = col_80189760(m);
            V2 *size = size_8018963c(m);
            float *rot = rot_80189574(m);
            float angle = (float)(rnd_8015ff5c(self) % 360) * 3.14159274f / 180.0f;
            do {
                unsigned age = now - self->times[i];
                if (age <= 2047) {
                    float s = (float)age * 0.01f;
                    size[i].x = s;
                    size[i].y = s;
                    ((Rgba *)&col[i])->a = 255 - (age >> 3);
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
                    ((Rgba *)&col[i])->a = 255 - (age >> 3);
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
