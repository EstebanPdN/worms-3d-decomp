struct Cc17cChild;
/* Observed child virtual slot +40 taking one argument and returning a status. */
struct Cc17cChildTable { char pad0[40]; int (*notify)(Cc17cChild *, void *); };
struct Cc17cChild { Cc17cChildTable *vtable; };
struct Cc17cChildVector {
    Cc17cChild **start; Cc17cChild **finish;
    unsigned int size() const { return finish - start; }
};
/* Observed: child pointer vector at +36/+40. */
struct Cc17cChildOwner { char pad0[36]; Cc17cChildVector children; };
extern "C" int w3d_cc17c_children_notify_801fba54(Cc17cChildOwner *self, void *argument, int mode)
{
    int result = 0;
    switch (mode) {
    case 2: {
        int failure;
        for (unsigned int i = 0; i < 4; i++) {
            Cc17cChild *child = *(Cc17cChild **)((char *)self->children.start + (i << 2));
            if (child) result = child->vtable->notify(child, argument);
            if (result < 0) failure = result;
        }
        return failure;
    }
    case 3: {
        int failure;
        for (unsigned int i = 0; i < self->children.size(); i++) {
            Cc17cChild *child = *(Cc17cChild **)((char *)self->children.start + (i << 2));
            result = child->vtable->notify(child, argument);
            if (result < 0) failure = result;
        }
        return failure;
    }
    case 0:
    case 1:
        break;
    }
    return 0x80004005;
}
