// desc: Appears to change the 10-bit class field of an object and, when it differs, propagate the new class into the halfword at offset 6 of every linked node.
struct S21Bits { unsigned klass : 10; unsigned rest : 22; };
struct S21Node { char pad[6]; short klass; };
struct S21Object { char pad[32]; struct S21Bits bits; };
extern struct S21Node *fn_8020fe00(struct S21Object *);
extern struct S21Node *fn_8020fe18(struct S21Object *, struct S21Node *);
void w3d_s21_set_class_801e9090(struct S21Object *self, int klass)
{
    struct S21Node *node;
    if (klass == self->bits.klass)
        return;
    self->bits.klass = klass;
    node = fn_8020fe00(self);
    if (!node)
        return;
    do {
        node->klass = klass;
        node = fn_8020fe18(self, node);
    } while (node);
}
