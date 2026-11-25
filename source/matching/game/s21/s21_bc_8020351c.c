// desc: Appears to construct a circular list object with a freshly allocated 24-byte sentinel node linked to itself, falling back to a second allocator on failure.
struct S21Node { int value; int previous; struct S21Node *next; struct S21Node *last; };
struct S21List { int pad; struct S21Node *head; int count; unsigned char flag; char pad1[3]; int extra; };
extern struct S21Node *fn_80212fd4(int);
extern struct S21Node *fn_803413d8(int);
struct S21List *w3d_s21_construct_list_8020351c(struct S21List *self)
{
    int zero = 0;
    volatile char frame_pad[16];
    struct S21Node *node;
    self->head = 0;
    node = fn_80212fd4(24);
    if (!node)
        node = fn_803413d8(24);
    self->head = node;
    self->count = zero;
    self->flag = zero;
    self->head->value = zero;
    self->head->previous = zero;
    self->head->next = self->head;
    self->head->last = self->head;
    self->extra = zero;
    return self;
}
