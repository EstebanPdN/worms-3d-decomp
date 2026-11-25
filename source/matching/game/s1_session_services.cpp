/* Observed session service construction, completion, and sound-table application. */
extern "C" {
struct W3dS1SessionInterface {void (**vtable)();};
struct W3dS1SessionEnvironment {char unknown[76];unsigned int flags;char unknown50[28];W3dS1SessionInterface *sound;};
struct W3dS1ServiceMessage {unsigned short id,reserved;void *vtable;};
extern W3dS1SessionEnvironment *w3d_environment_804b1788;
extern void *w3d_manager_804b178c,*w3d_queue_804b1754;
extern unsigned int w3d_message_804ad854,w3d_sound_id_804aa840;
extern unsigned char w3d_vtable_8040db38[],w3d_type_80410980[],w3d_type_80411a20[],w3d_table_803ebc18[],w3d_table_803eee68[];
unsigned int *w3d_fn_8020b680(void *);
unsigned int w3d_fn_80164514(void *,void *,unsigned int);
unsigned int *w3d_fn_80164fc8(unsigned int);
W3dS1ServiceMessage *w3d_fn_801613f0(void *,unsigned int);
unsigned int w3d_cached_message_id(void *,int);
int w3d_message_post_current(void *);
W3dS1SessionInterface *w3d_auto_8020b648(void);
void *w3d_slots_shared(void);
void w3d_fn_80198744(void *);
unsigned int w3d_fn_8006d4cc(unsigned int *self,void *type)
{
    unsigned int *owner;
    if(self[55]==0xffffffffU) {
        owner=w3d_fn_8020b680(w3d_type_80410980);
        self[55]=w3d_fn_80164514(w3d_manager_804b178c,owner,0x0babe000);
    } else owner=w3d_fn_80164fc8(self[55]);
    void *object=w3d_fn_8020b680(type);
    return w3d_fn_80164514(w3d_manager_804b178c,object,owner[5]);
}
void w3d_fn_8006d550(void *unused)
{
    W3dS1ServiceMessage *message=w3d_fn_801613f0(w3d_queue_804b1754,8);
    message->id=w3d_cached_message_id(&w3d_message_804ad854,1);message->vtable=w3d_vtable_8040db38;
    w3d_message_post_current(message);
    void *type=w3d_type_80411a20;
    w3d_environment_804b1788->flags|=0x40000000;
    W3dS1SessionInterface *manager=w3d_auto_8020b648();
    W3dS1SessionInterface *service=((W3dS1SessionInterface *(*)(W3dS1SessionInterface *,void *))manager->vtable[23])(manager,type);
    ((void (*)(W3dS1SessionInterface *))service->vtable[11])(service);
    w3d_fn_80198744(w3d_slots_shared());
    W3dS1SessionInterface *sound=w3d_environment_804b1788->sound;
    if(sound)((void (*)(W3dS1SessionInterface *))sound->vtable[22])(sound);
}
void w3d_fn_8006df98(void *unused)
{
    W3dS1SessionInterface *sound=w3d_environment_804b1788->sound;
    if(sound) {
        ((void (*)(W3dS1SessionInterface *,unsigned int,void *))sound->vtable[15])(sound,w3d_sound_id_804aa840,w3d_table_803ebc18);
        sound=w3d_environment_804b1788->sound;
        ((void (*)(W3dS1SessionInterface *,unsigned int,void *))sound->vtable[16])(sound,w3d_sound_id_804aa840,w3d_table_803eee68);
    }
}
}
