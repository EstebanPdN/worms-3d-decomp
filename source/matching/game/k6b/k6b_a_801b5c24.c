struct K6bBounds6 { float v[6]; };
struct K6bBinding {
    char head[8];
    struct K6bBounds6 bounds;
};
extern struct K6bBounds6 lbl_8045e690[];
extern char lbl_803ab078[];
extern char lbl_803ab0a8[];
extern struct K6bBinding *w3d_binding_create_801f1094(void *owner, const char *name);
extern void * w3d_s12_create_member_binding_801ece2c(void *owner, const char *name);
extern void fn_801e8d9c(void *owner);
int w3d_k6b_register_bounds_bindings_801b5c24(void *owner)
{
    w3d_binding_create_801f1094(owner, lbl_803ab078)->bounds = lbl_8045e690[0];
    w3d_s12_create_member_binding_801ece2c(owner, lbl_803ab0a8);
    fn_801e8d9c(owner);
    return 0;
}
// desc: w3d_k6b_register_bounds_bindings_801b5c24: Appears to create the binding named at 0x803ab078 with the default six-word bounds from 0x8045e690, add the member binding 0x803ab0a8 and finish with 0x801e8d9c.
