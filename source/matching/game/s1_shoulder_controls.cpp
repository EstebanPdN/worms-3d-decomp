/* Observed shoulder-camera input messages and view selection. */
extern "C" {
extern void *w3d_queue_804b1754,*w3d_view_804aa8c8;
extern int w3d_flag_804ab420;
extern unsigned int w3d_message_804ad4b0,w3d_message_804ad4b8,w3d_message_804ad4c0,w3d_message_804ad4c8;
extern const char w3d_str_80378268[],w3d_str_80378270[],w3d_str_8037827c[],w3d_str_80378288[],w3d_str_80378298[],w3d_str_803782b0[],w3d_str_803782c0[],w3d_str_803782cc[],w3d_str_803782d4[],w3d_str_803782dc[];
extern const float w3d_f32_803782e4[];
void *w3d_fn_801613f0(void *,unsigned int);
unsigned int w3d_cached_message_id(void *,int);
void *w3d_message_string_init(void *,unsigned short,const char *);
int w3d_message_post_current(void *);
void w3d_fn_800d308c(void *,void *);
void w3d_fn_800d5028(void *);
int w3d_fn_8015f65c(unsigned short,void *);
int w3d_fn_80035714(void *,const char *,float);
void w3d_fn_80052154(void *self,void *other)
{
    if(!w3d_flag_804ab420) {
    void *message0=w3d_fn_801613f0(w3d_queue_804b1754,12);
    unsigned short id0=w3d_cached_message_id(&w3d_message_804ad4b0,1);
    w3d_message_post_current(w3d_message_string_init(message0,id0,w3d_str_80378268));
    }
    void *message1=w3d_fn_801613f0(w3d_queue_804b1754,12);
    unsigned short id1=w3d_cached_message_id(&w3d_message_804ad4b0,1);
    w3d_message_post_current(w3d_message_string_init(message1,id1,w3d_str_80378270));
    void *message2=w3d_fn_801613f0(w3d_queue_804b1754,12);
    unsigned short id2=w3d_cached_message_id(&w3d_message_804ad4b0,1);
    w3d_message_post_current(w3d_message_string_init(message2,id2,w3d_str_8037827c));
    void *message3=w3d_fn_801613f0(w3d_queue_804b1754,12);
    unsigned short id3=w3d_cached_message_id(&w3d_message_804ad4b0,1);
    w3d_message_post_current(w3d_message_string_init(message3,id3,w3d_str_80378288));
    void *message4=w3d_fn_801613f0(w3d_queue_804b1754,12);
    unsigned short id4=w3d_cached_message_id(&w3d_message_804ad4b8,1);
    w3d_message_post_current(w3d_message_string_init(message4,id4,w3d_str_80378298));
    void *message5=w3d_fn_801613f0(w3d_queue_804b1754,12);
    unsigned short id5=w3d_cached_message_id(&w3d_message_804ad4b8,1);
    w3d_message_post_current(w3d_message_string_init(message5,id5,w3d_str_803782b0));
    void *message6=w3d_fn_801613f0(w3d_queue_804b1754,12);
    unsigned short id6=w3d_cached_message_id(&w3d_message_804ad4b8,1);
    w3d_message_post_current(w3d_message_string_init(message6,id6,w3d_str_803782c0));
    void *message7=w3d_fn_801613f0(w3d_queue_804b1754,12);
    unsigned short id7=w3d_cached_message_id(&w3d_message_804ad4b8,1);
    w3d_message_post_current(w3d_message_string_init(message7,id7,w3d_str_803782cc));
    w3d_fn_800d308c(self,other);
    w3d_fn_800d5028(self);
}
void w3d_fn_80052360(void *self,unsigned short *message)
{
    unsigned short id=*message;
    if(w3d_fn_8015f65c(id,&w3d_message_804ad4c8)) {
        w3d_fn_80035714(w3d_view_804aa8c8,w3d_str_803782d4,w3d_f32_803782e4[0]);
    } else if(w3d_fn_8015f65c(id,&w3d_message_804ad4c0)) {
        w3d_fn_80035714(w3d_view_804aa8c8,w3d_str_803782dc,w3d_f32_803782e4[0]);
    }
}
}
