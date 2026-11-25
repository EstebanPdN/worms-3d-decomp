#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef struct S19Iface { void **vtable; } S19Iface;
typedef void (*S19IfaceFn)(S19Iface *self, int arg);
struct S19Message { unsigned short id; };
struct S19Cache { int words[2]; };
extern struct S19Cache lbl_804ae184;
extern int w3d_auto_8015fb34(void *, struct S19Message *);
extern int w3d_message_id_equals_cache(int, struct S19Cache *);
extern void FUN_800a20cc(void *);

int s19_handle_message_800a1ca8(void *self, struct S19Message *msg)
{
    if (msg->id == 64) {
        if (w3d_auto_8015fb34(self, msg) >= 0) {
            FUN_800a20cc(self);
            return 0;
        }
        return 0x80004005;
    }
    if (w3d_message_id_equals_cache(msg->id, &lbl_804ae184)) {
        FIELD(self, int, 148) = 0;
        ((S19IfaceFn)FIELD(self, S19Iface *, 52)->vtable[22])(FIELD(self, S19Iface *, 52), 0);
    }
    return w3d_auto_8015fb34(self, msg);
}
