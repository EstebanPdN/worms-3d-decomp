// desc: Appears to allocate aligned memory when a flag bit is set, otherwise to call the allocation function pointer of the inner object with the same arguments.
struct S21Inner { char pad[24]; void *(*allocate)(struct S21Inner *, int, int); };
struct S21Allocator { struct S21Inner *inner; char pad[16]; unsigned flags; };
extern void *fn_801fe2a8(int, int);
void *w3d_s21_allocate_80209638(struct S21Allocator *self, int size, int alignment)
{
    void *result;
    if (self->flags & 16)
        result = fn_801fe2a8(size, alignment);
    else
        result = self->inner->allocate(self->inner, size, alignment);
    return result;
}
