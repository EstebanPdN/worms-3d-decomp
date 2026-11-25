/* New technique after k8b near miss: ordered single storage snapshots keep
   the two empty record walks ahead of their storage loads, as observed.
   Volatile qualification reconstructs scheduling, not hardware semantics. */
extern "C" {
typedef struct Cx16bObject { void **vtable; } Cx16bObject;
struct Cx16bVector { char *begin; char *end; };
extern char lbl_80413428[];
extern char lbl_80413470[];
extern int fn_80199c70(char *self, int mode);
extern void fn_801907d0(void *block);
extern void fn_80210990(void *node, int flags);
extern void fn_801fe1f8(void *object);

void w3d_cx16b_three_vectors_destroy_80198a3c(char *self, unsigned int flags)
{
    *(char **)self = lbl_80413428;
    fn_80199c70(self, -1);
    if (*(Cx16bObject **)(self + 20))
        ((void (*)(Cx16bObject *))(*(Cx16bObject **)(self + 20))->vtable[4])(*(Cx16bObject **)(self + 20));
    {
        int zero = 0;
        struct Cx16bVector *items = (struct Cx16bVector *)(self + 68);
        struct Cx16bVector *middle = (struct Cx16bVector *)(self + 48);
        struct Cx16bVector *last = (struct Cx16bVector *)(self + 32);
        char *cursor;
        char *end;
        void *node;
        *(int *)(self + 20) = zero;
        cursor = items->begin;
        end = items->end;
        node = self + 4;
        for (; cursor != end; cursor += 16) {
            if (*(void **)cursor)
                fn_801907d0(*(void **)cursor);
        }
        if (items->begin)
            fn_801907d0(items->begin);
        {
            char *tail = middle->end;
            char *walk;
            walk = *(char **)(self + 48);
            while (walk != tail)
                walk += 24;
        }
        void *middle_storage = *(void * volatile *)&middle->begin;
        if (middle_storage)
            fn_801907d0(middle_storage);
        {
            char *tail = last->end;
            char *walk;
            walk = *(char **)(self + 32);
            while (walk != tail)
                walk += 24;
        }
        void *last_storage = *(void * volatile *)&last->begin;
        if (last_storage)
            fn_801907d0(last_storage);
        if (*(Cx16bObject **)(self + 20))
            ((void (*)(Cx16bObject *))(*(Cx16bObject **)(self + 20))->vtable[4])(*(Cx16bObject **)(self + 20));
        *(char **)self = lbl_80413470;
        fn_80210990(node, 0);
    }
    if (flags & 1)
        fn_801fe1f8(self);
}

}
