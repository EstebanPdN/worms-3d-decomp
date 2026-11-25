extern int w3d_service_optional_context_query(void *);
extern void FUN_800a8b38(void *);
extern void FUN_800a8d00(void *, float, void *);

void s19_update_or_idle_800a8ad8(void *self, float t, int arg)
{
    if (w3d_service_optional_context_query(self))
        FUN_800a8b38(self);
    else
        FUN_800a8d00(self, t, arg);
}
