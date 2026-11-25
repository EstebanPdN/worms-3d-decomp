/* Virtual helpers on held objects. */
typedef struct S20Object { void **vtable; } S20Object;
typedef int (*S20CallInt)(S20Object *);
typedef void (*S20CallVoid)(S20Object *);
typedef struct S20Owner132 { char pad[132]; S20Object *held; } S20Owner132;
typedef struct S20Owner72 { char pad[72]; S20Object *first; S20Object *second; } S20Owner72;

int w3d_s20_query_then_run_801ad108(S20Owner132 *self) {
    if (((S20CallInt)self->held->vtable[6])(self->held) < 0)
        return 0;
    return ((S20CallInt)self->held->vtable[16])(self->held);
}

int w3d_s20_release_both_801b1ac4(S20Owner72 *self) {
    int result = 0;
    if (self->first != 0)
        ((S20CallVoid)self->first->vtable[4])(self->first);
    self->first = 0;
    if (self->second != 0)
        ((S20CallVoid)self->second->vtable[4])(self->second);
    self->second = 0;
    return result;
}
