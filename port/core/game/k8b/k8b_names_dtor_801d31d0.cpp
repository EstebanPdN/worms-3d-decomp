#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k8b_names_dtor_801d31d0.c"
struct K8bNameVector { Ptr32<Ptr32<void>> begin; Ptr32<Ptr32<void>> end; };
extern char lbl_804164d0[];
extern char lbl_80416518[];
extern void w3d_string_base_finish(Ptr32<void> string);
extern void w3d_string_release(Ptr32<void> string);
extern void w3d_handle_storage_release(Ptr32<void> block);
extern void w3d_destroy_801e828c(Ptr32<void> node, int flags);
extern void w3d_actor_member_delete_backend(Ptr32<void> object);

void w3d_k8b_names_dtor_801d31d0(Ptr32<char> self, unsigned int flags)
{
    *(Ptr32<Ptr32<void>>)self = lbl_804164d0;
    if (*(Ptr32<Ptr32<void>>)(self + 72))
        w3d_handle_storage_release(*(Ptr32<Ptr32<void>>)(self + 72));
    {
        Ptr32<struct K8bNameVector> names = (Ptr32<struct K8bNameVector>)(self + 48);
        Ptr32<Ptr32<void>> cursor = names->begin;
        Ptr32<Ptr32<void>> end = names->end;
        Ptr32<void> text = self + 40;
        Ptr32<void> node = self + 4;
        for (; cursor != end; cursor++) {
            w3d_string_base_finish(cursor);
            w3d_string_release(cursor);
        }
        if (names->begin)
            w3d_handle_storage_release(names->begin);
        w3d_string_base_finish(text);
        w3d_string_release(text);
        *(Ptr32<Ptr32<void>>)self = lbl_80416518;
        w3d_destroy_801e828c(node, 0);
    }
    if (flags & 1)
        w3d_actor_member_delete_backend(self);
}

}
