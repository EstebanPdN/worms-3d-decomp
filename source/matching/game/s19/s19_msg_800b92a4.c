struct S19V3 { float x, y, z; };
struct S19Msg { unsigned short id; unsigned short pad2; void *type; float value; struct S19V3 pos; };
struct S19Cache { int words[2]; };
extern struct S19Cache lbl_804ae510;
extern unsigned char lbl_8040db38[];
extern short w3d_cached_message_id(struct S19Cache *, int);

struct S19Msg *s19_msg_init_800b92a4(struct S19Msg *m, struct S19V3 *pos, float value)
{
    m->id = w3d_cached_message_id(&lbl_804ae510, 1);
    m->type = lbl_8040db38;
    m->pos = *pos;
    m->value = value;
    return m;
}
