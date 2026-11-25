struct S19Message { unsigned short id; };
struct S19Cache { int words[2]; };
extern struct S19Cache lbl_804ad050;
extern struct S19Cache lbl_804ad058;
extern int w3d_auto_8015fb34(void *, struct S19Message *);
extern int w3d_message_id_equals_cache(int, struct S19Cache *);
extern void FUN_80037d14(void *);
extern void w3d_release_interface_800382a8(void *);
extern void FUN_80038354(void *);
extern void FUN_800382f4(void *);

int s19_handle_message_80037bac(void *self, struct S19Message *msg)
{
    switch (msg->id) {
    case 64:
        if (w3d_auto_8015fb34(self, msg) >= 0)
            FUN_80037d14(self);
        else
            return 0x80004005;
        break;
    case 66:
        w3d_release_interface_800382a8(self);
        return w3d_auto_8015fb34(self, msg);
    default:
        if (w3d_message_id_equals_cache(msg->id, &lbl_804ad050)) {
            FUN_80038354(self);
            break;
        }
        if (!w3d_message_id_equals_cache(msg->id, &lbl_804ad058))
            return w3d_auto_8015fb34(self, msg);
        FUN_800382f4(self);
        break;
    }
    return 0;
}
