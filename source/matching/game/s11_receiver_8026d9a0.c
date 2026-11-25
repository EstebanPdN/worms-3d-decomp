/* Inferred interface relationships; slot offsets come from original loads. */
typedef struct S11Interface S11Interface;
typedef struct S11VTable {
    char unknown00[0x10];
    void (*release)(S11Interface *);
    char unknown14[4];
    S11Interface *(*related)(S11Interface *);
    char unknown1c[0x40];
    void (*attach)(S11Interface *, S11Interface *, int);
    void (*detach)(S11Interface *, S11Interface *);
} S11VTable;
struct S11Interface { S11VTable *vtable; };
typedef struct S11Owner {
    char unknown00[0x48];
    int initialized;
    S11Interface *target;
} S11Owner;
extern void fn_8026DBE8(void *);
void s11_transfer_interface_8026d9a0(S11Owner *owner, S11Interface **incoming) {
    S11Interface *related;
    if (!owner->initialized) fn_8026DBE8((void *)owner);
    if (owner->target->vtable->related(owner->target)) {
        related = owner->target->vtable->related(owner->target);
        related->vtable->detach(related, owner->target);
    }
    (*incoming)->vtable->attach(*incoming, owner->target, 0);
    if (*incoming) (*incoming)->vtable->release(*incoming);
}
