struct S19Message { unsigned short id; };
struct S19Cache { int words[2]; };
extern struct S19Cache lbl_804acb94;
extern int w3d_auto_8016293c(void *, struct S19Message *);
extern int w3d_message_id_equals_cache(int, struct S19Cache *);
extern void w3d_auto_80027d20(void *);

int s19_handle_message_8002779c(void *self, struct S19Message *msg)
{
    if (msg->id == 64) {
        if (w3d_auto_8016293c(self, msg) >= 0) {
            w3d_auto_80027d20(self);
            return 0;
        }
        return 0x80004005;
    }
    w3d_message_id_equals_cache(msg->id, &lbl_804acb94);
    return w3d_auto_8016293c(self, msg);
}
