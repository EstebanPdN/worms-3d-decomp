/* Observed fast-walk activation messages and inventory decrement. */
extern "C" {
struct W3dS1WalkMessage {unsigned short id,reserved;void *vtable;};
extern void *w3d_queue_804b1754;
extern unsigned char w3d_vtable_8040db38[];
extern unsigned int w3d_message_804ad608,w3d_message_804ad610,w3d_message_804ad5f8;
extern const char w3d_str_8037a214[];
W3dS1WalkMessage *w3d_fn_801613f0(void *,unsigned int);
unsigned int w3d_cached_message_id(void *,int);
void *w3d_int_message_init_80125fdc(void *,unsigned short,unsigned int);
void *w3d_message_int_init(void *,unsigned short,unsigned int);
void w3d_message_post_current(void *);
void w3d_fn_800fc1f0(const char **,unsigned int *);
void w3d_auto_8015fd1c(void *);
#if 0 /* Excluded: argument setup scheduling differs after three attempts. */
void w3d_fn_80068240(unsigned int *self)
{
    const char *key;unsigned int actor;
    if(!self[9]) {
        self[9]=1;
        void *message=w3d_fn_801613f0(w3d_queue_804b1754,12);
        unsigned short id=w3d_cached_message_id(&w3d_message_804ad608,1);
        w3d_message_post_current(w3d_int_message_init_80125fdc(message,id,45));
        unsigned int *active=&actor;
        key=w3d_str_8037a214;w3d_fn_800fc1f0(&key,active);
        message=w3d_fn_801613f0(w3d_queue_804b1754,12);
        id=w3d_cached_message_id(&w3d_message_804ad610,1);
        w3d_message_post_current(w3d_message_int_init(message,id,actor));
        W3dS1WalkMessage *finish=w3d_fn_801613f0(w3d_queue_804b1754,8);
        finish->id=w3d_cached_message_id(&w3d_message_804ad5f8,1);finish->vtable=w3d_vtable_8040db38;
        w3d_message_post_current(finish);
        w3d_auto_8015fd1c(self);
    }
}
#endif
}
