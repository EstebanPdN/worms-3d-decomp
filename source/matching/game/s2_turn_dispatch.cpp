/* Turn-state message helpers and service update forwarding. */
extern "C" {
struct S2Turn { void *vtable; unsigned char pad04[60]; int launched; };
struct S2TurnMessage { unsigned short id, reserved; void *vtable; };
struct S2TurnKey { const char *text; };
int w3d_fn_8002a914(S2Turn *);
void w3d_fn_8002a978(S2Turn *, int);
int w3d_fn_800fc3b0(S2TurnKey *, int);
void w3d_fn_800fc1f0(S2TurnKey *, int *);
void *w3d_fn_801613f0(void *, int);
int w3d_cached_message_id(void *, int);
void *w3d_message_int_init(void *, unsigned short, int);
void w3d_message_post_current(void *);
void w3d_fn_8002addc(S2Turn *);
void w3d_fn_8002ae70(S2Turn *);
void w3d_fn_80104be0(void *, int);
void w3d_fn_80104d78(void *, int);
extern unsigned char w3d_obj_80410638[], w3d_obj_8040db38[];
extern unsigned int w3d_obj_804af1a8, w3d_obj_804af1c8, w3d_obj_804af1b0, w3d_obj_804af1c0, w3d_obj_804af1d0;
extern int w3d_obj_804b1858, w3d_obj_804b1854, w3d_obj_804aafa0;
extern void *w3d_obj_804b1754;
extern const char w3d_str_803995dc[], w3d_str_803995e8[];

S2TurnMessage *w3d_land_clear_message_801040d0(S2TurnMessage *self, int first, int second)
{
    struct { unsigned int first, second; } scratch;
    self->id = w3d_cached_message_id(&w3d_obj_804af1a8, 1);
    self->vtable = w3d_obj_8040db38;
    w3d_obj_804b1858 = first;
    w3d_obj_804b1854 = second;
    return self;
}


S2Turn *w3d_turn_state_construct_8010430c(S2Turn *self)
{
    struct { unsigned int first, second; } scratch;
    w3d_fn_8002a914(self);
    self->launched = 0;
    self->vtable = w3d_obj_80410638;
    return self;
}


void w3d_turn_state_destroy_80104350(S2Turn *self, int flags)
{
    self->vtable = w3d_obj_80410638;
    w3d_fn_8002a978(self, flags);
}


void w3d_turn_clear_retreat_time_80104410()
{
    S2TurnKey key;
    key.text = w3d_str_803995dc;
    w3d_fn_800fc3b0(&key, 0);
}


#if 0 /* 4 attempts; three property-key setup instructions differ */
void w3d_turn_launch_once_80104448(S2Turn *self)
{
    S2TurnKey key;
    int index;
    if (!self->launched) {
        self->launched = 1;
        key.text = w3d_str_803995e8;
        w3d_fn_800fc1f0(&key, &index);
        void *message = w3d_fn_801613f0(w3d_obj_804b1754, 12);
        w3d_message_post_current(w3d_message_int_init(message, (unsigned short)w3d_cached_message_id(&w3d_obj_804af1c8, 1), index));
        S2TurnMessage *message_804af1b0 = (S2TurnMessage *)w3d_fn_801613f0(w3d_obj_804b1754, 8);
        message_804af1b0->id = w3d_cached_message_id(&w3d_obj_804af1b0, 1);
        message_804af1b0->vtable = w3d_obj_8040db38;
        w3d_message_post_current(message_804af1b0);
        S2TurnMessage *message_804af1c0 = (S2TurnMessage *)w3d_fn_801613f0(w3d_obj_804b1754, 8);
        message_804af1c0->id = w3d_cached_message_id(&w3d_obj_804af1c0, 1);
        message_804af1c0->vtable = w3d_obj_8040db38;
        w3d_message_post_current(message_804af1c0);
        S2TurnMessage *message_804af1d0 = (S2TurnMessage *)w3d_fn_801613f0(w3d_obj_804b1754, 8);
        message_804af1d0->id = w3d_cached_message_id(&w3d_obj_804af1d0, 1);
        message_804af1d0->vtable = w3d_obj_8040db38;
        w3d_message_post_current(message_804af1d0);
        w3d_fn_8002addc(self);
        w3d_fn_8002ae70(self);
    }
}
#endif


int w3d_service_update_delta_80104b90(void *self, int now)
{
    struct { unsigned int first, second; } scratch;
    int previous = w3d_obj_804aafa0;
    w3d_obj_804aafa0 = now;
    int delta = now - previous;
    w3d_fn_80104be0(self, delta);
    w3d_fn_80104d78(self, delta);
    return 0;
}

}
