/* Chute controller owner checks, message binding and pending-value release. */
struct S5ChuteString { const char *text; unsigned reserved; S5ChuteString(const char *); ~S5ChuteString(); };
extern "C" {
void w3d_string_from_text(void *,const char *);
void w3d_string_base_finish(S5ChuteString *);
void w3d_string_release(S5ChuteString *);
}
inline S5ChuteString::S5ChuteString(const char *text) { w3d_string_from_text(this,text); }
inline S5ChuteString::~S5ChuteString() { w3d_string_base_finish(this); w3d_string_release(this); }
extern "C" {
struct S5ChuteLogic { unsigned char reserved[20]; int id; unsigned reserved24; int owner,binding,pending; };
struct S5ChuteOwner { unsigned char reserved[72]; int chute; };
struct S5ChuteName { unsigned id;const char *text; };
extern const char w3d_str_8038975c[];
extern const float w3d_f32_80389768[];
extern S5ChuteName w3d_chute_name_804aeb8c,w3d_chute_name_804aeb94;
extern void *w3d_message_pool_804b1754;
S5ChuteOwner *w3d_owner_resolve_80164fc8(int);
void w3d_chute_open_800da4e4(S5ChuteLogic *);
void w3d_chute_close_800da750(S5ChuteLogic *);
float w3d_getf_800dc0ac(S5ChuteOwner *);
void w3d_handle_set_name(S5ChuteString *,int *,int);
void *w3d_message_allocate_801613f0(void *,unsigned);
unsigned w3d_cached_message_id(S5ChuteName *,int);
void *w3d_target_id_message_801190b4(void *,unsigned short,int);
void *w3d_int_message_init_80125fdc(void *,unsigned short,int);
int w3d_message_post_current(void *);
int w3d_chute_logic_step_800da388(S5ChuteLogic *logic)
{
    if(logic->owner!=-1) {
        S5ChuteOwner *owner=w3d_owner_resolve_80164fc8(logic->owner);
        if(!owner) { logic->owner=-1; return 0; }
        if(owner->chute) w3d_chute_open_800da4e4(logic);
        else w3d_chute_close_800da750(logic);
    }
    return 0;
}
/* 0x800da3fc: string-local address is cached before construction instead of after it after two attempts. */
#if 0
void w3d_chute_logic_attach_800da3fc(S5ChuteLogic *logic)
{
    {
        struct { const char *text; unsigned reserved; } name;
        w3d_string_from_text(&name.text,w3d_str_8038975c);
        w3d_handle_set_name((S5ChuteString*)&name,&logic->binding,255);
        w3d_string_base_finish((S5ChuteString*)&name);
        w3d_string_release((S5ChuteString*)&name);
    }
    void *message=w3d_message_allocate_801613f0(w3d_message_pool_804b1754,12);
    w3d_message_post_current(w3d_target_id_message_801190b4(message,w3d_cached_message_id(&w3d_chute_name_804aeb8c,1),logic->id));
}
#endif
float w3d_chute_logic_value_800da4a8(S5ChuteLogic *logic)
{
    S5ChuteOwner *owner=w3d_owner_resolve_80164fc8(logic->owner);
    float value;
    if(owner) value=w3d_getf_800dc0ac(owner);
    else value=*w3d_f32_80389768;
    return value;
}
void w3d_chute_close_800da750(S5ChuteLogic *logic)
{
    if(logic->pending) {
        void *message=w3d_message_allocate_801613f0(w3d_message_pool_804b1754,12);
        w3d_message_post_current(w3d_int_message_init_80125fdc(message,w3d_cached_message_id(&w3d_chute_name_804aeb94,1),logic->pending));
        logic->pending=0;
    }
}
}
