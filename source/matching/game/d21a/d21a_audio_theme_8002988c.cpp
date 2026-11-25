/* Audio theme start-up (0x8002988c): reads the Land.Theme (default
 * "ENGLAND") and Land.TimeOfDay (default "DAY") properties, maps the theme
 * name to England, Horror, Pirate, War, Lunar or Arctic and the time of day
 * to day or night (RANDOM: random; EVENING: night with probability 1/2),
 * starts one of the theme's four music tracks at random into the music slot
 * (+28) and the day or night ambience into the ambient slot (+32) through the
 * audio service, applies the Audio.Vol.Music and Audio.Vol.Ambient volumes to
 * the started sounds, passes Audio.Vol.Sfx (default 1.0) to audio option 19
 * and subscribes the three handlers at +44, +48 and +52 to their messages.
 * Field and type names are inferred from the original instructions.
 *
 * The strings and the 1.0f default are external views of the original
 * .rodata (0x80372018..0x80372377): that pool also holds the compiled-out
 * diagnostic strings of this translation unit ("Audio undef. theme
 * string: ", "Music England Track:", ...), so the unit owns no data. */
struct Sound;
struct SoundVtable { void *unknown00[13]; void (*setVolume)(Sound *, int, float); };
struct Sound { SoundVtable *vtable; };
struct AudioService;
struct AudioServiceVtable {
    void *unknown00[23];
    void (*play)(AudioService *, const char *, Sound **);   /* +92 */
    void *unknown60[4];
    void (*setOption)(AudioService *, int, float *);          /* +112 */
};
struct AudioService { AudioServiceVtable *vtable; };
struct Services { char unknown00[108]; AudioService *audio; };
extern Services *w3d_services_804b1788;
struct PropertyKey { const char *name; };
struct MessageCache { unsigned short id; unsigned char unknown[6]; };
struct MessageId { unsigned short value; };
struct AudioTheme {
    char unknown00[28];
    Sound *music;            /* +28 */
    Sound *ambient;          /* +32 */
    char unknown24[8];
    char handler44[4];       /* +44 */
    char handler48[4];       /* +48 */
    char handler52[4];       /* +52 */
};
extern "C" int w3d_string_property_800fc2b0(PropertyKey *, const char **);
extern "C" int w3d_float_property_800fc270(PropertyKey *, float *);
extern "C" int strcmp(const char *, const char *);
/* Game random number generator. */
extern "C" unsigned w3d_random_80162c20(void);
extern "C" int w3d_cached_message_id_8015f5a0(MessageCache *, int);
extern "C" int w3d_subscribe_80162024(AudioTheme *, MessageId *, void *);
extern MessageCache w3d_message_804acbfc, w3d_message_804acc04, w3d_message_804acc0c;
extern "C" char w3d_string_80372018[]; /* "ENGLAND" */
extern "C" char w3d_string_80372020[]; /* "DAY" */
extern "C" char w3d_string_80372024[]; /* "Land.Theme" */
extern "C" char w3d_string_80372030[]; /* "Land.TimeOfDay" */
extern "C" char w3d_string_80372040[]; /* "HORROR" */
extern "C" char w3d_string_80372048[]; /* "WAR" */
extern "C" char w3d_string_8037204c[]; /* "LUNAR" */
extern "C" char w3d_string_80372054[]; /* "PIRATE" */
extern "C" char w3d_string_8037205c[]; /* "ARCTIC" */
extern "C" char w3d_string_80372080[]; /* "RANDOM" */
extern "C" char w3d_string_80372088[]; /* "EVENING" */
extern "C" char w3d_string_80372090[]; /* "NIGHT" */
extern "C" char w3d_string_80372110[]; /* "MusEngland1" */
extern "C" char w3d_string_8037211c[]; /* "MusEngland2" */
extern "C" char w3d_string_80372128[]; /* "MusEngland3" */
extern "C" char w3d_string_80372134[]; /* "MusEngland4" */
extern "C" char w3d_string_80372140[]; /* "AmbEnglandDay" */
extern "C" char w3d_string_80372150[]; /* "AmbEnglandNight" */
extern "C" char w3d_string_80372178[]; /* "MusSpace1" */
extern "C" char w3d_string_80372184[]; /* "MusSpace2" */
extern "C" char w3d_string_80372190[]; /* "MusSpace3" */
extern "C" char w3d_string_8037219c[]; /* "MusSpace4" */
extern "C" char w3d_string_803721a8[]; /* "AmbSpaceDay" */
extern "C" char w3d_string_803721b4[]; /* "AmbSpaceNight" */
extern "C" char w3d_string_803721dc[]; /* "MusPirate1" */
extern "C" char w3d_string_803721e8[]; /* "MusPirate2" */
extern "C" char w3d_string_803721f4[]; /* "MusPirate3" */
extern "C" char w3d_string_80372200[]; /* "MusPirate4" */
extern "C" char w3d_string_8037220c[]; /* "AmbPirateDay" */
extern "C" char w3d_string_8037221c[]; /* "AmbPirateNight" */
extern "C" char w3d_string_80372244[]; /* "MusHorror1" */
extern "C" char w3d_string_80372250[]; /* "MusHorror2" */
extern "C" char w3d_string_8037225c[]; /* "MusHorror3" */
extern "C" char w3d_string_80372268[]; /* "MusHorror4" */
extern "C" char w3d_string_80372274[]; /* "AmbHorrorDay" */
extern "C" char w3d_string_80372284[]; /* "AmbHorrorNight" */
extern "C" char w3d_string_803722a8[]; /* "MusWar1" */
extern "C" char w3d_string_803722b0[]; /* "MusWar2" */
extern "C" char w3d_string_803722b8[]; /* "MusWar3" */
extern "C" char w3d_string_803722c0[]; /* "MusWar4" */
extern "C" char w3d_string_803722c8[]; /* "AmbWarDay" */
extern "C" char w3d_string_803722d4[]; /* "AmbWarNight" */
extern "C" char w3d_string_803722f0[]; /* "MusArctic1" */
extern "C" char w3d_string_803722fc[]; /* "MusArctic2" */
extern "C" char w3d_string_80372308[]; /* "MusArctic3" */
extern "C" char w3d_string_80372314[]; /* "MusArctic4" */
extern "C" char w3d_string_80372320[]; /* "AmbArcticDay" */
extern "C" char w3d_string_80372330[]; /* "AmbArcticNight" */
extern "C" char w3d_string_80372340[]; /* "Audio.Vol.Music" */
extern "C" char w3d_string_80372350[]; /* "Audio.Vol.Ambient" */
extern "C" char w3d_string_80372364[]; /* "Audio.Vol.Sfx" */
extern float w3d_default_sfx_volume_80372374[]; /* 1.0f */

