// d24d: 0x80160b7c (348 bytes). Keyboard event filter: key 1 pressed and key 28
// pressed post message 512 or 513 to the active input target (0x8016559c, virtual
// slot 7) while the owner's view (slot 11, then slot 2, byte +184) is active.
// Every other event goes to the input state 0x804b17f0: press 0x80160558 or
// release 0x801605c0. d24d_ViewKey 28 released skips straight to the release. Always
// returns 0. d24d_ViewKey meanings and names are inferred.
struct d24d_InputMessage { unsigned short id; void *data; };
struct d24d_InputTarget { void **vtable; };
struct d24d_KeyEvent { char pad[12]; int key; int down; };
struct d24d_View { char pad[184]; unsigned char active; };
struct d24d_Camera { void **vtable; };
extern "C" d24d_InputTarget *d24d_input_target_8016559c();
extern void *d24d_arena_804b1754;
extern void *d24d_input_state_804b17f0;
extern "C" d24d_InputMessage *d24d_arena_alloc_801613f0(void *, int);
extern char d24d_message_vtable_8040db38[];
extern "C" void d24d_key_press_80160558(void *, int);
extern "C" void d24d_key_release_801605c0(void *, int);
struct d24d_EventOwner { void **vtable; d24d_Camera *cam() { return ((d24d_Camera *(*)(d24d_EventOwner *))vtable[11])(this); } };

struct d24d_ViewKey { int v; };
inline d24d_View *view(d24d_EventOwner *self) { d24d_Camera *c = self->cam(); d24d_ViewKey k; return ((d24d_View *(*)(d24d_Camera *, d24d_ViewKey *))c->vtable[2])(c, &k); }
extern "C" int d24d_input_event_80160b7c(d24d_EventOwner *self, d24d_KeyEvent *e) {
    if (e->key == 1 && e->down == 1 && view(self)->active) { d24d_InputTarget *in = d24d_input_target_8016559c(); void **vt = in->vtable; d24d_InputMessage *m = d24d_arena_alloc_801613f0(d24d_arena_804b1754, 8); m->data = d24d_message_vtable_8040db38; m->id = 512; ((void (*)(d24d_InputTarget *, d24d_InputMessage *))vt[7])(in, m); return 0; }
    if (e->key == 28) {
        if (e->down != 1) goto up;
        if (view(self)->active) { d24d_InputTarget *in = d24d_input_target_8016559c(); void **vt = in->vtable; d24d_InputMessage *m = d24d_arena_alloc_801613f0(d24d_arena_804b1754, 8); m->data = d24d_message_vtable_8040db38; m->id = 513; ((void (*)(d24d_InputTarget *, d24d_InputMessage *))vt[7])(in, m); return 0; }
    }
    if (e->down == 1) d24d_key_press_80160558(d24d_input_state_804b17f0, e->key);
    else { up: d24d_key_release_801605c0(d24d_input_state_804b17f0, e->key); }
    return 0;
}
