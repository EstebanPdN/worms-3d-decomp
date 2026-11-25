#include "w3d_ptr.h"
#line 1 "d30d_spawn_search_80158358.cpp"
// GWMP8P rev0 0x80158358. Spawn point search. Walks two parallel position
// sources until the first stops changing, sweeps down from each position and
// keeps those whose hit lies above the water level (plus five) on ground with an
// upward normal, appending hit and companion position to two growth-by-bytes
// vectors (same shape as 0x801f2e60). Posts a progress message each step and
// returns the number kept. Names are inferred.
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    Vec operator*(float k) const { Vec r; r.x = x * k; r.y = y * k; r.z = z * k; return r; }
    Vec operator-(const Vec &o) const { Vec r; r.x = x - o.x; r.y = y - o.y; r.z = z - o.z; return r; }
    float len2() const { return x * x + y * y + z * z; }
    bool operator==(const Vec &o) const { return *(Ptr32<const int>)&x == *(Ptr32<const int>)&o.x && *(Ptr32<const int>)&y == *(Ptr32<const int>)&o.y && *(Ptr32<const int>)&z == *(Ptr32<const int>)&o.z; }
};
struct Obj;
extern "C" {
Ptr32<void> alloc_80212fd4(unsigned);
void free_802134fc(Ptr32<void>);
Ptr32<void> memcpy(Ptr32<void>, Ptr32<const void>, unsigned, ...);
int read_float_800fc270(Ptr32<Ptr32<const char>>, Ptr32<float>);
Ptr32<Obj> cast_80342fa4(Ptr32<Obj>);
int set_vec_80178fa4(Ptr32<Obj>, Ptr32<const Vec>);
Ptr32<const Vec> get_vec_80178ec4(Ptr32<Obj>);
Ptr32<void> alloc_801613f0(Ptr32<void>, int);
short message_id_8015f5a0(Ptr32<int>, int);
Ptr32<void> message_init_800683fc(Ptr32<void>, unsigned short, Ptr32<const char>, int);
int post_8016239c(Ptr32<void>);
void sweep_800b0824(const Vec &, const Vec &, const Vec &, int, int);
void trace_800bd920();
float sqrtf_802e82c0(float);
}
static inline const int &maximum(const int &a, const int &b) { return a < b ? b : a; }
static inline const unsigned int &minimum(const unsigned int &a, const unsigned int &b) { return b < a ? b : a; }
struct Vecs {
    Ptr32<unsigned char> begin; Ptr32<unsigned char> end; Ptr32<unsigned char> capacity;
    void push(const Vec &value) {
        if (end == capacity) {
            unsigned int used = end - begin;
            unsigned int bytes = maximum((int)used + 1, (int)(used + (used >> 1))) * 12;
            Ptr32<unsigned char> data = (Ptr32<unsigned char>)alloc_80212fd4(bytes);
            if (begin) { memcpy(data, begin, minimum(bytes, used)); free_802134fc(begin); }
            begin = data; end = data + used; capacity = data + bytes;
        }
        *(Ptr32<Vec>)end = value; end += 12;
    }
};
struct Self { char u0[40]; Ptr32<Obj> f40; Ptr32<Obj> f44; };
extern Ptr32<void> heap_804b1754;
extern int hits_804b1764;
extern int traceReady_804b1784;
extern int cache_804afe90;
extern char water_803a2bf8[];
extern char spawn_803a2c3c[];
extern Vec hit_8043ae20[];
extern Vec normal_8043ae38[];
extern Vec zero_8045e788[];
extern "C" int d30d_spawn_search_80158358(Ptr32<Self> self, Ptr32<Vecs> a, Ptr32<Vecs> b) {
    Ptr32<const char> key = water_803a2bf8;
    float level;
    read_float_800fc270(&key, &level);
    int found = 0;
    Vec t;
    level += 5.0f;
    Vec pos(9999.0f, 9999.0f, 9999.0f);
    Vec down(0.0f, -1.0f, 0.0f);
    int n = 0;
    set_vec_80178fa4(cast_80342fa4(self->f40), &pos);
    post_8016239c(message_init_800683fc(alloc_801613f0(heap_804b1754, 12), message_id_8015f5a0(&cache_804afe90, 1), spawn_803a2c3c, 0));
    while (!(*get_vec_80178ec4(cast_80342fa4(self->f40)) == pos)) {
        pos = *get_vec_80178ec4(cast_80342fa4(self->f40));
        Ptr32<Vec> pt = &t;
        *pt = *get_vec_80178ec4(cast_80342fa4(self->f44));
        sweep_800b0824(pos - down * 50.0f, down, *zero_8045e788, 130, 1);
        unsigned h = hits_804b1764;
        if (h > 29) if (h <= 129) if (hit_8043ae20->y > level) {
            if (!traceReady_804b1784) trace_800bd920();
            Vec nn = *normal_8043ae38;
            float s = 1.0f / sqrtf_802e82c0(nn.len2());
            nn.x *= s; nn.y *= s; nn.z *= s;
            if (nn.y >= 0.6f) {
                a->push(*hit_8043ae20);
                b->push(t);
                found++;
            }
        }
        n++;
        post_8016239c(message_init_800683fc(alloc_801613f0(heap_804b1754, 12), message_id_8015f5a0(&cache_804afe90, 1), spawn_803a2c3c, n));
    }
    return found;
}


