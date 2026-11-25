#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_leaf_g.c"
/* Forwarding helpers that call virtual methods of objects held by a global. */
typedef struct S20Object { Ptr32<Ptr32<void>> vtable; } S20Object;
typedef struct S20Services { char pad0[100]; Ptr32<S20Object> service100; char pad1[4]; Ptr32<S20Object> service108; } S20Services;
extern Ptr32<S20Services> lbl_804b1788;
typedef Ptr32<void (Ptr32<S20Object>)> S20Call0;
typedef Ptr32<void (Ptr32<S20Object>, int, int, int, int)> S20Call4;
typedef Ptr32<void (Ptr32<S20Object>, int, int, unsigned char)> S20Call3;

void w3d_s20_service_call_800fc668(void) {
    Ptr32<S20Object> object = lbl_804b1788->service100;
    ((S20Call0)object->vtable[28])(object);
}

void w3d_s20_service_call4_800fc110(int a, int b, int c, int d) {
    Ptr32<S20Object> object = lbl_804b1788->service100;
    ((S20Call4)object->vtable[13])(object, a, b, c, d);
}

void w3d_s20_service_call4_800fc160(int a, int b, int c, int d) {
    Ptr32<S20Object> object = lbl_804b1788->service100;
    ((S20Call4)object->vtable[14])(object, a, b, c, d);
}

void w3d_s20_service_call3_800fd440(int a, int b, int c) {
    Ptr32<S20Object> object = lbl_804b1788->service100;
    ((S20Call3)object->vtable[42])(object, a, b, c);
}

}
