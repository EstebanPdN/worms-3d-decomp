struct K8bShape {
    char pad0[36];
    const char *name;      /* +36 */
    char pad28[8];
    void *geometry;        /* +48 */
    void *shader;          /* +52 */
};

extern void w3d_k8b_log_801d6000(void *owner, const char *format, ...);
extern int w3d_s20_dispatch_two_targets_801a3adc(void *self, struct K8bShape *shape);

void w3d_k8b_shape_check_801d6644(char *self, struct K8bShape *shape)
{
    char *owner = self ? self - 4 : 0;
    if (shape->geometry == 0)
        w3d_k8b_log_801d6000(owner, "Warning: No geometry attached to shape '%s' @ %08x\n", shape->name, shape);
    if (shape->shader == 0)
        w3d_k8b_log_801d6000(owner, "Warning: No shader attached to shape '%s' @ %08x\n", shape->name, shape);
    w3d_s20_dispatch_two_targets_801a3adc(self, shape);
}
