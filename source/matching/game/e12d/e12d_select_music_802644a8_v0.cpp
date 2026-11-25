// Music mode selection for the front-end music owner object.
//
// The owner keeps a mode word at +0xd0 and a single music handle at +0xc8.
// Selection compares the requested mode name against three known tracks,
// stores the resulting mode and then, only when the mode actually changed,
// fades out or releases the current track and starts the newly selected one.
//
// Observed layout (offsets only; the original class names and sizes are not
// recoverable from this body):
//   owner + 0xc8 : music handle (one track pointer)
//   owner + 0xd0 : mode word
//   music object : vtable with release at +0x10, start at +0x14 and
//                  is_playing at +0x24
//   audio service: vtable with create at +0x5c and fade at +0x64
// The audio service lives at +0x6c of the object pointed to by the
// small-data pointer 0x804b1788.

struct W3dMusic;

struct W3dMusicVtable {
    unsigned int unknown00[4];
    void (*release)(W3dMusic *);         // +0x10
    void (*start)(W3dMusic *);           // +0x14
    unsigned int unknown18[3];
    int (*is_playing)(W3dMusic *);       // +0x24
};

struct W3dMusic {
    W3dMusicVtable *vtable;
};

// Reference-counted handle: the owned track is released when it is replaced.
struct W3dMusicHandle {
    W3dMusic *value;
    W3dMusic *get() const { return value; }
    int is_playing() const { return value->vtable->is_playing(value); }
    void reset(W3dMusic *next) { if (value) value->vtable->release(value); value = next; }
};

// Partial owner view: only the mode word and the music handle are observed.
struct W3dMusicOwner {
    unsigned char unknown00[200];
    W3dMusicHandle music;                // +0xc8
    unsigned int unknowncc;
    int mode;                            // +0xd0
};

struct W3dAudioService;

struct W3dAudioServiceVtable {
    unsigned int unknown00[23];
    void (*create)(W3dAudioService *, const char *, W3dMusic **);       // +0x5c
    unsigned int unknown60;
    void (*fade)(W3dAudioService *, W3dMusic **, unsigned int);         // +0x64
};

struct W3dAudioService {
    W3dAudioServiceVtable *vtable;
};

// Partial service container: the audio service pointer sits at +0x6c.
struct W3dServices {
    unsigned char unknown00[108];
    W3dAudioService *audio;
};

extern W3dServices *w3d_services_804b1788;

// Track resource names, referenced by original address.
extern const char w3d_track_normal_803caf0c[];
extern const char w3d_track_instrumental_803cb288[];
extern const char w3d_track_vocal_803cb298[];
extern const char w3d_track_intro_803cb2a0[];
extern const char w3d_track_credits_803cb2b0[];
extern const char w3d_track_wormsong_803cb2b8[];

// Original string comparison helper 0x802ef074 (exact bytes not yet recovered).
extern "C" int w3d_compare_text_802ef074(const char *, const char *);

// Modes: 3 is the neutral "unknown" value stored before the comparison.
extern "C" void e12d_select_music_802644a8(W3dMusicOwner *self, const char *mode)
{
    int old_mode = self->mode;
    self->mode = 3;
    const char *track = 0;
    int comparison = w3d_compare_text_802ef074(mode, w3d_track_normal_803caf0c);
    if (!comparison) {
        // The comparison result itself is the normal-mode value.
        track = w3d_track_instrumental_803cb288;
        self->mode = comparison;
    } else if (w3d_compare_text_802ef074(mode, w3d_track_vocal_803cb298) == 0) {
        track = w3d_track_intro_803cb2a0;
        self->mode = 1;
    } else if (w3d_compare_text_802ef074(mode, w3d_track_credits_803cb2b0) == 0) {
        self->mode = 2;
        track = w3d_track_wormsong_803cb2b8;
    }
    if (old_mode != self->mode) {
        if (self->music.get()) {
            if (self->music.is_playing())
                w3d_services_804b1788->audio->vtable->fade(
                    w3d_services_804b1788->audio, &self->music.value,
                    !track ? 200 : 2000);
            else
                self->music.reset(0);
        }
        if (track) {
            w3d_services_804b1788->audio->vtable->create(
                w3d_services_804b1788->audio, track, &self->music.value);
            self->music.value->vtable->start(self->music.value);
        }
    }
}
