/* Rope camera/input mode transitions expressed as string messages. */
extern "C" {
struct S5RopeMessageName { unsigned value; const char *text; };
extern S5RopeMessageName w3d_rope_message_804ae950,w3d_rope_message_804ae948;
extern const char w3d_str_80388170[],w3d_str_8038817c[],w3d_str_80388188[],w3d_str_80388194[];
extern void *w3d_message_pool_804b1754;
void *w3d_message_allocate_801613f0(void *,unsigned);
unsigned w3d_cached_message_id(S5RopeMessageName *,int);
void *w3d_message_string_init(void *,unsigned short,const char *);
int w3d_message_post_current(void *);
static inline void s5_rope_post(S5RopeMessageName *name,const char *text)
{
    void *message=w3d_message_allocate_801613f0(w3d_message_pool_804b1754,12);
    w3d_message_post_current(w3d_message_string_init(message,w3d_cached_message_id(name,1),text));
}
void w3d_rope_enter_mode_800d0d6c(void *unused)
{
    void *message1=w3d_message_allocate_801613f0(w3d_message_pool_804b1754,12);
    w3d_message_post_current(w3d_message_string_init(message1,w3d_cached_message_id(&w3d_rope_message_804ae950,1),w3d_str_80388170));
    void *message2=w3d_message_allocate_801613f0(w3d_message_pool_804b1754,12);
    w3d_message_post_current(w3d_message_string_init(message2,w3d_cached_message_id(&w3d_rope_message_804ae948,1),w3d_str_8038817c));
    void *message3=w3d_message_allocate_801613f0(w3d_message_pool_804b1754,12);
    w3d_message_post_current(w3d_message_string_init(message3,w3d_cached_message_id(&w3d_rope_message_804ae948,1),w3d_str_80388188));
    void *message4=w3d_message_allocate_801613f0(w3d_message_pool_804b1754,12);
    w3d_message_post_current(w3d_message_string_init(message4,w3d_cached_message_id(&w3d_rope_message_804ae948,1),w3d_str_80388194));
}
void w3d_rope_exit_mode_800d0e60(void *unused)
{
    void *message5=w3d_message_allocate_801613f0(w3d_message_pool_804b1754,12);
    w3d_message_post_current(w3d_message_string_init(message5,w3d_cached_message_id(&w3d_rope_message_804ae950,1),w3d_str_8038817c));
    void *message6=w3d_message_allocate_801613f0(w3d_message_pool_804b1754,12);
    w3d_message_post_current(w3d_message_string_init(message6,w3d_cached_message_id(&w3d_rope_message_804ae950,1),w3d_str_80388188));
    void *message7=w3d_message_allocate_801613f0(w3d_message_pool_804b1754,12);
    w3d_message_post_current(w3d_message_string_init(message7,w3d_cached_message_id(&w3d_rope_message_804ae950,1),w3d_str_80388194));
    void *message8=w3d_message_allocate_801613f0(w3d_message_pool_804b1754,12);
    w3d_message_post_current(w3d_message_string_init(message8,w3d_cached_message_id(&w3d_rope_message_804ae948,1),w3d_str_80388170));
}
}
