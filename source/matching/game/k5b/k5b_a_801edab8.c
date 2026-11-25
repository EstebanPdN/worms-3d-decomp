struct K5bShared { void **vtable; };
extern struct K5bShared *lbl_804b05a8;
extern struct K5bShared *lbl_804b05ac;
extern struct K5bShared *lbl_804b05b0;
extern struct K5bShared *lbl_804b05b4;
extern void *lbl_804176d0[];
extern void *lbl_80417670[];
extern void *lbl_804176a0[];
extern void *w3d_aligned_allocate(unsigned int size, unsigned int alignment);
extern struct K5bShared *w3d_tagged_construct_801ee1e4(struct K5bShared *self);
static inline void k5b_retain(struct K5bShared *object)
{
    ((void (*)(struct K5bShared *))object->vtable[3])(object);
}
int w3d_k5b_shared_defaults_create_801edab8(void)
{
    struct K5bShared *first;
    struct K5bShared *second;
    struct K5bShared *third;
    lbl_804b05a8 = w3d_aligned_allocate(32, 32);
    lbl_804b05ac = w3d_aligned_allocate(32, 32);
    lbl_804b05b0 = w3d_aligned_allocate(32, 32);
    lbl_804b05b4 = w3d_aligned_allocate(32, 32);
    lbl_804b05a8 = w3d_tagged_construct_801ee1e4(lbl_804b05a8);
    first = lbl_804b05ac;
    w3d_tagged_construct_801ee1e4(first);
    first->vtable = lbl_804176d0;
    lbl_804b05ac = first;
    second = lbl_804b05b0;
    w3d_tagged_construct_801ee1e4(second);
    second->vtable = lbl_80417670;
    lbl_804b05b0 = second;
    third = lbl_804b05b4;
    w3d_tagged_construct_801ee1e4(third);
    third->vtable = lbl_804176a0;
    lbl_804b05b4 = third;
    k5b_retain(lbl_804b05a8);
    k5b_retain(lbl_804b05ac);
    k5b_retain(lbl_804b05b0);
    k5b_retain(lbl_804b05b4);
    return 0;
}
// desc: w3d_k5b_shared_defaults_create_801edab8: Appears to allocate and construct the four shared default objects at 0x804b05a8..0x804b05b4 (three with derived vtables) and retain each once.
