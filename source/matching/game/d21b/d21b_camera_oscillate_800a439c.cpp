// d21b: 0x800a439c (408 bytes). Camera oscillation step: lazily initialise
// three static vectors (zero, (0, 0, -450), zero), drive the second vector's
// Y and the third vector's Z from two sine waves of the tick
// ((sin(tick * f) + 1) * amplitude with f = 0.0004, amplitude 400 and
// f = 0.0002, amplitude 500), pass the vectors to the camera's virtual slots
// 11 and 12, then run the optional logic hook. Returns 0.
// The first wave's constants are const locals: their pool entries are
// created at the declarations (0.0004 and 400 before the unsigned-to-float
// conversion constant), and the high half of the 400 address is computed
// before the first sine call while the load itself follows it, as in the
// original. Built with -mps-float: without it the build differs only by the
// 8-byte frame gap below the saved FPRs. The float literals form this
// function's constant pool at 0x80380dc8. Partial observed layouts.
extern "C" float w3d_cx9c_sinf_802e88ac(float);
struct d21b_OscVec {
    float x, y, z;
    void fill(float f) { x = f; y = f; z = f; }
    void set(float a, float b, float c) { x = a; y = b; z = c; }
};
struct d21b_OscCamera {
    void **vtable;
};
struct d21b_OscContext {
    unsigned char unknown00[48];
    d21b_OscCamera *camera;              // +48
};
extern d21b_OscContext *w3d_context_804b1788;
extern void *w3d_hook_804b1794;
extern int d21b_initA_804ae1b0, d21b_initB_804ae1b4, d21b_initC_804ae1b8;
extern d21b_OscVec d21b_vecA_80438544, d21b_vecB_80438550, d21b_vecC_8043855c;
extern "C" void w3d_logic_hook_800c88c4(void *);
typedef void (*d21b_OscSlot)(d21b_OscCamera *, const d21b_OscVec *);

extern "C" int d21b_camera_oscillate_800a439c(void *, unsigned tick) {
    if (!d21b_initA_804ae1b0) {
        d21b_vecA_80438544.fill(0.0f);
        d21b_initA_804ae1b0 = 1;
    }
    if (!d21b_initB_804ae1b4) {
        d21b_vecB_80438550.set(0.0f, 0.0f, -450.0f);
        d21b_initB_804ae1b4 = 1;
    }
    if (!d21b_initC_804ae1b8) {
        d21b_initC_804ae1b8 = 1;
        d21b_vecC_8043855c.fill(0.0f);
    }
    const float frequency = 0.0004f;
    const float amplitude = 400.0f;
    d21b_OscVec *b = &d21b_vecB_80438550;
    b->y = (w3d_cx9c_sinf_802e88ac((float)tick * frequency) + 1.0f) * amplitude;
    d21b_OscVec *c = &d21b_vecC_8043855c;
    c->z = (w3d_cx9c_sinf_802e88ac((float)tick * 0.0002f) + 1.0f) * 500.0f;
    ((d21b_OscSlot)w3d_context_804b1788->camera->vtable[11])(w3d_context_804b1788->camera, b);
    ((d21b_OscSlot)w3d_context_804b1788->camera->vtable[12])(w3d_context_804b1788->camera, c);
    if (w3d_hook_804b1794)
        w3d_logic_hook_800c88c4(w3d_hook_804b1794);
    return 0;
}
