struct S19Message { unsigned short id; unsigned short pad2; void *type; };
struct S19Cache { int words[2]; };
extern struct S19Cache lbl_804aca8c;
extern struct S19Cache lbl_804aca94;
extern unsigned char lbl_8040db38[];
extern void *lbl_804b1754;
extern int w3d_auto_8015fb34(void *, struct S19Message *);
extern int w3d_message_id_equals_cache(int, struct S19Cache *);
extern int w3d_auto_80024f64(void *);
extern void w3d_set_handle_owner_80024f00(void *, int);
extern void FUN_80024ea0(void *);
extern void *FUN_801613f0(void *, int);
extern short w3d_cached_message_id(struct S19Cache *, int);
extern int w3d_message_post_current(void *);

int s19_handle_message_80024dcc(void *self, struct S19Message *msg)
{
    if (msg->id == 64) {
        if (w3d_auto_8015fb34(self, msg) >= 0)
            FUN_80024ea0(self);
        else
            return 0x80004005;
    } else {
        if (!w3d_message_id_equals_cache(msg->id, &lbl_804aca8c))
            return w3d_auto_8015fb34(self, msg);
        w3d_set_handle_owner_80024f00(self, w3d_auto_80024f64(self) ^ 1);
        {
            struct S19Message *m = (struct S19Message *)FUN_801613f0(lbl_804b1754, 8);
            m->id = w3d_cached_message_id(&lbl_804aca94, 1);
            m->type = lbl_8040db38;
            w3d_message_post_current(m);
        }
    }
    return 0;
}
