inline void *operator new(unsigned int, void *place) { return place; }
struct W3dType_801629f8 { W3dType_801629f8(void *, void *, void *, int, int); int words[4]; };
struct K2aInt3 { int a, b, c; };
extern W3dType_801629f8 w3d_type_8035faf0;
extern "C" char w3d_str_803e7714[];
extern "C" char w3d_str_803618f0[];
extern "C" void * FUN_80022b18(void);
extern "C" int w3d_arena_804aca40[2];
extern "C" char w3d_str_8036c550[];
extern "C" void * FUN_802097ec(void *, const char *, int, int);
extern "C" int w3d_state_804aca48[1];
extern "C" K2aInt3 w3d_state_804200a4;
extern "C" int w3d_message_804aca4c[2];
extern "C" char w3d_str_8036c560[];
extern "C" void * w3d_cached_message_name_init(void *, const char *);

extern "C" void k2a_sinit_objreg_80023144(int initialize, int priority)
{
    if (priority == 0xffff && initialize) {
        new (&w3d_type_8035faf0) W3dType_801629f8(w3d_str_803e7714, w3d_str_803618f0, (void *)FUN_80022b18, 10, 0);
        FUN_802097ec(w3d_arena_804aca40, w3d_str_8036c550, 0, 0);
        w3d_state_804200a4.c = 0;
        w3d_state_804200a4.b = 0;
        w3d_state_804200a4.a = 0;
        w3d_state_804aca48[0] = 0;
        w3d_cached_message_name_init(w3d_message_804aca4c, w3d_str_8036c560);
    }
}
