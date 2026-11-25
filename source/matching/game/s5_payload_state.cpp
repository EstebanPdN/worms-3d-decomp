/* Payload state ownership and deferred-interface cleanup. */
extern "C" {
struct S5PayloadIface;
struct S5PayloadVtable { void (*reserved[4])(); void (*release)(S5PayloadIface *); };
struct S5PayloadIface { S5PayloadVtable *vtable; };
struct S5PayloadPending { unsigned count,capacity; S5PayloadIface **data; S5PayloadIface *&at(unsigned index) { return *(S5PayloadIface **)(index*sizeof(S5PayloadIface *)+(unsigned)data); } };
struct S5PayloadState { void *vtable; unsigned char unknown04[28]; int index; S5PayloadIface *first,*second; S5PayloadPending pending; S5PayloadIface *third,*fourth; int mode; };
extern unsigned char w3d_payload_vtable_8040fbc8[];
int w3d_ctor_8015fef0(void *);
void w3d_base_destroy_8015ff2c(void *,int);
void w3d_pending_init_802109dc(S5PayloadPending *);
void w3d_auto_80210abc(S5PayloadPending *,int);
void w3d_task_deferred_clear(S5PayloadPending *);
S5PayloadState *w3d_payload_state_init_800cc8a0(S5PayloadState *state)
{
    w3d_ctor_8015fef0(state);
    state->first=0; state->second=0;
    state->vtable=w3d_payload_vtable_8040fbc8;
    w3d_pending_init_802109dc(&state->pending);
    state->third=0; state->fourth=0;
    state->index=-1; state->mode=1;
    return state;
}
void w3d_payload_state_destroy_800cc908(S5PayloadState *state,int flags)
{
    state->vtable=w3d_payload_vtable_8040fbc8;
    if(state->fourth) state->fourth->vtable->release(state->fourth);
    if(state->third) state->third->vtable->release(state->third);
    w3d_auto_80210abc(&state->pending,2);
    if(state->second) state->second->vtable->release(state->second);
    if(state->first) state->first->vtable->release(state->first);
    w3d_base_destroy_8015ff2c(state,flags);
}
void w3d_payload_pending_clear_800ccd54(S5PayloadState *state)
{
    for(unsigned index=0;index<state->pending.count;++index) {
        S5PayloadIface *&entry=state->pending.at(index);
        S5PayloadIface *replacement=0;
        if(entry) entry->vtable->release(entry);
        entry=replacement;
    }
    w3d_task_deferred_clear(&state->pending);
}
}
