/* Observed session pause entry and return-to-menu messages. */
extern "C" {
struct W3dS1PauseSound;
struct W3dS1PauseSoundTable {void (*unused[9])();void (*pause)(W3dS1PauseSound *,int);void (*resume)(W3dS1PauseSound *,int);};
struct W3dS1PauseSound {W3dS1PauseSoundTable *vtable;};
struct W3dS1PauseContext {char unknown[108];W3dS1PauseSound *sound;};
struct W3dS1PauseGame {char unknown[24];void *session;};
struct W3dS1PauseRoot {char unknown[36];W3dS1PauseGame *game;};
struct W3dS1PauseMessage {unsigned short id,reserved;void *vtable;};
extern W3dS1PauseContext *w3d_context_804b1788;
extern W3dS1PauseRoot *w3d_root_804abac0;
extern void *w3d_queue_804b1754;
extern unsigned char w3d_vtable_8040db38[];
extern unsigned int w3d_message_804ad83c,w3d_message_804ad804,w3d_message_804ad734,w3d_message_804ad85c,w3d_message_804ad834,w3d_message_804ad7f4,w3d_message_804ad73c,w3d_message_804ad80c,w3d_message_804ad7fc;
extern const char w3d_str_8037bea0[],w3d_str_8037bb14[],w3d_str_8037bd3c[],w3d_str_8037bed4[],w3d_str_8037bedc[],w3d_str_8037beec[];
int w3d_fn_8015ccbc(void *);
void w3d_fn_800fc230(const char **,int *);
W3dS1PauseMessage *w3d_fn_801613f0(void *,unsigned int);
unsigned int w3d_cached_message_id(void *,int);
void w3d_message_post_current(void *);
void *w3d_message_string_init(void *,unsigned short,const char *);
void w3d_app_leave_801298cc(void *);
void w3d_app_enter_80129878(void *);
void w3d_fn_800a7e14(int,const char *);
int w3d_scene_timer_is_one_8006e71c(void);
void w3d_string_from_text(void *,const char *);
void w3d_string_assign(void *,const char *);
void w3d_string_base_finish(void *);
void w3d_string_release(void *);
int w3d_fn_8021eb00(void *);
void w3d_fn_800fde38(void);
struct W3dS1PauseString {const char *text;int unknown;W3dS1PauseString(const char *s){w3d_string_from_text(this,s);}~W3dS1PauseString(){w3d_string_base_finish(this);w3d_string_release(this);}};
static inline void pause_post(unsigned int *id)
{
    W3dS1PauseMessage *message=w3d_fn_801613f0(w3d_queue_804b1754,8);
    message->id=w3d_cached_message_id(id,1);message->vtable=w3d_vtable_8040db38;w3d_message_post_current(message);
}
static inline void pause_text(unsigned int *id,const char *text)
{
    void *message=w3d_fn_801613f0(w3d_queue_804b1754,12);
    unsigned short code=w3d_cached_message_id(id,1);
    w3d_message_post_current(w3d_message_string_init(message,code,text));
}
#if 0 /* Excluded: shared literal base caching and scheduling differ after two attempts. */
void w3d_fn_8006be38(unsigned int *self)
{
    const char *key;int active;
    if(w3d_fn_8015ccbc(w3d_context_804b1788)) {
        self[60]&=~0x00800000U;active=0;
        key=w3d_str_8037bea0;w3d_fn_800fc230(&key,&active);
        if(!active)pause_post(&w3d_message_804ad83c);
        pause_post(&w3d_message_804ad804);pause_text(&w3d_message_804ad734,"");
        w3d_app_leave_801298cc(w3d_context_804b1788);
        W3dS1PauseSound *sound=w3d_context_804b1788->sound;
        if(sound)sound->vtable->resume(sound,0);
        w3d_fn_800a7e14(5,"");
    }
}
#endif
#if 0 /* Excluded: temporary string lifetimes and saved-register allocation differ after two attempts. */
void w3d_fn_8006bf7c(unsigned int *self)
{
    if(self[60]&0x00800000U)goto finish;
    if(self[60]&0x00400000U)goto finish;
    if(w3d_scene_timer_is_one_8006e71c())goto finish;
    self[60]|=0x00400000U;
    if(self[52]==7) {
        int ordinary=1;
        pause_post(&w3d_message_804ad85c);self[60]|=0x00800000U;pause_post(&w3d_message_804ad834);
        w3d_fn_800a7e14(5,w3d_str_8037bd3c);
        W3dS1PauseString name(w3d_str_8037bed4);
        if(w3d_root_804abac0 && w3d_root_804abac0->game->session && !w3d_fn_8021eb00(w3d_root_804abac0->game->session)) {
            ordinary=0;w3d_string_assign(&name,w3d_str_8037bedc);
        }
        w3d_fn_800fde38();
        if(ordinary) {
            w3d_app_enter_80129878(w3d_context_804b1788);
            W3dS1PauseSound *sound=w3d_context_804b1788->sound;
            if(sound)sound->vtable->pause(sound,0);
        }
        pause_text(&w3d_message_804ad7f4,name.text);pause_text(&w3d_message_804ad73c,w3d_str_8037beec);
        pause_post(&w3d_message_804ad80c);pause_post(&w3d_message_804ad7fc);
    }
finish:;
}
#endif
}
