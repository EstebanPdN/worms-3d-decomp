// Partial service and owner views; original class names/full object sizes unknown.
struct d10b_Audio;
struct d10b_AudioVtable {
    unsigned int unknown00[4];
    void (*release)(d10b_Audio *);
    void (*start)(d10b_Audio *);
    void (*stop)(d10b_Audio *);
    unsigned int unknown1c[6];
    void (*set_volume)(d10b_Audio *, float, int);
};
struct d10b_Audio { d10b_AudioVtable *vtable; };
struct d10b_AudioFactory;
struct d10b_AudioFactoryVtable {
    unsigned int unknown00[23];
    void (*create)(d10b_AudioFactory *, unsigned int, d10b_Audio **);
};
struct d10b_AudioFactory { d10b_AudioFactoryVtable *vtable; };
struct d10b_AudioServices { unsigned char unknown00[108]; d10b_AudioFactory *factory; };
struct d10b_AudioOwner { unsigned char unknown00[204]; d10b_Audio *audio; };
extern d10b_AudioServices *d10b_services_804b1788;
extern char d10b_volume_key_803cae70[];
extern "C" int d10b_read_float_800fc270(const char **, float *);
extern "C" void d10b_replace_audio_802643d0(d10b_AudioOwner *self, unsigned int id) {
    if (self->audio) self->audio->vtable->stop(self->audio);
    if (self->audio) self->audio->vtable->release(self->audio);
    self->audio=0;
    d10b_services_804b1788->factory->vtable->create(d10b_services_804b1788->factory,id,&self->audio);
    self->audio->vtable->start(self->audio);
    const char *key=d10b_volume_key_803cae70;
    float volume;
    d10b_read_float_800fc270(&key,&volume);
    self->audio->vtable->set_volume(self->audio,volume,1);
}
