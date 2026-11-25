/* Counterpart of the child append 0x80186664: erases a child from the pointer vector at +104
 * (STLport erase of a trivial element: copy the tail down when not last, then shrink), then
 * detaches the child through its virtual slot +20. Inferred names. */
extern "C" void *copy_802eee50(void *, const void *, unsigned int, ...);
struct Cc17cNode;
struct Cc17cNodeTable { char pad0[20]; int (*attach)(Cc17cNode *, Cc17cNode *); };
struct Cc17cNodeVector {
    Cc17cNode **start, **finish, **end_of_storage;
    Cc17cNode **end() { return finish; }
    Cc17cNode **erase(Cc17cNode **position) {
        if (position + 1 != finish)
            copy_802eee50(position, position + 1, (char *)finish - (char *)(position + 1));
        --finish;
        return position;
    }
};
struct Cc17cNode { Cc17cNodeTable *vtable; char pad4[100]; Cc17cNodeVector children; };
extern "C" int w3d_cc17c_child_remove_801867b0(Cc17cNode *self, Cc17cNode *child)
{
    for (Cc17cNode **it = self->children.start; it != self->children.end(); ++it) {
        if (*it == child) {
            self->children.erase(it);
            child->vtable->attach(child, 0);
            return 0;
        }
    }
    return 0x80004005;
}
