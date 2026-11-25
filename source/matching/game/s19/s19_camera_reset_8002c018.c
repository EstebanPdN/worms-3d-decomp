#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef struct S19Iface { void **vtable; } S19Iface;
typedef void (*S19Set)(S19Iface *self, void *arg);
struct S19Message { unsigned short id; unsigned short pad2; void *type; };
struct S19Cache { int words[2]; };
struct S19Ctx { char pad0[48]; S19Iface *camera; char pad52[136]; unsigned flags; };
extern struct S19Ctx *lbl_804b1788;
extern void *lbl_804b1754;
extern struct S19Cache lbl_804acc90;
extern unsigned char lbl_8040db38[];
extern void *FUN_801613f0(void *, int);
extern short w3d_cached_message_id(struct S19Cache *, int);
extern int w3d_message_post_current(void *);

void s19_post_camera_reset_8002c018(void *self)
{
    struct S19Message *m;
    ((S19Set)lbl_804b1788->camera->vtable[10])(lbl_804b1788->camera, (char *)self + 100);
    ((S19Set)lbl_804b1788->camera->vtable[10])(lbl_804b1788->camera, (char *)self + 128);
    lbl_804b1788->flags &= ~4u;
    m = (struct S19Message *)FUN_801613f0(lbl_804b1754, 8);
    m->id = w3d_cached_message_id(&lbl_804acc90, 1);
    m->type = lbl_8040db38;
    w3d_message_post_current(m);
}
