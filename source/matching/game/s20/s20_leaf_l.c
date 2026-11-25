/* Linked-list append, reference swaps and flag helpers. */
typedef struct S20Object { void **vtable; } S20Object;
typedef void (*S20Call0)(S20Object *);
typedef struct S20Node { char pad[12]; struct S20Node *next; } S20Node;
typedef struct S20Inner { char pad[28]; S20Object *target; } S20Inner;
typedef struct S20Outer { char pad[4]; S20Inner *inner; } S20Outer;

int w3d_s20_append_node_80178a98(S20Node *self, S20Node *node) {
    S20Node *tail;
    if (self->next == 0) {
        self->next = node;
        return 0;
    }
    tail = self->next;
    while (tail->next != 0)
        tail = tail->next;
    tail->next = node;
    return 0;
}

void w3d_s20_replace_target_801795d4(S20Outer *self, S20Object *target) {
    S20Inner *inner = self->inner;
    S20Object *previous = inner->target;
    inner->target = target;
    if (target != 0)
        ((S20Call0)target->vtable[3])(target);
    if (previous != 0)
        ((S20Call0)previous->vtable[4])(previous);
}

void w3d_s20_clear_target_80179770(S20Outer *self) {
    S20Inner *inner = self->inner;
    S20Object *previous = inner->target;
    inner->target = 0;
    if (previous != 0)
        ((S20Call0)previous->vtable[4])(previous);
}

typedef struct S20FlagWord { char pad[20]; unsigned int pad2 : 2; unsigned int flag : 1; unsigned int rest : 29; } S20FlagWord;

int w3d_s20_set_flag_8017dc78(S20FlagWord *self, int value) {
    if (self->flag == value)
        return 1;
    self->flag = value;
    return 0;
}

extern int lbl_803fe440[];

int w3d_s20_lookup_by_virtual_8017988c(S20Object *self) {
    return lbl_803fe440[((int (*)(S20Object *))self->vtable[6])(self)];
}

extern int lbl_804a89d8[];

int w3d_s20_test_zero_entry_8017d508(void *self, unsigned char *key, int *out) {
    *out = lbl_804a89d8[*key] == 0;
    return 0;
}

typedef struct S20Word { int value; } S20Word;
extern S20Word lbl_804b015c;
extern S20Word lbl_804b0158;

void w3d_s20_static_init_801797c0(int initialize, int priority) {
    if (priority == 0xffff && initialize) {
        S20Word *second = &lbl_804b0158;
        second->value = 0;
        lbl_804b015c.value = 0;
    }
}
