/* Script state machine setters that write a parsed value into a reflected member. */
struct K7bMember { char head[4]; unsigned short offset; };
struct K7bObject;
struct K7bObjectVtable { void *slots[5]; void *(*get_members)(struct K7bObject *self); };
struct K7bObject { struct K7bObjectVtable *vtable; };
struct K7bStateMachine { char pad[92]; struct K7bObject *target; unsigned state; };
extern int atoi(const char *text);
extern double atof(const char *text);
extern struct K7bMember **w3d_s21_vector_get_801e9db8(void *vector, unsigned index);
extern void w3d_s21_state_dispatch_8027ae00(struct K7bStateMachine *self);
extern void w3d_auto_8027a98c(struct K7bStateMachine *self);

void w3d_k7b_state_set_int_8027a248(struct K7bStateMachine *self, const char *text)
{
    if (*text != 0) {
        int value = atoi(text);
        struct K7bObject *target = self->target;
        struct K7bMember *member = *w3d_s21_vector_get_801e9db8(target->vtable->get_members(target), self->state);
        *(int *)((char *)target + member->offset) = value;
    }
    w3d_s21_state_dispatch_8027ae00(self);
    w3d_auto_8027a98c(self);
}

void w3d_k7b_state_set_float_8027a2c4(struct K7bStateMachine *self, const char *text)
{
    if (*text != 0) {
        float value = atof(text);
        struct K7bObject *target = self->target;
        struct K7bMember *member = *w3d_s21_vector_get_801e9db8(target->vtable->get_members(target), self->state);
        *(float *)((char *)target + member->offset) = value;
    }
    w3d_s21_state_dispatch_8027ae00(self);
    w3d_auto_8027a98c(self);
}

void w3d_k7b_state_set_bool_8027a7fc(struct K7bStateMachine *self, int key)
{
    struct K7bObject *target;
    struct K7bMember *member;
    switch (key) {
    case '0':
        target = self->target;
        member = *w3d_s21_vector_get_801e9db8(target->vtable->get_members(target), self->state);
        *(int *)((char *)target + member->offset) = 0;
        break;
    case '1':
        target = self->target;
        member = *w3d_s21_vector_get_801e9db8(target->vtable->get_members(target), self->state);
        *(int *)((char *)target + member->offset) = 1;
        break;
    }
    w3d_s21_state_dispatch_8027ae00(self);
    w3d_auto_8027a98c(self);
}
