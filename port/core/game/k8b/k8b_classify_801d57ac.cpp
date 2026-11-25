#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k8b_classify_801d57ac.c"
/* Method on the secondary base subobject (this - 4, null-checked). */
extern float lbl_803af230[];
extern float lbl_803af22c[];

int w3d_k8b_classify_801d57ac(Ptr32<char> self, Ptr32<char> item) {
    Ptr32<char> base = self ? w3d::R(self - 4) : 0;
    Ptr32<char> record;
    int mode;
    Ptr32<float> values;
    unsigned int i;
    unsigned int count;
    float low;
    float high;
    if (*(Ptr32<int>)(base + 48) != 0) {
        *(Ptr32<int>)(base + 44) = 1;
        return 0;
    }
    record = *(Ptr32<Ptr32<char>>)(item + 20);
    mode = 0;
    count = *(Ptr32<unsigned int>)(record + 24);
    i = 0;
    values = (Ptr32<float>)(record + 44);
    low = lbl_803af22c[0];
    high = lbl_803af230[0];
    for (; i < count; i++, values += 4) {
        if (*values != low) {
            mode = 2;
            if (*values != high) {
                mode = 1;
                break;
            }
        }
    }
    *(Ptr32<int>)(base + 44) = mode;
    return 0;
}

}
