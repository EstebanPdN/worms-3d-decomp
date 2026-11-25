#include "w3d_ptr.h"
#line 1 "d25d_worm_input_yaw_8015139c.cpp"
// GWMP8P rev0 0x8015139c. Set the worm yaw (+576) from the input direction:
// take x and negated z of the input 0x8014c260, skip a zero vector, rotate
// it by the inverse (0x801f6c2c) of the view matrix from 0x8014be44, flatten
// it, and store the signed angle to the z axis. Names are inferred.
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
    float dot(const Vec &o) const { return x * o.x + y * o.y + z * o.z; }
};
struct Row { float x, y, z, w; };
struct Mat {
    Row r[4];
    const Row &Row_(int i) const { return r[i]; }
    void rotate(Vec &o, const Vec &v) const {
        o.x = v.x * Row_(0).x + v.y * Row_(1).x + v.z * Row_(2).x;
        o.y = v.x * Row_(0).y + v.y * Row_(1).y + v.z * Row_(2).y;
        o.z = v.x * Row_(0).z + v.y * Row_(1).z + v.z * Row_(2).z;
    }
};
extern "C" float sqrt_802e82c0(float);
extern "C" float acos_802e79e0(float);
inline const float &fmin(const float &a, const float &b) { return a < b ? a : b; }
inline const float &fmax(const float &a, const float &b) { return a < b ? b : a; }
inline const float &clamp(const float &v, const float &lo, const float &hi) { return fmax(fmin(v, hi), lo); }
struct Worm { unsigned char u0[576]; float yaw; };
extern "C" Vec input_8014c260(Ptr32<Worm>);
extern "C" void matrix_8014be44(Ptr32<Worm>, Ptr32<Mat>);
extern "C" int normalize_801f6c2c(Ptr32<Mat>, Ptr32<const Mat>);
extern "C" void d25d_worm_input_yaw_8015139c(Ptr32<Worm> self) {
    Vec v(input_8014c260(self).x, 0.0f, -input_8014c260(self).z);
    if (v.lenSq() != 0.0f) {
        Mat m, q;
        matrix_8014be44(self, &q);
        normalize_801f6c2c(&m, &q);
        Vec w; m.rotate(w, v);
        Vec ref(0.0f, 0.0f, 1.0f);
        w.y = 0.0f;
        float l = w.lenSq();
        if (l != 0.0f) {
            float f = 1.0f / sqrt_802e82c0(l);
            w.x *= f; w.y *= f; w.z *= f;
            float a = acos_802e79e0(clamp(w.dot(ref), -1.0f, 1.0f));
            if (ref.x * w.z - w.x * ref.z > 0.0f) a = 0.0f - a;
            self->yaw = a;
        }
    }
}


