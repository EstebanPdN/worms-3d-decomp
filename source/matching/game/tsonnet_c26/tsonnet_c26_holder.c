struct TsonnetC26Iface { void **vtable; };
struct TsonnetC26Holder { char head[32]; unsigned int flags; struct TsonnetC26Iface *held; };
int tsonnet_c26_set_held_801f3044(struct TsonnetC26Holder *self, struct TsonnetC26Iface *p) {
 if (p) ((void (*)(struct TsonnetC26Iface *))p->vtable[3])(p);
 if (self->held) ((void (*)(struct TsonnetC26Iface *))self->held->vtable[4])(self->held);
 self->held = p;
 self->flags &= 0x7fffffff;
 return 0;
}
