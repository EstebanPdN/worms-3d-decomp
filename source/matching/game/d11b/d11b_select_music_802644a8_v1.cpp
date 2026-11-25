// Partial music owner, service and callback views; full original identities/sizes unknown.
struct d11b_Music;
struct d11b_MusicTable {
    unsigned int unknown00[4]; void (*release)(d11b_Music *);
    void (*start)(d11b_Music *); unsigned int unknown18[3]; int (*playing)(d11b_Music *);
};
struct d11b_Music { d11b_MusicTable *vtable; };
struct d11b_MusicHandle {
    d11b_Music *value;
    d11b_Music *get() const { return value; }
    int playing() const { return value->vtable->playing(value); }
    void reset(d11b_Music *next) { if(value)value->vtable->release(value);value=next; }
};
struct d11b_MusicOwner { unsigned char unknown00[200]; d11b_MusicHandle music; unsigned int unknowncc; int mode; };
struct d11b_MusicService;
struct d11b_MusicServiceTable {
    unsigned int unknown00[23]; void (*create)(d11b_MusicService *,const char *,d11b_Music **);
    unsigned int unknown60; void (*fade)(d11b_MusicService *,d11b_Music **,unsigned int);
};
struct d11b_MusicService { d11b_MusicServiceTable *vtable; };
struct d11b_MusicServices { unsigned char unknown00[108]; d11b_MusicService *audio; };
extern d11b_MusicServices *d11b_services_804b1788;
extern const char d11b_normal_803caf0c[],d11b_instrumental_803cb288[],d11b_vocal_803cb298[],d11b_intro_803cb2a0[],d11b_credits_803cb2b0[],d11b_wormsong_803cb2b8[];
extern "C" int d11b_compare_text_802ef074(const char *,const char *);
extern "C" void d11b_select_music_802644a8(d11b_MusicOwner *self,const char *mode) {
    int old=self->mode;
    self->mode=3;
    const char *track=0;
    int comparison=d11b_compare_text_802ef074(mode,d11b_normal_803caf0c);
    if ((self->mode=comparison)==0) {track=d11b_instrumental_803cb288;}
    else if (d11b_compare_text_802ef074(mode,d11b_vocal_803cb298)==0) {track=d11b_intro_803cb2a0;self->mode=1;}
    else if (d11b_compare_text_802ef074(mode,d11b_credits_803cb2b0)==0) {self->mode=2;track=d11b_wormsong_803cb2b8;}
    if (!track) self->mode=3;
    if (old!=self->mode) {
        if (self->music.get()) {
            if (self->music.playing())
                d11b_services_804b1788->audio->vtable->fade(d11b_services_804b1788->audio,&self->music.value,!track?200:2000);
            else self->music.reset(0);
        }
        if (track) {
            d11b_services_804b1788->audio->vtable->create(d11b_services_804b1788->audio,track,&self->music.value);
            self->music.value->vtable->start(self->music.value);
        }
    }
}
