/* Award-movie lookup and playback service message bindings. */
struct S5MovieString { const char *text; S5MovieString(); ~S5MovieString(); };
struct S5MovieKey { const char *text; };
extern "C" {
void w3d_string_default(S5MovieString *);
void w3d_string_assign(void *,const char *);
void w3d_string_base_finish(S5MovieString *);
void w3d_string_release(S5MovieString *);
void w3d_read_string_800fc2b0(S5MovieKey *,const char **);
void w3d_write_string_800fc550(S5MovieKey *,const char *);
int w3d_movie_play_named_800c6660(void *,const char *);
extern const char w3d_str_803877f4[],w3d_str_80387410[];
}
inline S5MovieString::S5MovieString() { w3d_string_default(this); }
inline S5MovieString::~S5MovieString() { w3d_string_base_finish(this); w3d_string_release(this); }
struct S5LocalMovie { S5MovieString string; unsigned unknown; };
extern "C" {
/* 0x800c67f0: five string-local setup ordering differences remain after four attempts. */
#if 0
void w3d_movie_play_award_800c67f0(void *service)
{
    S5LocalMovie movie;
    S5MovieKey input; input.text=w3d_str_803877f4;
    const char *text;
    w3d_read_string_800fc2b0(&input,&text);
    w3d_string_assign(&movie.string.text,text);
    S5MovieKey output; output.text=w3d_str_803877f4;
    w3d_write_string_800fc550(&output,w3d_str_80387410);
    w3d_movie_play_named_800c6660(service,movie.string.text);
}
#endif
struct S5MovieCachedName { unsigned value; const char *name; };
struct S5MovieService { unsigned char reserved[28]; int bindings[8]; S5MovieString name; void *player; int state; };
extern S5MovieService *w3d_movie_service_804aae0c;
extern S5MovieCachedName w3d_movie_name_804ae794,w3d_movie_name_804ae79c,w3d_movie_name_804ae7a4,w3d_movie_name_804ae7ac,w3d_movie_name_804ae7cc,w3d_movie_name_804ae7ec,w3d_movie_name_804ae7b4;
unsigned w3d_cached_message_id(S5MovieCachedName *,int);
void w3d_message_bind_80162024(void *,unsigned short *,int *);
void *w3d_auto_802e0210(void);
/* 0x800c6a20: the final binding argument moves remain reversed after four attempts. */
#if 0
void w3d_movie_service_attach_800c6a20(S5MovieService *service)
{
    w3d_movie_service_804aae0c=service;
    service->player=0;
    service->state=0;
    w3d_string_assign(&service->name,w3d_str_80387410);
    unsigned short id0=w3d_cached_message_id(&w3d_movie_name_804ae794,1);
    w3d_message_bind_80162024(service,&id0,&service->bindings[0]);
    unsigned short id1=w3d_cached_message_id(&w3d_movie_name_804ae79c,1);
    w3d_message_bind_80162024(service,&id1,&service->bindings[1]);
    unsigned short id2=w3d_cached_message_id(&w3d_movie_name_804ae7a4,1);
    w3d_message_bind_80162024(service,&id2,&service->bindings[2]);
    unsigned short id3=w3d_cached_message_id(&w3d_movie_name_804ae7ac,1);
    w3d_message_bind_80162024(service,&id3,&service->bindings[3]);
    unsigned short id4=w3d_cached_message_id(&w3d_movie_name_804ae7cc,1);
    w3d_message_bind_80162024(service,&id4,&service->bindings[4]);
    unsigned short id5=w3d_cached_message_id(&w3d_movie_name_804ae7ec,1);
    w3d_message_bind_80162024(service,&id5,&service->bindings[5]);
    struct { unsigned short value; } id6;
    id6.value=w3d_cached_message_id(&w3d_movie_name_804ae7b4,1);
    int *last_binding=service->bindings+6;
    w3d_message_bind_80162024(service,&id6.value,last_binding);
    service->player=w3d_auto_802e0210();
}
#endif
}
