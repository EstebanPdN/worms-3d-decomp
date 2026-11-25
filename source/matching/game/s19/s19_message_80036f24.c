struct S19Message { unsigned short id; };
extern int w3d_auto_8016293c(void *, struct S19Message *);
extern void FUN_800370cc(void *);

int s19_handle_message_80036f24(void *self, struct S19Message *msg)
{
    if (msg->id == 64) {
        if (w3d_auto_8016293c(self, msg) >= 0) {
            FUN_800370cc(self);
            return 0;
        }
        return 0x80004005;
    }
    return w3d_auto_8016293c(self, msg);
}
