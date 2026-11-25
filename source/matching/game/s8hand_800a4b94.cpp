struct s8_MeshUpdateContext { char pad0[32]; void *mesh; int animation; char pad40[4]; int flag44; };
extern "C" void *fn_80343584(void *);
extern "C" int fn_80181ccc(void *,int);
extern "C" void fn_800a4da4(s8_MeshUpdateContext *);
extern "C" void fn_8015fd1c(s8_MeshUpdateContext *);
extern "C" int s8_mesh_update_800a4b94(s8_MeshUpdateContext *context) {
    if (fn_80181ccc(fn_80343584(context->mesh),context->animation)) {
        fn_800a4da4(context);
        if (context->flag44) fn_8015fd1c(context);
    }
    return 0;
}
