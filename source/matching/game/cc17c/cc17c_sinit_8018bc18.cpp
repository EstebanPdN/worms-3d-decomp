inline void *operator new(unsigned int, void *place) { return place; }
struct W3dType_8020fbd0 { W3dType_8020fbd0(void *, void *, void *, int, int); int words[4]; };
extern W3dType_8020fbd0 lbl_80361c58;
extern "C" char lbl_803e8aa8[];
extern "C" char lbl_80361f58[];
extern "C" void * fn_801899d4(void);
struct Cc17cPtr { void *p; Cc17cPtr() : p(0) {} };
extern Cc17cPtr lbl_804b0238, lbl_804b023c, lbl_804b0240, lbl_804b0244, lbl_804b0248, lbl_804b024c, lbl_804b0250, lbl_804b0254, lbl_804b0258, lbl_804b025c, lbl_804b0260, lbl_804b0264, lbl_804b0268, lbl_804b026c;
extern "C" void w3d_cc17c_sinit_8018bc18(int init, int priority)
{
    if (priority == 0xffff && init) {
        new (&lbl_80361c58) W3dType_8020fbd0(lbl_803e8aa8, lbl_80361f58, (void *)fn_801899d4, 0, 0);
        new (&lbl_804b0238) Cc17cPtr;
        new (&lbl_804b023c) Cc17cPtr;
        new (&lbl_804b0240) Cc17cPtr;
        new (&lbl_804b0244) Cc17cPtr;
        new (&lbl_804b0248) Cc17cPtr;
        new (&lbl_804b024c) Cc17cPtr;
        new (&lbl_804b0250) Cc17cPtr;
        new (&lbl_804b0254) Cc17cPtr;
        new (&lbl_804b0258) Cc17cPtr;
        new (&lbl_804b025c) Cc17cPtr;
        new (&lbl_804b0260) Cc17cPtr;
        new (&lbl_804b0264) Cc17cPtr;
        new (&lbl_804b0268) Cc17cPtr;
        new (&lbl_804b026c) Cc17cPtr;
    }
}
