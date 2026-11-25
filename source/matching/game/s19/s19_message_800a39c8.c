struct S19Message { unsigned short id; };
struct S19Cache { int words[2]; };
extern struct S19Cache lbl_804ae18c;
extern struct S19Cache lbl_804ae194;
extern struct S19Cache lbl_804ae19c;
extern struct S19Cache lbl_804ae1a4;
extern int w3d_auto_8016293c(void *, struct S19Message *);
extern int w3d_message_cache_equals(struct S19Cache *, int);
extern void FUN_800a3ac4(void *);
extern void s19_visibility_hide_800a3bb4(void *);
extern void s19_visibility_show_800a3bec(void *);
extern void FUN_800a3e84(void *);
extern void FUN_800a3d0c(void *);
extern void s8_show_flags_800a3fa0(void *);

int s19_handle_message_800a39c8(void *self, struct S19Message *msg)
{
    if (msg->id == 64) {
        if (w3d_auto_8016293c(self, msg) >= 0)
            FUN_800a3ac4(self);
        else
            return 0x80004005;
    } else if (w3d_message_cache_equals(&lbl_804ae18c, msg->id)) {
        s19_visibility_hide_800a3bb4(self);
    } else {
        if (w3d_message_cache_equals(&lbl_804ae194, msg->id)) {
            s19_visibility_show_800a3bec(self);
        } else if (w3d_message_cache_equals(&lbl_804ae19c, msg->id)) {
            FUN_800a3e84(self);
            FUN_800a3d0c(self);
        } else if (w3d_message_cache_equals(&lbl_804ae1a4, msg->id)) {
            s8_show_flags_800a3fa0(self);
        }
        return w3d_auto_8016293c(self, msg);
    }
    return 0;
}
