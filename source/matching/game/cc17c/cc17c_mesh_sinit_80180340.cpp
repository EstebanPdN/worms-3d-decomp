inline void *operator new(unsigned int, void *place) { return place; }
struct W3dType_8020fbd0 { W3dType_8020fbd0(void *, void *, void *, int, int); int words[4]; };
extern W3dType_8020fbd0 lbl_80361b98;
extern "C" char lbl_803e8a38[];
extern "C" char lbl_80361f58[];
extern "C" void fn_8017eae4(void);
struct Cc17cPtr { void *p; Cc17cPtr() : p(0) {} };
extern Cc17cPtr lbl_804b0184, lbl_804b0188, lbl_804b018c, lbl_804b0190, lbl_804b0194, lbl_804b0198, lbl_804b019c, lbl_804b01a0, lbl_804b01a4, lbl_804b01a8;
extern "C" void w3d_cc17c_mesh_sinit_80180340(int init, int priority)
{
    if (priority == 0xffff && init) {
        new (&lbl_80361b98) W3dType_8020fbd0(lbl_803e8a38, lbl_80361f58, (void *)fn_8017eae4, 0, 0);
        new (&lbl_804b01a8) Cc17cPtr;
        new (&lbl_804b0188) Cc17cPtr;
        new (&lbl_804b018c) Cc17cPtr;
        new (&lbl_804b0190) Cc17cPtr;
        new (&lbl_804b0194) Cc17cPtr;
        new (&lbl_804b0198) Cc17cPtr;
        new (&lbl_804b019c) Cc17cPtr;
        new (&lbl_804b01a0) Cc17cPtr;
        new (&lbl_804b01a4) Cc17cPtr;
        new (&lbl_804b0184) Cc17cPtr;
    }
}
