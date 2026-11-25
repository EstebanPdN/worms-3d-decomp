// desc: Appears to start a voice for a sound object: it checks the object's sound slot, queries its id twice, starts the voice with fixed volume and pan and records the handle in both records, returning one, or zero without a sound.
struct S21Sound;
struct S21SoundMethods { void (*reserved[16])(void); int (*id)(struct S21Sound *); };
struct S21Sound { struct S21SoundMethods *methods; };
struct S21Object;
struct S21ObjectMethods { void (*reserved[18])(void); int (*time)(struct S21Object *); };
struct S21Object { struct S21ObjectMethods *methods; char pad[52]; int voice; char pad1[28]; struct S21Sound *sound; };
struct S21Voice { int time; struct S21Sound *sound; int pad8; struct S21Object *owner; int handle; };
extern int fn_80322938(unsigned, int, int, int);
int w3d_s21_start_voice_801e4ce0(struct S21Voice *voice, struct S21Object *object)
{
    struct S21Sound *sound = object->sound;
    int handle;
    if (sound == 0)
        return 0;
    if (sound->methods->id(sound) >= 0) {
        voice->time = object->methods->time(object);
        handle = fn_80322938((unsigned short)sound->methods->id(sound), 127, 64, 0);
        voice->owner = object;
        voice->handle = handle;
        voice->sound = object->sound;
        object->voice = handle;
    }
    return 1;
}
