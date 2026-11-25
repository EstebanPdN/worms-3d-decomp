#include "w3d_ptr.h"
#line 1 "cc17c_child_remove_801867b0.cpp"
/* Counterpart of the child append 0x80186664: erases a child from the pointer vector at +104
 * (STLport erase of a trivial element: copy the tail down when not last, then shrink), then
 * detaches the child through its virtual slot +20. Inferred names. */
extern "C" Ptr32<void> copy_802eee50(Ptr32<void>, Ptr32<const void>, unsigned int, ...);
struct Cc17cNode;
struct Cc17cNodeTable { char pad0[20]; Ptr32<int (Ptr32<Cc17cNode>, Ptr32<Cc17cNode>)> attach; };
struct Cc17cNodeVector {
    Ptr32<Ptr32<Cc17cNode>> start; Ptr32<Ptr32<Cc17cNode>> finish; Ptr32<Ptr32<Cc17cNode>> end_of_storage;
    Ptr32<Ptr32<Cc17cNode>> end() { return finish; }
    Ptr32<Ptr32<Cc17cNode>> erase(Ptr32<Ptr32<Cc17cNode>> position) {
        if (position + 1 != finish)
            copy_802eee50(position, position + 1, (Ptr32<char>)finish - (Ptr32<char>)(position + 1));
        --finish;
        return position;
    }
};
struct Cc17cNode { Ptr32<Cc17cNodeTable> vtable; char pad4[100]; Cc17cNodeVector children; };
extern "C" int w3d_cc17c_child_remove_801867b0(Ptr32<Cc17cNode> self, Ptr32<Cc17cNode> child)
{
    for (Ptr32<Ptr32<Cc17cNode>> it = self->children.start; it != self->children.end(); ++it) {
        if (*it == child) {
            self->children.erase(it);
            child->vtable->attach(child, 0);
            return 0;
        }
    }
    return 0x80004005;
}


