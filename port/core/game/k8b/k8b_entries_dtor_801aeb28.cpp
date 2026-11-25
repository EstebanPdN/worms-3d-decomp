#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k8b_entries_dtor_801aeb28.c"
struct K8bEntry { char pad0[20]; char name[4]; };
struct K8bEntryVector { Ptr32<struct K8bEntry> begin; Ptr32<struct K8bEntry> end; };
extern char lbl_80414170[];
extern char lbl_804141b8[];
extern void w3d_auto_80355a14(Ptr32<struct K8bEntry> entry);
extern void w3d_string_base_finish(Ptr32<void> string);
extern void w3d_string_release(Ptr32<void> string);
extern void w3d_handle_storage_release(Ptr32<void> block);
extern void w3d_actor_node_destroy(Ptr32<void> node, int flags);
extern void w3d_actor_member_delete_backend(Ptr32<void> object);

static inline void k8b_for_each(Ptr32<struct K8bEntry> first, Ptr32<struct K8bEntry> last, Ptr32<void (Ptr32<struct K8bEntry>)> fn)
{
    while (first != last)
        fn(first++);
}

void w3d_k8b_entries_dtor_801aeb28(Ptr32<char> self, unsigned int flags)
{
    Ptr32<struct K8bEntryVector> entries = (Ptr32<struct K8bEntryVector>)(self + 20);
    *(Ptr32<Ptr32<void>>)self = lbl_80414170;
    k8b_for_each(entries->begin, entries->end, w3d_auto_80355a14);
    {
        Ptr32<struct K8bEntryVector> vector = (Ptr32<struct K8bEntryVector>)(self + 20);
        Ptr32<struct K8bEntry> cursor = vector->begin;
        Ptr32<struct K8bEntry> end = vector->end;
        Ptr32<void> node = self + 4;
        for (; cursor != end;) {
            Ptr32<char> name = cursor->name;
            cursor++;
            w3d_string_base_finish(name);
            w3d_string_release(name);
        }
        if (vector->begin)
            w3d_handle_storage_release(vector->begin);
        *(Ptr32<Ptr32<void>>)self = lbl_804141b8;
        w3d_actor_node_destroy(node, 0);
    }
    if (flags & 1)
        w3d_actor_member_delete_backend(self);
}

}
