typedef struct K4aGameContext { char pad0[188]; unsigned int flags; } K4aGameContext;
typedef struct K4aServices { char pad0[20]; unsigned int owner; char pad1[8]; void *slots[10]; } K4aServices;
extern K4aGameContext *w3d_context_804b1788;
extern void *w3d_context_804b178c;
extern char w3d_service_8040e1f8[];
extern char w3d_service_804102d8[];
extern char w3d_service_80410e30[];
extern char w3d_service_804105a8[];
extern char w3d_service_8040f498[];
extern char w3d_service_8040edf0[];
extern char w3d_service_8040e928[];
extern char w3d_service_8040f458[];
extern char w3d_service_8040e4e8[];
extern char w3d_service_8040de78[];
extern void *w3d_s10_service_forward_8020b680(void *type);
extern void *FUN_80164514(void *context, void *service, unsigned int owner);

void k4a_services_bind_800a3d0c(K4aServices *self)
{
    void *service;
    if ((w3d_context_804b1788->flags & 0x80000) != 0) {
        service = w3d_s10_service_forward_8020b680(w3d_service_8040e1f8);
        self->slots[0] = FUN_80164514(w3d_context_804b178c, service, self->owner);
        service = w3d_s10_service_forward_8020b680(w3d_service_804102d8);
        self->slots[1] = FUN_80164514(w3d_context_804b178c, service, self->owner);
        service = w3d_s10_service_forward_8020b680(w3d_service_80410e30);
        self->slots[2] = FUN_80164514(w3d_context_804b178c, service, self->owner);
        service = w3d_s10_service_forward_8020b680(w3d_service_804105a8);
        self->slots[3] = FUN_80164514(w3d_context_804b178c, service, self->owner);
        service = w3d_s10_service_forward_8020b680(w3d_service_8040f498);
        self->slots[4] = FUN_80164514(w3d_context_804b178c, service, self->owner);
        service = w3d_s10_service_forward_8020b680(w3d_service_8040edf0);
        self->slots[5] = FUN_80164514(w3d_context_804b178c, service, self->owner);
        service = w3d_s10_service_forward_8020b680(w3d_service_8040e928);
        self->slots[6] = FUN_80164514(w3d_context_804b178c, service, self->owner);
        service = w3d_s10_service_forward_8020b680(w3d_service_8040f458);
        self->slots[7] = FUN_80164514(w3d_context_804b178c, service, self->owner);
        service = w3d_s10_service_forward_8020b680(w3d_service_8040e4e8);
        self->slots[8] = FUN_80164514(w3d_context_804b178c, service, self->owner);
        service = w3d_s10_service_forward_8020b680(w3d_service_8040de78);
        self->slots[9] = FUN_80164514(w3d_context_804b178c, service, self->owner);
    }
}
