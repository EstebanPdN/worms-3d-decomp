#include "w3d_ptr.h"
#line 1 "k8c_gauge_step_80268420.cpp"
struct K8cVec3 {
    float x, y, z;
    K8cVec3() {}
    K8cVec3(const K8cVec3 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct K8cBounds { char pad00[20]; K8cVec3 size; };
struct K8cLabel { char pad00[44]; float width; float height; char pad34[8]; };
static inline void k8c_label_set_size(Ptr32<K8cLabel> l, float w, float h) { l->width = w; l->height = h; }
struct K8cGauge {
    char pad00[40];
    Ptr32<K8cBounds> bounds;
    char pad2c[524];
    float value;
    int busy;
    K8cLabel label;
    K8cLabel label_down;
};
extern "C" void fn_802683b8(Ptr32<K8cGauge> self, float value);
extern float w3d_f32_803cb74c[];
extern float w3d_f32_803cb750[];
extern float w3d_f32_803cb754[];
extern "C" void w3d_k8c_gauge_step_80268420(Ptr32<K8cGauge> self)
{
    float limit = w3d_f32_803cb74c[0];
    float v = self->value;
    if (v != limit) {
        v += w3d_f32_803cb750[0];
        if (v > limit)
            v = limit;
        fn_802683b8(self, v);
        K8cVec3 size = self->bounds->size;
        float k = w3d_f32_803cb754[0];
        k8c_label_set_size(&self->label, size.x * k, size.y * k);
    }
}
extern float w3d_f32_803cb758[];
extern float w3d_f32_803cb75c[];
extern float w3d_f32_803cb760[];
extern "C" void w3d_k8c_gauge_step_down_802684c4(Ptr32<K8cGauge> self)
{
    float limit = w3d_f32_803cb758[0];
    float v = self->value;
    if (v != limit) {
        v -= w3d_f32_803cb75c[0];
        if (v < limit)
            v = limit;
        fn_802683b8(self, v);
        K8cVec3 size = self->bounds->size;
        float k = w3d_f32_803cb760[0];
        k8c_label_set_size(&self->label_down, size.x * k, size.y * k);
    }
}


