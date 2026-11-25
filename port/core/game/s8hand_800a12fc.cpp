#include "w3d_ptr.h"
#line 1 "s8hand_800a12fc.cpp"
struct s8_Position { float x, y, z; };
struct s8_MeshStartContext {
    char pad0[28];
    Ptr32<void> mesh;
    s8_Position position;
    char pad44[40];
    int started;
};
extern "C" int fn_80343584(Ptr32<void>);
extern "C" int fn_801817e0(Ptr32<void>, int);
extern "C" int fn_80181640(int, int, Ptr32<s8_Position>, int, float, float, float);
extern "C" int fn_800a14c4(Ptr32<s8_MeshStartContext>, int);
extern float lbl_80380900[], lbl_80380904[];
extern int lbl_804aac14;
extern "C" void s8_mesh_start_800a12fc(Ptr32<s8_MeshStartContext> context) {
    if (!context->started) {
        int mesh = fn_80343584(context->mesh);
        fn_801817e0((Ptr32<void>)w3d::G(mesh), -1);
        fn_80181640(mesh, lbl_804aac14, &context->position, 0,
                    lbl_80380900[0], lbl_80380904[0], lbl_80380904[0]);
        context->started = 1;
        fn_800a14c4(context, 1);
    }
}


