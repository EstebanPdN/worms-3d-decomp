// Partial music owner, service and callback views; full original identities/sizes unknown.
struct d10b_Music;
struct d10b_MusicTable {
    unsigned int unknown00[4]; void (*release)(d10b_Music *);
    void (*start)(d10b_Music *); unsigned int unknown18[3]; int (*playing)(d10b_Music *);
};
struct d10b_Music { d10b_MusicTable *vtable; };
struct d10b_MusicHandle {
    d10b_Music *value;
    d10b_Music *get() const { return value; }
    int playing() const { return value->vtable->playing(value); }
    void reset(d10b_Music *next) { if(value)value->vtable->release(value);value=next; }
};
struct d10b_MusicOwner { unsigned char unknown00[200]; d10b_MusicHandle music; unsigned int unknowncc; int mode; };
struct d10b_MusicService;
struct d10b_MusicServiceTable {
    unsigned int unknown00[23]; void (*create)(d10b_MusicService *,const char *,d10b_Music **);
    unsigned int unknown60; void (*fade)(d10b_MusicService *,d10b_Music **,unsigned int);
};
struct d10b_MusicService { d10b_MusicServiceTable *vtable; };
struct d10b_MusicServices { unsigned char unknown00[108]; d10b_MusicService *audio; };
extern d10b_MusicServices *d10b_services_804b1788;
extern const char d10b_normal_803caf0c[],d10b_instrumental_803cb288[],d10b_vocal_803cb298[],d10b_intro_803cb2a0[],d10b_credits_803cb2b0[],d10b_wormsong_803cb2b8[];
extern "C" int d10b_compare_text_802ef074(const char *,const char *);
extern "C" void d10b_select_music_802644a8(d10b_MusicOwner *self,const char *mode) {
    int old=self->mode;
    self->mode=3;
    const char *track=0;
    if (d10b_compare_text_802ef074(mode,d10b_normal_803caf0c)==0) {self->mode=0;track=d10b_instrumental_803cb288;}
    else if (d10b_compare_text_802ef074(mode,d10b_vocal_803cb298)==0) {track=d10b_intro_803cb2a0;self->mode=1;}
    else if (d10b_compare_text_802ef074(mode,d10b_credits_803cb2b0)==0) {self->mode=2;track=d10b_wormsong_803cb2b8;}
    if (old!=self->mode) {
        if (self->music.get()) {
            if (self->music.playing()) {
                unsigned int duration=2000;
                if (!track) duration=200;
                d10b_services_804b1788->audio->vtable->fade(d10b_services_804b1788->audio,&self->music.value,duration);
            }
            else self->music.reset(0);
        }
        if (track) {
            d10b_services_804b1788->audio->vtable->create(d10b_services_804b1788->audio,track,&self->music.value);
            self->music.value->vtable->start(self->music.value);
        }
    }
}
