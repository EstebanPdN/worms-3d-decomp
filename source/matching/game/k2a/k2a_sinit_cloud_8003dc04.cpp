inline void *operator new(unsigned int, void *place) { return place; }
struct W3dType_80160038 { W3dType_80160038(void *, void *, void *, int, int); int words[4]; };
struct K2aZeroTriple { int a, b, c; };
extern W3dType_80160038 w3d_type_8035ffd0;
extern "C" char w3d_str_803e79ec[];
extern "C" char w3d_str_803617d0[];
extern "C" void * FUN_8003d2a8(void);
extern "C" K2aZeroTriple w3d_cloud_804273d4;
extern "C" K2aZeroTriple w3d_cloud_804273e0;

extern "C" void k2a_sinit_cloud_8003dc04(int initialize, int priority)
{
    if (priority == 0xffff && initialize) {
        new (&w3d_type_8035ffd0) W3dType_80160038(w3d_str_803e79ec, w3d_str_803617d0, (void *)FUN_8003d2a8, 9, 0);
        w3d_cloud_804273d4.c = 0;
        w3d_cloud_804273d4.b = 0;
        w3d_cloud_804273d4.a = 0;
        w3d_cloud_804273e0.c = 0;
        w3d_cloud_804273e0.b = 0;
        w3d_cloud_804273e0.a = 0;
    }
}
