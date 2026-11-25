// desc: Appears to finish a child, notify its registered listener, clear a link field and return the finish result.
struct S21Listener;
struct S21ListenerMethods { void (*reserved[3])(); void (*notify)(S21Listener *, void *); };
struct S21Listener { S21ListenerMethods *methods; };
struct S21Node { char pad[8]; void *child; char pad1[12]; S21Listener *listener; int link; };
extern int fn_80200ca4(void *);
extern "C" int w3d_s21_finish_node_80200c44(S21Node *self)
{
    int result = fn_80200ca4(self->child);
    if (self->listener)
        self->listener->methods->notify(self->listener, self);
    self->link = 0;
    return result;
}