enum { THEME_ENGLAND, THEME_HORROR, THEME_PIRATE, THEME_WAR, THEME_LUNAR, THEME_ARCTIC };
enum { TIME_DAY = 0, TIME_NIGHT = 2 };

/* Starts the named sound through the audio service and stores it in slot. */
inline void Play(const char *name, Sound **slot)
{
    AudioService *audio = w3d_services_804b1788->audio;
    audio->vtable->play(audio, name, slot);
}

extern "C" void w3d_d21a_audio_theme_8002988c(AudioTheme *self)
{
    const char *themeName = w3d_string_80372018;
    const char *timeName = w3d_string_80372020;
    PropertyKey themeKey;
    themeKey.name = w3d_string_80372024;
    w3d_string_property_800fc2b0(&themeKey, &themeName);
    int theme = THEME_ENGLAND;
    PropertyKey timeKey;
    timeKey.name = w3d_string_80372030;
    int time = TIME_DAY;
    w3d_string_property_800fc2b0(&timeKey, &timeName);
    if (strcmp(themeName, w3d_string_80372018) == 0) theme = THEME_ENGLAND;
    else if (strcmp(themeName, w3d_string_80372040) == 0) theme = THEME_HORROR;
    else if (strcmp(themeName, w3d_string_80372048) == 0) theme = THEME_WAR;
    else if (strcmp(themeName, w3d_string_8037204c) == 0) theme = THEME_LUNAR;
    else if (strcmp(themeName, w3d_string_80372054) == 0) theme = THEME_PIRATE;
    else if (strcmp(themeName, w3d_string_8037205c) == 0) theme = THEME_ARCTIC;
    if (strcmp(timeName, w3d_string_80372080) == 0) {
        switch (w3d_random_80162c20() & 1) {
        case 0: time = TIME_DAY; break;
        case 1: time = TIME_NIGHT; break;
        default: time = TIME_NIGHT; break;
        }
    } else if (strcmp(timeName, w3d_string_80372020) == 0) {
        time = TIME_DAY;
    } else if (strcmp(timeName, w3d_string_80372088) == 0) {
        time = TIME_NIGHT;
        if ((w3d_random_80162c20() & 1) == 0) time = TIME_DAY;
    } else if (strcmp(timeName, w3d_string_80372090) == 0) {
        time = TIME_NIGHT;
    }
    switch (theme) {
    case THEME_ENGLAND:
        switch (w3d_random_80162c20() & 3) {
        case 0: Play(w3d_string_80372110, &self->music); break;
        case 1: Play(w3d_string_8037211c, &self->music); break;
        case 2: Play(w3d_string_80372128, &self->music); break;
        case 3: Play(w3d_string_80372134, &self->music); break;
        }
        if (time == TIME_DAY) Play(w3d_string_80372140, &self->ambient);
        else Play(w3d_string_80372150, &self->ambient);
        break;
    case THEME_LUNAR:
        switch (w3d_random_80162c20() & 3) {
        case 0: Play(w3d_string_80372178, &self->music); break;
        case 1: Play(w3d_string_80372184, &self->music); break;
        case 2: Play(w3d_string_80372190, &self->music); break;
        case 3: Play(w3d_string_8037219c, &self->music); break;
        }
        if (time == TIME_DAY) Play(w3d_string_803721a8, &self->ambient);
        else Play(w3d_string_803721b4, &self->ambient);
        break;
    case THEME_PIRATE:
        switch (w3d_random_80162c20() & 3) {
        case 0: Play(w3d_string_803721dc, &self->music); break;
        case 1: Play(w3d_string_803721e8, &self->music); break;
        case 2: Play(w3d_string_803721f4, &self->music); break;
        case 3: Play(w3d_string_80372200, &self->music); break;
        }
        if (time == TIME_DAY) Play(w3d_string_8037220c, &self->ambient);
        else Play(w3d_string_8037221c, &self->ambient);
        break;
    case THEME_HORROR:
        switch (w3d_random_80162c20() & 3) {
        case 0: Play(w3d_string_80372244, &self->music); break;
        case 1: Play(w3d_string_80372250, &self->music); break;
        case 2: Play(w3d_string_8037225c, &self->music); break;
        case 3: Play(w3d_string_80372268, &self->music); break;
        }
        if (time == TIME_DAY) Play(w3d_string_80372274, &self->ambient);
        else Play(w3d_string_80372284, &self->ambient);
        break;
    case THEME_WAR:
        switch (w3d_random_80162c20() & 3) {
        case 0: Play(w3d_string_803722a8, &self->music); break;
        case 1: Play(w3d_string_803722b0, &self->music); break;
        case 2: Play(w3d_string_803722b8, &self->music); break;
        default: Play(w3d_string_803722c0, &self->music); break;
        }
        if (time == TIME_DAY) Play(w3d_string_803722c8, &self->ambient);
        else Play(w3d_string_803722d4, &self->ambient);
        break;
    case THEME_ARCTIC:
        switch (w3d_random_80162c20() & 3) {
        case 0: Play(w3d_string_803722f0, &self->music); break;
        case 1: Play(w3d_string_803722fc, &self->music); break;
        case 2: Play(w3d_string_80372308, &self->music); break;
        default: Play(w3d_string_80372314, &self->music); break;
        }
        if (time == TIME_DAY) Play(w3d_string_80372320, &self->ambient);
        else Play(w3d_string_80372330, &self->ambient);
        break;
    }
    if (self->music) {
        PropertyKey key;
        key.name = w3d_string_80372340;
        float volume;
        w3d_float_property_800fc270(&key, &volume);
        self->music->vtable->setVolume(self->music, 1, volume);
    }
    if (self->ambient) {
        PropertyKey key;
        key.name = w3d_string_80372350;
        float volume;
        w3d_float_property_800fc270(&key, &volume);
        self->ambient->vtable->setVolume(self->ambient, 1, volume);
    }
    PropertyKey sfxKey;
    sfxKey.name = w3d_string_80372364;
    float sfxVolume = w3d_default_sfx_volume_80372374[0];
    w3d_float_property_800fc270(&sfxKey, &sfxVolume);
    AudioService *audio = w3d_services_804b1788->audio;
    audio->vtable->setOption(audio, 19, &sfxVolume);
    MessageId id;
    id.value = w3d_cached_message_id_8015f5a0(&w3d_message_804acbfc, 1);
    w3d_subscribe_80162024(self, &id, self->handler44);
    MessageId id2;
    id2.value = w3d_cached_message_id_8015f5a0(&w3d_message_804acc04, 1);
    w3d_subscribe_80162024(self, &id2, self->handler48);
    MessageId id3;
    id3.value = w3d_cached_message_id_8015f5a0(&w3d_message_804acc0c, 1);
    w3d_subscribe_80162024(self, &id3, self->handler52);
}
