struct K8cHeld { struct K8cHeldVtable *vtable; };
struct K8cHeldVtable { void *slots[4]; void (*release)(struct K8cHeld *self); };
struct K8cTypeNode;
extern struct K8cTypeNode *w3d_sdata_804b1904;
extern struct K8cTypeNode *w3d_sdata_804b1908;
extern struct K8cHeld *w3d_sdata_804aba54;
extern void fn_8020fe64(struct K8cTypeNode *node);
extern void *fn_80210610(void);
extern void fn_80210660(void *);
int w3d_k8c_type_shutdown_80210010(void)
{
    while (w3d_sdata_804b1904)
        fn_8020fe64(w3d_sdata_804b1904);
    while (w3d_sdata_804b1908)
        fn_8020fe64(w3d_sdata_804b1908);fn_80210660((void *)fn_80210610());
    if (w3d_sdata_804aba54) {
        w3d_sdata_804aba54->vtable->release(w3d_sdata_804aba54);
        w3d_sdata_804aba54 = 0;
    }
    return 0;
}
