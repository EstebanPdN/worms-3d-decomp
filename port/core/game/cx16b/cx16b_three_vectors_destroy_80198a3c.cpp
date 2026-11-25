#include "w3d_ptr.h"
#line 1 "cx16b_three_vectors_destroy_80198a3c.cpp"
/* New technique after k8b near miss: ordered single storage snapshots keep
   the two empty record walks ahead of their storage loads, as observed.
   Volatile qualification reconstructs scheduling, not hardware semantics. */
extern "C" {
typedef struct Cx16bObject { Ptr32<Ptr32<void>> vtable; } Cx16bObject;
struct Cx16bVector { Ptr32<char> begin; Ptr32<char> end; };
extern char lbl_80413428[];
extern char lbl_80413470[];
extern int fn_80199c70(Ptr32<char> self, int mode);
extern void fn_801907d0(Ptr32<void> block);
extern void fn_80210990(Ptr32<void> node, int flags);
extern void fn_801fe1f8(Ptr32<void> object);

void w3d_cx16b_three_vectors_destroy_80198a3c(Ptr32<char> self, unsigned int flags)
{
    *(Ptr32<Ptr32<char>>)self = lbl_80413428;
    fn_80199c70(self, -1);
    if (*(Ptr32<Ptr32<Cx16bObject>>)(self + 20))
        ((Ptr32<void (Ptr32<Cx16bObject>)>)(*(Ptr32<Ptr32<Cx16bObject>>)(self + 20))->vtable[4])(*(Ptr32<Ptr32<Cx16bObject>>)(self + 20));
    {
        int zero = 0;
        Ptr32<struct Cx16bVector> items = (Ptr32<struct Cx16bVector>)(self + 68);
        Ptr32<struct Cx16bVector> middle = (Ptr32<struct Cx16bVector>)(self + 48);
        Ptr32<struct Cx16bVector> last = (Ptr32<struct Cx16bVector>)(self + 32);
        Ptr32<char> cursor;
        Ptr32<char> end;
        Ptr32<void> node;
        *(Ptr32<int>)(self + 20) = zero;
        cursor = items->begin;
        end = items->end;
        node = self + 4;
        for (; cursor != end; cursor += 16) {
            if (*(Ptr32<Ptr32<void>>)cursor)
                fn_801907d0(*(Ptr32<Ptr32<void>>)cursor);
        }
        if (items->begin)
            fn_801907d0(items->begin);
        {
            Ptr32<char> tail = middle->end;
            Ptr32<char> walk;
            walk = *(Ptr32<Ptr32<char>>)(self + 48);
            while (walk != tail)
                walk += 24;
        }
        Ptr32<void> middle_storage = *(Ptr32<Ptr32<void> volatile>)&middle->begin;
        if (middle_storage)
            fn_801907d0(middle_storage);
        {
            Ptr32<char> tail = last->end;
            Ptr32<char> walk;
            walk = *(Ptr32<Ptr32<char>>)(self + 32);
            while (walk != tail)
                walk += 24;
        }
        Ptr32<void> last_storage = *(Ptr32<Ptr32<void> volatile>)&last->begin;
        if (last_storage)
            fn_801907d0(last_storage);
        if (*(Ptr32<Ptr32<Cx16bObject>>)(self + 20))
            ((Ptr32<void (Ptr32<Cx16bObject>)>)(*(Ptr32<Ptr32<Cx16bObject>>)(self + 20))->vtable[4])(*(Ptr32<Ptr32<Cx16bObject>>)(self + 20));
        *(Ptr32<Ptr32<char>>)self = lbl_80413470;
        fn_80210990(node, 0);
    }
    if (flags & 1)
        fn_801fe1f8(self);
}

}


