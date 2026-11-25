// desc: Appears to be a deleting destructor that clears an embedded circular list, frees its sentinel node, installs the base vtable, destroys an embedded node and deletes the object when the low flag bit is set.
struct S21Node { int value; struct S21Node *parent; struct S21Node *left; struct S21Node *right; };
struct S21List { int pad; struct S21Node *head; int count; };
struct S21Object { void *vtable; char node[16]; struct S21List list; };
extern char lbl_80419510[];
extern char lbl_80419540[];
extern void fn_8035cc1c(struct S21List *, struct S21Node *);
extern void fn_802134fc(struct S21Node *);
extern void fn_80210990(void *, int);
extern void fn_801fe1f8(struct S21Object *);
void w3d_s21_destroy_list_object_8020e09c(struct S21Object *self, int flags)
{
    struct S21List *list = &self->list;
    self->vtable = lbl_80419510;
    if (list->count) {
        fn_8035cc1c(list, list->head->parent);
        list->head->left = list->head;
        list->head->parent = 0;
        list->head->right = list->head;
        list->count = 0;
    }
    if (list->head)
        fn_802134fc(list->head);
    self->vtable = lbl_80419540;
    fn_80210990(self->node, 0);
    if (flags & 1)
        fn_801fe1f8(self);
}
